
int init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005403bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_SHA1_Init_006a9288)(*(undefined4 *)(ctx + 0xc));
  return iVar1;
}
