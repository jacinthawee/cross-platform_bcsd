
void __regparm3 dtls1_clear_queues_isra_0(int *param_1)

{
  pitem *ppVar1;
  void *pvVar2;
  
  while (ppVar1 = pqueue_pop(*(pqueue *)(*param_1 + 0x238)), ppVar1 != (pitem *)0x0) {
    pvVar2 = ppVar1->data;
    if (*(void **)((int)pvVar2 + 8) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)pvVar2 + 8));
      pvVar2 = ppVar1->data;
    }
    CRYPTO_free(pvVar2);
    pitem_free(ppVar1);
  }
  while (ppVar1 = pqueue_pop(*(pqueue *)(*param_1 + 0x240)), ppVar1 != (pitem *)0x0) {
    pvVar2 = ppVar1->data;
    if (*(void **)((int)pvVar2 + 8) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)pvVar2 + 8));
      pvVar2 = ppVar1->data;
    }
    CRYPTO_free(pvVar2);
    pitem_free(ppVar1);
  }
  while (ppVar1 = pqueue_pop(*(pqueue *)(*param_1 + 0x244)), ppVar1 != (pitem *)0x0) {
    pvVar2 = ppVar1->data;
    CRYPTO_free(*(void **)((int)pvVar2 + 0x2c));
    CRYPTO_free(pvVar2);
    pitem_free(ppVar1);
  }
  while (ppVar1 = pqueue_pop(*(pqueue *)(*param_1 + 0x248)), ppVar1 != (pitem *)0x0) {
    pvVar2 = ppVar1->data;
    CRYPTO_free(*(void **)((int)pvVar2 + 0x2c));
    CRYPTO_free(pvVar2);
    pitem_free(ppVar1);
  }
  while (ppVar1 = pqueue_pop(*(pqueue *)(*param_1 + 0x250)), ppVar1 != (pitem *)0x0) {
    pvVar2 = ppVar1->data;
    CRYPTO_free(*(void **)((int)pvVar2 + 0x2c));
    CRYPTO_free(pvVar2);
    pitem_free(ppVar1);
  }
  return;
}

