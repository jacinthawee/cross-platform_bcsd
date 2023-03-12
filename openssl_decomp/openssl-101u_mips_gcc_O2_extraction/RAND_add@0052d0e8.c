
void RAND_add(void *buf,int num,double entropy)

{
  ENGINE *e;
  
  e = funct_ref;
  if (default_RAND_meth == (RAND_METHOD *)0x0) {
    e = ENGINE_get_default_RAND();
    if (e != (ENGINE *)0x0) {
      default_RAND_meth = ENGINE_get_RAND(e);
      if (default_RAND_meth != (RAND_METHOD *)0x0) goto LAB_0052d118;
      ENGINE_finish(e);
    }
    default_RAND_meth = (RAND_METHOD *)(*(code *)PTR_RAND_SSLeay_006a891c)();
    e = funct_ref;
    if (default_RAND_meth == (RAND_METHOD *)0x0) {
      return;
    }
  }
LAB_0052d118:
  funct_ref = e;
  if (default_RAND_meth->add == (_func_3806 *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0052d134. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*default_RAND_meth->add)(buf,num,entropy);
  return;
}

