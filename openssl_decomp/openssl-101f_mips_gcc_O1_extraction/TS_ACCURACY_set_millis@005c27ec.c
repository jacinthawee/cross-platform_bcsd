
undefined4 TS_ACCURACY_set_millis(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 == param_2) {
    return 1;
  }
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (*(code *)PTR_ASN1_INTEGER_dup_006aa37c)(param_2);
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x74,0x41,"ts_rsp_utils.c",0x108);
      return 0;
    }
    iVar2 = *(int *)(param_1 + 4);
  }
  (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar2);
  *(int *)(param_1 + 4) = iVar1;
  return 1;
}

