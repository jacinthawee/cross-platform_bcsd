
void * OBJ_bsearch_ex_(void *key,void *base,int num,int size,cmp *cmp,int flags)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  
  if (num != 0) {
    if (num < 1) {
      uVar1 = flags & 2;
      pvVar3 = base;
    }
    else {
      iVar6 = 0;
      do {
        while( true ) {
          iVar5 = (num + iVar6) / 2;
          pvVar3 = (void *)(size * iVar5 + (int)base);
          iVar2 = (*cmp)(key,pvVar3);
          if (-1 < iVar2) break;
          num = iVar5;
          if (iVar5 <= iVar6) goto LAB_080d75dd;
        }
        if (iVar2 == 0) goto LAB_080d75f8;
        iVar6 = iVar5 + 1;
      } while (iVar6 < num);
LAB_080d75dd:
      if (iVar2 == 0) {
LAB_080d75f8:
        if ((flags & 2U) == 0) {
          return pvVar3;
        }
        if (iVar5 < 1) {
          return pvVar3;
        }
        pvVar3 = (void *)((iVar5 + -1) * size + (int)base);
        do {
          pvVar4 = pvVar3;
          iVar6 = iVar5 + -1;
          iVar2 = (*cmp)(key,pvVar4);
          if (iVar2 != 0) {
            return (void *)(size * iVar5 + (int)base);
          }
          pvVar3 = (void *)((int)pvVar4 - size);
          iVar5 = iVar6;
        } while (iVar6 != 0);
        return pvVar4;
      }
      uVar1 = flags & 1;
    }
    if (uVar1 != 0) {
      return pvVar3;
    }
  }
  return (void *)0x0;
}

