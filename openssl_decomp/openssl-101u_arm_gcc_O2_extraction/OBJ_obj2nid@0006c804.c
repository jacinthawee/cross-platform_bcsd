
int OBJ_obj2nid(ASN1_OBJECT *o)

{
  undefined *puVar1;
  undefined *puVar2;
  void *pvVar3;
  undefined *puVar4;
  size_t __n;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_30;
  ASN1_OBJECT *local_2c;
  
  if (o != (ASN1_OBJECT *)0x0) {
    iVar5 = o->nid;
    if (iVar5 != 0) {
      return iVar5;
    }
    __n = o->length;
    if (__n == 0) {
      return 0;
    }
    if (added != (_LHASH *)0x0) {
      local_30 = iVar5;
      local_2c = o;
      pvVar3 = lh_retrieve(added,&local_30);
      if (pvVar3 != (void *)0x0) {
        return *(int *)(*(int *)((int)pvVar3 + 4) + 8);
      }
      __n = o->length;
      if (__n == 0) {
        iVar5 = 0x359;
        while( true ) {
          iVar6 = (int)(__n + iVar5) >> 1;
          iVar7 = *(int *)(obj_objs + iVar6 * 4);
          if (*(int *)(&DAT_0013fb4c + iVar7 * 0x18) == 0) break;
          if (*(int *)(&DAT_0013fb4c + iVar7 * 0x18) < 1) {
            __n = iVar6 + 1;
            iVar6 = iVar5;
          }
          iVar5 = iVar6;
          if (iVar6 <= (int)__n) {
            return 0;
          }
        }
        goto LAB_0006c888;
      }
    }
    puVar2 = PTR_obj_objs_0006c90c;
    iVar6 = 0;
    iVar5 = 0x359;
    do {
      iVar8 = iVar6 + iVar5 >> 1;
      iVar7 = *(int *)(puVar2 + iVar8 * 4);
      puVar4 = (undefined *)(__n - *(int *)(&DAT_0013fb4c + iVar7 * 0x18));
      if (puVar4 == (undefined *)0x0) {
        puVar4 = (undefined *)memcmp(o->data,*(void **)(&DAT_0013fb50 + iVar7 * 0x18),__n);
        if (-1 < (int)puVar4) {
          puVar1 = puVar2 + iVar8 * 4;
          if (puVar4 != (undefined *)0x0) goto LAB_0006c8c6;
          break;
        }
      }
      else if (-1 < (int)puVar4) {
LAB_0006c8c6:
        iVar6 = iVar8 + 1;
        iVar8 = iVar5;
      }
      iVar5 = iVar8;
      puVar1 = puVar4;
    } while (iVar6 < iVar8);
    if (puVar1 != (undefined *)0x0) {
LAB_0006c888:
      return *(int *)(&DAT_0013fb48 + iVar7 * 0x18);
    }
  }
  return 0;
}

