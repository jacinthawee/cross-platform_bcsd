
bool pub_cmp_gost01(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)();
  iVar2 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_2);
  if ((iVar1 != 0) && (iVar2 != 0)) {
    iVar3 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar1);
    iVar2 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar2);
    if ((iVar3 != 0) && (iVar2 != 0)) {
      uVar4 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(iVar1);
      iVar1 = (*(code *)PTR_EC_POINT_cmp_006a8610)(uVar4,iVar3,iVar2,0);
      return iVar1 == 0;
    }
  }
  return false;
}

