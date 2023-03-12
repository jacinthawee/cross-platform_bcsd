
void * CRYPTO_realloc_clean(void *addr,int old_num,int num,char *file,int line)

{
  void *pvVar1;
  undefined *puVar2;
  
  if (addr == (void *)0x0) {
    if (0 < num) {
      allow_customize = 0;
      if (malloc_debug_func != (code *)0x0) {
        allow_customize_debug = 0;
        (*malloc_debug_func)(0,num,file,line,0);
      }
      puVar2 = (undefined *)(*(code *)malloc_ex_func)(num,file,line);
      if (malloc_debug_func != (code *)0x0) {
        (*malloc_debug_func)(puVar2,num,file,line,1);
      }
      if (puVar2 != (undefined *)0x0) {
        if (num < 0x801) {
          return puVar2;
        }
        *puVar2 = *PTR_cleanse_ctr_006a959c;
        return puVar2;
      }
    }
  }
  else if ((0 < num) && (old_num <= num)) {
    if (realloc_debug_func != (code *)0x0) {
      (*realloc_debug_func)(addr,0,num,file,line,0);
    }
    pvVar1 = (void *)(*(code *)malloc_ex_func)(num,file,line);
    if (pvVar1 != (void *)0x0) {
      (*(code *)PTR_memcpy_006aabf4)(pvVar1,addr,old_num);
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

