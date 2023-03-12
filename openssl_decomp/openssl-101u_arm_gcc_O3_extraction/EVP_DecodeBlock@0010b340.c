
int EVP_DecodeBlock(uchar *t,uchar *f,int n)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  uchar *puVar5;
  uint uVar6;
  uint uVar7;
  uint unaff_r8;
  uint uVar8;
  bool bVar9;
  
  if (((int)((uint)*f << 0x18) < 0) || (data_ascii2bin[*f] != -0x20)) {
LAB_0010b37e:
    if (3 < n) {
      if (-1 < (int)((uint)f[n - 1] << 0x18)) {
        bVar1 = data_ascii2bin[f[n - 1]];
        uVar3 = n;
        while (n = uVar3, (bVar1 | 0x13) == 0xf3) {
          n = uVar3 - 1;
          if (n == 3) {
            return -1;
          }
          if ((int)((uint)f[uVar3 - 2] << 0x18) < 0) break;
          bVar1 = data_ascii2bin[f[uVar3 - 2]];
          uVar3 = n;
        }
      }
      if ((n & 3U) != 0) {
        return -1;
      }
      goto LAB_0010b3da;
    }
  }
  else if (0 < n) {
    pbVar2 = f + 1;
    do {
      f = pbVar2;
      n = n - 1;
      if (((int)((uint)*f << 0x18) < 0) || (data_ascii2bin[*f] != -0x20)) goto LAB_0010b37e;
      pbVar2 = f + 1;
    } while (n != 0);
  }
  if ((n & 3U) != 0) {
    return -1;
  }
  if (n < 1) {
    return 0;
  }
LAB_0010b3da:
  iVar4 = 0;
  puVar5 = t;
  do {
    if ((int)((uint)*f << 0x18) < 0) {
      uVar3 = 0xff;
    }
    else {
      uVar3 = (uint)(byte)data_ascii2bin[*f];
    }
    bVar9 = -1 < (int)((uint)f[1] << 0x18);
    if (bVar9) {
      uVar8 = (uint)(byte)data_ascii2bin[f[1]];
    }
    else {
      unaff_r8 = 0x80;
      uVar8 = 0xff;
    }
    if (bVar9) {
      unaff_r8 = (uVar3 | uVar8) & 0xffffff80;
    }
    if ((int)((uint)f[2] << 0x18) < 0) {
      uVar7 = 0xff;
    }
    else {
      uVar7 = (uint)(byte)data_ascii2bin[f[2]];
    }
    if ((f[3] & 0x80) == 0) {
      uVar6 = (uint)(byte)data_ascii2bin[f[3]];
    }
    else {
      uVar6 = 0xff;
    }
    if (unaff_r8 != 0) {
      return -1;
    }
    unaff_r8 = uVar6 | uVar7;
    if ((unaff_r8 & 0x80) != 0) {
      return -1;
    }
    f = f + 4;
    t[iVar4] = (byte)((uVar3 << 0x12) >> 0x10) | (byte)((uVar8 << 0xc) >> 0x10);
    iVar4 = iVar4 + 3;
    puVar5[2] = (byte)(uVar7 << 6) | (byte)uVar6;
    puVar5[1] = (byte)((uVar8 << 0xc) >> 8) | (byte)((uVar7 << 6) >> 8);
    puVar5 = puVar5 + 3;
  } while (iVar4 + ((n - 1U >> 2) + 1) * -3 != 0);
  return iVar4;
}

