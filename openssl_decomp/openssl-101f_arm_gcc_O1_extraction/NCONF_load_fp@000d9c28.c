
int NCONF_load_fp(CONF *conf,FILE *fp,long *eline)

{
  BIO *bp;
  
  bp = BIO_new_fp(fp,0);
  if (bp != (BIO *)0x0) {
    if (conf == (CONF *)0x0) {
      ERR_put_error(0xe,0x6e,0x69,"conf_lib.c",0x128);
    }
    else {
      conf = (CONF *)(*conf->meth->load_bio)(conf,bp,eline);
    }
    BIO_free(bp);
    return (int)conf;
  }
  ERR_put_error(0xe,0x72,7,"conf_lib.c",0x11b);
  return 0;
}

