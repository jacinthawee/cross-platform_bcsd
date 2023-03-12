
PKCS7_RECIP_INFO * PKCS7_add_recipient(PKCS7 *p7,X509 *x509)

{
  undefined *puVar1;
  PKCS7_RECIP_INFO *a;
  int iVar2;
  undefined4 uVar3;
  ASN1_INTEGER *pAVar4;
  int iVar5;
  ASN1_OBJECT *pAVar6;
  stack_st_PKCS7_RECIP_INFO *psVar7;
  undefined4 uVar8;
  PKCS7_ISSUER_AND_SERIAL *pPVar9;
  code *pcVar10;
  
  a = PKCS7_RECIP_INFO_new();
  if (a == (PKCS7_RECIP_INFO *)0x0) {
    return (PKCS7_RECIP_INFO *)0x0;
  }
  iVar2 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(a->version,0);
  if (iVar2 != 0) {
    pPVar9 = a->issuer_and_serial;
    uVar3 = (*(code *)PTR_X509_get_issuer_name_006a76e4)(x509);
    iVar2 = (*(code *)PTR_X509_NAME_set_006a8f2c)(pPVar9,uVar3);
    if (iVar2 != 0) {
      (*(code *)PTR_ASN1_STRING_free_006a879c)(a->issuer_and_serial->serial);
      pPVar9 = a->issuer_and_serial;
      uVar3 = (*(code *)PTR_X509_get_serialNumber_006a6f9c)(x509);
      pAVar4 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_STRING_dup_006a8cbc)(uVar3);
      pPVar9->serial = pAVar4;
      if (pAVar4 != (ASN1_INTEGER *)0x0) {
        iVar2 = (*(code *)PTR_X509_get_pubkey_006a6f08)(x509);
        if (iVar2 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x82,0x96,"pk7_lib.c",0x217);
        }
        else {
          if ((*(int *)(iVar2 + 0xc) == 0) ||
             (pcVar10 = *(code **)(*(int *)(iVar2 + 0xc) + 0x58), pcVar10 == (code *)0x0)) {
            uVar8 = 0x96;
            uVar3 = 0x217;
          }
          else {
            iVar5 = (*pcVar10)(iVar2,2,0,a);
            if (iVar5 == -2) {
              uVar8 = 0x96;
              uVar3 = 0x21e;
            }
            else {
              if (0 < iVar5) {
                (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar2);
                (*(code *)PTR_CRYPTO_add_lock_006a805c)(&x509->references,1,3,"pk7_lib.c",0x229);
                puVar1 = PTR_OBJ_obj2nid_006a712c;
                pAVar6 = p7->type;
                a->cert = x509;
                iVar2 = (*(code *)puVar1)(pAVar6);
                if (iVar2 == 0x17) {
                  psVar7 = (stack_st_PKCS7_RECIP_INFO *)((p7->d).data)->type;
                }
                else {
                  if (iVar2 != 0x18) {
                    (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x66,0x71,"pk7_lib.c",0x1fb);
                    goto LAB_005a0aa0;
                  }
                  psVar7 = ((p7->d).signed_and_enveloped)->recipientinfo;
                }
                iVar2 = (*(code *)PTR_sk_push_006a6fa8)(psVar7,a);
                if (iVar2 != 0) {
                  return a;
                }
                goto LAB_005a0aa0;
              }
              uVar8 = 0x95;
              uVar3 = 0x223;
            }
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x82,uVar8,"pk7_lib.c",uVar3);
          (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar2);
        }
      }
    }
  }
LAB_005a0aa0:
  PKCS7_RECIP_INFO_free(a);
  return (PKCS7_RECIP_INFO *)0x0;
}

