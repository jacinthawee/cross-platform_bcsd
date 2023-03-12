
GENERAL_NAMES *
v2i_GENERAL_NAMES(X509V3_EXT_METHOD *method,X509V3_CTX *ctx,stack_st_CONF_VALUE *nval)

{
  char *__s;
  _STACK *st;
  int iVar1;
  void *pvVar2;
  int iVar3;
  GENERAL_NAME *a;
  ASN1_STRING *str;
  size_t sVar4;
  char *pcVar5;
  OTHERNAME *pOVar6;
  ASN1_TYPE *pAVar7;
  ASN1_OBJECT *pAVar8;
  ASN1_OCTET_STRING *pAVar9;
  X509_NAME *a_00;
  stack_st_CONF_VALUE *dn_sk;
  int iVar10;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x76,0x41,"v3_alt.c",0x194);
  }
  else {
    iVar10 = 0;
    while( true ) {
      iVar1 = sk_num(&nval->stack);
      if (iVar1 <= iVar10) {
        return (GENERAL_NAMES *)st;
      }
      pvVar2 = sk_value(&nval->stack,iVar10);
      __s = *(char **)((int)pvVar2 + 8);
      pcVar5 = *(char **)((int)pvVar2 + 4);
      if (__s == (char *)0x0) break;
      iVar1 = name_cmp(pcVar5,"email");
      if (iVar1 != 0) {
        iVar1 = 6;
        iVar3 = name_cmp(pcVar5,"URI");
        if (iVar3 == 0) {
LAB_0816f3d8:
          a = GENERAL_NAME_new();
          goto joined_r0x0816f42e;
        }
        iVar1 = 2;
        iVar3 = name_cmp(pcVar5,"DNS");
        if (iVar3 == 0) goto LAB_0816f3d8;
        iVar1 = name_cmp(pcVar5,"RID");
        if (iVar1 == 0) {
          a = GENERAL_NAME_new();
          if (a != (GENERAL_NAME *)0x0) {
            pAVar8 = OBJ_txt2obj(__s,0);
            if (pAVar8 == (ASN1_OBJECT *)0x0) {
              iVar1 = 0x1ce;
              iVar10 = 0x77;
LAB_0816f697:
              ERR_put_error(0x22,0xa4,iVar10,"v3_alt.c",iVar1);
              ERR_add_error_data(2,"value=",__s);
              goto LAB_0816f489;
            }
            (a->d).registeredID = pAVar8;
            iVar1 = 8;
            goto LAB_0816f580;
          }
          goto LAB_0816f3e3;
        }
        iVar1 = name_cmp(pcVar5,"IP");
        if (iVar1 == 0) {
          a = GENERAL_NAME_new();
          if (a == (GENERAL_NAME *)0x0) goto LAB_0816f3e3;
          pAVar9 = a2i_IPADDRESS(__s);
          (a->d).iPAddress = pAVar9;
          if (pAVar9 == (ASN1_OCTET_STRING *)0x0) {
            iVar1 = 0x1dd;
            iVar10 = 0x76;
            goto LAB_0816f697;
          }
          iVar1 = 7;
          goto LAB_0816f580;
        }
        iVar1 = name_cmp(pcVar5,"dirName");
        if (iVar1 == 0) {
          a = GENERAL_NAME_new();
          if (a == (GENERAL_NAME *)0x0) goto LAB_0816f3e3;
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
                iVar1 = 4;
                X509V3_section_free(ctx,dn_sk);
                goto LAB_0816f580;
              }
              X509_NAME_free(a_00);
              (a->d).directoryName = a_00;
              X509V3_section_free(ctx,dn_sk);
            }
          }
          ERR_put_error(0x22,0xa4,0x95,"v3_alt.c",0x1e6);
        }
        else {
          iVar1 = name_cmp(pcVar5,"otherName");
          if (iVar1 != 0) {
            ERR_put_error(0x22,0x75,0x75,"v3_alt.c",0x22d);
            ERR_add_error_data(2,"name=",pcVar5);
            goto LAB_0816f401;
          }
          a = GENERAL_NAME_new();
          if (a == (GENERAL_NAME *)0x0) goto LAB_0816f3e3;
          pcVar5 = strchr(__s,0x3b);
          if (pcVar5 != (char *)0x0) {
            pOVar6 = OTHERNAME_new();
            (a->d).otherName = pOVar6;
            if (pOVar6 != (OTHERNAME *)0x0) {
              ASN1_TYPE_free(pOVar6->value);
              pOVar6 = (a->d).otherName;
              pAVar7 = ASN1_generate_v3(pcVar5 + 1,ctx);
              pOVar6->value = pAVar7;
              if (pAVar7 != (ASN1_TYPE *)0x0) {
                sVar4 = (int)pcVar5 - (int)__s;
                pcVar5 = (char *)CRYPTO_malloc(sVar4 + 1,"v3_alt.c",0x245);
                strncpy(pcVar5,__s,sVar4);
                pcVar5[sVar4] = '\0';
                pOVar6 = (a->d).otherName;
                pAVar8 = OBJ_txt2obj(pcVar5,0);
                pOVar6->type_id = pAVar8;
                CRYPTO_free(pcVar5);
                if (((a->d).otherName)->type_id != (ASN1_OBJECT *)0x0) {
                  iVar1 = 0;
                  goto LAB_0816f580;
                }
              }
            }
          }
          ERR_put_error(0x22,0xa4,0x93,"v3_alt.c",0x1ee);
        }
LAB_0816f489:
        GENERAL_NAME_free(a);
        goto LAB_0816f401;
      }
      a = GENERAL_NAME_new();
      iVar1 = 1;
joined_r0x0816f42e:
      if (a == (GENERAL_NAME *)0x0) {
LAB_0816f3e3:
        ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1bc);
        goto LAB_0816f401;
      }
      str = ASN1_STRING_type_new(0x16);
      (a->d).otherName = (OTHERNAME *)str;
      if (str == (ASN1_STRING *)0x0) {
LAB_0816f46b:
        ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1fd);
        goto LAB_0816f489;
      }
      sVar4 = strlen(__s);
      iVar3 = ASN1_STRING_set(str,__s,sVar4);
      if (iVar3 == 0) goto LAB_0816f46b;
LAB_0816f580:
      a->type = iVar1;
      iVar10 = iVar10 + 1;
      sk_push(st,a);
    }
    ERR_put_error(0x22,0x75,0x7c,"v3_alt.c",0x219);
LAB_0816f401:
    sk_pop_free(st,GENERAL_NAME_free);
  }
  return (GENERAL_NAMES *)0x0;
}

