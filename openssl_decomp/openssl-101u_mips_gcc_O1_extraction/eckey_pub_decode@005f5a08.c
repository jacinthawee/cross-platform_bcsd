
undefined4 eckey_pub_decode(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = 0;
  local_1c = 0;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_X509_PUBKEY_get0_param_006a87ac)(0,&local_2c,&local_20,&local_18,param_2);
  if (iVar2 != 0) {
    (*(code *)PTR_X509_ALGOR_get0_006a87a4)(0,&local_24,&local_28,local_18);
    local_1c = eckey_type2param(local_24,local_28);
    if (local_1c == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xd7,0x10,"ec_ameth.c",0xc3);
    }
    else {
      iVar2 = (*(code *)PTR_o2i_ECPublicKey_006a96d4)(&local_1c,&local_2c,local_20);
      if (iVar2 != 0) {
        (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_1,0x198,local_1c);
        uVar3 = 1;
        goto LAB_005f5a70;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xd7,0x8e,"ec_ameth.c",0xc9);
      if (local_1c != 0) {
        (*(code *)PTR_EC_KEY_free_006a71d4)();
        uVar3 = 0;
        goto LAB_005f5a70;
      }
    }
  }
  uVar3 = 0;
LAB_005f5a70:
  if (local_14 == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar4 = (*(code *)PTR_d2i_ECPrivateKey_006a8e1c)(0);
  if (iVar4 != 0) {
    (*(code *)PTR_EVP_PKEY_assign_006a83cc)(iVar2,0x198,iVar4);
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xde,0x8e,"ec_ameth.c",0x219);
  return 0;
}

