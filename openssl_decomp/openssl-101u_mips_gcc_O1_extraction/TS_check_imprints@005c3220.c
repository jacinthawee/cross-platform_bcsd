
undefined4 TS_check_imprints(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = TS_TST_INFO_get_msg_imprint(param_4);
  puVar2 = (undefined4 *)TS_MSG_IMPRINT_get_algo(iVar1);
  if (((param_1 == (undefined4 *)0x0) ||
      (((iVar3 = (*(code *)PTR_OBJ_cmp_006a8cc4)(*param_1,*puVar2), iVar3 == 0 &&
        ((param_1[1] == 0 || (iVar3 = (*(code *)PTR_ASN1_TYPE_get_006a74b0)(), iVar3 == 5)))) &&
       ((puVar2[1] == 0 || (iVar3 = (*(code *)PTR_ASN1_TYPE_get_006a74b0)(), iVar3 == 5)))))) &&
     (iVar3 = (*(code *)PTR_ASN1_STRING_length_006a732c)(*(undefined4 *)(iVar1 + 4)),
     iVar3 == param_3)) {
    uVar4 = (*(code *)PTR_ASN1_STRING_data_006a7330)(*(undefined4 *)(iVar1 + 4));
    iVar1 = (*(code *)PTR_memcmp_006a9ad0)(param_2,uVar4,param_3);
    if (iVar1 == 0) {
      return 1;
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,100,0x67,"ts_rsp_verify.c",0x2a0);
  return 0;
}

