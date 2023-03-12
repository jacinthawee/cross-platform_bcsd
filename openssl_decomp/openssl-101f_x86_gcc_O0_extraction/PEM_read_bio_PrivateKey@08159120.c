
EVP_PKEY * PEM_read_bio_PrivateKey(BIO *bp,EVP_PKEY **x,undefined1 *cb,void *u)

{
  int iVar1;
  X509_SIG *a;
  PKCS8_PRIV_KEY_INFO *pPVar2;
  EVP_PKEY *pEVar3;
  int *piVar4;
  char *pcVar5;
  char *pcVar6;
  int in_GS_OFFSET;
  bool bVar7;
  byte bVar8;
  char *local_430;
  uchar *local_42c;
  uchar *local_428;
  size_t local_424;
  char local_420 [1024];
  int local_20;
  
  bVar8 = 0;
  local_430 = (char *)0x0;
  local_42c = (uchar *)0x0;
  local_428 = (uchar *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = PEM_bytes_read_bio(&local_428,(long *)&local_424,&local_430,"ANY PRIVATE KEY",bp,cb,u);
  bVar7 = iVar1 == 0;
  if (bVar7) {
    pEVar3 = (EVP_PKEY *)0x0;
    goto LAB_081592b7;
  }
  iVar1 = 0xc;
  local_42c = local_428;
  pcVar5 = local_430;
  pcVar6 = "PRIVATE KEY";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar7 = *pcVar5 == *pcVar6;
    pcVar5 = pcVar5 + (uint)bVar8 * -2 + 1;
    pcVar6 = pcVar6 + (uint)bVar8 * -2 + 1;
  } while (bVar7);
  if (bVar7) {
    pPVar2 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,&local_42c,local_424);
    if (pPVar2 == (PKCS8_PRIV_KEY_INFO *)0x0) goto LAB_08159270;
    pEVar3 = EVP_PKCS82PKEY(pPVar2);
    if (x != (EVP_PKEY **)0x0) {
      if (*x != (EVP_PKEY *)0x0) {
        EVP_PKEY_free(*x);
      }
      *x = pEVar3;
    }
    PKCS8_PRIV_KEY_INFO_free(pPVar2);
LAB_08159263:
    if (pEVar3 == (EVP_PKEY *)0x0) goto LAB_08159270;
  }
  else {
    iVar1 = 0x16;
    pcVar5 = local_430;
    pcVar6 = "ENCRYPTED PRIVATE KEY";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar7 = *pcVar5 == *pcVar6;
      pcVar5 = pcVar5 + (uint)bVar8 * -2 + 1;
      pcVar6 = pcVar6 + (uint)bVar8 * -2 + 1;
    } while (bVar7);
    if (bVar7) {
      a = d2i_X509_SIG((X509_SIG **)0x0,&local_42c,local_424);
      if (a != (X509_SIG *)0x0) {
        if (cb == (undefined1 *)0x0) {
          iVar1 = PEM_def_callback(local_420,0x400,0,u);
        }
        else {
          iVar1 = (*(code *)cb)(local_420,0x400,0,u);
        }
        if (iVar1 < 1) {
          pEVar3 = (EVP_PKEY *)0x0;
          ERR_put_error(9,0x7b,0x68,"pem_pkey.c",0x6d);
          X509_SIG_free(a);
          goto LAB_0815928d;
        }
        pPVar2 = PKCS8_decrypt(a,local_420,iVar1);
        X509_SIG_free(a);
        if (pPVar2 != (PKCS8_PRIV_KEY_INFO *)0x0) {
          pEVar3 = EVP_PKCS82PKEY(pPVar2);
          if (x != (EVP_PKEY **)0x0) {
            if (*x != (EVP_PKEY *)0x0) {
              EVP_PKEY_free(*x);
            }
            *x = pEVar3;
          }
          PKCS8_PRIV_KEY_INFO_free(pPVar2);
          goto LAB_08159263;
        }
      }
    }
    else {
      iVar1 = pem_check_suffix(local_430,"PRIVATE KEY");
      if (((0 < iVar1) &&
          (piVar4 = (int *)EVP_PKEY_asn1_find_str((ENGINE **)0x0,local_430,iVar1),
          piVar4 != (int *)0x0)) && (piVar4[0x17] != 0)) {
        pEVar3 = d2i_PrivateKey(*piVar4,x,&local_42c,local_424);
        goto LAB_08159263;
      }
    }
LAB_08159270:
    pEVar3 = (EVP_PKEY *)0x0;
    ERR_put_error(9,0x7b,0xd,"pem_pkey.c",0x84);
  }
LAB_0815928d:
  CRYPTO_free(local_430);
  OPENSSL_cleanse(local_428,local_424);
  CRYPTO_free(local_428);
LAB_081592b7:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pEVar3;
}

