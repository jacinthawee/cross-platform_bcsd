
BIO * BIO_new_ssl(SSL_CTX *ctx,int client)

{
  BIO *pBVar1;
  SSL *s;
  
  pBVar1 = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(methods_sslp);
  if (pBVar1 == (BIO *)0x0) {
    pBVar1 = (BIO *)0x0;
  }
  else {
    s = SSL_new(ctx);
    if (s == (SSL *)0x0) {
      (*(code *)PTR_BIO_free_006a7f70)(pBVar1);
      pBVar1 = (BIO *)0x0;
    }
    else {
      if (client == 0) {
        SSL_set_accept_state(s);
      }
      else {
        SSL_set_connect_state(s);
      }
      (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar1,0x6d,1,s);
    }
  }
  return pBVar1;
}

