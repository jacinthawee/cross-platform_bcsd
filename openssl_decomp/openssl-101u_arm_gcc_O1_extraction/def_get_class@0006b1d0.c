
undefined4 * def_get_class(undefined4 param_1)

{
  undefined4 *ptr;
  _STACK *p_Var1;
  undefined4 local_1c [3];
  
  if (ex_data == (_LHASH *)0x0) {
    CRYPTO_lock(9,2,"ex_data.c",0x116);
    if ((ex_data == (_LHASH *)0x0) &&
       (ex_data = lh_new(ex_class_item_LHASH_HASH + 1,ex_class_item_LHASH_COMP + 1),
       ex_data == (_LHASH *)0x0)) {
      CRYPTO_lock(10,2,"ex_data.c",0x119);
      return (undefined4 *)0x0;
    }
    CRYPTO_lock(10,2,"ex_data.c",0x119);
  }
  local_1c[0] = param_1;
  CRYPTO_lock(9,2,"ex_data.c",0x13e);
  ptr = (undefined4 *)lh_retrieve(ex_data,local_1c);
  if (ptr == (undefined4 *)0x0) {
    ptr = (undefined4 *)CRYPTO_malloc(0xc,"ex_data.c",0x141);
    if (ptr != (undefined4 *)0x0) {
      *ptr = param_1;
      ptr[2] = 0;
      p_Var1 = sk_new_null();
      ptr[1] = p_Var1;
      if (p_Var1 != (_STACK *)0x0) {
        lh_insert(ex_data,ptr);
        goto LAB_0006b210;
      }
      CRYPTO_free(ptr);
    }
    CRYPTO_lock(10,2,"ex_data.c",0x152);
    ERR_put_error(0xf,0x69,0x41,"ex_data.c",0x154);
    ptr = (undefined4 *)0x0;
  }
  else {
LAB_0006b210:
    CRYPTO_lock(10,2,"ex_data.c",0x152);
  }
  return ptr;
}

