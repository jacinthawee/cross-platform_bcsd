
int SSL_use_RSAPrivateKey_file(SSL *ssl,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  RSA *rsa;
  RSA *pRVar2;
  int reason;
  
  type_00 = BIO_s_file();
  bp = BIO_new(type_00);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xce,7,"ssl_rsa.c",0xec);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    rsa = (RSA *)0x0;
    ERR_put_error(0x14,0xce,2,"ssl_rsa.c",0xf1);
  }
  else {
    if (type == 2) {
      rsa = d2i_RSAPrivateKey_bio(bp,(RSA **)0x0);
      reason = 0xd;
    }
    else {
      if (type != 1) {
        ERR_put_error(0x14,0xce,0x7c,"ssl_rsa.c",0xfe);
        rsa = (RSA *)0x0;
        goto LAB_00065b4c;
      }
      rsa = PEM_read_bio_RSAPrivateKey
                      (bp,(RSA **)0x0,*(undefined1 **)(ssl->psk_server_callback + 0x6c),
                       *(void **)(ssl->psk_server_callback + 0x70));
      reason = 9;
    }
    if (rsa == (RSA *)0x0) {
      ERR_put_error(0x14,0xce,reason,"ssl_rsa.c",0x102);
    }
    else {
      pRVar2 = (RSA *)SSL_use_RSAPrivateKey(ssl,rsa);
      RSA_free(rsa);
      rsa = pRVar2;
    }
  }
LAB_00065b4c:
  BIO_free(bp);
  return (int)rsa;
}

