
X509_EXTENSION * OCSP_url_svcloc_new(X509_NAME *issuer,char **urls)

{
  OCSP_SERVICELOC *a;
  X509_NAME *pXVar1;
  _STACK *p_Var2;
  ASN1_OBJECT *pAVar3;
  GENERAL_NAME *pGVar4;
  ASN1_IA5STRING *str;
  int iVar5;
  ACCESS_DESCRIPTION *data;
  X509_EXTENSION *pXVar6;
  
  a = OCSP_SERVICELOC_new();
  if (a == (OCSP_SERVICELOC *)0x0) {
    return (X509_EXTENSION *)0x0;
  }
  pXVar1 = X509_NAME_dup(issuer);
  a->issuer = pXVar1;
  if (pXVar1 == (X509_NAME *)0x0) {
LAB_08186470:
    pXVar6 = (X509_EXTENSION *)0x0;
  }
  else {
    if ((urls != (char **)0x0) && (*urls != (char *)0x0)) {
      p_Var2 = sk_new_null();
      a->locator = (stack_st_ACCESS_DESCRIPTION *)p_Var2;
      if (p_Var2 == (_STACK *)0x0) goto LAB_08186470;
      do {
        if (*urls == (char *)0x0) break;
        data = ACCESS_DESCRIPTION_new();
        if (data == (ACCESS_DESCRIPTION *)0x0) goto LAB_08186470;
        pAVar3 = OBJ_nid2obj(0xb2);
        data->method = pAVar3;
        if (pAVar3 == (ASN1_OBJECT *)0x0) goto LAB_08186470;
        pGVar4 = GENERAL_NAME_new();
        data->location = pGVar4;
        if (((pGVar4 == (GENERAL_NAME *)0x0) ||
            (str = ASN1_IA5STRING_new(), str == (ASN1_IA5STRING *)0x0)) ||
           (iVar5 = ASN1_STRING_set(str,*urls,-1), iVar5 == 0)) goto LAB_08186470;
        pGVar4 = data->location;
        pGVar4->type = 6;
        (pGVar4->d).rfc822Name = str;
        iVar5 = sk_push((_STACK *)a->locator,data);
        if (iVar5 == 0) goto LAB_08186470;
        urls = urls + 1;
      } while (urls != (char **)0x0);
    }
    pXVar6 = X509V3_EXT_i2d(0x173,0,a);
  }
  OCSP_SERVICELOC_free(a);
  return pXVar6;
}

