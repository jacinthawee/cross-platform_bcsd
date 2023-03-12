
pitem * pqueue_find(pqueue pq,uchar *prio64be)

{
  pitem *ppVar1;
  int iVar2;
  pitem *ppVar3;
  
  ppVar3 = *(pitem **)pq;
  if (*(pitem **)pq == (pitem *)0x0) {
    ppVar1 = (pitem *)0x0;
  }
  else {
    while (ppVar1 = ppVar3, ppVar3 = ppVar1->next, ppVar3 != (_pitem *)0x0) {
      iVar2 = (*(code *)PTR_memcmp_006a9ad0)(ppVar1,prio64be,8);
      if (iVar2 == 0) {
        return ppVar1;
      }
    }
    iVar2 = (*(code *)PTR_memcmp_006a9ad0)();
    if (iVar2 != 0) {
      ppVar1 = (pitem *)0x0;
    }
  }
  return ppVar1;
}

