
int i2d_PKCS7_ISSUER_AND_SERIAL(PKCS7_ISSUER_AND_SERIAL *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0059f434. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a8678)(a,out,PKCS7_ISSUER_AND_SERIAL_it);
  return iVar1;
}

