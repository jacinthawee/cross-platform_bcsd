
int param_copy_gost01(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int local_1c;
  
  iVar1 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)();
  iVar2 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_2);
  iVar3 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(param_2);
  iVar4 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(param_1);
  if (iVar3 != iVar4) {
    ERR_GOST_error(0x74,0x69,"gost_ameth.c",0x225);
    return 0;
  }
  if (iVar2 == 0) {
    ERR_GOST_error(0x74,0x73,"gost_ameth.c",0x229);
    iVar1 = 0;
  }
  else {
    if (iVar1 == 0) {
      iVar1 = (*(code *)PTR_EC_KEY_new_006a71a8)();
      if (iVar1 == 0) {
        ERR_GOST_error(0x74,0x41,"gost_ameth.c",0x22f);
        return 0;
      }
      uVar5 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(param_2);
      local_1c = (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_1,uVar5,iVar1);
      if (local_1c == 0) {
        uVar5 = 0x233;
        goto LAB_006195d4;
      }
    }
    uVar5 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(iVar2);
    local_1c = (*(code *)PTR_EC_KEY_set_group_006a71cc)(iVar1,uVar5);
    if (local_1c == 0) {
      uVar5 = 0x238;
LAB_006195d4:
      ERR_GOST_error(0x74,0x44,"gost_ameth.c",uVar5);
      return local_1c;
    }
    iVar2 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(iVar1);
    if (iVar2 == 0) {
      iVar1 = 1;
    }
    else {
      gost2001_compute_public(iVar1);
      iVar1 = 1;
    }
  }
  return iVar1;
}

