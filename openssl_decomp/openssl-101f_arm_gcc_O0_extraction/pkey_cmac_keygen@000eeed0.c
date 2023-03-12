
CMAC_CTX * pkey_cmac_keygen(int param_1,EVP_PKEY *param_2)

{
  CMAC_CTX *out;
  int iVar1;
  CMAC_CTX *pCVar2;
  
  out = CMAC_CTX_new();
  pCVar2 = out;
  if (out != (CMAC_CTX *)0x0) {
    iVar1 = CMAC_CTX_copy(out,*(CMAC_CTX **)(param_1 + 0x14));
    if (iVar1 == 0) {
      CMAC_CTX_free(out);
      return (CMAC_CTX *)0x0;
    }
    pCVar2 = (CMAC_CTX *)0x1;
    EVP_PKEY_assign(param_2,0x37e,out);
  }
  return pCVar2;
}

