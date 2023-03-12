
int i2d_BASIC_CONSTRAINTS(BASIC_CONSTRAINTS *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006110f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a979c)(a,out,BASIC_CONSTRAINTS_it);
  return iVar1;
}

