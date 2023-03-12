
void * CRYPTO_realloc(void *addr,int num,char *file,int line)

{
  void *pvVar1;
  
  if (addr == (void *)0x0) {
    if (0 < num) {
      allow_customize = addr;
      if (malloc_debug_func != (code *)0x0) {
        allow_customize_debug = addr;
        (*malloc_debug_func)();
      }
      addr = (void *)(*malloc_ex_func)(num,file,line);
      if (malloc_debug_func == (code *)0x0) {
        return addr;
      }
      (*malloc_debug_func)(addr,num,file,line,1);
    }
  }
  else if (num < 1) {
    addr = (void *)0x0;
  }
  else {
    if (realloc_debug_func != (code *)0x0) {
      (*realloc_debug_func)(addr,0,num,file,line,0);
    }
    pvVar1 = (void *)(*realloc_ex_func)(addr,num,file,line);
    if (realloc_debug_func == (code *)0x0) {
      return pvVar1;
    }
    (*realloc_debug_func)(addr,pvVar1,num,file,line,1);
    addr = pvVar1;
  }
  return addr;
}

