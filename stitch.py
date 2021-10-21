'''
Stitch together recordings that are mixed in with instrumentation (`[FUNC]`)
log outputs.
'''
import sys

out = []
for line in sys.stdin:
    _, _, call = line.partition(' ')
    func, _, args = call.rstrip(')').partition('(')
    if func == 'fromager_putchar':
        ch = chr(int(args.split(', ')[0], 16))
        out.append(ch)

print(''.join(out))
