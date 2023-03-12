
int PKCS7_RECIP_INFO_set(PKCS7_RECIP_INFO *p7i,X509 *x509)

{
  int iVar1;
  undefined4 uVar2;
  ASN1_INTEGER *pAVar3;
  int iVar4;
  undefined4 uVar5;
  PKCS7_ISSUER_AND_SERIAL *pPVar6;
  code *pcVar7;
  
  iVar1 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(p7i->version,0);
  if (iVar1 != 0) {
    pPVar6 = p7i->issuer_and_serial;
    uVar2 = (*(code *)PTR_X509_get_issuer_name_006a87d0)(x509);
    iVar1 = (*(code *)PTR_X509_NAME_set_006aa048)(pPVar6,uVar2);
    if (iVar1 != 0) {
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(p7i->issuer_and_serial->serial);
      pPVar6 = p7i->issuer_and_serial;
      uVar2 = (*(code *)PTR_X509_get_serialNumber_006a809c)(x509);
      pAVar3 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_STRING_dup_006a9ddc)(uVar2);
      pPVar6->serial = pAVar3;
      if (pAVar3 != (ASN1_INTEGER *)0x0) {
        iVar1 = (*(code *)PTR_X509_get_pubkey_006a8008)(x509);
        if (iVar1 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x82,0x96,"pk7_lib.c",0x225);
          return 0;
        }
        if ((*(int *)(iVar1 + 0xc) == 0) ||
           (pcVar7 = *(code **)(*(int *)(iVar1 + 0xc) + 0x58), pcVar7 == (code *)0x0)) {
          uVar5 = 0x96;
          uVar2 = 0x225;
        }
        else {
          iVar4 = (*pcVar7)(iVar1,2,0,p7i);
          if (iVar4 == -2) {
            uVar5 = 0x96;
            uVar2 = 0x22e;
          }
          else {
            if (0 < iVar4) {
              (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar1);
              (*(code *)PTR_CRYPTO_add_lock_006a9080)(&x509->references,1,3,"pk7_lib.c",0x23a);
              p7i->cert = x509;
              return 1;
            }
            uVar5 = 0x95;
            uVar2 = 0x234;
          }
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x82,uVar5,"pk7_lib.c",uVar2);
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar1);
        return 0;
      }
    }
  }
  return 0;
}

