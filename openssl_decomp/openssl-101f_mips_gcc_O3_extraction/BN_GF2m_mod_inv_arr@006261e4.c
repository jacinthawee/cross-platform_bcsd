
undefined4
BN_GF2m_mod_inv_arr(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  (*(code *)PTR_BN_CTX_start_006a9644)(param_4);
  iVar1 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
  if (iVar1 == 0) {
LAB_00626298:
    uVar4 = 0;
  }
  else {
    (*(code *)PTR_BN_set_word_006a8820)(iVar1,0);
    if (*param_3 != -1) {
      piVar3 = param_3 + 1;
      do {
        iVar2 = (*(code *)PTR_BN_set_bit_006a9710)(iVar1);
        if (iVar2 == 0) goto LAB_00626298;
        iVar2 = *piVar3;
        piVar3 = piVar3 + 1;
      } while (iVar2 != -1);
    }
    uVar4 = BN_GF2m_mod_inv(param_1,param_2,iVar1,param_4);
  }
  (*(code *)PTR_BN_CTX_end_006a9654)(param_4);
  return uVar4;
}

