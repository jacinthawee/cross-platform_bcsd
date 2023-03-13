
int SSL_check_private_key(SSL *ctx)

{
  X509 **ppXVar1;
  X509 *x509;
  X509 *pkey;
  int iVar2;
  int line;
  
  if (ctx == (SSL *)0x0) {
    line = 0x396;
    iVar2 = 0x43;
  }
  else {
    if ((int *)ctx->cert == (int *)0x0) {
      line = 0x39a;
    }
    else {
      ppXVar1 = *(X509 ***)ctx->cert;
      x509 = *ppXVar1;
      if (x509 != (X509 *)0x0) {
        pkey = ppXVar1[1];
        if (pkey != (X509 *)0x0) {
          iVar2 = X509_check_private_key(x509,(EVP_PKEY *)pkey);
          return iVar2;
        }
        line = 0x3a2;
        iVar2 = 0xbe;
        goto LAB_080bdb9a;
      }
      line = 0x39e;
    }
    iVar2 = 0xb1;
  }
LAB_080bdb9a:
  ERR_put_error(0x14,0xa3,iVar2,"ssl_lib.c",line);
  return 0;
}

