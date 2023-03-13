
int NCONF_load_fp(CONF *conf,FILE *fp,long *eline)

{
  BIO *bp;
  
  bp = (BIO *)(*(code *)PTR_BIO_new_fp_006a7248)(fp,0);
  if (bp != (BIO *)0x0) {
    if (conf == (CONF *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x6e,0x69,"conf_lib.c",0x11e);
    }
    else {
      conf = (CONF *)(*conf->meth->load_bio)(conf,bp,eline);
    }
    (*(code *)PTR_BIO_free_006a6e70)(bp);
    return (int)conf;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x72,7,"conf_lib.c",0x112);
  return 0;
}

