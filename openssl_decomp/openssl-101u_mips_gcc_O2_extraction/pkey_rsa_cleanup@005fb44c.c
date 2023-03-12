
void pkey_rsa_cleanup(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 4) != 0) {
      (*(code *)PTR_BN_free_006a701c)();
    }
    if (*(int *)(iVar1 + 0x20) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
                    /* WARNING: Could not recover jumptable at 0x005fb4ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar1);
    return;
  }
  return;
}

