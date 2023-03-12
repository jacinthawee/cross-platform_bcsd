
ENGINE * setup_engine(BIO *param_1,char *param_2,int param_3)

{
  int iVar1;
  ENGINE *e;
  ENGINE *pEVar2;
  char *pcVar3;
  
  if (param_2 == (char *)0x0) {
    return (ENGINE *)0x0;
  }
  iVar1 = strcmp(param_2,"auto");
  if (iVar1 == 0) {
    BIO_printf(param_1,"enabling auto ENGINE support\n");
    ENGINE_register_all_complete();
    return (ENGINE *)0x0;
  }
  e = ENGINE_by_id(param_2);
  if (e == (ENGINE *)0x0) {
    e = ENGINE_by_id("dynamic");
    if (e != (ENGINE *)0x0) {
      iVar1 = ENGINE_ctrl_cmd_string(e,"SO_PATH",param_2,0);
      if ((iVar1 != 0) && (iVar1 = ENGINE_ctrl_cmd_string(e,"LOAD",(char *)0x0,0), iVar1 != 0))
      goto LAB_00033f94;
      ENGINE_free(e);
    }
    BIO_printf(param_1,"invalid engine \"%s\"\n",param_2);
    ERR_print_errors(param_1);
    pEVar2 = (ENGINE *)0x0;
  }
  else {
LAB_00033f94:
    if (param_3 != 0) {
      ENGINE_ctrl(e,1,0,param_1,(f *)0x0);
    }
    ENGINE_ctrl_cmd(e,"SET_USER_INTERFACE",0,ui_method,(f *)0x0,1);
    pEVar2 = (ENGINE *)ENGINE_set_default(e,0xffff);
    if (pEVar2 == (ENGINE *)0x0) {
      BIO_printf(param_1,"can\'t use that engine\n");
      ERR_print_errors(param_1);
      ENGINE_free(e);
    }
    else {
      pcVar3 = ENGINE_get_id(e);
      BIO_printf(param_1,"engine \"%s\" set.\n",pcVar3);
      ENGINE_free(e);
      pEVar2 = e;
    }
  }
  return pEVar2;
}

