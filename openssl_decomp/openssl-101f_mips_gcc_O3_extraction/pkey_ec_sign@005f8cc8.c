
int pkey_ec_sign(int param_1,int param_2,uint *param_3,int param_4,undefined4 param_5)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  EC_KEY *eckey;
  int iVar6;
  uint local_28;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar6 = *(int *)(param_1 + 0x14);
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  eckey = *(EC_KEY **)(*(int *)(param_1 + 8) + 0x14);
  if (param_2 == 0) {
    uVar2 = ECDSA_size(eckey);
    iVar6 = 1;
    *param_3 = uVar2;
    param_4 = param_2;
  }
  else {
    uVar5 = *param_3;
    uVar2 = ECDSA_size(eckey);
    if (uVar5 < uVar2) {
      param_4 = 0xda;
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xda,100,"ec_pmeth.c",0x86);
      iVar6 = 0;
    }
    else {
      if (*(int *)(iVar6 + 4) == 0) {
        uVar3 = 0x40;
      }
      else {
        uVar3 = (*(code *)PTR_EVP_MD_type_006a84cc)();
      }
      iVar6 = (*(code *)PTR_ECDSA_sign_006a8b74)(uVar3,param_4,param_5,param_2,&local_28,eckey);
      if (0 < iVar6) {
        iVar6 = 1;
        *param_3 = local_28;
      }
    }
  }
  if (local_24 != *(int *)puVar1) {
    iVar6 = local_24;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    if (*(int *)(iVar6 + 8) == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,199,0x8b,"ec_pmeth.c",0x126);
      return 0;
    }
    iVar4 = (*(code *)PTR_EC_KEY_new_006a82a8)();
    if (iVar4 != 0) {
      (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_4,0x198,iVar4);
      iVar6 = (*(code *)PTR_EVP_PKEY_copy_parameters_006a8274)(param_4,*(undefined4 *)(iVar6 + 8));
      if (iVar6 != 0) {
                    /* WARNING: Could not recover jumptable at 0x005f8ec0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar6 = (*(code *)PTR_EC_KEY_generate_key_006a82d4)(*(undefined4 *)(param_4 + 0x14));
        return iVar6;
      }
    }
    return 0;
  }
  return iVar6;
}

