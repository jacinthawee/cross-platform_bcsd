
bool TS_REQ_set_nonce(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) != param_2) {
    iVar1 = (*(code *)PTR_ASN1_INTEGER_dup_006a9270)(param_2);
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x78,0x41,"ts_req_utils.c",0x9d);
    }
    else {
      (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(*(undefined4 *)(param_1 + 0xc));
      *(int *)(param_1 + 0xc) = iVar1;
    }
    return iVar1 != 0;
  }
  return true;
}
