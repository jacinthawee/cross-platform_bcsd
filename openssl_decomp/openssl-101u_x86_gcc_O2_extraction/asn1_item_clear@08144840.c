
void __regparm3 asn1_item_clear(undefined4 *param_1,byte *param_2)

{
  uint *puVar1;
  code *pcVar2;
  int iVar3;
  
LAB_08144843:
  if (6 < *param_2) {
    return;
  }
  switch(*param_2) {
  case 0:
    puVar1 = *(uint **)(param_2 + 8);
    if (puVar1 == (uint *)0x0) {
      iVar3 = *(int *)(param_2 + 0x10);
      if (iVar3 == 0) {
        if (*(int *)(param_2 + 4) == 1) {
          *param_1 = *(undefined4 *)(param_2 + 0x14);
          return;
        }
        goto switchD_0814484b_caseD_1;
      }
      goto LAB_0814489f;
    }
    if ((*puVar1 & 0x306) != 0) goto switchD_0814484b_caseD_1;
    param_2 = (byte *)puVar1[4];
    goto LAB_08144843;
  default:
    goto switchD_0814484b_caseD_1;
  case 4:
    if (*(int *)(param_2 + 0x10) == 0) goto switchD_0814484b_caseD_1;
    pcVar2 = *(code **)(*(int *)(param_2 + 0x10) + 0xc);
    break;
  case 5:
    iVar3 = *(int *)(param_2 + 0x10);
    if (iVar3 == 0) goto switchD_0814484b_caseD_1;
LAB_0814489f:
    pcVar2 = *(code **)(iVar3 + 0x10);
  }
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(param_1,param_2);
    return;
  }
switchD_0814484b_caseD_1:
  *param_1 = 0;
  return;
}

