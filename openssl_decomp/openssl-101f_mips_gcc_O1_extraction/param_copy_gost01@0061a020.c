
undefined4 param_copy_gost01(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar1 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)();
  iVar2 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_2);
  iVar3 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(param_2);
  iVar4 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(param_1);
  if (iVar3 != iVar4) {
    ERR_GOST_error(0x74,0x69,"gost_ameth.c",0x234);
    return 0;
  }
  if (iVar2 == 0) {
    ERR_GOST_error(0x74,0x73,"gost_ameth.c",0x23a);
    uVar5 = 0;
  }
  else {
    if (iVar1 == 0) {
      iVar1 = (*(code *)PTR_EC_KEY_new_006a82a8)();
      uVar5 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(param_2);
      (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_1,uVar5,iVar1);
    }
    uVar5 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(iVar2);
    (*(code *)PTR_EC_KEY_set_group_006a82d0)(iVar1,uVar5);
    iVar2 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(iVar1);
    if (iVar2 == 0) {
      return 1;
    }
    gost2001_compute_public(iVar1);
    uVar5 = 1;
  }
  return uVar5;
}

