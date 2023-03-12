
void sk_free(_STACK *param_1)

{
  if (param_1 != (_STACK *)0x0) {
    if (param_1->data != (char **)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
                    /* WARNING: Could not recover jumptable at 0x0052b414. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(param_1);
    return;
  }
  return;
}

