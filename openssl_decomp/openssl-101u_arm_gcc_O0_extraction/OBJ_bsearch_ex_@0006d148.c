
void * OBJ_bsearch_ex_(void *key,void *base,int num,int size,cmp *cmp,int flags)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  if (num != 0) {
    if (num < 1) {
      if ((flags & 2U) == 0) {
        return (void *)0x0;
      }
      return base;
    }
    iVar3 = 0;
    do {
      while( true ) {
        iVar2 = iVar3 + num >> 1;
        pvVar4 = (void *)(size * iVar2 + (int)base);
        iVar1 = (*cmp)(key,pvVar4);
        if (-1 < iVar1) break;
        num = iVar2;
        if (iVar2 <= iVar3) goto LAB_0006d182;
      }
      if (iVar1 == 0) goto LAB_0006d194;
      iVar3 = iVar2 + 1;
    } while (iVar3 < num);
LAB_0006d182:
    if (iVar1 == 0) {
LAB_0006d194:
      if (-1 < flags << 0x1e) {
        return pvVar4;
      }
      if (iVar2 == 0) {
        return pvVar4;
      }
      iVar3 = iVar2 + -1;
      pvVar4 = (void *)((iVar2 + -1) * size + (int)base);
      while( true ) {
        iVar1 = (*cmp)(key,pvVar4);
        if (iVar1 != 0) {
          return (void *)(iVar2 * size + (int)base);
        }
        if (iVar3 == 0) break;
        iVar2 = iVar3;
        iVar3 = iVar3 + -1;
        pvVar4 = (void *)((int)pvVar4 - size);
      }
      return pvVar4;
    }
    if (flags << 0x1f < 0) {
      return pvVar4;
    }
  }
  return (void *)0x0;
}

