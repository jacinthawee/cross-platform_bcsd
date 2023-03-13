
EC_KEY * d2i_ECPrivateKey_fp(FILE *fp,EC_KEY **eckey)

{
  EC_KEY *pEVar1;
  
  pEVar1 = (EC_KEY *)ASN1_d2i_fp(EC_KEY_new,d2i_ECPrivateKey,fp,eckey);
  return pEVar1;
}

