
void X509_INFO_free(X509_INFO *a)

{
  int iVar1;
  
  if ((a != (X509_INFO *)0x0) &&
     (iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a805c)(&a->references,0xffffffff,4,"x_info.c",0x5d),
     iVar1 < 1)) {
    if (a->x509 != (X509 *)0x0) {
      X509_free(a->x509);
    }
    if (a->crl != (X509_CRL *)0x0) {
      X509_CRL_free(a->crl);
    }
    if (a->x_pkey != (X509_PKEY *)0x0) {
      X509_PKEY_free(a->x_pkey);
    }
    if (a->enc_data != (char *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
                    /* WARNING: Could not recover jumptable at 0x00555598. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(a);
    return;
  }
  return;
}

