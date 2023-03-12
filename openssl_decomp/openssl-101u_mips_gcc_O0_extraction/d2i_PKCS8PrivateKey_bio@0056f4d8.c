
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
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pcVar5 = (char *)0x0;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
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
      in_stack_fffffbc8 = 0xaf;
      pcVar5 = &DAT_00000078;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x78,0x68,"pem_pk8.c",0xaf);
      X509_SIG_free(a);
    }
    else {
      a_00 = (PKCS8_PRIV_KEY_INFO *)(*(code *)PTR_PKCS8_decrypt_006a7cb4)(a,pcVar5);
      X509_SIG_free(a);
      if (a_00 != (PKCS8_PRIV_KEY_INFO *)0x0) {
        pEVar3 = (EVP_PKEY *)(*(code *)PTR_EVP_PKCS82PKEY_006a7220)(a_00);
        PKCS8_PRIV_KEY_INFO_free(a_00);
        if (pEVar3 != (EVP_PKEY *)0x0) {
          if (x != (EVP_PKEY **)0x0) {
            if (*x != (EVP_PKEY *)0x0) {
              (*(code *)PTR_EVP_PKEY_free_006a6e78)();
            }
            *x = pEVar3;
          }
          goto LAB_0056f5e0;
        }
      }
    }
  }
  pEVar3 = (EVP_PKEY *)0x0;
LAB_0056f5e0:
  if (local_24 == *(int *)puVar1) {
    return pEVar3;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar4 = (*(code *)PTR_BIO_new_fp_006a7248)();
  if (iVar4 != 0) {
    pEVar3 = (EVP_PKEY *)
             do_pk8pkey(iVar4,pcVar5,1,0xffffffff,puVar2,pcVar6,in_stack_fffffbc8,uStack_434,&_gp);
    (*(code *)PTR_BIO_free_006a6e70)(iVar4);
    return pEVar3;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(9,0x7d,7,"pem_pk8.c",0xe7);
  return (EVP_PKEY *)0x0;
}

