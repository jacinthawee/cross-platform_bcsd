
void dynamic_data_ctx_free_func(undefined4 param_1,int *param_2)

{
  if (param_2 != (int *)0x0) {
    if (*param_2 != 0) {
      (*(code *)PTR_DSO_free_006a8874)();
    }
    if (param_2[3] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (param_2[5] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if ((_STACK *)param_2[10] != (_STACK *)0x0) {
      sk_pop_free((_STACK *)param_2[10],int_free_str);
    }
                    /* WARNING: Could not recover jumptable at 0x0051d1f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(param_2);
    return;
  }
  return;
}

