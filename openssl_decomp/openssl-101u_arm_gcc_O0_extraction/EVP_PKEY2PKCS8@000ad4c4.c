
PKCS8_PRIV_KEY_INFO * EVP_PKEY2PKCS8(EVP_PKEY *pkey)

{
  PKCS8_PRIV_KEY_INFO *a;
  int iVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  code *pcVar3;
  ASN1_STRING *pAVar4;
  undefined4 in_stack_ffffffe8;
  undefined4 in_stack_ffffffec;
  
  a = PKCS8_PRIV_KEY_INFO_new();
  if (a == (PKCS8_PRIV_KEY_INFO *)0x0) {
    ERR_put_error(6,0x71,0x41,"evp_pkey.c",0x77);
    return (PKCS8_PRIV_KEY_INFO *)0x0;
  }
  pEVar2 = pkey->ameth;
  a->broken = 0;
  if (pEVar2 == (EVP_PKEY_ASN1_METHOD *)0x0) {
    ERR_put_error(6,0x71,0x76,"evp_pkey.c",0x89);
  }
  else {
    pcVar3 = *(code **)(pEVar2 + 0x28);
    if (pcVar3 == (code *)0x0) {
      ERR_put_error(6,0x71,0x90,"evp_pkey.c",0x84);
    }
    else {
      iVar1 = (*pcVar3)(a,pkey);
      if (iVar1 != 0) {
        pAVar4 = (a->pkey->value).asn1_string;
        RAND_add(pAVar4->data,pAVar4->length,(double)CONCAT44(in_stack_ffffffec,in_stack_ffffffe8));
        return a;
      }
      ERR_put_error(6,0x71,0x92,"evp_pkey.c",0x80);
    }
  }
  PKCS8_PRIV_KEY_INFO_free(a);
  return (PKCS8_PRIV_KEY_INFO *)0x0;
}

