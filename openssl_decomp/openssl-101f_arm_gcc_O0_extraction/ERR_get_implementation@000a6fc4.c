
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ERR_FNS * ERR_get_implementation(void)

{
  if (err_fns != (ERR_FNS *)0x0) {
    return err_fns;
  }
  CRYPTO_lock(9,1,"err.c",0x127);
  if (err_fns == (ERR_FNS *)0x0) {
    err_fns = (ERR_FNS *)&err_defaults;
  }
  CRYPTO_lock(10,1,"err.c",0x12a);
  return err_fns;
}

