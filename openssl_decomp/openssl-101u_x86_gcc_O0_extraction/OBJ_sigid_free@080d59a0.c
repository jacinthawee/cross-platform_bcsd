
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void OBJ_sigid_free(void)

{
  if (sig_app != (_STACK *)0x0) {
    sk_pop_free(sig_app,sid_free);
    sig_app = (_STACK *)0x0;
  }
  if (sigx_app != (_STACK *)0x0) {
    sk_free(sigx_app);
    sigx_app = (_STACK *)0x0;
  }
  return;
}

