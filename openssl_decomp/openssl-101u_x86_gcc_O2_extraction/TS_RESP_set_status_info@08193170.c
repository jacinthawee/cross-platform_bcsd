
undefined4 TS_RESP_set_status_info(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (*param_1 != param_2) {
    iVar1 = TS_STATUS_INFO_dup(param_2);
    if (iVar1 == 0) {
      uVar2 = 0;
      ERR_put_error(0x2f,0x87,0x41,"ts_rsp_utils.c",0x4c);
    }
    else {
      TS_STATUS_INFO_free(*param_1);
      *param_1 = iVar1;
    }
  }
  return uVar2;
}

