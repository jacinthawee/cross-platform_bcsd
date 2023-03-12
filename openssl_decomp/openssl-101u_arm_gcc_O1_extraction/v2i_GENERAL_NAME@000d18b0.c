
GENERAL_NAME * v2i_GENERAL_NAME(X509V3_EXT_METHOD *method,X509V3_CTX *ctx,CONF_VALUE *cnf)

{
  int iVar1;
  GENERAL_NAME *a;
  ASN1_STRING *str;
  size_t sVar2;
  int iVar3;
  X509_NAME *nm;
  X509_NAME *dn_sk;
  ASN1_OBJECT *pAVar4;
  ASN1_OCTET_STRING *pAVar5;
  OTHERNAME *pOVar6;
  ASN1_TYPE *pAVar7;
  char *__s;
  char *pcVar8;
  
  __s = cnf->value;
  pcVar8 = cnf->name;
  if (__s == (char *)0x0) {
    ERR_put_error(0x22,0x75,0x7c,"v3_alt.c",0x213);
    return (GENERAL_NAME *)0x0;
  }
  iVar1 = name_cmp(pcVar8,"email");
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = name_cmp(pcVar8,"URI");
    if (iVar1 == 0) {
      iVar1 = 6;
    }
    else {
      iVar1 = name_cmp(pcVar8,"DNS");
      if (iVar1 != 0) {
        iVar1 = name_cmp(pcVar8,"RID");
        if (iVar1 == 0) {
          a = GENERAL_NAME_new();
          if (a == (GENERAL_NAME *)0x0) goto LAB_000d1b90;
          pAVar4 = OBJ_txt2obj(__s,0);
          if (pAVar4 != (ASN1_OBJECT *)0x0) {
            (a->d).registeredID = pAVar4;
            a->type = 8;
            return a;
          }
          iVar3 = 0x1ce;
          iVar1 = 0x77;
        }
        else {
          iVar1 = name_cmp(pcVar8,"IP");
          if (iVar1 != 0) {
            iVar1 = name_cmp(pcVar8,"dirName");
            if (iVar1 == 0) {
              a = GENERAL_NAME_new();
              if (a != (GENERAL_NAME *)0x0) {
                nm = X509_NAME_new();
                dn_sk = nm;
                if (nm != (X509_NAME *)0x0) {
                  dn_sk = (X509_NAME *)X509V3_get_section(ctx,__s);
                  if (dn_sk == (X509_NAME *)0x0) {
                    ERR_put_error(0x22,0x90,0x96,"v3_alt.c",0x252);
                    ERR_add_error_data(2,"section=",__s);
                  }
                  else {
                    iVar1 = X509V3_NAME_from_section(nm,(stack_st_CONF_VALUE *)dn_sk,0x1001);
                    if (iVar1 != 0) {
                      (a->d).directoryName = nm;
                      iVar1 = 4;
                      X509V3_section_free(ctx,(stack_st_CONF_VALUE *)dn_sk);
                      goto LAB_000d1994;
                    }
                  }
                }
                X509_NAME_free(nm);
                X509V3_section_free(ctx,(stack_st_CONF_VALUE *)dn_sk);
                ERR_put_error(0x22,0xa4,0x95,"v3_alt.c",0x1e4);
                goto LAB_000d192a;
              }
              goto LAB_000d1b90;
            }
            iVar1 = name_cmp(pcVar8,"otherName");
            if (iVar1 != 0) {
              ERR_put_error(0x22,0x75,0x75,"v3_alt.c",0x226);
              ERR_add_error_data(2,"name=",pcVar8);
              return (GENERAL_NAME *)0x0;
            }
            a = GENERAL_NAME_new();
            if (a == (GENERAL_NAME *)0x0) goto LAB_000d1b90;
            pcVar8 = strchr(__s,0x3b);
            if (pcVar8 != (char *)0x0) {
              pOVar6 = OTHERNAME_new();
              (a->d).otherName = pOVar6;
              if (pOVar6 != (OTHERNAME *)0x0) {
                ASN1_TYPE_free(pOVar6->value);
                pOVar6 = (a->d).otherName;
                pAVar7 = ASN1_generate_v3(pcVar8 + 1,ctx);
                pOVar6->value = pAVar7;
                if (pAVar7 != (ASN1_TYPE *)0x0) {
                  sVar2 = (int)pcVar8 - (int)__s;
                  iVar1 = 0;
                  pcVar8 = (char *)CRYPTO_malloc(sVar2 + 1,"v3_alt.c",0x23f);
                  strncpy(pcVar8,__s,sVar2);
                  pcVar8[sVar2] = '\0';
                  pOVar6 = (a->d).otherName;
                  pAVar4 = OBJ_txt2obj(pcVar8,0);
                  pOVar6->type_id = pAVar4;
                  CRYPTO_free(pcVar8);
                  if (((a->d).otherName)->type_id != (ASN1_OBJECT *)0x0) goto LAB_000d1994;
                }
              }
            }
            ERR_put_error(0x22,0xa4,0x93,"v3_alt.c",0x1eb);
            goto LAB_000d192a;
          }
          a = GENERAL_NAME_new();
          if (a == (GENERAL_NAME *)0x0) goto LAB_000d1b90;
          iVar1 = 7;
          pAVar5 = a2i_IPADDRESS(__s);
          (a->d).iPAddress = pAVar5;
          if (pAVar5 != (ASN1_OCTET_STRING *)0x0) goto LAB_000d1994;
          iVar3 = 0x1dc;
          iVar1 = 0x76;
        }
        ERR_put_error(0x22,0xa4,iVar1,"v3_alt.c",iVar3);
        ERR_add_error_data(2,"value=",__s);
        goto LAB_000d192a;
      }
      iVar1 = 2;
    }
  }
  a = GENERAL_NAME_new();
  if (a == (GENERAL_NAME *)0x0) {
LAB_000d1b90:
    ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1be);
    return (GENERAL_NAME *)0x0;
  }
  str = ASN1_STRING_type_new(0x16);
  (a->d).otherName = (OTHERNAME *)str;
  if (str != (ASN1_STRING *)0x0) {
    sVar2 = strlen(__s);
    iVar3 = ASN1_STRING_set(str,__s,sVar2);
    if (iVar3 != 0) {
LAB_000d1994:
      a->type = iVar1;
      return a;
    }
  }
  ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1f8);
LAB_000d192a:
  GENERAL_NAME_free(a);
  return (GENERAL_NAME *)0x0;
}

