
undefined4 TS_RESP_CTX_set_def_policy(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)();
  }
  iVar1 = (*(code *)PTR_OBJ_dup_006a95b4)(param_2);
  *(int *)(param_1 + 0x10) = iVar1;
  if (iVar1 != 0) {
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x82,0x41,"ts_rsp_sign.c",0xe6);
  return 0;
}

