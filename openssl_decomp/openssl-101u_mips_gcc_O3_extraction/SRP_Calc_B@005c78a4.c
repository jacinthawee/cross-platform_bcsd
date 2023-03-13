
int SRP_Calc_B(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) || (param_4 == 0)) {
    return 0;
  }
  iVar1 = (*(code *)PTR_BN_CTX_new_006a794c)();
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = (*(code *)PTR_BN_new_006a71b4)();
  if ((iVar2 == 0) || (iVar3 = (*(code *)PTR_BN_new_006a71b4)(), iVar3 == 0)) {
    iVar5 = 0;
    iVar4 = 0;
    iVar3 = 0;
  }
  else {
    iVar4 = (*(code *)PTR_BN_new_006a71b4)();
    if (iVar4 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = (*(code *)PTR_BN_mod_exp_006a795c)(iVar3,param_3,param_1,param_2,iVar1);
      if ((iVar5 == 0) || (iVar5 = srp_Calc_k(param_2,param_3), iVar5 == 0)) {
        iVar5 = 0;
      }
      else {
        iVar6 = (*(code *)PTR_BN_mod_mul_006a8574)(iVar2,param_4,iVar5,param_2,iVar1);
        if ((iVar6 != 0) &&
           (iVar6 = (*(code *)PTR_BN_mod_add_006a9510)(iVar4,iVar3,iVar2,param_2,iVar1), iVar6 != 0)
           ) goto LAB_005c79b0;
      }
      (*(code *)PTR_BN_free_006a701c)(iVar4);
      iVar4 = 0;
    }
  }
LAB_005c79b0:
  (*(code *)PTR_BN_CTX_free_006a7954)(iVar1);
  (*(code *)PTR_BN_clear_free_006a7fa8)(iVar2);
  (*(code *)PTR_BN_clear_free_006a7fa8)(iVar3);
  (*(code *)PTR_BN_free_006a701c)(iVar5);
  return iVar4;
}

