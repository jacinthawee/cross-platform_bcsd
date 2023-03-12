
int CMAC_resume(CMAC_CTX *ctx)

{
  int iVar1;
  
  if (*(int *)(ctx + 0x10c) != -1) {
    iVar1 = (*(code *)PTR_EVP_EncryptInit_ex_006a8b84)(ctx,0,0,0,ctx + 0xcc);
    return iVar1;
  }
  return 0;
}

