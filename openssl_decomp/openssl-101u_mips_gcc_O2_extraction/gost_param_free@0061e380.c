
void gost_param_free(void)

{
  if (gost_params != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    gost_params = 0;
  }
  return;
}

