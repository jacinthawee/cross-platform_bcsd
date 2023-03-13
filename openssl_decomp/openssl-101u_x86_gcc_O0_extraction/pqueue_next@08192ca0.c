
pitem * pqueue_next(piterator *iter)

{
  pitem *ppVar1;
  
  if (iter == (piterator *)0x0) {
    ppVar1 = (pitem *)0x0;
  }
  else {
    ppVar1 = *iter;
    if (ppVar1 != (pitem *)0x0) {
      *iter = ppVar1->next;
      return ppVar1;
    }
  }
  return ppVar1;
}

