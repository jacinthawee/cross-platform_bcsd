
void EVP_PKEY_meth_free(EVP_PKEY_METHOD *pmeth)

{
  if ((pmeth != (EVP_PKEY_METHOD *)0x0) && ((*(uint *)(pmeth + 4) & 1) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x00544bbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    return;
  }
  return;
}

