
X509_EXTENSION * OCSP_url_svcloc_new(X509_NAME *issuer,char **urls)

{
  undefined *puVar1;
  OCSP_SERVICELOC *a;
  X509_NAME *pXVar2;
  stack_st_ACCESS_DESCRIPTION *psVar3;
  char *pcVar4;
  ASN1_OBJECT *pAVar5;
  GENERAL_NAME *pGVar6;
  int iVar7;
  ACCESS_DESCRIPTION *pAVar8;
  char *pcVar9;
  X509_EXTENSION *pXVar10;
  
  a = OCSP_SERVICELOC_new();
  if (a == (OCSP_SERVICELOC *)0x0) {
    return (X509_EXTENSION *)0x0;
  }
  pXVar2 = (X509_NAME *)(*(code *)PTR_X509_NAME_dup_006a713c)(issuer);
  a->issuer = pXVar2;
  if (pXVar2 == (X509_NAME *)0x0) {
LAB_005ac32c:
    pXVar10 = (X509_EXTENSION *)0x0;
  }
  else {
    if ((urls != (char **)0x0) && (*urls != (char *)0x0)) {
      psVar3 = (stack_st_ACCESS_DESCRIPTION *)(*(code *)PTR_sk_new_null_006a6fa4)();
      a->locator = psVar3;
      if (psVar3 == (stack_st_ACCESS_DESCRIPTION *)0x0) goto LAB_005ac32c;
      pcVar4 = *urls;
      while (pcVar4 != (char *)0x0) {
        pAVar8 = ACCESS_DESCRIPTION_new();
        if (pAVar8 == (ACCESS_DESCRIPTION *)0x0) goto LAB_005ac32c;
        pAVar5 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(0xb2);
        pAVar8->method = pAVar5;
        if (pAVar5 == (ASN1_OBJECT *)0x0) goto LAB_005ac32c;
        pGVar6 = (GENERAL_NAME *)(*(code *)PTR_GENERAL_NAME_new_006a9034)();
        pAVar8->location = pGVar6;
        if ((pGVar6 == (GENERAL_NAME *)0x0) ||
           (pcVar4 = (char *)(*(code *)PTR_ASN1_IA5STRING_new_006a9254)(), pcVar4 == (char *)0x0))
        goto LAB_005ac32c;
        pcVar9 = *urls;
        urls = urls + 1;
        iVar7 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)(pcVar4,pcVar9,0xffffffff);
        puVar1 = PTR_sk_push_006a6fa8;
        if (iVar7 == 0) goto LAB_005ac32c;
        pGVar6 = pAVar8->location;
        (pGVar6->d).ptr = pcVar4;
        pGVar6->type = 6;
        iVar7 = (*(code *)puVar1)(a->locator,pAVar8);
        if (iVar7 == 0) goto LAB_005ac32c;
        if (urls == (char **)0x0) break;
        pcVar4 = *urls;
      }
    }
    pXVar10 = (X509_EXTENSION *)(*(code *)PTR_X509V3_EXT_i2d_006a9018)(0x173,0,a);
  }
  OCSP_SERVICELOC_free(a);
  return pXVar10;
}

