
int PKCS7_set_type(PKCS7 *p7,int type)

{
  ASN1_OBJECT *pAVar1;
  PKCS7_DIGEST *pPVar2;
  PKCS7_ENCRYPT *pPVar3;
  int iVar4;
  ASN1_STRING *pAVar5;
  PKCS7_SIGNED *pPVar6;
  PKCS7_ENVELOPE *pPVar7;
  PKCS7_SIGN_ENVELOPE *pPVar8;
  PKCS7_ENC_CONTENT *pPVar9;
  
  pAVar1 = OBJ_nid2obj(type);
  if (5 < type - 0x15U) {
    ERR_put_error(0x21,0x6e,0x70,"pk7_lib.c",0xde);
    return 0;
  }
  p7->type = pAVar1;
  switch(type) {
  case 0x15:
    pAVar5 = ASN1_STRING_type_new(4);
    (p7->d).data = pAVar5;
    return (uint)(pAVar5 != (ASN1_STRING *)0x0);
  case 0x16:
    pPVar6 = PKCS7_SIGNED_new();
    (p7->d).sign = pPVar6;
    if (pPVar6 == (PKCS7_SIGNED *)0x0) {
      return 0;
    }
    iVar4 = ASN1_INTEGER_set(pPVar6->version,1);
    if (iVar4 != 0) {
      return 1;
    }
    PKCS7_SIGNED_free((p7->d).sign);
    (p7->d).ptr = (char *)0x0;
    return 0;
  case 0x17:
    pPVar7 = PKCS7_ENVELOPE_new();
    (p7->d).enveloped = pPVar7;
    if (pPVar7 == (PKCS7_ENVELOPE *)0x0) {
      return 0;
    }
    iVar4 = ASN1_INTEGER_set(pPVar7->version,0);
    if (iVar4 == 0) {
      return 0;
    }
    pPVar9 = ((p7->d).enveloped)->enc_data;
    break;
  case 0x18:
    pPVar8 = PKCS7_SIGN_ENVELOPE_new();
    (p7->d).signed_and_enveloped = pPVar8;
    if (pPVar8 == (PKCS7_SIGN_ENVELOPE *)0x0) {
      return 0;
    }
    ASN1_INTEGER_set(pPVar8->version,1);
    iVar4 = ASN1_INTEGER_set(((p7->d).sign)->version,1);
    if (iVar4 == 0) {
      return 0;
    }
    pPVar9 = ((p7->d).signed_and_enveloped)->enc_data;
    break;
  case 0x19:
    pPVar2 = PKCS7_DIGEST_new();
    (p7->d).digest = pPVar2;
    if (pPVar2 == (PKCS7_DIGEST *)0x0) {
      return 0;
    }
    iVar4 = ASN1_INTEGER_set(pPVar2->version,0);
    return (uint)(iVar4 != 0);
  case 0x1a:
    pPVar3 = PKCS7_ENCRYPT_new();
    (p7->d).encrypted = pPVar3;
    if (pPVar3 == (PKCS7_ENCRYPT *)0x0) {
      return 0;
    }
    iVar4 = ASN1_INTEGER_set(pPVar3->version,0);
    if (iVar4 == 0) {
      return 0;
    }
    pPVar9 = (PKCS7_ENC_CONTENT *)((p7->d).digest)->md;
  }
  pAVar1 = OBJ_nid2obj(0x15);
  pPVar9->content_type = pAVar1;
  return 1;
}

