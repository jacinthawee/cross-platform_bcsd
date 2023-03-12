
DSO * DSO_new_method(DSO_METHOD *method)

{
  DSO *dso;
  stack_st_void *psVar1;
  int iVar2;
  DSO_METHOD *pDVar3;
  _func_3770 *p_Var4;
  
  if (default_DSO_meth == (DSO_METHOD *)0x0) {
    default_DSO_meth = DSO_METHOD_openssl();
  }
  dso = (DSO *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x28,"dso_lib.c",0x67);
  if (dso == (DSO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x25,0x71,0x41,"dso_lib.c",0x6a);
    dso = (DSO *)0x0;
  }
  else {
    (*(code *)PTR_memset_006aab00)(dso,0,0x28);
    psVar1 = (stack_st_void *)(*(code *)PTR_sk_new_null_006a80a4)();
    dso->meth_data = psVar1;
    if (psVar1 == (stack_st_void *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x25,0x71,0x41,"dso_lib.c",0x72);
      (*(code *)PTR_CRYPTO_free_006a7f88)(dso);
      dso = (DSO *)0x0;
    }
    else {
      pDVar3 = default_DSO_meth;
      if (method != (DSO_METHOD *)0x0) {
        pDVar3 = method;
      }
      p_Var4 = pDVar3->init;
      dso->meth = pDVar3;
      dso->references = 1;
      if ((p_Var4 != (_func_3770 *)0x0) && (iVar2 = (*p_Var4)(dso), iVar2 == 0)) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
        dso = (DSO *)0x0;
      }
    }
  }
  return dso;
}

