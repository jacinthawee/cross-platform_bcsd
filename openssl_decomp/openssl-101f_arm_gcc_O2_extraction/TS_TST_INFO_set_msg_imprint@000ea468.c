
int TS_TST_INFO_set_msg_imprint(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 8) == param_2) {
    iVar1 = 1;
  }
  else {
    iVar1 = TS_MSG_IMPRINT_dup(param_2);
    if (iVar1 == 0) {
      ERR_put_error(0x2f,0x8a,0x41,"ts_rsp_utils.c",0x97);
    }
    else {
      TS_MSG_IMPRINT_free(*(undefined4 *)(param_1 + 8));
      *(int *)(param_1 + 8) = iVar1;
      iVar1 = 1;
    }
  }
  return iVar1;
}

