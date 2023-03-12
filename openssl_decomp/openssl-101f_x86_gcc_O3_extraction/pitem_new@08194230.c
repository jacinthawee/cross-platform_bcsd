
pitem * pitem_new(uchar *prio64be,void *data)

{
  undefined4 uVar1;
  undefined4 uVar2;
  pitem *ppVar3;
  
  ppVar3 = (pitem *)CRYPTO_malloc(0x10,"pqueue.c",0x49);
  if (ppVar3 != (pitem *)0x0) {
    uVar1 = *(undefined4 *)(prio64be + 4);
    uVar2 = *(undefined4 *)prio64be;
    ppVar3->next = (_pitem *)0x0;
    *(undefined4 *)ppVar3->priority = uVar2;
    *(undefined4 *)(ppVar3->priority + 4) = uVar1;
    ppVar3->data = data;
  }
  return ppVar3;
}

