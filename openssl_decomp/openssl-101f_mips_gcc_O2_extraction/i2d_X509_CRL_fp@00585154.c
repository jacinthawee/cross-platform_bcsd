
int i2d_X509_CRL_fp(FILE *fp,X509_CRL *crl)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00585168. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_fp_006aa0b8)(PTR_X509_CRL_it_006aa0bc,fp,crl);
  return iVar1;
}

