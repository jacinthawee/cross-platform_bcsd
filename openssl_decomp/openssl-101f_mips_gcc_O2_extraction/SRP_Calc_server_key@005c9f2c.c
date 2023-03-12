
int SRP_Calc_server_key(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((((param_3 != 0) && (param_1 != 0)) && (param_2 != 0)) && ((param_4 != 0 && (param_5 != 0))))
  {
    iVar1 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if ((iVar1 == 0) || (iVar2 = (*(code *)PTR_BN_new_006a82b4)(), iVar2 == 0)) {
      iVar3 = 0;
      iVar2 = 0;
    }
    else {
      iVar3 = (*(code *)PTR_BN_new_006a82b4)();
      if ((iVar3 != 0) &&
         ((iVar4 = (*(code *)PTR_BN_mod_exp_006a8a48)(iVar2,param_2,param_3,param_5,iVar1),
          iVar4 != 0 &&
          (iVar4 = (*(code *)PTR_BN_mod_mul_006a9698)(iVar2,param_1,iVar2,param_5,iVar1), iVar4 != 0
          )))) {
        (*(code *)PTR_BN_mod_exp_006a8a48)(iVar3,iVar2,param_4,param_5,iVar1);
      }
    }
    (*(code *)PTR_BN_CTX_free_006a8a40)(iVar1);
    (*(code *)PTR_BN_clear_free_006a9130)(iVar2);
    return iVar3;
  }
  return 0;
}

