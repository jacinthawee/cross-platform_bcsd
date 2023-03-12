
int DSO_free(DSO *dso)

{
  int iVar1;
  DSO_METHOD *pDVar2;
  
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x6f,0x43,"dso_lib.c",0x89);
    return 0;
  }
  iVar1 = CRYPTO_add_lock(&dso->references,-1,0x1c,"dso_lib.c",0x8d);
  if (0 < iVar1) {
    return 1;
  }
  pDVar2 = dso->meth;
  if (pDVar2->dso_unload != (_func_3766 *)0x0) {
    iVar1 = (*pDVar2->dso_unload)(dso);
    if (iVar1 == 0) {
      ERR_put_error(0x25,0x6f,0x6b,"dso_lib.c",0x9c);
      return 0;
    }
    pDVar2 = dso->meth;
  }
  if ((pDVar2->finish != (_func_3771 *)0x0) && (iVar1 = (*pDVar2->finish)(dso), iVar1 == 0)) {
    ERR_put_error(0x25,0x6f,0x66,"dso_lib.c",0xa2);
    return 0;
  }
  sk_free((_STACK *)dso->meth_data);
  if (dso->filename != (char *)0x0) {
    CRYPTO_free(dso->filename);
  }
  if (dso->loaded_filename != (char *)0x0) {
    CRYPTO_free(dso->loaded_filename);
  }
  CRYPTO_free(dso);
  return 1;
}

