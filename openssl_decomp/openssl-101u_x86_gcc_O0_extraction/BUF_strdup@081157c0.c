
char * BUF_strdup(char *str)

{
  size_t __n;
  char *__dest;
  char *pcVar1;
  
  if (str == (char *)0x0) {
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = (char *)0x0;
    __n = strlen(str);
    if (__n < 0x7fffffff) {
      __dest = (char *)CRYPTO_malloc(__n + 1,"buf_str.c",0x51);
      if (__dest == (char *)0x0) {
        ERR_put_error(7,0x68,0x41,"buf_str.c",0x53);
      }
      else {
        memcpy(__dest,str,__n);
        __dest[__n] = '\0';
        pcVar1 = __dest;
      }
    }
  }
  return pcVar1;
}

