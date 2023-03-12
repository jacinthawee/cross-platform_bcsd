
int OBJ_obj2nid(ASN1_OBJECT *o)

{
  int iVar1;
  size_t __n;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_GS_OFFSET;
  undefined4 local_28;
  ASN1_OBJECT *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (o != (ASN1_OBJECT *)0x0) {
    iVar5 = o->nid;
    if (iVar5 != 0) goto LAB_080d6a46;
    if (added != (_LHASH *)0x0) {
      local_28 = 0;
      local_24 = o;
      pvVar2 = lh_retrieve(added,&local_28);
      if (pvVar2 != (void *)0x0) {
        iVar5 = *(int *)(*(int *)((int)pvVar2 + 4) + 8);
        goto LAB_080d6a46;
      }
    }
    __n = o->length;
    iVar5 = 0;
    iVar6 = 0x359;
    do {
      while( true ) {
        iVar4 = iVar6 + iVar5 >> 1;
        iVar1 = *(int *)(obj_objs + iVar4 * 4) * 0x18;
        if (__n == *(size_t *)(nid_objs + iVar1 + 0xc)) break;
        if (-1 < (int)(__n - *(size_t *)(nid_objs + iVar1 + 0xc))) goto LAB_080d6a98;
LAB_080d6abc:
        iVar6 = iVar4;
        if (iVar4 <= iVar5) goto LAB_080d6ac8;
      }
      iVar3 = memcmp(o->data,*(void **)(nid_objs + iVar1 + 0x10),__n);
      if (iVar3 < 0) goto LAB_080d6abc;
      if (iVar3 == 0) {
        iVar5 = *(int *)(nid_objs + iVar1 + 8);
        goto LAB_080d6a46;
      }
LAB_080d6a98:
      iVar5 = iVar4 + 1;
    } while (iVar5 < iVar6);
  }
LAB_080d6ac8:
  iVar5 = 0;
LAB_080d6a46:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}

