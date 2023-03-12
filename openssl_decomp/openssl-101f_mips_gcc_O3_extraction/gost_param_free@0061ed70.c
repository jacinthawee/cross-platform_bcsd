
void gost_param_free(void)

{
  if (gost_params != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    gost_params = 0;
  }
  return;
}

