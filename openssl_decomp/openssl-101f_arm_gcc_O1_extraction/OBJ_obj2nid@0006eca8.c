
int OBJ_obj2nid(ASN1_OBJECT *o)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  size_t __n;
  int local_30;
  ASN1_OBJECT *pAStack_2c;
  
  if (o != (ASN1_OBJECT *)0x0) {
    iVar4 = o->nid;
    if (iVar4 != 0) {
      return iVar4;
    }
    if ((added != (_LHASH *)0x0) &&
       (local_30 = iVar4, pAStack_2c = o, pvVar2 = lh_retrieve(added,&local_30),
       pvVar2 != (void *)0x0)) {
      return *(int *)(*(int *)((int)pvVar2 + 4) + 8);
    }
    __n = o->length;
    iVar6 = 0;
    iVar4 = 0x359;
    do {
      while( true ) {
        iVar5 = iVar6 + iVar4 >> 1;
        iVar1 = *(int *)(obj_objs + iVar5 * 4) * 0x18;
        if (__n == *(size_t *)(&DAT_00140f94 + iVar1)) break;
        if (-1 < (int)(__n - *(size_t *)(&DAT_00140f94 + iVar1))) goto LAB_0006ed08;
LAB_0006ed30:
        iVar4 = iVar5;
        if (iVar5 <= iVar6) {
          return 0;
        }
      }
      iVar3 = memcmp(o->data,(&PTR_lvalues_00140f98)[*(int *)(obj_objs + iVar5 * 4) * 6],__n);
      if (iVar3 < 0) goto LAB_0006ed30;
      if (iVar3 == 0) {
        return *(int *)(&DAT_00140f90 + iVar1);
      }
LAB_0006ed08:
      iVar6 = iVar5 + 1;
    } while (iVar6 < iVar4);
  }
  return 0;
}

