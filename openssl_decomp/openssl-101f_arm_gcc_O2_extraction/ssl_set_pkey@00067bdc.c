
undefined4 ssl_set_pkey(int *param_1,EVP_PKEY *param_2)

{
  int iVar1;
  EVP_PKEY *to;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = ssl_cert_type(0);
  if (iVar1 < 0) {
    uVar3 = 0;
    ERR_put_error(0x14,0xc1,0xf7,"ssl_rsa.c",0xbd);
  }
  else {
    if ((X509 *)param_1[iVar1 * 3 + 0xc] != (X509 *)0x0) {
      to = X509_get_pubkey((X509 *)param_1[iVar1 * 3 + 0xc]);
      EVP_PKEY_copy_parameters(to,param_2);
      EVP_PKEY_free(to);
      ERR_clear_error();
      if ((param_2->type != 6) || (iVar2 = RSA_flags((param_2->pkey).rsa), -1 < iVar2 << 0x1f)) {
        iVar2 = X509_check_private_key((X509 *)param_1[iVar1 * 3 + 0xc],param_2);
        if (iVar2 == 0) {
          X509_free((X509 *)param_1[iVar1 * 3 + 0xc]);
          param_1[iVar1 * 3 + 0xc] = 0;
          return 0;
        }
      }
    }
    if ((EVP_PKEY *)param_1[iVar1 * 3 + 0xd] != (EVP_PKEY *)0x0) {
      EVP_PKEY_free((EVP_PKEY *)param_1[iVar1 * 3 + 0xd]);
    }
    uVar3 = 1;
    CRYPTO_add_lock(&param_2->references,1,10,"ssl_rsa.c",0xdb);
    param_1[iVar1 * 3 + 0xd] = (int)param_2;
    param_1[1] = 0;
    *param_1 = (int)(param_1 + iVar1 * 3 + 0xc);
  }
  return uVar3;
}

