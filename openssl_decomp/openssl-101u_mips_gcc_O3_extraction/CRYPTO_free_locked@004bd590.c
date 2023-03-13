
void CRYPTO_free_locked(void *ptr)

{
  if (free_debug_func != (code *)0x0) {
    (*free_debug_func)(ptr,0);
  }
  (*(code *)free_locked_func)(ptr);
  if (free_debug_func != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004bd5e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*free_debug_func)(0,1);
    return;
  }
  return;
}

