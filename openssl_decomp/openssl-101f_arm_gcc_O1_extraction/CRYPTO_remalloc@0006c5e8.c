
void * CRYPTO_remalloc(void *addr,int num,char *file,int line)

{
  void *pvVar1;
  
  if (addr != (void *)0x0) {
    if (free_debug_func != (code *)0x0) {
      (*free_debug_func)(addr,0);
    }
    (*(code *)free_func)(addr);
    if (free_debug_func != (code *)0x0) {
      (*free_debug_func)(0,1);
    }
  }
  if (num < 1) {
    pvVar1 = (void *)0x0;
  }
  else {
    allow_customize = 0;
    if (malloc_debug_func != (code *)0x0) {
      allow_customize_debug = 0;
      (*malloc_debug_func)(0,num,"mem.c",0x195,0);
    }
    pvVar1 = (void *)(*malloc_ex_func)(num,"mem.c",0x195);
    if (malloc_debug_func != (code *)0x0) {
      (*malloc_debug_func)(pvVar1,num,"mem.c",0x195,1);
    }
  }
  return pvVar1;
}

