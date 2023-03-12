
EVP_PKEY_CTX * EVP_PKEY_CTX_dup(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  
  if ((*(int *)ctx == 0) || (*(int *)(*(int *)ctx + 0xc) == 0)) {
    return (EVP_PKEY_CTX *)0x0;
  }
  if ((*(int *)(ctx + 4) == 0) || (iVar1 = (*(code *)PTR_ENGINE_init_006a8e68)(), iVar1 != 0)) {
    piVar2 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x28,"pmeth_lib.c",0x140);
    if (piVar2 != (int *)0x0) {
      iVar1 = *(int *)(ctx + 4);
      iVar3 = *(int *)(ctx + 8);
      *piVar2 = *(int *)ctx;
      piVar2[1] = iVar1;
      if (iVar3 != 0) {
        (*(code *)PTR_CRYPTO_add_lock_006a9080)(iVar3 + 8,1,10,"pmeth_lib.c",0x14a);
        iVar3 = *(int *)(ctx + 8);
      }
      iVar1 = *(int *)(ctx + 0xc);
      piVar2[2] = iVar3;
      if (iVar1 != 0) {
        (*(code *)PTR_CRYPTO_add_lock_006a9080)(iVar1 + 8,1,10,"pmeth_lib.c",0x14f);
        iVar1 = *(int *)(ctx + 0xc);
      }
      iVar3 = *(int *)ctx;
      iVar4 = *(int *)(ctx + 0x10);
      piVar2[3] = iVar1;
      piVar2[5] = 0;
      piVar2[6] = 0;
      piVar2[4] = iVar4;
      iVar1 = (**(code **)(iVar3 + 0xc))(piVar2,ctx);
      if (0 < iVar1) {
        return (EVP_PKEY_CTX *)piVar2;
      }
      if ((*piVar2 != 0) && (pcVar5 = *(code **)(*piVar2 + 0x10), pcVar5 != (code *)0x0)) {
        (*pcVar5)(piVar2);
      }
      if ((EVP_PKEY *)piVar2[2] != (EVP_PKEY *)0x0) {
        EVP_PKEY_free((EVP_PKEY *)piVar2[2]);
      }
      if ((EVP_PKEY *)piVar2[3] != (EVP_PKEY *)0x0) {
        EVP_PKEY_free((EVP_PKEY *)piVar2[3]);
      }
      if (piVar2[1] != 0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(piVar2);
      return (EVP_PKEY_CTX *)0x0;
    }
  }
  else {
    ERR_put_error(6,0x9c,0x26,"pmeth_lib.c",0x13c);
  }
  return (EVP_PKEY_CTX *)0x0;
}

