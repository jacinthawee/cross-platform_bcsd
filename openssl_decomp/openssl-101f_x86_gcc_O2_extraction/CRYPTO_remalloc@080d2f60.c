
void * CRYPTO_remalloc(void *addr,int num,char *file,int line)

{
  undefined *puVar1;
  
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
    puVar1 = (undefined *)0x0;
  }
  else {
    allow_customize = 0;
    if (malloc_debug_func != (code *)0x0) {
      allow_customize_debug = 0;
      (*malloc_debug_func)(0,num,"mem.c",0x195,0);
    }
    puVar1 = (undefined *)(*(code *)malloc_ex_func)(num,"mem.c",0x195);
    if (malloc_debug_func != (code *)0x0) {
      (*malloc_debug_func)(puVar1,num,"mem.c",0x195,1);
    }
    if ((puVar1 == (undefined *)0x0) || (num < 0x801)) {
      return puVar1;
    }
    *puVar1 = cleanse_ctr;
  }
  return puVar1;
}

