
void dtls1_clear_sent_buffer(int param_1)

{
  pitem *item;
  
  while (item = pqueue_pop(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x248)), item != (pitem *)0x0) {
    dtls1_hm_fragment_free(item->data);
    pitem_free(item);
  }
  return;
}

