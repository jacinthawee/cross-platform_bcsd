
int WHIRLPOOL_Final(uchar *md,WHIRLPOOL_CTX *c)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  uchar *puVar5;
  uint uVar6;
  byte bVar7;
  
  bVar7 = 0x80;
  uVar4 = c->bitoff >> 3;
  uVar6 = c->bitoff & 7;
  if (uVar6 != 0) {
    bVar7 = (byte)(0x80 >> (sbyte)uVar6) | c->data[uVar4];
  }
  c->data[uVar4] = bVar7;
  uVar6 = uVar4 + 1;
  if (uVar6 < 0x21) {
    if (uVar6 == 0x20) goto LAB_080ddbe0;
    puVar5 = c->data + uVar4 + 1;
    uVar4 = -uVar6 + 0x20;
    if (uVar4 < 4) {
      if ((uVar4 != 0) && (*puVar5 = '\0', (uVar4 & 2) != 0)) {
        *(undefined2 *)(puVar5 + -uVar6 + 0x1e) = 0;
      }
      goto LAB_080ddbe0;
    }
  }
  else {
    if (uVar6 < 0x40) {
      puVar5 = c->data + uVar4 + 1;
      iVar3 = -uVar6;
      uVar4 = iVar3 + 0x40;
      if (uVar4 < 4) {
        if ((uVar4 != 0) && (*puVar5 = '\0', (uVar4 & 2) != 0)) {
          *(undefined2 *)(puVar5 + iVar3 + 0x3e) = 0;
        }
      }
      else {
        *(undefined4 *)puVar5 = 0;
        *(undefined4 *)(puVar5 + iVar3 + 0x3c) = 0;
        if (3 < ((uint)(puVar5 + (uVar4 - ((uint)(puVar5 + 4) & 0xfffffffc))) & 0xfffffffc)) {
          uVar6 = 0;
          do {
            *(undefined4 *)(((uint)(puVar5 + 4) & 0xfffffffc) + uVar6) = 0;
            uVar6 = uVar6 + 4;
          } while (uVar6 < ((uint)(puVar5 + (uVar4 - ((uint)(puVar5 + 4) & 0xfffffffc))) &
                           0xfffffffc));
        }
      }
    }
    puVar5 = c->data;
    whirlpool_block(c,puVar5,1);
    uVar4 = 0x20;
  }
  *(undefined4 *)puVar5 = 0;
  *(undefined4 *)(puVar5 + (uVar4 - 4)) = 0;
  if (3 < ((uint)(puVar5 + (uVar4 - ((uint)(puVar5 + 4) & 0xfffffffc))) & 0xfffffffc)) {
    uVar6 = 0;
    do {
      *(undefined4 *)(((uint)(puVar5 + 4) & 0xfffffffc) + uVar6) = 0;
      uVar6 = uVar6 + 4;
    } while (uVar6 < ((uint)(puVar5 + (uVar4 - ((uint)(puVar5 + 4) & 0xfffffffc))) & 0xfffffffc));
  }
LAB_080ddbe0:
  sVar1 = c->bitlen[0];
  c->data[0x3f] = (uchar)sVar1;
  c->data[0x3e] = (uchar)(sVar1 >> 8);
  c->data[0x3c] = (uchar)(sVar1 >> 0x18);
  sVar2 = c->bitlen[1];
  c->data[0x3d] = (uchar)(sVar1 >> 0x10);
  c->data[0x3b] = (uchar)sVar2;
  c->data[0x3a] = (uchar)(sVar2 >> 8);
  c->data[0x38] = (uchar)(sVar2 >> 0x18);
  sVar1 = c->bitlen[2];
  c->data[0x39] = (uchar)(sVar2 >> 0x10);
  c->data[0x37] = (uchar)sVar1;
  c->data[0x36] = (uchar)(sVar1 >> 8);
  c->data[0x34] = (uchar)(sVar1 >> 0x18);
  sVar2 = c->bitlen[3];
  c->data[0x35] = (uchar)(sVar1 >> 0x10);
  c->data[0x33] = (uchar)sVar2;
  c->data[0x32] = (uchar)(sVar2 >> 8);
  c->data[0x30] = (uchar)(sVar2 >> 0x18);
  sVar1 = c->bitlen[4];
  c->data[0x31] = (uchar)(sVar2 >> 0x10);
  c->data[0x2f] = (uchar)sVar1;
  c->data[0x2e] = (uchar)(sVar1 >> 8);
  c->data[0x2c] = (uchar)(sVar1 >> 0x18);
  sVar2 = c->bitlen[5];
  c->data[0x2d] = (uchar)(sVar1 >> 0x10);
  c->data[0x2b] = (uchar)sVar2;
  c->data[0x2a] = (uchar)(sVar2 >> 8);
  c->data[0x28] = (uchar)(sVar2 >> 0x18);
  sVar1 = c->bitlen[6];
  c->data[0x29] = (uchar)(sVar2 >> 0x10);
  c->data[0x27] = (uchar)sVar1;
  c->data[0x26] = (uchar)(sVar1 >> 8);
  c->data[0x24] = (uchar)(sVar1 >> 0x18);
  sVar2 = c->bitlen[7];
  c->data[0x25] = (uchar)(sVar1 >> 0x10);
  c->data[0x23] = (uchar)sVar2;
  c->data[0x22] = (uchar)(sVar2 >> 8);
  c->data[0x20] = (uchar)(sVar2 >> 0x18);
  c->data[0x21] = (uchar)(sVar2 >> 0x10);
  whirlpool_block(c,c->data,1);
  if (md != (uchar *)0x0) {
    *(undefined4 *)md = *(undefined4 *)&c->H;
    *(undefined4 *)(md + 4) = *(undefined4 *)((int)&c->H + 4);
    *(undefined4 *)(md + 8) = *(undefined4 *)((int)&c->H + 8);
    *(undefined4 *)(md + 0xc) = *(undefined4 *)((int)&c->H + 0xc);
    *(undefined4 *)(md + 0x10) = *(undefined4 *)((int)&c->H + 0x10);
    *(undefined4 *)(md + 0x14) = *(undefined4 *)((int)&c->H + 0x14);
    *(undefined4 *)(md + 0x18) = *(undefined4 *)((int)&c->H + 0x18);
    *(undefined4 *)(md + 0x1c) = *(undefined4 *)((int)&c->H + 0x1c);
    *(undefined4 *)(md + 0x20) = *(undefined4 *)((int)&c->H + 0x20);
    *(undefined4 *)(md + 0x24) = *(undefined4 *)((int)&c->H + 0x24);
    *(undefined4 *)(md + 0x28) = *(undefined4 *)((int)&c->H + 0x28);
    *(undefined4 *)(md + 0x2c) = *(undefined4 *)((int)&c->H + 0x2c);
    *(undefined4 *)(md + 0x30) = *(undefined4 *)((int)&c->H + 0x30);
    *(undefined4 *)(md + 0x34) = *(undefined4 *)((int)&c->H + 0x34);
    *(undefined4 *)(md + 0x38) = *(undefined4 *)((int)&c->H + 0x38);
    *(undefined4 *)(md + 0x3c) = *(undefined4 *)((int)&c->H + 0x3c);
    OPENSSL_cleanse(c,0xa4);
  }
  return (uint)(md != (uchar *)0x0);
}

