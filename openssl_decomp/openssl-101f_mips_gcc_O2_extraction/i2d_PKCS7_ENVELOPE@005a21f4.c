
int i2d_PKCS7_ENVELOPE(PKCS7_ENVELOPE *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005a2204. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a979c)(a,out,PKCS7_ENVELOPE_it);
  return iVar1;
}

