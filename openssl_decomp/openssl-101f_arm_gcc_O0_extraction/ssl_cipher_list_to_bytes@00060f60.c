
int ssl_cipher_list_to_bytes(int param_1,_STACK *param_2,int param_3,code *param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  
  if (param_2 != (_STACK *)0x0) {
    pcVar5 = param_4;
    iVar6 = param_3;
    if (param_4 == (code *)0x0) {
      for (; iVar3 = sk_num(param_2), (int)pcVar5 < iVar3; pcVar5 = pcVar5 + 1) {
        pvVar2 = sk_value(param_2,(int)pcVar5);
        if (((-1 < *(int *)((int)pvVar2 + 0x1c) << 0x1d) ||
            ((*(int *)(param_1 + 0x110) >> 8 == 3 && (0x302 < *(int *)(param_1 + 0x110))))) &&
           (((-1 < *(int *)((int)pvVar2 + 0xc) << 0x17 &&
             (-1 < *(int *)((int)pvVar2 + 0x10) << 0x18)) || (*(int *)(param_1 + 0xdc) != 0)))) {
          iVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x4c))(pvVar2,iVar6);
          iVar6 = iVar6 + iVar3;
        }
      }
    }
    else {
      iVar3 = 0;
      while( true ) {
        iVar1 = sk_num(param_2);
        iVar4 = iVar3 + 1;
        if (iVar1 <= iVar3) break;
        pvVar2 = sk_value(param_2,iVar3);
        iVar3 = iVar4;
        if (((-1 < *(int *)((int)pvVar2 + 0x1c) << 0x1d) ||
            ((*(int *)(param_1 + 0x110) >> 8 == 3 && (0x302 < *(int *)(param_1 + 0x110))))) &&
           (((iVar1 = *(int *)((int)pvVar2 + 0xc) << 0x17, -1 < iVar1 &&
             (iVar4 = *(int *)((int)pvVar2 + 0x10) << 0x18, -1 < iVar4)) ||
            (iVar4 = *(int *)(param_1 + 0xdc), iVar4 != 0)))) {
          iVar1 = (*param_4)(pvVar2,iVar6,iVar1,iVar4,pcVar5);
          iVar6 = iVar6 + iVar1;
        }
      }
    }
    if ((iVar6 != param_3) && (*(int *)(param_1 + 400) == 0)) {
      if (param_4 == (code *)0x0) {
        iVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x4c))(&scsv_21190,iVar6);
        iVar6 = iVar6 + iVar3;
      }
      else {
        iVar3 = (*param_4)(&scsv_21190,iVar6);
        iVar6 = iVar6 + iVar3;
      }
    }
    return iVar6 - param_3;
  }
  return 0;
}

