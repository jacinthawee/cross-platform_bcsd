
int OBJ_NAME_remove(char *name,int type)

{
  int *ptr;
  int iVar1;
  void *pvVar2;
  int in_GS_OFFSET;
  uint local_20 [2];
  char *local_18;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (names_lh != (_LHASH *)0x0) {
    local_18 = name;
    local_20[0] = type & 0xffff7fff;
    ptr = (int *)lh_delete(names_lh,local_20);
    if (ptr != (int *)0x0) {
      if (name_funcs_stack != (_STACK *)0x0) {
        iVar1 = sk_num(name_funcs_stack);
        if (*ptr < iVar1) {
          pvVar2 = sk_value(name_funcs_stack,*ptr);
          (**(code **)((int)pvVar2 + 8))(ptr[2],*ptr,ptr[3]);
        }
      }
      CRYPTO_free(ptr);
      iVar1 = 1;
      goto LAB_080d3a41;
    }
  }
  iVar1 = 0;
LAB_080d3a41:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

