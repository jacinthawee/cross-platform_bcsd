
ENGINE * __regparm1 setup_engine(char *param_1_00,BIO *param_1,char *param_2,ENGINE *param_3)

{
  ENGINE *e;
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  
  bVar4 = param_2 == (char *)0x0;
  if (!bVar4) {
    iVar2 = 5;
    pcVar1 = param_2;
    pcVar3 = "auto";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar4 = *pcVar1 == *pcVar3;
      pcVar1 = pcVar1 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      BIO_printf(param_1,"enabling auto ENGINE support\n");
      ENGINE_register_all_complete();
      return (ENGINE *)0x0;
    }
    e = ENGINE_by_id(param_1_00);
    if (e != (ENGINE *)0x0) {
LAB_0807b3c1:
      if (param_3 != (ENGINE *)0x0) {
        param_3 = (ENGINE *)ENGINE_ctrl(e,1,0,param_1,(f *)0x0);
      }
      ENGINE_ctrl_cmd(param_3,(char *)e,(long)"SET_USER_INTERFACE",(void *)0x0,ui_method,0);
      iVar2 = ENGINE_set_default(e,0xffff);
      if (iVar2 != 0) {
        pcVar1 = ENGINE_get_id(e);
        BIO_printf(param_1,"engine \"%s\" set.\n",pcVar1);
        ENGINE_free(e);
        return e;
      }
      BIO_printf(param_1,"can\'t use that engine\n");
      ERR_print_errors(param_1);
      ENGINE_free(e);
      return (ENGINE *)0x0;
    }
    e = ENGINE_by_id((char *)0x0);
    if (e != (ENGINE *)0x0) {
      iVar2 = ENGINE_ctrl_cmd_string(e,"SO_PATH",param_2,0);
      if ((iVar2 != 0) && (iVar2 = ENGINE_ctrl_cmd_string(e,"LOAD",(char *)0x0,0), iVar2 != 0))
      goto LAB_0807b3c1;
      ENGINE_free(e);
    }
    BIO_printf(param_1,"invalid engine \"%s\"\n",param_2);
    ERR_print_errors(param_1);
  }
  return (ENGINE *)0x0;
}

