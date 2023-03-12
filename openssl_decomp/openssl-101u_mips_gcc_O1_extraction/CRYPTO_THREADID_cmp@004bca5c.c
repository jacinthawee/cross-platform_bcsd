
int CRYPTO_THREADID_cmp(CRYPTO_THREADID *a,CRYPTO_THREADID *b)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004bca68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_memcmp_006a9ad0)(a,b,8);
  return iVar1;
}

