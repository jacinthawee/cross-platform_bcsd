
void * CRYPTO_realloc_clean(void *addr,int old_num,int num,char *file,int line)

{
  void *__dest;
  undefined *puVar1;
  
  if (addr == (void *)0x0) {
    if (0 < num) {
      allow_customize = 0;
      if (malloc_debug_func != (code *)0x0) {
        allow_customize_debug = 0;
        (*malloc_debug_func)(0,num,file,line,0);
      }
      puVar1 = (undefined *)(*(code *)malloc_ex_func)(num,file,line);
      if (malloc_debug_func != (code *)0x0) {
        (*malloc_debug_func)(puVar1,num,file,line,1);
      }
      if (puVar1 == (undefined *)0x0) {
        return (void *)0x0;
      }
      if (num < 0x801) {
        return puVar1;
      }
      *puVar1 = cleanse_ctr;
      return puVar1;
    }
  }
  else if ((old_num <= num) && (0 < num)) {
    if (realloc_debug_func != (code *)0x0) {
      (*realloc_debug_func)(addr,0,num,file,line,0);
    }
    __dest = (void *)(*(code *)malloc_ex_func)(num,file,line);
    if (__dest != (void *)0x0) {
      memcpy(__dest,addr,old_num);
      OPENSSL_cleanse(addr,old_num);
      (*(code *)free_func)(addr);
    }
    if (realloc_debug_func == (code *)0x0) {
      return __dest;
    }
    (*realloc_debug_func)(addr,__dest,num,file,line,1);
    return __dest;
  }
  return (void *)0x0;
}

