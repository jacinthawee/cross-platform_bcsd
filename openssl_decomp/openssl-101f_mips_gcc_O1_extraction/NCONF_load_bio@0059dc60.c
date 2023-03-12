
int NCONF_load_bio(CONF *conf,BIO *bp,long *eline)

{
  int iVar1;
  
  if (conf != (CONF *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0059dc70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*conf->meth->load_bio)(conf,bp,eline);
    return iVar1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x6e,0x69,"conf_lib.c",0x128);
  return 0;
}

