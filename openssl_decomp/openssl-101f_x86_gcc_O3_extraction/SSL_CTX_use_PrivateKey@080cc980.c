
int SSL_CTX_use_PrivateKey(SSL_CTX *ctx,EVP_PKEY *pkey)

{
  int *piVar1;
  int iVar2;
  EVP_PKEY *to;
  int iVar3;
  uint uVar4;
  
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0x14,0xae,0x43,"ssl_rsa.c",0x26d);
    return 0;
  }
  iVar2 = ssl_cert_inst(&ctx->cert);
  if (iVar2 != 0) {
    piVar1 = (int *)ctx->cert;
    iVar2 = ssl_cert_type(0,pkey);
    if (iVar2 < 0) {
      ERR_put_error(0x14,0xc1,0xf7,"ssl_rsa.c",0xbd);
      iVar2 = 0;
    }
    else {
      if ((X509 *)piVar1[iVar2 * 3 + 0xc] != (X509 *)0x0) {
        to = X509_get_pubkey((X509 *)piVar1[iVar2 * 3 + 0xc]);
        EVP_PKEY_copy_parameters(to,pkey);
        EVP_PKEY_free(to);
        ERR_clear_error();
        if (((pkey->type != 6) || (uVar4 = RSA_flags((pkey->pkey).rsa), (uVar4 & 1) == 0)) &&
           (iVar3 = X509_check_private_key((X509 *)piVar1[iVar2 * 3 + 0xc],pkey), iVar3 == 0)) {
          X509_free((X509 *)piVar1[iVar2 * 3 + 0xc]);
          piVar1[iVar2 * 3 + 0xc] = 0;
          return 0;
        }
      }
      if ((EVP_PKEY *)piVar1[iVar2 * 3 + 0xd] != (EVP_PKEY *)0x0) {
        EVP_PKEY_free((EVP_PKEY *)piVar1[iVar2 * 3 + 0xd]);
      }
      CRYPTO_add_lock(&pkey->references,1,10,"ssl_rsa.c",0xdb);
      piVar1[iVar2 * 3 + 0xd] = (int)pkey;
      piVar1[1] = 0;
      *piVar1 = (int)(piVar1 + iVar2 * 3 + 0xc);
      iVar2 = 1;
    }
    return iVar2;
  }
  ERR_put_error(0x14,0xae,0x41,"ssl_rsa.c",0x272);
  return 0;
}
