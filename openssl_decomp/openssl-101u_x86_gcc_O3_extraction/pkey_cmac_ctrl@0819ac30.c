
uint pkey_cmac_ctrl(int param_1,int param_2,size_t param_3,EVP_CIPHER *param_4)

{
  CMAC_CTX *out;
  int iVar1;
  EVP_CIPHER *cipher;
  ENGINE *impl;
  
  out = *(CMAC_CTX **)(param_1 + 0x14);
  if (param_2 == 6) {
    if ((param_4 == (EVP_CIPHER *)0x0) || ((int)param_3 < 0)) {
      return 0;
    }
    impl = (ENGINE *)0x0;
    cipher = (EVP_CIPHER *)0x0;
  }
  else {
    if (param_2 == 0xc) {
      impl = *(ENGINE **)(param_1 + 4);
      cipher = param_4;
    }
    else {
      if (param_2 != 1) {
        return 0xfffffffe;
      }
      if ((*(int *)(param_1 + 8) != 0) &&
         (iVar1 = CMAC_CTX_copy(out,*(CMAC_CTX **)(*(int *)(param_1 + 8) + 0x14)), iVar1 == 0)) {
        return 0;
      }
      impl = (ENGINE *)0x0;
      cipher = (EVP_CIPHER *)0x0;
    }
    param_3 = 0;
    param_4 = (EVP_CIPHER *)0x0;
  }
  iVar1 = CMAC_Init(out,param_4,param_3,cipher,impl);
  return (uint)(iVar1 != 0);
}

