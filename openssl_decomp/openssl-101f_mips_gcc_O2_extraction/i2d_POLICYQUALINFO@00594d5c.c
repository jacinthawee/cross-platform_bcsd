
int i2d_POLICYQUALINFO(POLICYQUALINFO *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00594d6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a979c)(a,out,POLICYQUALINFO_it);
  return iVar1;
}
