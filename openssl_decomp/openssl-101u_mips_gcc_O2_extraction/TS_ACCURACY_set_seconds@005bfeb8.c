
bool TS_ACCURACY_set_seconds(int *param_1,int param_2)

{
  int iVar1;
  
  if (*param_1 != param_2) {
    iVar1 = (*(code *)PTR_ASN1_INTEGER_dup_006a9270)(param_2);
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x75,0x41,"ts_rsp_utils.c",0xe9);
    }
    else {
      (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(*param_1);
      *param_1 = iVar1;
    }
    return iVar1 != 0;
  }
  return true;
}

