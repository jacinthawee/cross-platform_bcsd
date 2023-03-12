
_STACK * v2i_issuer_alt(undefined4 param_1,X509V3_CTX *param_2,_STACK *param_3)

{
  _STACK *st;
  int iVar1;
  void *pvVar2;
  int iVar3;
  GENERAL_NAME *a;
  ASN1_STRING *str;
  size_t sVar4;
  X509_EXTENSION *ext;
  _STACK *p_Var5;
  OTHERNAME *pOVar6;
  ASN1_TYPE *pAVar7;
  ASN1_OBJECT *pAVar8;
  ASN1_OCTET_STRING *pAVar9;
  X509_NAME *a_00;
  stack_st_CONF_VALUE *dn_sk;
  int iVar10;
  char *pcVar11;
  char *__s1;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x99,0x41,"v3_alt.c",0xfa);
    return (_STACK *)0x0;
  }
  iVar10 = 0;
  iVar1 = sk_num(param_3);
  if (0 < iVar1) {
    do {
      pvVar2 = sk_value(param_3,iVar10);
      iVar1 = name_cmp(*(char **)((int)pvVar2 + 4),"issuer");
      __s1 = *(char **)((int)pvVar2 + 8);
      if (iVar1 != 0) {
        pcVar11 = *(char **)((int)pvVar2 + 4);
        if (__s1 == (char *)0x0) goto LAB_000d3302;
LAB_000d326a:
        iVar1 = name_cmp(pcVar11,"email");
        if (iVar1 == 0) {
          iVar1 = 1;
LAB_000d3294:
          a = GENERAL_NAME_new();
          if (a == (GENERAL_NAME *)0x0) {
LAB_000d368a:
            ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1bc);
            goto LAB_000d32e0;
          }
          str = ASN1_STRING_type_new(0x16);
          (a->d).otherName = (OTHERNAME *)str;
          if (str != (ASN1_STRING *)0x0) {
            sVar4 = strlen(__s1);
            iVar3 = ASN1_STRING_set(str,__s1,sVar4);
            if (iVar3 != 0) {
LAB_000d3444:
              a->type = iVar1;
              sk_push(st,a);
              goto LAB_000d338c;
            }
          }
          ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1fd);
        }
        else {
          iVar1 = 6;
          iVar3 = name_cmp(pcVar11,"URI");
          if (iVar3 == 0) goto LAB_000d3294;
          iVar1 = 2;
          iVar3 = name_cmp(pcVar11,"DNS");
          if (iVar3 == 0) goto LAB_000d3294;
          iVar1 = name_cmp(pcVar11,"RID");
          if (iVar1 != 0) {
            iVar1 = name_cmp(pcVar11,"IP");
            if (iVar1 != 0) {
              iVar1 = name_cmp(pcVar11,"dirName");
              if (iVar1 == 0) {
                a = GENERAL_NAME_new();
                if (a != (GENERAL_NAME *)0x0) {
                  a_00 = X509_NAME_new();
                  if (a_00 != (X509_NAME *)0x0) {
                    dn_sk = X509V3_get_section(param_2,__s1);
                    if (dn_sk == (stack_st_CONF_VALUE *)0x0) {
                      ERR_put_error(0x22,0x90,0x96,"v3_alt.c",0x259);
                      ERR_add_error_data(2,"section=",__s1);
                      X509_NAME_free(a_00);
                    }
                    else {
                      iVar1 = X509V3_NAME_from_section(a_00,dn_sk,0x1001);
                      if (iVar1 != 0) {
                        (a->d).directoryName = a_00;
                        X509V3_section_free(param_2,dn_sk);
                        a->type = 4;
                        sk_push(st,a);
                        goto LAB_000d338c;
                      }
                      X509_NAME_free(a_00);
                      (a->d).directoryName = a_00;
                      X509V3_section_free(param_2,dn_sk);
                    }
                  }
                  ERR_put_error(0x22,0xa4,0x95,"v3_alt.c",0x1e6);
                  goto LAB_000d32da;
                }
                goto LAB_000d368a;
              }
              iVar1 = name_cmp(pcVar11,"otherName");
              if (iVar1 != 0) {
                ERR_put_error(0x22,0x75,0x75,"v3_alt.c",0x22d);
                ERR_add_error_data(2,"name=",pcVar11);
                goto LAB_000d32e0;
              }
              a = GENERAL_NAME_new();
              if (a == (GENERAL_NAME *)0x0) goto LAB_000d368a;
              pcVar11 = strchr(__s1,0x3b);
              if (pcVar11 == (char *)0x0) {
LAB_000d362c:
                ERR_put_error(0x22,0xa4,0x93,"v3_alt.c",0x1ee);
                goto LAB_000d32da;
              }
              pOVar6 = OTHERNAME_new();
              (a->d).otherName = pOVar6;
              if (pOVar6 == (OTHERNAME *)0x0) goto LAB_000d362c;
              ASN1_TYPE_free(pOVar6->value);
              pOVar6 = (a->d).otherName;
              pAVar7 = ASN1_generate_v3(pcVar11 + 1,param_2);
              pOVar6->value = pAVar7;
              if (pAVar7 == (ASN1_TYPE *)0x0) goto LAB_000d362c;
              sVar4 = (int)pcVar11 - (int)__s1;
              pcVar11 = (char *)CRYPTO_malloc(sVar4 + 1,"v3_alt.c",0x245);
              strncpy(pcVar11,__s1,sVar4);
              pcVar11[sVar4] = '\0';
              pOVar6 = (a->d).otherName;
              pAVar8 = OBJ_txt2obj(pcVar11,0);
              pOVar6->type_id = pAVar8;
              CRYPTO_free(pcVar11);
              if (((a->d).otherName)->type_id == (ASN1_OBJECT *)0x0) goto LAB_000d362c;
              iVar1 = 0;
              goto LAB_000d3444;
            }
            a = GENERAL_NAME_new();
            if (a != (GENERAL_NAME *)0x0) {
              pAVar9 = a2i_IPADDRESS(__s1);
              (a->d).iPAddress = pAVar9;
              if (pAVar9 == (ASN1_OCTET_STRING *)0x0) {
                iVar10 = 0x1dd;
                iVar1 = 0x76;
                goto LAB_000d3546;
              }
              a->type = 7;
              sk_push(st,a);
              goto LAB_000d338c;
            }
            goto LAB_000d368a;
          }
          a = GENERAL_NAME_new();
          if (a == (GENERAL_NAME *)0x0) goto LAB_000d368a;
          pAVar8 = OBJ_txt2obj(__s1,0);
          if (pAVar8 != (ASN1_OBJECT *)0x0) {
            (a->d).registeredID = pAVar8;
            a->type = 8;
            sk_push(st,a);
            goto LAB_000d338c;
          }
          iVar10 = 0x1ce;
          iVar1 = 0x77;
LAB_000d3546:
          ERR_put_error(0x22,0xa4,iVar1,"v3_alt.c",iVar10);
          ERR_add_error_data(2,"value=",__s1);
        }
LAB_000d32da:
        GENERAL_NAME_free(a);
LAB_000d32e0:
        sk_pop_free(st,GENERAL_NAME_free);
        return (_STACK *)0x0;
      }
      if (__s1 == (char *)0x0) {
LAB_000d3302:
        ERR_put_error(0x22,0x75,0x7c,"v3_alt.c",0x219);
        goto LAB_000d32e0;
      }
      iVar1 = strcmp(__s1,"copy");
      if (iVar1 != 0) {
        pcVar11 = *(char **)((int)pvVar2 + 4);
        goto LAB_000d326a;
      }
      if (param_2 == (X509V3_CTX *)0x0) {
LAB_000d34ac:
        ERR_put_error(0x22,0x7b,0x7f,"v3_alt.c",0x119);
        goto LAB_000d32e0;
      }
      if (param_2->flags != 1) {
        if (param_2->issuer_cert == (X509 *)0x0) goto LAB_000d34ac;
        iVar1 = X509_get_ext_by_NID(param_2->issuer_cert,0x55,-1);
        if (-1 < iVar1) {
          ext = X509_get_ext(param_2->issuer_cert,iVar1);
          if ((ext == (X509_EXTENSION *)0x0) ||
             (p_Var5 = (_STACK *)X509V3_EXT_d2i(ext), p_Var5 == (_STACK *)0x0)) {
            ERR_put_error(0x22,0x7b,0x7e,"v3_alt.c",0x120);
            goto LAB_000d32e0;
          }
          iVar1 = 0;
          while( true ) {
            iVar3 = sk_num(p_Var5);
            if (iVar3 <= iVar1) break;
            pvVar2 = sk_value(p_Var5,iVar1);
            iVar3 = sk_push(st,pvVar2);
            iVar1 = iVar1 + 1;
            if (iVar3 == 0) {
              ERR_put_error(0x22,0x7b,0x41,"v3_alt.c",0x127);
              goto LAB_000d32e0;
            }
          }
          sk_free(p_Var5);
        }
      }
LAB_000d338c:
      iVar10 = iVar10 + 1;
      iVar1 = sk_num(param_3);
    } while (iVar10 < iVar1);
  }
  return st;
}

