
undefined4 file_free(int param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      if (*(int *)(param_1 + 0x20) != 0) {
        (*(code *)PTR_fclose_006a9998)();
        *(undefined4 *)(param_1 + 0x20) = 0;
        *(undefined4 *)(param_1 + 0x14) = 0;
      }
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    return 1;
  }
  return 1;
}

