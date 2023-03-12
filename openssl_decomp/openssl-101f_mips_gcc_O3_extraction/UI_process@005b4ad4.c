
int UI_process(UI *ui)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  
  if ((*(code **)(*(int *)ui + 4) != (code *)0x0) &&
     (iVar1 = (**(code **)(*(int *)ui + 4))(), iVar1 == 0)) {
    return -1;
  }
  if ((*(uint *)(ui + 0x14) & 0x100) != 0) {
    (*(code *)PTR_ERR_print_errors_cb_006aa3c8)(print_error,ui);
  }
  iVar1 = 0;
  do {
    do {
      iVar2 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(ui + 4));
      if (iVar2 <= iVar1) {
        if (*(code **)(*(int *)ui + 0xc) != (code *)0x0) {
          iVar1 = (**(code **)(*(int *)ui + 0xc))(ui,iVar1);
          if (iVar1 == -1) goto LAB_005b4c70;
          iVar2 = -1;
          if (iVar1 == 0) goto LAB_005b4b80;
        }
        iVar1 = 0;
        goto LAB_005b4bf8;
      }
      pcVar5 = *(code **)(*(int *)ui + 8);
      iVar1 = iVar1 + 1;
    } while (pcVar5 == (code *)0x0);
    uVar3 = (*(code *)PTR_sk_value_006a7f24)(*(undefined4 *)(ui + 4));
    iVar2 = (*pcVar5)(ui,uVar3);
  } while (iVar2 != 0);
  goto LAB_005b4b7c;
LAB_005b4c70:
  iVar2 = -2;
  goto LAB_005b4b80;
  while( true ) {
    uVar3 = (*(code *)PTR_sk_value_006a7f24)(*(undefined4 *)(ui + 4),iVar2);
    iVar4 = (*pcVar5)(ui,uVar3);
    if (iVar4 == -1) goto LAB_005b4c70;
    if (iVar4 == 0) break;
LAB_005b4bf8:
    do {
      iVar2 = iVar1;
      iVar1 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(ui + 4));
      if (iVar1 <= iVar2) {
        iVar2 = 0;
        goto LAB_005b4b80;
      }
      pcVar5 = *(code **)(*(int *)ui + 0x10);
      iVar1 = iVar2 + 1;
    } while (pcVar5 == (code *)0x0);
  }
LAB_005b4b7c:
  iVar2 = -1;
LAB_005b4b80:
  iVar1 = iVar2;
  if (*(code **)(*(int *)ui + 0x14) != (code *)0x0) {
    iVar4 = (**(code **)(*(int *)ui + 0x14))(ui);
    iVar1 = -1;
    if (iVar4 != 0) {
      iVar1 = iVar2;
    }
  }
  return iVar1;
}

