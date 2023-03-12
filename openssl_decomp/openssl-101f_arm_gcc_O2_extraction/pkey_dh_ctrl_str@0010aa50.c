
int pkey_dh_ctrl_str(EVP_PKEY_CTX *param_1,char *param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  
  iVar1 = strcmp(param_2,"dh_paramgen_prime_len");
  if (iVar1 != 0) {
    iVar1 = strcmp(param_2,"dh_paramgen_generator");
    if (iVar1 == 0) {
      lVar2 = strtol(param_3,(char **)0x0,10);
      iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x1c,2,0x1002,lVar2,(void *)0x0);
    }
    else {
      iVar1 = -2;
    }
    return iVar1;
  }
  lVar2 = strtol(param_3,(char **)0x0,10);
  iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x1c,2,0x1001,lVar2,(void *)0x0);
  return iVar1;
}

