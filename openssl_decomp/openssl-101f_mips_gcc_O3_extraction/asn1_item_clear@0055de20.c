
void asn1_item_clear(undefined4 *param_1,undefined *param_2)

{
  int iVar1;
  uint *puVar2;
  code *UNRECOVERED_JUMPTABLE;
  
LAB_0055de28:
  switch(*param_2) {
  case 0:
    puVar2 = *(uint **)(param_2 + 8);
    if (puVar2 == (uint *)0x0) {
      iVar1 = *(int *)(param_2 + 0x10);
      if (iVar1 != 0) goto LAB_0055de54;
      if (*(int *)(param_2 + 4) == 1) {
        *param_1 = *(undefined4 *)(param_2 + 0x14);
        return;
      }
    }
    else if ((*puVar2 & 0x306) == 0) goto code_r0x0055dea8;
  case 1:
  case 2:
  case 3:
  case 6:
switchD_0055de40_caseD_1:
    *param_1 = 0;
    return;
  case 4:
    if (*(int *)(param_2 + 0x10) == 0) goto switchD_0055de40_caseD_1;
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_2 + 0x10) + 0xc);
    break;
  case 5:
    iVar1 = *(int *)(param_2 + 0x10);
    if (iVar1 == 0) goto switchD_0055de40_caseD_1;
LAB_0055de54:
    UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x10);
    break;
  default:
    return;
  }
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0055de84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  goto switchD_0055de40_caseD_1;
code_r0x0055dea8:
  param_2 = (undefined *)puVar2[4];
  goto LAB_0055de28;
}

