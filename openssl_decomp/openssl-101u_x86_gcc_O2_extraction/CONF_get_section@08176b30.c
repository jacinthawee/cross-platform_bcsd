
stack_st_CONF_VALUE * CONF_get_section(lhash_st_CONF_VALUE *conf,char *section)

{
  stack_st_CONF_VALUE *psVar1;
  int in_GS_OFFSET;
  CONF local_1c;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (conf == (lhash_st_CONF_VALUE *)0x0) {
    psVar1 = (stack_st_CONF_VALUE *)0x0;
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    (*default_CONF_method->init)(&local_1c);
    local_1c.data = conf;
    if (section == (char *)0x0) {
      ERR_put_error(0xe,0x6c,0x6b,"conf_lib.c",0x12d);
      psVar1 = (stack_st_CONF_VALUE *)0x0;
    }
    else {
      psVar1 = _CONF_get_section_values(&local_1c,section);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return psVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

