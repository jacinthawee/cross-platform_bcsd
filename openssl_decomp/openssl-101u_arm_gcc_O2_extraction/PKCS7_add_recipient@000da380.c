
PKCS7_RECIP_INFO * PKCS7_add_recipient(PKCS7 *p7,X509 *x509)

{
  PKCS7_RECIP_INFO *a;
  int iVar1;
  X509_NAME *name;
  ASN1_INTEGER *a_00;
  ASN1_STRING *pAVar2;
  EVP_PKEY *pkey;
  _STACK *st;
  PKCS7_ISSUER_AND_SERIAL *pPVar3;
  code *pcVar4;
  
  a = PKCS7_RECIP_INFO_new();
  if (a == (PKCS7_RECIP_INFO *)0x0) {
    return (PKCS7_RECIP_INFO *)0x0;
  }
  iVar1 = ASN1_INTEGER_set(a->version,0);
  if (iVar1 == 0) goto LAB_000da39c;
  pPVar3 = a->issuer_and_serial;
  name = X509_get_issuer_name(x509);
  iVar1 = X509_NAME_set(&pPVar3->issuer,name);
  if (iVar1 == 0) goto LAB_000da39c;
  ASN1_STRING_free(a->issuer_and_serial->serial);
  pPVar3 = a->issuer_and_serial;
  a_00 = X509_get_serialNumber(x509);
  pAVar2 = ASN1_STRING_dup(a_00);
  pPVar3->serial = pAVar2;
  if (pAVar2 == (ASN1_STRING *)0x0) goto LAB_000da39c;
  pkey = X509_get_pubkey(x509);
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0x21,0x82,0x96,"pk7_lib.c",0x217);
    goto LAB_000da39c;
  }
  if ((pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) ||
     (pcVar4 = *(code **)(pkey->ameth + 0x58), pcVar4 == (code *)0x0)) {
    iVar1 = 0x217;
LAB_000da458:
    ERR_put_error(0x21,0x82,0x96,"pk7_lib.c",iVar1);
  }
  else {
    iVar1 = (*pcVar4)(pkey,2,0,a);
    if (iVar1 == -2) {
      iVar1 = 0x21e;
      goto LAB_000da458;
    }
    if (0 < iVar1) {
      EVP_PKEY_free(pkey);
      CRYPTO_add_lock(&x509->references,1,3,"pk7_lib.c",0x229);
      a->cert = x509;
      iVar1 = OBJ_obj2nid(p7->type);
      if (iVar1 == 0x17) {
        st = (_STACK *)((p7->d).sign)->md_algs;
      }
      else {
        if (iVar1 != 0x18) {
          ERR_put_error(0x21,0x66,0x71,"pk7_lib.c",0x1fb);
          goto LAB_000da39c;
        }
        st = (_STACK *)((p7->d).signed_and_enveloped)->recipientinfo;
      }
      iVar1 = sk_push(st,a);
      if (iVar1 != 0) {
        return a;
      }
      goto LAB_000da39c;
    }
    ERR_put_error(0x21,0x82,0x95,"pk7_lib.c",0x223);
  }
  EVP_PKEY_free(pkey);
LAB_000da39c:
  PKCS7_RECIP_INFO_free(a);
  return (PKCS7_RECIP_INFO *)0x0;
}

