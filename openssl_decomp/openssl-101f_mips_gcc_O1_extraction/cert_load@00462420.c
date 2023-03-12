
int cert_load(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    iVar1 = (*(code *)PTR_PEM_read_bio_X509_006a80cc)(param_1,0,0,0);
    if (iVar1 == 0) break;
    iVar2 = 1;
    (*(code *)PTR_sk_push_006a80a8)(param_2,iVar1);
  }
  if (iVar2 != 0) {
    (*(code *)PTR_ERR_clear_error_006a7fe0)();
  }
  return iVar2;
}

