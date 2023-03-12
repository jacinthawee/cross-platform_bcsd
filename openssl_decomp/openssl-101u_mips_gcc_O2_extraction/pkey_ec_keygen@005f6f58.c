
undefined4 pkey_ec_keygen(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 8) == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,199,0x8b,"ec_pmeth.c",0x11b);
    return 0;
  }
  iVar1 = (*(code *)PTR_EC_KEY_new_006a71a8)();
  if (iVar1 != 0) {
    (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_2,0x198,iVar1);
    iVar1 = (*(code *)PTR_EVP_PKEY_copy_parameters_006a7174)(param_2,*(undefined4 *)(param_1 + 8));
    if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x005f6ff0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*(code *)PTR_EC_KEY_generate_key_006a71d0)(*(undefined4 *)(param_2 + 0x14));
      return uVar2;
    }
  }
  return 0;
}

