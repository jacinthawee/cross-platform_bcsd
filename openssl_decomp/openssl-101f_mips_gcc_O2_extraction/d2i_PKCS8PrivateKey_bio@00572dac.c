
EVP_PKEY * d2i_PKCS8PrivateKey_bio(BIO *bp,EVP_PKEY **x,undefined1 *cb,void *u)

{
  undefined *puVar1;
  X509_SIG *a;
  undefined1 *puVar2;
  PKCS8_PRIV_KEY_INFO *a_00;
  EVP_PKEY *pEVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 in_stack_fffffbc8;
  undefined4 uStack_434;
  char acStack_424 [1024];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pcVar5 = (char *)0x0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar2 = cb;
  pcVar6 = (char *)u;
  a = d2i_PKCS8_bio(bp,(X509_SIG **)0x0);
  if (a != (X509_SIG *)0x0) {
    if (cb == (undefined1 *)0x0) {
      puVar2 = (undefined1 *)PEM_def_callback(acStack_424,0x400,0,u);
      pcVar6 = (char *)u;
    }
    else {
      puVar2 = (undefined1 *)(*(code *)cb)(acStack_424,0x400,0);
      pcVar6 = (char *)u;
    }
    pcVar5 = acStack_424;
    if ((int)puVar2 < 1) {
      puVar2 = &DAT_00000068;
      pcVar6 = "pem_pk8.c";
      in_stack_fffffbc8 = 0xa4;
      pcVar5 = &DAT_00000078;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x78,0x68,"pem_pk8.c",0xa4);
      X509_SIG_free(a);
    }
    else {
      a_00 = (PKCS8_PRIV_KEY_INFO *)(*(code *)PTR_PKCS8_decrypt_006a8da4)(a,pcVar5);
      X509_SIG_free(a);
      if (a_00 != (PKCS8_PRIV_KEY_INFO *)0x0) {
        pEVar3 = (EVP_PKEY *)(*(code *)PTR_EVP_PKCS82PKEY_006a8334)(a_00);
        PKCS8_PRIV_KEY_INFO_free(a_00);
        if (pEVar3 != (EVP_PKEY *)0x0) {
          if (x != (EVP_PKEY **)0x0) {
            if (*x != (EVP_PKEY *)0x0) {
              (*(code *)PTR_EVP_PKEY_free_006a7f78)();
            }
            *x = pEVar3;
          }
          goto LAB_00572eb4;
        }
      }
    }
  }
  pEVar3 = (EVP_PKEY *)0x0;
LAB_00572eb4:
  if (local_24 == *(int *)puVar1) {
    return pEVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar4 = (*(code *)PTR_BIO_new_fp_006a835c)();
  if (iVar4 != 0) {
    pEVar3 = (EVP_PKEY *)
             do_pk8pkey(iVar4,pcVar5,1,0xffffffff,puVar2,pcVar6,in_stack_fffffbc8,uStack_434,&_gp);
    (*(code *)PTR_BIO_free_006a7f70)(iVar4);
    return pEVar3;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(9,0x7d,7,"pem_pk8.c",0xd9);
  return (EVP_PKEY *)0x0;
}

