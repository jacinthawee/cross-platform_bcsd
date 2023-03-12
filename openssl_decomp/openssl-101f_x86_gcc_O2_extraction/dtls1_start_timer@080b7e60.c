
void dtls1_start_timer(SSL *param_1)

{
  __suseconds_t *p_Var1;
  dtls1_state_st *pdVar2;
  BIO *bp;
  
  pdVar2 = param_1->d1;
  if (((pdVar2->next_timeout).tv_usec == 0) && (*(int *)&pdVar2->timeout_duration == 0)) {
    *(undefined2 *)&pdVar2->alert_fragment_len = 1;
  }
  gettimeofday((timeval *)&(pdVar2->next_timeout).tv_usec,(__timezone_ptr_t)0x0);
  pdVar2 = param_1->d1;
  p_Var1 = &(pdVar2->next_timeout).tv_usec;
  *p_Var1 = *p_Var1 + (uint)*(ushort *)&pdVar2->alert_fragment_len;
  bp = SSL_get_rbio(param_1);
  BIO_ctrl(bp,0x2d,0,&(pdVar2->next_timeout).tv_usec);
  return;
}

