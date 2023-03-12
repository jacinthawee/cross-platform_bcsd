
void engine_cleanup_cb_free(code **param_1)

{
  (**param_1)();
                    /* WARNING: Could not recover jumptable at 0x00519f04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a7f88)(param_1);
  return;
}

