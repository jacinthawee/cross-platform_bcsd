
int __regparm1 ERR_set_implementation(ERR_FNS *fns)

{
  bool bVar1;
  int in_stack_00000004;
  
  CRYPTO_lock((int)fns,9,(char *)0x1,(int)"err.c");
  bVar1 = err_fns == 0;
  if (bVar1) {
    err_fns = in_stack_00000004;
  }
  CRYPTO_lock(err_fns,10,(char *)0x1,(int)"err.c");
  return (uint)bVar1;
}

