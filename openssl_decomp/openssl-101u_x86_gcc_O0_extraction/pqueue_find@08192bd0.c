
pitem * pqueue_find(pqueue pq,uchar *prio64be)

{
  int iVar1;
  pitem *ppVar2;
  pitem *__s1;
  
  ppVar2 = *(pitem **)pq;
  if (*(pitem **)pq == (pitem *)0x0) {
    ppVar2 = (pitem *)0x0;
  }
  else {
    while (__s1 = ppVar2, ppVar2 = __s1->next, ppVar2 != (pitem *)0x0) {
      iVar1 = memcmp(__s1,prio64be,8);
      if (iVar1 == 0) {
        return __s1;
      }
    }
    iVar1 = memcmp(__s1,prio64be,8);
    if (iVar1 == 0) {
      ppVar2 = __s1;
    }
  }
  return ppVar2;
}

