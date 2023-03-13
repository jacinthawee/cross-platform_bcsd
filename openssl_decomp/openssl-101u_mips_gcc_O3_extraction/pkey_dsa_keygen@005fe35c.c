
undefined4 pkey_dsa_keygen(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 8) == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(10,0x79,0x6b,"dsa_pmeth.c",0x108);
    return 0;
  }
  iVar1 = (*(code *)PTR_DSA_new_006a7528)();
  if (iVar1 != 0) {
    (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_2,0x74,iVar1);
    iVar1 = (*(code *)PTR_EVP_PKEY_copy_parameters_006a7174)(param_2,*(undefined4 *)(param_1 + 8));
    if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x005fe3f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*(code *)PTR_DSA_generate_key_006a767c)(*(undefined4 *)(param_2 + 0x14));
      return uVar2;
    }
  }
  return 0;
}

