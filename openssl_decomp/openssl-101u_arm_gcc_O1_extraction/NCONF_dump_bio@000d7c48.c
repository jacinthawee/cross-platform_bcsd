
int NCONF_dump_bio(CONF *conf,BIO *out)

{
  int iVar1;
  
  if (conf != (CONF *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000d7c5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*conf->meth->dump)(conf,out);
    return iVar1;
  }
  ERR_put_error(0xe,0x69,0x69,"conf_lib.c",0x172);
  return 0;
}
