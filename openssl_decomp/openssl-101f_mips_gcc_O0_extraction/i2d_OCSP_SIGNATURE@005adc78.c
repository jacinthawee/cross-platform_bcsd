
int i2d_OCSP_SIGNATURE(OCSP_SIGNATURE *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005adc88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a979c)(a,out,OCSP_SIGNATURE_it);
  return iVar1;
}

