
int UI_add_info_string(UI *ui,char *text)

{
  int *ptr;
  _STACK *st;
  int iVar1;
  
  if (text == (char *)0x0) {
    ERR_put_error(0x28,0x6d,0x43,"ui_lib.c",0x93);
  }
  else {
    ptr = (int *)CRYPTO_malloc(0x20,"ui_lib.c",0x9a);
    if (ptr != (int *)0x0) {
      ptr[1] = (int)text;
      ptr[3] = 0;
      st = *(_STACK **)(ui + 4);
      ptr[7] = 0;
      ptr[2] = 0;
      *ptr = 4;
      if (st == (_STACK *)0x0) {
        st = sk_new_null();
        *(_STACK **)(ui + 4) = st;
        if (st == (_STACK *)0x0) {
          if ((ptr[7] << 0x1f < 0) && (CRYPTO_free((void *)ptr[1]), *ptr == 3)) {
            CRYPTO_free((void *)ptr[4]);
            CRYPTO_free((void *)ptr[5]);
            CRYPTO_free((void *)ptr[6]);
          }
          CRYPTO_free(ptr);
          return -1;
        }
      }
      ptr[4] = 0;
      ptr[5] = 0;
      ptr[6] = 0;
      iVar1 = sk_push(st,ptr);
      if (0 < iVar1) {
        return iVar1;
      }
      return iVar1 + -1;
    }
  }
  return -1;
}
