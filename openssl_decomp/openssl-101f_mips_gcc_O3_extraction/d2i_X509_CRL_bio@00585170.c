
X509_CRL * d2i_X509_CRL_bio(BIO *bp,X509_CRL **crl)

{
  X509_CRL *pXVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00585184. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509_CRL *)(*(code *)PTR_ASN1_item_d2i_bio_006a8c64)(PTR_X509_CRL_it_006aa0bc,bp,crl);
  return pXVar1;
}

