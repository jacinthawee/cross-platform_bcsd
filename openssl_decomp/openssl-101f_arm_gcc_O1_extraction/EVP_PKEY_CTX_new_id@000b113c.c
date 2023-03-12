
EVP_PKEY_CTX * EVP_PKEY_CTX_new_id(int id,ENGINE *e)

{
  int iVar1;
  EVP_PKEY_METHOD *pEVar2;
  EVP_PKEY_METHOD **ppEVar3;
  code *pcVar4;
  int *local_80;
  int local_7c [27];
  
  if (id == -1) {
    return (EVP_PKEY_CTX *)0x0;
  }
  if (e == (ENGINE *)0x0) {
    e = ENGINE_get_pkey_meth_engine(id);
    if (e != (ENGINE *)0x0) goto LAB_000b115a;
    local_80 = local_7c;
    local_7c[0] = id;
    if ((app_pkey_methods == (_STACK *)0x0) ||
       (iVar1 = sk_find(app_pkey_methods,local_80), iVar1 < 0)) {
      ppEVar3 = (EVP_PKEY_METHOD **)
                OBJ_bsearch_(&local_80,&standard_methods,6,4,pmeth_cmp_BSEARCH_CMP_FN + 1);
      if (ppEVar3 == (EVP_PKEY_METHOD **)0x0) goto LAB_000b1236;
      pEVar2 = *ppEVar3;
    }
    else {
      pEVar2 = (EVP_PKEY_METHOD *)sk_value(app_pkey_methods,iVar1);
    }
  }
  else {
    iVar1 = ENGINE_init(e);
    if (iVar1 == 0) {
      ERR_put_error(6,0x9d,0x26,"pmeth_lib.c",0x91);
      return (EVP_PKEY_CTX *)0x0;
    }
LAB_000b115a:
    pEVar2 = ENGINE_get_pkey_meth(e,id);
  }
  if (pEVar2 != (EVP_PKEY_METHOD *)0x0) {
    ppEVar3 = (EVP_PKEY_METHOD **)CRYPTO_malloc(0x28,"pmeth_lib.c",0xa8);
    if (ppEVar3 == (EVP_PKEY_METHOD **)0x0) {
      if (e != (ENGINE *)0x0) {
        ENGINE_finish(e);
      }
      ERR_put_error(6,0x9d,0x41,"pmeth_lib.c",0xaf);
      return (EVP_PKEY_CTX *)0x0;
    }
    pcVar4 = *(code **)(pEVar2 + 8);
    ppEVar3[1] = (EVP_PKEY_METHOD *)e;
    *ppEVar3 = pEVar2;
    ppEVar3[4] = (EVP_PKEY_METHOD *)0x0;
    ppEVar3[2] = (EVP_PKEY_METHOD *)0x0;
    ppEVar3[3] = (EVP_PKEY_METHOD *)0x0;
    ppEVar3[7] = (EVP_PKEY_METHOD *)0x0;
    ppEVar3[5] = (EVP_PKEY_METHOD *)0x0;
    if (pcVar4 == (code *)0x0) {
      return (EVP_PKEY_CTX *)ppEVar3;
    }
    iVar1 = (*pcVar4)();
    if (0 < iVar1) {
      return (EVP_PKEY_CTX *)ppEVar3;
    }
    if ((*ppEVar3 != (EVP_PKEY_METHOD *)0x0) &&
       (pcVar4 = *(code **)(*ppEVar3 + 0x10), pcVar4 != (code *)0x0)) {
      (*pcVar4)(ppEVar3);
    }
    if ((EVP_PKEY *)ppEVar3[2] != (EVP_PKEY *)0x0) {
      EVP_PKEY_free((EVP_PKEY *)ppEVar3[2]);
    }
    if ((EVP_PKEY *)ppEVar3[3] != (EVP_PKEY *)0x0) {
      EVP_PKEY_free((EVP_PKEY *)ppEVar3[3]);
    }
    if ((ENGINE *)ppEVar3[1] != (ENGINE *)0x0) {
      ENGINE_finish((ENGINE *)ppEVar3[1]);
    }
    CRYPTO_free(ppEVar3);
    return (EVP_PKEY_CTX *)0x0;
  }
LAB_000b1236:
  ERR_put_error(6,0x9d,0x9c,"pmeth_lib.c",0xa4);
  return (EVP_PKEY_CTX *)0x0;
}

