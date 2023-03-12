
undefined4 pkey_ec_keygen(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 8) == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,199,0x8b,"ec_pmeth.c",0x126);
    return 0;
  }
  iVar1 = (*(code *)PTR_EC_KEY_new_006a82a8)();
  if (iVar1 != 0) {
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_2,0x198,iVar1);
    iVar1 = (*(code *)PTR_EVP_PKEY_copy_parameters_006a8274)(param_2,*(undefined4 *)(param_1 + 8));
    if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x005f8ec0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*(code *)PTR_EC_KEY_generate_key_006a82d4)(*(undefined4 *)(param_2 + 0x14));
      return uVar2;
    }
  }
  return 0;
}

