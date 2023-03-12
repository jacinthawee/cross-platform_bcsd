
void * PEM_ASN1_read_bio(undefined1 *d2i,char *name,BIO *bp,void **x,undefined1 *cb,void *u)

{
  undefined *puVar1;
  int iVar2;
  undefined1 *puVar3;
  PKCS8_PRIV_KEY_INFO *p8inf;
  X509_SIG *p8;
  void *pvVar4;
  BIO *bp_00;
  uchar **plen;
  uchar *puVar5;
  char acStack_474 [1024];
  int iStack_74;
  undefined1 *puStack_70;
  undefined *puStack_6c;
  void **ppvStack_68;
  code *pcStack_2c;
  uchar *local_20;
  uchar *local_1c;
  uchar *local_18;
  BIO *local_14;
  
  puStack_6c = PTR___stack_chk_guard_006a9ae8;
  plen = &local_18;
  local_20 = (uchar *)0x0;
  local_1c = (uchar *)0x0;
  local_14 = *(BIO **)PTR___stack_chk_guard_006a9ae8;
  puVar5 = (uchar *)0x0;
  iVar2 = PEM_bytes_read_bio(&local_1c,(long *)plen,(char **)0x0,name,bp,cb,u);
  if (iVar2 == 0) {
    puVar3 = (undefined1 *)0x0;
  }
  else {
    plen = &local_20;
    local_20 = local_1c;
    puVar3 = (undefined1 *)(*(code *)d2i)(x,plen);
    puVar5 = local_18;
    if (puVar3 == (undefined1 *)0x0) {
      puVar5 = (uchar *)0xd;
      name = "pem_oth.c";
      bp = (BIO *)0x53;
      plen = (uchar **)0x67;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x67);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(local_1c);
    d2i = puVar3;
  }
  if (local_14 == *(BIO **)puStack_6c) {
    return puVar3;
  }
  bp_00 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_74 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_70 = d2i;
  ppvStack_68 = x;
  p8inf = (PKCS8_PRIV_KEY_INFO *)(*(code *)PTR_EVP_PKEY2PKCS8_006a8e9c)(plen);
  if (p8inf == (PKCS8_PRIV_KEY_INFO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(9,0x7e,0x73,"pem_pk8.c",0x78);
    pvVar4 = (void *)0x0;
  }
  else if ((bp == (BIO *)0x0) && (name == (char *)0xffffffff)) {
    if (puVar5 == (uchar *)0x0) {
      pvVar4 = (void *)PEM_ASN1_write_bio(PTR_i2d_PKCS8_PRIV_KEY_INFO_006a8ea4,"PRIVATE KEY",bp_00,
                                          p8inf,(EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,
                                          (void *)0x0);
    }
    else {
      pvVar4 = (void *)i2d_PKCS8_PRIV_KEY_INFO_bio(bp_00,p8inf);
    }
    PKCS8_PRIV_KEY_INFO_free(p8inf);
  }
  else {
    if (cb == (undefined1 *)0x0) {
      if (pcStack_2c == (code *)0x0) {
        iVar2 = PEM_def_callback(acStack_474,0x400,1,&_gp);
      }
      else {
        iVar2 = (*pcStack_2c)(acStack_474,0x400,1,&_gp);
      }
      if (iVar2 < 1) {
        (*(code *)PTR_ERR_put_error_006a7f34)(9,0x7e,0x6f,"pem_pk8.c",0x82);
        PKCS8_PRIV_KEY_INFO_free(p8inf);
        pvVar4 = (void *)0x0;
        goto LAB_0056f1ec;
      }
      p8 = (X509_SIG *)(*(code *)PTR_PKCS8_encrypt_006a7cbc)(name,bp,acStack_474,iVar2,0,0,0,p8inf);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(acStack_474,iVar2);
    }
    else {
      p8 = (X509_SIG *)(*(code *)PTR_PKCS8_encrypt_006a7cbc)(name,bp,cb,u,0,0,0,p8inf);
    }
    PKCS8_PRIV_KEY_INFO_free(p8inf);
    if (p8 == (X509_SIG *)0x0) {
      pvVar4 = (void *)0x0;
    }
    else {
      if (puVar5 == (uchar *)0x0) {
        pvVar4 = (void *)PEM_ASN1_write_bio(PTR_i2d_X509_SIG_006a8734,"ENCRYPTED PRIVATE KEY",bp_00,
                                            p8,(EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,
                                            (void *)0x0);
      }
      else {
        pvVar4 = (void *)i2d_PKCS8_bio(bp_00,p8);
      }
      X509_SIG_free(p8);
    }
  }
LAB_0056f1ec:
  if (iStack_74 == *(int *)puVar1) {
    return pvVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pvVar4 = (void *)do_pk8pkey();
  return pvVar4;
}

