
GENERAL_NAME *
v2i_GENERAL_NAME_ex(GENERAL_NAME *out,X509V3_EXT_METHOD *method,X509V3_CTX *ctx,CONF_VALUE *cnf,
                   int is_nc)

{
  char *__s;
  int iVar1;
  GENERAL_NAME *pGVar2;
  X509_NAME *a;
  stack_st_CONF_VALUE *dn_sk;
  ASN1_STRING *str;
  size_t sVar3;
  ASN1_OBJECT *pAVar4;
  ASN1_OCTET_STRING *pAVar5;
  char *pcVar6;
  OTHERNAME *pOVar7;
  ASN1_TYPE *pAVar8;
  uint uVar9;
  int line;
  
  __s = cnf->value;
  pcVar6 = cnf->name;
  if (__s == (char *)0x0) {
    ERR_put_error(0x22,0x75,0x7c,"v3_alt.c",0x219);
    return (GENERAL_NAME *)0x0;
  }
  iVar1 = name_cmp(pcVar6,"email");
  pGVar2 = out;
  if (iVar1 == 0) {
    uVar9 = 1;
joined_r0x081701a3:
    if (out != (GENERAL_NAME *)0x0) goto LAB_081701ad;
    pGVar2 = GENERAL_NAME_new();
    if (pGVar2 == (GENERAL_NAME *)0x0) {
LAB_08170320:
      ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1bc);
      return (GENERAL_NAME *)0x0;
    }
    if (uVar9 == 4) goto LAB_08170124;
    if (uVar9 < 5) {
      if (1 < uVar9 - 1) {
LAB_0817021a:
        ERR_put_error(0x22,0xa4,0xa7,"v3_alt.c",499);
        goto LAB_0817023b;
      }
    }
    else if (uVar9 != 6) goto LAB_0817021a;
LAB_081701ad:
    str = ASN1_STRING_type_new(0x16);
    (pGVar2->d).otherName = (OTHERNAME *)str;
    if (str != (ASN1_STRING *)0x0) {
      sVar3 = strlen(__s);
      iVar1 = ASN1_STRING_set(str,__s,sVar3);
      if (iVar1 != 0) {
LAB_08170188:
        pGVar2->type = uVar9;
        return pGVar2;
      }
    }
    ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1fd);
  }
  else {
    uVar9 = 6;
    iVar1 = name_cmp(pcVar6,"URI");
    if (iVar1 == 0) goto joined_r0x081701a3;
    uVar9 = 2;
    iVar1 = name_cmp(pcVar6,"DNS");
    if (iVar1 == 0) goto joined_r0x081701a3;
    iVar1 = name_cmp(pcVar6,"RID");
    if (iVar1 == 0) {
      if ((out == (GENERAL_NAME *)0x0) &&
         (pGVar2 = GENERAL_NAME_new(), pGVar2 == (GENERAL_NAME *)0x0)) goto LAB_08170320;
      pAVar4 = OBJ_txt2obj(__s,0);
      if (pAVar4 != (ASN1_OBJECT *)0x0) {
        (pGVar2->d).registeredID = pAVar4;
        uVar9 = 8;
        goto LAB_08170188;
      }
      line = 0x1ce;
      iVar1 = 0x77;
LAB_0817040c:
      ERR_put_error(0x22,0xa4,iVar1,"v3_alt.c",line);
      ERR_add_error_data(2,"value=",__s);
    }
    else {
      iVar1 = name_cmp(pcVar6,"IP");
      if (iVar1 == 0) {
        if ((out == (GENERAL_NAME *)0x0) &&
           (pGVar2 = GENERAL_NAME_new(), pGVar2 == (GENERAL_NAME *)0x0)) goto LAB_08170320;
        if (is_nc == 0) {
          pAVar5 = a2i_IPADDRESS(__s);
          (pGVar2->d).iPAddress = pAVar5;
        }
        else {
          pAVar5 = a2i_IPADDRESS_NC(__s);
          (pGVar2->d).iPAddress = pAVar5;
        }
        uVar9 = 7;
        if (pAVar5 != (ASN1_OCTET_STRING *)0x0) goto LAB_08170188;
        line = 0x1dd;
        iVar1 = 0x76;
        goto LAB_0817040c;
      }
      iVar1 = name_cmp(pcVar6,"dirName");
      if (iVar1 != 0) {
        iVar1 = name_cmp(pcVar6,"otherName");
        if (iVar1 != 0) {
          ERR_put_error(0x22,0x75,0x75,"v3_alt.c",0x22d);
          ERR_add_error_data(2,"name=",pcVar6);
          return (GENERAL_NAME *)0x0;
        }
        if ((out == (GENERAL_NAME *)0x0) &&
           (pGVar2 = GENERAL_NAME_new(), pGVar2 == (GENERAL_NAME *)0x0)) goto LAB_08170320;
        pcVar6 = strchr(__s,0x3b);
        if (pcVar6 != (char *)0x0) {
          pOVar7 = OTHERNAME_new();
          (pGVar2->d).otherName = pOVar7;
          if (pOVar7 != (OTHERNAME *)0x0) {
            ASN1_TYPE_free(pOVar7->value);
            pOVar7 = (pGVar2->d).otherName;
            pAVar8 = ASN1_generate_v3(pcVar6 + 1,ctx);
            pOVar7->value = pAVar8;
            if (pAVar8 != (ASN1_TYPE *)0x0) {
              sVar3 = (int)pcVar6 - (int)__s;
              pcVar6 = (char *)CRYPTO_malloc(sVar3 + 1,"v3_alt.c",0x245);
              strncpy(pcVar6,__s,sVar3);
              pcVar6[sVar3] = '\0';
              pOVar7 = (pGVar2->d).otherName;
              pAVar4 = OBJ_txt2obj(pcVar6,0);
              pOVar7->type_id = pAVar4;
              CRYPTO_free(pcVar6);
              if (((pGVar2->d).otherName)->type_id != (ASN1_OBJECT *)0x0) {
                uVar9 = 0;
                goto LAB_08170188;
              }
            }
          }
        }
        ERR_put_error(0x22,0xa4,0x93,"v3_alt.c",0x1ee);
        goto LAB_081701fc;
      }
      if ((out == (GENERAL_NAME *)0x0) &&
         (pGVar2 = GENERAL_NAME_new(), pGVar2 == (GENERAL_NAME *)0x0)) goto LAB_08170320;
LAB_08170124:
      a = X509_NAME_new();
      if (a != (X509_NAME *)0x0) {
        dn_sk = X509V3_get_section(ctx,__s);
        if (dn_sk == (stack_st_CONF_VALUE *)0x0) {
          ERR_put_error(0x22,0x90,0x96,"v3_alt.c",0x259);
          ERR_add_error_data(2,"section=",__s);
          X509_NAME_free(a);
        }
        else {
          iVar1 = X509V3_NAME_from_section(a,dn_sk,0x1001);
          if (iVar1 != 0) {
            (pGVar2->d).directoryName = a;
            uVar9 = 4;
            X509V3_section_free(ctx,dn_sk);
            goto LAB_08170188;
          }
          X509_NAME_free(a);
          (pGVar2->d).directoryName = a;
          X509V3_section_free(ctx,dn_sk);
        }
      }
      ERR_put_error(0x22,0xa4,0x95,"v3_alt.c",0x1e6);
    }
  }
LAB_081701fc:
  if (out != (GENERAL_NAME *)0x0) {
    return (GENERAL_NAME *)0x0;
  }
LAB_0817023b:
  GENERAL_NAME_free(pGVar2);
  return (GENERAL_NAME *)0x0;
}
