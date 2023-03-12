
int i2d_GENERAL_NAMES(GENERAL_NAMES *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0058c2c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a8678)(a,out,GENERAL_NAMES_it);
  return iVar1;
}

