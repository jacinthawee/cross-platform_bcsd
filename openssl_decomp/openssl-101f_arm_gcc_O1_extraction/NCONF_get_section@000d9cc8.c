
stack_st_CONF_VALUE * NCONF_get_section(CONF *conf,char *section)

{
  stack_st_CONF_VALUE *psVar1;
  
  if (conf == (CONF *)0x0) {
    ERR_put_error(0xe,0x6c,0x69,"conf_lib.c",0x133);
  }
  else {
    if (section != (char *)0x0) {
      psVar1 = _CONF_get_section_values(conf,section);
      return psVar1;
    }
    ERR_put_error(0xe,0x6c,0x6b,"conf_lib.c",0x139);
  }
  return (stack_st_CONF_VALUE *)0x0;
}

