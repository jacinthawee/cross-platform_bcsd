
void bn_sqr_normal(ulong *param_1,ulong *param_2,int param_3,ulong *param_4)

{
  ulong uVar1;
  int iVar2;
  ulong *rp;
  ulong *puVar3;
  int num;
  ulong *puVar4;
  
  num = param_3 * 2;
  iVar2 = param_3 + -1;
  param_1[num + 0x3fffffff] = 0;
  rp = param_1 + 1;
  *param_1 = 0;
  puVar3 = param_2;
  if (0 < iVar2) {
    uVar1 = bn_mul_words(rp,param_2 + 1,iVar2,*param_2);
    rp[iVar2] = uVar1;
    rp = param_1 + 3;
    puVar3 = param_2 + 1;
  }
  iVar2 = param_3 + -2;
  if (0 < iVar2) {
    puVar4 = rp + param_3 + -3;
    do {
      uVar1 = bn_mul_add_words(rp,puVar3 + 1,iVar2,*puVar3);
      iVar2 = iVar2 + -1;
      puVar4 = puVar4 + 1;
      *puVar4 = uVar1;
      rp = rp + 2;
      puVar3 = puVar3 + 1;
    } while (iVar2 != 0);
  }
  bn_add_words(param_1,param_1,param_1,num);
  bn_sqr_words(param_4,param_2,param_3);
  bn_add_words(param_1,param_1,param_4,num);
  return;
}

