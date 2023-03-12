
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CMAC_CTX * CMAC_CTX_new(void)

{
  CMAC_CTX *pCVar1;
  
  pCVar1 = (CMAC_CTX *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x110,"cmac.c",100);
  if (pCVar1 != (CMAC_CTX *)0x0) {
    (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(pCVar1);
    *(undefined4 *)(pCVar1 + 0x10c) = 0xffffffff;
  }
  return pCVar1;
}

