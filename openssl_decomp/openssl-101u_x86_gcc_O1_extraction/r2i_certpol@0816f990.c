
_STACK * r2i_certpol(undefined4 param_1,X509V3_CTX *param_2,char *param_3)

{
  char *pcVar1;
  _STACK *st;
  int *piVar2;
  ASN1_OBJECT *pAVar3;
  int iVar4;
  undefined4 *puVar5;
  ASN1_OBJECT **ppAVar6;
  size_t sVar7;
  _STACK *st_00;
  void *pvVar8;
  ASN1_INTEGER *data;
  int iVar9;
  ASN1_STRING *str;
  ASN1_VALUE *pAVar10;
  ASN1_STRING **ppAVar11;
  char *pcVar12;
  byte *pbVar13;
  byte *pbVar14;
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
    ERR_put_error(0x22,0x82,0x41,"v3_cpols.c",0x93);
  }
  else {
    local_2c = (_STACK *)X509V3_parse_list(param_3);
    if (local_2c != (_STACK *)0x0) {
      local_28 = 0;
      local_30 = 0;
LAB_0816fa3b:
      iVar4 = sk_num(local_2c);
      if (iVar4 <= local_30) {
        sk_pop_free(local_2c,X509V3_conf_free);
        return local_20;
      }
      puVar5 = (undefined4 *)sk_value(local_2c,local_30);
      if (puVar5[2] == 0) {
        pcVar1 = (char *)puVar5[1];
        bVar18 = pcVar1 == (char *)0x0;
        if (bVar18) goto LAB_0817006f;
        iVar4 = 7;
        pcVar12 = pcVar1;
        pcVar15 = "ia5org";
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar18 = *pcVar12 == *pcVar15;
          pcVar12 = pcVar12 + (uint)bVar20 * -2 + 1;
          pcVar15 = pcVar15 + (uint)bVar20 * -2 + 1;
        } while (bVar18);
        if (bVar18) {
          local_28 = 1;
LAB_0816fa36:
          local_30 = local_30 + 1;
          goto LAB_0816fa3b;
        }
        if (*pcVar1 == '@') {
          local_38 = (_STACK *)X509V3_get_section(param_2,pcVar1 + 1);
          if (local_38 == (_STACK *)0x0) {
            iVar21 = 0xac;
            iVar4 = 0x87;
            goto LAB_08170081;
          }
          local_34 = (ASN1_OBJECT **)ASN1_item_new((ASN1_ITEM *)POLICYINFO_it);
          if (local_34 == (ASN1_OBJECT **)0x0) {
LAB_0816fbfb:
            ERR_put_error(0x22,0x83,0x41,"v3_cpols.c",0x11c);
          }
          else {
            local_40 = 0;
            while (iVar4 = sk_num(local_38), local_40 < iVar4) {
              uVar17 = auStack_4c < &DAT_00000008;
              uVar19 = &stack0x00000000 == (undefined *)0x54;
              puVar5 = (undefined4 *)sk_value(local_38,local_40);
              iVar4 = 0x11;
              pbVar14 = (byte *)puVar5[1];
              pbVar13 = (byte *)"policyIdentifier";
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                uVar17 = *pbVar14 < *pbVar13;
                uVar19 = *pbVar14 == *pbVar13;
                pbVar14 = pbVar14 + (uint)bVar20 * -2 + 1;
                pbVar13 = pbVar13 + (uint)bVar20 * -2 + 1;
              } while ((bool)uVar19);
              if ((!(bool)uVar17 && !(bool)uVar19) == (bool)uVar17) {
                pAVar3 = OBJ_txt2obj((char *)puVar5[2],0);
                if (pAVar3 == (ASN1_OBJECT *)0x0) {
                  iVar21 = 0xe0;
                  iVar4 = 0x6e;
                  goto LAB_08170122;
                }
                *local_34 = pAVar3;
              }
              else {
                iVar4 = name_cmp((char *)(byte *)puVar5[1],"CPS");
                if (iVar4 != 0) {
                  iVar4 = name_cmp((char *)puVar5[1],"userNotice");
                  if (iVar4 == 0) {
                    if (*(char *)puVar5[2] == '@') {
                      local_44 = (_STACK *)X509V3_get_section(param_2,(char *)puVar5[2] + 1);
                      if (local_44 != (_STACK *)0x0) {
                        ppAVar6 = (ASN1_OBJECT **)ASN1_item_new((ASN1_ITEM *)POLICYQUALINFO_it);
                        local_24 = ppAVar6;
                        if (ppAVar6 == (ASN1_OBJECT **)0x0) {
LAB_0816fe9e:
                          ERR_put_error(0x22,0x84,0x41,"v3_cpols.c",0x16f);
                        }
                        else {
                          pAVar3 = OBJ_nid2obj(0xa5);
                          *ppAVar6 = pAVar3;
                          if (pAVar3 == (ASN1_OBJECT *)0x0) {
                            ERR_put_error(0x22,0x84,0x44,"v3_cpols.c",0x12e);
                          }
                          else {
                            local_3c = (ASN1_OBJECT *)ASN1_item_new((ASN1_ITEM *)USERNOTICE_it);
                            if (local_3c == (ASN1_OBJECT *)0x0) goto LAB_0816fe9e;
                            local_24[1] = local_3c;
                            for (iVar4 = 0; iVar21 = sk_num(local_44), iVar4 < iVar21;
                                iVar4 = iVar4 + 1) {
                              uVar17 = auStack_4c < &DAT_00000008;
                              uVar19 = &stack0x00000000 == (undefined *)0x54;
                              puVar5 = (undefined4 *)sk_value(local_44,iVar4);
                              pbVar14 = (byte *)puVar5[1];
                              iVar21 = 0xd;
                              pbVar13 = pbVar14;
                              pbVar16 = (byte *)"explicitText";
                              do {
                                if (iVar21 == 0) break;
                                iVar21 = iVar21 + -1;
                                uVar17 = *pbVar13 < *pbVar16;
                                uVar19 = *pbVar13 == *pbVar16;
                                pbVar13 = pbVar13 + (uint)bVar20 * -2 + 1;
                                pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
                              } while ((bool)uVar19);
                              bVar18 = (!(bool)uVar17 && !(bool)uVar19) == (bool)uVar17;
                              if (bVar18) {
                                str = ASN1_STRING_type_new(0x1a);
                                local_3c->ln = (char **)str;
                                if (str == (ASN1_STRING *)0x0) goto LAB_0816fe9e;
LAB_0816fd3b:
                                pcVar1 = (char *)puVar5[2];
                                sVar7 = strlen(pcVar1);
                                iVar21 = ASN1_STRING_set(str,pcVar1,sVar7);
                                if (iVar21 == 0) goto LAB_0816fe9e;
                              }
                              else {
                                iVar21 = 0xd;
                                pbVar13 = pbVar14;
                                pbVar16 = (byte *)0x8209015;
                                do {
                                  if (iVar21 == 0) break;
                                  iVar21 = iVar21 + -1;
                                  bVar18 = *pbVar13 == *pbVar16;
                                  pbVar13 = pbVar13 + (uint)bVar20 * -2 + 1;
                                  pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
                                } while (bVar18);
                                if (bVar18) {
                                  ppAVar11 = (ASN1_STRING **)local_3c->sn;
                                  if (ppAVar11 == (ASN1_STRING **)0x0) {
                                    ppAVar11 = (ASN1_STRING **)
                                               ASN1_item_new((ASN1_ITEM *)NOTICEREF_it);
                                    if (ppAVar11 == (ASN1_STRING **)0x0) goto LAB_0816fe9e;
                                    local_3c->sn = (char *)ppAVar11;
                                  }
                                  str = *ppAVar11;
                                  if (local_28 == 0) {
                                    str->type = 0x1a;
                                  }
                                  else {
                                    str->type = 0x16;
                                  }
                                  goto LAB_0816fd3b;
                                }
                                iVar21 = 0xe;
                                pbVar13 = (byte *)"noticeNumbers";
                                do {
                                  if (iVar21 == 0) break;
                                  iVar21 = iVar21 + -1;
                                  bVar18 = *pbVar14 == *pbVar13;
                                  pbVar14 = pbVar14 + (uint)bVar20 * -2 + 1;
                                  pbVar13 = pbVar13 + (uint)bVar20 * -2 + 1;
                                } while (bVar18);
                                if (!bVar18) {
                                  iVar21 = 0x15f;
                                  iVar4 = 0x8a;
LAB_08170028:
                                  ERR_put_error(0x22,0x84,iVar4,"v3_cpols.c",iVar21);
                                  ERR_add_error_data(6,"section:",*puVar5,",name:",puVar5[1],
                                                     ",value:",puVar5[2]);
                                  goto LAB_0816fec0;
                                }
                                pAVar10 = (ASN1_VALUE *)local_3c->sn;
                                if (pAVar10 == (ASN1_VALUE *)0x0) {
                                  pAVar10 = ASN1_item_new((ASN1_ITEM *)NOTICEREF_it);
                                  if (pAVar10 == (ASN1_VALUE *)0x0) goto LAB_0816fe9e;
                                  local_3c->sn = (char *)pAVar10;
                                }
                                st_00 = (_STACK *)X509V3_parse_list((char *)puVar5[2]);
                                if ((st_00 == (_STACK *)0x0) ||
                                   (iVar21 = sk_num(st_00), iVar21 == 0)) {
                                  iVar21 = 0x156;
                                  iVar4 = 0x8d;
                                  goto LAB_08170028;
                                }
                                st = *(_STACK **)(pAVar10 + 4);
                                for (iVar21 = 0; iVar9 = sk_num(st_00), iVar21 < iVar9;
                                    iVar21 = iVar21 + 1) {
                                  pvVar8 = sk_value(st_00,iVar21);
                                  data = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,
                                                          *(char **)((int)pvVar8 + 4));
                                  if (data == (ASN1_INTEGER *)0x0) {
                                    ERR_put_error(0x22,0x85,0x8c,"v3_cpols.c",0x180);
LAB_0816ff21:
                                    sk_pop_free(st,ASN1_STRING_free);
                                    sk_pop_free(st_00,X509V3_conf_free);
                                    goto LAB_0816fec0;
                                  }
                                  iVar9 = sk_push(st,data);
                                  if (iVar9 == 0) {
                                    ERR_put_error(0x22,0x85,0x41,"v3_cpols.c",0x189);
                                    goto LAB_0816ff21;
                                  }
                                }
                                sk_pop_free(st_00,X509V3_conf_free);
                              }
                            }
                            piVar2 = (int *)local_3c->sn;
                            if ((piVar2 == (int *)0x0) || ((piVar2[1] != 0 && (*piVar2 != 0)))) {
                              X509V3_section_free(param_2,(stack_st_CONF_VALUE *)local_44);
                              pAVar3 = local_34[1];
                              if (pAVar3 == (ASN1_OBJECT *)0x0) {
                                pAVar3 = (ASN1_OBJECT *)sk_new_null();
                                local_34[1] = pAVar3;
                              }
                              iVar4 = sk_push((_STACK *)pAVar3,local_24);
                              if (iVar4 != 0) goto LAB_0816fb06;
                              goto LAB_0816fbfb;
                            }
                            ERR_put_error(0x22,0x84,0x8e,"v3_cpols.c",0x168);
                          }
                        }
LAB_0816fec0:
                        ASN1_item_free((ASN1_VALUE *)local_24,(ASN1_ITEM *)POLICYQUALINFO_it);
                        X509V3_section_free(param_2,(stack_st_CONF_VALUE *)local_44);
                        goto LAB_0816fc19;
                      }
                      iVar21 = 0x100;
                      iVar4 = 0x87;
                    }
                    else {
                      iVar21 = 0xfa;
                      iVar4 = 0x89;
                    }
                  }
                  else {
                    iVar21 = 0x10e;
                    iVar4 = 0x8a;
                  }
LAB_08170122:
                  ERR_put_error(0x22,0x83,iVar4,"v3_cpols.c",iVar21);
                  ERR_add_error_data(6,"section:",*puVar5,",name:",puVar5[1],",value:",puVar5[2]);
                  goto LAB_0816fc19;
                }
                if (local_34[1] == (ASN1_OBJECT *)0x0) {
                  pAVar3 = (ASN1_OBJECT *)sk_new_null();
                  local_34[1] = pAVar3;
                }
                ppAVar6 = (ASN1_OBJECT **)ASN1_item_new((ASN1_ITEM *)POLICYQUALINFO_it);
                if ((ppAVar6 == (ASN1_OBJECT **)0x0) ||
                   (iVar4 = sk_push((_STACK *)local_34[1],ppAVar6), iVar4 == 0)) goto LAB_0816fbfb;
                pAVar3 = OBJ_nid2obj(0xa4);
                *ppAVar6 = pAVar3;
                if (pAVar3 == (ASN1_OBJECT *)0x0) {
                  ERR_put_error(0x22,0x83,0x44,"v3_cpols.c",0xee);
                  goto LAB_0816fc19;
                }
                pAVar3 = (ASN1_OBJECT *)ASN1_STRING_type_new(0x16);
                ppAVar6[1] = pAVar3;
                if (pAVar3 == (ASN1_OBJECT *)0x0) goto LAB_0816fbfb;
                pcVar1 = (char *)puVar5[2];
                sVar7 = strlen(pcVar1);
                iVar4 = ASN1_STRING_set((ASN1_STRING *)pAVar3,pcVar1,sVar7);
                if (iVar4 == 0) goto LAB_0816fbfb;
              }
LAB_0816fb06:
              local_40 = local_40 + 1;
            }
            if (*local_34 != (ASN1_OBJECT *)0x0) {
              X509V3_section_free(param_2,(stack_st_CONF_VALUE *)local_38);
              goto LAB_0816fa1b;
            }
            ERR_put_error(0x22,0x83,0x8b,"v3_cpols.c",0x115);
          }
LAB_0816fc19:
          ASN1_item_free((ASN1_VALUE *)local_34,(ASN1_ITEM *)POLICYINFO_it);
          X509V3_section_free(param_2,(stack_st_CONF_VALUE *)local_38);
          goto LAB_0816fc3c;
        }
        pAVar3 = OBJ_txt2obj(pcVar1,0);
        if (pAVar3 != (ASN1_OBJECT *)0x0) {
          local_34 = (ASN1_OBJECT **)ASN1_item_new((ASN1_ITEM *)POLICYINFO_it);
          if (local_34 == (ASN1_OBJECT **)0x0) {
            iVar4 = 0xbe;
          }
          else {
            *local_34 = pAVar3;
LAB_0816fa1b:
            iVar4 = sk_push(local_20,local_34);
            if (iVar4 != 0) goto LAB_0816fa36;
            ASN1_item_free((ASN1_VALUE *)local_34,(ASN1_ITEM *)POLICYINFO_it);
            iVar4 = 0xc5;
          }
          ERR_put_error(0x22,0x82,0x41,"v3_cpols.c",iVar4);
          goto LAB_0816fc3c;
        }
        iVar21 = 0xb8;
        iVar4 = 0x6e;
      }
      else {
LAB_0817006f:
        iVar21 = 0xa0;
        iVar4 = 0x86;
      }
LAB_08170081:
      ERR_put_error(0x22,0x82,iVar4,"v3_cpols.c",iVar21);
      ERR_add_error_data(6,"section:",*puVar5,",name:",puVar5[1],",value:",puVar5[2]);
      goto LAB_0816fc3c;
    }
    ERR_put_error(0x22,0x82,0x22,"v3_cpols.c",0x98);
LAB_0816fc3c:
    sk_pop_free(local_2c,X509V3_conf_free);
    sk_pop_free(local_20,POLICYINFO_free);
  }
  return (_STACK *)0x0;
}

