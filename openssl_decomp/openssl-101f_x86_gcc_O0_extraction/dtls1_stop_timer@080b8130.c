
void dtls1_stop_timer(SSL *param_1)

{
  dtls1_state_st *pdVar1;
  BIO *bp;
  
  pdVar1 = param_1->d1;
  (pdVar1->timeout).write_timeouts = 0;
  (pdVar1->timeout).num_alerts = 0;
  (pdVar1->next_timeout).tv_sec = 0;
  pdVar1 = param_1->d1;
  (pdVar1->next_timeout).tv_usec = 0;
  *(undefined4 *)&pdVar1->timeout_duration = 0;
  pdVar1 = param_1->d1;
  *(undefined2 *)&pdVar1->alert_fragment_len = 1;
  bp = SSL_get_rbio(param_1);
  BIO_ctrl(bp,0x2d,0,&(pdVar1->next_timeout).tv_usec);
  dtls1_clear_record_buffer();
  return;
}

