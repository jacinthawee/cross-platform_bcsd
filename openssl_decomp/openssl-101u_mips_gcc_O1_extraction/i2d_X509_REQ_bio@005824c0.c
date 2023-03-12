
int i2d_X509_REQ_bio(BIO *bp,X509_REQ *req)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005824d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_bio_006a7720)(PTR_X509_REQ_it_006a8fac,bp,req);
  return iVar1;
}

