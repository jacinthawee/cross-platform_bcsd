
int ssl_cipher_list_to_bytes(int param_1,int param_2,int param_3,code *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar4 = param_3;
  if (param_4 == (code *)0x0) {
    iVar2 = 0;
    while (iVar1 = (*(code *)PTR_sk_num_006a7f2c)(param_2), iVar2 < iVar1) {
      iVar1 = (*(code *)PTR_sk_value_006a7f24)(param_2,iVar2);
      if ((((*(uint *)(iVar1 + 0x1c) & 4) == 0) ||
          ((*(int *)(param_1 + 0x110) >> 8 == 3 && (0x302 < *(int *)(param_1 + 0x110))))) &&
         ((((*(uint *)(iVar1 + 0xc) & 0x100) == 0 && ((*(uint *)(iVar1 + 0x10) & 0x80) == 0)) ||
          (*(int *)(param_1 + 0xdc) != 0)))) {
        iVar2 = iVar2 + 1;
        iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x4c))(iVar1,iVar4);
        iVar4 = iVar4 + iVar1;
      }
      else {
        iVar2 = iVar2 + 1;
      }
    }
  }
  else {
    iVar2 = 0;
    while( true ) {
      iVar1 = (*(code *)PTR_sk_num_006a7f2c)(param_2);
      iVar3 = iVar2 + 1;
      if (iVar1 <= iVar2) break;
      iVar1 = (*(code *)PTR_sk_value_006a7f24)(param_2,iVar2);
      iVar2 = iVar3;
      if ((((*(uint *)(iVar1 + 0x1c) & 4) == 0) ||
          ((*(int *)(param_1 + 0x110) >> 8 == 3 && (0x302 < *(int *)(param_1 + 0x110))))) &&
         ((((*(uint *)(iVar1 + 0xc) & 0x100) == 0 && ((*(uint *)(iVar1 + 0x10) & 0x80) == 0)) ||
          (*(int *)(param_1 + 0xdc) != 0)))) {
        iVar1 = (*param_4)(iVar1,iVar4);
        iVar4 = iVar4 + iVar1;
      }
    }
  }
  if (param_3 == iVar4) {
    return 0;
  }
  iVar2 = iVar4 - param_3;
  if (*(int *)(param_1 + 400) == 0) {
    if (param_4 == (code *)0x0) {
      iVar2 = (**(code **)(*(int *)(param_1 + 8) + 0x4c))(scsv_18559,iVar4);
    }
    else {
      iVar2 = (*param_4)(scsv_18559);
    }
    iVar2 = (iVar4 + iVar2) - param_3;
  }
  return iVar2;
}

