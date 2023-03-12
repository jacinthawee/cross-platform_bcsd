
void CRYPTO_gcm128_release(int param_1)

{
  if (param_1 != 0) {
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(param_1,0x178);
                    /* WARNING: Could not recover jumptable at 0x004efdfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(param_1);
    return;
  }
  return;
}

