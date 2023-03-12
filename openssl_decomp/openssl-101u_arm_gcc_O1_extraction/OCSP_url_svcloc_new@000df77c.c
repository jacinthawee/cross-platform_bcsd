
X509_EXTENSION * OCSP_url_svcloc_new(X509_NAME *issuer,char **urls)

{
  char **ppcVar1;
  OCSP_SERVICELOC *a;
  X509_NAME *pXVar2;
  _STACK *p_Var3;
  ASN1_OBJECT *pAVar4;
  GENERAL_NAME *pGVar5;
  ASN1_IA5STRING *str;
  int iVar6;
  ACCESS_DESCRIPTION *data;
  X509_EXTENSION *pXVar7;
  char *pcVar8;
  
  a = OCSP_SERVICELOC_new();
  if (a == (OCSP_SERVICELOC *)0x0) {
    return (X509_EXTENSION *)0x0;
  }
  pXVar2 = X509_NAME_dup(issuer);
  a->issuer = pXVar2;
  if (pXVar2 == (X509_NAME *)0x0) {
LAB_000df7fe:
    pXVar7 = (X509_EXTENSION *)0x0;
  }
  else {
    if ((urls != (char **)0x0) && (*urls != (char *)0x0)) {
      p_Var3 = sk_new_null();
      a->locator = (stack_st_ACCESS_DESCRIPTION *)p_Var3;
      if (p_Var3 == (_STACK *)0x0) goto LAB_000df7fe;
      pcVar8 = *urls;
      ppcVar1 = urls + 1;
      while (pcVar8 != (char *)0x0) {
        data = ACCESS_DESCRIPTION_new();
        if (data == (ACCESS_DESCRIPTION *)0x0) goto LAB_000df7fe;
        pAVar4 = OBJ_nid2obj(0xb2);
        data->method = pAVar4;
        if (pAVar4 == (ASN1_OBJECT *)0x0) goto LAB_000df7fe;
        pGVar5 = GENERAL_NAME_new();
        data->location = pGVar5;
        if (((pGVar5 == (GENERAL_NAME *)0x0) ||
            (str = ASN1_IA5STRING_new(), str == (ASN1_IA5STRING *)0x0)) ||
           (iVar6 = ASN1_STRING_set(str,ppcVar1[-1],-1), iVar6 == 0)) goto LAB_000df7fe;
        pGVar5 = data->location;
        pGVar5->type = 6;
        (pGVar5->d).rfc822Name = str;
        iVar6 = sk_push((_STACK *)a->locator,data);
        if (iVar6 == 0) goto LAB_000df7fe;
        if (ppcVar1 == (char **)0x0) break;
        pcVar8 = *ppcVar1;
        ppcVar1 = ppcVar1 + 1;
      }
    }
    pXVar7 = X509V3_EXT_i2d(0x173,0,a);
  }
  OCSP_SERVICELOC_free(a);
  return pXVar7;
}

