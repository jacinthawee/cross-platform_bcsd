
GENERAL_NAME * v2i_GENERAL_NAME(X509V3_EXT_METHOD *method,X509V3_CTX *ctx,CONF_VALUE *cnf)

{
  char *__s;
  int iVar1;
  int iVar2;
  GENERAL_NAME *a;
  ASN1_STRING *str;
  size_t sVar3;
  char *pcVar4;
  OTHERNAME *pOVar5;
  ASN1_TYPE *pAVar6;
  ASN1_OBJECT *pAVar7;
  ASN1_OCTET_STRING *pAVar8;
  X509_NAME *nm;
  stack_st_CONF_VALUE *dn_sk;
  
  __s = cnf->value;
  pcVar4 = cnf->name;
  if (__s == (char *)0x0) {
    ERR_put_error(0x22,0x75,0x7c,"v3_alt.c",0x213);
    return (GENERAL_NAME *)0x0;
  }
  iVar1 = name_cmp(pcVar4,"email");
  if (iVar1 == 0) {
    a = GENERAL_NAME_new();
    iVar1 = 1;
  }
  else {
    iVar1 = 6;
    iVar2 = name_cmp(pcVar4,"URI");
    if (iVar2 != 0) {
      iVar1 = 2;
      iVar2 = name_cmp(pcVar4,"DNS");
      if (iVar2 != 0) {
        iVar1 = name_cmp(pcVar4,"RID");
        if (iVar1 == 0) {
          a = GENERAL_NAME_new();
          if (a == (GENERAL_NAME *)0x0) goto LAB_0816d9c7;
          pAVar7 = OBJ_txt2obj(__s,0);
          if (pAVar7 != (ASN1_OBJECT *)0x0) {
            (a->d).registeredID = pAVar7;
            a->type = 8;
            return a;
          }
          iVar2 = 0x1ce;
          iVar1 = 0x77;
        }
        else {
          iVar1 = name_cmp(pcVar4,"IP");
          if (iVar1 != 0) {
            iVar1 = name_cmp(pcVar4,"dirName");
            if (iVar1 == 0) {
              a = GENERAL_NAME_new();
              if (a == (GENERAL_NAME *)0x0) goto LAB_0816d9c7;
              nm = X509_NAME_new();
              if (nm == (X509_NAME *)0x0) {
                dn_sk = (stack_st_CONF_VALUE *)0x0;
              }
              else {
                dn_sk = X509V3_get_section(ctx,__s);
                if (dn_sk == (stack_st_CONF_VALUE *)0x0) {
                  ERR_put_error(0x22,0x90,0x96,"v3_alt.c",0x252);
                  ERR_add_error_data(2,"section=",__s);
                }
                else {
                  iVar1 = X509V3_NAME_from_section(nm,dn_sk,0x1001);
                  if (iVar1 != 0) {
                    (a->d).directoryName = nm;
                    iVar1 = 4;
                    X509V3_section_free(ctx,dn_sk);
                    goto LAB_0816db40;
                  }
                }
              }
              X509_NAME_free(nm);
              X509V3_section_free(ctx,dn_sk);
              ERR_put_error(0x22,0xa4,0x95,"v3_alt.c",0x1e4);
              goto LAB_0816da53;
            }
            iVar1 = name_cmp(pcVar4,"otherName");
            if (iVar1 != 0) {
              ERR_put_error(0x22,0x75,0x75,"v3_alt.c",0x226);
              ERR_add_error_data(2,"name=",pcVar4);
              return (GENERAL_NAME *)0x0;
            }
            a = GENERAL_NAME_new();
            if (a != (GENERAL_NAME *)0x0) {
              pcVar4 = strchr(__s,0x3b);
              if (pcVar4 != (char *)0x0) {
                pOVar5 = OTHERNAME_new();
                (a->d).otherName = pOVar5;
                if (pOVar5 != (OTHERNAME *)0x0) {
                  ASN1_TYPE_free(pOVar5->value);
                  pOVar5 = (a->d).otherName;
                  pAVar6 = ASN1_generate_v3(pcVar4 + 1,ctx);
                  pOVar5->value = pAVar6;
                  if (pAVar6 != (ASN1_TYPE *)0x0) {
                    sVar3 = (int)pcVar4 - (int)__s;
                    pcVar4 = (char *)CRYPTO_malloc(sVar3 + 1,"v3_alt.c",0x23f);
                    strncpy(pcVar4,__s,sVar3);
                    pcVar4[sVar3] = '\0';
                    pOVar5 = (a->d).otherName;
                    pAVar7 = OBJ_txt2obj(pcVar4,0);
                    pOVar5->type_id = pAVar7;
                    CRYPTO_free(pcVar4);
                    if (((a->d).otherName)->type_id != (ASN1_OBJECT *)0x0) {
                      iVar1 = 0;
                      goto LAB_0816db40;
                    }
                  }
                }
              }
              ERR_put_error(0x22,0xa4,0x93,"v3_alt.c",0x1eb);
              goto LAB_0816da53;
            }
            goto LAB_0816d9c7;
          }
          a = GENERAL_NAME_new();
          if (a == (GENERAL_NAME *)0x0) goto LAB_0816d9c7;
          iVar1 = 7;
          pAVar8 = a2i_IPADDRESS(__s);
          (a->d).iPAddress = pAVar8;
          if (pAVar8 != (ASN1_OCTET_STRING *)0x0) goto LAB_0816db40;
          iVar2 = 0x1dc;
          iVar1 = 0x76;
        }
        ERR_put_error(0x22,0xa4,iVar1,"v3_alt.c",iVar2);
        ERR_add_error_data(2,"value=",__s);
        goto LAB_0816da53;
      }
    }
    a = GENERAL_NAME_new();
  }
  if (a == (GENERAL_NAME *)0x0) {
LAB_0816d9c7:
    ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1be);
    return (GENERAL_NAME *)0x0;
  }
  str = ASN1_STRING_type_new(0x16);
  (a->d).otherName = (OTHERNAME *)str;
  if (str != (ASN1_STRING *)0x0) {
    sVar3 = strlen(__s);
    iVar2 = ASN1_STRING_set(str,__s,sVar3);
    if (iVar2 != 0) {
LAB_0816db40:
      a->type = iVar1;
      return a;
    }
  }
  ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1f8);
LAB_0816da53:
  GENERAL_NAME_free(a);
  return (GENERAL_NAME *)0x0;
}

