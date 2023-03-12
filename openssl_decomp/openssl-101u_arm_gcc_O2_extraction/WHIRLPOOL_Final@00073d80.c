
int WHIRLPOOL_Final(uchar *md,WHIRLPOOL_CTX *c)

{
  byte bVar1;
  uchar *__s;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  size_t sVar5;
  undefined4 uVar6;
  uint uVar7;
  WHIRLPOOL_CTX *pWVar8;
  WHIRLPOOL_CTX *pWVar9;
  size_t sVar10;
  size_t sVar11;
  size_t sVar12;
  size_t sVar13;
  size_t sVar14;
  size_t sVar15;
  
  uVar4 = c->bitoff >> 3;
  uVar7 = c->bitoff & 7;
  bVar1 = 0x80;
  if (uVar7 != 0) {
    bVar1 = c->data[uVar4] | (byte)(0x80 >> uVar7);
  }
  uVar7 = uVar4 + 1;
  c->data[uVar4] = bVar1;
  if (uVar7 < 0x21) {
    if (uVar7 == 0x20) goto LAB_00073dd6;
    sVar5 = 0x1f - uVar4;
    __s = c->data + uVar4 + 1;
  }
  else {
    if (uVar7 < 0x40) {
      memset(c->data + uVar4 + 1,0,0x3f - uVar4);
    }
    __s = c->data;
    whirlpool_block(c,__s,1);
    sVar5 = 0x20;
  }
  memset(__s,0,sVar5);
LAB_00073dd6:
  sVar13 = c->bitlen[0];
  sVar15 = c->bitlen[2];
  sVar12 = c->bitlen[3];
  sVar11 = c->bitlen[4];
  sVar10 = c->bitlen[5];
  sVar14 = c->bitlen[1];
  sVar5 = c->bitlen[6];
  c->data[0x3e] = (uchar)(sVar13 >> 8);
  c->data[0x3f] = (uchar)sVar13;
  c->data[0x3b] = (uchar)sVar14;
  c->data[0x3d] = (uchar)(sVar13 >> 0x10);
  c->data[0x3c] = (uchar)(sVar13 >> 0x18);
  c->data[0x3a] = (uchar)(sVar14 >> 8);
  c->data[0x39] = (uchar)(sVar14 >> 0x10);
  c->data[0x38] = (uchar)(sVar14 >> 0x18);
  c->data[0x37] = (uchar)sVar15;
  c->data[0x36] = (uchar)(sVar15 >> 8);
  c->data[0x35] = (uchar)(sVar15 >> 0x10);
  c->data[0x34] = (uchar)(sVar15 >> 0x18);
  c->data[0x33] = (uchar)sVar12;
  c->data[0x32] = (uchar)(sVar12 >> 8);
  c->data[0x31] = (uchar)(sVar12 >> 0x10);
  c->data[0x30] = (uchar)(sVar12 >> 0x18);
  c->data[0x2f] = (uchar)sVar11;
  c->data[0x2e] = (uchar)(sVar11 >> 8);
  c->data[0x2d] = (uchar)(sVar11 >> 0x10);
  c->data[0x2c] = (uchar)(sVar11 >> 0x18);
  c->data[0x2b] = (uchar)sVar10;
  c->data[0x28] = (uchar)(sVar10 >> 0x18);
  c->data[0x2a] = (uchar)(sVar10 >> 8);
  c->data[0x29] = (uchar)(sVar10 >> 0x10);
  c->data[0x27] = (uchar)sVar5;
  sVar10 = c->bitlen[7];
  c->data[0x26] = (uchar)(sVar5 >> 8);
  c->data[0x25] = (uchar)(sVar5 >> 0x10);
  c->data[0x23] = (uchar)sVar10;
  c->data[0x24] = (uchar)(sVar5 >> 0x18);
  c->data[0x22] = (uchar)(sVar10 >> 8);
  c->data[0x21] = (uchar)(sVar10 >> 0x10);
  c->data[0x20] = (uchar)(sVar10 >> 0x18);
  whirlpool_block(c,c->data,1);
  pWVar8 = c;
  if (md != (uchar *)0x0) {
    do {
      pWVar9 = (WHIRLPOOL_CTX *)((int)&pWVar8->H + 0x10);
      uVar2 = *(undefined4 *)((int)&pWVar8->H + 4);
      uVar3 = *(undefined4 *)((int)&pWVar8->H + 8);
      uVar6 = *(undefined4 *)((int)&pWVar8->H + 0xc);
      *(undefined4 *)md = *(undefined4 *)&pWVar8->H;
      *(undefined4 *)((int)md + 4) = uVar2;
      *(undefined4 *)((int)md + 8) = uVar3;
      *(undefined4 *)((int)md + 0xc) = uVar6;
      pWVar8 = pWVar9;
      md = (uchar *)((int)md + 0x10);
    } while (pWVar9 != (WHIRLPOOL_CTX *)c->data);
    OPENSSL_cleanse(c,0xa8);
    md = (uchar *)0x1;
  }
  return (int)md;
}

