
GENERAL_NAMES *
v2i_GENERAL_NAMES(X509V3_EXT_METHOD *method,X509V3_CTX *ctx,stack_st_CONF_VALUE *nval)

{
  _STACK *st;
  int iVar1;
  void *pvVar2;
  int iVar3;
  GENERAL_NAME *a;
  ASN1_STRING *str;
  size_t sVar4;
  OTHERNAME *pOVar5;
  ASN1_TYPE *pAVar6;
  ASN1_OBJECT *pAVar7;
  ASN1_OCTET_STRING *pAVar8;
  X509_NAME *a_00;
  stack_st_CONF_VALUE *dn_sk;
  char *__s;
  int iVar9;
  char *pcVar10;
  
  st = sk_new_null();
  iVar9 = 0;
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x76,0x41,"v3_alt.c",0x194);
    return (GENERAL_NAMES *)0x0;
  }
  iVar1 = sk_num(&nval->stack);
  if (0 < iVar1) {
    do {
      pvVar2 = sk_value(&nval->stack,iVar9);
      __s = *(char **)((int)pvVar2 + 8);
      pcVar10 = *(char **)((int)pvVar2 + 4);
      if (__s == (char *)0x0) {
        ERR_put_error(0x22,0x75,0x7c,"v3_alt.c",0x219);
        goto LAB_000d3a9e;
      }
      iVar1 = name_cmp(pcVar10,"email");
      if (iVar1 != 0) {
        iVar1 = 6;
        iVar3 = name_cmp(pcVar10,"URI");
        if (iVar3 == 0) goto LAB_000d3a54;
        iVar1 = 2;
        iVar3 = name_cmp(pcVar10,"DNS");
        if (iVar3 == 0) goto LAB_000d3a54;
        iVar1 = name_cmp(pcVar10,"RID");
        if (iVar1 != 0) {
          iVar1 = name_cmp(pcVar10,"IP");
          if (iVar1 != 0) {
            iVar1 = name_cmp(pcVar10,"dirName");
            if (iVar1 == 0) {
              a = GENERAL_NAME_new();
              if (a != (GENERAL_NAME *)0x0) {
                a_00 = X509_NAME_new();
                if (a_00 != (X509_NAME *)0x0) {
                  dn_sk = X509V3_get_section(ctx,__s);
                  if (dn_sk == (stack_st_CONF_VALUE *)0x0) {
                    ERR_put_error(0x22,0x90,0x96,"v3_alt.c",0x259);
                    ERR_add_error_data(2,"section=",__s);
                    X509_NAME_free(a_00);
                  }
                  else {
                    iVar1 = X509V3_NAME_from_section(a_00,dn_sk,0x1001);
                    if (iVar1 != 0) {
                      (a->d).directoryName = a_00;
                      X509V3_section_free(ctx,dn_sk);
                      a->type = 4;
                      sk_push(st,a);
                      goto LAB_000d3b6c;
                    }
                    X509_NAME_free(a_00);
                    (a->d).directoryName = a_00;
                    X509V3_section_free(ctx,dn_sk);
                  }
                }
                ERR_put_error(0x22,0xa4,0x95,"v3_alt.c",0x1e6);
                goto LAB_000d3a98;
              }
              goto LAB_000d3d86;
            }
            iVar1 = name_cmp(pcVar10,"otherName");
            if (iVar1 != 0) {
              ERR_put_error(0x22,0x75,0x75,"v3_alt.c",0x22d);
              ERR_add_error_data(2,"name=",pcVar10);
              goto LAB_000d3a9e;
            }
            a = GENERAL_NAME_new();
            if (a == (GENERAL_NAME *)0x0) goto LAB_000d3d86;
            pcVar10 = strchr(__s,0x3b);
            if (pcVar10 == (char *)0x0) {
LAB_000d3d26:
              ERR_put_error(0x22,0xa4,0x93,"v3_alt.c",0x1ee);
              goto LAB_000d3a98;
            }
            pOVar5 = OTHERNAME_new();
            (a->d).otherName = pOVar5;
            if (pOVar5 == (OTHERNAME *)0x0) goto LAB_000d3d26;
            ASN1_TYPE_free(pOVar5->value);
            pOVar5 = (a->d).otherName;
            pAVar6 = ASN1_generate_v3(pcVar10 + 1,ctx);
            pOVar5->value = pAVar6;
            if (pAVar6 == (ASN1_TYPE *)0x0) goto LAB_000d3d26;
            sVar4 = (int)pcVar10 - (int)__s;
            pcVar10 = (char *)CRYPTO_malloc(sVar4 + 1,"v3_alt.c",0x245);
            strncpy(pcVar10,__s,sVar4);
            pcVar10[sVar4] = '\0';
            pOVar5 = (a->d).otherName;
            pAVar7 = OBJ_txt2obj(pcVar10,0);
            pOVar5->type_id = pAVar7;
            CRYPTO_free(pcVar10);
            if (((a->d).otherName)->type_id == (ASN1_OBJECT *)0x0) goto LAB_000d3d26;
            iVar1 = 0;
            goto LAB_000d3b5e;
          }
          a = GENERAL_NAME_new();
          if (a != (GENERAL_NAME *)0x0) {
            pAVar8 = a2i_IPADDRESS(__s);
            (a->d).iPAddress = pAVar8;
            if (pAVar8 == (ASN1_OCTET_STRING *)0x0) {
              iVar1 = 0x1dd;
              iVar9 = 0x76;
              goto LAB_000d3c3e;
            }
            a->type = 7;
            sk_push(st,a);
            goto LAB_000d3b6c;
          }
          goto LAB_000d3d86;
        }
        a = GENERAL_NAME_new();
        if (a == (GENERAL_NAME *)0x0) goto LAB_000d3d86;
        pAVar7 = OBJ_txt2obj(__s,0);
        if (pAVar7 != (ASN1_OBJECT *)0x0) {
          (a->d).registeredID = pAVar7;
          a->type = 8;
          sk_push(st,a);
          goto LAB_000d3b6c;
        }
        iVar1 = 0x1ce;
        iVar9 = 0x77;
LAB_000d3c3e:
        ERR_put_error(0x22,0xa4,iVar9,"v3_alt.c",iVar1);
        ERR_add_error_data(2,"value=",__s);
LAB_000d3a98:
        GENERAL_NAME_free(a);
LAB_000d3a9e:
        sk_pop_free(st,GENERAL_NAME_free);
        return (GENERAL_NAMES *)0x0;
      }
      iVar1 = 1;
LAB_000d3a54:
      a = GENERAL_NAME_new();
      if (a == (GENERAL_NAME *)0x0) {
LAB_000d3d86:
        ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1bc);
        goto LAB_000d3a9e;
      }
      str = ASN1_STRING_type_new(0x16);
      (a->d).otherName = (OTHERNAME *)str;
      if (str == (ASN1_STRING *)0x0) {
LAB_000d3a80:
        ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1fd);
        goto LAB_000d3a98;
      }
      sVar4 = strlen(__s);
      iVar3 = ASN1_STRING_set(str,__s,sVar4);
      if (iVar3 == 0) goto LAB_000d3a80;
LAB_000d3b5e:
      a->type = iVar1;
      sk_push(st,a);
LAB_000d3b6c:
      iVar9 = iVar9 + 1;
      iVar1 = sk_num(&nval->stack);
    } while (iVar9 < iVar1);
  }
  return (GENERAL_NAMES *)st;
}

