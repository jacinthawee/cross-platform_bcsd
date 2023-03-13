
void CRYPTO_mem_leaks_fp(FILE *param_1)

{
  BIO_METHOD *type;
  BIO *bp;
  BIO *mode;
  
  if (mh != 0) {
    CRYPTO_mem_ctrl_constprop_5();
    type = BIO_s_file();
    bp = BIO_new(type);
    mode = bp;
    CRYPTO_lock((int)bp,9,&DAT_00000014,(int)"mem_dbg.c");
    if (((mh_mode & 1) != 0) && (mode = num_disable, num_disable != (BIO *)0x0)) {
      mode = (BIO *)((int)&num_disable[-1].ex_data.dummy + 3);
      num_disable = mode;
      if (mode == (BIO *)0x0) {
        mh_mode = mh_mode | 2;
        CRYPTO_lock(0,10,(char *)0x1b,(int)"mem_dbg.c");
      }
    }
    CRYPTO_lock((int)mode,10,&DAT_00000014,(int)"mem_dbg.c");
    if (bp != (BIO *)0x0) {
      BIO_ctrl(bp,0x6a,0,param_1);
      CRYPTO_mem_leaks(bp);
      BIO_free(bp);
      return;
    }
  }
  return;
}

