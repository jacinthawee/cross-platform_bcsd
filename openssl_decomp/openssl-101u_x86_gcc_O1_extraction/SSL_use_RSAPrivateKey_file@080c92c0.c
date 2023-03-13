
int SSL_use_RSAPrivateKey_file(SSL *ssl,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  RSA *rsa;
  int iVar2;
  int reason;
  int line;
  
  type_00 = BIO_s_file();
  bp = BIO_new(type_00);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xce,7,"ssl_rsa.c",0xec);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    line = 0xf1;
    reason = 2;
  }
  else {
    if (type == 2) {
      rsa = d2i_RSAPrivateKey_bio(bp,(RSA **)0x0);
      reason = 0xd;
    }
    else {
      if (type != 1) {
        line = 0xfe;
        reason = 0x7c;
        goto LAB_080c9318;
      }
      rsa = PEM_read_bio_RSAPrivateKey
                      (bp,(RSA **)0x0,*(undefined1 **)(ssl->psk_server_callback + 0x6c),
                       *(void **)(ssl->psk_server_callback + 0x70));
      reason = 9;
    }
    if (rsa != (RSA *)0x0) {
      iVar2 = SSL_use_RSAPrivateKey(ssl,rsa);
      RSA_free(rsa);
      goto LAB_080c9329;
    }
    line = 0x102;
  }
LAB_080c9318:
  iVar2 = 0;
  ERR_put_error(0x14,0xce,reason,"ssl_rsa.c",line);
LAB_080c9329:
  BIO_free(bp);
  return iVar2;
}

