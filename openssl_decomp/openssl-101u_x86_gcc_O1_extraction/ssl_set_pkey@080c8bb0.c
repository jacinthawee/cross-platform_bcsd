
undefined4 __regparm3 ssl_set_pkey(int *param_1,EVP_PKEY *param_2)

{
  int iVar1;
  EVP_PKEY *to;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = ssl_cert_type(0,param_2);
  if (iVar1 < 0) {
    ERR_put_error(0x14,0xc1,0xf7,"ssl_rsa.c",0xb4);
    uVar3 = 0;
  }
  else {
    if ((X509 *)param_1[iVar1 * 3 + 0xc] != (X509 *)0x0) {
      to = X509_get_pubkey((X509 *)param_1[iVar1 * 3 + 0xc]);
      if (to == (EVP_PKEY *)0x0) {
        ERR_put_error(0x14,0xc1,0x41,"ssl_rsa.c",0xbc);
        EVP_PKEY_free((EVP_PKEY *)0x0);
        return 0;
      }
      EVP_PKEY_copy_parameters(to,param_2);
      EVP_PKEY_free(to);
      ERR_clear_error();
      if (((param_2->type != 6) || (uVar4 = RSA_flags((param_2->pkey).rsa), (uVar4 & 1) == 0)) &&
         (iVar2 = X509_check_private_key((X509 *)param_1[iVar1 * 3 + 0xc],param_2), iVar2 == 0)) {
        X509_free((X509 *)param_1[iVar1 * 3 + 0xc]);
        param_1[iVar1 * 3 + 0xc] = 0;
        return 0;
      }
    }
    if ((EVP_PKEY *)param_1[iVar1 * 3 + 0xd] != (EVP_PKEY *)0x0) {
      EVP_PKEY_free((EVP_PKEY *)param_1[iVar1 * 3 + 0xd]);
    }
    CRYPTO_add_lock(&param_2->references,1,10,"ssl_rsa.c",0xda);
    param_1[iVar1 * 3 + 0xd] = (int)param_2;
    param_1[1] = 0;
    *param_1 = (int)(param_1 + iVar1 * 3 + 0xc);
    uVar3 = 1;
  }
  return uVar3;
}

