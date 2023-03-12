
void engine_cleanup_cb_free(code **param_1)

{
  (**param_1)();
                    /* WARNING: Could not recover jumptable at 0x00517fe4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a6e88)(param_1);
  return;
}

