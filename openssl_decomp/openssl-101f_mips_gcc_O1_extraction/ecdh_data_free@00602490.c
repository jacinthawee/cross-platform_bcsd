
void ecdh_data_free(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    (*(code *)PTR_ENGINE_finish_006a80c4)();
  }
  (*(code *)PTR_CRYPTO_free_ex_data_006a9414)(0xd,param_1,param_1 + 0x10);
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(param_1,0x18);
                    /* WARNING: Could not recover jumptable at 0x00602500. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a7f88)(param_1);
  return;
}

