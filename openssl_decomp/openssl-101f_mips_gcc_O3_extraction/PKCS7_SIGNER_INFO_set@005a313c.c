
int PKCS7_SIGNER_INFO_set(PKCS7_SIGNER_INFO *p7i,X509 *x509,EVP_PKEY *pkey,EVP_MD *dgst)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  ASN1_INTEGER *pAVar4;
  undefined4 uVar5;
  X509_ALGOR *pXVar6;
  PKCS7_ISSUER_AND_SERIAL *pPVar7;
  code *pcVar8;
  
  iVar2 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(p7i->version,1);
  if (iVar2 == 0) {
    return 0;
  }
  pPVar7 = p7i->issuer_and_serial;
  uVar3 = (*(code *)PTR_X509_get_issuer_name_006a87d0)(x509);
  iVar2 = (*(code *)PTR_X509_NAME_set_006aa048)(pPVar7,uVar3);
  if (iVar2 == 0) {
    return 0;
  }
  (*(code *)PTR_ASN1_STRING_free_006a98bc)(p7i->issuer_and_serial->serial);
  pPVar7 = p7i->issuer_and_serial;
  uVar3 = (*(code *)PTR_X509_get_serialNumber_006a809c)(x509);
  pAVar4 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_STRING_dup_006a9ddc)(uVar3);
  pPVar7->serial = pAVar4;
  if (pAVar4 == (ASN1_INTEGER *)0x0) {
    return 0;
  }
  (*(code *)PTR_CRYPTO_add_lock_006a9080)(&pkey->references,1,10,"pk7_lib.c",0x182);
  puVar1 = PTR_EVP_MD_type_006a84cc;
  pXVar6 = p7i->digest_alg;
  p7i->pkey = pkey;
  uVar3 = (*(code *)puVar1)(dgst);
  uVar3 = (*(code *)PTR_OBJ_nid2obj_006a8240)(uVar3);
  (*(code *)PTR_X509_ALGOR_set0_006a9e04)(pXVar6,uVar3,5,0);
  if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
     (pcVar8 = *(code **)(pkey->ameth + 0x58), pcVar8 != (code *)0x0)) {
    iVar2 = (*pcVar8)(pkey,1,0,p7i);
    if (0 < iVar2) {
      return 1;
    }
    if (iVar2 != -2) {
      uVar5 = 0x93;
      uVar3 = 0x193;
      goto LAB_005a32d0;
    }
  }
  uVar5 = 0x94;
  uVar3 = 0x198;
LAB_005a32d0:
  (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x81,uVar5,"pk7_lib.c",uVar3);
  return 0;
}

