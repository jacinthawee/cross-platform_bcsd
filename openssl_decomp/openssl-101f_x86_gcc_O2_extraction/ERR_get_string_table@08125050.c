
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

lhash_st_ERR_STRING_DATA * ERR_get_string_table(void)

{
  code **mode;
  lhash_st_ERR_STRING_DATA *plVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  if ((code **)err_fns != (code **)0x0) {
    plVar1 = (lhash_st_ERR_STRING_DATA *)(**(code **)err_fns)(0);
    return plVar1;
  }
  CRYPTO_lock(0,9,(char *)0x1,(int)"err.c");
  mode = (code **)err_fns;
  if ((code **)err_fns == (code **)0x0) {
    err_fns = err_defaults;
  }
  uVar4 = 0x12a;
  pcVar3 = "err.c";
  uVar2 = 1;
  CRYPTO_lock((int)mode,10,(char *)0x1,(int)"err.c");
  plVar1 = (lhash_st_ERR_STRING_DATA *)(**(code **)err_fns)(0,uVar2,pcVar3,uVar4);
  return plVar1;
}

