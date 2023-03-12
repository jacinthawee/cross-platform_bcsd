
void dtls1_stop_timer(SSL *param_1)

{
  BIO *pBVar1;
  int iVar2;
  dtls1_state_st *pdVar3;
  void *ptr;
  
  pdVar3 = param_1->d1;
  *(undefined *)&(pdVar3->timeout).write_timeouts = 0;
  *(undefined *)((int)&(pdVar3->timeout).write_timeouts + 1) = 0;
  *(undefined *)((int)&(pdVar3->timeout).write_timeouts + 2) = 0;
  *(undefined *)((int)&(pdVar3->timeout).write_timeouts + 3) = 0;
  *(undefined *)&(pdVar3->timeout).num_alerts = 0;
  *(undefined *)((int)&(pdVar3->timeout).num_alerts + 1) = 0;
  *(undefined *)((int)&(pdVar3->timeout).num_alerts + 2) = 0;
  *(undefined *)((int)&(pdVar3->timeout).num_alerts + 3) = 0;
  *(undefined *)&(pdVar3->next_timeout).tv_sec = 0;
  *(undefined *)((int)&(pdVar3->next_timeout).tv_sec + 1) = 0;
  *(undefined *)((int)&(pdVar3->next_timeout).tv_sec + 2) = 0;
  *(undefined *)((int)&(pdVar3->next_timeout).tv_sec + 3) = 0;
  pdVar3 = param_1->d1;
  *(undefined *)&(pdVar3->next_timeout).tv_usec = 0;
  *(undefined *)((int)&(pdVar3->next_timeout).tv_usec + 1) = 0;
  *(undefined *)((int)&(pdVar3->next_timeout).tv_usec + 2) = 0;
  *(undefined *)((int)&(pdVar3->next_timeout).tv_usec + 3) = 0;
  *(undefined *)&pdVar3->timeout_duration = 0;
  *(undefined *)((int)&pdVar3->timeout_duration + 1) = 0;
  pdVar3->alert_fragment[0] = '\0';
  pdVar3->alert_fragment[1] = '\0';
  *(undefined2 *)&param_1->d1->alert_fragment_len = 1;
  pBVar1 = SSL_get_rbio(param_1);
  (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar1,0x2d,0,&(param_1->d1->next_timeout).tv_usec);
  iVar2 = (*(code *)PTR_pqueue_pop_006a93a0)(param_1->d1->sent_messages);
  while (iVar2 != 0) {
    ptr = *(void **)(iVar2 + 8);
    if (*(int *)((int)ptr + 0x14) != 0) {
      (*(code *)PTR_EVP_CIPHER_CTX_free_006a93f8)(*(undefined4 *)((int)ptr + 0x18));
      (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)(*(undefined4 *)((int)ptr + 0x1c));
    }
    if (*(void **)((int)ptr + 0x2c) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)ptr + 0x2c));
    }
    if (*(void **)((int)ptr + 0x30) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)ptr + 0x30));
    }
    CRYPTO_free(ptr);
    (*(code *)PTR_pitem_free_006a939c)(iVar2);
    iVar2 = (*(code *)PTR_pqueue_pop_006a93a0)(param_1->d1->sent_messages);
  }
  return;
}

