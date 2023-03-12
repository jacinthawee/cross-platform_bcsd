
char * NCONF_get_string(CONF *conf,char *group,char *name)

{
  CONF *pCVar1;
  
  pCVar1 = (CONF *)_CONF_get_string(conf,group,name);
  if (pCVar1 == (CONF *)0x0) {
    if (conf != (CONF *)0x0) {
      ERR_put_error(0xe,0x6d,0x6c,"conf_lib.c",0x14f);
      ERR_add_error_data(4,"group=",group," name=",name);
      return (char *)0x0;
    }
    ERR_put_error(0xe,0x6d,0x6a,"conf_lib.c",0x14b);
    pCVar1 = conf;
  }
  return (char *)pCVar1;
}

