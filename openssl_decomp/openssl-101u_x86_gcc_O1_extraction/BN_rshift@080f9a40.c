
int BN_rshift(BIGNUM *r,BIGNUM *a,int n)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  BIGNUM *pBVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  sbyte local_2c;
  byte local_28;
  
  if (n < 0) {
    ERR_put_error(3,0x92,0x77,"bn_shift.c",0xb7);
    return 0;
  }
  iVar6 = n >> 5;
  if ((a->top != 0) && (iVar6 < a->top)) {
    iVar2 = BN_num_bits(a);
    iVar3 = (iVar2 - n) + 0x1f;
    iVar2 = (iVar2 - n) + 0x3e;
    if (-1 < iVar3) {
      iVar2 = iVar3;
    }
    iVar2 = iVar2 >> 5;
    if (a == r) {
      if (n == 0) {
        return 1;
      }
    }
    else {
      r->neg = a->neg;
      if ((r->dmax < iVar2) && (pBVar4 = bn_expand2(r,iVar2), pBVar4 == (BIGNUM *)0x0)) {
        return 0;
      }
    }
    iVar3 = a->top - iVar6;
    puVar1 = a->d + iVar6;
    puVar5 = r->d;
    r->top = iVar2;
    if ((n & 0x1fU) == 0) {
      if (iVar3 != 0) {
        iVar6 = 0;
        do {
          puVar5[iVar6] = puVar1[iVar6];
          iVar6 = iVar6 + 1;
        } while (iVar3 != iVar6);
      }
    }
    else {
      uVar7 = *puVar1;
      local_2c = (sbyte)(n & 0x1fU);
      if (iVar3 != 1) {
        local_28 = 0x20 - local_2c;
        iVar6 = 0;
        do {
          uVar8 = uVar7 >> local_2c;
          uVar7 = puVar1[iVar6 + 1];
          puVar5[iVar6] = uVar8 | uVar7 << (local_28 & 0x1f);
          iVar6 = iVar6 + 1;
        } while (iVar3 + -1 != iVar6);
        puVar5 = puVar5 + iVar3 + -1;
      }
      if (uVar7 >> local_2c != 0) {
        *puVar5 = uVar7 >> local_2c;
      }
    }
    return 1;
  }
  BN_set_word(r,0);
  return 1;
}

