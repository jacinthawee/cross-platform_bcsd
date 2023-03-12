
int SRP_Calc_A(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) {
    iVar1 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if (iVar1 == 0) {
      iVar4 = 0;
    }
    else {
      iVar2 = (*(code *)PTR_BN_new_006a82b4)();
      iVar4 = iVar2;
      if (iVar2 != 0) {
        iVar3 = (*(code *)PTR_BN_mod_exp_006a8a48)(iVar2,param_3,param_1,param_2,iVar1);
        if (iVar3 == 0) {
          iVar4 = 0;
          (*(code *)PTR_BN_free_006a811c)(iVar2);
        }
      }
      (*(code *)PTR_BN_CTX_free_006a8a40)(iVar1);
    }
    return iVar4;
  }
  return 0;
}

