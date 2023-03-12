
void sid_free(void *ptr)

{
  if (free_debug_func != (code *)0x0) {
    (*free_debug_func)(ptr,0);
  }
  (*(code *)free_func)(ptr);
  if (free_debug_func != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0006a17a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*free_debug_func)(0,1);
    return;
  }
  return;
}
