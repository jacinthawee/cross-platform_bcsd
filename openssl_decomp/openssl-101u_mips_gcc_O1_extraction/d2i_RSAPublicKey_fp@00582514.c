
RSA * d2i_RSAPublicKey_fp(FILE *fp,RSA **rsa)

{
  RSA *pRVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582528. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pRVar1 = (RSA *)(*(code *)PTR_ASN1_item_d2i_fp_006a8f98)(PTR_RSAPublicKey_it_006a8fb4,fp,rsa);
  return pRVar1;
}

