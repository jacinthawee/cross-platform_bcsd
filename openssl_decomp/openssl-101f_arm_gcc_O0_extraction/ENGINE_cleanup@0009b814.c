
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_cleanup(void)

{
  if (cleanup_stack != (_STACK *)0x0) {
    sk_pop_free(cleanup_stack,engine_cleanup_cb_free + 1);
    cleanup_stack = (_STACK *)0x0;
  }
  RAND_set_rand_method((RAND_METHOD *)0x0);
  return;
}

