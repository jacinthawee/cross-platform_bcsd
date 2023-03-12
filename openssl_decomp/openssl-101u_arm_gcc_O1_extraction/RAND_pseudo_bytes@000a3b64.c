
int RAND_pseudo_bytes(uchar *buf,int num)

{
  int iVar1;
  ENGINE *e;
  
  e = funct_ref;
  if (default_RAND_meth == (RAND_METHOD *)0x0) {
    e = ENGINE_get_default_RAND();
    if (e != (ENGINE *)0x0) {
      default_RAND_meth = ENGINE_get_RAND(e);
      if (default_RAND_meth != (RAND_METHOD *)0x0) goto LAB_000a3b76;
      ENGINE_finish(e);
    }
    default_RAND_meth = RAND_SSLeay();
    e = funct_ref;
    if (default_RAND_meth == (RAND_METHOD *)0x0) {
      return -1;
    }
  }
LAB_000a3b76:
  funct_ref = e;
  if (default_RAND_meth->pseudorand == (_func_3807 *)0x0) {
    return -1;
  }
                    /* WARNING: Could not recover jumptable at 0x000a3b82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*default_RAND_meth->pseudorand)(buf,num);
  return iVar1;
}

