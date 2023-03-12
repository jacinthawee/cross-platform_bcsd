
int i2d_X509_CRL_fp(FILE *fp,X509_CRL *crl)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005823bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_fp_006a8fa0)(PTR_X509_CRL_it_006a8fa4,fp,crl);
  return iVar1;
}

