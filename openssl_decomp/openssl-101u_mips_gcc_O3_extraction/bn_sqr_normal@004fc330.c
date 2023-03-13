
void bn_sqr_normal(ulong *param_1,ulong *param_2,int param_3,ulong *param_4)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  ulong *puVar4;
  ulong *rp;
  ulong *puVar5;
  
  iVar2 = param_3 + -1;
  rp = param_1 + 1;
  param_1[param_3 * 2 + -1] = 0;
  *param_1 = 0;
  puVar4 = param_2;
  if (0 < iVar2) {
    puVar4 = rp + iVar2;
    uVar1 = bn_mul_words(rp,param_2 + 1,iVar2,*param_2);
    rp = param_1 + 3;
    *puVar4 = uVar1;
    puVar4 = param_2 + 1;
  }
  if (0 < param_3 + -2) {
    puVar5 = rp + param_3;
    iVar2 = param_3 + -2;
    do {
      iVar3 = iVar2 + -1;
      uVar1 = bn_mul_add_words(rp,puVar4 + 1,iVar2,*puVar4);
      rp = rp + 2;
      puVar5[-2] = uVar1;
      puVar5 = puVar5 + 1;
      iVar2 = iVar3;
      puVar4 = puVar4 + 1;
    } while (iVar3 != 0);
  }
  bn_add_words(param_1,param_1,param_1,param_3 << 1);
  bn_sqr_words(param_4,param_2,param_3);
  bn_add_words(param_1,param_1,param_4,param_3 << 1);
  return;
}

