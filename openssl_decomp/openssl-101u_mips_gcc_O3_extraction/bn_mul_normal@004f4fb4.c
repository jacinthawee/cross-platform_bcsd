
void bn_mul_normal(ulong *param_1,ulong *param_2,int param_3,ulong *param_4,int param_5)

{
  ulong uVar1;
  ulong *puVar2;
  int iVar3;
  ulong *puVar4;
  ulong *puVar5;
  
  iVar3 = param_5;
  puVar5 = param_4;
  if (param_3 < param_5) {
    iVar3 = param_3;
    puVar5 = param_2;
    param_3 = param_5;
    param_2 = param_4;
  }
  puVar4 = param_1 + param_3;
  if (iVar3 < 1) {
    bn_mul_words(param_1,param_2,param_3,0);
    return;
  }
  uVar1 = bn_mul_words(param_1,param_2,param_3,*puVar5);
  *puVar4 = uVar1;
  while( true ) {
    if (iVar3 == 1) {
      return;
    }
    uVar1 = bn_mul_add_words(param_1 + 1,param_2,param_3,puVar5[1]);
    puVar4[1] = uVar1;
    if (iVar3 == 2) {
      return;
    }
    uVar1 = bn_mul_add_words(param_1 + 2,param_2,param_3,puVar5[2]);
    puVar2 = param_1 + 3;
    param_1 = param_1 + 4;
    puVar4[2] = uVar1;
    if (iVar3 == 3) {
      return;
    }
    iVar3 = iVar3 + -4;
    uVar1 = bn_mul_add_words(puVar2,param_2,param_3,puVar5[3]);
    puVar4[3] = uVar1;
    if (iVar3 == 0) break;
    puVar2 = puVar5 + 4;
    puVar4 = puVar4 + 4;
    puVar5 = puVar5 + 4;
    uVar1 = bn_mul_add_words(param_1,param_2,param_3,*puVar2);
    *puVar4 = uVar1;
  }
  return;
}

