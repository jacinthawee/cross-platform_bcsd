
_STACK * v2i_subject_alt(undefined4 param_1,X509V3_CTX *param_2,_STACK *param_3)

{
  _STACK *st;
  int iVar1;
  void *pvVar2;
  int iVar3;
  GENERAL_NAME *pGVar4;
  ASN1_STRING *pAVar5;
  size_t sVar6;
  char *pcVar7;
  OTHERNAME *pOVar8;
  ASN1_TYPE *pAVar9;
  X509_NAME_ENTRY *pXVar10;
  ASN1_OBJECT *pAVar11;
  ASN1_OCTET_STRING *pAVar12;
  X509_NAME *pXVar13;
  stack_st_CONF_VALUE *dn_sk;
  char *pcVar14;
  char *pcVar15;
  bool bVar16;
  byte bVar17;
  int local_20;
  
  bVar17 = 0;
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x9a,0x41,"v3_alt.c",0x13b);
    return (_STACK *)0x0;
  }
  local_20 = 0;
  do {
    iVar1 = sk_num(param_3);
    if (iVar1 <= local_20) {
      return st;
    }
    pvVar2 = sk_value(param_3,local_20);
    iVar1 = name_cmp(*(char **)((int)pvVar2 + 4),"email");
    if (iVar1 == 0) {
      bVar16 = *(char **)((int)pvVar2 + 8) == (char *)0x0;
      if (bVar16) goto LAB_0816e69a;
      iVar1 = 5;
      pcVar14 = *(char **)((int)pvVar2 + 8);
      pcVar7 = "copy";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar16 = *pcVar14 == *pcVar7;
        pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
        pcVar7 = pcVar7 + (uint)bVar17 * -2 + 1;
      } while (bVar16);
      if (!bVar16) goto LAB_0816e69a;
      if (param_2 == (X509V3_CTX *)0x0) {
LAB_0816ebe8:
        pGVar4 = (GENERAL_NAME *)0x0;
        pAVar5 = (ASN1_STRING *)0x0;
        ERR_put_error(0x22,0x7a,0x7d,"v3_alt.c",0x161);
LAB_0816e9cd:
        GENERAL_NAME_free(pGVar4);
        ASN1_STRING_free(pAVar5);
        goto LAB_0816e733;
      }
      if (param_2->flags != 1) {
        if (param_2->subject_cert == (X509 *)0x0) {
          if (param_2->subject_req == (X509_REQ *)0x0) goto LAB_0816ebe8;
          pXVar13 = param_2->subject_req->req_info->subject;
        }
        else {
          pXVar13 = X509_get_subject_name(param_2->subject_cert);
        }
        iVar1 = -1;
        while (iVar1 = X509_NAME_get_index_by_NID(pXVar13,0x30,iVar1), -1 < iVar1) {
          pXVar10 = X509_NAME_get_entry(pXVar13,iVar1);
          pAVar5 = X509_NAME_ENTRY_get_data(pXVar10);
          pAVar5 = ASN1_STRING_dup(pAVar5);
          if ((pAVar5 == (ASN1_STRING *)0x0) ||
             (pGVar4 = GENERAL_NAME_new(), pGVar4 == (GENERAL_NAME *)0x0)) {
            pGVar4 = (GENERAL_NAME *)0x0;
            ERR_put_error(0x22,0x7a,0x41,"v3_alt.c",0x175);
            goto LAB_0816e9cd;
          }
          (pGVar4->d).otherName = (OTHERNAME *)pAVar5;
          pGVar4->type = 1;
          iVar3 = sk_push(st,pGVar4);
          if (iVar3 == 0) {
            pAVar5 = (ASN1_STRING *)0x0;
            ERR_put_error(0x22,0x7a,0x41,"v3_alt.c",0x17c);
            goto LAB_0816e9cd;
          }
        }
      }
    }
    else {
LAB_0816e69a:
      iVar1 = name_cmp(*(char **)((int)pvVar2 + 4),"email");
      if (iVar1 != 0) {
        pcVar14 = *(char **)((int)pvVar2 + 8);
        pcVar7 = *(char **)((int)pvVar2 + 4);
        if (pcVar14 == (char *)0x0) goto LAB_0816e7e0;
LAB_0816e6d7:
        iVar1 = name_cmp(pcVar7,"email");
        if (iVar1 == 0) {
          pGVar4 = GENERAL_NAME_new();
          iVar1 = 1;
joined_r0x0816e766:
          if (pGVar4 == (GENERAL_NAME *)0x0) {
LAB_0816e715:
            ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1bc);
            goto LAB_0816e733;
          }
          pAVar5 = ASN1_STRING_type_new(0x16);
          (pGVar4->d).otherName = (OTHERNAME *)pAVar5;
          if (pAVar5 != (ASN1_STRING *)0x0) {
            sVar6 = strlen(pcVar14);
            iVar3 = ASN1_STRING_set(pAVar5,pcVar14,sVar6);
            if (iVar3 != 0) {
LAB_0816e8f0:
              pGVar4->type = iVar1;
              sk_push(st,pGVar4);
              goto LAB_0816e902;
            }
          }
          ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1fd);
        }
        else {
          iVar1 = 6;
          iVar3 = name_cmp(pcVar7,"URI");
          if (iVar3 == 0) {
LAB_0816e70a:
            pGVar4 = GENERAL_NAME_new();
            goto joined_r0x0816e766;
          }
          iVar1 = 2;
          iVar3 = name_cmp(pcVar7,"DNS");
          if (iVar3 == 0) goto LAB_0816e70a;
          iVar1 = name_cmp(pcVar7,"RID");
          if (iVar1 == 0) {
            pGVar4 = GENERAL_NAME_new();
            if (pGVar4 != (GENERAL_NAME *)0x0) {
              pAVar11 = OBJ_txt2obj(pcVar14,0);
              if (pAVar11 == (ASN1_OBJECT *)0x0) {
                iVar3 = 0x1ce;
                iVar1 = 0x77;
LAB_0816ec88:
                ERR_put_error(0x22,0xa4,iVar1,"v3_alt.c",iVar3);
                ERR_add_error_data(2,"value=",pcVar14);
                goto LAB_0816e7bb;
              }
              (pGVar4->d).registeredID = pAVar11;
              iVar1 = 8;
              goto LAB_0816e8f0;
            }
            goto LAB_0816e715;
          }
          iVar1 = name_cmp(pcVar7,"IP");
          if (iVar1 == 0) {
            pGVar4 = GENERAL_NAME_new();
            if (pGVar4 == (GENERAL_NAME *)0x0) goto LAB_0816e715;
            pAVar12 = a2i_IPADDRESS(pcVar14);
            (pGVar4->d).iPAddress = pAVar12;
            if (pAVar12 == (ASN1_OCTET_STRING *)0x0) {
              iVar3 = 0x1dd;
              iVar1 = 0x76;
              goto LAB_0816ec88;
            }
            iVar1 = 7;
            goto LAB_0816e8f0;
          }
          iVar1 = name_cmp(pcVar7,"dirName");
          if (iVar1 == 0) {
            pGVar4 = GENERAL_NAME_new();
            if (pGVar4 == (GENERAL_NAME *)0x0) goto LAB_0816e715;
            pXVar13 = X509_NAME_new();
            if (pXVar13 != (X509_NAME *)0x0) {
              dn_sk = X509V3_get_section(param_2,pcVar14);
              if (dn_sk == (stack_st_CONF_VALUE *)0x0) {
                ERR_put_error(0x22,0x90,0x96,"v3_alt.c",0x259);
                ERR_add_error_data(2,"section=",pcVar14);
                X509_NAME_free(pXVar13);
              }
              else {
                iVar1 = X509V3_NAME_from_section(pXVar13,dn_sk,0x1001);
                if (iVar1 != 0) {
                  (pGVar4->d).directoryName = pXVar13;
                  iVar1 = 4;
                  X509V3_section_free(param_2,dn_sk);
                  goto LAB_0816e8f0;
                }
                X509_NAME_free(pXVar13);
                (pGVar4->d).directoryName = pXVar13;
                X509V3_section_free(param_2,dn_sk);
              }
            }
            ERR_put_error(0x22,0xa4,0x95,"v3_alt.c",0x1e6);
          }
          else {
            iVar1 = name_cmp(pcVar7,"otherName");
            if (iVar1 != 0) {
              ERR_put_error(0x22,0x75,0x75,"v3_alt.c",0x22d);
              ERR_add_error_data(2,"name=",pcVar7);
              goto LAB_0816e733;
            }
            pGVar4 = GENERAL_NAME_new();
            if (pGVar4 == (GENERAL_NAME *)0x0) goto LAB_0816e715;
            pcVar7 = strchr(pcVar14,0x3b);
            if (pcVar7 != (char *)0x0) {
              pOVar8 = OTHERNAME_new();
              (pGVar4->d).otherName = pOVar8;
              if (pOVar8 != (OTHERNAME *)0x0) {
                ASN1_TYPE_free(pOVar8->value);
                pOVar8 = (pGVar4->d).otherName;
                pAVar9 = ASN1_generate_v3(pcVar7 + 1,param_2);
                pOVar8->value = pAVar9;
                if (pAVar9 != (ASN1_TYPE *)0x0) {
                  sVar6 = (int)pcVar7 - (int)pcVar14;
                  pcVar7 = (char *)CRYPTO_malloc(sVar6 + 1,"v3_alt.c",0x245);
                  strncpy(pcVar7,pcVar14,sVar6);
                  pcVar7[sVar6] = '\0';
                  pOVar8 = (pGVar4->d).otherName;
                  pAVar11 = OBJ_txt2obj(pcVar7,0);
                  pOVar8->type_id = pAVar11;
                  CRYPTO_free(pcVar7);
                  if (((pGVar4->d).otherName)->type_id != (ASN1_OBJECT *)0x0) {
                    iVar1 = 0;
                    goto LAB_0816e8f0;
                  }
                }
              }
            }
            ERR_put_error(0x22,0xa4,0x93,"v3_alt.c",0x1ee);
          }
        }
