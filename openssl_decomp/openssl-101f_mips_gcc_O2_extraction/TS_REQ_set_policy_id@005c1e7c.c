
bool TS_REQ_set_policy_id(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 8) != param_2) {
    iVar1 = (*(code *)PTR_OBJ_dup_006a95b4)(param_2);
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x79,0x41,"ts_req_utils.c",0x8a);
    }
    else {
      (*(code *)PTR_ASN1_OBJECT_free_006a8104)(*(undefined4 *)(param_1 + 8));
      *(int *)(param_1 + 8) = iVar1;
    }
    return iVar1 != 0;
  }
  return true;
}

