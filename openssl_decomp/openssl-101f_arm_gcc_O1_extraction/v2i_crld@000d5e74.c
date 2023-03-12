
_STACK * v2i_crld(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,_STACK *param_3)

{
  _STACK *st;
  int iVar1;
  CONF_VALUE *cnf;
  _STACK *p_Var2;
  int **val;
  void *pvVar3;
  _STACK *p_Var4;
  _STACK *p_Var5;
  X509_NAME *nm;
  stack_st_CONF_VALUE *dn_sk;
  int *piVar6;
  GENERAL_NAMES *pGVar7;
  char *pcVar8;
  char *pcVar9;
  int *piVar10;
  int iVar11;
  
  st = sk_new_null();
  p_Var2 = st;
  p_Var4 = st;
  if (st == (_STACK *)0x0) {
LAB_000d6184:
    ERR_put_error(0x22,0x86,0x41,"v3_crld.c",0x16d);
LAB_000d6028:
    GENERAL_NAME_free((GENERAL_NAME *)p_Var2);
    GENERAL_NAMES_free((GENERAL_NAMES *)p_Var4);
    sk_pop_free(st,DIST_POINT_free + 1);
    return (_STACK *)0x0;
  }
  iVar11 = 0;
  do {
    iVar1 = sk_num(param_3);
    if (iVar1 <= iVar11) {
      return st;
    }
    cnf = (CONF_VALUE *)sk_value(param_3,iVar11);
    pcVar8 = cnf->value;
    if (pcVar8 == (char *)0x0) {
      p_Var2 = (_STACK *)X509V3_get_section(param_2,cnf->name);
      if (p_Var2 == (_STACK *)0x0) {
LAB_000d61d4:
        p_Var2 = (_STACK *)0x0;
        p_Var4 = p_Var2;
        goto LAB_000d6028;
      }
      val = (int **)ASN1_item_new((ASN1_ITEM *)PTR_DIST_POINT_it_000d61e8);
      if (val == (int **)0x0) {
LAB_000d601c:
        X509V3_section_free(param_2,(stack_st_CONF_VALUE *)p_Var2);
        p_Var2 = (_STACK *)0x0;
        p_Var4 = (_STACK *)0x0;
        goto LAB_000d6028;
      }
      for (; iVar1 = sk_num(p_Var2), (int)pcVar8 < iVar1; pcVar8 = pcVar8 + 1) {
        pvVar3 = sk_value(p_Var2,(int)pcVar8);
        pcVar9 = *(char **)((int)pvVar3 + 4);
        iVar1 = strcmp(pcVar9,"fullname");
        if (iVar1 == 0) {
          pcVar9 = *(char **)((int)pvVar3 + 8);
          if (*pcVar9 == '@') {
            p_Var4 = (_STACK *)X509V3_get_section(param_2,pcVar9 + 1);
          }
          else {
            p_Var4 = (_STACK *)X509V3_parse_list(pcVar9);
          }
          if (p_Var4 == (_STACK *)0x0) {
            ERR_put_error(0x22,0x9c,0x96,"v3_crld.c",0x68);
          }
          else {
            p_Var5 = (_STACK *)
                     v2i_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,param_2,
                                       (stack_st_CONF_VALUE *)p_Var4);
            if (*pcVar9 == '@') {
              X509V3_section_free(param_2,(stack_st_CONF_VALUE *)p_Var4);
            }
            else {
              sk_pop_free(p_Var4,X509V3_conf_free + 1);
            }
            if (p_Var5 != (_STACK *)0x0) {
              p_Var4 = (_STACK *)0x0;
              piVar10 = *val;
joined_r0x000d60b8:
              if (piVar10 == (int *)0x0) {
                piVar6 = (int *)ASN1_item_new((ASN1_ITEM *)PTR_DIST_POINT_NAME_it_000d61ec);
                *val = piVar6;
                if (piVar6 != (int *)0x0) {
                  if (p_Var5 == (_STACK *)0x0) {
                    piVar6[1] = (int)p_Var4;
                    piVar10 = (int *)0x1;
                  }
                  else {
                    piVar6[1] = (int)p_Var5;
                  }
                  *piVar6 = (int)piVar10;
                  goto LAB_000d5f64;
                }
              }
              else {
                ERR_put_error(0x22,0x9e,0xa0,"v3_crld.c",0xa5);
              }
              if (p_Var5 != (_STACK *)0x0) {
                sk_pop_free(p_Var5,GENERAL_NAME_free);
              }
LAB_000d6004:
              if (p_Var4 != (_STACK *)0x0) {
                sk_pop_free(p_Var4,X509_NAME_ENTRY_free + 1);
              }
            }
          }
LAB_000d6014:
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PTR_DIST_POINT_it_000d61e8);
          goto LAB_000d601c;
        }
        iVar1 = strcmp(pcVar9,"relativename");
        if (iVar1 == 0) {
          nm = X509_NAME_new();
          if (nm != (X509_NAME *)0x0) {
            dn_sk = X509V3_get_section(param_2,*(char **)((int)pvVar3 + 8));
            if (dn_sk != (stack_st_CONF_VALUE *)0x0) {
              iVar1 = X509V3_NAME_from_section(nm,dn_sk,0x1001);
              X509V3_section_free(param_2,dn_sk);
              p_Var4 = (_STACK *)nm->entries;
              nm->entries = (stack_st_X509_NAME_ENTRY *)0x0;
              X509_NAME_free(nm);
              if ((iVar1 != 0) && (iVar1 = sk_num(p_Var4), 0 < iVar1)) {
                iVar1 = sk_num(p_Var4);
                pvVar3 = sk_value(p_Var4,iVar1 + -1);
                p_Var5 = *(_STACK **)((int)pvVar3 + 8);
                if (p_Var5 == (_STACK *)0x0) {
                  piVar10 = *val;
                  goto joined_r0x000d60b8;
                }
                ERR_put_error(0x22,0x9e,0xa1,"v3_crld.c",0x9b);
              }
              goto LAB_000d6004;
            }
            ERR_put_error(0x22,0x9e,0x96,"v3_crld.c",0x8a);
          }
          goto LAB_000d6014;
        }
        iVar1 = strcmp(pcVar9,"reasons");
        if (iVar1 == 0) {
          iVar1 = set_reasons(val + 1,*(undefined4 *)((int)pvVar3 + 8));
          if (iVar1 == 0) goto LAB_000d6014;
        }
        else {
          iVar1 = strcmp(pcVar9,"CRLissuer");
          if (iVar1 == 0) {
            pcVar9 = *(char **)((int)pvVar3 + 8);
            if (*pcVar9 == '@') {
              p_Var4 = (_STACK *)X509V3_get_section(param_2,pcVar9 + 1);
            }
            else {
              p_Var4 = (_STACK *)X509V3_parse_list(pcVar9);
            }
            if (p_Var4 == (_STACK *)0x0) {
              ERR_put_error(0x22,0x9c,0x96,"v3_crld.c",0x68);
              val[2] = (int *)0x0;
            }
            else {
              pGVar7 = v2i_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,param_2,
                                         (stack_st_CONF_VALUE *)p_Var4);
              if (*pcVar9 == '@') {
                X509V3_section_free(param_2,(stack_st_CONF_VALUE *)p_Var4);
              }
              else {
                sk_pop_free(p_Var4,X509V3_conf_free + 1);
              }
              val[2] = (int *)pGVar7;
              if (pGVar7 != (GENERAL_NAMES *)0x0) goto LAB_000d5f64;
            }
            goto LAB_000d6014;
          }
        }
LAB_000d5f64:
      }
      X509V3_section_free(param_2,(stack_st_CONF_VALUE *)p_Var2);
      p_Var2 = (_STACK *)sk_push(st,val);
      if (p_Var2 == (_STACK *)0x0) {
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PTR_DIST_POINT_it_000d61e8);
        p_Var4 = p_Var2;
        goto LAB_000d6184;
      }
    }
    else {
      p_Var2 = (_STACK *)v2i_GENERAL_NAME(param_1,param_2,cnf);
      if (p_Var2 == (_STACK *)0x0) goto LAB_000d61d4;
      p_Var4 = (_STACK *)GENERAL_NAMES_new();
      if (((p_Var4 == (_STACK *)0x0) || (iVar1 = sk_push(p_Var4,p_Var2), iVar1 == 0)) ||
         (p_Var5 = (_STACK *)ASN1_item_new((ASN1_ITEM *)PTR_DIST_POINT_it_000d61e8), p_Var2 = p_Var5
         , p_Var5 == (_STACK *)0x0)) goto LAB_000d6184;
      p_Var2 = (_STACK *)sk_push(st,p_Var5);
      if (p_Var2 == (_STACK *)0x0) {
        ASN1_item_free((ASN1_VALUE *)p_Var5,(ASN1_ITEM *)PTR_DIST_POINT_it_000d623c);
        goto LAB_000d6184;
      }
      p_Var2 = (_STACK *)ASN1_item_new((ASN1_ITEM *)PTR_DIST_POINT_NAME_it_000d61ec);
      p_Var5->num = (int)p_Var2;
      if (p_Var2 == (_STACK *)0x0) goto LAB_000d6184;
      p_Var2->data = (char **)p_Var4;
      p_Var2->num = 0;
    }
    iVar11 = iVar11 + 1;
  } while( true );
}