LAB_0816e7bb:
        GENERAL_NAME_free(pGVar4);
LAB_0816e733:
        sk_pop_free(st,GENERAL_NAME_free);
        return (_STACK *)0x0;
      }
      pcVar14 = *(char **)((int)pvVar2 + 8);
      bVar16 = pcVar14 == (char *)0x0;
      if (bVar16) {
LAB_0816e7e0:
        ERR_put_error(0x22,0x75,0x7c,"v3_alt.c",0x219);
        goto LAB_0816e733;
      }
      iVar1 = 5;
      pcVar7 = pcVar14;
      pcVar15 = "move";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar16 = *pcVar7 == *pcVar15;
        pcVar7 = pcVar7 + (uint)bVar17 * -2 + 1;
        pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
      } while (bVar16);
      if (!bVar16) {
        pcVar7 = *(char **)((int)pvVar2 + 4);
        goto LAB_0816e6d7;
      }
      if (param_2 == (X509V3_CTX *)0x0) {
LAB_0816ec10:
        pGVar4 = (GENERAL_NAME *)0x0;
        pAVar5 = (ASN1_STRING *)0x0;
        ERR_put_error(0x22,0x7a,0x7d,"v3_alt.c",0x161);
LAB_0816eacb:
        GENERAL_NAME_free(pGVar4);
        ASN1_STRING_free(pAVar5);
        goto LAB_0816e733;
      }
      if (param_2->flags == 1) goto LAB_0816e902;
      if (param_2->subject_cert == (X509 *)0x0) {
        if (param_2->subject_req == (X509_REQ *)0x0) goto LAB_0816ec10;
        pXVar13 = param_2->subject_req->req_info->subject;
      }
      else {
        pXVar13 = X509_get_subject_name(param_2->subject_cert);
      }
      iVar1 = -1;
      while (iVar3 = X509_NAME_get_index_by_NID(pXVar13,0x30,iVar1), -1 < iVar3) {
        pXVar10 = X509_NAME_get_entry(pXVar13,iVar3);
        pAVar5 = X509_NAME_ENTRY_get_data(pXVar10);
        pAVar5 = ASN1_STRING_dup(pAVar5);
        iVar1 = iVar3 + -1;
        X509_NAME_delete_entry(pXVar13,iVar3);
        X509_NAME_ENTRY_free(pXVar10);
        if ((pAVar5 == (ASN1_STRING *)0x0) ||
           (pGVar4 = GENERAL_NAME_new(), pGVar4 == (GENERAL_NAME *)0x0)) {
          pGVar4 = (GENERAL_NAME *)0x0;
          ERR_put_error(0x22,0x7a,0x41,"v3_alt.c",0x175);
          goto LAB_0816eacb;
        }
        (pGVar4->d).otherName = (OTHERNAME *)pAVar5;
        pGVar4->type = 1;
        iVar3 = sk_push(st,pGVar4);
        if (iVar3 == 0) {
          pAVar5 = (ASN1_STRING *)0x0;
          ERR_put_error(0x22,0x7a,0x41,"v3_alt.c",0x17c);
          goto LAB_0816eacb;
        }
      }
    }
LAB_0816e902:
    local_20 = local_20 + 1;
  } while( true );
}

