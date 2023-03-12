
X509_REQ * d2i_X509_REQ_bio(BIO *bp,X509_REQ **req)

{
  X509_REQ *pXVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00585264. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509_REQ *)(*(code *)PTR_ASN1_item_d2i_bio_006a8c64)(PTR_X509_REQ_it_006aa0c4,bp,req);
  return pXVar1;
}

