
GENERAL_NAME *
v2i_GENERAL_NAME_ex(GENERAL_NAME *out,X509V3_EXT_METHOD *method,X509V3_CTX *ctx,CONF_VALUE *cnf,
                   int is_nc)

{
  int iVar1;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  GENERAL_NAME *pGVar4;
  ASN1_OCTET_STRING *pAVar5;
  X509_NAME *a;
  stack_st_CONF_VALUE *dn_sk;
  ASN1_STRING *str;
  size_t sVar6;
  OTHERNAME *pOVar7;
  ASN1_TYPE *pAVar8;
  GENERAL_NAME *a_00;
  char *s;
  char *pcVar9;
  
  s = cnf->value;
  pcVar9 = cnf->name;
  if (s == (char *)0x0) {
    ERR_put_error(0x22,0x75,0x7c,"v3_alt.c",0x219);
    return (GENERAL_NAME *)0x0;
  }
  iVar1 = name_cmp(pcVar9,"email");
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = 6;
    iVar2 = name_cmp(pcVar9,"URI");
    if (iVar2 != 0) {
      iVar1 = 2;
      iVar2 = name_cmp(pcVar9,"DNS");
      if (iVar2 != 0) {
        iVar1 = 8;
        iVar2 = name_cmp(pcVar9,"RID");
        if (iVar2 != 0) {
          iVar1 = 7;
          iVar2 = name_cmp(pcVar9,"IP");
          if (iVar2 != 0) {
            iVar1 = 4;
            iVar2 = name_cmp(pcVar9,"dirName");
            if ((iVar2 != 0) && (iVar1 = name_cmp(pcVar9,"otherName"), iVar1 != 0)) {
              ERR_put_error(0x22,0x75,0x75,"v3_alt.c",0x22d);
              ERR_add_error_data(2,"name=",pcVar9);
              return (GENERAL_NAME *)0x0;
            }
          }
        }
      }
    }
  }
  a_00 = out;
  if ((out == (GENERAL_NAME *)0x0) && (a_00 = GENERAL_NAME_new(), a_00 == (GENERAL_NAME *)0x0)) {
    ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1bc);
    return (GENERAL_NAME *)0x0;
  }
  switch(iVar1) {
  case 0:
    pcVar9 = strchr(s,0x3b);
    if (pcVar9 != (char *)0x0) {
      pOVar7 = OTHERNAME_new();
      (a_00->d).otherName = pOVar7;
      if (pOVar7 != (OTHERNAME *)0x0) {
        ASN1_TYPE_free(pOVar7->value);
        pOVar7 = (a_00->d).otherName;
        pAVar8 = ASN1_generate_v3(pcVar9 + 1,ctx);
        pOVar7->value = pAVar8;
        if (pAVar8 != (ASN1_TYPE *)0x0) {
          sVar6 = (int)pcVar9 - (int)s;
          pcVar9 = (char *)CRYPTO_malloc(sVar6 + 1,"v3_alt.c",0x245);
          strncpy(pcVar9,s,sVar6);
          pcVar9[sVar6] = '\0';
          pOVar7 = (a_00->d).otherName;
          pAVar3 = OBJ_txt2obj(pcVar9,0);
          pOVar7->type_id = pAVar3;
          CRYPTO_free(pcVar9);
          if (((a_00->d).otherName)->type_id != (ASN1_OBJECT *)0x0) goto LAB_000d437a;
        }
      }
    }
    ERR_put_error(0x22,0xa4,0x93,"v3_alt.c",0x1ee);
    break;
  case 1:
  case 2:
  case 6:
    str = ASN1_STRING_type_new(0x16);
    (a_00->d).otherName = (OTHERNAME *)str;
    if (str != (ASN1_STRING *)0x0) {
      sVar6 = strlen(s);
      iVar2 = ASN1_STRING_set(str,s,sVar6);
      if (iVar2 != 0) goto LAB_000d437a;
    }
    ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1fd);
    break;
  default:
    ERR_put_error(0x22,0xa4,0xa7,"v3_alt.c",499);
    break;
  case 4:
    a = X509_NAME_new();
    if (a != (X509_NAME *)0x0) {
      dn_sk = X509V3_get_section(ctx,s);
      if (dn_sk == (stack_st_CONF_VALUE *)0x0) {
        ERR_put_error(0x22,0x90,0x96,"v3_alt.c",0x259);
        ERR_add_error_data(2,"section=",s);
        X509_NAME_free(a);
      }
      else {
        iVar2 = X509V3_NAME_from_section(a,dn_sk,0x1001);
        if (iVar2 != 0) {
          (a_00->d).directoryName = a;
          X509V3_section_free(ctx,dn_sk);
          goto LAB_000d437a;
        }
        X509_NAME_free(a);
        (a_00->d).directoryName = a;
        X509V3_section_free(ctx,dn_sk);
      }
    }
    ERR_put_error(0x22,0xa4,0x95,"v3_alt.c",0x1e6);
    break;
  case 7:
    if (is_nc == 0) {
      pAVar5 = a2i_IPADDRESS(s);
      (a_00->d).iPAddress = pAVar5;
    }
    else {
      pAVar5 = a2i_IPADDRESS_NC(s);
      (a_00->d).iPAddress = pAVar5;
    }
    if (pAVar5 != (ASN1_OCTET_STRING *)0x0) {
LAB_000d437a:
      a_00->type = iVar1;
      return a_00;
    }
    iVar2 = 0x1dd;
    iVar1 = 0x76;
    goto LAB_000d43ac;
  case 8:
    pAVar3 = OBJ_txt2obj(s,0);
    if (pAVar3 != (ASN1_OBJECT *)0x0) {
      (a_00->d).registeredID = pAVar3;
      goto LAB_000d437a;
    }
    iVar2 = 0x1ce;
    iVar1 = 0x77;
LAB_000d43ac:
    ERR_put_error(0x22,0xa4,iVar1,"v3_alt.c",iVar2);
    ERR_add_error_data(2,"value=",s);
  }
  pGVar4 = (GENERAL_NAME *)0x0;
  if (out == (GENERAL_NAME *)0x0) {
    GENERAL_NAME_free(a_00);
    pGVar4 = out;
  }
  return pGVar4;
}

