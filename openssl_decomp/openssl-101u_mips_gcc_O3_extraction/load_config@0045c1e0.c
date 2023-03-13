
undefined4 load_config(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if ((load_config_called_16976 == 0) &&
     ((load_config_called_16976 = 1, param_2 != 0 ||
      (param_2 = *(int *)PTR_config_006a6e68, param_2 != 0)))) {
    (*(code *)PTR_OPENSSL_load_builtin_modules_006a7be0)();
    iVar1 = (*(code *)PTR_CONF_modules_load_006a7be4)(param_2,0,0);
    if (iVar1 < 1) {
      (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Error configuring OpenSSL\n");
      (*(code *)PTR_ERR_print_errors_006a6e40)(param_1);
      return 0;
    }
  }
  return 1;
}

