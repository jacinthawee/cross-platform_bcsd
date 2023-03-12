
X509_CRL * d2i_X509_CRL_fp(FILE *fp,X509_CRL **crl)

{
  X509_CRL *pXVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0058514c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509_CRL *)(*(code *)PTR_ASN1_item_d2i_fp_006aa0b0)(PTR_X509_CRL_it_006aa0bc,fp,crl);
  return pXVar1;
}

