
undefined4 buffer_new(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x20,"bf_buff.c",0x60);
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x1000,"bf_buff.c",99);
    puVar1[2] = iVar2;
    if (iVar2 == 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(puVar1);
      uVar3 = 0;
    }
    else {
      iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x1000,"bf_buff.c",0x68);
      puVar1[5] = iVar2;
      if (iVar2 == 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)(puVar1[2]);
        (*(code *)PTR_CRYPTO_free_006a6e88)(puVar1);
        uVar3 = 0;
      }
      else {
        puVar1[3] = 0;
        uVar3 = 1;
        puVar1[4] = 0;
        puVar1[6] = 0;
        *puVar1 = 0x1000;
        puVar1[1] = 0x1000;
        puVar1[7] = 0;
        *(undefined4 **)(param_1 + 0x20) = puVar1;
        *(undefined4 *)(param_1 + 0xc) = 1;
        *(undefined4 *)(param_1 + 0x14) = 0;
      }
    }
    return uVar3;
  }
  return 0;
}

