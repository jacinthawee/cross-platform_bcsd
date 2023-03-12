
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
    if (piVar2 == (int *)0x0) goto LAB_005235b4;
    iVar1 = piVar2[1];
  }
  else {
    if (*piVar2 == 6) {
      (*(code *)PTR_shutdown_006a995c)(iVar1,2);
      iVar1 = *(int *)(param_1 + 0x1c);
    }
    (*(code *)PTR_close_006a994c)(iVar1);
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
    iVar1 = piVar2[1];
  }
  if (iVar1 != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  if (piVar2[2] != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  (*(code *)PTR_CRYPTO_free_006a6e88)(piVar2);
LAB_005235b4:
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return 1;
}

