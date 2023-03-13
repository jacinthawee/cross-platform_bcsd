
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER_CTX * EVP_CIPHER_CTX_new(void)

{
  EVP_CIPHER_CTX *pEVar1;
  
  pEVar1 = (EVP_CIPHER_CTX *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x8c,"evp_enc.c",0x58);
  if (pEVar1 != (EVP_CIPHER_CTX *)0x0) {
    (*(code *)PTR_memset_006a99f4)(pEVar1,0,0x8c);
  }
  return pEVar1;
}

