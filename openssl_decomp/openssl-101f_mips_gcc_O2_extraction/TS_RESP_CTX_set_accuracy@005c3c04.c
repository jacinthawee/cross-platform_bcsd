
undefined4 TS_RESP_CTX_set_accuracy(int param_1,int param_2,int param_3,int param_4)

{
  undefined *puVar1;
  int iVar2;
  
  (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(*(undefined4 *)(param_1 + 0x18));
  puVar1 = PTR_ASN1_INTEGER_free_006a7f94;
  *(undefined4 *)(param_1 + 0x18) = 0;
  (*(code *)puVar1)(*(undefined4 *)(param_1 + 0x1c));
  puVar1 = PTR_ASN1_INTEGER_free_006a7f94;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  (*(code *)puVar1)(*(undefined4 *)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x20) = 0;
  if (param_2 == 0) {
LAB_005c3c78:
    if (param_3 != 0) {
      iVar2 = (*(code *)PTR_ASN1_INTEGER_new_006a8260)();
      *(int *)(param_1 + 0x1c) = iVar2;
      if ((iVar2 == 0) ||
         (iVar2 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(iVar2,param_3), iVar2 == 0))
      goto LAB_005c3cd4;
    }
    if (param_4 == 0) {
      return 1;
    }
    iVar2 = (*(code *)PTR_ASN1_INTEGER_new_006a8260)();
    *(int *)(param_1 + 0x20) = iVar2;
    if ((iVar2 != 0) &&
       (iVar2 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(iVar2,param_4), iVar2 != 0)) {
      return 1;
    }
  }
  else {
    iVar2 = (*(code *)PTR_ASN1_INTEGER_new_006a8260)();
    *(int *)(param_1 + 0x18) = iVar2;
    if (iVar2 == 0) goto LAB_005c3cd8;
    iVar2 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(iVar2,param_2);
    if (iVar2 != 0) goto LAB_005c3c78;
  }
LAB_005c3cd4:
  iVar2 = *(int *)(param_1 + 0x18);
LAB_005c3cd8:
  (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar2);
  puVar1 = PTR_ASN1_INTEGER_free_006a7f94;
  *(undefined4 *)(param_1 + 0x18) = 0;
  (*(code *)puVar1)(*(undefined4 *)(param_1 + 0x1c));
  puVar1 = PTR_ASN1_INTEGER_free_006a7f94;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  (*(code *)puVar1)(*(undefined4 *)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x20) = 0;
  (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x80,0x41,"ts_rsp_sign.c",0x13b);
  return 0;
}

