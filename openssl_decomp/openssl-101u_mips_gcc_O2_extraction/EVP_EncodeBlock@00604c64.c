
int EVP_EncodeBlock(uchar *t,uchar *f,int n)

{
  uchar uVar1;
  uchar uVar2;
  byte bVar3;
  uchar *puVar4;
  int iVar5;
  uint uVar6;
  uchar uVar7;
  
  if (n < 1) {
    iVar5 = 0;
  }
  else {
    iVar5 = 0;
    puVar4 = t + 4;
    do {
      t = puVar4;
      uVar7 = '=';
      if (n < 3) {
        uVar6 = (uint)*f << 0x10;
        if (n == 2) {
          bVar3 = f[1];
          uVar7 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                  [(((uint)bVar3 << 8 | uVar6) << 0xe) >> 0x1a];
          t[-4] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[uVar6 >> 0x12];
          t[-3] = uVar7;
          uVar7 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                  [((uint)bVar3 << 8 & 0xfc0) >> 6];
        }
        else {
          uVar1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                  [uVar6 >> 0xc & 0x3f];
          t[-4] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[uVar6 >> 0x12];
          t[-3] = uVar1;
        }
        t[-1] = '=';
        t[-2] = uVar7;
      }
      else {
        uVar6 = (uint)*f << 0x10 | (uint)f[1] << 8 | (uint)f[2];
        uVar7 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                [(uVar6 << 0xe) >> 0x1a];
        uVar1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                [(uVar6 << 0x14) >> 0x1a];
        uVar2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[f[2] & 0x3f];
        t[-4] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                [((uint)*f << 0x10) >> 0x12];
        t[-3] = uVar7;
        t[-2] = uVar1;
        t[-1] = uVar2;
      }
      n = n + -3;
      iVar5 = iVar5 + 4;
      f = f + 3;
      puVar4 = t + 4;
    } while (0 < n);
  }
  *t = '\0';
  return iVar5;
}

