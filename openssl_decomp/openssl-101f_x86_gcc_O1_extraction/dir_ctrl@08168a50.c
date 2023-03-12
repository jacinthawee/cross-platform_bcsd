
int dir_ctrl(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == 2) {
    if (param_4 != 3) {
      iVar1 = add_cert_dir_isra_0();
      return iVar1;
    }
    pcVar2 = X509_get_default_cert_dir_env();
    pcVar2 = getenv(pcVar2);
    if (pcVar2 == (char *)0x0) {
      X509_get_default_cert_dir();
    }
    iVar1 = add_cert_dir_isra_0();
    if (iVar1 == 0) {
      ERR_put_error(0xb,0x66,0x67,"by_dir.c",0x92);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

