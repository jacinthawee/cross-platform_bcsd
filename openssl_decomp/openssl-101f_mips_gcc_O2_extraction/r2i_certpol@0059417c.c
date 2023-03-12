
int r2i_certpol(undefined4 param_1,X509V3_CTX *param_2,char *param_3)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  stack_st_CONF_VALUE *psVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  stack_st_CONF_VALUE *section;
  undefined4 uVar8;
  undefined4 *puVar9;
  stack_st_CONF_VALUE *section_00;
  int **ppiVar10;
  int *piVar11;
  stack_st_CONF_VALUE *psVar12;
  ASN1_INTEGER *pAVar13;
  int iVar14;
  undefined4 uVar15;
  char *pcVar16;
  undefined4 uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int local_64;
  
  iVar3 = (*(code *)PTR_sk_new_null_006a80a4)();
  if (iVar3 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x82,0x41,"v3_cpols.c",0x8f);
  }
  else {
    psVar4 = X509V3_parse_list(param_3);
    if (psVar4 != (stack_st_CONF_VALUE *)0x0) {
      bVar1 = false;
      local_64 = 0;
LAB_00594298:
      iVar6 = (*(code *)PTR_sk_num_006a7f2c)(psVar4);
      if (iVar6 <= local_64) {
        (*(code *)PTR_sk_pop_free_006a8158)(psVar4,PTR_X509V3_conf_free_006a8c38);
        return iVar3;
      }
      puVar7 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(psVar4,local_64);
      if ((puVar7[2] == 0) && (pcVar16 = (char *)puVar7[1], pcVar16 != (char *)0x0)) {
        iVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar16,"ia5org");
        if (iVar6 == 0) {
          bVar1 = true;
LAB_0059428c:
          local_64 = local_64 + 1;
          goto LAB_00594298;
        }
        if (*pcVar16 != '@') {
          iVar6 = (*(code *)PTR_OBJ_txt2obj_006a8100)(pcVar16,0);
          if (iVar6 == 0) {
            uVar15 = 0x6e;
            uVar8 = 0xb1;
            goto LAB_00594a80;
          }
          piVar5 = (int *)(*(code *)PTR_ASN1_item_new_006a9778)(POLICYINFO_it);
          puVar2 = PTR_sk_push_006a80a8;
          *piVar5 = iVar6;
          iVar6 = (*(code *)puVar2)(iVar3,piVar5);
          if (iVar6 != 0) goto LAB_0059428c;
LAB_00594418:
          (*(code *)PTR_ASN1_item_free_006a977c)(piVar5,POLICYINFO_it);
          uVar15 = 0x41;
          uVar8 = 0xba;
          goto LAB_00594444;
        }
        section = X509V3_get_section(param_2,pcVar16 + 1);
        if (section != (stack_st_CONF_VALUE *)0x0) {
          piVar5 = (int *)(*(code *)PTR_ASN1_item_new_006a9778)(POLICYINFO_it);
          if (piVar5 == (int *)0x0) {
LAB_00594514:
            uVar15 = 0x41;
            uVar8 = 0x107;
          }
          else {
            iVar20 = 0;
            iVar6 = (*(code *)PTR_sk_num_006a7f2c)(section);
            if (0 < iVar6) {
              do {
                puVar7 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(section,iVar20);
                pcVar16 = (char *)puVar7[1];
                iVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar16,"policyIdentifier");
                if (iVar6 == 0) {
                  iVar6 = (*(code *)PTR_OBJ_txt2obj_006a8100)(puVar7[2],0);
                  if (iVar6 == 0) {
                    uVar15 = 0x6e;
                    uVar8 = 0xd3;
                    goto LAB_00594b48;
                  }
                  *piVar5 = iVar6;
                }
                else {
                  iVar6 = name_cmp(pcVar16,"CPS");
                  if (iVar6 != 0) {
                    iVar6 = name_cmp((char *)puVar7[1],"userNotice");
                    if (iVar6 == 0) {
                      if (*(char *)puVar7[2] == '@') {
                        section_00 = X509V3_get_section(param_2,(char *)puVar7[2] + 1);
                        if (section_00 != (stack_st_CONF_VALUE *)0x0) {
                          puVar7 = (undefined4 *)
                                   (*(code *)PTR_ASN1_item_new_006a9778)(POLICYQUALINFO_it);
                          if (puVar7 == (undefined4 *)0x0) {
LAB_005947f4:
                            uVar15 = 0x41;
                            uVar8 = 0x14c;
                          }
                          else {
                            uVar8 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0xa5);
                            puVar2 = PTR_ASN1_item_new_006a9778;
                            *puVar7 = uVar8;
                            ppiVar10 = (int **)(*(code *)puVar2)(USERNOTICE_it);
                            puVar2 = PTR_sk_num_006a7f2c;
                            if (ppiVar10 == (int **)0x0) goto LAB_005947f4;
                            puVar7[1] = ppiVar10;
                            iVar19 = 0;
                            iVar6 = (*(code *)puVar2)(section_00);
                            if (0 < iVar6) {
                              do {
                                puVar9 = (undefined4 *)
                                         (*(code *)PTR_sk_value_006a7f24)(section_00,iVar19);
                                uVar8 = puVar9[1];
                                iVar6 = (*(code *)PTR_strcmp_006aac20)(uVar8,"explicitText");
                                if (iVar6 == 0) {
                                  piVar11 = (int *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)
                                                             (0x1a);
                                  uVar15 = puVar9[2];
                                  ppiVar10[1] = piVar11;
                                  uVar8 = (*(code *)PTR_strlen_006aab30)(uVar15);
                                  iVar6 = (*(code *)PTR_ASN1_STRING_set_006a8e0c)
                                                    (piVar11,uVar15,uVar8);
joined_r0x005947ec:
                                  if (iVar6 == 0) goto LAB_005947f4;
                                }
                                else {
                                  iVar6 = (*(code *)PTR_strcmp_006aac20)(uVar8,"organization");
                                  if (iVar6 == 0) {
                                    piVar11 = *ppiVar10;
                                    if (piVar11 == (int *)0x0) {
                                      piVar11 = (int *)(*(code *)PTR_ASN1_item_new_006a9778)
                                                                 (NOTICEREF_it);
                                      if (piVar11 == (int *)0x0) goto LAB_005947f4;
                                      *ppiVar10 = piVar11;
                                    }
                                    iVar6 = *piVar11;
                                    if (bVar1) {
                                      *(undefined4 *)(iVar6 + 4) = 0x16;
                                    }
                                    else {
                                      *(undefined4 *)(iVar6 + 4) = 0x1a;
                                    }
                                    uVar15 = puVar9[2];
                                    uVar8 = (*(code *)PTR_strlen_006aab30)(uVar15);
                                    iVar6 = (*(code *)PTR_ASN1_STRING_set_006a8e0c)
                                                      (iVar6,uVar15,uVar8);
                                    goto joined_r0x005947ec;
                                  }
                                  iVar6 = (*(code *)PTR_strcmp_006aac20)(uVar8,"noticeNumbers");
                                  if (iVar6 != 0) {
                                    uVar15 = 0x8a;
                                    uVar8 = 0x13d;
LAB_005949e8:
                                    (*(code *)PTR_ERR_put_error_006a9030)
                                              (0x22,0x84,uVar15,"v3_cpols.c",uVar8);
                                    (*(code *)PTR_ERR_add_error_data_006a9264)
                                              (6,"section:",*puVar9,",name:",puVar9[1],",value:",
                                               puVar9[2]);
                                    goto LAB_0059481c;
                                  }
                                  piVar11 = *ppiVar10;
                                  if (piVar11 == (int *)0x0) {
                                    piVar11 = (int *)(*(code *)PTR_ASN1_item_new_006a9778)
                                                               (NOTICEREF_it);
                                    if (piVar11 != (int *)0x0) {
                                      pcVar16 = (char *)puVar9[2];
                                      *ppiVar10 = piVar11;
                                      psVar12 = X509V3_parse_list(pcVar16);
                                      if (psVar12 != (stack_st_CONF_VALUE *)0x0) goto LAB_00594884;
LAB_005949d4:
                                      uVar15 = 0x8d;
                                      uVar8 = 0x134;
                                      goto LAB_005949e8;
                                    }
                                    goto LAB_005947f4;
                                  }
                                  psVar12 = X509V3_parse_list((char *)puVar9[2]);
                                  if (psVar12 == (stack_st_CONF_VALUE *)0x0) goto LAB_005949d4;
LAB_00594884:
                                  iVar6 = (*(code *)PTR_sk_num_006a7f2c)(psVar12);
                                  if (iVar6 == 0) goto LAB_005949d4;
                                  iVar18 = piVar11[1];
                                  iVar6 = 0;
LAB_005948e4:
                                  iVar14 = (*(code *)PTR_sk_num_006a7f2c)(psVar12);
                                  if (iVar6 < iVar14) {
                                    iVar14 = (*(code *)PTR_sk_value_006a7f24)(psVar12,iVar6);
                                    pAVar13 = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,
                                                               *(char **)(iVar14 + 4));
                                    if (pAVar13 != (ASN1_INTEGER *)0x0) goto code_r0x005948d4;
                                    uVar15 = 0x8c;
                                    uVar8 = 0x15d;
                                    goto LAB_00594948;
                                  }
                                  (*(code *)PTR_sk_pop_free_006a8158)
                                            (psVar12,PTR_X509V3_conf_free_006a8c38);
                                }
                                iVar19 = iVar19 + 1;
                                iVar6 = (*(code *)PTR_sk_num_006a7f2c)(section_00);
                              } while (iVar19 < iVar6);
                            }
                            piVar11 = *ppiVar10;
                            if ((piVar11 == (int *)0x0) || ((piVar11[1] != 0 && (*piVar11 != 0)))) {
                              X509V3_section_free(param_2,section_00);
                              iVar6 = piVar5[1];
                              if (iVar6 == 0) {
                                iVar6 = (*(code *)PTR_sk_new_null_006a80a4)();
                                piVar5[1] = iVar6;
                              }
                              iVar6 = (*(code *)PTR_sk_push_006a80a8)(iVar6,puVar7);
                              if (iVar6 != 0) goto LAB_005943c8;
                              goto LAB_00594514;
                            }
                            uVar15 = 0x8e;
                            uVar8 = 0x145;
                          }
                          (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x84,uVar15,"v3_cpols.c",uVar8)
                          ;
LAB_0059481c:
                          (*(code *)PTR_ASN1_item_free_006a977c)(puVar7,POLICYQUALINFO_it);
                          X509V3_section_free(param_2,section_00);
                          goto LAB_0059453c;
                        }
                        uVar15 = 0x87;
                        uVar8 = 0xec;
                      }
                      else {
                        uVar15 = 0x89;
                        uVar8 = 0xe6;
                      }
                    }
                    else {
                      uVar15 = 0x8a;
                      uVar8 = 0xf9;
                    }
LAB_00594b48:
                    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x83,uVar15,"v3_cpols.c",uVar8);
                    (*(code *)PTR_ERR_add_error_data_006a9264)
                              (6,"section:",*puVar7,",name:",puVar7[1],",value:",puVar7[2]);
                    goto LAB_0059453c;
                  }
                  if (piVar5[1] == 0) {
                    iVar6 = (*(code *)PTR_sk_new_null_006a80a4)();
                    piVar5[1] = iVar6;
                  }
                  puVar9 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(POLICYQUALINFO_it);
                  if ((puVar9 == (undefined4 *)0x0) ||
                     (iVar6 = (*(code *)PTR_sk_push_006a80a8)(piVar5[1],puVar9), iVar6 == 0))
                  goto LAB_00594514;
                  uVar8 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0xa4);
                  puVar2 = PTR_ASN1_STRING_type_new_006a97a4;
                  *puVar9 = uVar8;
                  uVar8 = (*(code *)puVar2)(0x16);
                  puVar9[1] = uVar8;
                  uVar17 = puVar7[2];
                  uVar15 = (*(code *)PTR_strlen_006aab30)(uVar17);
                  iVar6 = (*(code *)PTR_ASN1_STRING_set_006a8e0c)(uVar8,uVar17,uVar15);
                  if (iVar6 == 0) goto LAB_00594514;
                }
LAB_005943c8:
                iVar20 = iVar20 + 1;
                iVar6 = (*(code *)PTR_sk_num_006a7f2c)(section);
              } while (iVar20 < iVar6);
            }
            if (*piVar5 != 0) {
              X509V3_section_free(param_2,section);
              iVar6 = (*(code *)PTR_sk_push_006a80a8)(iVar3,piVar5);
              if (iVar6 == 0) goto LAB_00594418;
              goto LAB_0059428c;
            }
            uVar15 = 0x8b;
            uVar8 = 0x100;
          }
          (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x83,uVar15,"v3_cpols.c",uVar8);
