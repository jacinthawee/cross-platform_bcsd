
void dtls1_double_timeout(SSL *param_1)

{
  dtls1_state_st *pdVar1;
  BIO *bp;
  ushort uVar2;
  
  pdVar1 = param_1->d1;
  uVar2 = *(short *)pdVar1->handshake_fragment * 2;
  if (0x3c < uVar2) {
    uVar2 = 0x3c;
  }
  *(ushort *)pdVar1->handshake_fragment = uVar2;
  if ((*(int *)&pdVar1->timeout_duration == 0) && (pdVar1->alert_fragment_len == 0)) {
    *(undefined2 *)pdVar1->handshake_fragment = 1;
  }
  gettimeofday((timeval *)&pdVar1->timeout_duration,(__timezone_ptr_t)0x0);
  pdVar1 = param_1->d1;
  *(uint *)&pdVar1->timeout_duration =
       *(int *)&pdVar1->timeout_duration + (uint)*(ushort *)pdVar1->handshake_fragment;
  bp = SSL_get_rbio(param_1);
  BIO_ctrl(bp,0x2d,0,&pdVar1->timeout_duration);
  return;
}

