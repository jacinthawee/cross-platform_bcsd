
void bn_sqr_recursive(ulong *param_1,ulong *param_2,int param_3,ulong *param_4)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  int num;
  uint *puVar7;
  ulong *puVar8;
  ulong *rp;
  code *UNRECOVERED_JUMPTABLE;
  ulong *ap;
  
  UNRECOVERED_JUMPTABLE = (code *)PTR_bn_sqr_comba4_006a9704;
  if ((param_3 == 4) || (UNRECOVERED_JUMPTABLE = (code *)PTR_bn_sqr_comba8_006a9708, param_3 == 8))
  {
                    /* WARNING: Could not recover jumptable at 0x004fed60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  num = param_3 >> 1;
  if (param_3 < 0x10) {
    bn_sqr_normal();
    return;
  }
  ap = param_2 + num;
  iVar1 = bn_cmp_words(param_2,ap,num);
  if (iVar1 < 1) {
    if (iVar1 == 0) {
      (*(code *)PTR_memset_006aab00)(param_4 + param_3,0,param_3 * 4);
      puVar8 = param_4 + param_3 * 2;
      goto LAB_004febe0;
    }
    bn_sub_words(param_4,ap,param_2,num);
  }
  else {
    bn_sub_words(param_4,param_2,ap,num);
  }
  puVar8 = param_4 + param_3 * 2;
  bn_sqr_recursive(param_4 + param_3,param_4,num,puVar8);
LAB_004febe0:
  rp = param_4 + param_3;
  bn_sqr_recursive(param_1,param_2,num,puVar8);
  bn_sqr_recursive(param_1 + param_3,ap,num,puVar8);
  uVar2 = bn_add_words(param_4,param_1,param_1 + param_3,param_3);
  uVar3 = bn_sub_words(rp,param_4,rp,param_3);
  uVar4 = bn_add_words(param_1 + num,param_1 + num,rp,param_3);
  uVar5 = uVar4 + (uVar2 - uVar3);
  if (uVar5 != 0) {
    puVar7 = param_1 + param_3 + num;
    uVar6 = *puVar7;
    *puVar7 = uVar5 + uVar6;
    if (uVar5 + uVar6 < uVar5) {
      do {
        puVar7 = puVar7 + 1;
        uVar5 = *puVar7;
        *puVar7 = uVar5 + 1;
      } while (uVar5 + 1 == 0);
    }
  }
  return;
}

