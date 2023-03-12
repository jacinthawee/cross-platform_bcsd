
int PKCS7_set_type(PKCS7 *p7,int type)

{
  undefined *puVar1;
  ASN1_OBJECT *pAVar2;
  PKCS7_DIGEST *pPVar3;
  PKCS7_ENCRYPT *pPVar4;
  int iVar5;
  char *pcVar6;
  PKCS7_SIGNED *pPVar7;
  PKCS7_ENVELOPE *pPVar8;
  PKCS7_SIGN_ENVELOPE *pPVar9;
  uchar *puVar10;
  stack_st_X509 *psVar11;
  pkcs7_st *ppVar12;
  stack_st_X509_ALGOR *psVar13;
  
  pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(type);
  puVar1 = PTR_ASN1_STRING_type_new_006a8680;
  switch(type) {
  case 0x15:
    p7->type = pAVar2;
    pcVar6 = (char *)(*(code *)puVar1)(4);
    (p7->d).ptr = pcVar6;
    return (uint)(pcVar6 != (char *)0x0);
  case 0x16:
    p7->type = pAVar2;
    pPVar7 = PKCS7_SIGNED_new();
    (p7->d).sign = pPVar7;
    if (pPVar7 != (PKCS7_SIGNED *)0x0) {
      iVar5 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(pPVar7->version,1);
      if (iVar5 == 0) {
        PKCS7_SIGNED_free((p7->d).sign);
        (p7->d).ptr = (char *)0x0;
      }
      else {
        iVar5 = 1;
      }
      return iVar5;
    }
    break;
  case 0x17:
    p7->type = pAVar2;
    pPVar8 = PKCS7_ENVELOPE_new();
    (p7->d).enveloped = pPVar8;
    if ((pPVar8 != (PKCS7_ENVELOPE *)0x0) &&
       (iVar5 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(pPVar8->version,0), iVar5 != 0)) {
      psVar11 = ((p7->d).sign)->cert;
      iVar5 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x15);
      (psVar11->stack).num = iVar5;
      return 1;
    }
    break;
  case 0x18:
    p7->type = pAVar2;
    pPVar9 = PKCS7_SIGN_ENVELOPE_new();
    (p7->d).signed_and_enveloped = pPVar9;
    if (pPVar9 != (PKCS7_SIGN_ENVELOPE *)0x0) {
      (*(code *)PTR_ASN1_INTEGER_set_006a7164)(pPVar9->version,1);
      iVar5 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(((p7->d).data)->length,1);
      if (iVar5 != 0) {
        ppVar12 = ((p7->d).sign)->contents;
        puVar10 = (uchar *)(*(code *)PTR_OBJ_nid2obj_006a7140)(0x15);
        ppVar12->asn1 = puVar10;
        return 1;
      }
    }
    break;
  case 0x19:
    p7->type = pAVar2;
    pPVar3 = PKCS7_DIGEST_new();
    (p7->d).digest = pPVar3;
    if (pPVar3 != (PKCS7_DIGEST *)0x0) {
      iVar5 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(pPVar3->version,0);
      return (uint)(iVar5 != 0);
    }
    break;
  case 0x1a:
    p7->type = pAVar2;
    pPVar4 = PKCS7_ENCRYPT_new();
    (p7->d).encrypted = pPVar4;
    if ((pPVar4 != (PKCS7_ENCRYPT *)0x0) &&
       (iVar5 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(pPVar4->version,0), iVar5 != 0)) {
      psVar13 = ((p7->d).sign)->md_algs;
      iVar5 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x15);
      (psVar13->stack).num = iVar5;
      return 1;
    }
    break;
  default:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x6e,0x70,"pk7_lib.c",0xde);
  }
  return 0;
}

