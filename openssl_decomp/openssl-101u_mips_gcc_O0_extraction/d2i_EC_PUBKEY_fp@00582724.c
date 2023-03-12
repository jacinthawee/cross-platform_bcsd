
EC_KEY * d2i_EC_PUBKEY_fp(FILE *fp,EC_KEY **eckey)

{
  EC_KEY *pEVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0058273c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pEVar1 = (EC_KEY *)
           (*(code *)PTR_ASN1_d2i_fp_006a8fb8)
                     (PTR_EC_KEY_new_006a71a8,PTR_d2i_EC_PUBKEY_006a8e7c,fp,eckey);
  return pEVar1;
}

