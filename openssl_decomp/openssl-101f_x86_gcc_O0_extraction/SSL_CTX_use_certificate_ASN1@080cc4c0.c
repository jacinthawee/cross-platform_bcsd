
int SSL_CTX_use_certificate_ASN1(SSL_CTX *ctx,int len,uchar *d)

{
  X509 *a;
  int iVar1;
  
  a = d2i_X509((X509 **)0x0,&d,len);
  if (a != (X509 *)0x0) {
    iVar1 = ssl_cert_inst(&ctx->cert);
    if (iVar1 == 0) {
      ERR_put_error(0x14,0xab,0x41,"ssl_rsa.c",0x184);
    }
    else {
      iVar1 = ssl_set_cert();
    }
    X509_free(a);
    return iVar1;
  }
  ERR_put_error(0x14,0xac,0xd,"ssl_rsa.c",0x1ff);
  return 0;
}

