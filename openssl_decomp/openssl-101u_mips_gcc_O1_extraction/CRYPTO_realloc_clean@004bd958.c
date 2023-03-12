
void * CRYPTO_realloc_clean(void *addr,int old_num,int num,char *file,int line)

{
  void *pvVar1;
  
  if (addr == (void *)0x0) {
    pvVar1 = CRYPTO_malloc(num,file,line);
    return pvVar1;
  }
  if ((0 < num) && (old_num <= num)) {
    if (realloc_debug_func != (code *)0x0) {
      (*realloc_debug_func)(addr,0,num,file,line,0);
    }
    pvVar1 = (void *)(*(code *)malloc_ex_func)(num,file,line);
    if (pvVar1 != (void *)0x0) {
      (*(code *)PTR_memcpy_006a9aec)(pvVar1,addr,old_num);
      OPENSSL_cleanse(addr,old_num);
      (*(code *)free_func)(addr);
    }
    if (realloc_debug_func != (code *)0x0) {
      (*realloc_debug_func)(addr,pvVar1,num,file,line,1);
      return pvVar1;
    }
    return pvVar1;
  }
  return (void *)0x0;
}

