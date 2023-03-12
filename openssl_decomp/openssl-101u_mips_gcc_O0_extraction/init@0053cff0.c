
int init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0053cffc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_MD5_Init_006a8160)(*(undefined4 *)(ctx + 0xc));
  return iVar1;
}

