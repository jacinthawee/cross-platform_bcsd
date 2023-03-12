
int i2d_PKCS7_NDEF(PKCS7 *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0059f328. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_ndef_i2d_006a910c)(a,out,PKCS7_it);
  return iVar1;
}

