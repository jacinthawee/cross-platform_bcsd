
int SSL_use_certificate_ASN1(SSL *ssl,uchar *d,int len)

{
  X509 *a;
  int iVar1;
  uchar *local_14;
  
  local_14 = d;
  a = d2i_X509((X509 **)0x0,&local_14,len);
  if (a != (X509 *)0x0) {
    iVar1 = ssl_cert_inst(&ssl->cert);
    if (iVar1 == 0) {
      ERR_put_error(0x14,0xc6,0x41,"ssl_rsa.c",0x4e);
    }
    else {
      iVar1 = ssl_set_cert(ssl->cert,a);
    }
    X509_free(a);
    return iVar1;
  }
  ERR_put_error(0x14,199,0xd,"ssl_rsa.c",0x8e);
  return 0;
}

