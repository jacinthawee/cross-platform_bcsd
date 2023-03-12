
int NCONF_load_fp(CONF *conf,FILE *fp,long *eline)

{
  BIO *bp;
  
  bp = (BIO *)(*(code *)PTR_BIO_new_fp_006a835c)(fp,0);
  if (bp != (BIO *)0x0) {
    if (conf == (CONF *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x6e,0x69,"conf_lib.c",0x128);
    }
    else {
      conf = (CONF *)(*conf->meth->load_bio)(conf,bp,eline);
    }
    (*(code *)PTR_BIO_free_006a7f70)(bp);
    return (int)conf;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x72,7,"conf_lib.c",0x11b);
  return 0;
}

