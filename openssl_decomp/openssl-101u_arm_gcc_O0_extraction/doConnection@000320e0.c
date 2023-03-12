
SSL * doConnection(SSL *param_1)

{
  BIO_METHOD *type;
  BIO *pBVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  SSL *s;
  fd_set fStack_a0;
  
  type = BIO_s_connect();
  pBVar1 = BIO_new(type);
  if (pBVar1 == (BIO *)0x0) {
    return (SSL *)0x0;
  }
  BIO_ctrl(pBVar1,100,0,host);
  if (param_1 == (SSL *)0x0) {
    s = SSL_new(tm_ctx);
  }
  else {
    SSL_set_connect_state(param_1);
    s = param_1;
  }
  SSL_set_bio(s,pBVar1,pBVar1);
  while( true ) {
    iVar2 = SSL_connect(s);
    iVar3 = BIO_sock_should_retry(iVar2);
    if (iVar3 == 0) break;
    BIO_printf(bio_err,"DELAY\n");
    iVar2 = SSL_get_fd(s);
    memset(&fStack_a0,0,0x80);
    iVar3 = __fdelt_chk(iVar2);
    fStack_a0.fds_bits[iVar3] = fStack_a0.fds_bits[iVar3] | 1 << (iVar2 % 0x20 & 0xffU);
    select(iVar2 + 1,&fStack_a0,(fd_set *)0x0,(fd_set *)0x0,(timeval *)0x0);
  }
  if (iVar2 < 1) {
    BIO_printf(bio_err,"ERROR\n");
    pBVar1 = bio_err;
    if (verify_error == 0) {
      ERR_print_errors(bio_err);
    }
    else {
      pcVar4 = X509_verify_cert_error_string(verify_error);
      BIO_printf(pBVar1,"verify error:%s\n",pcVar4);
    }
    if (param_1 != (SSL *)0x0) {
      return (SSL *)0x0;
    }
    SSL_free(s);
    s = param_1;
  }
  return s;
}

