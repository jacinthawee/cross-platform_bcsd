
void EVP_PKEY_free(EVP_PKEY *pkey)

{
  code *pcVar1;
  int iVar2;
  
  if (pkey != (EVP_PKEY *)0x0) {
    iVar2 = CRYPTO_add_lock(&pkey->references,-1,10,"p_lib.c",0x189);
    if (iVar2 < 1) {
      if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
         (pcVar1 = *(code **)(pkey->ameth + 0x54), pcVar1 != (code *)0x0)) {
        (*pcVar1)(pkey);
        (pkey->pkey).ptr = (char *)0x0;
      }
      if (pkey->engine != (ENGINE *)0x0) {
        ENGINE_finish(pkey->engine);
        pkey->engine = (ENGINE *)0x0;
      }
      if ((_STACK *)pkey->attributes != (_STACK *)0x0) {
        sk_pop_free((_STACK *)pkey->attributes,X509_ATTRIBUTE_free);
      }
      CRYPTO_free(pkey);
      return;
    }
  }
  return;
}

