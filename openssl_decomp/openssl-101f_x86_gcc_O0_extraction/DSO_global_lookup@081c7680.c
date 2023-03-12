
void * DSO_global_lookup(char *name)

{
  void *pvVar1;
  DSO_METHOD *pDVar2;
  
  pDVar2 = default_DSO_meth;
  if (default_DSO_meth == (DSO_METHOD *)0x0) {
    pDVar2 = DSO_METHOD_openssl();
  }
  if (pDVar2->globallookup != (_func_3773 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x081c76a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pvVar1 = (*pDVar2->globallookup)(name);
    return pvVar1;
  }
  ERR_put_error(0x25,0x8b,0x6c,"dso_lib.c",0x1df);
  return (void *)0x0;
}

