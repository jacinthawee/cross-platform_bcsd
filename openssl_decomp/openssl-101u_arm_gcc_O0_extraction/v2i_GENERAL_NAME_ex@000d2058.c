
GENERAL_NAME *
v2i_GENERAL_NAME_ex(GENERAL_NAME *out,X509V3_EXT_METHOD *method,X509V3_CTX *ctx,CONF_VALUE *cnf,
                   int is_nc)

{
  int iVar1;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  GENERAL_NAME *pGVar4;
  ASN1_OCTET_STRING *pAVar5;
  X509_NAME *nm;
  X509_NAME *dn_sk;
  ASN1_STRING *str;
  size_t sVar6;
  OTHERNAME *pOVar7;
  ASN1_TYPE *pAVar8;
  GENERAL_NAME *a;
  char *s;
  char *pcVar9;
  
  s = cnf->value;
  pcVar9 = cnf->name;
  if (s == (char *)0x0) {
    ERR_put_error(0x22,0x75,0x7c,"v3_alt.c",0x213);
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
              ERR_put_error(0x22,0x75,0x75,"v3_alt.c",0x226);
              ERR_add_error_data(2,"name=",pcVar9);
              return (GENERAL_NAME *)0x0;
            }
          }
        }
      }
    }
  }
  a = out;
  if ((out == (GENERAL_NAME *)0x0) && (a = GENERAL_NAME_new(), a == (GENERAL_NAME *)0x0)) {
    ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1be);
    return (GENERAL_NAME *)0x0;
  }
  switch(iVar1) {
  case 0:
    pcVar9 = strchr(s,0x3b);
    if (pcVar9 != (char *)0x0) {
      pOVar7 = OTHERNAME_new();
      (a->d).otherName = pOVar7;
      if (pOVar7 != (OTHERNAME *)0x0) {
        ASN1_TYPE_free(pOVar7->value);
        pOVar7 = (a->d).otherName;
        pAVar8 = ASN1_generate_v3(pcVar9 + 1,ctx);
        pOVar7->value = pAVar8;
        if (pAVar8 != (ASN1_TYPE *)0x0) {
          sVar6 = (int)pcVar9 - (int)s;
          pcVar9 = (char *)CRYPTO_malloc(sVar6 + 1,"v3_alt.c",0x23f);
          strncpy(pcVar9,s,sVar6);
          pcVar9[sVar6] = '\0';
          pOVar7 = (a->d).otherName;
          pAVar3 = OBJ_txt2obj(pcVar9,0);
          pOVar7->type_id = pAVar3;
          CRYPTO_free(pcVar9);
          if (((a->d).otherName)->type_id != (ASN1_OBJECT *)0x0) goto LAB_000d20c2;
        }
      }
    }
    ERR_put_error(0x22,0xa4,0x93,"v3_alt.c",0x1eb);
    break;
  case 1:
  case 2:
  case 6:
    str = ASN1_STRING_type_new(0x16);
    (a->d).otherName = (OTHERNAME *)str;
    if (str != (ASN1_STRING *)0x0) {
      sVar6 = strlen(s);
      iVar2 = ASN1_STRING_set(str,s,sVar6);
      if (iVar2 != 0) goto LAB_000d20c2;
    }
    ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1f8);
    break;
  default:
    ERR_put_error(0x22,0xa4,0xa7,"v3_alt.c",0x1f0);
    break;
  case 4:
    nm = X509_NAME_new();
    dn_sk = nm;
    if (nm != (X509_NAME *)0x0) {
      dn_sk = (X509_NAME *)X509V3_get_section(ctx,s);
      if (dn_sk == (X509_NAME *)0x0) {
        ERR_put_error(0x22,0x90,0x96,"v3_alt.c",0x252);
        ERR_add_error_data(2,"section=",s);
      }
      else {
        iVar2 = X509V3_NAME_from_section(nm,(stack_st_CONF_VALUE *)dn_sk,0x1001);
        if (iVar2 != 0) {
          (a->d).directoryName = nm;
          X509V3_section_free(ctx,(stack_st_CONF_VALUE *)dn_sk);
          goto LAB_000d20c2;
        }
      }
    }
    X509_NAME_free(nm);
    X509V3_section_free(ctx,(stack_st_CONF_VALUE *)dn_sk);
    ERR_put_error(0x22,0xa4,0x95,"v3_alt.c",0x1e4);
    break;
  case 7:
    if (is_nc == 0) {
      pAVar5 = a2i_IPADDRESS(s);
      (a->d).iPAddress = pAVar5;
    }
    else {
      pAVar5 = a2i_IPADDRESS_NC(s);
      (a->d).iPAddress = pAVar5;
    }
    if (pAVar5 != (ASN1_OCTET_STRING *)0x0) {
LAB_000d20c2:
      a->type = iVar1;
      return a;
    }
    iVar2 = 0x1dc;
    iVar1 = 0x76;
    goto LAB_000d20f4;
  case 8:
    pAVar3 = OBJ_txt2obj(s,0);
    if (pAVar3 != (ASN1_OBJECT *)0x0) {
      (a->d).registeredID = pAVar3;
      goto LAB_000d20c2;
    }
    iVar2 = 0x1ce;
    iVar1 = 0x77;
LAB_000d20f4:
    ERR_put_error(0x22,0xa4,iVar1,"v3_alt.c",iVar2);
    ERR_add_error_data(2,"value=",s);
  }
  pGVar4 = (GENERAL_NAME *)0x0;
  if (out == (GENERAL_NAME *)0x0) {
    GENERAL_NAME_free(a);
    pGVar4 = out;
  }
  return pGVar4;
}

