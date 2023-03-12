
int i2d_EXTENDED_KEY_USAGE(EXTENDED_KEY_USAGE *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006116e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a979c)(a,out,EXTENDED_KEY_USAGE_it);
  return iVar1;
}

