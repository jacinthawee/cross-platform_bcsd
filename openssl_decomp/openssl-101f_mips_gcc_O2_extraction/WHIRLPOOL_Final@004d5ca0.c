
int WHIRLPOOL_Final(uchar *md,WHIRLPOOL_CTX *c)

{
  uint uVar1;
  size_t sVar2;
  WHIRLPOOL_CTX *pWVar3;
  WHIRLPOOL_CTX *pWVar4;
  uint uVar5;
  byte bVar8;
  size_t sVar6;
  undefined4 uVar7;
  uchar *puVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  size_t sVar13;
  size_t sVar14;
  size_t sVar15;
  size_t sVar16;
  size_t sVar17;
  
  uVar5 = c->bitoff & 7;
  uVar1 = c->bitoff >> 3;
  if (uVar5 == 0) {
    bVar8 = 0x80;
  }
  else {
    bVar8 = (byte)(0x80 >> uVar5) | c->data[uVar1];
  }
  uVar5 = uVar1 + 1;
  c->data[uVar1] = bVar8;
  if (uVar5 < 0x21) {
    if (uVar5 == 0x20) goto LAB_004d5d4c;
    puVar9 = c->data + uVar1 + 1;
    iVar11 = 0x20 - uVar5;
  }
  else {
    if (uVar5 < 0x40) {
      (*(code *)PTR_memset_006aab00)(c->data + uVar1 + 1,0,0x40 - uVar5);
    }
    puVar9 = c->data;
    whirlpool_block(c,puVar9,1);
    iVar11 = 0x20;
  }
  (*(code *)PTR_memset_006aab00)(puVar9,0,iVar11);
LAB_004d5d4c:
  sVar17 = c->bitlen[0];
  sVar16 = c->bitlen[1];
  sVar15 = c->bitlen[2];
  sVar14 = c->bitlen[3];
  sVar13 = c->bitlen[4];
  sVar6 = c->bitlen[5];
  sVar2 = c->bitlen[6];
  c->data[0x3f] = (uchar)sVar17;
  c->data[0x3e] = (uchar)(sVar17 >> 8);
  c->data[0x3d] = (uchar)(sVar17 >> 0x10);
  c->data[0x3c] = (uchar)(sVar17 >> 0x18);
  c->data[0x3b] = (uchar)sVar16;
  c->data[0x3a] = (uchar)(sVar16 >> 8);
  c->data[0x39] = (uchar)(sVar16 >> 0x10);
  c->data[0x38] = (uchar)(sVar16 >> 0x18);
  c->data[0x36] = (uchar)(sVar15 >> 8);
  c->data[0x35] = (uchar)(sVar15 >> 0x10);
  c->data[0x34] = (uchar)(sVar15 >> 0x18);
  c->data[0x37] = (uchar)sVar15;
  c->data[0x33] = (uchar)sVar14;
  c->data[0x30] = (uchar)(sVar14 >> 0x18);
  c->data[0x2f] = (uchar)sVar13;
  c->data[0x2e] = (uchar)(sVar13 >> 8);
  c->data[0x2d] = (uchar)(sVar13 >> 0x10);
  c->data[0x2c] = (uchar)(sVar13 >> 0x18);
  c->data[0x2b] = (uchar)sVar6;
  c->data[0x2a] = (uchar)(sVar6 >> 8);
  c->data[0x29] = (uchar)(sVar6 >> 0x10);
  c->data[0x28] = (uchar)(sVar6 >> 0x18);
  c->data[0x27] = (uchar)sVar2;
  c->data[0x32] = (uchar)(sVar14 >> 8);
  c->data[0x31] = (uchar)(sVar14 >> 0x10);
  c->data[0x26] = (uchar)(sVar2 >> 8);
  sVar6 = c->bitlen[7];
  c->data[0x25] = (uchar)(sVar2 >> 0x10);
  c->data[0x24] = (uchar)(sVar2 >> 0x18);
  c->data[0x23] = (uchar)sVar6;
  c->data[0x22] = (uchar)(sVar6 >> 8);
  c->data[0x21] = (uchar)(sVar6 >> 0x10);
  c->data[0x20] = (uchar)(sVar6 >> 0x18);
  whirlpool_block(c,c->data,1);
  pWVar3 = c;
  if (md == (uchar *)0x0) {
    return 0;
  }
  do {
    uVar12 = *(undefined4 *)((int)&pWVar3->H + 4);
    uVar10 = *(undefined4 *)((int)&pWVar3->H + 8);
    uVar7 = *(undefined4 *)((int)&pWVar3->H + 0xc);
    pWVar4 = (WHIRLPOOL_CTX *)((int)&pWVar3->H + 0x10);
    *(undefined4 *)md = *(undefined4 *)&pWVar3->H;
    *(undefined4 *)((int)md + 4) = uVar12;
    *(undefined4 *)((int)md + 8) = uVar10;
    *(undefined4 *)((int)md + 0xc) = uVar7;
    md = (uchar *)((int)md + 0x10);
    pWVar3 = pWVar4;
  } while (pWVar4 != (WHIRLPOOL_CTX *)c->data);
  (*(code *)PTR_memset_006aab00)(c,0,0xa8);
  return 1;
}

