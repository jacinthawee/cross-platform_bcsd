
undefined4 def_destroy(CONF *param_1)

{
  if (param_1 != (CONF *)0x0) {
    _CONF_free_data(param_1);
    (*(code *)PTR_CRYPTO_free_006a7f88)(param_1);
    return 1;
  }
  return 0;
}

