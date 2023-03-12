
bool by_file_ctrl(X509_LOOKUP *param_1,int param_2,char *param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  bool bVar3;
  
  if (param_2 != 1) {
    return false;
  }
  if (param_4 == 3) {
    pcVar2 = X509_get_default_cert_file_env();
    pcVar2 = getenv(pcVar2);
    if (pcVar2 == (char *)0x0) {
      X509_get_default_cert_file();
    }
    iVar1 = X509_load_cert_crl_file_part_0();
    bVar3 = iVar1 != 0;
    if (bVar3) {
      bVar3 = true;
    }
    else {
      ERR_put_error(0xb,0x65,0x68,"by_file.c",0x72);
    }
  }
  else {
    if (param_4 == 1) {
      iVar1 = X509_load_cert_crl_file_part_0();
      return iVar1 != 0;
    }
    iVar1 = X509_load_cert_file(param_1,param_3,param_4);
    bVar3 = iVar1 != 0;
  }
  return bVar3;
}

