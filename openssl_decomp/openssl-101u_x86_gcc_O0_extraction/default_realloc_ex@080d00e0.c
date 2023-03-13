
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * default_realloc_ex(void *__ptr,size_t __size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x080d00e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)realloc_func)();
  return pvVar1;
}

