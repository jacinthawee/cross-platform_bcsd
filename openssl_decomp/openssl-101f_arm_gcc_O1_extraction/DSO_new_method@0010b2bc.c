
DSO * DSO_new_method(DSO_METHOD *method)

{
  DSO *dso;
  DSO *pDVar1;
  int iVar2;
  _func_3770 *p_Var3;
  
  if (default_DSO_meth == (DSO_METHOD *)0x0) {
    default_DSO_meth = DSO_METHOD_openssl();
  }
  dso = (DSO *)CRYPTO_malloc(0x28,"dso_lib.c",0x67);
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x71,0x41,"dso_lib.c",0x6a);
  }
  else {
    memset(dso,0,0x28);
    pDVar1 = (DSO *)sk_new_null();
    dso->meth_data = (stack_st_void *)pDVar1;
    if (pDVar1 == (DSO *)0x0) {
      ERR_put_error(0x25,0x71,0x41,"dso_lib.c",0x72);
      CRYPTO_free(dso);
      dso = pDVar1;
    }
    else {
      if (method == (DSO_METHOD *)0x0) {
        method = default_DSO_meth;
      }
      p_Var3 = method->init;
      dso->meth = method;
      dso->references = 1;
      if ((p_Var3 != (_func_3770 *)0x0) && (iVar2 = (*p_Var3)(dso), iVar2 == 0)) {
        CRYPTO_free(dso);
        return (DSO *)0x0;
      }
    }
  }
  return dso;
}

