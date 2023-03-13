
int EVP_DecodeBlock(uchar *t,uchar *f,int n)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  uchar *puVar7;
  uchar *puVar8;
  uint uVar9;
  uint uVar10;
  
  if ((-1 < (char)*f) && (data_ascii2bin[*f] == -0x20)) {
    if (n < 1) {
      if ((n & 3U) != 0) {
        return -1;
      }
    }
    else {
      do {
        f = f + 1;
        n = n - 1;
        if (((char)*f < '\0') || (data_ascii2bin[*f] != -0x20)) goto LAB_006050ac;
      } while (n != 0);
    }
    return 0;
  }
LAB_006050ac:
  pbVar5 = f + n;
  if (n < 4) {
    if ((n & 3U) == 0) {
      if (n < 1) {
        return 0;
      }
      goto LAB_00605134;
    }
  }
  else {
    if (-1 < (char)pbVar5[-1]) {
      bVar2 = data_ascii2bin[pbVar5[-1]];
      while ((bVar2 | 0x13) == 0xf3) {
        n = n - 1;
        if (n == 3) {
          return -1;
        }
        pbVar1 = pbVar5 + -2;
        pbVar5 = pbVar5 + -1;
        if ((char)*pbVar1 < '\0') break;
        bVar2 = data_ascii2bin[*pbVar1];
      }
    }
    if ((n & 3U) == 0) {
LAB_00605134:
      puVar8 = t;
      do {
        if ((char)*f < '\0') {
          bVar2 = f[1];
          uVar10 = 0xff;
          if ((char)bVar2 < '\0') goto LAB_00605218;
LAB_00605174:
          bVar3 = f[2];
          uVar9 = (uint)(byte)data_ascii2bin[bVar2];
        }
        else {
          bVar2 = f[1];
          uVar10 = (uint)(byte)data_ascii2bin[*f];
          if (-1 < (char)bVar2) goto LAB_00605174;
LAB_00605218:
          bVar3 = f[2];
          uVar9 = 0xff;
        }
        if ((char)bVar3 < '\0') {
          return -1;
        }
        if ((char)f[3] < '\0') {
          return -1;
        }
        uVar6 = uVar10 << 0x12 | (uint)(byte)data_ascii2bin[f[3]] | uVar9 << 0xc;
        uVar4 = uVar6 | (uint)(byte)data_ascii2bin[bVar3] << 6;
        if ((((uint)(byte)data_ascii2bin[bVar3] | uVar9 | (byte)data_ascii2bin[f[3]] | uVar10) &
            0xffffff80) != 0) {
          return -1;
        }
        *puVar8 = (uchar)(uVar6 >> 0x10);
        puVar7 = puVar8 + 3;
        puVar8[2] = (uchar)uVar4;
        puVar8[1] = (uchar)(uVar4 >> 8);
        f = f + 4;
        puVar8 = puVar7;
        if (puVar7 == t + ((n - 1U >> 2) + 1) * 3) {
          return (int)puVar7 - (int)t;
        }
      } while( true );
    }
  }
  return -1;
}

