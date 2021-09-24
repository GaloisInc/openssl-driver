
#ifdef __APPLE__
# define SECRET_GLOBAL      __attribute__((section("__DATA,__secret")))
# define SECRET_GLOBAL_RO   __attribute__((section("__TEXT,__secret")))
#else
# define SECRET_GLOBAL      __attribute__((section(".data.secret")))
# define SECRET_GLOBAL_RO   __attribute__((section(".rodata.secret")))
#endif


unsigned char read_buf_0[32] SECRET_GLOBAL_RO = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
unsigned char read_buf_1[11] SECRET_GLOBAL_RO = {
  0x16, 0x03, 0x01, 0x00, 0xE2, 0x01, 0x00, 0x00, 0xDE, 0x03, 0x03
};
unsigned char read_buf_2[220] SECRET_GLOBAL_RO = {
  0x10, 0x6F, 0x1C, 0xD0, 0x67, 0xB5, 0x75, 0x97, 0xCE, 0xCB, 0x5B, 0x21, 0x96, 0x59, 0xF2, 0x6D,
  0xE3, 0xB8, 0xE9, 0x66, 0xE2, 0x00, 0xF0, 0x8C, 0xF4, 0x4E, 0x29, 0xE2, 0x9C, 0x56, 0xAD, 0xC3,
  0x20, 0x78, 0xD2, 0x39, 0xB1, 0xB8, 0x0B, 0xEF, 0xC5, 0x88, 0xBB, 0xD5, 0x54, 0xEE, 0x8C, 0x9A,
  0x6F, 0x75, 0xC3, 0xA8, 0x4C, 0x9D, 0x5E, 0x8C, 0x41, 0xB3, 0xAC, 0x81, 0xCC, 0xA5, 0x64, 0xA8,
  0x83, 0x00, 0x0A, 0x13, 0x02, 0x13, 0x03, 0x13, 0x01, 0x00, 0x9D, 0x00, 0xFF, 0x01, 0x00, 0x00,
  0x8B, 0x00, 0x0B, 0x00, 0x04, 0x03, 0x00, 0x01, 0x02, 0x00, 0x0A, 0x00, 0x0C, 0x00, 0x0A, 0x00,
  0x1D, 0x00, 0x17, 0x00, 0x1E, 0x00, 0x19, 0x00, 0x18, 0x00, 0x23, 0x00, 0x00, 0x00, 0x16, 0x00,
  0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x2A, 0x00, 0x28, 0x04, 0x03, 0x05, 0x03, 0x06,
  0x03, 0x08, 0x07, 0x08, 0x08, 0x08, 0x09, 0x08, 0x0A, 0x08, 0x0B, 0x08, 0x04, 0x08, 0x05, 0x08,
  0x06, 0x04, 0x01, 0x05, 0x01, 0x06, 0x01, 0x03, 0x03, 0x03, 0x01, 0x03, 0x02, 0x04, 0x02, 0x05,
  0x02, 0x06, 0x02, 0x00, 0x2B, 0x00, 0x05, 0x04, 0x03, 0x04, 0x03, 0x03, 0x00, 0x2D, 0x00, 0x02,
  0x01, 0x01, 0x00, 0x33, 0x00, 0x26, 0x00, 0x24, 0x00, 0x1D, 0x00, 0x20, 0xC1, 0x8F, 0xE9, 0x63,
  0x90, 0xEC, 0x38, 0x51, 0xBA, 0xF3, 0xB3, 0x92, 0x02, 0xAD, 0x7C, 0xE4, 0x67, 0x09, 0xA6, 0x85,
  0x54, 0x5A, 0x71, 0xB3, 0x61, 0x30, 0x4B, 0x55, 0xBE, 0xE0, 0x13, 0x46
};
unsigned char read_buf_3[5] SECRET_GLOBAL_RO = {
  0x16, 0x03, 0x03, 0x02, 0x06
};
unsigned char read_buf_4[518] SECRET_GLOBAL_RO = {
  0x10, 0x00, 0x02, 0x02, 0x02, 0x00, 0x77, 0x32, 0xFF, 0x41, 0x9D, 0x53, 0x93, 0x32, 0x93, 0xBA,
  0xFB, 0x78, 0x10, 0xD9, 0x95, 0xA4, 0x6B, 0xFE, 0x7B, 0x0C, 0xF7, 0xCC, 0xCD, 0xF3, 0x65, 0xBF,
  0xF6, 0x08, 0x60, 0xCF, 0xFF, 0xF4, 0xAB, 0xBA, 0x8D, 0x9B, 0x4E, 0xC1, 0xB5, 0xFB, 0x9A, 0x43,
  0x4B, 0xC7, 0x9D, 0x02, 0x47, 0xD1, 0x4A, 0xFF, 0x21, 0xDC, 0xC8, 0x5E, 0xC1, 0x49, 0xF5, 0x44,
  0x4A, 0x1A, 0x6F, 0x3C, 0x03, 0xA8, 0x98, 0x97, 0xF2, 0x5D, 0x58, 0xB8, 0x2B, 0x06, 0x31, 0xB9,
  0x0D, 0x87, 0x9F, 0xD1, 0x8D, 0xDE, 0x18, 0x64, 0x78, 0x5B, 0xFD, 0x5C, 0x4C, 0x35, 0xBF, 0xE3,
  0xDA, 0xC2, 0x0B, 0xD2, 0x63, 0xD2, 0xC7, 0xF4, 0x71, 0x72, 0x5F, 0x8C, 0x04, 0x11, 0x97, 0xA5,
  0x16, 0xD7, 0xEE, 0xA7, 0x14, 0x25, 0xDA, 0x59, 0xD8, 0xE7, 0xB6, 0xB4, 0xB7, 0x37, 0x0E, 0xB2,
  0xB5, 0xCD, 0x34, 0x02, 0x55, 0xB7, 0x10, 0xDC, 0xCE, 0xB1, 0x0D, 0x8B, 0xF6, 0xFE, 0xBE, 0xEE,
  0x6C, 0x24, 0x7C, 0xAF, 0x11, 0x8F, 0x44, 0x44, 0x7B, 0x1A, 0x63, 0xB4, 0x55, 0x05, 0x92, 0xDE,
  0x1F, 0x86, 0x64, 0xCE, 0x98, 0x76, 0xC2, 0x0F, 0x74, 0x5D, 0xFA, 0xA8, 0x8F, 0xB4, 0xCA, 0x76,
  0x7F, 0xC4, 0x6C, 0x1F, 0x2E, 0x7D, 0x40, 0xE6, 0x6B, 0x7A, 0x78, 0xC9, 0x83, 0xAC, 0x78, 0xD9,
  0x8C, 0xB6, 0x71, 0xC5, 0x3A, 0xF6, 0x4B, 0x9E, 0x96, 0x05, 0xD6, 0xCC, 0x04, 0xC8, 0x10, 0xF9,
  0x3D, 0xDC, 0xB2, 0xF2, 0x1D, 0x4D, 0x06, 0x91, 0x59, 0xA9, 0x7F, 0x17, 0xC1, 0xF3, 0x9B, 0x23,
  0x5C, 0x0A, 0xE6, 0xBE, 0xD2, 0xE8, 0x8A, 0x7A, 0xAD, 0xA4, 0x65, 0xB1, 0x69, 0xB6, 0x98, 0x2C,
  0x6B, 0xEF, 0xD2, 0x28, 0x69, 0xF9, 0xB4, 0x26, 0xB4, 0xE6, 0x44, 0xDE, 0x2B, 0x3C, 0x8C, 0x5E,
  0xDE, 0x11, 0x0E, 0xA8, 0xAA, 0x2F, 0x25, 0xD1, 0x20, 0x2A, 0x6A, 0xD4, 0xBE, 0x5B, 0xF7, 0xB8,
  0xAF, 0x8C, 0x6B, 0x53, 0x88, 0x7E, 0xEE, 0xCB, 0x15, 0x33, 0x70, 0x2D, 0xC0, 0x7D, 0xDB, 0x1D,
  0x68, 0x8F, 0x99, 0x86, 0xAA, 0xB0, 0x0D, 0x51, 0xED, 0x0A, 0xEF, 0xF7, 0x23, 0x57, 0x2D, 0x68,
  0x54, 0xF1, 0x92, 0xB2, 0x3A, 0xC4, 0x94, 0x1C, 0x67, 0x82, 0xCD, 0x8F, 0xB5, 0xE9, 0x38, 0xB1,
  0x67, 0x37, 0x3D, 0xC5, 0x95, 0x9E, 0xE6, 0x00, 0x40, 0x79, 0x35, 0x76, 0x32, 0x43, 0xBD, 0x77,
  0x7C, 0x8B, 0x20, 0x84, 0x6D, 0x78, 0x9E, 0xB0, 0x02, 0x57, 0xFA, 0xAF, 0xF7, 0x0A, 0xF9, 0x95,
  0x5A, 0x5C, 0x98, 0x6C, 0x74, 0x3B, 0x17, 0xBB, 0x92, 0xC5, 0x2E, 0xEE, 0x0C, 0x2D, 0x85, 0x1A,
  0xDC, 0x90, 0x1B, 0xBD, 0xAA, 0x8F, 0x26, 0x41, 0x03, 0x4F, 0x6E, 0xC7, 0x18, 0x93, 0x90, 0x4C,
  0x86, 0x5B, 0x95, 0xED, 0x9E, 0x74, 0x28, 0x40, 0xC9, 0xC5, 0x0E, 0xBE, 0xAB, 0xC5, 0x2A, 0xF0,
  0xB3, 0x56, 0x8B, 0xF3, 0x60, 0x4C, 0xBF, 0xDF, 0xC9, 0xFB, 0x42, 0x16, 0x7D, 0x19, 0x41, 0xCA,
  0x04, 0x23, 0x5E, 0x6B, 0x1E, 0x3B, 0x7A, 0x96, 0x59, 0x32, 0x8F, 0x8E, 0xF4, 0xB7, 0x2D, 0x12,
  0xFF, 0x4F, 0x08, 0x13, 0x03, 0xBB, 0x40, 0xE2, 0xD4, 0x27, 0x3C, 0xC7, 0x28, 0x5B, 0xE0, 0xF8,
  0xD1, 0xA6, 0x35, 0x47, 0xEC, 0x46, 0xB2, 0x22, 0x49, 0x7E, 0x66, 0xD5, 0xA9, 0xC4, 0x77, 0xA6,
  0xD7, 0x0F, 0x13, 0x79, 0xC7, 0x4D, 0x21, 0x69, 0x63, 0x39, 0x38, 0x7A, 0x4F, 0x6F, 0xA2, 0xAA,
  0xF5, 0x83, 0x43, 0xDC, 0x3D, 0xCA, 0xC5, 0x64, 0xDB, 0x66, 0x6D, 0x7D, 0xE9, 0xA5, 0xFC, 0xB0,
  0x7C, 0xB4, 0xD4, 0x4F, 0x6C, 0x06, 0xCD, 0x6C, 0x3D, 0x72, 0xDA, 0xF8, 0x3B, 0x73, 0x37, 0xCA,
  0x65, 0x19, 0x4B, 0x53, 0x1A, 0xF3
};
unsigned char read_buf_5[5] SECRET_GLOBAL_RO = {
  0x14, 0x03, 0x03, 0x00, 0x01
};
unsigned char read_buf_6[1] SECRET_GLOBAL_RO = {
  0x01
};
unsigned char read_buf_7[5] SECRET_GLOBAL_RO = {
  0x16, 0x03, 0x03, 0x00, 0x28
};
unsigned char read_buf_8[40] SECRET_GLOBAL_RO = {
  0xEB, 0x84, 0x9F, 0xAA, 0xB7, 0xD0, 0xA7, 0x74, 0x83, 0x71, 0x02, 0x3B, 0xE8, 0xBE, 0x6B, 0x96,
  0x1B, 0x16, 0x8D, 0xA0, 0xB1, 0x64, 0xFD, 0xB7, 0xA5, 0xE4, 0xC2, 0x04, 0xD1, 0x84, 0x23, 0x7C,
  0x68, 0x2F, 0x63, 0x5D, 0x5E, 0xE4, 0xEA, 0xE2
};
unsigned char read_buf_9[5] SECRET_GLOBAL_RO = {
  0x17, 0x03, 0x03, 0x00, 0xF9
};
unsigned char read_buf_10[249] SECRET_GLOBAL_RO = {
  0xEB, 0x84, 0x9F, 0xAA, 0xB7, 0xD0, 0xA7, 0x75, 0x0E, 0x4B, 0x82, 0x89, 0xBB, 0x24, 0x6E, 0x01,
  0x21, 0x99, 0xBA, 0x97, 0x53, 0xD7, 0x44, 0x8D, 0xDA, 0x67, 0x36, 0x3C, 0xFB, 0xD0, 0xC4, 0xD6,
  0xD6, 0x1A, 0xB2, 0x68, 0x64, 0x97, 0x43, 0x43, 0x54, 0x7C, 0x92, 0x28, 0xD6, 0x8D, 0xAA, 0xAB,
  0x24, 0x1D, 0xC6, 0x02, 0x9F, 0xEB, 0xFA, 0x35, 0xA4, 0x18, 0x3D, 0x94, 0x1F, 0x6F, 0x74, 0xD3,
  0xFD, 0xA3, 0xED, 0x73, 0x0A, 0x23, 0x9B, 0x27, 0x62, 0xFE, 0xFE, 0x89, 0xC6, 0xA8, 0x5A, 0x7B,
  0x06, 0x20, 0x36, 0x43, 0x61, 0x6E, 0xFD, 0x90, 0x37, 0x1B, 0xAE, 0xF3, 0xD0, 0x98, 0x17, 0x98,
  0x40, 0xDB, 0x12, 0x3E, 0xB0, 0x4C, 0xCF, 0xE5, 0x3A, 0x48, 0xB6, 0xB0, 0x5C, 0xC4, 0xEE, 0xC4,
  0x7B, 0x52, 0xEB, 0xC6, 0x67, 0xC8, 0x88, 0x91, 0x3D, 0xAE, 0x68, 0xCB, 0x39, 0x19, 0x68, 0x81,
  0x44, 0x4C, 0xDE, 0x31, 0xBD, 0xC4, 0x5F, 0xC6, 0x3D, 0xF4, 0x40, 0xD3, 0x45, 0xE3, 0x18, 0xB2,
  0x5A, 0xFD, 0xEE, 0xD2, 0x52, 0x09, 0x88, 0x5D, 0x79, 0x88, 0x7E, 0x73, 0xC2, 0xCD, 0x3E, 0xB5,
  0x53, 0xC1, 0x49, 0xF9, 0x00, 0x2A, 0xF0, 0x3E, 0x6A, 0x2C, 0xBC, 0x80, 0x87, 0x8F, 0x45, 0x0E,
  0x7A, 0x44, 0xF2, 0xCC, 0xAB, 0x59, 0x77, 0xB9, 0xE5, 0x57, 0x34, 0x71, 0x3E, 0xA3, 0xD5, 0x1D,
  0xE1, 0x0E, 0xF3, 0xF0, 0x48, 0x92, 0x08, 0xE7, 0x74, 0xC6, 0x13, 0x46, 0x9A, 0x87, 0xAF, 0xD6,
  0xFD, 0x12, 0xB6, 0xC0, 0x18, 0x9B, 0xFD, 0x10, 0xF7, 0xB6, 0xB2, 0xB3, 0x21, 0xBC, 0x30, 0x72,
  0x24, 0xCB, 0x95, 0x57, 0x84, 0x74, 0x7B, 0x3A, 0xE8, 0xCF, 0xC0, 0xD3, 0x31, 0xF1, 0x84, 0x04,
  0x4A, 0x88, 0x3E, 0xB6, 0x17, 0x1A, 0xEE, 0x2A, 0x7F
};
unsigned char read_buf_11[11] SECRET_GLOBAL_RO = {
  0x16, 0x03, 0x01, 0x00, 0xDC, 0x01, 0x00, 0x00, 0xD8, 0x03, 0x01
};
unsigned char read_buf_12[214] SECRET_GLOBAL_RO = {
  0x53, 0x43, 0x5B, 0x90, 0x9D, 0x9B, 0x72, 0x0B, 0xBC, 0x0C, 0xBC, 0x2B, 0x92, 0xA8, 0x48, 0x97,
  0xCF, 0xBD, 0x39, 0x04, 0xCC, 0x16, 0x0A, 0x85, 0x03, 0x90, 0x9F, 0x77, 0x04, 0x33, 0xD4, 0xDE,
  0x00, 0x00, 0x66, 0xC0, 0x14, 0xC0, 0x0A, 0xC0, 0x22, 0xC0, 0x21, 0x00, 0x39, 0x00, 0x38, 0x00,
  0x88, 0x00, 0x87, 0xC0, 0x0F, 0xC0, 0x05, 0x00, 0x35, 0x00, 0x84, 0xC0, 0x12, 0xC0, 0x08, 0xC0,
  0x1C, 0xC0, 0x1B, 0x00, 0x16, 0x00, 0x13, 0xC0, 0x0D, 0xC0, 0x03, 0x00, 0x0A, 0xC0, 0x13, 0xC0,
  0x09, 0xC0, 0x1F, 0xC0, 0x1E, 0x00, 0x33, 0x00, 0x32, 0x00, 0x9A, 0x00, 0x99, 0x00, 0x45, 0x00,
  0x44, 0xC0, 0x0E, 0xC0, 0x04, 0x00, 0x2F, 0x00, 0x96, 0x00, 0x41, 0xC0, 0x11, 0xC0, 0x07, 0xC0,
  0x0C, 0xC0, 0x02, 0x00, 0x05, 0x00, 0x04, 0x00, 0x15, 0x00, 0x12, 0x00, 0x09, 0x00, 0x14, 0x00,
  0x11, 0x00, 0x08, 0x00, 0x06, 0x00, 0x03, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x49, 0x00, 0x0B, 0x00,
  0x04, 0x03, 0x00, 0x01, 0x02, 0x00, 0x0A, 0x00, 0x34, 0x00, 0x32, 0x00, 0x0E, 0x00, 0x0D, 0x00,
  0x19, 0x00, 0x0B, 0x00, 0x0C, 0x00, 0x18, 0x00, 0x09, 0x00, 0x0A, 0x00, 0x16, 0x00, 0x17, 0x00,
  0x08, 0x00, 0x06, 0x00, 0x07, 0x00, 0x14, 0x00, 0x15, 0x00, 0x04, 0x00, 0x05, 0x00, 0x12, 0x00,
  0x13, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x0F, 0x00, 0x10, 0x00, 0x11, 0x00, 0x23, 0x00,
  0x00, 0x00, 0x0F, 0x00, 0x01, 0x01
};
unsigned char read_buf_13[5] SECRET_GLOBAL_RO = {
  0x18, 0x03, 0x01, 0x00, 0x03
};
unsigned char read_buf_14[3] SECRET_GLOBAL_RO = {
  0x01, 0x40, 0x00
};

