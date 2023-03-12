
X509 * d2i_X509_bio(BIO *bp,X509 **x509)

{
  X509 *pXVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00585114. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509 *)(*(code *)PTR_ASN1_item_d2i_bio_006a8c64)(PTR_X509_it_006aa0b4,bp,x509);
  return pXVar1;
}

