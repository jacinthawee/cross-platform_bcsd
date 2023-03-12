
pitem * pitem_new(uchar *prio64be,void *data)

{
  pitem *ppVar1;
  undefined4 uVar2;
  undefined4 in_a3;
  
  ppVar1 = (pitem *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x10,"pqueue.c",0x47,in_a3,&_gp);
  if (ppVar1 != (pitem *)0x0) {
    uVar2 = *(undefined4 *)(prio64be + 4);
    *(undefined4 *)ppVar1->priority = *(undefined4 *)prio64be;
    *(undefined4 *)(ppVar1->priority + 4) = uVar2;
    ppVar1->data = data;
    ppVar1->next = (_pitem *)0x0;
  }
  return ppVar1;
}

