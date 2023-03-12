
void * CRYPTO_realloc_clean(void *addr,int old_num,int num,char *file,int line)

{
  void *__dest;
  
  if (addr == (void *)0x0) {
    __dest = addr;
    if (0 < num) {
      allow_customize = addr;
      if (malloc_debug_func != (code *)0x0) {
        allow_customize_debug = addr;
        (*malloc_debug_func)(0,num,file,line,0);
      }
      __dest = (void *)(*malloc_ex_func)(num,file,line);
      if (malloc_debug_func != (code *)0x0) {
        (*malloc_debug_func)(__dest,num,file,line,1);
      }
    }
  }
  else {
    if ((num < 1) || (num < old_num)) {
      return (void *)0x0;
    }
    if (realloc_debug_func != (code *)0x0) {
      (*realloc_debug_func)();
    }
    __dest = (void *)(*malloc_ex_func)(num,file,line);
    if (__dest != (void *)0x0) {
      memcpy(__dest,addr,old_num);
      OPENSSL_cleanse(addr,old_num);
      (*(code *)free_func)(addr);
    }
    if (realloc_debug_func != (code *)0x0) {
      (*realloc_debug_func)(addr,__dest,num,file,line,1);
    }
  }
  return __dest;
}

