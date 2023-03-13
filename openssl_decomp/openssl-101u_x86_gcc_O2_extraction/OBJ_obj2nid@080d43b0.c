
int OBJ_obj2nid(ASN1_OBJECT *o)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  size_t __n;
  int iVar6;
  int in_GS_OFFSET;
  undefined4 local_28;
  ASN1_OBJECT *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (o != (ASN1_OBJECT *)0x0) {
    iVar4 = o->nid;
    if (iVar4 != 0) goto LAB_080d4409;
    __n = o->length;
    if (__n != 0) {
      if (added != (_LHASH *)0x0) {
        local_28 = 0;
        local_24 = o;
        pvVar1 = lh_retrieve(added,&local_28);
        if (pvVar1 != (void *)0x0) {
          iVar4 = *(int *)(*(int *)((int)pvVar1 + 4) + 8);
          goto LAB_080d4409;
        }
        __n = o->length;
        iVar4 = 0;
        iVar3 = 0x359;
        if (__n == 0) {
          do {
            iVar6 = iVar4 + iVar3 >> 1;
            iVar5 = *(int *)(obj_objs + iVar6 * 4);
            if (*(int *)(nid_objs + iVar5 * 0x18 + 0xc) == 0) goto LAB_080d44c9;
            if (*(int *)(nid_objs + iVar5 * 0x18 + 0xc) < 1) {
              iVar4 = iVar6 + 1;
              iVar6 = iVar3;
            }
            iVar3 = iVar6;
          } while (iVar4 < iVar6);
          goto LAB_080d4428;
        }
      }
      iVar4 = 0;
      iVar3 = 0x359;
      do {
        iVar6 = iVar3 + iVar4 >> 1;
        iVar5 = *(int *)(obj_objs + iVar6 * 4);
        if (__n == *(size_t *)(nid_objs + iVar5 * 0x18 + 0xc)) {
          iVar2 = memcmp(o->data,*(void **)(nid_objs + iVar5 * 0x18 + 0x10),__n);
          if (-1 < iVar2) {
            if (iVar2 == 0) goto LAB_080d44c9;
LAB_080d4478:
            iVar4 = iVar6 + 1;
            iVar6 = iVar3;
          }
        }
        else if (-1 < (int)(__n - *(size_t *)(nid_objs + iVar5 * 0x18 + 0xc))) goto LAB_080d4478;
        iVar3 = iVar6;
      } while (iVar4 < iVar6);
    }
  }
LAB_080d4428:
  iVar4 = 0;
LAB_080d4409:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
LAB_080d44c9:
  iVar4 = *(int *)(nid_objs + iVar5 * 0x18 + 8);
  goto LAB_080d4409;
}

