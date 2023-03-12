
_STACK * v2i_issuer_alt(undefined4 param_1,X509V3_CTX *param_2,_STACK *param_3)

{
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
  X509_EXTENSION *ext;
  _STACK *p_Var8;
  ASN1_OBJECT *pAVar9;
  ASN1_OCTET_STRING *pAVar10;
  X509_NAME *a_00;
  stack_st_CONF_VALUE *dn_sk;
  char *__s;
  char *pcVar11;
  bool bVar12;
  byte bVar13;
  int local_24;
  
  bVar13 = 0;
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x99,0x41,"v3_alt.c",0xfa);
  }
  else {
    local_24 = 0;
    while( true ) {
      iVar1 = sk_num(param_3);
      if (iVar1 <= local_24) {
        return st;
      }
      pvVar2 = sk_value(param_3,local_24);
      iVar1 = name_cmp(*(char **)((int)pvVar2 + 4),"issuer");
      if (iVar1 != 0) break;
      __s = *(char **)((int)pvVar2 + 8);
      bVar12 = __s == (char *)0x0;
      if (bVar12) {
LAB_0816e160:
        ERR_put_error(0x22,0x75,0x7c,"v3_alt.c",0x219);
        goto LAB_0816e0b3;
      }
      iVar1 = 5;
      pcVar5 = __s;
      pcVar11 = "copy";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar12 = *pcVar5 == *pcVar11;
        pcVar5 = pcVar5 + (uint)bVar13 * -2 + 1;
        pcVar11 = pcVar11 + (uint)bVar13 * -2 + 1;
      } while (bVar12);
      if (!bVar12) {
        pcVar5 = *(char **)((int)pvVar2 + 4);
        goto LAB_0816e057;
      }
      if (param_2 == (X509V3_CTX *)0x0) {
LAB_0816e398:
        ERR_put_error(0x22,0x7b,0x7f,"v3_alt.c",0x119);
        goto LAB_0816e0b3;
      }
      if (param_2->flags != 1) {
        if (param_2->issuer_cert == (X509 *)0x0) goto LAB_0816e398;
        iVar1 = X509_get_ext_by_NID(param_2->issuer_cert,0x55,-1);
        if (-1 < iVar1) {
          ext = X509_get_ext(param_2->issuer_cert,iVar1);
          if ((ext == (X509_EXTENSION *)0x0) ||
             (p_Var8 = (_STACK *)X509V3_EXT_d2i(ext), p_Var8 == (_STACK *)0x0)) {
            ERR_put_error(0x22,0x7b,0x7e,"v3_alt.c",0x120);
            goto LAB_0816e0b3;
          }
          for (iVar1 = 0; iVar3 = sk_num(p_Var8), iVar1 < iVar3; iVar1 = iVar1 + 1) {
            pvVar2 = sk_value(p_Var8,iVar1);
            iVar3 = sk_push(st,pvVar2);
            if (iVar3 == 0) {
              ERR_put_error(0x22,0x7b,0x41,"v3_alt.c",0x127);
              goto LAB_0816e0b3;
            }
          }
          sk_free(p_Var8);
        }
      }
LAB_0816e262:
      local_24 = local_24 + 1;
    }
    __s = *(char **)((int)pvVar2 + 8);
    pcVar5 = *(char **)((int)pvVar2 + 4);
    if (__s == (char *)0x0) goto LAB_0816e160;
