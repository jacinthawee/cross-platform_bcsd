
EVP_PKEY * PEM_read_bio_PrivateKey(BIO *bp,EVP_PKEY **x,undefined1 *cb,void *u)

{
  char *__s1;
  EVP_PKEY *pEVar1;
  int iVar2;
  X509_SIG *a;
  PKCS8_PRIV_KEY_INFO *pPVar3;
  int *piVar4;
  char *local_434;
  uchar *local_430;
  uchar *local_42c;
  size_t local_428;
  char acStack_424 [1024];
  int local_24;
  
  local_24 = __stack_chk_guard;
  local_434 = (char *)0x0;
  local_430 = (uchar *)0x0;
  local_42c = (uchar *)0x0;
  pEVar1 = (EVP_PKEY *)
           PEM_bytes_read_bio(&local_42c,(long *)&local_428,&local_434,"ANY PRIVATE KEY",bp,cb,u);
  __s1 = local_434;
  if (pEVar1 == (EVP_PKEY *)0x0) goto LAB_000c3c86;
  local_430 = local_42c;
  iVar2 = strcmp(local_434,"PRIVATE KEY");
  if (iVar2 == 0) {
    pPVar3 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,&local_430,local_428);
    if (pPVar3 == (PKCS8_PRIV_KEY_INFO *)0x0) goto LAB_000c3cf6;
    pEVar1 = EVP_PKCS82PKEY(pPVar3);
    if (x != (EVP_PKEY **)0x0) {
      if (*x != (EVP_PKEY *)0x0) {
        EVP_PKEY_free(*x);
      }
      *x = pEVar1;
    }
    PKCS8_PRIV_KEY_INFO_free(pPVar3);
LAB_000c3c6c:
    if (pEVar1 == (EVP_PKEY *)0x0) goto LAB_000c3cf6;
  }
  else {
    iVar2 = strcmp(__s1,"ENCRYPTED PRIVATE KEY");
    if (iVar2 == 0) {
      a = d2i_X509_SIG((X509_SIG **)0x0,&local_430,local_428);
      if (a != (X509_SIG *)0x0) {
        if (cb == (undefined1 *)0x0) {
          iVar2 = PEM_def_callback(acStack_424,0x400,0,u);
        }
        else {
          iVar2 = (*(code *)cb)(acStack_424,0x400,0,u);
        }
        if (iVar2 < 1) {
          pEVar1 = (EVP_PKEY *)0x0;
          ERR_put_error(9,0x7b,0x68,"pem_pkey.c",0x72);
          X509_SIG_free(a);
          goto LAB_000c3c70;
        }
        pPVar3 = PKCS8_decrypt(a,acStack_424,iVar2);
        X509_SIG_free(a);
        if (pPVar3 != (PKCS8_PRIV_KEY_INFO *)0x0) {
          pEVar1 = EVP_PKCS82PKEY(pPVar3);
          if (x != (EVP_PKEY **)0x0) {
            if (*x != (EVP_PKEY *)0x0) {
              EVP_PKEY_free(*x);
            }
            *x = pEVar1;
          }
          PKCS8_PRIV_KEY_INFO_free(pPVar3);
          goto LAB_000c3c6c;
        }
      }
    }
    else {
      iVar2 = pem_check_suffix(__s1,"PRIVATE KEY");
      if (((0 < iVar2) &&
          (piVar4 = (int *)EVP_PKEY_asn1_find_str((ENGINE **)0x0,local_434,iVar2),
          piVar4 != (int *)0x0)) && (piVar4[0x17] != 0)) {
        pEVar1 = d2i_PrivateKey(*piVar4,x,&local_430,local_428);
        goto LAB_000c3c6c;
      }
    }
LAB_000c3cf6:
    pEVar1 = (EVP_PKEY *)0x0;
    ERR_put_error(9,0x7b,0xd,"pem_pkey.c",0x8a);
  }
LAB_000c3c70:
  CRYPTO_free(local_434);
  OPENSSL_cleanse(local_42c,local_428);
  CRYPTO_free(local_42c);
LAB_000c3c86:
  if (local_24 == __stack_chk_guard) {
    return pEVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

