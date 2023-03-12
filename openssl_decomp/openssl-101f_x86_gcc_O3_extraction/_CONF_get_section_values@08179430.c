
stack_st_CONF_VALUE * _CONF_get_section_values(CONF *conf,char *section)

{
  void *pvVar1;
  stack_st_CONF_VALUE *psVar2;
  int in_GS_OFFSET;
  char *local_1c;
  undefined4 local_18;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((conf != (CONF *)0x0) && (section != (char *)0x0)) {
    local_18 = 0;
    local_1c = section;
    pvVar1 = lh_retrieve((_LHASH *)conf->data,&local_1c);
    if (pvVar1 != (void *)0x0) {
      psVar2 = *(stack_st_CONF_VALUE **)((int)pvVar1 + 8);
      goto LAB_08179475;
    }
  }
  psVar2 = (stack_st_CONF_VALUE *)0x0;
LAB_08179475:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return psVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

