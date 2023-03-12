
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_STORE_CTX * X509_STORE_CTX_new(void)

{
  X509_STORE_CTX *pXVar1;
  
  pXVar1 = (X509_STORE_CTX *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x88,"x509_vfy.c",0x83d);
  if (pXVar1 == (X509_STORE_CTX *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x8e,0x41,"x509_vfy.c",0x83f);
    pXVar1 = (X509_STORE_CTX *)0x0;
  }
  else {
    (*(code *)PTR_memset_006a99f4)(pXVar1,0,0x88);
  }
  return pXVar1;
}

