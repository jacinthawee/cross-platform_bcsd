
int RAND_bytes(uchar *buf,int num)

{
  int iVar1;
  ENGINE *e;
  
  e = funct_ref;
  if (default_RAND_meth == (RAND_METHOD *)0x0) {
    e = ENGINE_get_default_RAND();
    if (e != (ENGINE *)0x0) {
      default_RAND_meth = ENGINE_get_RAND(e);
      if (default_RAND_meth != (RAND_METHOD *)0x0) goto LAB_08120d54;
      ENGINE_finish((ENGINE *)0x0);
    }
    default_RAND_meth = RAND_SSLeay();
    e = funct_ref;
    if (default_RAND_meth == (RAND_METHOD *)0x0) {
      return -1;
    }
  }
LAB_08120d54:
  funct_ref = e;
  if (default_RAND_meth->bytes == (_func_3804 *)0x0) {
    return -1;
  }
                    /* WARNING: Could not recover jumptable at 0x08120d66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*default_RAND_meth->bytes)(buf,num);
  return iVar1;
}
