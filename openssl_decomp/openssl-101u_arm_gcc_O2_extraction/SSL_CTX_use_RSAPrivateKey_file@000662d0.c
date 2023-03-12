
int SSL_CTX_use_RSAPrivateKey_file(SSL_CTX *ctx,char *file,int type)

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
    ERR_put_error(0x14,0xb3,7,"ssl_rsa.c",0x21c);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    rsa = (RSA *)0x0;
    ERR_put_error(0x14,0xb3,2,"ssl_rsa.c",0x221);
  }
  else {
    if (type == 2) {
      rsa = d2i_RSAPrivateKey_bio(bp,(RSA **)0x0);
      reason = 0xd;
    }
    else {
      if (type != 1) {
        ERR_put_error(0x14,0xb3,0x7c,"ssl_rsa.c",0x22d);
        rsa = (RSA *)0x0;
        goto LAB_00066316;
      }
      rsa = PEM_read_bio_RSAPrivateKey
                      (bp,(RSA **)0x0,ctx->default_passwd_callback,
                       ctx->default_passwd_callback_userdata);
      reason = 9;
    }
    if (rsa == (RSA *)0x0) {
      ERR_put_error(0x14,0xb3,reason,"ssl_rsa.c",0x231);
    }
    else {
      pRVar2 = (RSA *)SSL_CTX_use_RSAPrivateKey(ctx,rsa);
      RSA_free(rsa);
      rsa = pRVar2;
    }
  }
LAB_00066316:
  BIO_free(bp);
  return (int)rsa;
}

