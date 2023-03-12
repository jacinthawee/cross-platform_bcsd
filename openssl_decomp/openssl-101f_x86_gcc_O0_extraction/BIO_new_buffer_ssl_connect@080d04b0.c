
BIO * BIO_new_buffer_ssl_connect(SSL_CTX *ctx)

{
  BIO_METHOD *pBVar1;
  BIO *a;
  BIO *pBVar2;
  BIO *pBVar3;
  SSL *s;
  
  pBVar1 = BIO_f_buffer();
  a = BIO_new(pBVar1);
  if (a != (BIO *)0x0) {
    pBVar1 = BIO_s_connect();
    pBVar2 = BIO_new(pBVar1);
    if (pBVar2 != (BIO *)0x0) {
      pBVar3 = BIO_new((BIO_METHOD *)methods_sslp);
      if (pBVar3 != (BIO *)0x0) {
        s = SSL_new(ctx);
        if (s == (SSL *)0x0) {
          BIO_free(pBVar3);
        }
        else {
          SSL_set_connect_state(s);
          BIO_ctrl(pBVar3,0x6d,1,s);
          pBVar3 = BIO_push(pBVar3,pBVar2);
          if (pBVar3 != (BIO *)0x0) {
            pBVar2 = BIO_push(a,pBVar3);
            if (pBVar2 == (BIO *)0x0) {
              BIO_free(a);
              BIO_free(pBVar3);
            }
            return pBVar2;
          }
        }
      }
      BIO_free(pBVar2);
    }
    BIO_free(a);
  }
  return (BIO *)0x0;
}

