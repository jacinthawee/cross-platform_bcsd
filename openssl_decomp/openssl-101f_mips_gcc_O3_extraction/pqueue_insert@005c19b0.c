
pitem * pqueue_insert(pqueue pq,pitem *item)

{
  _pitem *p_Var1;
  int iVar2;
  _pitem *p_Var3;
  _pitem *p_Var4;
  
  p_Var1 = *(_pitem **)pq;
  p_Var4 = (_pitem *)0x0;
  if (*(_pitem **)pq != (_pitem *)0x0) {
    while (p_Var3 = p_Var1, iVar2 = (*(code *)PTR_memcmp_006aabd8)(p_Var3,item,8), iVar2 < 1) {
      if (iVar2 == 0) {
        return (pitem *)0x0;
      }
      p_Var1 = p_Var3->next;
      p_Var4 = p_Var3;
      if (p_Var3->next == (_pitem *)0x0) {
        item->next = (_pitem *)0x0;
        p_Var3->next = item;
        return item;
      }
    }
    item->next = p_Var3;
    if (p_Var4 != (_pitem *)0x0) {
      p_Var4->next = item;
      return item;
    }
  }
  *(pitem **)pq = item;
  return item;
}

