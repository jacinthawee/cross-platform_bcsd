
int i2d_X509_fp(FILE *fp,X509 *x509)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005850f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_fp_006aa0b8)(PTR_X509_it_006aa0b4,fp,x509);
  return iVar1;
}

