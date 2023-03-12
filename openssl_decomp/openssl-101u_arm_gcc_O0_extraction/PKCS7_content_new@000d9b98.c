
int PKCS7_content_new(PKCS7 *p7,int nid)

{
  PKCS7 *a;
  ASN1_OBJECT *pAVar1;
  PKCS7_ENCRYPT *pPVar2;
  int iVar3;
  PKCS7_ENVELOPE *pPVar4;
  PKCS7_SIGN_ENVELOPE *pPVar5;
  ASN1_STRING *pAVar6;
  PKCS7_DIGEST *pPVar7;
  PKCS7_SIGNED *pPVar8;
  PKCS7_ENC_CONTENT *pPVar9;
  X509_ALGOR *pXVar10;
  
  a = PKCS7_new();
  if (a == (PKCS7 *)0x0) {
    return 0;
  }
  pAVar1 = OBJ_nid2obj(nid);
  switch(nid) {
  case 0x15:
    a->type = pAVar1;
    pAVar6 = ASN1_STRING_type_new(4);
    (a->d).data = pAVar6;
    goto joined_r0x000d9ca2;
  case 0x16:
    a->type = pAVar1;
    pPVar8 = PKCS7_SIGNED_new();
    (a->d).sign = pPVar8;
    if (pPVar8 == (PKCS7_SIGNED *)0x0) goto LAB_000d9bd6;
    iVar3 = ASN1_INTEGER_set(pPVar8->version,1);
    if (iVar3 == 0) {
      PKCS7_SIGNED_free((a->d).sign);
      (a->d).ptr = (char *)0x0;
      goto LAB_000d9bd6;
    }
    break;
  case 0x17:
    a->type = pAVar1;
    pPVar4 = PKCS7_ENVELOPE_new();
    (a->d).enveloped = pPVar4;
    if ((pPVar4 == (PKCS7_ENVELOPE *)0x0) ||
       (iVar3 = ASN1_INTEGER_set(pPVar4->version,0), iVar3 == 0)) goto LAB_000d9bd6;
    pPVar9 = ((a->d).enveloped)->enc_data;
    pAVar1 = OBJ_nid2obj(0x15);
    pPVar9->content_type = pAVar1;
    break;
  case 0x18:
    a->type = pAVar1;
    pPVar5 = PKCS7_SIGN_ENVELOPE_new();
    (a->d).signed_and_enveloped = pPVar5;
    if (pPVar5 == (PKCS7_SIGN_ENVELOPE *)0x0) goto LAB_000d9bd6;
    ASN1_INTEGER_set(pPVar5->version,1);
    iVar3 = ASN1_INTEGER_set(((a->d).sign)->version,1);
    if (iVar3 == 0) goto LAB_000d9bd6;
    pPVar9 = ((a->d).signed_and_enveloped)->enc_data;
    pAVar1 = OBJ_nid2obj(0x15);
    pPVar9->content_type = pAVar1;
    break;
  case 0x19:
    a->type = pAVar1;
    pPVar7 = PKCS7_DIGEST_new();
    (a->d).digest = pPVar7;
    if (pPVar7 == (PKCS7_DIGEST *)0x0) goto LAB_000d9bd6;
    pAVar6 = (ASN1_STRING *)ASN1_INTEGER_set(pPVar7->version,0);
joined_r0x000d9ca2:
    if (pAVar6 == (ASN1_STRING *)0x0) goto LAB_000d9bd6;
    break;
  case 0x1a:
    a->type = pAVar1;
    pPVar2 = PKCS7_ENCRYPT_new();
    (a->d).encrypted = pPVar2;
    if ((pPVar2 == (PKCS7_ENCRYPT *)0x0) ||
       (iVar3 = ASN1_INTEGER_set(pPVar2->version,0), iVar3 == 0)) goto LAB_000d9bd6;
    pXVar10 = ((a->d).digest)->md;
    pAVar1 = OBJ_nid2obj(0x15);
    pXVar10->algorithm = pAVar1;
    break;
  default:
    ERR_put_error(0x21,0x6e,0x70,"pk7_lib.c",0xde);
    goto LAB_000d9bd6;
  }
  iVar3 = OBJ_obj2nid(p7->type);
  if (iVar3 == 0x16) {
    pPVar8 = (p7->d).sign;
    if (pPVar8->contents != (PKCS7 *)0x0) {
      PKCS7_free(pPVar8->contents);
      pPVar8 = (p7->d).sign;
    }
    pPVar8->contents = a;
    return 1;
  }
  if (iVar3 == 0x19) {
    pPVar7 = (p7->d).digest;
    if (pPVar7->contents != (PKCS7 *)0x0) {
      PKCS7_free(pPVar7->contents);
      pPVar7 = (p7->d).digest;
    }
    pPVar7->contents = a;
    return 1;
  }
  ERR_put_error(0x21,0x6d,0x70,"pk7_lib.c",0x96);
LAB_000d9bd6:
  PKCS7_free(a);
  return 0;
}

