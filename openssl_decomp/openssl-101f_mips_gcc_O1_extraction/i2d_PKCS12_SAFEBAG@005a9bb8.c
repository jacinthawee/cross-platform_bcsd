
int i2d_PKCS12_SAFEBAG(PKCS12_SAFEBAG *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005a9bc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a979c)(a,out,PKCS12_SAFEBAG_it);
  return iVar1;
}
