
undefined4 __regparm1
TS_CONF_set_crypto_device(char *param_1_00,CONF *param_1,char *param_2,char *param_3)

{
  ENGINE *e;
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  byte bVar5;
  
  bVar5 = 0;
  bVar4 = param_3 == (char *)0x0;
  if (bVar4) {
    param_1_00 = NCONF_get_string(param_1,param_2,"crypto_device");
    bVar4 = param_1_00 == (char *)0x0;
    param_3 = param_1_00;
    if (bVar4) {
      return 1;
    }
  }
  iVar1 = 8;
  pcVar2 = param_3;
  pcVar3 = "builtin";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + (uint)bVar5 * -2 + 1;
    pcVar3 = pcVar3 + (uint)bVar5 * -2 + 1;
  } while (bVar4);
  if (bVar4) {
    return 1;
  }
  e = ENGINE_by_id(param_1_00);
  bVar4 = e == (ENGINE *)0x0;
  if (bVar4) {
    ERR_put_error(0x2f,0x92,0x7f,"ts_conf.c",0xe6);
    ERR_add_error_data(2,"engine:",param_3);
  }
  else {
    iVar1 = 5;
    pcVar2 = param_3;
    pcVar3 = "chil";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + (uint)bVar5 * -2 + 1;
      pcVar3 = pcVar3 + (uint)bVar5 * -2 + 1;
    } while (bVar4);
    if (bVar4) {
      ENGINE_ctrl(e,100,1,(void *)0x0,(f *)0x0);
    }
    iVar1 = ENGINE_set_default(e,0xffff);
    if (iVar1 != 0) {
      ENGINE_free(e);
      return 1;
    }
    ERR_put_error(0x2f,0x92,0x7f,"ts_conf.c",0xe6);
    ERR_add_error_data(2,"engine:",param_3);
    ENGINE_free(e);
  }
  __fprintf_chk(stderr,1,"invalid variable value for %s::%s\n",param_2,"crypto_device");
  return 0;
}

