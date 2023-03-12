
int i2d_POLICYINFO(POLICYINFO *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00594d24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a979c)(a,out,POLICYINFO_it);
  return iVar1;
}

