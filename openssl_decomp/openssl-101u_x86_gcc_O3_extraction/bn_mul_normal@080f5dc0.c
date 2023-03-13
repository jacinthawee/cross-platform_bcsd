
void bn_mul_normal(ulong *param_1,ulong *param_2,int param_3,ulong *param_4,int param_5)

{
  ulong *puVar1;
  ulong uVar2;
  ulong *puVar3;
  int local_24;
  ulong *local_20;
  
  local_24 = param_5;
  local_20 = param_2;
  if (param_3 < param_5) {
    local_20 = param_4;
    local_24 = param_3;
    param_3 = param_5;
    param_4 = param_2;
  }
  puVar3 = param_1 + param_3;
  if (local_24 < 1) {
    bn_mul_words(param_1,local_20,param_3,0);
    return;
  }
  uVar2 = bn_mul_words(param_1,local_20,param_3,*param_4);
  *puVar3 = uVar2;
  while( true ) {
    if (local_24 == 1) {
      return;
    }
    uVar2 = bn_mul_add_words(param_1 + 1,local_20,param_3,param_4[1]);
    puVar3[1] = uVar2;
    if (local_24 == 2) {
      return;
    }
    uVar2 = bn_mul_add_words(param_1 + 2,local_20,param_3,param_4[2]);
    puVar3[2] = uVar2;
    if (local_24 == 3) {
      return;
    }
    uVar2 = bn_mul_add_words(param_1 + 3,local_20,param_3,param_4[3]);
    puVar3[3] = uVar2;
    local_24 = local_24 + -4;
    if (local_24 == 0) break;
    param_1 = param_1 + 4;
    puVar1 = param_4 + 4;
    puVar3 = puVar3 + 4;
    param_4 = param_4 + 4;
    uVar2 = bn_mul_add_words(param_1,local_20,param_3,*puVar1);
    *puVar3 = uVar2;
  }
  return;
}

