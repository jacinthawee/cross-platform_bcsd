
undefined4 pkey_cmac_keygen(int param_1,EVP_PKEY *param_2)

{
  CMAC_CTX *out;
  undefined4 uVar1;
  int iVar2;
  
  out = CMAC_CTX_new();
  uVar1 = 0;
  if (out != (CMAC_CTX *)0x0) {
    iVar2 = CMAC_CTX_copy(out,*(CMAC_CTX **)(param_1 + 0x14));
    if (iVar2 == 0) {
      CMAC_CTX_free(out);
      return 0;
    }
    EVP_PKEY_assign(param_2,0x37e,out);
    uVar1 = 1;
  }
  return uVar1;
}

