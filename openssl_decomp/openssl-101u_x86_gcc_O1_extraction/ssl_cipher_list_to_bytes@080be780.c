
int ssl_cipher_list_to_bytes(int param_1,_STACK *param_2,int param_3,code *param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 != (_STACK *)0x0) {
    if (param_4 == (code *)0x0) {
      param_4 = *(code **)(*(int *)(param_1 + 8) + 0x4c);
    }
    iVar4 = param_3;
    for (iVar3 = 0; iVar1 = sk_num(param_2), iVar3 < iVar1; iVar3 = iVar3 + 1) {
      pvVar2 = sk_value(param_2,iVar3);
      if (((((*(byte *)((int)pvVar2 + 0x1c) & 4) == 0) ||
           ((*(int *)(param_1 + 0x110) >> 8 == 3 && (0x302 < *(int *)(param_1 + 0x110))))) &&
          ((((*(uint *)((int)pvVar2 + 0xc) & 0x100) == 0 &&
            ((*(byte *)((int)pvVar2 + 0x10) & 0x80) == 0)) || (*(int *)(param_1 + 0xdc) != 0)))) &&
         ((((*(uint *)((int)pvVar2 + 0xc) & 0x400) == 0 &&
           ((*(byte *)((int)pvVar2 + 0x11) & 4) == 0)) || ((*(byte *)(param_1 + 0x1d1) & 4) != 0))))
      {
        iVar1 = (*param_4)(pvVar2,iVar4);
        iVar4 = iVar4 + iVar1;
      }
    }
    if (iVar4 != param_3) {
      if (*(int *)(param_1 + 400) == 0) {
        iVar3 = (*param_4)(scsv_18568,iVar4);
        iVar4 = iVar4 + iVar3;
      }
      if ((*(byte *)(param_1 + 0x104) & 0x80) != 0) {
        iVar3 = (*param_4)(scsv_18569,iVar4);
        return (iVar4 + iVar3) - param_3;
      }
      return iVar4 - param_3;
    }
  }
  return 0;
}

