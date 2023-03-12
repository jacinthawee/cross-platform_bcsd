
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = 0;
  local_1c = 0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_X509_PUBKEY_get0_param_006a98cc)(0,&local_2c,&local_20,&local_18,param_2);
  if (iVar2 != 0) {
    (*(code *)PTR_X509_ALGOR_get0_006a98c4)(0,&local_24,&local_28,local_18);
    local_1c = eckey_type2param(local_24,local_28);
    if (local_1c == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xd7,0x10,"ec_ameth.c",0xce);
    }
    else {
      iVar2 = (*(code *)PTR_o2i_ECPublicKey_006aa7dc)(&local_1c,&local_2c,local_20);
      if (iVar2 != 0) {
        (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_1,0x198,local_1c);
        uVar3 = 1;
        goto LAB_005f7a2c;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xd7,0x8e,"ec_ameth.c",0xd5);
      if (local_1c != 0) {
        (*(code *)PTR_EC_KEY_free_006a82d8)();
        uVar3 = 0;
        goto LAB_005f7a2c;
      }
    }
  }
  uVar3 = 0;
LAB_005f7a2c:
  if (local_14 == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar4 = (*(code *)PTR_d2i_ECPrivateKey_006a9f38)(0);
  if (iVar4 != 0) {
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(iVar2,0x198,iVar4);
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xde,0x8e,"ec_ameth.c",0x235);
  return 0;
}

