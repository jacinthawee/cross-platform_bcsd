
int dir_ctrl(int param_1,int param_2,undefined4 param_3,int param_4)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 != 2) {
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0xc);
  if (param_4 != 3) {
    iVar3 = add_cert_dir_isra_0(iVar3 + 4,param_3,param_4);
    return iVar3;
  }
  pcVar1 = X509_get_default_cert_dir_env();
  iVar2 = (*(code *)PTR_getenv_006aab6c)(pcVar1);
  if (iVar2 == 0) {
    pcVar1 = X509_get_default_cert_dir();
    iVar3 = add_cert_dir_isra_0(iVar3 + 4,pcVar1,1);
  }
  else {
    iVar3 = add_cert_dir_isra_0(iVar3 + 4,iVar2,1);
  }
  if (iVar3 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x66,0x67,"by_dir.c",0x92);
  }
  return iVar3;
}

