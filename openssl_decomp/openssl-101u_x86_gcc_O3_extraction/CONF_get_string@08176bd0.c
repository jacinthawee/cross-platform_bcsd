
char * CONF_get_string(lhash_st_CONF_VALUE *conf,char *group,char *name)

{
  char *pcVar1;
  int in_GS_OFFSET;
  CONF local_2c;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (conf == (lhash_st_CONF_VALUE *)0x0) {
    pcVar1 = _CONF_get_string((CONF *)0x0,group,name);
    if (pcVar1 == (char *)0x0) {
      ERR_put_error(0xe,0x6d,0x6a,"conf_lib.c",0x141);
    }
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    (*default_CONF_method->init)(&local_2c);
    local_2c.data = conf;
    pcVar1 = _CONF_get_string(&local_2c,group,name);
    if (pcVar1 == (char *)0x0) {
      ERR_put_error(0xe,0x6d,0x6c,"conf_lib.c",0x144);
      ERR_add_error_data(4,"group=",group," name=",name);
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pcVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

