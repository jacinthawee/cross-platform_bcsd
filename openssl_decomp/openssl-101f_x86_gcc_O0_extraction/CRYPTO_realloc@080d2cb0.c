
void * CRYPTO_realloc(void *addr,int num,char *file,int line)

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
      if (puVar2 == (undefined *)0x0) {
        return (void *)0x0;
      }
      if (num < 0x801) {
        return puVar2;
      }
      *puVar2 = cleanse_ctr;
      return puVar2;
    }
  }
  else if (0 < num) {
    if (realloc_debug_func != (code *)0x0) {
      (*realloc_debug_func)(addr,0,num,file,line,0);
    }
    pvVar1 = (void *)(*(code *)realloc_ex_func)(addr,num,file,line);
    if (realloc_debug_func == (code *)0x0) {
      return pvVar1;
    }
    (*realloc_debug_func)(addr,pvVar1,num,file,line,1);
    return pvVar1;
  }
  return (void *)0x0;
}

