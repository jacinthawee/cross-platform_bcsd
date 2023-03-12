
int ssl_cipher_list_to_bytes(int param_1,_STACK *param_2,int param_3,code *param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 != (_STACK *)0x0) {
    iVar3 = 0;
    iVar4 = param_3;
    if (param_4 == (code *)0x0) {
      for (; iVar1 = sk_num(param_2), iVar3 < iVar1; iVar3 = iVar3 + 1) {
        pvVar2 = sk_value(param_2,iVar3);
        if ((*(byte *)((int)pvVar2 + 0x1c) & 4) == 0) {
          if ((*(byte *)((int)pvVar2 + 0xd) & 1) == 0) goto LAB_080c11ac;
LAB_080c114e:
          if (*(int *)(param_1 + 0xdc) == 0) goto LAB_080c1168;
LAB_080c1158:
          iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x4c))(pvVar2,iVar4);
          iVar4 = iVar4 + iVar1;
        }
        else if ((*(int *)(param_1 + 0x110) >> 8 == 3) && (0x302 < *(int *)(param_1 + 0x110))) {
          if ((*(byte *)((int)pvVar2 + 0xd) & 1) != 0) goto LAB_080c114e;
LAB_080c11ac:
          if (((*(byte *)((int)pvVar2 + 0x10) & 0x80) == 0) || (*(int *)(param_1 + 0xdc) != 0))
          goto LAB_080c1158;
        }
LAB_080c1168:
      }
    }
    else {
      for (; iVar1 = sk_num(param_2), iVar3 < iVar1; iVar3 = iVar3 + 1) {
        pvVar2 = sk_value(param_2,iVar3);
        if ((((*(byte *)((int)pvVar2 + 0x1c) & 4) == 0) ||
            ((*(int *)(param_1 + 0x110) >> 8 == 3 && (0x302 < *(int *)(param_1 + 0x110))))) &&
           ((((*(byte *)((int)pvVar2 + 0xd) & 1) == 0 &&
             ((*(byte *)((int)pvVar2 + 0x10) & 0x80) == 0)) || (*(int *)(param_1 + 0xdc) != 0)))) {
          iVar1 = (*param_4)(pvVar2,iVar4);
          iVar4 = iVar4 + iVar1;
        }
      }
    }
    if (param_3 != iVar4) {
      if (*(int *)(param_1 + 400) == 0) {
        if (param_4 == (code *)0x0) {
          iVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x4c))(scsv_18539,iVar4);
          iVar4 = iVar4 + iVar3;
        }
        else {
          iVar3 = (*param_4)(scsv_18539,iVar4);
          iVar4 = iVar4 + iVar3;
        }
      }
      return iVar4 - param_3;
    }
  }
  return 0;
}

