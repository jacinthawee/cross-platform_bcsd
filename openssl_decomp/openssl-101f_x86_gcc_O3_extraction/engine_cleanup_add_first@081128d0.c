
void engine_cleanup_add_first(undefined4 param_1)

{
  undefined4 *data;
  
  if (((cleanup_stack != (_STACK *)0x0) ||
      (cleanup_stack = sk_new_null(), cleanup_stack != (_STACK *)0x0)) &&
     (data = (undefined4 *)CRYPTO_malloc(4,"eng_lib.c",0xa2), data != (undefined4 *)0x0)) {
    *data = param_1;
    sk_insert(cleanup_stack,data,0);
  }
  return;
}

