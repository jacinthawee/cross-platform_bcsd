
EC_KEY * d2i_EC_PUBKEY_bio(BIO *bp,EC_KEY **eckey)

{
  EC_KEY *pEVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00585560. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pEVar1 = (EC_KEY *)
           (*(code *)PTR_ASN1_d2i_bio_006a82c4)
                     (PTR_EC_KEY_new_006a82a8,PTR_d2i_EC_PUBKEY_006a9f98,bp,eckey);
  return pEVar1;
}

