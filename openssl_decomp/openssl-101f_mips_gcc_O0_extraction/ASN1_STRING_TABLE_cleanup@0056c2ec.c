
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ASN1_STRING_TABLE_cleanup(void)

{
  int iVar1;
  
  iVar1 = stable;
  if (stable != 0) {
    stable = 0;
                    /* WARNING: Could not recover jumptable at 0x0056c30c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_sk_pop_free_006a8158)(iVar1,st_free);
    return;
  }
  return;
}

