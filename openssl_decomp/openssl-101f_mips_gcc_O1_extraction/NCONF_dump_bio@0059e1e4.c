
int NCONF_dump_bio(CONF *conf,BIO *out)

{
  int iVar1;
  
  if (conf != (CONF *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0059e1f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*conf->meth->dump)(conf,out);
    return iVar1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x69,0x69,"conf_lib.c",0x180);
  return 0;
}
