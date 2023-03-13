
EVP_PKEY_CTX * EVP_PKEY_CTX_new_id(int id,ENGINE *e)

{
  code *pcVar1;
  int iVar2;
  EVP_PKEY_METHOD *pEVar3;
  EVP_PKEY_METHOD **ptr;
  EVP_PKEY_METHOD **ppEVar4;
  int in_GS_OFFSET;
  int line;
  int *local_80;
  int local_7c [27];
  int local_10;
  
  ppEVar4 = (EVP_PKEY_METHOD **)0x0;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (id == -1) goto LAB_08133601;
  if (e == (ENGINE *)0x0) {
    e = ENGINE_get_pkey_meth_engine(id);
    if (e != (ENGINE *)0x0) goto LAB_08133587;
    local_80 = local_7c;
    local_7c[0] = id;
    if (app_pkey_methods != (_STACK *)0x0) {
      iVar2 = sk_find(app_pkey_methods,local_80);
      if (iVar2 < 0) goto LAB_0813365c;
      pEVar3 = (EVP_PKEY_METHOD *)sk_value(app_pkey_methods,iVar2);
      goto LAB_08133596;
    }
LAB_0813365c:
    ppEVar4 = (EVP_PKEY_METHOD **)
              OBJ_bsearch_(&local_80,standard_methods,6,4,pmeth_cmp_BSEARCH_CMP_FN);
    if (ppEVar4 != (EVP_PKEY_METHOD **)0x0) {
      pEVar3 = *ppEVar4;
      goto LAB_08133596;
    }
LAB_081336d0:
    line = 0xa0;
    iVar2 = 0x9c;
  }
  else {
    iVar2 = ENGINE_init((ENGINE *)0x0);
    if (iVar2 == 0) {
      ERR_put_error(6,0x9d,0x26,"pmeth_lib.c",0x8e);
      goto LAB_08133601;
    }
LAB_08133587:
    pEVar3 = ENGINE_get_pkey_meth(e,id);
LAB_08133596:
    if (pEVar3 == (EVP_PKEY_METHOD *)0x0) goto LAB_081336d0;
    ptr = (EVP_PKEY_METHOD **)CRYPTO_malloc(0x28,"pmeth_lib.c",0xa4);
    if (ptr != (EVP_PKEY_METHOD **)0x0) {
      *ptr = pEVar3;
      ptr[1] = (EVP_PKEY_METHOD *)e;
      ptr[4] = (EVP_PKEY_METHOD *)0x0;
      ptr[2] = (EVP_PKEY_METHOD *)0x0;
      ptr[3] = (EVP_PKEY_METHOD *)0x0;
      ptr[7] = (EVP_PKEY_METHOD *)0x0;
      ptr[5] = (EVP_PKEY_METHOD *)0x0;
      ppEVar4 = ptr;
      if (*(code **)(pEVar3 + 8) != (code *)0x0) {
        iVar2 = (**(code **)(pEVar3 + 8))(ptr);
        if (iVar2 < 1) {
          if ((*ptr != (EVP_PKEY_METHOD *)0x0) &&
             (pcVar1 = *(code **)(*ptr + 0x10), pcVar1 != (code *)0x0)) {
            (*pcVar1)(ptr);
          }
          if ((EVP_PKEY *)ptr[2] != (EVP_PKEY *)0x0) {
            EVP_PKEY_free((EVP_PKEY *)ptr[2]);
          }
          if ((EVP_PKEY *)ptr[3] != (EVP_PKEY *)0x0) {
            EVP_PKEY_free((EVP_PKEY *)ptr[3]);
          }
          if ((ENGINE *)ptr[1] != (ENGINE *)0x0) {
            ENGINE_finish((ENGINE *)ptr[1]);
          }
          ppEVar4 = (EVP_PKEY_METHOD **)0x0;
          CRYPTO_free(ptr);
        }
      }
      goto LAB_08133601;
    }
    if (e != (ENGINE *)0x0) {
      ENGINE_finish((ENGINE *)0x0);
    }
    line = 0xaa;
    iVar2 = 0x41;
  }
  ppEVar4 = (EVP_PKEY_METHOD **)0x0;
  ERR_put_error(6,0x9d,iVar2,"pmeth_lib.c",line);
LAB_08133601:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (EVP_PKEY_CTX *)ppEVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

