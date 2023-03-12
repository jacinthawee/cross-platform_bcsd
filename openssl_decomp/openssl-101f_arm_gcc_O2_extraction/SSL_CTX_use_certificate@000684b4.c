
int SSL_CTX_use_certificate(SSL_CTX *ctx,X509 *x)

{
  int iVar1;
  EVP_PKEY *pkey;
  int iVar2;
  EVP_PKEY *pkey_00;
  cert_st **ppcVar3;
  
  if (x == (X509 *)0x0) {
    ERR_put_error(0x14,0xab,0x43,"ssl_rsa.c",0x17f);
    return 0;
  }
  iVar1 = ssl_cert_inst(&ctx->cert);
  if (iVar1 == 0) {
    ERR_put_error(0x14,0xab,0x41,"ssl_rsa.c",0x184);
    return 0;
  }
  ppcVar3 = (cert_st **)ctx->cert;
  pkey = X509_get_pubkey(x);
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0x14,0xbf,0x10c,"ssl_rsa.c",0x192);
    return 0;
  }
  iVar1 = ssl_cert_type(x,pkey);
  if (iVar1 < 0) {
    ERR_put_error(0x14,0xbf,0xf7,"ssl_rsa.c",0x199);
    EVP_PKEY_free(pkey);
    return 0;
  }
  if ((EVP_PKEY *)ppcVar3[iVar1 * 3 + 0xd] != (EVP_PKEY *)0x0) {
    EVP_PKEY_copy_parameters(pkey,(EVP_PKEY *)ppcVar3[iVar1 * 3 + 0xd]);
    ERR_clear_error();
    pkey_00 = (EVP_PKEY *)ppcVar3[iVar1 * 3 + 0xd];
    if (pkey_00->type == 6) {
      iVar2 = RSA_flags((pkey_00->pkey).rsa);
      if (iVar2 << 0x1f < 0) goto LAB_0006851c;
      pkey_00 = (EVP_PKEY *)ppcVar3[iVar1 * 3 + 0xd];
    }
    iVar2 = X509_check_private_key(x,pkey_00);
    if (iVar2 == 0) {
      EVP_PKEY_free((EVP_PKEY *)ppcVar3[iVar1 * 3 + 0xd]);
      ppcVar3[iVar1 * 3 + 0xd] = (cert_st *)0x0;
      ERR_clear_error();
    }
  }
LAB_0006851c:
  EVP_PKEY_free(pkey);
  if ((X509 *)ppcVar3[iVar1 * 3 + 0xc] != (X509 *)0x0) {
    X509_free((X509 *)ppcVar3[iVar1 * 3 + 0xc]);
  }
  CRYPTO_add_lock(&x->references,1,3,"ssl_rsa.c",0x1bd);
  ppcVar3[iVar1 * 3 + 0xc] = (cert_st *)x;
  *ppcVar3 = (cert_st *)(ppcVar3 + iVar1 * 3 + 0xc);
  ppcVar3[1] = (cert_st *)0x0;
  return 1;
}

