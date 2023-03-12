
_STACK * r2i_certpol(undefined4 param_1,X509V3_CTX *param_2,char *param_3)

{
  bool bVar1;
  _STACK *st;
  _STACK *st_00;
  ASN1_OBJECT *pAVar2;
  ASN1_OBJECT **val;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  _STACK *section;
  ASN1_OBJECT **ppAVar6;
  size_t sVar7;
  _STACK *section_00;
  ASN1_STRING **ppAVar8;
  int iVar9;
  _STACK *st_01;
  void *pvVar10;
  ASN1_INTEGER *data;
  int iVar11;
  int *piVar12;
  char *pcVar13;
  ASN1_STRING *str;
  ASN1_VALUE *pAVar14;
  _STACK *st_02;
  int local_48;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x82,0x41,"v3_cpols.c",0x93);
  }
  else {
    st_00 = (_STACK *)X509V3_parse_list(param_3);
    if (st_00 != (_STACK *)0x0) {
      bVar1 = false;
      local_48 = 0;
LAB_000d2f88:
      iVar3 = sk_num(st_00);
      if (iVar3 <= local_48) {
        sk_pop_free(st_00,X509V3_conf_free + 1);
        return st;
      }
      puVar4 = (undefined4 *)sk_value(st_00,local_48);
      iVar3 = puVar4[2];
      if ((iVar3 == 0) && (pcVar13 = (char *)puVar4[1], pcVar13 != (char *)0x0)) {
        iVar5 = strcmp(pcVar13,"ia5org");
        if (iVar5 == 0) {
          bVar1 = true;
LAB_000d2f82:
          local_48 = local_48 + 1;
          goto LAB_000d2f88;
        }
        if (*pcVar13 == '@') {
          section = (_STACK *)X509V3_get_section(param_2,pcVar13 + 1);
          if (section == (_STACK *)0x0) {
            iVar5 = 0xac;
            iVar3 = 0x87;
            goto LAB_000d338c;
          }
          val = (ASN1_OBJECT **)ASN1_item_new((ASN1_ITEM *)&POLICYINFO_it);
          if (val == (ASN1_OBJECT **)0x0) {
LAB_000d3090:
            ERR_put_error(0x22,0x83,0x41,"v3_cpols.c",0x11c);
          }
          else {
            for (; iVar5 = sk_num(section), iVar3 < iVar5; iVar3 = iVar3 + 1) {
              puVar4 = (undefined4 *)sk_value(section,iVar3);
              pcVar13 = (char *)puVar4[1];
              iVar5 = strcmp(pcVar13,"policyIdentifier");
              if (iVar5 == 0) {
                pAVar2 = OBJ_txt2obj((char *)puVar4[2],0);
                if (pAVar2 == (ASN1_OBJECT *)0x0) {
                  iVar5 = 0xe0;
                  iVar3 = 0x6e;
                  goto LAB_000d3440;
                }
                *val = pAVar2;
              }
              else {
                iVar5 = name_cmp(pcVar13,"CPS");
                if (iVar5 != 0) {
                  iVar5 = name_cmp((char *)puVar4[1],"userNotice");
                  if (iVar5 == 0) {
                    if (*(char *)puVar4[2] == '@') {
                      section_00 = (_STACK *)X509V3_get_section(param_2,(char *)puVar4[2] + 1);
                      if (section_00 != (_STACK *)0x0) {
                        ppAVar6 = (ASN1_OBJECT **)
                                  ASN1_item_new((ASN1_ITEM *)PTR_POLICYQUALINFO_it_000d3364);
                        if (ppAVar6 == (ASN1_OBJECT **)0x0) {
LAB_000d323a:
                          ERR_put_error(0x22,0x84,0x41,"v3_cpols.c",0x16f);
                        }
                        else {
                          pAVar2 = OBJ_nid2obj(0xa5);
                          *ppAVar6 = pAVar2;
                          if (pAVar2 == (ASN1_OBJECT *)0x0) {
                            ERR_put_error(0x22,0x84,0x44,"v3_cpols.c",0x12e);
                          }
                          else {
                            pAVar2 = (ASN1_OBJECT *)
                                     ASN1_item_new((ASN1_ITEM *)PTR_USERNOTICE_it_000d3368);
                            if (pAVar2 == (ASN1_OBJECT *)0x0) goto LAB_000d323a;
                            ppAVar6[1] = pAVar2;
                            for (; iVar9 = sk_num(section_00), iVar5 < iVar9; iVar5 = iVar5 + 1) {
                              puVar4 = (undefined4 *)sk_value(section_00,iVar5);
                              pcVar13 = (char *)puVar4[1];
                              iVar9 = strcmp(pcVar13,"explicitText");
                              if (iVar9 == 0) {
                                str = ASN1_STRING_type_new(0x1a);
                                pAVar2->ln = (char **)str;
                                if (str == (ASN1_STRING *)0x0) goto LAB_000d323a;
LAB_000d3162:
                                pcVar13 = (char *)puVar4[2];
                                sVar7 = strlen(pcVar13);
                                iVar9 = ASN1_STRING_set(str,pcVar13,sVar7);
                                if (iVar9 == 0) goto LAB_000d323a;
                              }
                              else {
                                iVar9 = strcmp(pcVar13,"organization");
                                if (iVar9 == 0) {
                                  ppAVar8 = (ASN1_STRING **)pAVar2->sn;
                                  if (ppAVar8 == (ASN1_STRING **)0x0) {
                                    ppAVar8 = (ASN1_STRING **)
                                              ASN1_item_new((ASN1_ITEM *)PTR_NOTICEREF_it_000d336c);
                                    if (ppAVar8 == (ASN1_STRING **)0x0) goto LAB_000d323a;
                                    pAVar2->sn = (char *)ppAVar8;
                                  }
                                  str = *ppAVar8;
                                  if (bVar1) {
                                    str->type = 0x16;
                                  }
                                  else {
                                    str->type = 0x1a;
                                  }
                                  goto LAB_000d3162;
                                }
                                iVar9 = strcmp(pcVar13,"noticeNumbers");
                                if (iVar9 != 0) {
                                  iVar5 = 0x15f;
                                  iVar3 = 0x8a;
LAB_000d32ea:
                                  ERR_put_error(0x22,0x84,iVar3,"v3_cpols.c",iVar5);
                                  ERR_add_error_data(6,"section:",*puVar4,",name:",puVar4[1],
                                                     ",value:",puVar4[2]);
                                  goto LAB_000d3252;
                                }
                                pAVar14 = (ASN1_VALUE *)pAVar2->sn;
                                if (pAVar14 == (ASN1_VALUE *)0x0) {
                                  pAVar14 = ASN1_item_new((ASN1_ITEM *)PTR_NOTICEREF_it_000d336c);
                                  if (pAVar14 != (ASN1_VALUE *)0x0) {
                                    pAVar2->sn = (char *)pAVar14;
                                    st_01 = (_STACK *)X509V3_parse_list((char *)puVar4[2]);
                                    if (st_01 != (_STACK *)0x0) goto LAB_000d31de;
LAB_000d32d6:
                                    iVar5 = 0x156;
                                    iVar3 = 0x8d;
                                    goto LAB_000d32ea;
                                  }
                                  goto LAB_000d323a;
                                }
                                st_01 = (_STACK *)X509V3_parse_list((char *)puVar4[2]);
                                if (st_01 == (_STACK *)0x0) goto LAB_000d32d6;
LAB_000d31de:
                                iVar9 = sk_num(st_01);
                                if (iVar9 == 0) goto LAB_000d32d6;
                                st_02 = *(_STACK **)(pAVar14 + 4);
                                iVar9 = 0;
LAB_000d3208:
                                iVar11 = sk_num(st_01);
                                if (iVar9 < iVar11) {
                                  pvVar10 = sk_value(st_01,iVar9);
                                  data = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,
                                                          *(char **)((int)pvVar10 + 4));
                                  if (data != (ASN1_INTEGER *)0x0) goto code_r0x000d3200;
                                  ERR_put_error(0x22,0x85,0x8c,"v3_cpols.c",0x180);
                                  goto LAB_000d3282;
                                }
                                sk_pop_free(st_01,X509V3_conf_free + 1);
                              }
                            }
                            piVar12 = (int *)pAVar2->sn;
                            if ((piVar12 == (int *)0x0) || ((piVar12[1] != 0 && (*piVar12 != 0)))) {
                              X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section_00);
                              pAVar2 = val[1];
                              if (pAVar2 == (ASN1_OBJECT *)0x0) {
                                pAVar2 = (ASN1_OBJECT *)sk_new_null();
                                val[1] = pAVar2;
                              }
                              iVar5 = sk_push((_STACK *)pAVar2,ppAVar6);
                              if (iVar5 != 0) goto LAB_000d3000;
                              goto LAB_000d3090;
                            }
                            ERR_put_error(0x22,0x84,0x8e,"v3_cpols.c",0x168);
                          }
                        }
LAB_000d3252:
                        ASN1_item_free((ASN1_VALUE *)ppAVar6,
                                       (ASN1_ITEM *)PTR_POLICYQUALINFO_it_000d3364);
                        X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section_00);
                        goto LAB_000d30a8;
                      }
                      iVar5 = 0x100;
                      iVar3 = 0x87;
                    }
                    else {
                      iVar5 = 0xfa;
                      iVar3 = 0x89;
                    }
                  }
                  else {
                    iVar5 = 0x10e;
                    iVar3 = 0x8a;
                  }
LAB_000d3440:
                  ERR_put_error(0x22,0x83,iVar3,"v3_cpols.c",iVar5);
                  ERR_add_error_data(6,"section:",*puVar4,",name:",puVar4[1],",value:",puVar4[2]);
                  goto LAB_000d30a8;
                }
                if (val[1] == (ASN1_OBJECT *)0x0) {
                  pAVar2 = (ASN1_OBJECT *)sk_new_null();
                  val[1] = pAVar2;
                }
                ppAVar6 = (ASN1_OBJECT **)ASN1_item_new((ASN1_ITEM *)PTR_POLICYQUALINFO_it_000d3364)
                ;
                if ((ppAVar6 == (ASN1_OBJECT **)0x0) ||
                   (iVar5 = sk_push((_STACK *)val[1],ppAVar6), iVar5 == 0)) goto LAB_000d3090;
                pAVar2 = OBJ_nid2obj(0xa4);
                *ppAVar6 = pAVar2;
                if (pAVar2 == (ASN1_OBJECT *)0x0) {
                  ERR_put_error(0x22,0x83,0x44,"v3_cpols.c",0xee);
                  goto LAB_000d30a8;
                }
                pAVar2 = (ASN1_OBJECT *)ASN1_STRING_type_new(0x16);
                ppAVar6[1] = pAVar2;
                if (pAVar2 == (ASN1_OBJECT *)0x0) goto LAB_000d3090;
                pcVar13 = (char *)puVar4[2];
                sVar7 = strlen(pcVar13);
                iVar5 = ASN1_STRING_set((ASN1_STRING *)pAVar2,pcVar13,sVar7);
                if (iVar5 == 0) goto LAB_000d3090;
              }
LAB_000d3000:
            }
            if (*val != (ASN1_OBJECT *)0x0) {
              X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section);
              iVar3 = sk_push(st,val);
              if (iVar3 == 0) goto LAB_000d33dc;
              goto LAB_000d2f82;
            }
            ERR_put_error(0x22,0x83,0x8b,"v3_cpols.c",0x115);
          }
