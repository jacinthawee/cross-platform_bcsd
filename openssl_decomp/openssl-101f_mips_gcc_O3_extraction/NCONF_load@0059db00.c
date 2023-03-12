
int NCONF_load(CONF *conf,char *file,long *eline)

{
  int iVar1;
  
  if (conf != (CONF *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0059db10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*conf->meth->load)(conf,file,eline);
    return iVar1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x71,0x69,"conf_lib.c",0x10d);
  return 0;
}

