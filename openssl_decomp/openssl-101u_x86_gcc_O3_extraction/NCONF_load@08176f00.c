
int NCONF_load(CONF *conf,char *file,long *eline)

{
  int iVar1;
  
  if (conf != (CONF *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08176f15. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*conf->meth->load)(conf,file,eline);
    return iVar1;
  }
  ERR_put_error(0xe,0x71,0x69,"conf_lib.c",0x105);
  return 0;
}

