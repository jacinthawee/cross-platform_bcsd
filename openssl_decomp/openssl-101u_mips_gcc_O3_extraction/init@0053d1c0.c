
int init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0053d1cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_MDC2_Init_006a8acc)(*(undefined4 *)(ctx + 0xc));
  return iVar1;
}

