
int init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0054045c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_RIPEMD160_Init_006a9bf4)(*(undefined4 *)(ctx + 0xc));
  return iVar1;
}

