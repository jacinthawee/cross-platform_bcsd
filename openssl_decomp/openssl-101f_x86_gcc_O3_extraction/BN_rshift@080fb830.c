
int BN_rshift(BIGNUM *r,BIGNUM *a,int n)

{
  uint *puVar1;
  ulong *puVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  BIGNUM *pBVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  byte local_2c;
  byte local_28;
  
  iVar7 = n + 0x1f;
  if (-1 < n) {
    iVar7 = n;
  }
  iVar7 = iVar7 >> 5;
  if ((a->top != 0) && (iVar7 < a->top)) {
    iVar3 = BN_num_bits(a);
    iVar4 = (iVar3 - n) + 0x1f;
    iVar3 = (iVar3 - n) + 0x3e;
    if (-1 < iVar4) {
      iVar3 = iVar4;
    }
    iVar3 = iVar3 >> 5;
    if (a == r) {
      if (n == 0) {
        return 1;
      }
    }
    else {
      r->neg = a->neg;
      if ((r->dmax < iVar3) && (pBVar6 = bn_expand2(r,iVar3), pBVar6 == (BIGNUM *)0x0)) {
        return 0;
      }
    }
    puVar2 = a->d;
    iVar4 = a->top;
    r->top = iVar3;
    iVar4 = iVar4 - iVar7;
    puVar1 = puVar2 + iVar7;
    puVar5 = r->d;
    if (n % 0x20 == 0) {
      if (iVar4 != 0) {
        iVar7 = 0;
        do {
          puVar5[iVar7] = puVar1[iVar7];
          iVar7 = iVar7 + 1;
        } while (iVar4 != iVar7);
      }
    }
    else {
      uVar9 = *puVar1;
      local_2c = (byte)(n % 0x20);
      if (iVar4 != 1) {
        local_28 = 0x20 - local_2c;
        iVar7 = 0;
        do {
          uVar8 = uVar9 >> (local_2c & 0x1f);
          uVar9 = puVar1[iVar7 + 1];
          puVar5[iVar7] = uVar8 | uVar9 << (local_28 & 0x1f);
          iVar7 = iVar7 + 1;
        } while (iVar4 + -1 != iVar7);
        puVar5 = puVar5 + iVar4 + -1;
      }
      uVar9 = uVar9 >> (local_2c & 0x1f);
      if (uVar9 != 0) {
        *puVar5 = uVar9;
      }
    }
    return 1;
  }
  BN_set_word(r,0);
  return 1;
}

