
undefined4
BN_GF2m_mod_sqrt_arr(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*param_3 == 0) {
    (*(code *)PTR_BN_set_word_006a7730)(param_1,0);
    return 1;
  }
  (*(code *)PTR_BN_CTX_start_006a8528)(param_4);
  iVar1 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
  if (iVar1 != 0) {
    iVar2 = (*(code *)PTR_BN_set_bit_006a85ec)(iVar1,*param_3 + -1);
    if (iVar2 != 0) {
      uVar3 = BN_GF2m_mod_exp_arr(param_1,param_2,iVar1,param_3,param_4);
      goto LAB_00626274;
    }
  }
  uVar3 = 0;
LAB_00626274:
  (*(code *)PTR_BN_CTX_end_006a8530)(param_4);
  return uVar3;
}

