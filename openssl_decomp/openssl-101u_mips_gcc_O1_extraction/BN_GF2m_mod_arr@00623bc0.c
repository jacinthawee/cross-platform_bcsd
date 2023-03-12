
undefined4 BN_GF2m_mod_arr(int *param_1,int *param_2,int *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if (*param_3 == 0) {
    (*(code *)PTR_BN_set_word_006a7730)(param_1,0,param_3,param_4,&_gp);
    return 1;
  }
  if (param_1 != param_2) {
    iVar5 = param_2[1];
    if (param_1[2] < iVar5) {
      iVar5 = (*(code *)PTR_bn_expand2_006a8524)();
      if (iVar5 == 0) {
        return 0;
      }
      iVar5 = param_2[1];
    }
    iVar3 = 0;
    if (0 < iVar5) {
      puVar4 = (undefined4 *)*param_2;
      puVar1 = (undefined4 *)*param_1;
      do {
        iVar3 = iVar3 + 1;
        *puVar1 = *puVar4;
        iVar5 = param_2[1];
        puVar4 = puVar4 + 1;
        puVar1 = puVar1 + 1;
      } while (iVar3 < iVar5);
    }
    param_1[1] = iVar5;
  }
  uVar2 = BN_GF2m_mod_arr_part_0(param_1,param_3);
  return uVar2;
}

