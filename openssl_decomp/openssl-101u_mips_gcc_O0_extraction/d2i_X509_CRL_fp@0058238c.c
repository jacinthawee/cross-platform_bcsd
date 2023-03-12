
X509_CRL * d2i_X509_CRL_fp(FILE *fp,X509_CRL **crl)

{
  X509_CRL *pXVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005823a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509_CRL *)(*(code *)PTR_ASN1_item_d2i_fp_006a8f98)(PTR_X509_CRL_it_006a8fa4,fp,crl);
  return pXVar1;
}

