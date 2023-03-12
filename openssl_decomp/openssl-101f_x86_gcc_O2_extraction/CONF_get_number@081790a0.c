
long CONF_get_number(lhash_st_CONF_VALUE *conf,char *group,char *name)

{
  int iVar1;
  char *pcVar2;
  int in_GS_OFFSET;
  long local_30;
  CONF local_2c;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_30 = 0;
  if (conf == (lhash_st_CONF_VALUE *)0x0) {
    pcVar2 = _CONF_get_string((CONF *)0x0,group,name);
    if (pcVar2 != (char *)0x0) {
      do {
        invalidInstructionException();
      } while( true );
    }
    ERR_put_error(0xe,0x6d,0x6a,"conf_lib.c",0x14b);
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    (*default_CONF_method->init)(&local_2c);
    local_2c.data = conf;
    iVar1 = NCONF_get_number_e(&local_2c,group,name,&local_30);
    if (iVar1 != 0) goto LAB_081790fb;
  }
  ERR_clear_error();
LAB_081790fb:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_30;
}

