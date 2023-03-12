
undefined4 TS_CONF_set_crypto_device(CONF *param_1,char *param_2,char *param_3)

{
  int iVar1;
  ENGINE *e;
  
  if (((param_3 == (char *)0x0) &&
      (param_3 = NCONF_get_string(param_1,param_2,"crypto_device"), param_3 == (char *)0x0)) ||
     (iVar1 = strcmp(param_3,"builtin"), iVar1 == 0)) {
    return 1;
  }
  e = ENGINE_by_id(param_3);
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x2f,0x92,0x7f,"ts_conf.c",0xe6);
    ERR_add_error_data(2,"engine:",param_3);
  }
  else {
    iVar1 = strcmp(param_3,"chil");
    if (iVar1 == 0) {
      ENGINE_ctrl(e,100,1,(void *)0x0,(f *)0x0);
    }
    iVar1 = ENGINE_set_default(e,0xffff);
    if (iVar1 == 0) {
      ERR_put_error(0x2f,0x92,0x7f,"ts_conf.c",0xe6);
      ERR_add_error_data(2,"engine:",param_3);
    }
    else {
      iVar1 = 1;
    }
    ENGINE_free(e);
    if (iVar1 != 0) {
      return 1;
    }
  }
  __fprintf_chk(stderr,1,"invalid variable value for %s::%s\n",param_2,"crypto_device");
  return 0;
}

