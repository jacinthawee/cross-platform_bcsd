
void WHIRLPOOL_BitUpdate(WHIRLPOOL_CTX *c,void *inp,size_t bits)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  size_t sVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uchar *puVar8;
  uint uVar9;
  uint uVar10;
  
  uVar3 = bits + c->bitlen[0];
  uVar10 = -bits & 7;
  c->bitlen[0] = uVar3;
  uVar6 = c->bitoff;
  uVar9 = uVar6 & 7;
  if (((((uVar3 < bits) && (sVar4 = c->bitlen[1] + 1, c->bitlen[1] = sVar4, sVar4 == 0)) &&
       (sVar4 = c->bitlen[2] + 1, c->bitlen[2] = sVar4, sVar4 == 0)) &&
      ((sVar4 = c->bitlen[3] + 1, c->bitlen[3] = sVar4, sVar4 == 0 &&
       (sVar4 = c->bitlen[4] + 1, c->bitlen[4] = sVar4, sVar4 == 0)))) &&
     ((sVar4 = c->bitlen[5] + 1, c->bitlen[5] = sVar4, sVar4 == 0 &&
      (sVar4 = c->bitlen[6] + 1, c->bitlen[6] = sVar4, sVar4 == 0)))) {
    c->bitlen[7] = c->bitlen[7] + 1;
  }
  if (uVar10 == 0) {
    if (uVar9 == 0) goto LAB_004d5a50;
    if (bits == 0) {
      return;
    }
LAB_004d58a8:
    uVar3 = uVar6 >> 3;
    if (7 < bits) {
      do {
        uVar6 = uVar6 + 8;
                    /* WARNING: Load size is inaccurate */
        uVar7 = ((int)(uint)*(byte *)((int)inp + 1) >> (8 - uVar10 & 0x1f) | (uint)*inp << uVar10) &
                0xff;
        bits = bits - 8;
        c->data[uVar3] = (byte)((int)uVar7 >> uVar9) | c->data[uVar3];
        inp = (void *)((int)inp + 1);
        if (uVar6 < 0x200) {
          iVar5 = uVar3 + 1;
        }
        else {
          uVar6 = uVar6 & 0x1ff;
          whirlpool_block(c,c->data,1);
          iVar5 = 0;
        }
        uVar3 = uVar6 >> 3;
        c->data[iVar5] = (uchar)(uVar7 << (8 - uVar9 & 0x1f));
        c->bitoff = uVar6;
        if (bits == 0) {
          return;
        }
      } while (7 < bits);
    }
                    /* WARNING: Load size is inaccurate */
    uVar6 = bits + uVar6;
    uVar10 = (uint)*inp << uVar10;
    iVar5 = uVar3 + 1;
    uVar7 = uVar10 & 0xff;
    c->data[uVar3] = (byte)((int)uVar7 >> uVar9) | c->data[uVar3];
    if (uVar6 == 0x200) goto LAB_004d59e8;
  }
  else {
    if (bits == 0) {
      return;
    }
    uVar3 = uVar6 >> 3;
    if (uVar9 == uVar10) {
                    /* WARNING: Load size is inaccurate */
      uVar6 = uVar6 + (8 - uVar9);
      c->data[uVar3] = (byte)(0xff >> uVar9) & *inp | c->data[uVar3];
      bits = bits - (8 - uVar9);
      inp = (void *)((int)inp + 1);
      if (uVar6 == 0x200) {
        uVar6 = 0;
        whirlpool_block(c,c->data,1);
        c->bitoff = 0;
      }
      else {
        c->bitoff = uVar6;
      }
LAB_004d5a50:
      if (bits == 0) {
        return;
      }
      puVar8 = c->data;
      do {
        while( true ) {
          uVar3 = 0x200 - uVar6;
          if ((uVar6 != 0) || (uVar10 = bits >> 9, uVar10 == 0)) break;
          bits = bits & 0x1ff;
          whirlpool_block(c,inp,uVar10);
          inp = (void *)((int)inp + uVar10 * 0x40);
          if (bits == 0) {
            return;
          }
        }
        uVar10 = uVar6 >> 3;
        if (bits < uVar3) {
          uVar6 = uVar6 + bits;
          (*(code *)PTR_memcpy_006aabf4)(puVar8 + uVar10,inp,bits >> 3);
          bits = 0;
          c->bitoff = uVar6;
        }
        else {
          bits = bits - uVar3;
          (*(code *)PTR_memcpy_006aabf4)(puVar8 + uVar10,inp,uVar3 >> 3);
          uVar6 = 0;
          inp = (void *)((int)inp + (uVar3 >> 3));
          whirlpool_block(c,puVar8,1);
          c->bitoff = 0;
        }
      } while (bits != 0);
      return;
    }
    if (uVar9 != 0) goto LAB_004d58a8;
    while (7 < bits) {
      pbVar1 = (byte *)((int)inp + 1);
      uVar6 = uVar6 + 8;
                    /* WARNING: Load size is inaccurate */
      bVar2 = *inp;
      bits = bits - 8;
      inp = (void *)((int)inp + 1);
      c->data[uVar3] = (byte)((int)(uint)*pbVar1 >> (8 - uVar10 & 0x1f)) | bVar2 << uVar10;
      if (0x1ff < uVar6) {
        whirlpool_block(c,c->data,1);
        uVar6 = uVar6 & 0x1ff;
      }
      c->bitoff = uVar6;
      uVar3 = uVar6 >> 3;
      if (bits == 0) {
        return;
      }
    }
                    /* WARNING: Load size is inaccurate */
    uVar6 = uVar6 + bits;
    uVar10 = (uint)*inp << uVar10;
    c->data[uVar3] = (uchar)uVar10;
    if (uVar6 != 0x200) goto LAB_004d5990;
LAB_004d59e8:
    whirlpool_block(c,c->data,1);
    uVar6 = 0;
    if (uVar9 == 0) goto LAB_004d5990;
    iVar5 = 0;
    uVar7 = uVar10 & 0xff;
  }
  c->data[iVar5] = (uchar)(uVar7 << (8 - uVar9 & 0x1f));
LAB_004d5990:
  c->bitoff = uVar6;
  return;
}

