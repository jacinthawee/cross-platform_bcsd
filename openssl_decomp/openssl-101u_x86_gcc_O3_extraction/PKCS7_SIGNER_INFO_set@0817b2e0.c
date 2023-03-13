
int PKCS7_SIGNER_INFO_set(PKCS7_SIGNER_INFO *p7i,X509 *x509,EVP_PKEY *pkey,EVP_MD *dgst)

{
  PKCS7_ISSUER_AND_SERIAL *pPVar1;
  code *pcVar2;
  int iVar3;
  X509_NAME *name;
  ASN1_INTEGER *a;
  ASN1_STRING *pAVar4;
  ASN1_OBJECT *aobj;
  int line;
  
  iVar3 = ASN1_INTEGER_set(p7i->version,1);
  if (iVar3 == 0) {
    return 0;
  }
  name = X509_get_issuer_name(x509);
  iVar3 = X509_NAME_set(&p7i->issuer_and_serial->issuer,name);
  if (iVar3 == 0) {
    return 0;
  }
  ASN1_STRING_free(p7i->issuer_and_serial->serial);
  pPVar1 = p7i->issuer_and_serial;
  a = X509_get_serialNumber(x509);
  pAVar4 = ASN1_STRING_dup(a);
  pPVar1->serial = pAVar4;
  if (pAVar4 == (ASN1_STRING *)0x0) {
    return 0;
  }
  CRYPTO_add_lock(&pkey->references,1,10,"pk7_lib.c",0x179);
  p7i->pkey = pkey;
  iVar3 = EVP_MD_type(dgst);
  aobj = OBJ_nid2obj(iVar3);
  X509_ALGOR_set0(p7i->digest_alg,aobj,5,(void *)0x0);
  if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
     (pcVar2 = *(code **)(pkey->ameth + 0x58), pcVar2 != (code *)0x0)) {
    iVar3 = (*pcVar2)(pkey,1,0,p7i);
    if (0 < iVar3) {
      return 1;
    }
    if (iVar3 != -2) {
      line = 0x187;
      iVar3 = 0x93;
      goto LAB_0817b3fa;
    }
  }
  line = 0x18c;
  iVar3 = 0x94;
LAB_0817b3fa:
  ERR_put_error(0x21,0x81,iVar3,"pk7_lib.c",line);
  return 0;
}

