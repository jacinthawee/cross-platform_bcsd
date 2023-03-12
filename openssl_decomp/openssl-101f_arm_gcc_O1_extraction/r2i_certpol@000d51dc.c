
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
  int local_44;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x82,0x41,"v3_cpols.c",0x8f);
  }
  else {
    st_00 = (_STACK *)X509V3_parse_list(param_3);
    if (st_00 != (_STACK *)0x0) {
      bVar1 = false;
      local_44 = 0;
LAB_000d5242:
      iVar3 = sk_num(st_00);
      if (iVar3 <= local_44) {
        sk_pop_free(st_00,X509V3_conf_free + 1);
        return st;
      }
      puVar4 = (undefined4 *)sk_value(st_00,local_44);
      iVar3 = puVar4[2];
      if ((iVar3 == 0) && (pcVar13 = (char *)puVar4[1], pcVar13 != (char *)0x0)) {
        iVar5 = strcmp(pcVar13,"ia5org");
        if (iVar5 == 0) {
          bVar1 = true;
LAB_000d523c:
          local_44 = local_44 + 1;
          goto LAB_000d5242;
        }
        if (*pcVar13 == '@') {
          section = (_STACK *)X509V3_get_section(param_2,pcVar13 + 1);
          if (section == (_STACK *)0x0) {
            iVar5 = 0xa7;
            iVar3 = 0x87;
            goto LAB_000d5680;
          }
          val = (ASN1_OBJECT **)ASN1_item_new((ASN1_ITEM *)&POLICYINFO_it);
          if (val == (ASN1_OBJECT **)0x0) {
LAB_000d5342:
            ERR_put_error(0x22,0x83,0x41,"v3_cpols.c",0x107);
          }
          else {
            for (; iVar5 = sk_num(section), iVar3 < iVar5; iVar3 = iVar3 + 1) {
              puVar4 = (undefined4 *)sk_value(section,iVar3);
              pcVar13 = (char *)puVar4[1];
              iVar5 = strcmp(pcVar13,"policyIdentifier");
              if (iVar5 == 0) {
                pAVar2 = OBJ_txt2obj((char *)puVar4[2],0);
                if (pAVar2 == (ASN1_OBJECT *)0x0) {
                  iVar5 = 0xd3;
                  iVar3 = 0x6e;
                  goto LAB_000d56ee;
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
                                  ASN1_item_new((ASN1_ITEM *)PTR_POLICYQUALINFO_it_000d561c);
                        if (ppAVar6 == (ASN1_OBJECT **)0x0) {
LAB_000d55f6:
                          ERR_put_error(0x22,0x84,0x41,"v3_cpols.c",0x14c);
                        }
                        else {
                          pAVar2 = OBJ_nid2obj(0xa5);
                          *ppAVar6 = pAVar2;
                          pAVar2 = (ASN1_OBJECT *)
                                   ASN1_item_new((ASN1_ITEM *)PTR_USERNOTICE_it_000d5620);
                          if (pAVar2 == (ASN1_OBJECT *)0x0) goto LAB_000d55f6;
                          ppAVar6[1] = pAVar2;
                          for (; iVar9 = sk_num(section_00), iVar5 < iVar9; iVar5 = iVar5 + 1) {
                            puVar4 = (undefined4 *)sk_value(section_00,iVar5);
                            pcVar13 = (char *)puVar4[1];
                            iVar9 = strcmp(pcVar13,"explicitText");
                            if (iVar9 == 0) {
                              str = ASN1_STRING_type_new(0x1a);
                              pcVar13 = (char *)puVar4[2];
                              pAVar2->ln = (char **)str;
LAB_000d5410:
                              sVar7 = strlen(pcVar13);
                              iVar9 = ASN1_STRING_set(str,pcVar13,sVar7);
                              if (iVar9 == 0) goto LAB_000d55f6;
                            }
                            else {
                              iVar9 = strcmp(pcVar13,"organization");
                              if (iVar9 == 0) {
                                ppAVar8 = (ASN1_STRING **)pAVar2->sn;
                                if (ppAVar8 == (ASN1_STRING **)0x0) {
                                  ppAVar8 = (ASN1_STRING **)
                                            ASN1_item_new((ASN1_ITEM *)PTR_NOTICEREF_it_000d5624);
                                  if (ppAVar8 == (ASN1_STRING **)0x0) goto LAB_000d55f6;
                                  pAVar2->sn = (char *)ppAVar8;
                                }
                                str = *ppAVar8;
                                if (bVar1) {
                                  str->type = 0x16;
                                }
                                else {
                                  str->type = 0x1a;
                                }
                                pcVar13 = (char *)puVar4[2];
                                goto LAB_000d5410;
                              }
                              iVar9 = strcmp(pcVar13,"noticeNumbers");
                              if (iVar9 != 0) {
                                iVar5 = 0x13d;
                                iVar3 = 0x8a;
LAB_000d557e:
                                ERR_put_error(0x22,0x84,iVar3,"v3_cpols.c",iVar5);
                                ERR_add_error_data(6,"section:",*puVar4,",name:",puVar4[1],",value:"
                                                   ,puVar4[2]);
                                goto LAB_000d5522;
                              }
                              pAVar14 = (ASN1_VALUE *)pAVar2->sn;
                              if (pAVar14 == (ASN1_VALUE *)0x0) {
                                pAVar14 = ASN1_item_new((ASN1_ITEM *)PTR_NOTICEREF_it_000d5624);
                                if (pAVar14 != (ASN1_VALUE *)0x0) {
                                  pAVar2->sn = (char *)pAVar14;
                                  st_01 = (_STACK *)X509V3_parse_list((char *)puVar4[2]);
                                  if (st_01 != (_STACK *)0x0) goto LAB_000d548c;
LAB_000d556a:
                                  iVar5 = 0x134;
                                  iVar3 = 0x8d;
                                  goto LAB_000d557e;
                                }
                                goto LAB_000d55f6;
                              }
                              st_01 = (_STACK *)X509V3_parse_list((char *)puVar4[2]);
                              if (st_01 == (_STACK *)0x0) goto LAB_000d556a;
LAB_000d548c:
                              iVar9 = sk_num(st_01);
                              if (iVar9 == 0) goto LAB_000d556a;
                              st_02 = *(_STACK **)(pAVar14 + 4);
                              iVar9 = 0;
LAB_000d54b6:
                              iVar11 = sk_num(st_01);
                              if (iVar9 < iVar11) {
                                pvVar10 = sk_value(st_01,iVar9);
                                data = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,
                                                        *(char **)((int)pvVar10 + 4));
                                if (data != (ASN1_INTEGER *)0x0) goto code_r0x000d54ae;
                                ERR_put_error(0x22,0x85,0x8c,"v3_cpols.c",0x15d);
                                goto LAB_000d5506;
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
                            if (iVar5 != 0) goto LAB_000d52ba;
                            goto LAB_000d5342;
                          }
                          ERR_put_error(0x22,0x84,0x8e,"v3_cpols.c",0x145);
                        }
LAB_000d5522:
                        ASN1_item_free((ASN1_VALUE *)ppAVar6,
                                       (ASN1_ITEM *)PTR_POLICYQUALINFO_it_000d561c);
                        X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section_00);
                        goto LAB_000d535a;
                      }
                      iVar5 = 0xec;
                      iVar3 = 0x87;
                    }
                    else {
                      iVar5 = 0xe6;
                      iVar3 = 0x89;
                    }
                  }
                  else {
                    iVar5 = 0xf9;
                    iVar3 = 0x8a;
                  }
LAB_000d56ee:
                  ERR_put_error(0x22,0x83,iVar3,"v3_cpols.c",iVar5);
                  ERR_add_error_data(6,"section:",*puVar4,",name:",puVar4[1],",value:",puVar4[2]);
                  goto LAB_000d535a;
                }
                if (val[1] == (ASN1_OBJECT *)0x0) {
                  pAVar2 = (ASN1_OBJECT *)sk_new_null();
                  val[1] = pAVar2;
                }
                ppAVar6 = (ASN1_OBJECT **)ASN1_item_new((ASN1_ITEM *)PTR_POLICYQUALINFO_it_000d561c)
                ;
                if ((ppAVar6 == (ASN1_OBJECT **)0x0) ||
                   (iVar5 = sk_push((_STACK *)val[1],ppAVar6), iVar5 == 0)) goto LAB_000d5342;
                pAVar2 = OBJ_nid2obj(0xa4);
                *ppAVar6 = pAVar2;
                pAVar2 = (ASN1_OBJECT *)ASN1_STRING_type_new(0x16);
                ppAVar6[1] = pAVar2;
                pcVar13 = (char *)puVar4[2];
                sVar7 = strlen(pcVar13);
                iVar5 = ASN1_STRING_set((ASN1_STRING *)pAVar2,pcVar13,sVar7);
                if (iVar5 == 0) goto LAB_000d5342;
              }
LAB_000d52ba:
            }
            if (*val != (ASN1_OBJECT *)0x0) {
              X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section);
              iVar3 = sk_push(st,val);
              if (iVar3 == 0) goto LAB_000d5648;
              goto LAB_000d523c;
            }
            ERR_put_error(0x22,0x83,0x8b,"v3_cpols.c",0x100);
          }
