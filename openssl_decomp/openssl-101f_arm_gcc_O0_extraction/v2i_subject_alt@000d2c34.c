
_STACK * v2i_subject_alt(undefined4 param_1,X509V3_CTX *param_2,_STACK *param_3)

{
  _STACK *st;
  int iVar1;
  void *pvVar2;
  int iVar3;
  GENERAL_NAME *pGVar4;
  ASN1_STRING *pAVar5;
  size_t sVar6;
  X509_NAME_ENTRY *pXVar7;
  OTHERNAME *pOVar8;
  ASN1_TYPE *pAVar9;
  ASN1_OBJECT *pAVar10;
  ASN1_OCTET_STRING *pAVar11;
  X509_NAME *pXVar12;
  stack_st_CONF_VALUE *dn_sk;
  char *pcVar13;
  int iVar14;
  char *__s1;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x9a,0x41,"v3_alt.c",0x13b);
    return (_STACK *)0x0;
  }
  iVar14 = 0;
  iVar1 = sk_num(param_3);
  if (0 < iVar1) {
    do {
      pvVar2 = sk_value(param_3,iVar14);
      iVar1 = name_cmp(*(char **)((int)pvVar2 + 4),"email");
      if (((iVar1 == 0) && (*(char **)((int)pvVar2 + 8) != (char *)0x0)) &&
         (iVar1 = strcmp(*(char **)((int)pvVar2 + 8),"copy"), iVar1 == 0)) {
        if (param_2 == (X509V3_CTX *)0x0) {
LAB_000d3034:
          pGVar4 = (GENERAL_NAME *)0x0;
          ERR_put_error(0x22,0x7a,0x7d,"v3_alt.c",0x161);
          pAVar5 = (ASN1_STRING *)0x0;
LAB_000d2fb0:
          GENERAL_NAME_free(pGVar4);
          ASN1_STRING_free(pAVar5);
          goto LAB_000d2d2a;
        }
        if (param_2->flags != 1) {
          if (param_2->subject_cert == (X509 *)0x0) {
            if (param_2->subject_req == (X509_REQ *)0x0) goto LAB_000d3034;
            pXVar12 = param_2->subject_req->req_info->subject;
          }
          else {
            pXVar12 = X509_get_subject_name(param_2->subject_cert);
          }
          iVar1 = -1;
          while (iVar1 = X509_NAME_get_index_by_NID(pXVar12,0x30,iVar1), -1 < iVar1) {
            pXVar7 = X509_NAME_get_entry(pXVar12,iVar1);
            pAVar5 = X509_NAME_ENTRY_get_data(pXVar7);
            pAVar5 = ASN1_STRING_dup(pAVar5);
            if ((pAVar5 == (ASN1_STRING *)0x0) ||
               (pGVar4 = GENERAL_NAME_new(), pGVar4 == (GENERAL_NAME *)0x0)) {
              pGVar4 = (GENERAL_NAME *)0x0;
              ERR_put_error(0x22,0x7a,0x41,"v3_alt.c",0x175);
              goto LAB_000d2fb0;
            }
            pGVar4->type = 1;
            (pGVar4->d).otherName = (OTHERNAME *)pAVar5;
            pAVar5 = (ASN1_STRING *)sk_push(st,pGVar4);
            if (pAVar5 == (ASN1_STRING *)0x0) {
              ERR_put_error(0x22,0x7a,0x41,"v3_alt.c",0x17c);
              goto LAB_000d2fb0;
            }
          }
        }
        goto LAB_000d2dd6;
      }
      iVar1 = name_cmp(*(char **)((int)pvVar2 + 4),"email");
      __s1 = *(char **)((int)pvVar2 + 8);
      if (iVar1 == 0) {
        if (__s1 == (char *)0x0) {
LAB_000d2d4c:
          ERR_put_error(0x22,0x75,0x7c,"v3_alt.c",0x219);
          goto LAB_000d2d2a;
        }
        iVar1 = strcmp(__s1,"move");
        if (iVar1 == 0) {
          if (param_2 == (X509V3_CTX *)0x0) {
LAB_000d3052:
            pGVar4 = (GENERAL_NAME *)0x0;
            ERR_put_error(0x22,0x7a,0x7d,"v3_alt.c",0x161);
            pAVar5 = (ASN1_STRING *)0x0;
LAB_000d2fda:
            GENERAL_NAME_free(pGVar4);
            ASN1_STRING_free(pAVar5);
            goto LAB_000d2d2a;
          }
          if (param_2->flags == 1) goto LAB_000d2dd6;
          if (param_2->subject_cert == (X509 *)0x0) {
            if (param_2->subject_req == (X509_REQ *)0x0) goto LAB_000d3052;
            pXVar12 = param_2->subject_req->req_info->subject;
          }
          else {
            pXVar12 = X509_get_subject_name(param_2->subject_cert);
          }
          iVar1 = -1;
          while( true ) {
            iVar3 = X509_NAME_get_index_by_NID(pXVar12,0x30,iVar1);
            iVar1 = iVar3 + -1;
            if (iVar3 < 0) break;
            pXVar7 = X509_NAME_get_entry(pXVar12,iVar3);
            pAVar5 = X509_NAME_ENTRY_get_data(pXVar7);
            pAVar5 = ASN1_STRING_dup(pAVar5);
            X509_NAME_delete_entry(pXVar12,iVar3);
            X509_NAME_ENTRY_free(pXVar7);
            if ((pAVar5 == (ASN1_STRING *)0x0) ||
               (pGVar4 = GENERAL_NAME_new(), pGVar4 == (GENERAL_NAME *)0x0)) {
              pGVar4 = (GENERAL_NAME *)0x0;
              ERR_put_error(0x22,0x7a,0x41,"v3_alt.c",0x175);
              goto LAB_000d2fda;
            }
            (pGVar4->d).otherName = (OTHERNAME *)pAVar5;
            pGVar4->type = 1;
            pAVar5 = (ASN1_STRING *)sk_push(st,pGVar4);
            if (pAVar5 == (ASN1_STRING *)0x0) {
              ERR_put_error(0x22,0x7a,0x41,"v3_alt.c",0x17c);
              goto LAB_000d2fda;
            }
          }
          goto LAB_000d2dd6;
        }
        pcVar13 = *(char **)((int)pvVar2 + 4);
      }
      else {
        pcVar13 = *(char **)((int)pvVar2 + 4);
        if (__s1 == (char *)0x0) goto LAB_000d2d4c;
      }
      iVar1 = name_cmp(pcVar13,"email");
      if (iVar1 != 0) {
        iVar1 = 6;
        iVar3 = name_cmp(pcVar13,"URI");
        if (iVar3 == 0) goto LAB_000d2cde;
        iVar1 = 2;
        iVar3 = name_cmp(pcVar13,"DNS");
        if (iVar3 == 0) goto LAB_000d2cde;
        iVar1 = name_cmp(pcVar13,"RID");
        if (iVar1 != 0) {
          iVar1 = name_cmp(pcVar13,"IP");
          if (iVar1 != 0) {
            iVar1 = name_cmp(pcVar13,"dirName");
            if (iVar1 == 0) {
              pGVar4 = GENERAL_NAME_new();
              if (pGVar4 != (GENERAL_NAME *)0x0) {
                pXVar12 = X509_NAME_new();
                if (pXVar12 != (X509_NAME *)0x0) {
                  dn_sk = X509V3_get_section(param_2,__s1);
                  if (dn_sk == (stack_st_CONF_VALUE *)0x0) {
                    ERR_put_error(0x22,0x90,0x96,"v3_alt.c",0x259);
                    ERR_add_error_data(2,"section=",__s1);
                    X509_NAME_free(pXVar12);
                  }
                  else {
                    iVar1 = X509V3_NAME_from_section(pXVar12,dn_sk,0x1001);
                    if (iVar1 != 0) {
                      (pGVar4->d).directoryName = pXVar12;
                      X509V3_section_free(param_2,dn_sk);
                      pGVar4->type = 4;
                      sk_push(st,pGVar4);
                      goto LAB_000d2dd6;
                    }
                    X509_NAME_free(pXVar12);
                    (pGVar4->d).directoryName = pXVar12;
                    X509V3_section_free(param_2,dn_sk);
                  }
                }
                ERR_put_error(0x22,0xa4,0x95,"v3_alt.c",0x1e6);
                goto LAB_000d2d24;
              }
              goto LAB_000d31f6;
            }
            iVar1 = name_cmp(pcVar13,"otherName");
            if (iVar1 != 0) {
              ERR_put_error(0x22,0x75,0x75,"v3_alt.c",0x22d);
              ERR_add_error_data(2,"name=",pcVar13);
              goto LAB_000d2d2a;
            }
            pGVar4 = GENERAL_NAME_new();
            if (pGVar4 == (GENERAL_NAME *)0x0) goto LAB_000d31f6;
            pcVar13 = strchr(__s1,0x3b);
            if (pcVar13 == (char *)0x0) {
LAB_000d3124:
              ERR_put_error(0x22,0xa4,0x93,"v3_alt.c",0x1ee);
              goto LAB_000d2d24;
            }
            pOVar8 = OTHERNAME_new();
            (pGVar4->d).otherName = pOVar8;
            if (pOVar8 == (OTHERNAME *)0x0) goto LAB_000d3124;
            ASN1_TYPE_free(pOVar8->value);
            pOVar8 = (pGVar4->d).otherName;
            pAVar9 = ASN1_generate_v3(pcVar13 + 1,param_2);
            pOVar8->value = pAVar9;
            if (pAVar9 == (ASN1_TYPE *)0x0) goto LAB_000d3124;
            sVar6 = (int)pcVar13 - (int)__s1;
            pcVar13 = (char *)CRYPTO_malloc(sVar6 + 1,"v3_alt.c",0x245);
            strncpy(pcVar13,__s1,sVar6);
            pcVar13[sVar6] = '\0';
            pOVar8 = (pGVar4->d).otherName;
            pAVar10 = OBJ_txt2obj(pcVar13,0);
            pOVar8->type_id = pAVar10;
            CRYPTO_free(pcVar13);
            if (((pGVar4->d).otherName)->type_id == (ASN1_OBJECT *)0x0) goto LAB_000d3124;
            iVar1 = 0;
            goto LAB_000d2f2a;
          }
          pGVar4 = GENERAL_NAME_new();
          if (pGVar4 != (GENERAL_NAME *)0x0) {
            pAVar11 = a2i_IPADDRESS(__s1);
            (pGVar4->d).iPAddress = pAVar11;
            if (pAVar11 == (ASN1_OCTET_STRING *)0x0) {
              iVar14 = 0x1dd;
              iVar1 = 0x76;
              goto LAB_000d30c2;
            }
            pGVar4->type = 7;
            sk_push(st,pGVar4);
            goto LAB_000d2dd6;
          }
          goto LAB_000d31f6;
        }
        pGVar4 = GENERAL_NAME_new();
        if (pGVar4 == (GENERAL_NAME *)0x0) goto LAB_000d31f6;
        pAVar10 = OBJ_txt2obj(__s1,0);
        if (pAVar10 != (ASN1_OBJECT *)0x0) {
          (pGVar4->d).registeredID = pAVar10;
          pGVar4->type = 8;
          sk_push(st,pGVar4);
          goto LAB_000d2dd6;
        }
        iVar14 = 0x1ce;
        iVar1 = 0x77;
LAB_000d30c2:
        ERR_put_error(0x22,0xa4,iVar1,"v3_alt.c",iVar14);
        ERR_add_error_data(2,"value=",__s1);
LAB_000d2d24:
        GENERAL_NAME_free(pGVar4);
LAB_000d2d2a:
        sk_pop_free(st,GENERAL_NAME_free);
        return (_STACK *)0x0;
      }
      iVar1 = 1;
LAB_000d2cde:
      pGVar4 = GENERAL_NAME_new();
      if (pGVar4 == (GENERAL_NAME *)0x0) {
LAB_000d31f6:
        ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1bc);
        goto LAB_000d2d2a;
      }
      pAVar5 = ASN1_STRING_type_new(0x16);
      (pGVar4->d).otherName = (OTHERNAME *)pAVar5;
      if (pAVar5 == (ASN1_STRING *)0x0) {
LAB_000d2d0c:
        ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1fd);
        goto LAB_000d2d24;
      }
      sVar6 = strlen(__s1);
      iVar3 = ASN1_STRING_set(pAVar5,__s1,sVar6);
      if (iVar3 == 0) goto LAB_000d2d0c;
LAB_000d2f2a:
      pGVar4->type = iVar1;
      sk_push(st,pGVar4);
LAB_000d2dd6:
      iVar14 = iVar14 + 1;
      iVar1 = sk_num(param_3);
    } while (iVar14 < iVar1);
  }
  return st;
}

