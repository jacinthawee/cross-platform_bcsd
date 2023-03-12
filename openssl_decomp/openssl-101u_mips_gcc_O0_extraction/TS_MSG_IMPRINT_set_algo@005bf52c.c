
bool TS_MSG_IMPRINT_set_algo(int *param_1,int param_2)

{
  int iVar1;
  
  if (*param_1 != param_2) {
    iVar1 = (*(code *)PTR_X509_ALGOR_dup_006a9408)(param_2);
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x76,0x41,"ts_req_utils.c",0x69);
    }
    else {
      (*(code *)PTR_X509_ALGOR_free_006a7ea4)(*param_1);
      *param_1 = iVar1;
    }
    return iVar1 != 0;
  }
  return true;
}

