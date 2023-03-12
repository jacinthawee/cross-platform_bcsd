
undefined4 TS_RESP_CTX_add_failure_info(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = TS_RESP_get_status_info(*(undefined4 *)(param_1 + 0x48));
  iVar2 = *(int *)(iVar1 + 8);
  if (iVar2 == 0) {
    iVar2 = (*(code *)PTR_ASN1_BIT_STRING_new_006a9784)();
    *(int *)(iVar1 + 8) = iVar2;
    if (iVar2 == 0) goto LAB_005c4398;
  }
  iVar1 = (*(code *)PTR_ASN1_BIT_STRING_set_bit_006a9ee8)(iVar2,param_2,1);
  if (iVar1 != 0) {
    return 1;
  }
LAB_005c4398:
  (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x7c,0x41,"ts_rsp_sign.c",0x18b);
  return 0;
}

