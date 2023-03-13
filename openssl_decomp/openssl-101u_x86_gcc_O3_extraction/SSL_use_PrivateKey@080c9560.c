
int SSL_use_PrivateKey(SSL *ssl,EVP_PKEY *pkey)

{
  int *piVar1;
  int iVar2;
  EVP_PKEY *to;
  int iVar3;
  uint uVar4;
  
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0x14,0xc9,0x43,"ssl_rsa.c",0x125);
    return 0;
  }
  iVar2 = ssl_cert_inst(&ssl->cert);
  if (iVar2 == 0) {
    ERR_put_error(0x14,0xc9,0x41,"ssl_rsa.c",0x129);
    return 0;
  }
  piVar1 = (int *)ssl->cert;
  iVar2 = ssl_cert_type(0,pkey);
  if (iVar2 < 0) {
    ERR_put_error(0x14,0xc1,0xf7,"ssl_rsa.c",0xb4);
    iVar2 = 0;
  }
  else {
    if ((X509 *)piVar1[iVar2 * 3 + 0xc] != (X509 *)0x0) {
      to = X509_get_pubkey((X509 *)piVar1[iVar2 * 3 + 0xc]);
      if (to == (EVP_PKEY *)0x0) {
        ERR_put_error(0x14,0xc1,0x41,"ssl_rsa.c",0xbc);
        EVP_PKEY_free((EVP_PKEY *)0x0);
        return 0;
      }
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
    CRYPTO_add_lock(&pkey->references,1,10,"ssl_rsa.c",0xda);
    piVar1[iVar2 * 3 + 0xd] = (int)pkey;
    piVar1[1] = 0;
    *piVar1 = (int)(piVar1 + iVar2 * 3 + 0xc);
    iVar2 = 1;
  }
  return iVar2;
}

