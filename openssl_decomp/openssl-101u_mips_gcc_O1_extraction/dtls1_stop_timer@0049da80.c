
void dtls1_stop_timer(SSL *param_1)

{
  BIO *pBVar1;
  int iVar2;
  dtls1_state_st *pdVar3;
  
  pdVar3 = param_1->d1;
  *(undefined *)&(pdVar3->timeout).num_alerts = 0;
  *(undefined *)((int)&(pdVar3->timeout).num_alerts + 1) = 0;
  *(undefined *)((int)&(pdVar3->timeout).num_alerts + 2) = 0;
  *(undefined *)((int)&(pdVar3->timeout).num_alerts + 3) = 0;
  *(undefined *)&(pdVar3->next_timeout).tv_sec = 0;
  *(undefined *)((int)&(pdVar3->next_timeout).tv_sec + 1) = 0;
  *(undefined *)((int)&(pdVar3->next_timeout).tv_sec + 2) = 0;
  *(undefined *)((int)&(pdVar3->next_timeout).tv_sec + 3) = 0;
  *(undefined *)&(pdVar3->next_timeout).tv_usec = 0;
  *(undefined *)((int)&(pdVar3->next_timeout).tv_usec + 1) = 0;
  *(undefined *)((int)&(pdVar3->next_timeout).tv_usec + 2) = 0;
  *(undefined *)((int)&(pdVar3->next_timeout).tv_usec + 3) = 0;
  pdVar3 = param_1->d1;
  *(undefined *)&pdVar3->timeout_duration = 0;
  *(undefined *)((int)&pdVar3->timeout_duration + 1) = 0;
  pdVar3->alert_fragment[0] = '\0';
  pdVar3->alert_fragment[1] = '\0';
  *(undefined *)&pdVar3->alert_fragment_len = 0;
  *(undefined *)((int)&pdVar3->alert_fragment_len + 1) = 0;
  *(undefined *)((int)&pdVar3->alert_fragment_len + 2) = 0;
  *(undefined *)((int)&pdVar3->alert_fragment_len + 3) = 0;
  *(undefined2 *)param_1->d1->handshake_fragment = 1;
  pBVar1 = SSL_get_rbio(param_1);
  (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar1,0x2d,0,&param_1->d1->timeout_duration);
  while (iVar2 = (*(code *)PTR_pqueue_pop_006a827c)(param_1->d1->sent_messages), iVar2 != 0) {
    dtls1_hm_fragment_free(*(undefined4 *)(iVar2 + 8));
    (*(code *)PTR_pitem_free_006a8278)(iVar2);
  }
  return;
}

