
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

lhash_st_ERR_STATE * ERR_get_err_state_table(void)

{
  undefined1 *mode;
  lhash_st_ERR_STATE *plVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  if (err_fns != (undefined1 *)0x0) {
    plVar1 = (lhash_st_ERR_STATE *)(**(code **)(err_fns + 0x14))(0);
    return plVar1;
  }
  CRYPTO_lock(0,9,(char *)0x1,(int)"err.c");
  mode = err_fns;
  if (err_fns == (undefined1 *)0x0) {
    err_fns = err_defaults;
  }
  uVar4 = 0x12a;
  pcVar3 = "err.c";
  uVar2 = 1;
  CRYPTO_lock((int)mode,10,(char *)0x1,(int)"err.c");
  plVar1 = (lhash_st_ERR_STATE *)(**(code **)(err_fns + 0x14))(0,uVar2,pcVar3,uVar4);
  return plVar1;
}

