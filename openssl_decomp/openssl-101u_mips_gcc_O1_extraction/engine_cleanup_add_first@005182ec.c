
void engine_cleanup_add_first(undefined4 param_1)

{
  _STACK *sk;
  undefined4 *data;
  
  if ((cleanup_stack == (_STACK *)0x0) &&
     (cleanup_stack = sk_new_null(), cleanup_stack == (_STACK *)0x0)) {
    return;
  }
  data = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(4,"eng_lib.c",0xa8);
  sk = cleanup_stack;
  if (data == (undefined4 *)0x0) {
    return;
  }
  *data = param_1;
  sk_insert(sk,data,0);
  return;
}