LAB_0059453c:
          (*(code *)PTR_ASN1_item_free_006a977c)(piVar5,POLICYINFO_it);
          X509V3_section_free(param_2,section);
          goto LAB_00594568;
        }
        uVar15 = 0x87;
        uVar8 = 0xa7;
      }
      else {
        uVar15 = 0x86;
        uVar8 = 0x9b;
      }
LAB_00594a80:
      (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x82,uVar15,"v3_cpols.c",uVar8);
      (*(code *)PTR_ERR_add_error_data_006a9264)
                (6,"section:",*puVar7,",name:",puVar7[1],",value:",puVar7[2]);
      goto LAB_00594568;
    }
    uVar15 = 0x22;
    uVar8 = 0x94;
LAB_00594444:
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x82,uVar15,"v3_cpols.c",uVar8);
LAB_00594568:
    (*(code *)PTR_sk_pop_free_006a8158)(psVar4,PTR_X509V3_conf_free_006a8c38);
    (*(code *)PTR_sk_pop_free_006a8158)(iVar3,POLICYINFO_free);
  }
  return 0;
code_r0x005948d4:
  iVar14 = (*(code *)PTR_sk_push_006a80a8)(iVar18,pAVar13);
  iVar6 = iVar6 + 1;
  if (iVar14 == 0) {
    uVar15 = 0x41;
    uVar8 = 0x165;
LAB_00594948:
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x85,uVar15,"v3_cpols.c",uVar8);
    (*(code *)PTR_sk_pop_free_006a8158)(iVar18,PTR_ASN1_STRING_free_006a98bc);
    (*(code *)PTR_sk_pop_free_006a8158)(psVar12,PTR_X509V3_conf_free_006a8c38);
    goto LAB_0059481c;
  }
  goto LAB_005948e4;
}

