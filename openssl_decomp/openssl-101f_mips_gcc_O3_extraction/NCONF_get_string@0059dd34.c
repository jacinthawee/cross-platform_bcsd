
char * NCONF_get_string(CONF *conf,char *group,char *name)

{
  char *pcVar1;
  
  pcVar1 = _CONF_get_string(conf,group,name);
  if (pcVar1 == (char *)0x0) {
    if (conf != (CONF *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x6d,0x6c,"conf_lib.c",0x14f);
      (*(code *)PTR_ERR_add_error_data_006a9264)(4,"group=",group," name=",name);
      return (char *)0x0;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x6d,0x6a,"conf_lib.c",0x14b);
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}

