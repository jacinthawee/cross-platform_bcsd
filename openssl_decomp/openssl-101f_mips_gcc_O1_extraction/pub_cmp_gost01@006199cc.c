
bool pub_cmp_gost01(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)();
  iVar2 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_2);
  if ((iVar1 != 0) && (iVar2 != 0)) {
    iVar3 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(iVar1);
    iVar2 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(iVar2);
    if ((iVar3 != 0) && (iVar2 != 0)) {
      uVar4 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(iVar1);
      iVar1 = (*(code *)PTR_EC_POINT_cmp_006a9730)(uVar4,iVar3,iVar2,0);
      return iVar1 == 0;
    }
  }
  return false;
}

