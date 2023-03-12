
undefined4 TS_RESP_CTX_add_md(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14);
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_sk_new_null_006a80a4)();
    *(int *)(param_1 + 0x14) = iVar1;
    if (iVar1 == 0) goto LAB_005c3b98;
  }
  iVar1 = (*(code *)PTR_sk_push_006a80a8)(iVar1,param_2);
  if (iVar1 != 0) {
    return 1;
  }
LAB_005c3b98:
  (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x7d,0x41,"ts_rsp_sign.c",0x11d);
  return 0;
}

