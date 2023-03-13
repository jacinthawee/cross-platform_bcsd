
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DSO * DSO_new(void)

{
  _func_3770 *p_Var1;
  DSO_METHOD *pDVar2;
  DSO *dso;
  _STACK *p_Var3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  byte bVar7;
  
  bVar7 = 0;
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
    puVar6 = (undefined4 *)((uint)&dso->meth_data & 0xfffffffc);
    uVar5 = (uint)((int)dso + (0x28 - (int)puVar6)) >> 2;
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + (uint)bVar7 * -2 + 1;
    }
    p_Var3 = sk_new_null();
    dso->meth_data = (stack_st_void *)p_Var3;
    pDVar2 = default_DSO_meth;
    if (p_Var3 == (_STACK *)0x0) {
      ERR_put_error(0x25,0x71,0x41,"dso_lib.c",0x73);
      CRYPTO_free(dso);
      dso = (DSO *)0x0;
    }
    else {
      dso->references = 1;
      dso->meth = pDVar2;
      p_Var1 = pDVar2->init;
      if (p_Var1 != (_func_3770 *)0x0) {
        iVar4 = (*p_Var1)(dso);
        if (iVar4 == 0) {
          CRYPTO_free(dso);
          dso = (DSO *)0x0;
        }
      }
    }
  }
  return dso;
}

