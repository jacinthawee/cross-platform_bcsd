
RSA * RSAPublicKey_dup(RSA *rsa)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)ASN1_item_dup((ASN1_ITEM *)PTR_RSAPublicKey_it_00098780,rsa);
  return pRVar1;
}

