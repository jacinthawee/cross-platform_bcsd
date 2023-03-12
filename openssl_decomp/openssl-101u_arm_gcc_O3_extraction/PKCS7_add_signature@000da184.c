
PKCS7_SIGNER_INFO * PKCS7_add_signature(PKCS7 *p7,X509 *x509,EVP_PKEY *pkey,EVP_MD *dgst)

{
  PKCS7_SIGNER_INFO *p7i;
  int iVar1;
  X509_NAME *name;
  ASN1_INTEGER *a;
  ASN1_STRING *pAVar2;
  ASN1_OBJECT *aobj;
  char *name_00;
  X509_ALGOR *alg;
  code *pcVar3;
  PKCS7_ISSUER_AND_SERIAL *pPVar4;
  int local_24 [2];
  
  if (dgst == (EVP_MD *)0x0) {
    iVar1 = EVP_PKEY_get_default_digest_nid(pkey,local_24);
    if (iVar1 < 1) {
      return (PKCS7_SIGNER_INFO *)0x0;
    }
    name_00 = OBJ_nid2sn(local_24[0]);
    dgst = EVP_get_digestbyname(name_00);
    if (dgst == (EVP_MD *)0x0) {
      ERR_put_error(0x21,0x83,0x97,"pk7_lib.c",0x19c);
      return (PKCS7_SIGNER_INFO *)0x0;
    }
  }
  p7i = PKCS7_SIGNER_INFO_new();
  if (p7i == (PKCS7_SIGNER_INFO *)0x0) {
    return (PKCS7_SIGNER_INFO *)0x0;
  }
  iVar1 = ASN1_INTEGER_set(p7i->version,1);
  if (iVar1 != 0) {
    pPVar4 = p7i->issuer_and_serial;
    name = X509_get_issuer_name(x509);
    iVar1 = X509_NAME_set(&pPVar4->issuer,name);
    if (iVar1 != 0) {
      ASN1_STRING_free(p7i->issuer_and_serial->serial);
      pPVar4 = p7i->issuer_and_serial;
      a = X509_get_serialNumber(x509);
      pAVar2 = ASN1_STRING_dup(a);
      pPVar4->serial = pAVar2;
      if (pAVar2 != (ASN1_STRING *)0x0) {
        CRYPTO_add_lock(&pkey->references,1,10,"pk7_lib.c",0x179);
        p7i->pkey = pkey;
        alg = p7i->digest_alg;
        iVar1 = EVP_MD_type(dgst);
        aobj = OBJ_nid2obj(iVar1);
        X509_ALGOR_set0(alg,aobj,5,(void *)0x0);
        if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
           (pcVar3 = *(code **)(pkey->ameth + 0x58), pcVar3 != (code *)0x0)) {
          iVar1 = (*pcVar3)(pkey,1,0,p7i);
          if (0 < iVar1) {
            iVar1 = PKCS7_add_signer(p7,p7i);
            if (iVar1 != 0) {
              return p7i;
            }
            goto LAB_000da1aa;
          }
          if (iVar1 != -2) {
            ERR_put_error(0x21,0x81,0x93,"pk7_lib.c",0x187);
            goto LAB_000da1aa;
          }
        }
        ERR_put_error(0x21,0x81,0x94,"pk7_lib.c",0x18c);
      }
    }
  }
LAB_000da1aa:
  PKCS7_SIGNER_INFO_free(p7i);
  return (PKCS7_SIGNER_INFO *)0x0;
}

