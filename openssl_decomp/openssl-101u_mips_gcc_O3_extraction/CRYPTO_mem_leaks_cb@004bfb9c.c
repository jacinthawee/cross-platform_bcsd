
void CRYPTO_mem_leaks_cb(undefined1 *cb)

{
  undefined1 *local_res0 [4];
  
  if (mh != 0) {
    local_res0[0] = cb;
    CRYPTO_lock(9,0x1b,"mem_dbg.c",0x33a);
    (*(code *)PTR_lh_doall_arg_006a83a0)(mh,cb_leak_LHASH_DOALL_ARG,local_res0);
    CRYPTO_lock(10,0x1b,"mem_dbg.c",0x33d);
  }
  return;
}

