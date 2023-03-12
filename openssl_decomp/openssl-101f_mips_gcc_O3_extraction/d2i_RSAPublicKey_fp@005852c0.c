
RSA * d2i_RSAPublicKey_fp(FILE *fp,RSA **rsa)

{
  RSA *pRVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005852d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pRVar1 = (RSA *)(*(code *)PTR_ASN1_item_d2i_fp_006aa0b0)(PTR_RSAPublicKey_it_006aa0cc,fp,rsa);
  return pRVar1;
}

