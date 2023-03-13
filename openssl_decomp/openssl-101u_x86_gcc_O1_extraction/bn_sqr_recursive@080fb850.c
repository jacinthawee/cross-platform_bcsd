
void bn_sqr_recursive(ulong *param_1,ulong *param_2,int param_3,ulong *param_4)

{
  uint uVar1;
  int num;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong *ap;
  uint *puVar6;
  uint uVar7;
  ulong *local_2c;
  ulong *local_24;
  
  if (param_3 == 4) {
    bn_sqr_comba4();
    return;
  }
  if (param_3 == 8) {
    bn_sqr_comba8();
    return;
  }
  if (param_3 < 0x10) {
    bn_sqr_normal();
    return;
  }
  num = param_3 >> 1;
  ap = param_2 + num;
  iVar2 = bn_cmp_words(param_2,ap,num);
  if (iVar2 < 1) {
    if (iVar2 == 0) {
      local_2c = param_4 + param_3 * 2;
      memset(param_4 + param_3,0,param_3 * 4);
      goto LAB_080fb8eb;
    }
    bn_sub_words(param_4,ap,param_2,num);
  }
  else {
    bn_sub_words(param_4,param_2,ap,num);
  }
  local_2c = param_4 + param_3 * 2;
  bn_sqr_recursive(param_4 + param_3,param_4,num,local_2c);
LAB_080fb8eb:
  local_24 = param_4 + param_3;
  bn_sqr_recursive(param_1,param_2,num,local_2c);
  bn_sqr_recursive(param_1 + param_3,ap,num,local_2c);
  uVar3 = bn_add_words(param_4,param_1,param_1 + param_3,param_3);
  uVar4 = bn_sub_words(local_24,param_4,local_24,param_3);
  uVar5 = bn_add_words(param_1 + num,param_1 + num,local_24,param_3);
  uVar7 = (uVar3 - uVar4) + uVar5;
  if (uVar7 != 0) {
    puVar6 = param_1 + param_3 + num;
    uVar1 = *puVar6;
    *puVar6 = uVar1 + uVar7;
    if (uVar1 + uVar7 < uVar7) {
      do {
        puVar6 = puVar6 + 1;
        *puVar6 = *puVar6 + 1;
      } while (*puVar6 == 0);
    }
  }
  return;
}

