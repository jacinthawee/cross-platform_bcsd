
int UI_add_input_string(UI *ui,char *prompt,int flags,char *result_buf,int minsize,int maxsize)

{
  int *ptr;
  _STACK *st;
  int iVar1;
  
  if (prompt == (char *)0x0) {
    ERR_put_error(0x28,0x6d,0x43,"ui_lib.c",0x93);
    return -1;
  }
  if (result_buf != (char *)0x0) {
    ptr = (int *)CRYPTO_malloc(0x20,"ui_lib.c",0x9a);
    if (ptr == (int *)0x0) {
      return -1;
    }
    ptr[1] = (int)prompt;
    ptr[3] = (int)result_buf;
    st = *(_STACK **)(ui + 4);
    ptr[2] = flags;
    ptr[7] = 0;
    *ptr = 1;
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
    ptr[4] = minsize;
    ptr[5] = maxsize;
    ptr[6] = 0;
    iVar1 = sk_push(st,ptr);
    if (iVar1 < 1) {
      iVar1 = iVar1 + -1;
    }
    return iVar1;
  }
  ERR_put_error(0x28,0x6d,0x69,"ui_lib.c",0x98);
  return -1;
}

