
char * _CONF_get_string(CONF *conf,char *section,char *name)

{
  undefined *puVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *local_28;
  char *local_24;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (name == (char *)0x0) {
LAB_0059ba1c:
    pcVar3 = (char *)0x0;
  }
  else {
    if (conf == (CONF *)0x0) {
      pcVar3 = (char *)(*(code *)PTR_getenv_006a9a60)(name);
      goto LAB_0059b97c;
    }
    if (section == (char *)0x0) {
LAB_0059b9f8:
      local_28 = "default";
      local_24 = name;
      iVar2 = (*(code *)PTR_lh_retrieve_006a73b0)(conf->data,&local_28);
      if (iVar2 == 0) goto LAB_0059ba1c;
    }
    else {
      local_28 = section;
      local_24 = name;
      iVar2 = (*(code *)PTR_lh_retrieve_006a73b0)(conf->data,&local_28);
      if (iVar2 == 0) {
        if ((((*section == 'E') && (section[1] == 'N')) && (section[2] == 'V')) &&
           ((section[3] == '\0' &&
            (pcVar3 = (char *)(*(code *)PTR_getenv_006a9a60)(name), pcVar3 != (char *)0x0))))
        goto LAB_0059b97c;
        goto LAB_0059b9f8;
      }
    }
    pcVar3 = *(char **)(iVar2 + 8);
  }
LAB_0059b97c:
  if (local_1c == *(int *)puVar1) {
    return pcVar3;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (iVar2 == 0) {
    return (char *)0x0;
  }
  if (*(int *)(iVar2 + 8) == 0) {
    iVar4 = (*(code *)PTR_lh_new_006a740c)(conf_value_LHASH_HASH,conf_value_LHASH_COMP);
    *(int *)(iVar2 + 8) = iVar4;
    return (char *)(uint)(iVar4 != 0);
  }
  return (char *)0x1;
}

