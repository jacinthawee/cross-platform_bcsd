
bool TS_TST_INFO_set_serial(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) != param_2) {
    iVar1 = (*(code *)PTR_ASN1_INTEGER_dup_006aa37c)(param_2);
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x8d,0x41,"ts_rsp_utils.c",0xad);
    }
    else {
      (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(*(undefined4 *)(param_1 + 0xc));
      *(int *)(param_1 + 0xc) = iVar1;
    }
    return iVar1 != 0;
  }
  return true;
}

