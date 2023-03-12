
int EVP_DecodeBlock(uchar *t,uchar *f,int n)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  uint uVar5;
  uchar *puVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = (uint)(byte)data_ascii2bin[*f & 0x7f];
  if (uVar8 == 0xe0) {
    if (0 < n) {
      pbVar4 = f + 1;
      do {
        f = pbVar4;
        n = n - 1;
        uVar8 = (uint)(byte)data_ascii2bin[*f & 0x7f];
        if (uVar8 != 0xe0) goto LAB_0010d02c;
        pbVar4 = f + 1;
      } while (n != 0);
    }
    uVar8 = 0xe0;
  }
  else {
LAB_0010d02c:
    if (3 < n) {
      while ((data_ascii2bin[f[n - 1] & 0x7f] | 0x13) == 0xf3) {
        n = n - 1;
        if (n == 3) {
          return -1;
        }
      }
      if ((n & 3U) != 0) {
        return -1;
      }
      goto LAB_0010d070;
    }
  }
  if ((n & 3U) != 0) {
    return -1;
  }
  if (n < 1) {
    return 0;
  }
LAB_0010d070:
  uVar7 = (uint)(byte)data_ascii2bin[f[1] & 0x7f];
  bVar2 = data_ascii2bin[f[2] & 0x7f];
  bVar3 = data_ascii2bin[f[3] & 0x7f];
  uVar5 = (uVar7 | uVar8) & 0xffffff80;
  if (uVar5 == 0) {
    puVar6 = t;
    do {
      pbVar4 = f + 4;
      uVar8 = uVar8 << 0x12 | uVar7 << 0xc;
      uVar7 = uVar8 | bVar3 | (uint)bVar2 << 6;
      if (((bVar3 | bVar2) & 0x80) != 0) {
        return -1;
      }
      t[uVar5] = (uchar)(uVar8 >> 0x10);
      uVar5 = uVar5 + 3;
      puVar6[2] = (uchar)uVar7;
      puVar6[1] = (uchar)(uVar7 >> 8);
      if (uVar5 + ((n - 1U >> 2) + 1) * -3 == 0) {
        return uVar5;
      }
      pbVar1 = f + 5;
      uVar8 = (uint)(byte)data_ascii2bin[*pbVar4 & 0x7f];
      uVar7 = (uint)(byte)data_ascii2bin[*pbVar1 & 0x7f];
      bVar2 = data_ascii2bin[f[6] & 0x7f];
      bVar3 = data_ascii2bin[f[7] & 0x7f];
      puVar6 = puVar6 + 3;
      f = pbVar4;
    } while (-1 < (int)((uint)(byte)(data_ascii2bin[*pbVar1 & 0x7f] | data_ascii2bin[*pbVar4 & 0x7f]
                                    ) << 0x18));
  }
  return -1;
}

