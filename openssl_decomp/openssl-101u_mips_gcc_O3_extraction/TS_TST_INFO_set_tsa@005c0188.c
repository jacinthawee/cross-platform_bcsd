
bool TS_TST_INFO_set_tsa(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x20) != param_2) {
    iVar1 = (*(code *)PTR_GENERAL_NAME_dup_006a9440)(param_2);
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x8f,0x41,"ts_rsp_utils.c",0x14c);
    }
    else {
      (*(code *)PTR_GENERAL_NAME_free_006a73a4)(*(undefined4 *)(param_1 + 0x20));
      *(int *)(param_1 + 0x20) = iVar1;
    }
    return iVar1 != 0;
  }
  return true;
}
