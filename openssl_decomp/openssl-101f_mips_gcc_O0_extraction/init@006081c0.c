
int init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006081cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_WHIRLPOOL_Init_006aa8ec)(*(undefined4 *)(ctx + 0xc));
  return iVar1;
}

