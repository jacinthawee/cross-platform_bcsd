
EVP_PKEY_CTX * EVP_PKEY_CTX_new(EVP_PKEY *pkey,ENGINE *e)

{
  int iVar1;
  EVP_PKEY_METHOD **ppEVar2;
  ENGINE *e_00;
  code *pcVar3;
  EVP_PKEY_METHOD *pEVar4;
  EVP_PKEY_METHOD **local_88;
  EVP_PKEY_METHOD *local_84 [28];
  
  if (pkey == (EVP_PKEY *)0x0) {
    return (EVP_PKEY_CTX *)0x0;
  }
  if ((EVP_PKEY_METHOD **)pkey->ameth == (EVP_PKEY_METHOD **)0x0) {
    return (EVP_PKEY_CTX *)0x0;
  }
  pEVar4 = *(EVP_PKEY_METHOD **)pkey->ameth;
  e_00 = pkey->engine;
  if ((pkey->engine == (ENGINE *)0x0) && (e_00 = e, e == (ENGINE *)0x0)) {
    e_00 = ENGINE_get_pkey_meth_engine((int)pEVar4);
    if (e_00 != (ENGINE *)0x0) goto LAB_000ae4b6;
    local_88 = local_84;
    local_84[0] = pEVar4;
    if ((app_pkey_methods == (_STACK *)0x0) ||
       (iVar1 = sk_find(app_pkey_methods,local_88), iVar1 < 0)) {
      ppEVar2 = (EVP_PKEY_METHOD **)
                OBJ_bsearch_(&local_88,&standard_methods,6,4,pmeth_cmp_BSEARCH_CMP_FN + 1);
      if (ppEVar2 == (EVP_PKEY_METHOD **)0x0) goto LAB_000ae5b6;
      pEVar4 = *ppEVar2;
    }
    else {
      pEVar4 = (EVP_PKEY_METHOD *)sk_value(app_pkey_methods,iVar1);
    }
  }
  else {
    iVar1 = ENGINE_init(e_00);
    if (iVar1 == 0) {
      ERR_put_error(6,0x9d,0x26,"pmeth_lib.c",0x8e);
      return (EVP_PKEY_CTX *)0x0;
    }
LAB_000ae4b6:
    pEVar4 = ENGINE_get_pkey_meth(e_00,(int)pEVar4);
  }
  if (pEVar4 != (EVP_PKEY_METHOD *)0x0) {
    ppEVar2 = (EVP_PKEY_METHOD **)CRYPTO_malloc(0x28,"pmeth_lib.c",0xa4);
    if (ppEVar2 == (EVP_PKEY_METHOD **)0x0) {
      if (e_00 != (ENGINE *)0x0) {
        ENGINE_finish(e_00);
      }
      ERR_put_error(6,0x9d,0x41,"pmeth_lib.c",0xaa);
      return (EVP_PKEY_CTX *)0x0;
    }
    ppEVar2[1] = (EVP_PKEY_METHOD *)e_00;
    *ppEVar2 = pEVar4;
    ppEVar2[2] = (EVP_PKEY_METHOD *)pkey;
    ppEVar2[4] = (EVP_PKEY_METHOD *)0x0;
    ppEVar2[3] = (EVP_PKEY_METHOD *)0x0;
    ppEVar2[7] = (EVP_PKEY_METHOD *)0x0;
    CRYPTO_add_lock(&pkey->references,1,10,"pmeth_lib.c",0xb4);
    pcVar3 = *(code **)(pEVar4 + 8);
    ppEVar2[5] = (EVP_PKEY_METHOD *)0x0;
    if (pcVar3 != (code *)0x0) {
      iVar1 = (*pcVar3)();
      if (iVar1 < 1) {
        if ((*ppEVar2 != (EVP_PKEY_METHOD *)0x0) &&
           (pcVar3 = *(code **)(*ppEVar2 + 0x10), pcVar3 != (code *)0x0)) {
          (*pcVar3)(ppEVar2);
        }
        if ((EVP_PKEY *)ppEVar2[2] != (EVP_PKEY *)0x0) {
          EVP_PKEY_free((EVP_PKEY *)ppEVar2[2]);
        }
        if ((EVP_PKEY *)ppEVar2[3] != (EVP_PKEY *)0x0) {
          EVP_PKEY_free((EVP_PKEY *)ppEVar2[3]);
        }
        if ((ENGINE *)ppEVar2[1] != (ENGINE *)0x0) {
          ENGINE_finish((ENGINE *)ppEVar2[1]);
        }
        CRYPTO_free(ppEVar2);
        return (EVP_PKEY_CTX *)0x0;
      }
      return (EVP_PKEY_CTX *)ppEVar2;
    }
    return (EVP_PKEY_CTX *)ppEVar2;
  }
LAB_000ae5b6:
  ERR_put_error(6,0x9d,0x9c,"pmeth_lib.c",0xa0);
  return (EVP_PKEY_CTX *)0x0;
}

