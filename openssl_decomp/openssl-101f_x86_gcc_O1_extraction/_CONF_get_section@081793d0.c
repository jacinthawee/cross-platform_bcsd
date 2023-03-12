
CONF_VALUE * _CONF_get_section(CONF *conf,char *section)

{
  CONF_VALUE *pCVar1;
  int in_GS_OFFSET;
  char *local_1c;
  undefined4 local_18;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((conf == (CONF *)0x0) || (section == (char *)0x0)) {
    pCVar1 = (CONF_VALUE *)0x0;
  }
  else {
    local_18 = 0;
    local_1c = section;
    pCVar1 = (CONF_VALUE *)lh_retrieve((_LHASH *)conf->data,&local_1c);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pCVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

