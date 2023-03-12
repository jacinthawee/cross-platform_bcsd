
int BN_rshift(BIGNUM *r,BIGNUM *a,int n)

{
  int iVar1;
  ulong *puVar2;
  BIGNUM *pBVar3;
  int iVar4;
  ulong *puVar5;
  uint uVar6;
  uint uVar7;
  ulong *puVar8;
  uint uVar9;
  int iVar10;
  
  if (n < 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x92,0x77,"bn_shift.c",0xb7);
    return 0;
  }
  iVar10 = n >> 5;
  if ((a->top <= iVar10) || (a->top == 0)) {
    BN_set_word(r,0);
    return 1;
  }
  iVar1 = BN_num_bits(a);
  iVar4 = (iVar1 - n) + 0x1f;
  if (iVar4 < 0) {
    iVar4 = (iVar1 - n) + 0x3e;
  }
  iVar4 = iVar4 >> 5;
  if (a == r) {
    if (n == 0) {
      return 1;
    }
  }
  else {
    r->neg = a->neg;
    if (r->dmax < iVar4) {
      pBVar3 = bn_expand2(r,iVar4);
      if (pBVar3 == (BIGNUM *)0x0) {
        return 0;
      }
      puVar2 = a->d;
      goto LAB_004fa044;
    }
  }
  puVar2 = a->d;
LAB_004fa044:
  iVar1 = a->top;
  uVar6 = n & 0x1f;
  puVar5 = r->d;
  puVar2 = puVar2 + iVar10;
  r->top = iVar4;
  iVar1 = iVar1 - iVar10;
  if (uVar6 == 0) {
    for (; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar2;
      puVar5 = puVar5 + 1;
      puVar2 = puVar2 + 1;
    }
  }
  else {
    iVar10 = iVar1 + -1;
    uVar7 = *puVar2;
    if (iVar10 != 0) {
      puVar8 = puVar5;
      do {
        puVar2 = puVar2 + 1;
        uVar9 = uVar7 >> uVar6;
        uVar7 = *puVar2;
        iVar10 = iVar10 + -1;
        *puVar8 = uVar7 << (0x20 - uVar6 & 0x1f) | uVar9;
        puVar8 = puVar8 + 1;
      } while (iVar10 != 0);
      puVar5 = puVar5 + iVar1 + -1;
    }
    if (uVar7 >> uVar6 != 0) {
      *puVar5 = uVar7 >> uVar6;
      return 1;
    }
  }
  return 1;
}

