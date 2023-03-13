
int EVP_DecodeBlock(uchar *t,uchar *f,int n)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if ((-1 < (char)*f) && (data_ascii2bin[*f] == -0x20)) {
    if (n < 1) {
      if ((n & 3U) != 0) {
        return -1;
      }
      return 0;
    }
    while( true ) {
      f = f + 1;
      n = n - 1;
      if (((char)*f < '\0') || (data_ascii2bin[*f] != -0x20)) break;
      if (n == 0) {
        return 0;
      }
    }
  }
  if (n < 4) {
    if ((n & 3U) == 0) {
      if (n < 1) {
        return 0;
      }
LAB_081c895c:
      iVar5 = 0;
      iVar1 = (n - 1U >> 2) * 3 + 3;
      while( true ) {
        uVar4 = 0xff;
        if (-1 < (char)*f) {
          uVar4 = (uint)(byte)data_ascii2bin[*f];
        }
        bVar2 = 0xff;
        if (-1 < (char)f[1]) {
          bVar2 = data_ascii2bin[f[1]];
        }
        if ((char)f[2] < '\0') break;
        if ((char)f[3] < '\0') {
          return -1;
        }
        if ((char)(data_ascii2bin[f[3]] | (byte)uVar4 | bVar2 | data_ascii2bin[f[2]]) < '\0') {
          return -1;
        }
        uVar3 = (uint)bVar2 << 0xc | (uint)(byte)data_ascii2bin[f[3]] | uVar4 << 0x12;
        uVar4 = uVar3 | (uint)(byte)data_ascii2bin[f[2]] << 6;
        t[iVar5 + 2] = (uchar)uVar4;
        t[iVar5] = (uchar)(uVar3 >> 0x10);
        t[iVar5 + 1] = (uchar)(uVar4 >> 8);
        iVar5 = iVar5 + 3;
        f = f + 4;
        if (iVar5 == iVar1) {
          return iVar1;
        }
      }
    }
  }
  else {
    do {
      if (((char)f[n - 1] < '\0') || ((data_ascii2bin[f[n - 1]] | 0x13) != 0xf3)) {
        if ((n & 3U) != 0) {
          return -1;
        }
        goto LAB_081c895c;
      }
      n = n - 1;
    } while (n != 3);
  }
  return -1;
}

