
undefined4 b64_free(int param_1)

{
  if (param_1 != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    return 1;
  }
  return 0;
}
