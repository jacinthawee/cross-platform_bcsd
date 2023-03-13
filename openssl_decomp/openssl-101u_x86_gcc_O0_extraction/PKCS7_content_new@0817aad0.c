
int PKCS7_content_new(PKCS7 *p7,int nid)

{
  PKCS7 *a;
  ASN1_OBJECT *pAVar1;
  PKCS7_DIGEST *pPVar2;
  ASN1_STRING *pAVar3;
  PKCS7_ENCRYPT *pPVar4;
  int iVar5;
  PKCS7_ENVELOPE *pPVar6;
  PKCS7_SIGN_ENVELOPE *pPVar7;
  PKCS7_SIGNED *pPVar8;
  PKCS7_ENC_CONTENT *pPVar9;
  
  a = PKCS7_new();
  if (a == (PKCS7 *)0x0) {
    return 0;
  }
  pAVar1 = OBJ_nid2obj(nid);
  if (5 < nid - 0x15U) {
    ERR_put_error(0x21,0x6e,0x70,"pk7_lib.c",0xde);
    goto LAB_0817abcb;
  }
  a->type = pAVar1;
  switch(nid) {
  case 0x15:
    pAVar3 = ASN1_STRING_type_new(4);
    (a->d).data = pAVar3;
    goto joined_r0x0817ab9d;
  case 0x16:
    pPVar8 = PKCS7_SIGNED_new();
    (a->d).sign = pPVar8;
    if (pPVar8 == (PKCS7_SIGNED *)0x0) goto LAB_0817abcb;
    iVar5 = ASN1_INTEGER_set(pPVar8->version,1);
    if (iVar5 == 0) {
      PKCS7_SIGNED_free((a->d).sign);
      (a->d).ptr = (char *)0x0;
      goto LAB_0817abcb;
    }
    goto LAB_0817ab28;
  case 0x17:
    pPVar6 = PKCS7_ENVELOPE_new();
    (a->d).enveloped = pPVar6;
    if ((pPVar6 == (PKCS7_ENVELOPE *)0x0) ||
       (iVar5 = ASN1_INTEGER_set(pPVar6->version,0), iVar5 == 0)) goto LAB_0817abcb;
    pPVar9 = ((a->d).enveloped)->enc_data;
    break;
  case 0x18:
    pPVar7 = PKCS7_SIGN_ENVELOPE_new();
    (a->d).signed_and_enveloped = pPVar7;
    if (pPVar7 == (PKCS7_SIGN_ENVELOPE *)0x0) goto LAB_0817abcb;
    ASN1_INTEGER_set(pPVar7->version,1);
    iVar5 = ASN1_INTEGER_set(((a->d).sign)->version,1);
    if (iVar5 == 0) goto LAB_0817abcb;
    pPVar9 = ((a->d).signed_and_enveloped)->enc_data;
    break;
  case 0x19:
    pPVar2 = PKCS7_DIGEST_new();
    (a->d).digest = pPVar2;
    if (pPVar2 == (PKCS7_DIGEST *)0x0) goto LAB_0817abcb;
    pAVar3 = (ASN1_STRING *)ASN1_INTEGER_set(pPVar2->version,0);
joined_r0x0817ab9d:
    if (pAVar3 == (ASN1_STRING *)0x0) goto LAB_0817abcb;
    goto LAB_0817ab28;
  case 0x1a:
    pPVar4 = PKCS7_ENCRYPT_new();
    (a->d).encrypted = pPVar4;
    if ((pPVar4 == (PKCS7_ENCRYPT *)0x0) ||
       (iVar5 = ASN1_INTEGER_set(pPVar4->version,0), iVar5 == 0)) goto LAB_0817abcb;
    pPVar9 = (PKCS7_ENC_CONTENT *)((a->d).digest)->md;
  }
  pAVar1 = OBJ_nid2obj(0x15);
  pPVar9->content_type = pAVar1;
LAB_0817ab28:
  iVar5 = OBJ_obj2nid(p7->type);
  if (iVar5 == 0x16) {
    pPVar8 = (p7->d).sign;
    if (pPVar8->contents != (PKCS7 *)0x0) {
      PKCS7_free(pPVar8->contents);
      pPVar8 = (p7->d).sign;
    }
    pPVar8->contents = a;
  }
  else {
    if (iVar5 != 0x19) {
      ERR_put_error(0x21,0x6d,0x70,"pk7_lib.c",0x96);
LAB_0817abcb:
      PKCS7_free(a);
      return 0;
    }
    pPVar2 = (p7->d).digest;
    if (pPVar2->contents != (PKCS7 *)0x0) {
      PKCS7_free(pPVar2->contents);
      pPVar2 = (p7->d).digest;
    }
    pPVar2->contents = a;
  }
  return 1;
}

