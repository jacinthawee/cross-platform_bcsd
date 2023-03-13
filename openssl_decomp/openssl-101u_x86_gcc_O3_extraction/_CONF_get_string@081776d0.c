
char * _CONF_get_string(CONF *conf,char *section,char *name)

{
  void *pvVar1;
  char *pcVar2;
  int in_GS_OFFSET;
  char *local_2c;
  char *local_28;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (name == (char *)0x0) {
LAB_0817778e:
    pcVar2 = (char *)0x0;
  }
  else {
    if (conf == (CONF *)0x0) {
      pcVar2 = getenv(name);
      goto LAB_08177728;
    }
    if (section == (char *)0x0) {
LAB_08177770:
      local_2c = "default";
      local_28 = name;
      pvVar1 = lh_retrieve((_LHASH *)conf->data,&local_2c);
      if (pvVar1 == (void *)0x0) goto LAB_0817778e;
    }
    else {
      local_28 = name;
      local_2c = section;
      pvVar1 = lh_retrieve((_LHASH *)conf->data,&local_2c);
      if (pvVar1 == (void *)0x0) {
        if ((((*section == 'E') && (section[1] == 'N')) && (section[2] == 'V')) &&
           ((section[3] == '\0' && (pcVar2 = getenv(name), pcVar2 != (char *)0x0))))
        goto LAB_08177728;
        goto LAB_08177770;
      }
    }
    pcVar2 = *(char **)((int)pvVar1 + 8);
  }
LAB_08177728:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pcVar2;
}

