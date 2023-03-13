
int build_subject(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_parse_name_006a6ff0)(param_2,param_3,param_4);
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (*(code *)PTR_X509_REQ_set_subject_name_006a6ff4)(param_1,iVar1);
    if (iVar2 == 0) {
      (*(code *)PTR_X509_NAME_free_006a6ff8)(iVar1);
    }
    else {
      (*(code *)PTR_X509_NAME_free_006a6ff8)(iVar1);
      iVar2 = 1;
    }
  }
  return iVar2;
}

