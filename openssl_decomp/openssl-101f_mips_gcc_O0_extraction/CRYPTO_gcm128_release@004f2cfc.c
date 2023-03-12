
void CRYPTO_gcm128_release(int param_1)

{
  if (param_1 != 0) {
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(param_1,0x178);
                    /* WARNING: Could not recover jumptable at 0x004f2d3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(param_1);
    return;
  }
  return;
}

