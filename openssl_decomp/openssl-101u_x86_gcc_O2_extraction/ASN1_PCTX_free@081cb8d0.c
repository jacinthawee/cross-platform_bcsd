
void ASN1_PCTX_free(void *ptr)

{
  if (free_debug_func != (code *)0x0) {
    (*free_debug_func)(ptr,0);
  }
  (*(code *)free_func)(ptr);
  if (free_debug_func != (code *)0x0) {
    (*free_debug_func)(0,1);
  }
  return;
}

