
int UTF8_getc(uchar *str,int len,ulong *val)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint local_20;
  
  if (len < 1) {
    return 0;
  }
  bVar1 = *str;
  uVar2 = (uint)bVar1;
  if ((char)bVar1 < '\0') {
    if ((bVar1 & 0xe0) == 0xc0) {
      if (len == 1) {
        return -1;
      }
      if ((str[1] & 0xc0) != 0x80) {
        return -3;
      }
      uVar2 = str[1] & 0x3f | (uVar2 & 0x1f) << 6;
      if (uVar2 < 0x80) {
        return -4;
      }
      iVar3 = 2;
    }
    else if ((bVar1 & 0xf0) == 0xe0) {
      if (len < 3) {
        return -1;
      }
      if ((str[1] & 0xc0) != 0x80) {
        return -3;
      }
      if ((str[2] & 0xc0) != 0x80) {
        return -3;
      }
      uVar2 = str[2] & 0x3f | (str[1] & 0x3f) << 6 | (uVar2 & 0xf) << 0xc;
      if (uVar2 < 0x800) {
        return -4;
      }
      iVar3 = 3;
    }
    else if ((bVar1 & 0xf8) == 0xf0) {
      if (len < 4) {
        return -1;
      }
      if ((str[1] & 0xc0) != 0x80) {
        return -3;
      }
      if ((str[2] & 0xc0) != 0x80) {
        return -3;
      }
      if ((str[3] & 0xc0) != 0x80) {
        return -3;
      }
      uVar2 = (str[2] & 0x3f) << 6 | (str[1] & 0x3f) << 0xc | str[3] & 0x3f | (uVar2 & 7) << 0x12;
      if (uVar2 < 0x10000) {
        return -4;
      }
      iVar3 = 4;
    }
    else if ((bVar1 & 0xfc) == 0xf8) {
      if (len < 5) {
        return -1;
      }
      if ((str[1] & 0xc0) != 0x80) {
        return -3;
      }
      if ((str[2] & 0xc0) != 0x80) {
        return -3;
      }
      if ((str[3] & 0xc0) != 0x80) {
        return -3;
      }
      if ((str[4] & 0xc0) != 0x80) {
        return -3;
      }
      uVar2 = (str[3] & 0x3f) << 6 |
              (str[2] & 0x3f) << 0xc | (str[1] & 0x3f) << 0x12 | (uVar2 & 3) << 0x18 | str[4] & 0x3f
      ;
      if (uVar2 < 0x200000) {
        return -4;
      }
      iVar3 = 5;
    }
    else {
      if ((bVar1 & 0xfe) != 0xfc) {
        return -2;
      }
      if (len < 6) {
        return -1;
      }
      if (((((str[1] & 0xc0) != 0x80) || ((str[2] & 0xc0) != 0x80)) ||
          (local_20 = (uint)str[3], (str[3] & 0xc0) != 0x80)) ||
         (((str[4] & 0xc0) != 0x80 || ((str[5] & 0xc0) != 0x80)))) {
        return -3;
      }
      uVar2 = (str[4] & 0x3f) << 6 |
              (str[2] & 0x3f) << 0x12 |
              (str[1] & 0x3f) << 0x18 | (uVar2 & 1) << 0x1e | str[5] & 0x3f |
              (local_20 & 0x3f) << 0xc;
      if (uVar2 < 0x4000000) {
        return -4;
      }
      iVar3 = 6;
    }
  }
  else {
    iVar3 = 1;
  }
  *val = uVar2;
  return iVar3;
}

