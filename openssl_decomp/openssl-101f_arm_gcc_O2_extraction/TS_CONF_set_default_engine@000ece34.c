
ENGINE * TS_CONF_set_default_engine(char *param_1)

{
  int iVar1;
  ENGINE *e;
  ENGINE *pEVar2;
  
  iVar1 = strcmp(param_1,"builtin");
  if (iVar1 == 0) {
    e = (ENGINE *)0x1;
  }
  else {
    e = ENGINE_by_id(param_1);
    if (e != (ENGINE *)0x0) {
      iVar1 = strcmp(param_1,"chil");
      if (iVar1 == 0) {
        ENGINE_ctrl(e,100,1,(void *)0x0,(f *)0x0);
      }
      pEVar2 = (ENGINE *)ENGINE_set_default(e,0xffff);
      if (pEVar2 == (ENGINE *)0x0) {
        ERR_put_error(0x2f,0x92,0x7f,"ts_conf.c",0xe6);
        ERR_add_error_data(2,"engine:",param_1);
      }
      else {
        pEVar2 = (ENGINE *)0x1;
      }
      ENGINE_free(e);
      return pEVar2;
    }
    ERR_put_error(0x2f,0x92,0x7f,"ts_conf.c",0xe6);
    ERR_add_error_data(2,"engine:",param_1);
  }
  return e;
}

