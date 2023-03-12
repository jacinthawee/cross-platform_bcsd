
void CRYPTO_mem_leaks_cb(undefined1 *cb)

{
  undefined1 **arg;
  
  if (mh != (_LHASH *)0x0) {
    CRYPTO_lock((int)mh,9,(char *)0x1b,(int)"mem_dbg.c");
    arg = &cb;
    lh_doall_arg(mh,cb_leak_LHASH_DOALL_ARG,arg);
    CRYPTO_lock((int)arg,10,(char *)0x1b,(int)"mem_dbg.c");
  }
  return;
}

