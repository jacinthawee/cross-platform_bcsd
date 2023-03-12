
int i2d_PKCS12_fp(FILE *fp,PKCS12 *p12)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005aab1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_fp_006a8fa0)(PTR_PKCS12_it_006a9244,fp,p12);
  return iVar1;
}

