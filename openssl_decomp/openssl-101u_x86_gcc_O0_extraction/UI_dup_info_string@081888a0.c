
int UI_dup_info_string(UI *ui,char *text)

{
  char *pcVar1;
  int *ptr;
  int iVar2;
  _STACK *st;
  
  if (text == (char *)0x0) {
    ERR_put_error(0x28,0x6d,0x43,"ui_lib.c",0x8f);
  }
  else {
    pcVar1 = BUF_strdup(text);
    if (pcVar1 == (char *)0x0) {
      ERR_put_error(0x28,0x66,0x41,"ui_lib.c",0x16d);
      return -1;
    }
    ptr = (int *)CRYPTO_malloc(0x20,"ui_lib.c",0x93);
    if (ptr != (int *)0x0) {
      ptr[1] = (int)pcVar1;
      ptr[3] = 0;
      st = *(_STACK **)(ui + 4);
      ptr[7] = 1;
      ptr[2] = 0;
      *ptr = 4;
      if (st == (_STACK *)0x0) {
        st = sk_new_null();
        *(_STACK **)(ui + 4) = st;
        if (st == (_STACK *)0x0) {
          if (((*(byte *)(ptr + 7) & 1) != 0) && (CRYPTO_free((void *)ptr[1]), *ptr == 3)) {
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
      iVar2 = sk_push(st,ptr);
      if (0 < iVar2) {
        return iVar2;
      }
      return iVar2 + -1;
    }
  }
  return -1;
}

