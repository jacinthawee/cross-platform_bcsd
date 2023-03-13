
PKCS7_SIGNER_INFO * PKCS7_add_signature(PKCS7 *p7,X509 *x509,EVP_PKEY *pkey,EVP_MD *dgst)

{
  PKCS7_ISSUER_AND_SERIAL *pPVar1;
  code *pcVar2;
  PKCS7_SIGNER_INFO *p7i;
  int iVar3;
  X509_NAME *name;
  ASN1_INTEGER *a;
  ASN1_STRING *pAVar4;
  ASN1_OBJECT *aobj;
  char *name_00;
  int in_GS_OFFSET;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (dgst == (EVP_MD *)0x0) {
    iVar3 = EVP_PKEY_get_default_digest_nid(pkey,&local_24);
    if (0 < iVar3) {
      name_00 = OBJ_nid2sn(local_24);
      dgst = EVP_get_digestbyname(name_00);
      if (dgst != (EVP_MD *)0x0) goto LAB_0817b43f;
      ERR_put_error(0x21,0x83,0x97,"pk7_lib.c",0x19c);
    }
  }
  else {
LAB_0817b43f:
    p7i = PKCS7_SIGNER_INFO_new();
    if (p7i != (PKCS7_SIGNER_INFO *)0x0) {
      iVar3 = ASN1_INTEGER_set(p7i->version,1);
      if (iVar3 != 0) {
        name = X509_get_issuer_name(x509);
        iVar3 = X509_NAME_set(&p7i->issuer_and_serial->issuer,name);
        if (iVar3 != 0) {
          ASN1_STRING_free(p7i->issuer_and_serial->serial);
          pPVar1 = p7i->issuer_and_serial;
          a = X509_get_serialNumber(x509);
          pAVar4 = ASN1_STRING_dup(a);
          pPVar1->serial = pAVar4;
          if (pAVar4 != (ASN1_STRING *)0x0) {
            CRYPTO_add_lock(&pkey->references,1,10,"pk7_lib.c",0x179);
            p7i->pkey = pkey;
            iVar3 = EVP_MD_type(dgst);
            aobj = OBJ_nid2obj(iVar3);
            X509_ALGOR_set0(p7i->digest_alg,aobj,5,(void *)0x0);
            if ((pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) ||
               (pcVar2 = *(code **)(pkey->ameth + 0x58), pcVar2 == (code *)0x0)) {
LAB_0817b5c5:
              ERR_put_error(0x21,0x81,0x94,"pk7_lib.c",0x18c);
            }
            else {
              iVar3 = (*pcVar2)(pkey,1,0,p7i);
              if (iVar3 < 1) {
                if (iVar3 == -2) goto LAB_0817b5c5;
                ERR_put_error(0x21,0x81,0x93,"pk7_lib.c",0x187);
              }
              else {
                iVar3 = PKCS7_add_signer(p7,p7i);
                if (iVar3 != 0) goto LAB_0817b46b;
              }
            }
          }
        }
      }
      PKCS7_SIGNER_INFO_free(p7i);
    }
  }
  p7i = (PKCS7_SIGNER_INFO *)0x0;
LAB_0817b46b:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return p7i;
}

