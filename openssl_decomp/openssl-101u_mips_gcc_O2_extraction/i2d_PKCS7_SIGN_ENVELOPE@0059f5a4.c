
int i2d_PKCS7_SIGN_ENVELOPE(PKCS7_SIGN_ENVELOPE *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0059f5b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a8678)(a,out,PKCS7_SIGN_ENVELOPE_it);
  return iVar1;
}

