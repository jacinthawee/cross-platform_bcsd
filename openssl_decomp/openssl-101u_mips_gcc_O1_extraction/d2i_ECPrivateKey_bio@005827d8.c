
EC_KEY * d2i_ECPrivateKey_bio(BIO *bp,EC_KEY **eckey)

{
  EC_KEY *pEVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005827f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pEVar1 = (EC_KEY *)
           (*(code *)PTR_ASN1_d2i_bio_006a71c4)
                     (PTR_EC_KEY_new_006a71a8,PTR_d2i_ECPrivateKey_006a8e1c,bp,eckey);
  return pEVar1;
}

