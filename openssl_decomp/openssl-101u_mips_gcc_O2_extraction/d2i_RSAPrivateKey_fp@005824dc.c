
RSA * d2i_RSAPrivateKey_fp(FILE *fp,RSA **rsa)

{
  RSA *pRVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005824f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pRVar1 = (RSA *)(*(code *)PTR_ASN1_item_d2i_fp_006a8f98)(PTR_RSAPrivateKey_it_006a8fb0,fp,rsa);
  return pRVar1;
}

