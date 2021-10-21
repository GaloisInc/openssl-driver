'''
Usage: python3 update_records.py [FILES]

Reads C declarations from stdin and updates the FILES with those declarations,
based on the presence of `BEGIN/END RECORDINGS` comments.  See `src/*.c` for
examples of such comments.
'''
import re
import sys

C_TYPES = {
        'char', 'short', 'int', 'long', 'float', 'double',
        'void', 'unsigned',
        'uint8_t', 'uint16_t', 'uint32_t', 'uint64_t',
        'int8_t', 'int16_t', 'int32_t', 'int64_t',
}

IDENT_RE = re.compile(r'[a-zA-Z_][a-zA-Z_0-9]*')

def read_recordings():
    recs = {}
    cur_rec_name = None
    cur_rec = []

    for line in sys.stdin:
        if cur_rec_name is None:
            words = IDENT_RE.findall(line)
            if len(words) > 0 and words[0] in C_TYPES:
                name_parts = [w for w in words if w not in C_TYPES]
                if len(name_parts) > 0:
                    cur_rec_name = name_parts[0]
                    # Current line will be added to `cur_rec` below

        if cur_rec_name is not None:
            cur_rec.append(line)
            if line.rstrip().endswith(';'):
                assert cur_rec_name not in recs, 'duplicate recording name %r' % cur_rec_name
                recs[cur_rec_name] = cur_rec
                cur_rec_name = None
                cur_rec = []

    assert cur_rec_name is None, 'unfinished recording %r' % cur_rec_name
    return recs

BEGIN_RE = re.compile(
        r'// \*\* BEGIN RECORDINGS (public|secret) ([a-zA-Z_0-9]*?)([0-9]+)(-([0-9]+))?$')
END_RE = re.compile(r'// \*\* END RECORDINGS$')

def emit(rec, mode, out):
    if mode == 'public':
        out.extend(rec)
    elif mode == 'secret':
        out.append(rec[0].replace('=', 'SECRET_GLOBAL_RO ='))
        out.extend(rec[1:])
    else:
        raise ValueError('bad mode %r' % (mode,))

def update_file(path, recs):
    used = []
    lines = []
    in_recordings = False
    for line in open(path, 'r'):
        if in_recordings:
            if END_RE.match(line.strip()):
                in_recordings = False
            else:
                continue

        lines.append(line)

        m = BEGIN_RE.match(line.strip())
        if m:
            in_recordings = True;

            mode, name_base, count_start_str, _, count_end_str = m.groups()

            if count_end_str is not None:
                count_start = int(count_start_str)
                count_end = int(count_end_str)
                for i in range(count_start, count_end + 1):
                    name = '%s%d' % (name_base, i)
                    emit(recs[name], mode, lines)
                    used.append(name)
            else:
                name = name_base + (count_start_str or '')
                emit(recs[name], mode, lines)
                used.append(name)

    with open(path, 'w') as f:
        f.write(''.join(lines))

    return used


def main():
    recs = read_recordings()

    paths = sys.argv[1:]
    all_used = set()
    for path in paths:
        used = update_file(path, recs)
        print('updated %s with %r' % (path, used))
        all_used |= set(used)

    unused = set(recs.keys()) - all_used
    if len(unused) > 0:
        print('warning: found unused recordings in input:')
        for name in sorted(unused):
            print(''.join(recs[name]))

if __name__ == '__main__':
    main()
