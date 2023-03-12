
char * BUF_strndup(char *str,size_t siz)

{
  char *__dest;
  
  __dest = str;
  if (str != (char *)0x0) {
    if (siz < 0x7fffffff) {
      __dest = (char *)CRYPTO_malloc(siz + 1,"buf_str.c",0x51);
      if (__dest == (char *)0x0) {
        ERR_put_error(7,0x68,0x41,"buf_str.c",0x53);
      }
      else {
        memcpy(__dest,str,siz);
        __dest[siz] = '\0';
      }
    }
    else {
      __dest = (char *)0x0;
    }
  }
  return __dest;
}

