
X509 * d2i_X509_bio(BIO *bp,X509 **x509)

{
  X509 *pXVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582368. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509 *)(*(code *)PTR_ASN1_item_d2i_bio_006a7b78)(PTR_X509_it_006a8f9c,bp,x509);
  return pXVar1;
}

