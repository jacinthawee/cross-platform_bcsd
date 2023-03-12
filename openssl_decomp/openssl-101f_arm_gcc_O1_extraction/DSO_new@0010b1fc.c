
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DSO * DSO_new(void)

{
  DSO_METHOD *pDVar1;
  DSO *dso;
  DSO *pDVar2;
  int iVar3;
  _func_3770 *p_Var4;
  
  if (default_DSO_meth == (DSO_METHOD *)0x0) {
    default_DSO_meth = DSO_METHOD_openssl();
  }
  dso = (DSO *)CRYPTO_malloc(0x28,"dso_lib.c",0x67);
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x71,0x41,"dso_lib.c",0x6a);
  }
  else {
    memset(dso,0,0x28);
    pDVar2 = (DSO *)sk_new_null();
    dso->meth_data = (stack_st_void *)pDVar2;
    pDVar1 = default_DSO_meth;
    if (pDVar2 == (DSO *)0x0) {
      ERR_put_error(0x25,0x71,0x41,"dso_lib.c",0x72);
      CRYPTO_free(dso);
      dso = pDVar2;
    }
    else {
      dso->references = 1;
      p_Var4 = pDVar1->init;
      dso->meth = pDVar1;
      if ((p_Var4 != (_func_3770 *)0x0) && (iVar3 = (*p_Var4)(dso), iVar3 == 0)) {
        CRYPTO_free(dso);
        return (DSO *)0x0;
      }
    }
  }
  return dso;
}

