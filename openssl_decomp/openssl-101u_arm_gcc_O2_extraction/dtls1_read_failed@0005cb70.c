
int dtls1_read_failed(SSL *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  BIO *b;
  
  if (param_2 < 1) {
    iVar1 = dtls1_is_timer_expired();
    if (iVar1 == 0) {
      return param_2;
    }
    uVar2 = SSL_state(param_1);
    if (((uVar2 & 0x3000) != 0) || (param_1->tlsext_heartbeat != 0)) {
      iVar1 = dtls1_handle_timeout();
      return iVar1;
    }
    b = SSL_get_rbio(param_1);
    BIO_set_flags(b,1);
  }
  else {
    __fprintf_chk(stderr,1,"invalid state reached %s:%d","d1_both.c",0x4a7);
    param_2 = 1;
  }
  return param_2;
}

