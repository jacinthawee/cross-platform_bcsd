
bool by_file_ctrl(X509_LOOKUP *param_1,int param_2,char *param_3,int param_4)

{
  int iVar1;
  bool bVar3;
  char *pcVar2;
  
  if (param_2 != 1) {
    return false;
  }
  if (param_4 == 3) {
    pcVar2 = X509_get_default_cert_file_env();
    iVar1 = (*(code *)PTR_getenv_006aab6c)(pcVar2);
    if (iVar1 == 0) {
      pcVar2 = X509_get_default_cert_file();
      iVar1 = X509_load_cert_crl_file_part_0(param_1,pcVar2);
    }
    else {
      iVar1 = X509_load_cert_crl_file_part_0(param_1,iVar1);
    }
    bVar3 = iVar1 != 0;
    if (bVar3) {
      bVar3 = true;
    }
    else {
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x65,0x68,"by_file.c",0x72);
    }
  }
  else {
    if (param_4 == 1) {
      iVar1 = X509_load_cert_crl_file_part_0(param_1,param_3);
      return iVar1 != 0;
    }
    iVar1 = X509_load_cert_file(param_1,param_3,param_4);
    bVar3 = iVar1 != 0;
  }
  return bVar3;
}

