
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ERR_FNS * ERR_get_implementation(void)

{
  ERR_FNS *mode;
  
  if ((ERR_FNS *)err_fns != (ERR_FNS *)0x0) {
    return (ERR_FNS *)err_fns;
  }
  CRYPTO_lock(0,9,(char *)0x1,(int)"err.c");
  mode = (ERR_FNS *)err_fns;
  if ((ERR_FNS *)err_fns == (ERR_FNS *)0x0) {
    err_fns = err_defaults;
  }
  CRYPTO_lock((int)mode,10,(char *)0x1,(int)"err.c");
  return (ERR_FNS *)err_fns;
}

