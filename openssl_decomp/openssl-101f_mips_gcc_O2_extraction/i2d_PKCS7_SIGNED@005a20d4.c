
int i2d_PKCS7_SIGNED(PKCS7_SIGNED *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005a20e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a979c)(a,out,PKCS7_SIGNED_it);
  return iVar1;
}

