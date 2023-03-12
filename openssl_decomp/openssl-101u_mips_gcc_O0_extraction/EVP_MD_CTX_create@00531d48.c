
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_MD_CTX * EVP_MD_CTX_create(void)

{
  EVP_MD_CTX *pEVar1;
  
  pEVar1 = (EVP_MD_CTX *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x18,"digest.c",0x83);
  if (pEVar1 != (EVP_MD_CTX *)0x0) {
    (*(code *)PTR_memset_006a99f4)(pEVar1,0,0x18);
  }
  return pEVar1;
}

