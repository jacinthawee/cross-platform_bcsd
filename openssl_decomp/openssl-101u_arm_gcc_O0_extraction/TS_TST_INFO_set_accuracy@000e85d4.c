
int TS_TST_INFO_set_accuracy(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x14) == param_2) {
    iVar1 = 1;
  }
  else {
    iVar1 = TS_ACCURACY_dup(param_2);
    if (iVar1 == 0) {
      ERR_put_error(0x2f,0x89,0x41,"ts_rsp_utils.c",0xd4);
    }
    else {
      TS_ACCURACY_free(*(undefined4 *)(param_1 + 0x14));
      *(int *)(param_1 + 0x14) = iVar1;
      iVar1 = 1;
    }
  }
  return iVar1;
}

