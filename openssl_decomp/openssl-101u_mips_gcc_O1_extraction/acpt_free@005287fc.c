
undefined4 acpt_free(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x10) == 0) {
    return 1;
  }
  iVar1 = *(int *)(param_1 + 0x20);
  if (*(int *)(iVar1 + 8) != -1) {
    (*(code *)PTR_shutdown_006a995c)(*(int *)(iVar1 + 8),2);
    (*(code *)PTR_close_006a994c)(*(undefined4 *)(iVar1 + 8));
    *(undefined4 *)(iVar1 + 8) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  }
  if (*(int *)(iVar1 + 4) != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  if (*(int *)(iVar1 + 0x10) != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  if (*(BIO **)(iVar1 + 0x1c) != (BIO *)0x0) {
    BIO_free(*(BIO **)(iVar1 + 0x1c));
  }
  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar1);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return 1;
}

