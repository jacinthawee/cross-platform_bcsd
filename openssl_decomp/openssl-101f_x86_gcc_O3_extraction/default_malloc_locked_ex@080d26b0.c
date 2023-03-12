
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * default_malloc_locked_ex(size_t __size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x080d26b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)malloc_locked_func)();
  return pvVar1;
}

