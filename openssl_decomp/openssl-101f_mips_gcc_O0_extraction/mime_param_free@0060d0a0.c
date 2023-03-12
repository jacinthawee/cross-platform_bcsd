
void mime_param_free(int *param_1)

{
  if (*param_1 != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  if (param_1[1] != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
                    /* WARNING: Could not recover jumptable at 0x0060d0fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a7f88)(param_1);
  return;
}

