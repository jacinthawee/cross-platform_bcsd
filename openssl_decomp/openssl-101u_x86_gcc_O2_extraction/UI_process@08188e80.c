
int UI_process(UI *ui)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  if ((*(code **)(*(int *)ui + 4) != (code *)0x0) &&
     (iVar2 = (**(code **)(*(int *)ui + 4))(ui), iVar2 == 0)) {
    return -1;
  }
  if (((byte)ui[0x15] & 1) != 0) {
    ERR_print_errors_cb(print_error,ui);
  }
  iVar2 = 0;
  while( true ) {
    iVar3 = sk_num(*(_STACK **)(ui + 4));
    if (iVar3 <= iVar2) break;
    pcVar1 = *(code **)(*(int *)ui + 8);
    if (pcVar1 != (code *)0x0) {
      pvVar4 = sk_value(*(_STACK **)(ui + 4),iVar2);
      iVar3 = (*pcVar1)(ui,pvVar4);
      if (iVar3 == 0) goto LAB_08188f49;
    }
    iVar2 = iVar2 + 1;
  }
  pcVar1 = *(code **)(*(int *)ui + 0xc);
  if (pcVar1 != (code *)0x0) {
    iVar2 = (*pcVar1)(ui);
    iVar3 = -2;
    if ((iVar2 == -1) || (iVar3 = -1, iVar2 == 0)) goto LAB_08188f4e;
  }
  for (iVar2 = 0; iVar3 = sk_num(*(_STACK **)(ui + 4)), iVar2 < iVar3; iVar2 = iVar2 + 1) {
    pcVar1 = *(code **)(*(int *)ui + 0x10);
    if (pcVar1 != (code *)0x0) {
      pvVar4 = sk_value(*(_STACK **)(ui + 4),iVar2);
      iVar3 = (*pcVar1)(ui,pvVar4);
      if (iVar3 == -1) {
        iVar3 = -2;
        goto LAB_08188f4e;
      }
      if (iVar3 == 0) goto LAB_08188f49;
    }
  }
  iVar3 = 0;
LAB_08188f4e:
  if (*(code **)(*(int *)ui + 0x14) == (code *)0x0) {
    return iVar3;
  }
  iVar2 = (**(code **)(*(int *)ui + 0x14))(ui);
  if (iVar2 == 0) {
    return -1;
  }
  return iVar3;
LAB_08188f49:
  iVar3 = -1;
  goto LAB_08188f4e;
}

