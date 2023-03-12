
int EC_POINT_mul(EC_GROUP *group,EC_POINT *r,BIGNUM *n,EC_POINT *q,BIGNUM *m,BN_CTX *ctx)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  piVar3 = *(int **)PTR___stack_chk_guard_006a9ae8;
  if (q == (EC_POINT *)0x0) {
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)group + 0x78);
  }
  else {
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)group + 0x78);
  }
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    iVar2 = ec_wNAF_mul();
  }
  else {
    iVar2 = (*UNRECOVERED_JUMPTABLE)();
  }
  if (piVar3 == *(int **)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (*(int *)(*piVar3 + 0x78) == 0) {
    iVar2 = ec_wNAF_precompute_mult();
    return iVar2;
  }
  UNRECOVERED_JUMPTABLE = *(code **)(*piVar3 + 0x7c);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00503220. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*UNRECOVERED_JUMPTABLE)();
    return iVar2;
  }
  return 1;
}

