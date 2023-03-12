
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ERR_get_next_error_library(void)

{
  int iVar1;
  
  if (err_fns != (undefined1 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00531070. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(err_fns + 0x28))();
    return iVar1;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
  if (err_fns == (undefined1 *)0x0) {
    err_fns = err_defaults;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x12a);
                    /* WARNING: Could not recover jumptable at 0x005310d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(err_fns + 0x28))();
  return iVar1;
}

