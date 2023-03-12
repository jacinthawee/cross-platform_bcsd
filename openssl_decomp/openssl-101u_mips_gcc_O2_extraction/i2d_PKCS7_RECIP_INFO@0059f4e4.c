
int i2d_PKCS7_RECIP_INFO(PKCS7_RECIP_INFO *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0059f4f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a8678)(a,out,PKCS7_RECIP_INFO_it);
  return iVar1;
}

