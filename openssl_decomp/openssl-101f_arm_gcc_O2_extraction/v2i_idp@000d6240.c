
ASN1_VALUE ** v2i_idp(undefined4 param_1,X509V3_CTX *param_2,_STACK *param_3)

{
  ASN1_VALUE **val;
  int iVar1;
  CONF_VALUE *value;
  _STACK *p_Var2;
  _STACK *st;
  X509_NAME *nm;
  stack_st_CONF_VALUE *dn_sk;
  void *pvVar3;
  ASN1_VALUE **ppAVar4;
  ASN1_VALUE *pAVar5;
  int iVar6;
  char *__s1;
  char *line;
  
  val = (ASN1_VALUE **)ASN1_item_new((ASN1_ITEM *)PTR_ISSUING_DIST_POINT_it_000d6538);
  if (val == (ASN1_VALUE **)0x0) {
    ERR_put_error(0x22,0x9d,0x41,"v3_crld.c",0x1f5);
LAB_000d6392:
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PTR_ISSUING_DIST_POINT_it_000d6538);
    return (ASN1_VALUE **)0x0;
  }
  iVar6 = 0;
  do {
    iVar1 = sk_num(param_3);
    if (iVar1 <= iVar6) {
      return val;
    }
    value = (CONF_VALUE *)sk_value(param_3,iVar6);
    __s1 = value->name;
    line = value->value;
    iVar1 = strcmp(__s1,"fullname");
    if (iVar1 == 0) {
      if (*line == '@') {
        p_Var2 = (_STACK *)X509V3_get_section(param_2,line + 1);
      }
      else {
        p_Var2 = (_STACK *)X509V3_parse_list(line);
      }
      if (p_Var2 == (_STACK *)0x0) {
        ERR_put_error(0x22,0x9c,0x96,"v3_crld.c",0x68);
      }
      else {
        st = (_STACK *)
             v2i_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,param_2,(stack_st_CONF_VALUE *)p_Var2);
        if (*line == '@') {
          X509V3_section_free(param_2,(stack_st_CONF_VALUE *)p_Var2);
        }
        else {
          sk_pop_free(p_Var2,X509V3_conf_free + 1);
        }
        if (st != (_STACK *)0x0) {
          p_Var2 = (_STACK *)0x0;
LAB_000d6352:
          pAVar5 = *val;
          if (pAVar5 == (ASN1_VALUE *)0x0) {
            ppAVar4 = (ASN1_VALUE **)ASN1_item_new((ASN1_ITEM *)PTR_DIST_POINT_NAME_it_000d653c);
            *val = (ASN1_VALUE *)ppAVar4;
            if (ppAVar4 != (ASN1_VALUE **)0x0) {
              if (st == (_STACK *)0x0) {
                ppAVar4[1] = (ASN1_VALUE *)p_Var2;
                pAVar5 = (ASN1_VALUE *)0x1;
              }
              else {
                ppAVar4[1] = (ASN1_VALUE *)st;
              }
              *ppAVar4 = pAVar5;
              goto LAB_000d62e4;
            }
          }
          else {
            ERR_put_error(0x22,0x9e,0xa0,"v3_crld.c",0xa5);
          }
          if (st != (_STACK *)0x0) {
            sk_pop_free(st,GENERAL_NAME_free + 1);
          }
LAB_000d6382:
          if (p_Var2 != (_STACK *)0x0) {
            sk_pop_free(p_Var2,X509_NAME_ENTRY_free + 1);
          }
        }
      }
      goto LAB_000d6392;
    }
    iVar1 = strcmp(__s1,"relativename");
    if (iVar1 == 0) {
      nm = X509_NAME_new();
      if (nm != (X509_NAME *)0x0) {
        dn_sk = X509V3_get_section(param_2,value->value);
        if (dn_sk != (stack_st_CONF_VALUE *)0x0) {
          iVar1 = X509V3_NAME_from_section(nm,dn_sk,0x1001);
          X509V3_section_free(param_2,dn_sk);
          p_Var2 = (_STACK *)nm->entries;
          nm->entries = (stack_st_X509_NAME_ENTRY *)0x0;
          X509_NAME_free(nm);
          if ((iVar1 != 0) && (iVar1 = sk_num(p_Var2), 0 < iVar1)) {
            iVar1 = sk_num(p_Var2);
            pvVar3 = sk_value(p_Var2,iVar1 + -1);
            st = *(_STACK **)((int)pvVar3 + 8);
            if (st == (_STACK *)0x0) goto LAB_000d6352;
            ERR_put_error(0x22,0x9e,0xa1,"v3_crld.c",0x9b);
          }
          goto LAB_000d6382;
        }
        ERR_put_error(0x22,0x9e,0x96,"v3_crld.c",0x8a);
      }
      goto LAB_000d6392;
    }
    iVar1 = strcmp(__s1,"onlyuser");
    if (iVar1 == 0) {
      iVar1 = X509V3_get_value_bool(value,(int *)(val + 1));
    }
    else {
      iVar1 = strcmp(__s1,"onlyCA");
      if (iVar1 == 0) {
        iVar1 = X509V3_get_value_bool(value,(int *)(val + 2));
      }
      else {
        iVar1 = strcmp(__s1,"onlyAA");
        if (iVar1 == 0) {
          iVar1 = X509V3_get_value_bool(value,(int *)(val + 5));
          if (iVar1 != 0) goto LAB_000d62e4;
          goto LAB_000d6392;
        }
        iVar1 = strcmp(__s1,"indirectCRL");
        if (iVar1 == 0) {
          iVar1 = X509V3_get_value_bool(value,(int *)(val + 4));
        }
        else {
          iVar1 = strcmp(__s1,"onlysomereasons");
          if (iVar1 != 0) {
            ERR_put_error(0x22,0x9d,0x6a,"v3_crld.c",0x1ed);
            ERR_add_error_data(6,"section:",value->section,",name:",value->name,",value:",
                               value->value);
            goto LAB_000d6392;
          }
          iVar1 = set_reasons(val + 3,line);
        }
      }
    }
    if (iVar1 == 0) goto LAB_000d6392;
LAB_000d62e4:
    iVar6 = iVar6 + 1;
  } while( true );
}

