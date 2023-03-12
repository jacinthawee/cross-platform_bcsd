
bool TS_RESP_set_status_info(int *param_1,int param_2)

{
  int iVar1;
  
  if (*param_1 != param_2) {
    iVar1 = TS_STATUS_INFO_dup(param_2);
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x87,0x41,"ts_rsp_utils.c",0x4c);
    }
    else {
      TS_STATUS_INFO_free(*param_1);
      *param_1 = iVar1;
    }
    return iVar1 != 0;
  }
  return true;
}

