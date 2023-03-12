
int UTF8_getc(uchar *str,int len,ulong *val)

{
  uint uVar1;
  int iVar2;
  
  if (len < 1) {
    return 0;
  }
  uVar1 = (uint)*str;
  iVar2 = 1;
  if ((char)*str < '\0') {
    if ((uVar1 & 0xe0) != 0xc0) {
      if ((uVar1 & 0xf0) == 0xe0) {
        if (len < 3) {
          return -1;
        }
        if ((str[1] & 0xffffffc0) == 0x80) {
          if ((str[2] & 0xffffffc0) == 0x80) {
            uVar1 = str[2] & 0x3f | (str[1] & 0x3f) << 6 | (uVar1 & 0xf) << 0xc;
            if (0x7ff < uVar1) {
              *val = uVar1;
              return 3;
            }
            return -4;
          }
        }
      }
      else if ((uVar1 & 0xf8) == 0xf0) {
        if (len < 4) {
          return -1;
        }
        if (((str[1] & 0xffffffc0) == 0x80) && ((str[2] & 0xffffffc0) == 0x80)) {
          if ((str[3] & 0xffffffc0) == 0x80) {
            uVar1 = (str[2] & 0x3f) << 6 |
                    (uVar1 & 7) << 0x12 | str[3] & 0x3f | (str[1] & 0x3f) << 0xc;
            if (0xffff < uVar1) {
              *val = uVar1;
              return 4;
            }
            return -4;
          }
        }
      }
      else if ((uVar1 & 0xfc) == 0xf8) {
        if (len < 5) {
          return -1;
        }
        if ((((str[1] & 0xffffffc0) == 0x80) && ((str[2] & 0xffffffc0) == 0x80)) &&
           ((str[3] & 0xffffffc0) == 0x80)) {
          if ((str[4] & 0xc0) == 0x80) {
            uVar1 = (str[3] & 0x3f) << 6 |
                    (str[1] & 0x3f) << 0x12 | (uVar1 & 3) << 0x18 | str[4] & 0x3f |
                    (str[2] & 0x3f) << 0xc;
            if (0x1fffff < uVar1) {
              *val = uVar1;
              return 5;
            }
            return -4;
          }
        }
      }
      else {
        if ((uVar1 & 0xfe) != 0xfc) {
          return -2;
        }
        if (len < 6) {
          return -1;
        }
        if ((((str[1] & 0xc0) == 0x80) && ((str[2] & 0xffffffc0) == 0x80)) &&
           (((str[3] & 0xffffffc0) == 0x80 && ((str[4] & 0xffffffc0) == 0x80)))) {
          if ((str[5] & 0xffffffc0) == 0x80) {
            uVar1 = (str[4] & 0x3f) << 6 |
                    (uint)(str[1] & 0x3f) << 0x18 | (uVar1 & 1) << 0x1e | str[5] & 0x3f |
                    (str[2] & 0x3f) << 0x12 | (str[3] & 0x3f) << 0xc;
            if (0x3ffffff < uVar1) {
              *val = uVar1;
              return 6;
            }
            return -4;
          }
        }
      }
      return -3;
    }
    if (len == 1) {
      return -1;
    }
    if ((str[1] & 0xc0) != 0x80) {
      return -3;
    }
    uVar1 = str[1] & 0x3f | (uVar1 & 0x1f) << 6;
    iVar2 = 2;
    if (uVar1 < 0x80) {
      return -4;
    }
    *val = uVar1;
  }
  else {
    *val = uVar1;
  }
  return iVar2;
}

