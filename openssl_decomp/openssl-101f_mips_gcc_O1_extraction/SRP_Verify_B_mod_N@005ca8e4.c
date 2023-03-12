
bool SRP_Verify_B_mod_N(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return false;
  }
  iVar1 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  if (iVar1 == 0) {
    return false;
  }
  iVar2 = (*(code *)PTR_BN_new_006a82b4)();
  if (iVar2 != 0) {
    iVar3 = (*(code *)PTR_BN_nnmod_006a9664)(iVar2,param_1,param_2,iVar1);
    if (iVar3 != 0) {
      bVar4 = *(int *)(iVar2 + 4) != 0;
      goto LAB_005ca96c;
    }
  }
  bVar4 = false;
LAB_005ca96c:
  (*(code *)PTR_BN_CTX_free_006a8a40)(iVar1);
  (*(code *)PTR_BN_free_006a811c)(iVar2);
  return bVar4;
}

