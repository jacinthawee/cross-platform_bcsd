
int SSL_CTX_use_PrivateKey(SSL_CTX *ctx,EVP_PKEY *pkey)

{
  int iVar1;
  EVP_PKEY *to;
  int iVar2;
  cert_st **ppcVar3;
  
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0x14,0xae,0x43,"ssl_rsa.c",0x253);
    return 0;
  }
  iVar1 = ssl_cert_inst(&ctx->cert);
  if (iVar1 == 0) {
    ERR_put_error(0x14,0xae,0x41,"ssl_rsa.c",599);
    return 0;
  }
  ppcVar3 = (cert_st **)ctx->cert;
  iVar1 = ssl_cert_type(0,pkey);
  if (iVar1 < 0) {
    iVar2 = 0;
    ERR_put_error(0x14,0xc1,0xf7,"ssl_rsa.c",0xb4);
  }
  else {
    if ((X509 *)ppcVar3[iVar1 * 3 + 0xc] != (X509 *)0x0) {
      to = X509_get_pubkey((X509 *)ppcVar3[iVar1 * 3 + 0xc]);
      if (to == (EVP_PKEY *)0x0) {
        ERR_put_error(0x14,0xc1,0x41,"ssl_rsa.c",0xbc);
        EVP_PKEY_free((EVP_PKEY *)0x0);
        return 0;
      }
      EVP_PKEY_copy_parameters(to,pkey);
      EVP_PKEY_free(to);
      ERR_clear_error();
      if (((pkey->type != 6) || (iVar2 = RSA_flags((pkey->pkey).rsa), -1 < iVar2 << 0x1f)) &&
         (iVar2 = X509_check_private_key((X509 *)ppcVar3[iVar1 * 3 + 0xc],pkey), iVar2 == 0)) {
        X509_free((X509 *)ppcVar3[iVar1 * 3 + 0xc]);
        ppcVar3[iVar1 * 3 + 0xc] = (cert_st *)0x0;
        return 0;
      }
    }
    if ((EVP_PKEY *)ppcVar3[iVar1 * 3 + 0xd] != (EVP_PKEY *)0x0) {
      EVP_PKEY_free((EVP_PKEY *)ppcVar3[iVar1 * 3 + 0xd]);
    }
    iVar2 = 1;
    CRYPTO_add_lock(&pkey->references,1,10,"ssl_rsa.c",0xda);
    ppcVar3[iVar1 * 3 + 0xd] = (cert_st *)pkey;
    ppcVar3[1] = (cert_st *)0x0;
    *ppcVar3 = (cert_st *)(ppcVar3 + iVar1 * 3 + 0xc);
  }
  return iVar2;
}

