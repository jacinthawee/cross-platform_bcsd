
int NCONF_dump_fp(CONF *conf,FILE *out)

{
  BIO *bp;
  
  bp = BIO_new_fp(out,0);
  if (bp != (BIO *)0x0) {
    if (conf == (CONF *)0x0) {
      ERR_put_error(0xe,0x69,0x69,"conf_lib.c",0x172);
    }
    else {
      conf = (CONF *)(*conf->meth->dump)(conf,bp);
    }
    BIO_free(bp);
    return (int)conf;
  }
  ERR_put_error(0xe,0x6a,7,"conf_lib.c",0x166);
  return 0;
}

