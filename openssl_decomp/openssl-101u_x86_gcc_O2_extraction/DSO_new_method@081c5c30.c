
DSO * DSO_new_method(DSO_METHOD *method)

{
  _func_3770 *p_Var1;
  DSO *dso;
  _STACK *p_Var2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  byte bVar6;
  
  bVar6 = 0;
  if (default_DSO_meth == (DSO_METHOD *)0x0) {
    default_DSO_meth = DSO_METHOD_openssl();
  }
  dso = (DSO *)CRYPTO_malloc(0x28,"dso_lib.c",0x6a);
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x71,0x41,"dso_lib.c",0x6c);
  }
  else {
    dso->meth = (DSO_METHOD *)0x0;
    dso->loaded_filename = (char *)0x0;
    puVar5 = (undefined4 *)((uint)&dso->meth_data & 0xfffffffc);
    uVar4 = (uint)((int)dso + (0x28 - (int)puVar5)) >> 2;
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar5 = 0;
      puVar5 = puVar5 + (uint)bVar6 * -2 + 1;
    }
    p_Var2 = sk_new_null();
    dso->meth_data = (stack_st_void *)p_Var2;
    if (p_Var2 == (_STACK *)0x0) {
      ERR_put_error(0x25,0x71,0x41,"dso_lib.c",0x73);
      CRYPTO_free(dso);
      dso = (DSO *)0x0;
    }
    else {
      if (method == (DSO_METHOD *)0x0) {
        method = default_DSO_meth;
      }
      dso->references = 1;
      p_Var1 = method->init;
      dso->meth = method;
      if (p_Var1 != (_func_3770 *)0x0) {
        iVar3 = (*p_Var1)(dso);
        if (iVar3 == 0) {
          CRYPTO_free(dso);
          dso = (DSO *)0x0;
        }
      }
    }
  }
  return dso;
}

