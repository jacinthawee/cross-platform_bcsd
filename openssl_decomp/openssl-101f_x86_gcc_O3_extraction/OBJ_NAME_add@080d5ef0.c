
int OBJ_NAME_add(char *name,int type,char *data)

{
  uint *data_00;
  int *ptr;
  int iVar1;
  void *pvVar2;
  
  if (names_lh == (_LHASH *)0x0) {
    CRYPTO_mem_ctrl(3);
    names_lh = lh_new(obj_name_LHASH_HASH,obj_name_LHASH_COMP);
    CRYPTO_mem_ctrl(2);
    if (names_lh == (_LHASH *)0x0) {
      return 0;
    }
  }
  data_00 = (uint *)CRYPTO_malloc(0x10,"o_names.c",0xc3);
  if (data_00 == (uint *)0x0) {
    return 0;
  }
  *data_00 = type & 0xffff7fff;
  data_00[1] = type & 0x8000;
  data_00[2] = (uint)name;
  data_00[3] = (uint)data;
  ptr = (int *)lh_insert(names_lh,data_00);
  if (ptr == (int *)0x0) {
    return (uint)(names_lh->error == 0);
  }
  if (name_funcs_stack != (_STACK *)0x0) {
    iVar1 = sk_num(name_funcs_stack);
    if (*ptr < iVar1) {
      pvVar2 = sk_value(name_funcs_stack,*ptr);
      (**(code **)((int)pvVar2 + 8))(ptr[2],*ptr,ptr[3]);
    }
  }
  CRYPTO_free(ptr);
  return 1;
}

