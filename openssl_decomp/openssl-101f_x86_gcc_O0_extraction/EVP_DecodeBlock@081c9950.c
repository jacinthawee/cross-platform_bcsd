
int EVP_DecodeBlock(uchar *t,uchar *f,int n)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  bVar2 = data_ascii2bin[*f & 0x7f];
  if (bVar2 == 0xe0) {
    if (n < 1) {
      if ((n & 3U) != 0) {
        return -1;
      }
    }
    else {
      do {
        f = f + 1;
        n = n - 1;
        bVar2 = data_ascii2bin[*f & 0x7f];
        if (bVar2 != 0xe0) goto LAB_081c999f;
      } while (n != 0);
    }
    return 0;
  }
LAB_081c999f:
  if (n < 4) {
    if ((n & 3U) == 0) {
      if (n < 1) {
        return 0;
      }
LAB_081c99dc:
      iVar1 = (n - 1U >> 2) * 3 + 3;
      iVar6 = 0;
      while( true ) {
        bVar3 = data_ascii2bin[f[3] & 0x7f];
        if ((char)(data_ascii2bin[f[1] & 0x7f] | data_ascii2bin[f[2] & 0x7f] | bVar2 | bVar3) < '\0'
           ) break;
        iVar5 = (uint)(byte)data_ascii2bin[f[1] & 0x7f] << 0xc;
        iVar4 = (uint)(byte)data_ascii2bin[f[2] & 0x7f] << 6;
        t[iVar6] = (byte)(((uint)bVar2 << 0x12) >> 0x10) | (byte)((uint)iVar5 >> 0x10);
        t[iVar6 + 2] = (byte)iVar4 | bVar3;
        t[iVar6 + 1] = (byte)((uint)iVar4 >> 8) | (byte)((uint)iVar5 >> 8);
        iVar6 = iVar6 + 3;
        if (iVar6 == iVar1) {
          return iVar1;
        }
        bVar2 = data_ascii2bin[f[4] & 0x7f];
        f = f + 4;
      }
    }
  }
  else {
    do {
      if ((data_ascii2bin[f[n - 1] & 0x7f] | 0x13) != 0xf3) {
        if ((n & 3U) != 0) {
          return -1;
        }
        goto LAB_081c99dc;
      }
      n = n - 1;
    } while (n != 3);
  }
  return -1;
}

