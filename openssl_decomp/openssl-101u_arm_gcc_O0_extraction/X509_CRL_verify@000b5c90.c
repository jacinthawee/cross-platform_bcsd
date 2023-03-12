
int X509_CRL_verify(X509_CRL *a,EVP_PKEY *r)

{
  int iVar1;
  
  if (*(code **)(a->meth + 0x10) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000b5c96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(a->meth + 0x10))();
    return iVar1;
  }
  return 0;
}

