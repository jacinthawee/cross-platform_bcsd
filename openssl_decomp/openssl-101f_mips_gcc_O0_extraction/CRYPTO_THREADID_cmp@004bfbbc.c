
int CRYPTO_THREADID_cmp(CRYPTO_THREADID *a,CRYPTO_THREADID *b)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004bfbc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_memcmp_006aabd8)(a,b,8);
  return iVar1;
}

