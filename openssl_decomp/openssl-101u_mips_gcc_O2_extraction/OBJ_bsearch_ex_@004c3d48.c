
void * OBJ_bsearch_ex_(void *key,void *base,int num,int size,cmp *cmp,int flags)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  
  if (num != 0) {
    if (num < 1) {
      uVar2 = flags & 2;
      pvVar4 = base;
    }
    else {
      iVar5 = 0;
      do {
        while( true ) {
          iVar3 = (num + iVar5) / 2;
          pvVar4 = (void *)(iVar3 * size + (int)base);
          iVar1 = (*cmp)(key,pvVar4);
          if (-1 < iVar1) break;
          num = iVar3;
          if (iVar3 <= iVar5) goto LAB_004c3de0;
        }
        iVar5 = iVar3 + 1;
        if (iVar1 == 0) goto LAB_004c3e24;
      } while (iVar5 < num);
LAB_004c3de0:
      if (iVar1 == 0) {
LAB_004c3e24:
        if ((flags & 2U) == 0) {
          return pvVar4;
        }
        if (iVar3 < 1) {
          return pvVar4;
        }
        iVar5 = iVar3 + -1;
        pvVar4 = (void *)((iVar3 + -1) * size + (int)base);
        while( true ) {
          iVar1 = (*cmp)(key,pvVar4);
          if (iVar1 != 0) {
            return (void *)(size * iVar3 + (int)base);
          }
          if (iVar5 == 0) break;
          iVar3 = iVar5;
          iVar5 = iVar5 + -1;
          pvVar4 = (void *)((int)pvVar4 - size);
        }
        return pvVar4;
      }
      uVar2 = flags & 1;
    }
    if (uVar2 != 0) {
      return pvVar4;
    }
  }
  return (void *)0x0;
}

