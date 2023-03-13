
undefined4 pkey_cmac_init(int param_1)

{
  CMAC_CTX *pCVar1;
  
  pCVar1 = CMAC_CTX_new();
  *(CMAC_CTX **)(param_1 + 0x14) = pCVar1;
  if (pCVar1 != (CMAC_CTX *)0x0) {
    *(undefined4 *)(param_1 + 0x24) = 0;
    return 1;
  }
  return 0;
}

