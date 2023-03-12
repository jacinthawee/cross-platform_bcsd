
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
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pcVar6 = "clock_precision_digits";
  local_20 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_NCONF_get_number_e_006a6f3c)
                    (param_1,param_2,"clock_precision_digits",&local_20);
  if (iVar2 == 0) {
    local_20 = 0;
  }
  else if (6 < local_20) {
    uVar5 = 1;
    pcVar6 = "invalid variable value for %s::%s\n";
    (*(code *)PTR___fprintf_chk_006a9980)
              (*(undefined4 *)PTR_stderr_006a9af8,1,"invalid variable value for %s::%s\n",param_2,
               "clock_precision_digits");
    bVar4 = false;
    goto LAB_005c654c;
  }
  uVar5 = local_20;
  iVar2 = TS_RESP_CTX_set_clock_precision_digits(param_3,local_20);
  bVar4 = iVar2 != 0;
LAB_005c654c:
  if (local_1c == *(int *)puVar1) {
    return bVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pcVar3 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)();
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
    (*(code *)PTR___fprintf_chk_006a9980)
              (*(undefined4 *)PTR_stderr_006a9af8,1,"invalid variable value for %s::%s\n",uVar5,
               "ordering");
    return false;
  }
  return true;
}

