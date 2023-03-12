
int UI_dup_verify_string
              (UI *ui,char *prompt,int flags,char *result_buf,int minsize,int maxsize,char *test_buf
              )

{
  char *pcVar1;
  int *ptr;
  _STACK *st;
  int iVar2;
  
  if (prompt == (char *)0x0) {
    ERR_put_error(0x28,0x6d,0x43,"ui_lib.c",0x8f);
  }
  else {
    pcVar1 = BUF_strdup(prompt);
    if (pcVar1 == (char *)0x0) {
      ERR_put_error(0x28,0x6a,0x41,"ui_lib.c",0x115);
      return -1;
    }
    if (result_buf == (char *)0x0) {
      ERR_put_error(0x28,0x6d,0x69,"ui_lib.c",0x92);
    }
    else {
      ptr = (int *)CRYPTO_malloc(0x20,"ui_lib.c",0x93);
      if (ptr != (int *)0x0) {
        ptr[1] = (int)pcVar1;
        ptr[3] = (int)result_buf;
        st = *(_STACK **)(ui + 4);
        ptr[2] = flags;
        ptr[7] = 1;
        *ptr = 2;
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
        ptr[6] = (int)test_buf;
        iVar2 = sk_push(st,ptr);
        if (0 < iVar2) {
          return iVar2;
        }
        return iVar2 + -1;
      }
    }
  }
  return -1;
}

