
void def_cleanup_util_cb(void *ptr)

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
