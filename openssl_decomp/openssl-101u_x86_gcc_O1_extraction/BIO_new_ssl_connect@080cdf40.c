
BIO * BIO_new_ssl_connect(SSL_CTX *ctx)

{
  BIO_METHOD *type;
  BIO *append;
  BIO *pBVar1;
  SSL *s;
  
  type = BIO_s_connect();
  append = BIO_new(type);
  if (append != (BIO *)0x0) {
    pBVar1 = BIO_new((BIO_METHOD *)methods_sslp);
    if (pBVar1 != (BIO *)0x0) {
      s = SSL_new(ctx);
      if (s == (SSL *)0x0) {
        BIO_free(pBVar1);
      }
      else {
        SSL_set_connect_state(s);
        BIO_ctrl(pBVar1,0x6d,1,s);
        pBVar1 = BIO_push(pBVar1,append);
        if (pBVar1 != (BIO *)0x0) {
          return pBVar1;
        }
      }
    }
    BIO_free(append);
  }
  return (BIO *)0x0;
}

