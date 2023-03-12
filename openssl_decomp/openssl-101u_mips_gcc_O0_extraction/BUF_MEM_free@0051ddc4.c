
void BUF_MEM_free(BUF_MEM *a)

{
  if (a != (BUF_MEM *)0x0) {
    if (a->data != (char *)0x0) {
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(a->data,a->max);
      (*(code *)PTR_CRYPTO_free_006a6e88)(a->data);
    }
                    /* WARNING: Could not recover jumptable at 0x0051de1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(a);
    return;
  }
  return;
}

