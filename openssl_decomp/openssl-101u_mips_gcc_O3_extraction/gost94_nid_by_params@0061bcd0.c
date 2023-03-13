
undefined4 gost94_nid_by_params(int param_1)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_20;
  int local_1c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_20 = (*(code *)PTR_BN_new_006a71b4)();
  iVar5 = *(int *)(PTR_R3410_paramset_006a95fc + 0xc);
  puVar1 = (undefined4 *)PTR_R3410_paramset_006a95fc;
  do {
    if (iVar5 == 0) {
      (*(code *)PTR_BN_free_006a701c)(local_20);
      uVar3 = 0;
LAB_0061bd94:
      if (local_1c == *(int *)puVar2) {
        return uVar3;
      }
      iVar5 = local_1c;
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
      iVar4 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)();
      if (iVar4 == 0x32b) {
        iVar5 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(iVar5);
        if (iVar5 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0061be60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(iVar5);
          return uVar3;
        }
      }
      else if ((iVar4 == 0x32c) &&
              (iVar5 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(iVar5), iVar5 != 0)) {
        return *(undefined4 *)(iVar5 + 0x1c);
      }
      return 0;
    }
    (*(code *)PTR_BN_dec2bn_006a7e30)(&local_20);
    iVar5 = (*(code *)PTR_BN_cmp_006a7960)(local_20,*(undefined4 *)(param_1 + 0x10));
    if (iVar5 == 0) {
      (*(code *)PTR_BN_free_006a701c)(local_20);
      uVar3 = *puVar1;
      goto LAB_0061bd94;
    }
    iVar5 = puVar1[7];
    puVar1 = puVar1 + 4;
  } while( true );
}

