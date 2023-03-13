
void dtls1_stop_timer(SSL *param_1)

{
  dtls1_state_st *pdVar1;
  BIO *bp;
  pitem *item;
  
  pdVar1 = param_1->d1;
  (pdVar1->timeout).num_alerts = 0;
  (pdVar1->next_timeout).tv_sec = 0;
  (pdVar1->next_timeout).tv_usec = 0;
  pdVar1 = param_1->d1;
  *(undefined4 *)&pdVar1->timeout_duration = 0;
  pdVar1->alert_fragment_len = 0;
  pdVar1 = param_1->d1;
  *(undefined2 *)pdVar1->handshake_fragment = 1;
  bp = SSL_get_rbio(param_1);
  BIO_ctrl(bp,0x2d,0,&pdVar1->timeout_duration);
  while( true ) {
    item = pqueue_pop(param_1->d1->sent_messages);
    if (item == (pitem *)0x0) break;
    dtls1_hm_fragment_free(item->data);
    pitem_free(item);
  }
  return;
}

