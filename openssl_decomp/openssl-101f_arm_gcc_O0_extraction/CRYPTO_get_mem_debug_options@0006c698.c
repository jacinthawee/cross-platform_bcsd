
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long CRYPTO_get_mem_debug_options(void)

{
  long lVar1;
  
  if (get_debug_options_func != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0006c6a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    lVar1 = (*get_debug_options_func)();
    return lVar1;
  }
  return 0;
}

