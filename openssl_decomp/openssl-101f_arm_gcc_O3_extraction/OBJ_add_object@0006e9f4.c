
int OBJ_add_object(ASN1_OBJECT *obj)

{
  ASN1_OBJECT *ptr;
  void *ptr_00;
  int *data;
  int iVar1;
  void **ppvVar2;
  void *pvStack_2c;
  int *local_28;
  void *local_24;
  void *local_20;
  void *local_1c [2];
  
  local_28 = (int *)0x0;
  local_24 = (void *)0x0;
  local_20 = (void *)0x0;
  local_1c[0] = (void *)0x0;
  if ((added == (_LHASH *)0x0) &&
     (added = lh_new(added_obj_LHASH_HASH + 1,added_obj_LHASH_COMP + 1), added == (_LHASH *)0x0)) {
    return 0;
  }
  ptr = OBJ_dup(obj);
  if (ptr == (ASN1_OBJECT *)0x0) goto LAB_0006ead0;
  local_1c[0] = CRYPTO_malloc(8,"obj_dat.c",0x100);
  if (local_1c[0] != (void *)0x0) {
    if ((ptr->length != 0) && (obj->data != (uchar *)0x0)) {
      local_28 = (int *)CRYPTO_malloc(8,"obj_dat.c",0x102);
      if (local_28 == (int *)0x0) goto LAB_0006eab8;
    }
    if (ptr->sn != (char *)0x0) {
      local_24 = CRYPTO_malloc(8,"obj_dat.c",0x104);
      if (local_24 == (void *)0x0) goto LAB_0006eab8;
    }
    if (ptr->ln == (char **)0x0) {
LAB_0006ea88:
      iVar1 = 0;
      do {
        data = (&local_28)[iVar1];
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
      return ptr->nid;
    }
    local_20 = CRYPTO_malloc(8,"obj_dat.c",0x106);
    if (local_20 != (void *)0x0) goto LAB_0006ea88;
  }
LAB_0006eab8:
  ERR_put_error(8,0x69,0x41,"obj_dat.c",0x119);
LAB_0006ead0:
  ppvVar2 = &pvStack_2c;
  do {
    ppvVar2 = ppvVar2 + 1;
    if (*ppvVar2 != (void *)0x0) {
      CRYPTO_free(*ppvVar2);
    }
  } while (ppvVar2 != local_1c);
  if (ptr != (ASN1_OBJECT *)0x0) {
    CRYPTO_free(ptr);
  }
  return 0;
}

