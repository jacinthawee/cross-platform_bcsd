
void RAND_seed(void *buf,int num)

{
  ENGINE *e;
  
  e = funct_ref;
  if (default_RAND_meth == (RAND_METHOD *)0x0) {
    e = ENGINE_get_default_RAND();
    if (e != (ENGINE *)0x0) {
      default_RAND_meth = ENGINE_get_RAND(e);
      if (default_RAND_meth != (RAND_METHOD *)0x0) goto LAB_08120c14;
      ENGINE_finish((ENGINE *)0x0);
    }
    default_RAND_meth = RAND_SSLeay();
    e = funct_ref;
    if (default_RAND_meth == (RAND_METHOD *)0x0) {
      return;
    }
  }
LAB_08120c14:
  funct_ref = e;
  if (default_RAND_meth->seed == (_func_3803 *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x08120c25. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*default_RAND_meth->seed)(buf,num);
  return;
}

