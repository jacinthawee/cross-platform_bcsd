
void CRYPTO_set_mem_debug_options(long bits)

{
  if (set_debug_options_func != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0006c694. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*set_debug_options_func)();
    return;
  }
  return;
}

