
_STACK * r2i_certpol(undefined4 param_1,X509V3_CTX *param_2,char *param_3)

{
  _STACK *st;
  int *piVar1;
  ASN1_OBJECT *pAVar2;
  int iVar3;
  undefined4 *puVar4;
  ASN1_OBJECT **ppAVar5;
  size_t sVar6;
  _STACK *st_00;
  void *pvVar7;
  ASN1_INTEGER *data;
  int iVar8;
  ASN1_STRING *str;
  ASN1_VALUE *pAVar9;
  ASN1_STRING **ppAVar10;
  char *pcVar11;
  byte *pbVar12;
  byte *pbVar13;
  char *pcVar14;
  char *pcVar15;
  byte *pbVar16;
  undefined uVar17;
  bool bVar18;
  undefined uVar19;
  byte bVar20;
  int iVar21;
  undefined auStack_4c [8];
  _STACK *local_44;
  int local_40;
  ASN1_OBJECT *local_3c;
  _STACK *local_38;
  ASN1_OBJECT **local_34;
  int local_30;
  _STACK *local_2c;
  int local_28;
  ASN1_OBJECT **local_24;
  _STACK *local_20;
  
  bVar20 = 0;
  local_20 = sk_new_null();
  if (local_20 == (_STACK *)0x0) {
    ERR_put_error(0x22,0x82,0x41,"v3_cpols.c",0x8f);
  }
  else {
    local_2c = (_STACK *)X509V3_parse_list(param_3);
    if (local_2c != (_STACK *)0x0) {
      local_28 = 0;
      local_30 = 0;
LAB_0817192f:
      iVar3 = sk_num(local_2c);
      if (iVar3 <= local_30) {
        sk_pop_free(local_2c,X509V3_conf_free);
        return local_20;
      }
      puVar4 = (undefined4 *)sk_value(local_2c,local_30);
      if (puVar4[2] == 0) {
        pcVar15 = (char *)puVar4[1];
        bVar18 = pcVar15 == (char *)0x0;
        if (bVar18) goto LAB_08171f34;
        iVar3 = 7;
        pcVar11 = pcVar15;
        pcVar14 = "ia5org";
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar18 = *pcVar11 == *pcVar14;
          pcVar11 = pcVar11 + (uint)bVar20 * -2 + 1;
          pcVar14 = pcVar14 + (uint)bVar20 * -2 + 1;
        } while (bVar18);
        if (bVar18) {
          local_28 = 1;
LAB_0817192a:
          local_30 = local_30 + 1;
          goto LAB_0817192f;
        }
        if (*pcVar15 == '@') {
          local_38 = (_STACK *)X509V3_get_section(param_2,pcVar15 + 1);
          if (local_38 == (_STACK *)0x0) {
            iVar21 = 0xa7;
            iVar3 = 0x87;
            goto LAB_08171f46;
          }
          local_34 = (ASN1_OBJECT **)ASN1_item_new((ASN1_ITEM *)POLICYINFO_it);
          if (local_34 == (ASN1_OBJECT **)0x0) {
LAB_08171ae2:
            ERR_put_error(0x22,0x83,0x41,"v3_cpols.c",0x107);
          }
          else {
            local_40 = 0;
            while (iVar3 = sk_num(local_38), local_40 < iVar3) {
              uVar17 = auStack_4c < &DAT_00000008;
              uVar19 = &stack0x00000000 == (undefined *)0x54;
              puVar4 = (undefined4 *)sk_value(local_38,local_40);
              iVar3 = 0x11;
              pbVar13 = (byte *)puVar4[1];
              pbVar12 = (byte *)"policyIdentifier";
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                uVar17 = *pbVar13 < *pbVar12;
                uVar19 = *pbVar13 == *pbVar12;
                pbVar13 = pbVar13 + (uint)bVar20 * -2 + 1;
                pbVar12 = pbVar12 + (uint)bVar20 * -2 + 1;
              } while ((bool)uVar19);
              if ((!(bool)uVar17 && !(bool)uVar19) == (bool)uVar17) {
                pAVar2 = OBJ_txt2obj((char *)puVar4[2],0);
                if (pAVar2 == (ASN1_OBJECT *)0x0) {
                  iVar21 = 0xd3;
                  iVar3 = 0x6e;
                  goto LAB_08171fe7;
                }
                *local_34 = pAVar2;
              }
              else {
                iVar3 = name_cmp((char *)(byte *)puVar4[1],"CPS");
                if (iVar3 != 0) {
                  iVar3 = name_cmp((char *)puVar4[1],"userNotice");
                  if (iVar3 == 0) {
                    if (*(char *)puVar4[2] == '@') {
                      local_44 = (_STACK *)X509V3_get_section(param_2,(char *)puVar4[2] + 1);
                      if (local_44 != (_STACK *)0x0) {
                        ppAVar5 = (ASN1_OBJECT **)ASN1_item_new((ASN1_ITEM *)POLICYQUALINFO_it);
                        local_24 = ppAVar5;
                        if (ppAVar5 == (ASN1_OBJECT **)0x0) {
LAB_08171eb8:
                          ERR_put_error(0x22,0x84,0x41,"v3_cpols.c",0x14c);
                        }
                        else {
                          pAVar2 = OBJ_nid2obj(0xa5);
                          *ppAVar5 = pAVar2;
                          local_3c = (ASN1_OBJECT *)ASN1_item_new((ASN1_ITEM *)USERNOTICE_it);
                          if (local_3c == (ASN1_OBJECT *)0x0) goto LAB_08171eb8;
                          ppAVar5[1] = local_3c;
                          for (iVar3 = 0; iVar21 = sk_num(local_44), iVar3 < iVar21;
                              iVar3 = iVar3 + 1) {
                            uVar17 = auStack_4c < &DAT_00000008;
                            uVar19 = &stack0x00000000 == (undefined *)0x54;
                            puVar4 = (undefined4 *)sk_value(local_44,iVar3);
                            pbVar13 = (byte *)puVar4[1];
                            iVar21 = 0xd;
                            pbVar12 = pbVar13;
                            pbVar16 = (byte *)"explicitText";
                            do {
                              if (iVar21 == 0) break;
                              iVar21 = iVar21 + -1;
                              uVar17 = *pbVar12 < *pbVar16;
                              uVar19 = *pbVar12 == *pbVar16;
                              pbVar12 = pbVar12 + (uint)bVar20 * -2 + 1;
                              pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
                            } while ((bool)uVar19);
                            bVar18 = (!(bool)uVar17 && !(bool)uVar19) == (bool)uVar17;
                            if (bVar18) {
                              str = ASN1_STRING_type_new(0x1a);
                              pcVar15 = (char *)puVar4[2];
                              local_3c->ln = (char **)str;
LAB_08171c1a:
                              sVar6 = strlen(pcVar15);
                              iVar21 = ASN1_STRING_set(str,pcVar15,sVar6);
                              if (iVar21 == 0) goto LAB_08171eb8;
                            }
                            else {
                              iVar21 = 0xd;
                              pbVar12 = pbVar13;
                              pbVar16 = (byte *)0x8208c55;
                              do {
                                if (iVar21 == 0) break;
                                iVar21 = iVar21 + -1;
                                bVar18 = *pbVar12 == *pbVar16;
                                pbVar12 = pbVar12 + (uint)bVar20 * -2 + 1;
                                pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
                              } while (bVar18);
                              if (bVar18) {
                                ppAVar10 = (ASN1_STRING **)local_3c->sn;
                                if (ppAVar10 == (ASN1_STRING **)0x0) {
                                  ppAVar10 = (ASN1_STRING **)
                                             ASN1_item_new((ASN1_ITEM *)NOTICEREF_it);
                                  if (ppAVar10 == (ASN1_STRING **)0x0) goto LAB_08171eb8;
                                  local_3c->sn = (char *)ppAVar10;
                                }
                                str = *ppAVar10;
                                if (local_28 == 0) {
                                  str->type = 0x1a;
                                }
                                else {
                                  str->type = 0x16;
                                }
                                pcVar15 = (char *)puVar4[2];
                                goto LAB_08171c1a;
                              }
                              iVar21 = 0xe;
                              pbVar12 = (byte *)"noticeNumbers";
                              do {
                                if (iVar21 == 0) break;
                                iVar21 = iVar21 + -1;
                                bVar18 = *pbVar13 == *pbVar12;
                                pbVar13 = pbVar13 + (uint)bVar20 * -2 + 1;
                                pbVar12 = pbVar12 + (uint)bVar20 * -2 + 1;
                              } while (bVar18);
                              if (!bVar18) {
                                iVar21 = 0x13d;
                                iVar3 = 0x8a;
LAB_08171eed:
                                ERR_put_error(0x22,0x84,iVar3,"v3_cpols.c",iVar21);
                                ERR_add_error_data(6,"section:",*puVar4,",name:",puVar4[1],",value:"
                                                   ,puVar4[2]);
                                goto LAB_08171dbf;
                              }
                              pAVar9 = (ASN1_VALUE *)local_3c->sn;
                              if (pAVar9 == (ASN1_VALUE *)0x0) {
                                pAVar9 = ASN1_item_new((ASN1_ITEM *)NOTICEREF_it);
                                if (pAVar9 == (ASN1_VALUE *)0x0) goto LAB_08171eb8;
                                local_3c->sn = (char *)pAVar9;
                              }
                              st_00 = (_STACK *)X509V3_parse_list((char *)puVar4[2]);
                              if ((st_00 == (_STACK *)0x0) || (iVar21 = sk_num(st_00), iVar21 == 0))
                              {
                                iVar21 = 0x134;
                                iVar3 = 0x8d;
                                goto LAB_08171eed;
                              }
                              st = *(_STACK **)(pAVar9 + 4);
                              for (iVar21 = 0; iVar8 = sk_num(st_00), iVar21 < iVar8;
                                  iVar21 = iVar21 + 1) {
                                pvVar7 = sk_value(st_00,iVar21);
                                data = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,
                                                        *(char **)((int)pvVar7 + 4));
                                if (data == (ASN1_INTEGER *)0x0) {
                                  ERR_put_error(0x22,0x85,0x8c,"v3_cpols.c",0x15d);
LAB_08171da1:
                                  sk_pop_free(st,ASN1_STRING_free);
                                  sk_pop_free(st_00,X509V3_conf_free);
                                  goto LAB_08171dbf;
                                }
                                iVar8 = sk_push(st,data);
                                if (iVar8 == 0) {
                                  ERR_put_error(0x22,0x85,0x41,"v3_cpols.c",0x165);
                                  goto LAB_08171da1;
                                }
                              }
                              sk_pop_free(st_00,X509V3_conf_free);
                            }
                          }
                          piVar1 = (int *)local_3c->sn;
                          if ((piVar1 == (int *)0x0) || ((piVar1[1] != 0 && (*piVar1 != 0)))) {
                            X509V3_section_free(param_2,(stack_st_CONF_VALUE *)local_44);
                            pAVar2 = local_34[1];
                            if (pAVar2 == (ASN1_OBJECT *)0x0) {
                              pAVar2 = (ASN1_OBJECT *)sk_new_null();
                              local_34[1] = pAVar2;
                            }
                            iVar3 = sk_push((_STACK *)pAVar2,local_24);
                            if (iVar3 != 0) goto LAB_081719fe;
                            goto LAB_08171ae2;
                          }
                          ERR_put_error(0x22,0x84,0x8e,"v3_cpols.c",0x145);
                        }
LAB_08171dbf:
                        ASN1_item_free((ASN1_VALUE *)local_24,(ASN1_ITEM *)POLICYQUALINFO_it);
                        X509V3_section_free(param_2,(stack_st_CONF_VALUE *)local_44);
                        goto LAB_08171b00;
                      }
                      iVar21 = 0xec;
                      iVar3 = 0x87;
                    }
                    else {
                      iVar21 = 0xe6;
                      iVar3 = 0x89;
                    }
                  }
                  else {
                    iVar21 = 0xf9;
                    iVar3 = 0x8a;
                  }
LAB_08171fe7:
                  ERR_put_error(0x22,0x83,iVar3,"v3_cpols.c",iVar21);
                  ERR_add_error_data(6,"section:",*puVar4,",name:",puVar4[1],",value:",puVar4[2]);
                  goto LAB_08171b00;
                }
                if (local_34[1] == (ASN1_OBJECT *)0x0) {
                  pAVar2 = (ASN1_OBJECT *)sk_new_null();
                  local_34[1] = pAVar2;
                }
                ppAVar5 = (ASN1_OBJECT **)ASN1_item_new((ASN1_ITEM *)POLICYQUALINFO_it);
                if ((ppAVar5 == (ASN1_OBJECT **)0x0) ||
                   (iVar3 = sk_push((_STACK *)local_34[1],ppAVar5), iVar3 == 0)) goto LAB_08171ae2;
                pAVar2 = OBJ_nid2obj(0xa4);
                *ppAVar5 = pAVar2;
                pAVar2 = (ASN1_OBJECT *)ASN1_STRING_type_new(0x16);
                ppAVar5[1] = pAVar2;
                pcVar15 = (char *)puVar4[2];
                sVar6 = strlen(pcVar15);
                iVar3 = ASN1_STRING_set((ASN1_STRING *)pAVar2,pcVar15,sVar6);
                if (iVar3 == 0) goto LAB_08171ae2;
              }
LAB_081719fe:
              local_40 = local_40 + 1;
            }
            if (*local_34 != (ASN1_OBJECT *)0x0) {
              X509V3_section_free(param_2,(stack_st_CONF_VALUE *)local_38);
              goto LAB_0817190f;
            }
            ERR_put_error(0x22,0x83,0x8b,"v3_cpols.c",0x100);
          }
LAB_08171b00:
          ASN1_item_free((ASN1_VALUE *)local_34,(ASN1_ITEM *)POLICYINFO_it);
          X509V3_section_free(param_2,(stack_st_CONF_VALUE *)local_38);
          goto LAB_08171b23;
        }
        pAVar2 = OBJ_txt2obj(pcVar15,0);
        if (pAVar2 != (ASN1_OBJECT *)0x0) {
          local_34 = (ASN1_OBJECT **)ASN1_item_new((ASN1_ITEM *)POLICYINFO_it);
          *local_34 = pAVar2;
LAB_0817190f:
          iVar3 = sk_push(local_20,local_34);
          if (iVar3 != 0) goto LAB_0817192a;
          ASN1_item_free((ASN1_VALUE *)local_34,(ASN1_ITEM *)POLICYINFO_it);
          ERR_put_error(0x22,0x82,0x41,"v3_cpols.c",0xba);
          goto LAB_08171b23;
        }
        iVar21 = 0xb1;
        iVar3 = 0x6e;
      }
      else {
LAB_08171f34:
        iVar21 = 0x9b;
        iVar3 = 0x86;
      }
LAB_08171f46:
      ERR_put_error(0x22,0x82,iVar3,"v3_cpols.c",iVar21);
      ERR_add_error_data(6,"section:",*puVar4,",name:",puVar4[1],",value:",puVar4[2]);
      goto LAB_08171b23;
    }
    ERR_put_error(0x22,0x82,0x22,"v3_cpols.c",0x94);
LAB_08171b23:
    sk_pop_free(local_2c,X509V3_conf_free);
    sk_pop_free(local_20,POLICYINFO_free);
  }
  return (_STACK *)0x0;
}

