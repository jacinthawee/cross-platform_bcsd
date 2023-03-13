
int PKCS7_RECIP_INFO_set(PKCS7_RECIP_INFO *p7i,X509 *x509)

{
  PKCS7_ISSUER_AND_SERIAL *pPVar1;
  code *pcVar2;
  int iVar3;
  X509_NAME *name;
  ASN1_INTEGER *a;
  ASN1_STRING *pAVar4;
  EVP_PKEY *pkey;
  
  iVar3 = ASN1_INTEGER_set(p7i->version,0);
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
  pkey = X509_get_pubkey(x509);
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0x21,0x82,0x96,"pk7_lib.c",0x217);
    return 0;
  }
  if ((pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) ||
     (pcVar2 = *(code **)(pkey->ameth + 0x58), pcVar2 == (code *)0x0)) {
    iVar3 = 0x217;
  }
  else {
    iVar3 = (*pcVar2)(pkey,2,0,p7i);
    if (iVar3 != -2) {
      if (0 < iVar3) {
        EVP_PKEY_free(pkey);
        CRYPTO_add_lock(&x509->references,1,3,"pk7_lib.c",0x229);
        p7i->cert = x509;
        return 1;
      }
      ERR_put_error(0x21,0x82,0x95,"pk7_lib.c",0x223);
      goto LAB_0817bb19;
    }
    iVar3 = 0x21e;
  }
  ERR_put_error(0x21,0x82,0x96,"pk7_lib.c",iVar3);
LAB_0817bb19:
  EVP_PKEY_free(pkey);
  return 0;
}