LAB_000d535a:
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&POLICYINFO_it);
          X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section);
          goto LAB_000d5370;
        }
        pAVar2 = OBJ_txt2obj(pcVar13,0);
        if (pAVar2 != (ASN1_OBJECT *)0x0) {
          val = (ASN1_OBJECT **)ASN1_item_new((ASN1_ITEM *)&POLICYINFO_it);
          *val = pAVar2;
          iVar3 = sk_push(st,val);
          if (iVar3 != 0) goto LAB_000d523c;
LAB_000d5648:
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&POLICYINFO_it);
          ERR_put_error(0x22,0x82,0x41,"v3_cpols.c",0xba);
          goto LAB_000d5370;
        }
        iVar5 = 0xb1;
        iVar3 = 0x6e;
      }
      else {
        iVar5 = 0x9b;
        iVar3 = 0x86;
      }
LAB_000d5680:
      ERR_put_error(0x22,0x82,iVar3,"v3_cpols.c",iVar5);
      ERR_add_error_data(6,"section:",*puVar4,",name:",puVar4[1],",value:",puVar4[2]);
      goto LAB_000d5370;
    }
    ERR_put_error(0x22,0x82,0x22,"v3_cpols.c",0x94);
LAB_000d5370:
    sk_pop_free(st_00,X509V3_conf_free + 1);
    sk_pop_free(st,POLICYINFO_free + 1);
    st = (_STACK *)0x0;
  }
  return st;
code_r0x000d54ae:
  iVar11 = sk_push(st_02,data);
  iVar9 = iVar9 + 1;
  if (iVar11 == 0) {
    ERR_put_error(0x22,0x85,0x41,"v3_cpols.c",0x165);
LAB_000d5506:
    sk_pop_free(st_02,ASN1_STRING_free + 1);
    sk_pop_free(st_01,X509V3_conf_free + 1);
    goto LAB_000d5522;
  }
  goto LAB_000d54b6;
}

