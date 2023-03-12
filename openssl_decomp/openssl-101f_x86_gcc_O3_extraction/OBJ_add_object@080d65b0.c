
int OBJ_add_object(ASN1_OBJECT *obj)

{
  int *data;
  ASN1_OBJECT *ptr;
  void *ptr_00;
  int iVar1;
  int **ppiVar2;
  int in_GS_OFFSET;
  int *local_20;
  void *local_1c;
  void *local_18;
  void *local_14;
  int *local_10;
  
  local_10 = *(int **)(in_GS_OFFSET + 0x14);
  local_20 = (int *)0x0;
  local_1c = (void *)0x0;
  local_18 = (void *)0x0;
  local_14 = (void *)0x0;
  if (added == (_LHASH *)0x0) {
    added = lh_new(added_obj_LHASH_HASH,added_obj_LHASH_COMP);
    if (added == (_LHASH *)0x0) {
      iVar1 = 0;
      goto LAB_080d66e8;
    }
  }
  ptr = OBJ_dup(obj);
  if (ptr != (ASN1_OBJECT *)0x0) {
    local_14 = CRYPTO_malloc(8,"obj_dat.c",0x100);
    if (local_14 != (void *)0x0) {
      if ((ptr->length != 0) && (obj->data != (uchar *)0x0)) {
        local_20 = (int *)CRYPTO_malloc(8,"obj_dat.c",0x102);
        if (local_20 == (int *)0x0) goto LAB_080d6700;
      }
      if (ptr->sn != (char *)0x0) {
        local_1c = CRYPTO_malloc(8,"obj_dat.c",0x104);
        if (local_1c == (void *)0x0) goto LAB_080d6700;
      }
      if (ptr->ln != (char **)0x0) {
        local_18 = CRYPTO_malloc(8,"obj_dat.c",0x106);
        if (local_18 == (void *)0x0) goto LAB_080d6700;
      }
      iVar1 = 0;
      do {
        data = (&local_20)[iVar1];
        if (data != (int *)0x0) {
          *data = iVar1;
          data[1] = (int)ptr;
          ptr_00 = lh_insert(added,data);
          if (ptr_00 != (void *)0x0) {
            CRYPTO_free(ptr_00);
          }
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 != 4);
      ptr->flags = ptr->flags & 0xfffffff2;
      iVar1 = ptr->nid;
      goto LAB_080d66e8;
    }
LAB_080d6700:
    ERR_put_error(8,0x69,0x41,"obj_dat.c",0x119);
  }
  ppiVar2 = &local_20;
  do {
    if (*ppiVar2 != (int *)0x0) {
      CRYPTO_free(*ppiVar2);
    }
    ppiVar2 = ppiVar2 + 1;
  } while (&local_10 != ppiVar2);
  if (ptr != (ASN1_OBJECT *)0x0) {
    CRYPTO_free(ptr);
  }
  iVar1 = 0;
LAB_080d66e8:
  if (local_10 == *(int **)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

