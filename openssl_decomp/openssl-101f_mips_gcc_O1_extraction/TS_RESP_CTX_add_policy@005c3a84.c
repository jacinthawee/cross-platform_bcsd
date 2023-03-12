
undefined4 TS_RESP_CTX_add_policy(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar1 = (*(code *)PTR_sk_new_null_006a80a4)();
    *(int *)(param_1 + 0xc) = iVar1;
    if (iVar1 != 0) goto LAB_005c3aac;
  }
  else {
LAB_005c3aac:
    iVar1 = (*(code *)PTR_OBJ_dup_006a95b4)(param_2);
    if (iVar1 != 0) {
      iVar2 = (*(code *)PTR_sk_push_006a80a8)(*(undefined4 *)(param_1 + 0xc),iVar1);
      if (iVar2 != 0) {
        return 1;
      }
      goto LAB_005c3adc;
    }
  }
  iVar1 = 0;
LAB_005c3adc:
  (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x7e,0x41,"ts_rsp_sign.c",0x10e);
  (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iVar1);
  return 0;
}

