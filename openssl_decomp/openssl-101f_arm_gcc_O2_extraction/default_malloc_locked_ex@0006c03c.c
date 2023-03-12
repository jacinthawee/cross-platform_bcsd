
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * default_malloc_locked_ex(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)malloc_locked_func)();
  return pvVar1;
}