LAB_000d30a8:
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&POLICYINFO_it);
          X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section);
          goto LAB_000d30be;
        }
        pAVar2 = OBJ_txt2obj(pcVar13,0);
        if (pAVar2 != (ASN1_OBJECT *)0x0) {
          val = (ASN1_OBJECT **)ASN1_item_new((ASN1_ITEM *)&POLICYINFO_it);
          if (val == (ASN1_OBJECT **)0x0) {
            ERR_put_error(0x22,0x82,0x41,"v3_cpols.c",0xbe);
          }
          else {
            *val = pAVar2;
            iVar3 = sk_push(st,val);
            if (iVar3 != 0) goto LAB_000d2f82;
LAB_000d33dc:
            ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&POLICYINFO_it);
            ERR_put_error(0x22,0x82,0x41,"v3_cpols.c",0xc5);
          }
          goto LAB_000d30be;
        }
        iVar5 = 0xb8;
        iVar3 = 0x6e;
      }
      else {
        iVar5 = 0xa0;
        iVar3 = 0x86;
      }
LAB_000d338c:
      ERR_put_error(0x22,0x82,iVar3,"v3_cpols.c",iVar5);
      ERR_add_error_data(6,"section:",*puVar4,",name:",puVar4[1],",value:",puVar4[2]);
      goto LAB_000d30be;
    }
    ERR_put_error(0x22,0x82,0x22,"v3_cpols.c",0x98);
LAB_000d30be:
    sk_pop_free(st_00,X509V3_conf_free + 1);
    sk_pop_free(st,POLICYINFO_free + 1);
    st = (_STACK *)0x0;
  }
  return st;
code_r0x000d3200:
  iVar11 = sk_push(st_02,data);
  iVar9 = iVar9 + 1;
  if (iVar11 == 0) {
    ERR_put_error(0x22,0x85,0x41,"v3_cpols.c",0x189);
LAB_000d3282:
    sk_pop_free(st_02,ASN1_STRING_free + 1);
    sk_pop_free(st_01,X509V3_conf_free + 1);
    goto LAB_000d3252;
  }
  goto LAB_000d3208;
}

