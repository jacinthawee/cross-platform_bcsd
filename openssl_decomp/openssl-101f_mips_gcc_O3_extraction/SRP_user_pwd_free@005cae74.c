
void SRP_user_pwd_free(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    (*(code *)PTR_BN_free_006a811c)(param_1[1]);
    (*(code *)PTR_BN_clear_free_006a9130)(param_1[2]);
    (*(code *)PTR_CRYPTO_free_006a7f88)(*param_1);
    (*(code *)PTR_CRYPTO_free_006a7f88)(param_1[5]);
                    /* WARNING: Could not recover jumptable at 0x005caee4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(param_1);
    return;
  }
  return;
}

