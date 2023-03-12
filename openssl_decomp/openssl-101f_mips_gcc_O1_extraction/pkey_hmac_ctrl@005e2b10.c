
uint pkey_hmac_ctrl(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x14);
  if (param_2 == 6) {
    if (((param_4 != 0) || (param_3 < 1)) && (-2 < param_3)) {
      iVar2 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)(piVar3 + 1,param_4);
      return (uint)(iVar2 != 0);
    }
    return 0;
  }
  if (param_2 == 7) {
    puVar1 = *(undefined4 **)(*(int *)(param_1 + 8) + 0x14);
    iVar2 = (*(code *)PTR_HMAC_Init_ex_006a8ba0)
                      (piVar3 + 5,puVar1[2],*puVar1,*piVar3,*(undefined4 *)(param_1 + 4));
    return (uint)(iVar2 != 0);
  }
  if (param_2 != 1) {
    return 0xfffffffe;
  }
  *piVar3 = param_4;
  return 1;
}

