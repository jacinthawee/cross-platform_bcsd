
lhash_st_CONF_VALUE * CONF_load_fp(lhash_st_CONF_VALUE *conf,FILE *fp,long *eline)

{
  BIO *bp;
  BIO *pBVar1;
  CONF local_24;
  
  bp = BIO_new_fp(fp,0);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xe,0x67,7,"conf_lib.c",0x78);
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    (*default_CONF_method->init)(&local_24);
    local_24.data = conf;
    pBVar1 = (BIO *)(*(local_24.meth)->load_bio)(&local_24,bp,eline);
    if (pBVar1 != (BIO *)0x0) {
      pBVar1 = (BIO *)local_24.data;
    }
    BIO_free(bp);
    bp = pBVar1;
  }
  return (lhash_st_CONF_VALUE *)bp;
}

