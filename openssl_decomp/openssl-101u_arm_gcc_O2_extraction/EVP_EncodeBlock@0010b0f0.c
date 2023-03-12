
int EVP_EncodeBlock(uchar *t,uchar *f,int n)

{
  uchar uVar1;
  uchar uVar2;
  uchar *puVar3;
  int iVar4;
  uint uVar5;
  uchar *puVar6;
  uchar *puVar7;
  uchar *puVar8;
  uchar uVar9;
  
  if (0 < n) {
    puVar7 = f + 3;
    iVar4 = 0;
    puVar3 = t + 4;
    puVar8 = puVar7;
    do {
      puVar6 = puVar3;
      if (n < 3) {
        uVar9 = '=';
        uVar5 = (uint)puVar7[-3] << 0x10;
        if (n == 2) {
          uVar1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                  [((uVar5 | (uint)f[1] << 8) << 0xe) >> 0x1a];
          uVar9 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                  [((uint)f[1] << 8 & 0xfc0) >> 6];
          puVar6[-4] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                       [uVar5 >> 0x12];
          t[1] = uVar1;
        }
        else {
          uVar1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                  [uVar5 >> 0xc & 0x3f];
          puVar6[-4] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                       [uVar5 >> 0x12];
          t[1] = uVar1;
        }
        t[2] = uVar9;
        t[3] = '=';
      }
      else {
        uVar5 = (uint)CONCAT12(puVar7[-3],CONCAT11(f[1],f[2]));
        uVar1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                [(uVar5 << 0xe) >> 0x1a];
        uVar2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                [(uVar5 << 0x14) >> 0x1a];
        uVar9 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[uVar5 & 0x3f];
        puVar6[-4] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                     [puVar7[-3] >> 2];
        t[1] = uVar1;
        t[2] = uVar2;
        t[3] = uVar9;
      }
      n = n + -3;
      iVar4 = iVar4 + 4;
      puVar7 = puVar7 + 3;
      t = t + 4;
      f = puVar8;
      puVar3 = puVar6 + 4;
      puVar8 = puVar8 + 3;
    } while (0 < n);
    *puVar6 = '\0';
    return iVar4;
  }
  *t = '\0';
  return 0;
}

