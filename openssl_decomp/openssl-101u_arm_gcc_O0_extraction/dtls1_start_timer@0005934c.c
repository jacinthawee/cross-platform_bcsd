
void dtls1_start_timer(SSL *param_1)

{
  dtls1_state_st *pdVar1;
  BIO *bp;
  
  pdVar1 = param_1->d1;
  if ((*(int *)&pdVar1->timeout_duration == 0) && (pdVar1->alert_fragment_len == 0)) {
    *(undefined2 *)pdVar1->handshake_fragment = 1;
  }
  gettimeofday((timeval *)&pdVar1->timeout_duration,(__timezone_ptr_t)0x0);
  pdVar1 = param_1->d1;
  *(uint *)&pdVar1->timeout_duration =
       *(int *)&pdVar1->timeout_duration + (uint)*(ushort *)pdVar1->handshake_fragment;
  bp = SSL_get_rbio(param_1);
  BIO_ctrl(bp,0x2d,0,&param_1->d1->timeout_duration);
  return;
}

