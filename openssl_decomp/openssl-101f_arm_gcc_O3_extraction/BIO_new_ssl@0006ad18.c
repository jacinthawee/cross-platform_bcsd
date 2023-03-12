
BIO * BIO_new_ssl(SSL_CTX *ctx,int client)

{
  BIO *a;
  SSL *s;
  
  a = BIO_new((BIO_METHOD *)&methods_sslp);
  if (a == (BIO *)0x0) {
    return (BIO *)0x0;
  }
  s = SSL_new(ctx);
  if (s != (SSL *)0x0) {
    if (client == 0) {
      SSL_set_accept_state(s);
    }
    else {
      SSL_set_connect_state(s);
    }
    BIO_ctrl(a,0x6d,1,s);
    return a;
  }
  BIO_free(a);
  return (BIO *)0x0;
}
