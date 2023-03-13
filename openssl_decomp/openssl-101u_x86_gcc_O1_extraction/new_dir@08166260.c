
undefined4 new_dir(int param_1)

{
  BUF_MEM **ptr;
  BUF_MEM *pBVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  ptr = (BUF_MEM **)CRYPTO_malloc(8,"by_dir.c",0x97);
  if (ptr != (BUF_MEM **)0x0) {
    pBVar1 = BUF_MEM_new();
    *ptr = pBVar1;
    if (pBVar1 == (BUF_MEM *)0x0) {
      CRYPTO_free(ptr);
    }
    else {
      ptr[1] = (BUF_MEM *)0x0;
      uVar2 = 1;
      *(BUF_MEM ***)(param_1 + 0xc) = ptr;
    }
  }
  return uVar2;
}

