
int i2d_PKCS7_fp(FILE *fp,PKCS7 *p7)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005851d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_fp_006aa0b8)(PTR_PKCS7_it_006aa0c0,fp,p7);
  return iVar1;
}

