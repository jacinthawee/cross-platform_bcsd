
void * CRYPTO_malloc_locked(int num,char *file,int line)

{
  undefined *puVar1;
  
  if (0 < num) {
    if (allow_customize != 0) {
      allow_customize = 0;
    }
    if (malloc_debug_func != (code *)0x0) {
      if (allow_customize_debug != 0) {
        allow_customize_debug = 0;
      }
      (*malloc_debug_func)(0,num,file,line,0);
    }
    puVar1 = (undefined *)(*(code *)malloc_locked_ex_func)(num,file,line);
    if (malloc_debug_func != (code *)0x0) {
      (*malloc_debug_func)(puVar1,num,file,line,1);
    }
    if (puVar1 == (undefined *)0x0) {
      puVar1 = (undefined *)0x0;
    }
    else if (0x800 < num) {
      *puVar1 = *PTR_cleanse_ctr_006a847c;
    }
    return puVar1;
  }
  return (void *)0x0;
}

