
int SRP_Calc_client_key(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if ((((param_6 != 0) && (param_2 != 0)) && (param_1 != 0)) &&
     (((param_3 != 0 && (param_4 != 0)) && (param_5 != 0)))) {
    iVar1 = (*(code *)PTR_BN_CTX_new_006a794c)();
    if (iVar1 != 0) {
      iVar2 = (*(code *)PTR_BN_new_006a71b4)();
      if ((iVar2 == 0) || (iVar3 = (*(code *)PTR_BN_new_006a71b4)(), iVar3 == 0)) {
        iVar6 = 0;
        iVar5 = 0;
        iVar4 = 0;
        iVar3 = 0;
      }
      else {
        iVar4 = (*(code *)PTR_BN_new_006a71b4)();
        if ((iVar4 == 0) ||
           (iVar5 = (*(code *)PTR_BN_mod_exp_006a795c)(iVar2,param_3,param_4,param_1,iVar1),
           iVar5 == 0)) {
          iVar5 = 0;
          iVar6 = 0;
        }
        else {
          iVar5 = srp_Calc_k(param_1,param_3);
          if ((((iVar5 == 0) ||
               (iVar6 = (*(code *)PTR_BN_mod_mul_006a8574)(iVar3,iVar2,iVar5,param_1,iVar1),
               iVar6 == 0)) ||
              (iVar6 = (*(code *)PTR_BN_mod_sub_006a9514)(iVar2,param_2,iVar3,param_1,iVar1),
              iVar6 == 0)) ||
             ((iVar6 = (*(code *)PTR_BN_mod_mul_006a8574)(iVar4,param_6,param_4,param_1,iVar1),
              iVar6 == 0 ||
              (iVar6 = (*(code *)PTR_BN_mod_add_006a9510)(iVar3,param_5,iVar4,param_1,iVar1),
              iVar6 == 0)))) {
            iVar6 = 0;
          }
          else {
            iVar7 = (*(code *)PTR_BN_new_006a71b4)();
            iVar6 = iVar7;
            if ((iVar7 != 0) &&
               (iVar8 = (*(code *)PTR_BN_mod_exp_006a795c)(iVar7,iVar2,iVar3,param_1,iVar1),
               iVar8 == 0)) {
              iVar6 = 0;
              (*(code *)PTR_BN_free_006a701c)(iVar7);
            }
          }
        }
      }
      (*(code *)PTR_BN_CTX_free_006a7954)(iVar1);
      (*(code *)PTR_BN_clear_free_006a7fa8)(iVar2);
      (*(code *)PTR_BN_clear_free_006a7fa8)(iVar3);
      (*(code *)PTR_BN_clear_free_006a7fa8)(iVar4);
      (*(code *)PTR_BN_free_006a701c)(iVar5);
      return iVar6;
    }
    return 0;
  }
  return 0;
}

