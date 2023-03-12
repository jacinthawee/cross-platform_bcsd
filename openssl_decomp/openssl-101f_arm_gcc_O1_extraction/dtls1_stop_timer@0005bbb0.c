
void dtls1_stop_timer(SSL *param_1)

{
  BIO *bp;
  pitem *item;
  dtls1_state_st *pdVar1;
  void *ptr;
  
  pdVar1 = param_1->d1;
  *(undefined *)&(pdVar1->timeout).write_timeouts = 0;
  *(undefined *)((int)&(pdVar1->timeout).write_timeouts + 1) = 0;
  *(undefined *)((int)&(pdVar1->timeout).write_timeouts + 2) = 0;
  *(undefined *)((int)&(pdVar1->timeout).write_timeouts + 3) = 0;
  *(undefined *)&(pdVar1->timeout).num_alerts = 0;
  *(undefined *)((int)&(pdVar1->timeout).num_alerts + 1) = 0;
  *(undefined *)((int)&(pdVar1->timeout).num_alerts + 2) = 0;
  *(undefined *)((int)&(pdVar1->timeout).num_alerts + 3) = 0;
  *(undefined *)&(pdVar1->next_timeout).tv_sec = 0;
  *(undefined *)((int)&(pdVar1->next_timeout).tv_sec + 1) = 0;
  *(undefined *)((int)&(pdVar1->next_timeout).tv_sec + 2) = 0;
  *(undefined *)((int)&(pdVar1->next_timeout).tv_sec + 3) = 0;
  pdVar1 = param_1->d1;
  *(undefined *)&(pdVar1->next_timeout).tv_usec = 0;
  *(undefined *)((int)&(pdVar1->next_timeout).tv_usec + 1) = 0;
  *(undefined *)((int)&(pdVar1->next_timeout).tv_usec + 2) = 0;
  *(undefined *)((int)&(pdVar1->next_timeout).tv_usec + 3) = 0;
  *(undefined *)&pdVar1->timeout_duration = 0;
  *(undefined *)((int)&pdVar1->timeout_duration + 1) = 0;
  pdVar1->alert_fragment[0] = '\0';
  pdVar1->alert_fragment[1] = '\0';
  *(undefined2 *)&param_1->d1->alert_fragment_len = 1;
  bp = SSL_get_rbio(param_1);
  BIO_ctrl(bp,0x2d,0,&(param_1->d1->next_timeout).tv_usec);
  while (item = pqueue_pop(param_1->d1->sent_messages), item != (pitem *)0x0) {
    ptr = item->data;
    if (*(int *)((int)ptr + 0x14) != 0) {
      EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)((int)ptr + 0x18));
      EVP_MD_CTX_destroy(*(EVP_MD_CTX **)((int)ptr + 0x1c));
    }
    if (*(void **)((int)ptr + 0x2c) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)ptr + 0x2c));
    }
    if (*(void **)((int)ptr + 0x30) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)ptr + 0x30));
    }
    CRYPTO_free(ptr);
    pitem_free(item);
  }
  return;
}

