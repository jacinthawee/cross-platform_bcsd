
void * OBJ_bsearch_(void *key,void *base,int num,int size,cmp *cmp)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  if (0 < num) {
    iVar3 = 0;
    do {
      while( true ) {
        iVar2 = (num + iVar3) / 2;
        pvVar4 = (void *)(size * iVar2 + (int)base);
        iVar1 = (*cmp)(key,pvVar4);
        if (-1 < iVar1) break;
        num = iVar2;
        if (iVar2 <= iVar3) goto LAB_004c6c80;
      }
      iVar3 = iVar2 + 1;
      if (iVar1 == 0) {
        return pvVar4;
      }
    } while (iVar3 < num);
LAB_004c6c80:
    if (iVar1 == 0) {
      return pvVar4;
    }
  }
  return (void *)0x0;
}

