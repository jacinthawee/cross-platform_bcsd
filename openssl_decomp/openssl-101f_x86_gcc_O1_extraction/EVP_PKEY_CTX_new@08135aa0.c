
EVP_PKEY_CTX * EVP_PKEY_CTX_new(EVP_PKEY *pkey,ENGINE *e)

{
  int *e_00;
  code *pcVar1;
  int iVar2;
  EVP_PKEY_METHOD *pEVar3;
  EVP_PKEY_METHOD **ptr;
  int iVar4;
  ENGINE *e_01;
  EVP_PKEY_METHOD **ppEVar5;
  int in_GS_OFFSET;
  int *local_90;
  int local_8c [27];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((pkey == (EVP_PKEY *)0x0) || (e_00 = (int *)pkey->ameth, e_00 == (int *)0x0)) {
    ppEVar5 = (EVP_PKEY_METHOD **)0x0;
    goto LAB_08135b8b;
  }
  iVar4 = *e_00;
  e_01 = pkey->engine;
  if ((pkey->engine == (ENGINE *)0x0) && (e_01 = e, e == (ENGINE *)0x0)) {
    e_01 = ENGINE_get_pkey_meth_engine(iVar4);
    if (e_01 != (ENGINE *)0x0) goto LAB_08135af8;
    local_90 = local_8c;
    local_8c[0] = iVar4;
    if ((app_pkey_methods == (_STACK *)0x0) ||
       (iVar4 = sk_find(app_pkey_methods,local_90), iVar4 < 0)) {
      ppEVar5 = (EVP_PKEY_METHOD **)
                OBJ_bsearch_(&local_90,standard_methods,6,4,pmeth_cmp_BSEARCH_CMP_FN);
      if (ppEVar5 != (EVP_PKEY_METHOD **)0x0) {
        pEVar3 = *ppEVar5;
        goto LAB_08135b07;
      }
    }
    else {
      pEVar3 = (EVP_PKEY_METHOD *)sk_value(app_pkey_methods,iVar4);
LAB_08135b07:
      if (pEVar3 != (EVP_PKEY_METHOD *)0x0) {
        ptr = (EVP_PKEY_METHOD **)CRYPTO_malloc(0x28,"pmeth_lib.c",0xa8);
        if (ptr != (EVP_PKEY_METHOD **)0x0) {
          ptr[2] = (EVP_PKEY_METHOD *)pkey;
          ptr[1] = (EVP_PKEY_METHOD *)e_01;
          *ptr = pEVar3;
          ptr[4] = (EVP_PKEY_METHOD *)0x0;
          ptr[3] = (EVP_PKEY_METHOD *)0x0;
          ptr[7] = (EVP_PKEY_METHOD *)0x0;
          CRYPTO_add_lock(&pkey->references,1,10,"pmeth_lib.c",0xb9);
          pcVar1 = *(code **)(pEVar3 + 8);
          ptr[5] = (EVP_PKEY_METHOD *)0x0;
          ppEVar5 = ptr;
          if ((pcVar1 != (code *)0x0) && (iVar4 = (*pcVar1)(ptr), iVar4 < 1)) {
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
            ppEVar5 = (EVP_PKEY_METHOD **)0x0;
            CRYPTO_free(ptr);
          }
          goto LAB_08135b8b;
        }
        if (e_01 != (ENGINE *)0x0) {
          ENGINE_finish((ENGINE *)0x0);
        }
        iVar2 = 0xaf;
        iVar4 = 0x41;
        goto LAB_08135c6f;
      }
    }
    iVar2 = 0xa4;
    iVar4 = 0x9c;
  }
  else {
    iVar2 = ENGINE_init((ENGINE *)e_00);
    if (iVar2 != 0) {
LAB_08135af8:
      pEVar3 = ENGINE_get_pkey_meth(e_01,iVar4);
      goto LAB_08135b07;
    }
    iVar2 = 0x91;
    iVar4 = 0x26;
  }
LAB_08135c6f:
  ppEVar5 = (EVP_PKEY_METHOD **)0x0;
  ERR_put_error(6,0x9d,iVar4,"pmeth_lib.c",iVar2);
LAB_08135b8b:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (EVP_PKEY_CTX *)ppEVar5;
}

