
int SRP_Calc_server_key(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((((param_3 != 0) && (param_1 != 0)) && (param_2 != 0)) && ((param_4 != 0 && (param_5 != 0))))
  {
    iVar1 = (*(code *)PTR_BN_CTX_new_006a794c)();
    if ((iVar1 == 0) || (iVar2 = (*(code *)PTR_BN_new_006a71b4)(), iVar2 == 0)) {
      iVar3 = 0;
      iVar2 = 0;
    }
    else {
      iVar3 = (*(code *)PTR_BN_mod_exp_006a795c)(iVar2,param_2,param_3,param_5,iVar1);
      if ((iVar3 == 0) ||
         (iVar3 = (*(code *)PTR_BN_mod_mul_006a8574)(iVar2,param_1,iVar2,param_5,iVar1), iVar3 == 0)
         ) {
        iVar3 = 0;
      }
      else {
        iVar4 = (*(code *)PTR_BN_new_006a71b4)();
        iVar3 = iVar4;
        if ((iVar4 != 0) &&
           (iVar5 = (*(code *)PTR_BN_mod_exp_006a795c)(iVar4,iVar2,param_4,param_5,iVar1),
           iVar5 == 0)) {
          iVar3 = 0;
          (*(code *)PTR_BN_free_006a701c)(iVar4);
        }
      }
    }
    (*(code *)PTR_BN_CTX_free_006a7954)(iVar1);
    (*(code *)PTR_BN_clear_free_006a7fa8)(iVar2);
    return iVar3;
  }
  return 0;
}

