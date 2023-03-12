
bool TS_TST_INFO_set_time(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x10) != param_2) {
    iVar1 = (*(code *)PTR_ASN1_STRING_dup_006a9ddc)(param_2);
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x8e,0x41,"ts_rsp_utils.c",0xc3);
    }
    else {
      (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a8138)(*(undefined4 *)(param_1 + 0x10));
      *(int *)(param_1 + 0x10) = iVar1;
    }
    return iVar1 != 0;
  }
  return true;
}

