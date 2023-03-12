
void dtls1_start_timer(SSL *param_1)

{
  dtls1_state_st *pdVar1;
  BIO *bp;
  
  pdVar1 = param_1->d1;
  if (((pdVar1->next_timeout).tv_usec == 0) && (*(int *)&pdVar1->timeout_duration == 0)) {
    *(undefined2 *)&pdVar1->alert_fragment_len = 1;
  }
  gettimeofday((timeval *)&(pdVar1->next_timeout).tv_usec,(__timezone_ptr_t)0x0);
  pdVar1 = param_1->d1;
  (pdVar1->next_timeout).tv_usec =
       (pdVar1->next_timeout).tv_usec + (uint)*(ushort *)&pdVar1->alert_fragment_len;
  bp = SSL_get_rbio(param_1);
  BIO_ctrl(bp,0x2d,0,&(param_1->d1->next_timeout).tv_usec);
  return;
}

