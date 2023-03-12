
bool pkey_cmac_copy(int param_1,int param_2)

{
  CMAC_CTX *out;
  int iVar1;
  
  out = CMAC_CTX_new();
  *(CMAC_CTX **)(param_1 + 0x14) = out;
  if (out != (CMAC_CTX *)0x0) {
    *(undefined4 *)(param_1 + 0x24) = 0;
    iVar1 = CMAC_CTX_copy(out,*(CMAC_CTX **)(param_2 + 0x14));
    return iVar1 != 0;
  }
  return false;
}

