
void EVP_PKEY_free(EVP_PKEY *pkey)

{
  int iVar1;
  code *pcVar2;
  
  if ((pkey != (EVP_PKEY *)0x0) &&
     (iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a9080)
                        (&pkey->references,0xffffffff,10,"p_lib.c",0x189), iVar1 < 1)) {
    if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
       (pcVar2 = *(code **)(pkey->ameth + 0x54), pcVar2 != (code *)0x0)) {
      (*pcVar2)(pkey);
      (pkey->pkey).ptr = (char *)0x0;
    }
    if (pkey->engine != (ENGINE *)0x0) {
      (*(code *)PTR_ENGINE_finish_006a80c4)();
      pkey->engine = (ENGINE *)0x0;
    }
    if ((_STACK *)pkey->attributes != (_STACK *)0x0) {
      sk_pop_free((_STACK *)pkey->attributes,(func *)PTR_X509_ATTRIBUTE_free_006a9c00);
    }
                    /* WARNING: Could not recover jumptable at 0x00541d34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(pkey);
    return;
  }
  return;
}

