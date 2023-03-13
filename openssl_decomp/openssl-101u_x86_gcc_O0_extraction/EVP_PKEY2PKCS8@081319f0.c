
PKCS8_PRIV_KEY_INFO * EVP_PKEY2PKCS8(EVP_PKEY *pkey)

{
  code *pcVar1;
  ASN1_STRING *pAVar2;
  PKCS8_PRIV_KEY_INFO *a;
  int iVar3;
  
  a = PKCS8_PRIV_KEY_INFO_new();
  if (a == (PKCS8_PRIV_KEY_INFO *)0x0) {
    ERR_put_error(6,0x71,0x41,"evp_pkey.c",0x77);
    return (PKCS8_PRIV_KEY_INFO *)0x0;
  }
  a->broken = 0;
  if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
    ERR_put_error(6,0x71,0x76,"evp_pkey.c",0x89);
  }
  else {
    pcVar1 = *(code **)(pkey->ameth + 0x28);
    if (pcVar1 == (code *)0x0) {
      ERR_put_error(6,0x71,0x90,"evp_pkey.c",0x84);
    }
    else {
      iVar3 = (*pcVar1)(a,pkey);
      if (iVar3 != 0) {
        pAVar2 = (a->pkey->value).asn1_string;
        RAND_add(pAVar2->data,pAVar2->length,0.0);
        return a;
      }
      ERR_put_error(6,0x71,0x92,"evp_pkey.c",0x80);
    }
  }
  PKCS8_PRIV_KEY_INFO_free(a);
  return (PKCS8_PRIV_KEY_INFO *)0x0;
}

