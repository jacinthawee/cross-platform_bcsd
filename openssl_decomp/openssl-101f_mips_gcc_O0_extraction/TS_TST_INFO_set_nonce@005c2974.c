
bool TS_TST_INFO_set_nonce(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x1c) != param_2) {
    iVar1 = (*(code *)PTR_ASN1_INTEGER_dup_006aa37c)(param_2);
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x8b,0x41,"ts_rsp_utils.c",0x144);
    }
    else {
      (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(*(undefined4 *)(param_1 + 0x1c));
      *(int *)(param_1 + 0x1c) = iVar1;
    }
    return iVar1 != 0;
  }
  return true;
}

