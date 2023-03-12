
void ASN1_STRING_clear_free(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  if ((param_1[2] != 0) && ((param_1[3] & 0x10) == 0)) {
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(param_1[2],*param_1);
    if ((param_1[2] != 0) && ((param_1[3] & 0x10) == 0)) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
                    /* WARNING: Could not recover jumptable at 0x00568188. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CRYPTO_free_006a6e88)(param_1);
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00568140. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a6e88)(param_1);
  return;
}

