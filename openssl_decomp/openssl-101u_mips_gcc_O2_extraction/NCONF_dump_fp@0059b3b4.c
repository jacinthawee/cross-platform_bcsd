
int NCONF_dump_fp(CONF *conf,FILE *out)

{
  BIO *bp;
  
  bp = (BIO *)(*(code *)PTR_BIO_new_fp_006a7248)(out,0);
  if (bp != (BIO *)0x0) {
    if (conf == (CONF *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x69,0x69,"conf_lib.c",0x172);
    }
    else {
      conf = (CONF *)(*conf->meth->dump)(conf,bp);
    }
    (*(code *)PTR_BIO_free_006a6e70)(bp);
    return (int)conf;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x6a,7,"conf_lib.c",0x166);
  return 0;
}

