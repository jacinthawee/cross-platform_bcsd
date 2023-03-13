
_STACK * __regparm3 def_get_class(int param_1)

{
  _LHASH *mode;
  _STACK *p_Var1;
  _STACK *ptr;
  int in_GS_OFFSET;
  int local_1c [3];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  mode = (_LHASH *)0x0;
  if (ex_data == (_LHASH *)0x0) {
    CRYPTO_lock(0,9,(char *)0x2,(int)"ex_data.c");
    if (ex_data == (_LHASH *)0x0) {
      mode = lh_new(ex_class_item_LHASH_HASH,ex_class_item_LHASH_COMP);
      ex_data = mode;
      if (mode == (_LHASH *)0x0) {
        CRYPTO_lock(0,10,(char *)0x2,(int)"ex_data.c");
        ptr = (_STACK *)0x0;
        goto LAB_080d2366;
      }
    }
    CRYPTO_lock((int)mode,10,(char *)0x2,(int)"ex_data.c");
  }
  local_1c[0] = param_1;
  CRYPTO_lock((int)mode,9,(char *)0x2,(int)"ex_data.c");
  p_Var1 = (_STACK *)lh_retrieve(ex_data,local_1c);
  ptr = p_Var1;
  if (p_Var1 == (_STACK *)0x0) {
    ptr = (_STACK *)CRYPTO_malloc(0xc,"ex_data.c",0x141);
    p_Var1 = ptr;
    if (ptr != (_STACK *)0x0) {
      ptr->num = param_1;
      ptr->sorted = 0;
      p_Var1 = sk_new_null();
      ptr->data = (char **)p_Var1;
      if (p_Var1 != (_STACK *)0x0) {
        p_Var1 = (_STACK *)lh_insert(ex_data,ptr);
        goto LAB_080d234e;
      }
      CRYPTO_free(ptr);
    }
    CRYPTO_lock((int)p_Var1,10,(char *)0x2,(int)"ex_data.c");
    ERR_put_error(0xf,0x69,0x41,"ex_data.c",0x154);
    ptr = (_STACK *)0x0;
  }
  else {
LAB_080d234e:
    CRYPTO_lock((int)p_Var1,10,(char *)0x2,(int)"ex_data.c");
  }
LAB_080d2366:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return ptr;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

