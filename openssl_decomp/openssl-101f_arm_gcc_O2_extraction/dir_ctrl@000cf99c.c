
int dir_ctrl(int param_1,int param_2,undefined4 param_3,int param_4)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  if (param_2 == 2) {
    if (param_4 != 3) {
      iVar2 = add_cert_dir_isra_0(iVar2 + 4,param_3,param_4);
      return iVar2;
    }
    pcVar1 = X509_get_default_cert_dir_env();
    pcVar1 = getenv(pcVar1);
    if (pcVar1 == (char *)0x0) {
      pcVar1 = X509_get_default_cert_dir();
    }
    iVar2 = add_cert_dir_isra_0(iVar2 + 4,pcVar1,1);
    if (iVar2 == 0) {
      ERR_put_error(0xb,0x66,0x67,"by_dir.c",0x92);
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

