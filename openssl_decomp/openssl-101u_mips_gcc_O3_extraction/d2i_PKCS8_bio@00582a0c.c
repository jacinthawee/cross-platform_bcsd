
X509_SIG * d2i_PKCS8_bio(BIO *bp,X509_SIG **p8)

{
  X509_SIG *pXVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582a24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509_SIG *)
           (*(code *)PTR_ASN1_d2i_bio_006a71c4)
                     (PTR_X509_SIG_new_006a8fcc,PTR_d2i_X509_SIG_006a8738,bp,p8);
  return pXVar1;
}
