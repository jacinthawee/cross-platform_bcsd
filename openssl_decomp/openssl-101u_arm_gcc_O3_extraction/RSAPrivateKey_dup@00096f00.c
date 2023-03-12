
RSA * RSAPrivateKey_dup(RSA *rsa)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)ASN1_item_dup((ASN1_ITEM *)PTR_RSAPrivateKey_it_00096f08,rsa);
  return pRVar1;
}

