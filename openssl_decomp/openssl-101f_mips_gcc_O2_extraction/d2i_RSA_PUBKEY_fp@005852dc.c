
RSA * d2i_RSA_PUBKEY_fp(FILE *fp,RSA **rsa)

{
  RSA *pRVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005852f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pRVar1 = (RSA *)(*(code *)PTR_ASN1_d2i_fp_006aa0d0)
                            (PTR_RSA_new_006a8964,PTR_d2i_RSA_PUBKEY_006a9f80,fp,rsa);
  return pRVar1;
}

