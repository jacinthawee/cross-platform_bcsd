
RSA * d2i_RSA_PUBKEY_fp(FILE *fp,RSA **rsa)

{
  RSA *pRVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582548. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pRVar1 = (RSA *)(*(code *)PTR_ASN1_d2i_fp_006a8fb8)
                            (PTR_RSA_new_006a787c,PTR_d2i_RSA_PUBKEY_006a8e64,fp,rsa);
  return pRVar1;
}

