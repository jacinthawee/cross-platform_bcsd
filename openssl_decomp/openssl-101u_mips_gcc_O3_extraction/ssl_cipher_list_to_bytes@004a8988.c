
int ssl_cipher_list_to_bytes(int param_1,int param_2,int param_3,code *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == 0) {
    return 0;
  }
  if (param_4 == (code *)0x0) {
    param_4 = *(code **)(*(int *)(param_1 + 8) + 0x4c);
  }
  iVar3 = 0;
  iVar1 = (*(code *)PTR_sk_num_006a6e2c)(param_2);
  iVar4 = param_3;
  if (0 < iVar1) {
    do {
      iVar1 = (*(code *)PTR_sk_value_006a6e24)(param_2,iVar3);
      if (((((*(uint *)(iVar1 + 0x1c) & 4) == 0) ||
           ((*(int *)(param_1 + 0x110) >> 8 == 3 && (0x302 < *(int *)(param_1 + 0x110))))) &&
          ((((*(uint *)(iVar1 + 0xc) & 0x100) == 0 && ((*(uint *)(iVar1 + 0x10) & 0x80) == 0)) ||
           (*(int *)(param_1 + 0xdc) != 0)))) &&
         ((((*(uint *)(iVar1 + 0xc) & 0x400) == 0 && ((*(uint *)(iVar1 + 0x10) & 0x400) == 0)) ||
          ((*(uint *)(param_1 + 0x1d0) & 0x400) != 0)))) {
        iVar1 = (*param_4)(iVar1,iVar4);
        iVar4 = iVar4 + iVar1;
      }
      iVar3 = iVar3 + 1;
      iVar1 = (*(code *)PTR_sk_num_006a6e2c)(param_2);
    } while (iVar3 < iVar1);
  }
  if (iVar4 == param_3) {
    return 0;
  }
  if (*(int *)(param_1 + 400) == 0) {
    iVar1 = (*param_4)(scsv_18588,iVar4);
    iVar4 = iVar4 + iVar1;
    uVar2 = *(uint *)(param_1 + 0x104);
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x104);
  }
  if ((uVar2 & 0x80) != 0) {
    iVar1 = (*param_4)(scsv_18589,iVar4);
    return (iVar4 + iVar1) - param_3;
  }
  return iVar4 - param_3;
}

