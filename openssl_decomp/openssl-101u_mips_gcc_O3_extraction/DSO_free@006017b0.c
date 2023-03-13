
int DSO_free(DSO *dso)

{
  int iVar1;
  DSO_METHOD *pDVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int local_14;
  
  if (dso == (DSO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x6f,0x43,"dso_lib.c",0x88);
    return 0;
  }
  iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a805c)(&dso->references,0xffffffff,0x1c,"dso_lib.c",0x8c)
  ;
  if (0 < iVar1) {
    return 1;
  }
  pDVar2 = dso->meth;
  if (pDVar2->dso_unload != (_func_3766 *)0x0) {
    local_14 = (*pDVar2->dso_unload)(dso);
    if (local_14 == 0) {
      uVar4 = 0x6b;
      uVar3 = 0x9a;
      goto LAB_00601910;
    }
    pDVar2 = dso->meth;
  }
  if ((pDVar2->finish == (_func_3771 *)0x0) || (local_14 = (*pDVar2->finish)(dso), local_14 != 0)) {
    (*(code *)PTR_sk_free_006a6e80)(dso->meth_data);
    if (dso->filename != (char *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (dso->loaded_filename != (char *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(dso);
    return 1;
  }
  uVar4 = 0x66;
  uVar3 = 0x9f;
LAB_00601910:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x6f,uVar4,"dso_lib.c",uVar3);
  return local_14;
}

