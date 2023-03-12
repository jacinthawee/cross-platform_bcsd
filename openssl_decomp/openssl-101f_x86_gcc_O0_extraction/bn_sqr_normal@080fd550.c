
void bn_sqr_normal(ulong *param_1,ulong *param_2,int param_3,ulong *param_4)

{
  ulong uVar1;
  int iVar2;
  ulong *puVar3;
  ulong *ap;
  ulong *rp;
  
  puVar3 = param_1 + 1;
  param_1[param_3 * 2 + -1] = 0;
  *param_1 = 0;
  iVar2 = param_3 + -1;
  ap = param_2;
  rp = puVar3;
  if (0 < iVar2) {
    ap = param_2 + 1;
    rp = param_1 + 3;
    uVar1 = bn_mul_words(puVar3,ap,iVar2,*param_2);
    puVar3[iVar2] = uVar1;
  }
  iVar2 = param_3 + -2;
  puVar3 = rp + iVar2;
  if (0 < iVar2) {
    do {
      uVar1 = bn_mul_add_words(rp,ap + 1,iVar2,*ap);
      *puVar3 = uVar1;
      iVar2 = iVar2 + -1;
      puVar3 = puVar3 + 1;
      ap = ap + 1;
      rp = rp + 2;
    } while (iVar2 != 0);
  }
  bn_add_words(param_1,param_1,param_1,param_3 * 2);
  bn_sqr_words(param_4,param_2,param_3);
  bn_add_words(param_1,param_1,param_4,param_3 * 2);
  return;
}

