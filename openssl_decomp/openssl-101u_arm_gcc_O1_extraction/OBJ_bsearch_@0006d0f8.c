
void * OBJ_bsearch_(void *key,void *base,int num,int size,cmp *cmp)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  if (num == 0) {
    return (void *)0x0;
  }
  if (num < 1) {
    pvVar4 = (void *)0x0;
  }
  else {
    iVar3 = 0;
    do {
      while( true ) {
        iVar2 = (iVar3 + num) / 2;
        pvVar4 = (void *)(iVar2 * size + (int)base);
        iVar1 = (*cmp)(key,pvVar4);
        if (-1 < iVar1) break;
        num = iVar2;
        if (iVar2 <= iVar3) goto LAB_0006d134;
      }
      if (iVar1 == 0) {
        return pvVar4;
      }
      iVar3 = iVar2 + 1;
    } while (iVar3 < num);
LAB_0006d134:
    if (iVar1 != 0) {
      return (void *)0x0;
    }
  }
  return pvVar4;
}

