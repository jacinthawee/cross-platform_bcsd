
EVP_PKEY_ASN1_METHOD * EVP_PKEY_asn1_get0(int idx)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  
  if (idx < 0) {
    pEVar1 = (EVP_PKEY_ASN1_METHOD *)0x0;
  }
  else {
    if (10 < idx) {
      pEVar1 = (EVP_PKEY_ASN1_METHOD *)sk_value(app_methods,idx + -0xb);
      return pEVar1;
    }
    pEVar1 = *(EVP_PKEY_ASN1_METHOD **)(standard_methods + idx * 4);
  }
  return pEVar1;
}

