
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int RAND_status(void)

{
  int iVar1;
  ENGINE *e;
  
  e = funct_ref;
  if (default_RAND_meth == (RAND_METHOD *)0x0) {
    e = ENGINE_get_default_RAND();
    if (e != (ENGINE *)0x0) {
      default_RAND_meth = ENGINE_get_RAND(e);
      if (default_RAND_meth != (RAND_METHOD *)0x0) goto LAB_0812372d;
      ENGINE_finish((ENGINE *)0x0);
    }
    default_RAND_meth = RAND_SSLeay();
    e = funct_ref;
    if (default_RAND_meth == (RAND_METHOD *)0x0) {
      return 0;
    }
  }
LAB_0812372d:
  funct_ref = e;
  if (default_RAND_meth->status == (_func_3808 *)0x0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x08123738. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*default_RAND_meth->status)();
  return iVar1;
}
