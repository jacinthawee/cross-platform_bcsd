
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DSO * DSO_new(void)

{
  DSO_METHOD *pDVar1;
  DSO *dso;
  stack_st_void *psVar2;
  int iVar3;
  _func_3770 *p_Var4;
  
  if (default_DSO_meth == (DSO_METHOD *)0x0) {
    default_DSO_meth = DSO_METHOD_openssl();
  }
  dso = (DSO *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x28,"dso_lib.c",0x6a);
  if (dso == (DSO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x71,0x41,"dso_lib.c",0x6c);
    dso = (DSO *)0x0;
  }
  else {
    (*(code *)PTR_memset_006a99f4)(dso,0,0x28);
    psVar2 = (stack_st_void *)(*(code *)PTR_sk_new_null_006a6fa4)();
    dso->meth_data = psVar2;
    pDVar1 = default_DSO_meth;
    if (psVar2 == (stack_st_void *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x71,0x41,"dso_lib.c",0x73);
      (*(code *)PTR_CRYPTO_free_006a6e88)(dso);
      dso = (DSO *)0x0;
    }
    else {
      dso->references = 1;
      dso->meth = pDVar1;
      p_Var4 = pDVar1->init;
      if ((p_Var4 != (_func_3770 *)0x0) && (iVar3 = (*p_Var4)(dso), iVar3 == 0)) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
        dso = (DSO *)0x0;
      }
    }
  }
  return dso;
}

