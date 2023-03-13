
/* WARNING: Could not reconcile some variable overlaps */

void WHIRLPOOL_BitUpdate(WHIRLPOOL_CTX *c,void *inp,size_t bits)

{
  byte *pbVar1;
  uchar *puVar2;
  size_t *psVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  void *__src;
  void *pvVar11;
  sbyte local_2c;
  int local_28;
  byte local_24;
  
  uVar9 = c->bitoff;
  uVar5 = uVar9 & 7;
  uVar6 = -bits & 7;
  uVar7 = bits + c->bitlen[0];
  c->bitlen[0] = uVar7;
  if (uVar7 < bits) {
    psVar3 = c->bitlen + 1;
    *psVar3 = *psVar3 + 1;
    if (*psVar3 == 0) {
      psVar3 = c->bitlen + 2;
      *psVar3 = *psVar3 + 1;
      if (*psVar3 == 0) {
        psVar3 = c->bitlen + 3;
        *psVar3 = *psVar3 + 1;
        if (*psVar3 == 0) {
          psVar3 = c->bitlen + 4;
          *psVar3 = *psVar3 + 1;
          if (*psVar3 == 0) {
            psVar3 = c->bitlen + 5;
            *psVar3 = *psVar3 + 1;
            if (*psVar3 == 0) {
              psVar3 = c->bitlen + 6;
              *psVar3 = *psVar3 + 1;
              if (*psVar3 == 0) {
                c->bitlen[7] = c->bitlen[7] + 1;
              }
            }
          }
        }
      }
    }
  }
  __src = inp;
  if (((-bits | uVar9) & 7) == 0) {
LAB_080dd978:
    if (bits != 0) {
      puVar2 = c->data;
      do {
        if ((uVar9 == 0) && (uVar5 = bits >> 9, uVar5 != 0)) {
          bits = bits & 0x1ff;
          whirlpool_block(c,__src,uVar5);
          pvVar11 = (void *)((int)__src + uVar5 * 0x40);
        }
        else {
          uVar5 = 0x200 - uVar9;
          uVar6 = uVar9 >> 3;
          if (bits < uVar5) {
            uVar5 = bits >> 3;
            uVar9 = uVar9 + bits;
            bits = 0;
            memcpy(puVar2 + uVar6,__src,uVar5);
            pvVar11 = __src;
          }
          else {
            bits = bits - uVar5;
            pvVar11 = (void *)((int)__src + (uVar5 >> 3));
            uVar9 = 0;
            memcpy(puVar2 + uVar6,__src,uVar5 >> 3);
            whirlpool_block(c,puVar2,1);
          }
          c->bitoff = uVar9;
        }
        __src = pvVar11;
      } while (bits != 0);
    }
    return;
  }
  if (bits == 0) {
    return;
  }
  uVar7 = uVar9 >> 3;
  local_2c = (sbyte)uVar5;
  if (uVar5 == uVar6) {
    __src = (void *)((int)inp + 1);
                    /* WARNING: Load size is inaccurate */
    c->data[uVar7] = c->data[uVar7] | (byte)(0xff >> local_2c) & *inp;
    bits = bits - (8 - uVar5);
    uVar9 = uVar9 + (8 - uVar5);
    if (uVar9 == 0x200) {
      uVar9 = 0;
      whirlpool_block(c,c->data,1);
    }
    c->bitoff = uVar9;
    goto LAB_080dd978;
  }
  local_28._0_1_ = (sbyte)uVar6;
  if (uVar5 == 0) {
    local_24 = 8 - (sbyte)local_28;
    while (7 < bits) {
      pbVar1 = (byte *)((int)inp + 1);
      uVar9 = uVar9 + 8;
                    /* WARNING: Load size is inaccurate */
      bVar4 = *inp;
      bits = bits - 8;
      inp = (void *)((int)inp + 1);
      c->data[uVar7] = (byte)((int)(uint)*pbVar1 >> (local_24 & 0x1f)) | bVar4 << (sbyte)local_28;
      if (0x1ff < uVar9) {
        uVar9 = uVar9 & 0x1ff;
        whirlpool_block(c,c->data,1);
      }
      c->bitoff = uVar9;
      if (bits == 0) {
        return;
      }
      uVar7 = uVar9 >> 3;
    }
                    /* WARNING: Load size is inaccurate */
    uVar9 = uVar9 + bits;
    uVar6 = (uint)*inp << (sbyte)local_28;
    c->data[uVar7] = (uchar)uVar6;
    if (uVar9 != 0x200) goto LAB_080dd8e2;
LAB_080dd910:
    whirlpool_block(c,c->data,1);
    if (uVar5 == 0) {
      uVar9 = 0;
      goto LAB_080dd8e2;
    }
    local_28 = 0;
    uVar9 = 0;
    uVar8 = uVar6 & 0xff;
  }
  else {
    local_24 = 8 - (sbyte)local_28;
    while (7 < bits) {
      pbVar1 = (byte *)((int)inp + 1);
      uVar9 = uVar9 + 8;
                    /* WARNING: Load size is inaccurate */
      bVar4 = *inp;
      bits = bits - 8;
      inp = (void *)((int)inp + 1);
      uVar6 = ((int)(uint)*pbVar1 >> (local_24 & 0x1f) | (uint)bVar4 << (sbyte)local_28) & 0xff;
      c->data[uVar7] = c->data[uVar7] | (byte)((int)uVar6 >> local_2c);
      iVar10 = uVar7 + 1;
      if (0x1ff < uVar9) {
        uVar9 = uVar9 & 0x1ff;
        iVar10 = 0;
        whirlpool_block(c,c->data,1);
      }
      c->data[iVar10] = (uchar)(uVar6 << (8U - local_2c & 0x1f));
      c->bitoff = uVar9;
      if (bits == 0) {
        return;
      }
      uVar7 = uVar9 >> 3;
    }
                    /* WARNING: Load size is inaccurate */
    local_28 = uVar7 + 1;
    uVar9 = uVar9 + bits;
    uVar6 = (uint)*inp << (sbyte)local_28;
    uVar8 = uVar6 & 0xff;
    c->data[uVar7] = c->data[uVar7] | (byte)((int)uVar8 >> local_2c);
    if (uVar9 == 0x200) goto LAB_080dd910;
  }
  c->data[local_28] = (uchar)(uVar8 << (8U - local_2c & 0x1f));
LAB_080dd8e2:
  c->bitoff = uVar9;
  return;
}

