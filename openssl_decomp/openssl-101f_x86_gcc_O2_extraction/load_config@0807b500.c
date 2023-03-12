
undefined4 load_config(BIO *param_1,CONF *param_2)

{
  int iVar1;
  
  if ((load_config_called_16993 == 0) &&
     ((load_config_called_16993 = 1, param_2 != (CONF *)0x0 ||
      (param_2 = config, config != (CONF *)0x0)))) {
    OPENSSL_load_builtin_modules();
    iVar1 = CONF_modules_load(param_2,(char *)0x0,0);
    if (iVar1 < 1) {
      BIO_printf(param_1,"Error configuring OpenSSL\n");
      ERR_print_errors(param_1);
      return 0;
    }
  }
  return 1;
}

