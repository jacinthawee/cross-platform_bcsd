
EVP_PKEY_CTX * EVP_PKEY_CTX_dup(EVP_PKEY_CTX *ctx)

{
  code *pcVar1;
  int iVar2;
  int *ptr;
  
  if ((*(int *)ctx != 0) && (*(int *)(*(int *)ctx + 0xc) != 0)) {
    if ((*(ENGINE **)(ctx + 4) != (ENGINE *)0x0) &&
       (iVar2 = ENGINE_init(*(ENGINE **)(ctx + 4)), iVar2 == 0)) {
      ERR_put_error(6,0x9c,0x26,"pmeth_lib.c",0x13c);
      return (EVP_PKEY_CTX *)0x0;
    }
    ptr = (int *)CRYPTO_malloc(0x28,"pmeth_lib.c",0x140);
    if (ptr != (int *)0x0) {
      *ptr = *(int *)ctx;
      ptr[1] = *(int *)(ctx + 4);
      iVar2 = *(int *)(ctx + 8);
      if (iVar2 != 0) {
        CRYPTO_add_lock((int *)(iVar2 + 8),1,10,"pmeth_lib.c",0x14a);
        iVar2 = *(int *)(ctx + 8);
      }
      ptr[2] = iVar2;
      iVar2 = *(int *)(ctx + 0xc);
      if (iVar2 != 0) {
        CRYPTO_add_lock((int *)(iVar2 + 8),1,10,"pmeth_lib.c",0x14f);
        iVar2 = *(int *)(ctx + 0xc);
      }
      ptr[3] = iVar2;
      iVar2 = *(int *)(ctx + 0x10);
      ptr[5] = 0;
      ptr[6] = 0;
      ptr[4] = iVar2;
      iVar2 = (**(code **)(*(int *)ctx + 0xc))(ptr,ctx);
      if (0 < iVar2) {
        return (EVP_PKEY_CTX *)ptr;
      }
      if ((*ptr != 0) && (pcVar1 = *(code **)(*ptr + 0x10), pcVar1 != (code *)0x0)) {
        (*pcVar1)(ptr);
      }
      if ((EVP_PKEY *)ptr[2] != (EVP_PKEY *)0x0) {
        EVP_PKEY_free((EVP_PKEY *)ptr[2]);
      }
      if ((EVP_PKEY *)ptr[3] != (EVP_PKEY *)0x0) {
        EVP_PKEY_free((EVP_PKEY *)ptr[3]);
      }
      if ((ENGINE *)ptr[1] != (ENGINE *)0x0) {
        ENGINE_finish((ENGINE *)ptr[1]);
      }
      CRYPTO_free(ptr);
    }
  }
  return (EVP_PKEY_CTX *)0x0;
}

