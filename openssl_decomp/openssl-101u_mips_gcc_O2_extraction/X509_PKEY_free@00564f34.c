
void X509_PKEY_free(X509_PKEY *a)

{
  int iVar1;
  
  if ((a != (X509_PKEY *)0x0) &&
     (iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a805c)(&a->references,0xffffffff,5,"x_pkey.c",0x83),
     iVar1 < 1)) {
    if (a->enc_algor != (X509_ALGOR *)0x0) {
      X509_ALGOR_free(a->enc_algor);
    }
    if (a->enc_pkey != (ASN1_STRING *)0x0) {
      ASN1_STRING_free(a->enc_pkey);
    }
    if (a->dec_pkey != (EVP_PKEY *)0x0) {
      (*(code *)PTR_EVP_PKEY_free_006a6e78)();
    }
    if ((a->key_data != (char *)0x0) && (a->key_free != 0)) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
                    /* WARNING: Could not recover jumptable at 0x00565004. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(a);
    return;
  }
  return;
}

