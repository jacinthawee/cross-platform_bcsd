
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * default_realloc_ex(void *__ptr,size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)realloc_func)();
  return pvVar1;
}

