
int RAND_pseudo_bytes(uchar *buf,int num)

{
  int iVar1;
  ENGINE *e;
  
  e = funct_ref;
  if (default_RAND_meth == (RAND_METHOD *)0x0) {
    e = ENGINE_get_default_RAND();
    if (e != (ENGINE *)0x0) {
      default_RAND_meth = ENGINE_get_RAND(e);
      if (default_RAND_meth != (RAND_METHOD *)0x0) goto LAB_0052d30c;
      ENGINE_finish(e);
    }
    default_RAND_meth = (RAND_METHOD *)(*(code *)PTR_RAND_SSLeay_006a891c)();
    e = funct_ref;
    if (default_RAND_meth == (RAND_METHOD *)0x0) {
      return -1;
    }
  }
LAB_0052d30c:
  funct_ref = e;
  if (default_RAND_meth->pseudorand == (_func_3807 *)0x0) {
    return -1;
  }
                    /* WARNING: Could not recover jumptable at 0x0052d328. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*default_RAND_meth->pseudorand)(buf,num);
  return iVar1;
}

