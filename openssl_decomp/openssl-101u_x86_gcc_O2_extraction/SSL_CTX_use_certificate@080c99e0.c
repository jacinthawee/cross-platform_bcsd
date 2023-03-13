
int SSL_CTX_use_certificate(SSL_CTX *ctx,X509 *x)

{
  int *piVar1;
  int iVar2;
  EVP_PKEY *pkey;
  EVP_PKEY *pkey_00;
  int iVar3;
  uint uVar4;
  
  if (x == (X509 *)0x0) {
    ERR_put_error(0x14,0xab,0x43,"ssl_rsa.c",0x170);
    return 0;
  }
  iVar2 = ssl_cert_inst(&ctx->cert);
  if (iVar2 == 0) {
    ERR_put_error(0x14,0xab,0x41,"ssl_rsa.c",0x174);
    return 0;
  }
  piVar1 = (int *)ctx->cert;
  pkey = X509_get_pubkey(x);
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0x14,0xbf,0x10c,"ssl_rsa.c",0x181);
    return 0;
  }
  iVar2 = ssl_cert_type(x,pkey);
  if (iVar2 < 0) {
    ERR_put_error(0x14,0xbf,0xf7,"ssl_rsa.c",0x187);
    EVP_PKEY_free(pkey);
    return 0;
  }
  if ((EVP_PKEY *)piVar1[iVar2 * 3 + 0xd] != (EVP_PKEY *)0x0) {
    EVP_PKEY_copy_parameters(pkey,(EVP_PKEY *)piVar1[iVar2 * 3 + 0xd]);
    ERR_clear_error();
    pkey_00 = (EVP_PKEY *)piVar1[iVar2 * 3 + 0xd];
    if (pkey_00->type == 6) {
      uVar4 = RSA_flags((pkey_00->pkey).rsa);
      if ((uVar4 & 1) != 0) goto LAB_080c9a8c;
      pkey_00 = (EVP_PKEY *)piVar1[iVar2 * 3 + 0xd];
    }
    iVar3 = X509_check_private_key(x,pkey_00);
    if (iVar3 == 0) {
      EVP_PKEY_free((EVP_PKEY *)piVar1[iVar2 * 3 + 0xd]);
      piVar1[iVar2 * 3 + 0xd] = 0;
      ERR_clear_error();
    }
  }
LAB_080c9a8c:
  EVP_PKEY_free(pkey);
  if ((X509 *)piVar1[iVar2 * 3 + 0xc] != (X509 *)0x0) {
    X509_free((X509 *)piVar1[iVar2 * 3 + 0xc]);
  }
  CRYPTO_add_lock(&x->references,1,3,"ssl_rsa.c",0x1af);
  piVar1[iVar2 * 3 + 0xc] = (int)x;
  piVar1[1] = 0;
  *piVar1 = (int)(piVar1 + iVar2 * 3 + 0xc);
  return 1;
}

