
void asn1_item_clear(undefined4 *param_1,undefined *param_2)

{
  uint *puVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
code_r0x000bb30c:
  switch(*param_2) {
  case 0:
    puVar1 = *(uint **)(param_2 + 8);
    if (puVar1 == (uint *)0x0) {
      iVar2 = *(int *)(param_2 + 0x10);
      if (iVar2 != 0) goto LAB_000bb346;
      if (*(int *)(param_2 + 4) == 1) {
        *param_1 = *(undefined4 *)(param_2 + 0x14);
        return;
      }
    }
    else if ((*puVar1 & 0x306) == 0) goto code_r0x000bb33c;
  case 1:
  case 2:
  case 3:
  case 6:
switchD_000bb312_caseD_1:
    *param_1 = 0;
    return;
  case 4:
    if (*(int *)(param_2 + 0x10) == 0) goto switchD_000bb312_caseD_1;
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_2 + 0x10) + 0xc);
    break;
  case 5:
    iVar2 = *(int *)(param_2 + 0x10);
    if (iVar2 == 0) goto switchD_000bb312_caseD_1;
LAB_000bb346:
    UNRECOVERED_JUMPTABLE = *(code **)(iVar2 + 0x10);
    break;
  default:
    return;
  }
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000bb34c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  goto switchD_000bb312_caseD_1;
code_r0x000bb33c:
  param_2 = (undefined *)puVar1[4];
  goto code_r0x000bb30c;
}

