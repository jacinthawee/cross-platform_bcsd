
PKCS7_RECIP_INFO * PKCS7_add_recipient(PKCS7 *p7,X509 *x509)

{
  PKCS7_ISSUER_AND_SERIAL *pPVar1;
  code *pcVar2;
  PKCS7_RECIP_INFO *a;
  int iVar3;
  X509_NAME *name;
  ASN1_INTEGER *a_00;
  ASN1_STRING *pAVar4;
  EVP_PKEY *pkey;
  _STACK *st;
  
  a = PKCS7_RECIP_INFO_new();
  if (a == (PKCS7_RECIP_INFO *)0x0) {
    return (PKCS7_RECIP_INFO *)0x0;
  }
  iVar3 = ASN1_INTEGER_set(a->version,0);
  if (iVar3 == 0) goto LAB_0817d5a5;
  name = X509_get_issuer_name(x509);
  iVar3 = X509_NAME_set(&a->issuer_and_serial->issuer,name);
  if (iVar3 == 0) goto LAB_0817d5a5;
  ASN1_STRING_free(a->issuer_and_serial->serial);
  pPVar1 = a->issuer_and_serial;
  a_00 = X509_get_serialNumber(x509);
  pAVar4 = ASN1_STRING_dup(a_00);
  pPVar1->serial = pAVar4;
  if (pAVar4 == (ASN1_STRING *)0x0) goto LAB_0817d5a5;
  pkey = X509_get_pubkey(x509);
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0x21,0x82,0x96,"pk7_lib.c",0x225);
    goto LAB_0817d5a5;
  }
  if ((pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) ||
     (pcVar2 = *(code **)(pkey->ameth + 0x58), pcVar2 == (code *)0x0)) {
    iVar3 = 0x225;
LAB_0817d6d8:
    ERR_put_error(0x21,0x82,0x96,"pk7_lib.c",iVar3);
  }
  else {
    iVar3 = (*pcVar2)(pkey,2,0,a);
    if (iVar3 == -2) {
      iVar3 = 0x22e;
      goto LAB_0817d6d8;
    }
    if (0 < iVar3) {
      EVP_PKEY_free(pkey);
      CRYPTO_add_lock(&x509->references,1,3,"pk7_lib.c",0x23a);
      a->cert = x509;
      iVar3 = OBJ_obj2nid(p7->type);
      if (iVar3 == 0x17) {
        st = (_STACK *)((p7->d).sign)->md_algs;
      }
      else {
        if (iVar3 != 0x18) {
          ERR_put_error(0x21,0x66,0x71,"pk7_lib.c",0x208);
          goto LAB_0817d5a5;
        }
        st = (_STACK *)((p7->d).signed_and_enveloped)->recipientinfo;
      }
      iVar3 = sk_push(st,a);
      if (iVar3 != 0) {
        return a;
      }
      goto LAB_0817d5a5;
    }
    ERR_put_error(0x21,0x82,0x95,"pk7_lib.c",0x234);
  }
  EVP_PKEY_free(pkey);
LAB_0817d5a5:
  PKCS7_RECIP_INFO_free(a);
  return (PKCS7_RECIP_INFO *)0x0;
}

