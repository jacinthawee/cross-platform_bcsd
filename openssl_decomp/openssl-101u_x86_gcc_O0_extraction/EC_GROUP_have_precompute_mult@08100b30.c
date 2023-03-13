
int EC_GROUP_have_precompute_mult(EC_GROUP *group)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  
  if (*(int *)(*(int *)group + 0x78) == 0) {
    iVar1 = ec_wNAF_have_precompute_mult();
    return iVar1;
  }
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)group + 0x80);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08100b4b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)();
    return iVar1;
  }
  return 0;
}

