
undefined4 __regparm3 ssl_set_cert(int *param_1,X509 *param_2)

{
  EVP_PKEY *pkey;
  int iVar1;
  EVP_PKEY *pkey_00;
  int iVar2;
  uint uVar3;
  
  pkey = X509_get_pubkey(param_2);
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0x14,0xbf,0x10c,"ssl_rsa.c",0x181);
    return 0;
  }
  iVar1 = ssl_cert_type(param_2,pkey);
  if (iVar1 < 0) {
    ERR_put_error(0x14,0xbf,0xf7,"ssl_rsa.c",0x187);
    EVP_PKEY_free(pkey);
    return 0;
  }
  if ((EVP_PKEY *)param_1[iVar1 * 3 + 0xd] != (EVP_PKEY *)0x0) {
    EVP_PKEY_copy_parameters(pkey,(EVP_PKEY *)param_1[iVar1 * 3 + 0xd]);
    ERR_clear_error();
    pkey_00 = (EVP_PKEY *)param_1[iVar1 * 3 + 0xd];
    if (pkey_00->type == 6) {
      uVar3 = RSA_flags((pkey_00->pkey).rsa);
      if ((uVar3 & 1) != 0) goto LAB_080c8a89;
      pkey_00 = (EVP_PKEY *)param_1[iVar1 * 3 + 0xd];
    }
    iVar2 = X509_check_private_key(param_2,pkey_00);
    if (iVar2 == 0) {
      EVP_PKEY_free((EVP_PKEY *)param_1[iVar1 * 3 + 0xd]);
      param_1[iVar1 * 3 + 0xd] = 0;
      ERR_clear_error();
    }
  }
LAB_080c8a89:
  EVP_PKEY_free(pkey);
  if ((X509 *)param_1[iVar1 * 3 + 0xc] != (X509 *)0x0) {
    X509_free((X509 *)param_1[iVar1 * 3 + 0xc]);
  }
  CRYPTO_add_lock(&param_2->references,1,3,"ssl_rsa.c",0x1af);
  param_1[iVar1 * 3 + 0xc] = (int)param_2;
  param_1[1] = 0;
  *param_1 = (int)(param_1 + iVar1 * 3 + 0xc);
  return 1;
}

