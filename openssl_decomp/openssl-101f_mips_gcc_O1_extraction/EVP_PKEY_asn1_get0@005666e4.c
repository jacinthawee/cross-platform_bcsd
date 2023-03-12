
EVP_PKEY_ASN1_METHOD * EVP_PKEY_asn1_get0(int idx)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  
  if (idx < 0) {
    return (EVP_PKEY_ASN1_METHOD *)0x0;
  }
  if (idx < 0xb) {
    return *(EVP_PKEY_ASN1_METHOD **)(standard_methods + idx * 4);
  }
                    /* WARNING: Could not recover jumptable at 0x00566720. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pEVar1 = (EVP_PKEY_ASN1_METHOD *)(*(code *)PTR_sk_value_006a7f24)(app_methods,idx + -0xb);
  return pEVar1;
}

