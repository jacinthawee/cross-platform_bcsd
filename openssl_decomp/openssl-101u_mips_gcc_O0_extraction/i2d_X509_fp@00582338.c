
int i2d_X509_fp(FILE *fp,X509 *x509)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0058234c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_fp_006a8fa0)(PTR_X509_it_006a8f9c,fp,x509);
  return iVar1;
}

