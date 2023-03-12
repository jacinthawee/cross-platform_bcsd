
bool TS_CONF_set_clock_precision_digits(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  bool bVar4;
  char *pcVar3;
  uint uVar5;
  char *pcVar6;
  uint local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pcVar6 = "clock_precision_digits";
  local_20 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                    (param_1,param_2,"clock_precision_digits",&local_20);
  if (iVar2 == 0) {
    local_20 = 0;
  }
  else if (6 < local_20) {
    uVar5 = 1;
    pcVar6 = "invalid variable value for %s::%s\n";
    (*(code *)PTR___fprintf_chk_006aaa8c)
              (*(undefined4 *)PTR_stderr_006aac00,1,"invalid variable value for %s::%s\n",param_2,
               "clock_precision_digits");
    bVar4 = false;
    goto LAB_005c8dcc;
  }
  uVar5 = local_20;
  iVar2 = TS_RESP_CTX_set_clock_precision_digits(param_3,local_20);
  bVar4 = iVar2 != 0;
LAB_005c8dcc:
  if (local_1c == *(int *)puVar1) {
    return bVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pcVar3 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)();
  if (pcVar3 != (char *)0x0) {
    if (*pcVar3 == 'y') {
      if (((pcVar3[1] == 'e') && (pcVar3[2] == 's')) && (pcVar3[3] == '\0')) {
        TS_RESP_CTX_add_flags(pcVar6,2);
        return true;
      }
    }
    else if (((*pcVar3 == 'n') && (pcVar3[1] == 'o')) && (pcVar3[2] == '\0')) {
      return true;
    }
    (*(code *)PTR___fprintf_chk_006aaa8c)
              (*(undefined4 *)PTR_stderr_006aac00,1,"invalid variable value for %s::%s\n",uVar5,
               "ordering");
    return false;
  }
  return true;
}

