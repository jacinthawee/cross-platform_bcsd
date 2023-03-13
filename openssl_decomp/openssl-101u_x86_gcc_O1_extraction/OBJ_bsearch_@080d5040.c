
void * OBJ_bsearch_(void *key,void *base,int num,int size,cmp *cmp)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  if (0 < num) {
    iVar4 = 0;
    do {
      while( true ) {
        iVar3 = (num + iVar4) / 2;
        pvVar2 = (void *)(size * iVar3 + (int)base);
        iVar1 = (*cmp)(key,pvVar2);
        if (-1 < iVar1) break;
        num = iVar3;
        if (iVar3 <= iVar4) goto LAB_080d5099;
      }
      if (iVar1 == 0) {
        return pvVar2;
      }
      iVar4 = iVar3 + 1;
    } while (iVar4 < num);
LAB_080d5099:
    if (iVar1 == 0) {
      return pvVar2;
    }
  }
  return (void *)0x0;
}

