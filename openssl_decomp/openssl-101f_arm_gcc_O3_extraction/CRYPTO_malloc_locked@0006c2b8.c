
void * CRYPTO_malloc_locked(int num,char *file,int line)

{
  void *pvVar1;
  
  if (num < 1) {
    pvVar1 = (void *)0x0;
  }
  else {
    allow_customize = 0;
    if (malloc_debug_func != (code *)0x0) {
      allow_customize_debug = 0;
      (*malloc_debug_func)(0,num,file,line,0);
    }
    pvVar1 = (void *)(*malloc_locked_ex_func)(num,file,line);
    if (malloc_debug_func != (code *)0x0) {
      (*malloc_debug_func)(pvVar1,num,file,line,1);
    }
  }
  return pvVar1;
}

