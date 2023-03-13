
int EVP_EncodeBlock(uchar *t,uchar *f,int n)

{
  byte bVar1;
  uchar uVar2;
  uchar *puVar3;
  uchar uVar4;
  uint uVar5;
  int local_14;
  
  if (n < 1) {
    local_14 = 0;
  }
  else {
    local_14 = 0;
    puVar3 = t;
    do {
      t = puVar3 + 4;
      if (n < 3) {
        uVar5 = (uint)*f << 0x10;
        if (n == 2) {
          bVar1 = f[1];
          *puVar3 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                    [uVar5 >> 0x12];
          puVar3[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                      [(uVar5 | (uint)bVar1 << 8) >> 0xc & 0x3f];
          uVar4 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                  [((uint)bVar1 << 8 & 0xfc0) >> 6];
        }
        else {
          *puVar3 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                    [uVar5 >> 0x12];
          puVar3[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                      [uVar5 >> 0xc & 0x3f];
          uVar4 = '=';
        }
        puVar3[2] = uVar4;
        puVar3[3] = '=';
      }
      else {
        uVar5 = (uint)f[1] << 8 | (uint)*f << 0x10;
        bVar1 = f[2];
        *puVar3 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                  [((uint)*f << 0x10) >> 0x12];
        uVar4 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[bVar1 & 0x3f];
        puVar3[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                    [(uVar5 & 0x3f000) >> 0xc];
        uVar2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                [(uVar5 | bVar1) >> 6 & 0x3f];
        puVar3[3] = uVar4;
        puVar3[2] = uVar2;
      }
      n = n + -3;
      local_14 = local_14 + 4;
      f = f + 3;
      puVar3 = t;
    } while (0 < n);
  }
  *t = '\0';
  return local_14;
}

