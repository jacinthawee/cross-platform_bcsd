
int EC_KEY_precompute_mult(EC_KEY *key,BN_CTX *ctx)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (*(int **)(key + 4) == (int *)0x0) {
    return 0;
  }
  iVar1 = **(int **)(key + 4);
  if (*(int *)(iVar1 + 0x78) != 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x7c);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00505584. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    return 1;
  }
  iVar1 = ec_wNAF_precompute_mult();
  return iVar1;
}