LAB_0816e057:
    iVar1 = name_cmp(pcVar5,"email");
    if (iVar1 == 0) {
      a = GENERAL_NAME_new();
      iVar1 = 1;
joined_r0x0816e0e6:
      if (a == (GENERAL_NAME *)0x0) {
LAB_0816e095:
        ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1bc);
        goto LAB_0816e0b3;
      }
      str = ASN1_STRING_type_new(0x16);
      (a->d).otherName = (OTHERNAME *)str;
      if (str != (ASN1_STRING *)0x0) {
        sVar4 = strlen(__s);
        iVar3 = ASN1_STRING_set(str,__s,sVar4);
        if (iVar3 != 0) {
LAB_0816e250:
          a->type = iVar1;
          sk_push(st,a);
          goto LAB_0816e262;
        }
      }
      ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1fd);
    }
    else {
      iVar1 = 6;
      iVar3 = name_cmp(pcVar5,"URI");
      if (iVar3 == 0) {
LAB_0816e08a:
        a = GENERAL_NAME_new();
        goto joined_r0x0816e0e6;
      }
      iVar1 = 2;
      iVar3 = name_cmp(pcVar5,"DNS");
      if (iVar3 == 0) goto LAB_0816e08a;
      iVar1 = name_cmp(pcVar5,"RID");
      if (iVar1 == 0) {
        a = GENERAL_NAME_new();
        if (a != (GENERAL_NAME *)0x0) {
          pAVar9 = OBJ_txt2obj(__s,0);
          if (pAVar9 == (ASN1_OBJECT *)0x0) {
            iVar3 = 0x1ce;
            iVar1 = 0x77;
LAB_0816e460:
            ERR_put_error(0x22,0xa4,iVar1,"v3_alt.c",iVar3);
            ERR_add_error_data(2,"value=",__s);
            goto LAB_0816e13b;
          }
          (a->d).registeredID = pAVar9;
          iVar1 = 8;
          goto LAB_0816e250;
        }
        goto LAB_0816e095;
      }
      iVar1 = name_cmp(pcVar5,"IP");
      if (iVar1 == 0) {
        a = GENERAL_NAME_new();
        if (a == (GENERAL_NAME *)0x0) goto LAB_0816e095;
        pAVar10 = a2i_IPADDRESS(__s);
        (a->d).iPAddress = pAVar10;
        if (pAVar10 == (ASN1_OCTET_STRING *)0x0) {
          iVar3 = 0x1dd;
          iVar1 = 0x76;
          goto LAB_0816e460;
        }
        iVar1 = 7;
        goto LAB_0816e250;
      }
      iVar1 = name_cmp(pcVar5,"dirName");
      if (iVar1 == 0) {
        a = GENERAL_NAME_new();
        if (a == (GENERAL_NAME *)0x0) goto LAB_0816e095;
        a_00 = X509_NAME_new();
        if (a_00 != (X509_NAME *)0x0) {
          dn_sk = X509V3_get_section(param_2,__s);
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
              X509V3_section_free(param_2,dn_sk);
              goto LAB_0816e250;
            }
            X509_NAME_free(a_00);
            (a->d).directoryName = a_00;
            X509V3_section_free(param_2,dn_sk);
          }
        }
        ERR_put_error(0x22,0xa4,0x95,"v3_alt.c",0x1e6);
      }
      else {
        iVar1 = name_cmp(pcVar5,"otherName");
        if (iVar1 != 0) {
          ERR_put_error(0x22,0x75,0x75,"v3_alt.c",0x22d);
          ERR_add_error_data(2,"name=",pcVar5);
          goto LAB_0816e0b3;
        }
        a = GENERAL_NAME_new();
        if (a == (GENERAL_NAME *)0x0) goto LAB_0816e095;
        pcVar5 = strchr(__s,0x3b);
        if (pcVar5 != (char *)0x0) {
          pOVar6 = OTHERNAME_new();
          (a->d).otherName = pOVar6;
          if (pOVar6 != (OTHERNAME *)0x0) {
            ASN1_TYPE_free(pOVar6->value);
            pOVar6 = (a->d).otherName;
            pAVar7 = ASN1_generate_v3(pcVar5 + 1,param_2);
            pOVar6->value = pAVar7;
            if (pAVar7 != (ASN1_TYPE *)0x0) {
              sVar4 = (int)pcVar5 - (int)__s;
              pcVar5 = (char *)CRYPTO_malloc(sVar4 + 1,"v3_alt.c",0x245);
              strncpy(pcVar5,__s,sVar4);
              pcVar5[sVar4] = '\0';
              pOVar6 = (a->d).otherName;
              pAVar9 = OBJ_txt2obj(pcVar5,0);
              pOVar6->type_id = pAVar9;
              CRYPTO_free(pcVar5);
              if (((a->d).otherName)->type_id != (ASN1_OBJECT *)0x0) {
                iVar1 = 0;
                goto LAB_0816e250;
              }
            }
          }
        }
        ERR_put_error(0x22,0xa4,0x93,"v3_alt.c",0x1ee);
      }
    }
LAB_0816e13b:
    GENERAL_NAME_free(a);
LAB_0816e0b3:
    sk_pop_free(st,GENERAL_NAME_free);
  }
  return (_STACK *)0x0;
}

