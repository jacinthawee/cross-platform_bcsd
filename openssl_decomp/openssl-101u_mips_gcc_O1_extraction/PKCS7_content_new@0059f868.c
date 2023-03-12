
int PKCS7_content_new(PKCS7 *p7,int nid)

{
  undefined *puVar1;
  PKCS7 *a;
  ASN1_OBJECT *pAVar2;
  char *pcVar3;
  PKCS7_ENCRYPT *pPVar4;
  int iVar5;
  PKCS7_DIGEST *pPVar6;
  PKCS7_ENVELOPE *pPVar7;
  PKCS7_SIGN_ENVELOPE *pPVar8;
  uchar *puVar9;
  PKCS7_SIGNED *pPVar10;
  stack_st_X509 *psVar11;
  pkcs7_st *ppVar12;
  stack_st_X509_ALGOR *psVar13;
  
  a = PKCS7_new();
  if (a == (PKCS7 *)0x0) {
    return 0;
  }
  pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(nid);
  puVar1 = PTR_ASN1_STRING_type_new_006a8680;
  switch(nid) {
  case 0x15:
    a->type = pAVar2;
    pcVar3 = (char *)(*(code *)puVar1)(4);
    (a->d).ptr = pcVar3;
    goto joined_r0x0059f920;
  case 0x16:
    a->type = pAVar2;
    pPVar10 = PKCS7_SIGNED_new();
    (a->d).sign = pPVar10;
    if (pPVar10 == (PKCS7_SIGNED *)0x0) goto LAB_0059f960;
    iVar5 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(pPVar10->version,1);
    if (iVar5 == 0) {
      PKCS7_SIGNED_free((a->d).sign);
      (a->d).ptr = (char *)0x0;
      goto LAB_0059f960;
    }
    break;
  case 0x17:
    a->type = pAVar2;
    pPVar7 = PKCS7_ENVELOPE_new();
    (a->d).enveloped = pPVar7;
    if ((pPVar7 == (PKCS7_ENVELOPE *)0x0) ||
       (iVar5 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(pPVar7->version,0), iVar5 == 0))
    goto LAB_0059f960;
    psVar11 = ((a->d).sign)->cert;
    iVar5 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x15);
    (psVar11->stack).num = iVar5;
    break;
  case 0x18:
    a->type = pAVar2;
    pPVar8 = PKCS7_SIGN_ENVELOPE_new();
    (a->d).signed_and_enveloped = pPVar8;
    if (pPVar8 == (PKCS7_SIGN_ENVELOPE *)0x0) goto LAB_0059f960;
    (*(code *)PTR_ASN1_INTEGER_set_006a7164)(pPVar8->version,1);
    iVar5 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(((a->d).data)->length,1);
    if (iVar5 == 0) goto LAB_0059f960;
    ppVar12 = ((a->d).sign)->contents;
    puVar9 = (uchar *)(*(code *)PTR_OBJ_nid2obj_006a7140)(0x15);
    ppVar12->asn1 = puVar9;
    break;
  case 0x19:
    a->type = pAVar2;
    pPVar6 = PKCS7_DIGEST_new();
    (a->d).digest = pPVar6;
    if (pPVar6 == (PKCS7_DIGEST *)0x0) goto LAB_0059f960;
    pcVar3 = (char *)(*(code *)PTR_ASN1_INTEGER_set_006a7164)(pPVar6->version,0);
joined_r0x0059f920:
    if (pcVar3 == (char *)0x0) goto LAB_0059f960;
    break;
  case 0x1a:
    a->type = pAVar2;
    pPVar4 = PKCS7_ENCRYPT_new();
    (a->d).encrypted = pPVar4;
    if ((pPVar4 == (PKCS7_ENCRYPT *)0x0) ||
       (iVar5 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(pPVar4->version,0), iVar5 == 0))
    goto LAB_0059f960;
    psVar13 = ((a->d).sign)->md_algs;
    iVar5 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x15);
    (psVar13->stack).num = iVar5;
    break;
  default:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x6e,0x70,"pk7_lib.c",0xde);
    goto LAB_0059f960;
  }
  iVar5 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
  if (iVar5 == 0x16) {
    pPVar10 = (p7->d).sign;
    if (pPVar10->contents != (PKCS7 *)0x0) {
      PKCS7_free(pPVar10->contents);
      pPVar10 = (p7->d).sign;
    }
    pPVar10->contents = a;
  }
  else {
    if (iVar5 != 0x19) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x6d,0x70,"pk7_lib.c",0x96);
LAB_0059f960:
      PKCS7_free(a);
      return 0;
    }
    pPVar6 = (p7->d).digest;
    if (pPVar6->contents != (PKCS7 *)0x0) {
      PKCS7_free(pPVar6->contents);
      pPVar6 = (p7->d).digest;
    }
    pPVar6->contents = a;
  }
  return 1;
}

