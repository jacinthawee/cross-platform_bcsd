
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_PKEY * EVP_PKEY_new(void)

{
  EVP_PKEY *pEVar1;
  
  pEVar1 = (EVP_PKEY *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x20,"p_lib.c",0xba);
  if (pEVar1 == (EVP_PKEY *)0x0) {
    ERR_put_error(6,0x6a,0x41,"p_lib.c",0xbd);
    pEVar1 = (EVP_PKEY *)0x0;
  }
  else {
    pEVar1->type = 0;
    pEVar1->save_type = 0;
    pEVar1->ameth = (EVP_PKEY_ASN1_METHOD *)0x0;
    pEVar1->references = 1;
    pEVar1->engine = (ENGINE *)0x0;
    (pEVar1->pkey).ptr = (char *)0x0;
    pEVar1->attributes = (stack_st_X509_ATTRIBUTE *)0x0;
    pEVar1->save_parameters = 1;
  }
  return pEVar1;
}

