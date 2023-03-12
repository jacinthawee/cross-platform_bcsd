
char * _CONF_get_string(CONF *conf,char *section,char *name)

{
  undefined *puVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *local_28;
  char *local_24;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (name == (char *)0x0) {
LAB_0059e75c:
    pcVar3 = (char *)0x0;
  }
  else {
    if (conf == (CONF *)0x0) {
      pcVar3 = (char *)(*(code *)PTR_getenv_006aab6c)(name);
      goto LAB_0059e6bc;
    }
    if (section == (char *)0x0) {
LAB_0059e738:
      local_28 = "default";
      local_24 = name;
      iVar2 = (*(code *)PTR_lh_retrieve_006a84b0)(conf->data,&local_28);
      if (iVar2 == 0) goto LAB_0059e75c;
    }
    else {
      local_28 = section;
      local_24 = name;
      iVar2 = (*(code *)PTR_lh_retrieve_006a84b0)(conf->data,&local_28);
      if (iVar2 == 0) {
        if ((((*section == 'E') && (section[1] == 'N')) && (section[2] == 'V')) &&
           ((section[3] == '\0' &&
            (pcVar3 = (char *)(*(code *)PTR_getenv_006aab6c)(name), pcVar3 != (char *)0x0))))
        goto LAB_0059e6bc;
        goto LAB_0059e738;
      }
    }
    pcVar3 = *(char **)(iVar2 + 8);
  }
LAB_0059e6bc:
  if (local_1c == *(int *)puVar1) {
    return pcVar3;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (iVar2 == 0) {
    return (char *)0x0;
  }
  if (*(int *)(iVar2 + 8) == 0) {
    iVar4 = (*(code *)PTR_lh_new_006a850c)(conf_value_LHASH_HASH,conf_value_LHASH_COMP);
    *(int *)(iVar2 + 8) = iVar4;
    return (char *)(uint)(iVar4 != 0);
  }
  return (char *)0x1;
}

