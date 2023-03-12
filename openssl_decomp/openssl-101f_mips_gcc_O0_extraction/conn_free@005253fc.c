
undefined4 conn_free(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x10) == 0) {
    return 1;
  }
  iVar1 = *(int *)(param_1 + 0x1c);
  piVar2 = *(int **)(param_1 + 0x20);
  if (iVar1 == -1) {
    if (piVar2 == (int *)0x0) goto LAB_005254b0;
    iVar1 = piVar2[1];
  }
  else {
    if (*piVar2 == 6) {
      (*(code *)PTR_shutdown_006aaa6c)(iVar1,2);
      iVar1 = *(int *)(param_1 + 0x1c);
    }
    (*(code *)PTR_close_006aaa5c)(iVar1);
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
    iVar1 = piVar2[1];
  }
  if (iVar1 != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  if (piVar2[2] != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  (*(code *)PTR_CRYPTO_free_006a7f88)(piVar2);
LAB_005254b0:
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return 1;
}

