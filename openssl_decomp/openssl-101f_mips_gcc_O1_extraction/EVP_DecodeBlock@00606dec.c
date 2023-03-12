
int EVP_DecodeBlock(uchar *t,uchar *f,int n)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  
  uVar6 = (uint)(byte)data_ascii2bin[*f & 0x7f];
  if (uVar6 != 0xe0) {
LAB_00606e44:
    pbVar2 = f + n;
    if (n < 4) {
      if ((n & 3U) != 0) {
        return -1;
      }
      if (n < 1) {
        return 0;
      }
    }
    else {
      bVar1 = data_ascii2bin[pbVar2[-1] & 0x7f];
      while ((bVar1 | 0x13) == 0xf3) {
        n = n - 1;
        if (n == 3) {
          return -1;
        }
        pbVar5 = pbVar2 + -2;
        pbVar2 = pbVar2 + -1;
        bVar1 = data_ascii2bin[*pbVar5 & 0x7f];
      }
      if ((n & 3U) != 0) {
        return -1;
      }
    }
    pbVar2 = t;
    while( true ) {
      iVar4 = (uint)(byte)data_ascii2bin[f[1] & 0x7f] << 0xc;
      bVar1 = data_ascii2bin[f[3] & 0x7f];
      iVar3 = (uint)(byte)data_ascii2bin[f[2] & 0x7f] << 6;
      if ((((uint)bVar1 | uVar6 | (byte)(data_ascii2bin[f[1] & 0x7f] | data_ascii2bin[f[2] & 0x7f]))
          & 0xffffff80) != 0) {
        return -1;
      }
      *pbVar2 = (byte)((uint)iVar4 >> 0x10) | (byte)((uVar6 << 0x12) >> 0x10);
      pbVar5 = pbVar2 + 3;
      pbVar2[2] = (byte)iVar3 | bVar1;
      pbVar2[1] = (byte)((uint)iVar4 >> 8) | (byte)((uint)iVar3 >> 8);
      if (t + ((n - 1U >> 2) + 1) * 3 == pbVar5) break;
      uVar6 = (uint)(byte)data_ascii2bin[f[4] & 0x7f];
      f = f + 4;
      pbVar2 = pbVar5;
    }
    return (int)pbVar5 - (int)t;
  }
  f = f + 1;
  if (n < 1) {
    if ((n & 3U) != 0) {
      return -1;
    }
  }
  else {
    do {
      uVar6 = (uint)(byte)data_ascii2bin[*f & 0x7f];
      n = n - 1;
      if (uVar6 != 0xe0) goto LAB_00606e44;
      f = f + 1;
    } while (n != 0);
  }
  return 0;
}

