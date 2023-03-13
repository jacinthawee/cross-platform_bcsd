
int r2i_certpol(undefined4 param_1,X509V3_CTX *param_2,char *param_3)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  stack_st_CONF_VALUE *psVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  stack_st_CONF_VALUE *section;
  undefined4 uVar8;
  int *piVar9;
  stack_st_CONF_VALUE *section_00;
  int **ppiVar10;
  int **ppiVar11;
  stack_st_CONF_VALUE *psVar12;
  ASN1_INTEGER *pAVar13;
  int iVar14;
  undefined4 uVar15;
  char *pcVar16;
  int *piVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  
  iVar3 = (*(code *)PTR_sk_new_null_006a6fa4)();
  if (iVar3 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x82,0x41,"v3_cpols.c",0x93);
  }
  else {
    psVar4 = X509V3_parse_list(param_3);
    if (psVar4 != (stack_st_CONF_VALUE *)0x0) {
      iVar21 = 0;
      bVar1 = false;
      iVar5 = (*(code *)PTR_sk_num_006a6e2c)(psVar4);
      if (iVar5 < 1) {
LAB_00591574:
        (*(code *)PTR_sk_pop_free_006a7058)(psVar4,PTR_X509V3_conf_free_006a7b4c);
        return iVar3;
      }
LAB_005914ac:
      puVar6 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(psVar4,iVar21);
      if ((puVar6[2] == 0) && (pcVar16 = (char *)puVar6[1], pcVar16 != (char *)0x0)) {
        iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"ia5org");
        if (iVar5 == 0) {
          bVar1 = true;
LAB_0059155c:
          iVar21 = iVar21 + 1;
          iVar5 = (*(code *)PTR_sk_num_006a6e2c)(psVar4);
          if (iVar5 <= iVar21) goto LAB_00591574;
          goto LAB_005914ac;
        }
        if (*pcVar16 == '@') {
          section = X509V3_get_section(param_2,pcVar16 + 1);
          if (section == (stack_st_CONF_VALUE *)0x0) {
            uVar15 = 0x87;
            uVar8 = 0xac;
            goto LAB_00591d18;
          }
          piVar7 = (int *)(*(code *)PTR_ASN1_item_new_006a8654)(POLICYINFO_it);
          if (piVar7 == (int *)0x0) {
LAB_005917e8:
            uVar15 = 0x41;
            uVar8 = 0x11c;
          }
          else {
            iVar20 = 0;
            iVar5 = (*(code *)PTR_sk_num_006a6e2c)(section);
            if (0 < iVar5) {
              do {
                puVar6 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(section,iVar20);
                pcVar16 = (char *)puVar6[1];
                iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"policyIdentifier");
                if (iVar5 == 0) {
                  iVar5 = (*(code *)PTR_OBJ_txt2obj_006a7000)(puVar6[2],0);
                  if (iVar5 == 0) {
                    uVar15 = 0x6e;
                    uVar8 = 0xe0;
                    goto LAB_00591db0;
                  }
                  *piVar7 = iVar5;
                }
                else {
                  iVar5 = name_cmp(pcVar16,"CPS");
                  if (iVar5 != 0) {
                    iVar5 = name_cmp((char *)puVar6[1],"userNotice");
                    if (iVar5 == 0) {
                      if (*(char *)puVar6[2] == '@') {
                        section_00 = X509V3_get_section(param_2,(char *)puVar6[2] + 1);
                        if (section_00 != (stack_st_CONF_VALUE *)0x0) {
                          piVar9 = (int *)(*(code *)PTR_ASN1_item_new_006a8654)(POLICYQUALINFO_it);
                          if (piVar9 == (int *)0x0) {
LAB_00591aa0:
                            uVar15 = 0x41;
                            uVar8 = 0x16f;
                          }
                          else {
                            iVar5 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0xa5);
                            *piVar9 = iVar5;
                            if (iVar5 == 0) {
                              uVar15 = 0x44;
                              uVar8 = 0x12e;
                            }
                            else {
                              ppiVar10 = (int **)(*(code *)PTR_ASN1_item_new_006a8654)
                                                           (USERNOTICE_it);
                              puVar2 = PTR_sk_num_006a6e2c;
                              if (ppiVar10 == (int **)0x0) goto LAB_00591aa0;
                              iVar19 = 0;
                              piVar9[1] = (int)ppiVar10;
                              iVar5 = (*(code *)puVar2)(section_00);
                              if (0 < iVar5) {
                                do {
                                  puVar6 = (undefined4 *)
                                           (*(code *)PTR_sk_value_006a6e24)(section_00,iVar19);
                                  uVar8 = puVar6[1];
                                  iVar5 = (*(code *)PTR_strcmp_006a9b18)(uVar8,"explicitText");
                                  if (iVar5 == 0) {
                                    piVar17 = (int *)(*(code *)PTR_ASN1_STRING_type_new_006a8680)
                                                               (0x1a);
                                    ppiVar10[1] = piVar17;
                                    if (piVar17 == (int *)0x0) goto LAB_00591aa0;
LAB_005919dc:
                                    uVar15 = puVar6[2];
                                    uVar8 = (*(code *)PTR_strlen_006a9a24)(uVar15);
                                    iVar5 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)
                                                      (piVar17,uVar15,uVar8);
                                    if (iVar5 == 0) goto LAB_00591aa0;
                                  }
                                  else {
                                    iVar5 = (*(code *)PTR_strcmp_006a9b18)(uVar8,"organization");
                                    if (iVar5 == 0) {
                                      ppiVar11 = (int **)*ppiVar10;
                                      if (ppiVar11 == (int **)0x0) {
                                        ppiVar11 = (int **)(*(code *)PTR_ASN1_item_new_006a8654)
                                                                     (NOTICEREF_it);
                                        if (ppiVar11 == (int **)0x0) goto LAB_00591aa0;
                                        *ppiVar10 = (int *)ppiVar11;
                                      }
                                      piVar17 = *ppiVar11;
                                      if (bVar1) {
                                        piVar17[1] = 0x16;
                                      }
                                      else {
                                        piVar17[1] = 0x1a;
                                      }
                                      goto LAB_005919dc;
                                    }
                                    iVar5 = (*(code *)PTR_strcmp_006a9b18)(uVar8,"noticeNumbers");
                                    if (iVar5 != 0) {
                                      uVar15 = 0x8a;
                                      uVar8 = 0x15f;
LAB_00591c94:
                                      (*(code *)PTR_ERR_put_error_006a7f34)
                                                (0x22,0x84,uVar15,"v3_cpols.c",uVar8);
                                      (*(code *)PTR_ERR_add_error_data_006a813c)
                                                (6,"section:",*puVar6,",name:",puVar6[1],",value:",
                                                 puVar6[2]);
                                      goto LAB_00591ac8;
                                    }
                                    piVar17 = *ppiVar10;
                                    if (piVar17 == (int *)0x0) {
                                      piVar17 = (int *)(*(code *)PTR_ASN1_item_new_006a8654)
                                                                 (NOTICEREF_it);
                                      if (piVar17 != (int *)0x0) {
                                        pcVar16 = (char *)puVar6[2];
                                        *ppiVar10 = piVar17;
                                        psVar12 = X509V3_parse_list(pcVar16);
                                        if (psVar12 != (stack_st_CONF_VALUE *)0x0)
                                        goto LAB_00591b30;
LAB_00591c80:
                                        uVar15 = 0x8d;
                                        uVar8 = 0x156;
                                        goto LAB_00591c94;
                                      }
                                      goto LAB_00591aa0;
                                    }
                                    psVar12 = X509V3_parse_list((char *)puVar6[2]);
                                    if (psVar12 == (stack_st_CONF_VALUE *)0x0) goto LAB_00591c80;
LAB_00591b30:
                                    iVar5 = (*(code *)PTR_sk_num_006a6e2c)(psVar12);
                                    if (iVar5 == 0) goto LAB_00591c80;
                                    iVar18 = piVar17[1];
                                    iVar5 = 0;
LAB_00591b90:
                                    iVar14 = (*(code *)PTR_sk_num_006a6e2c)(psVar12);
                                    if (iVar5 < iVar14) {
                                      iVar14 = (*(code *)PTR_sk_value_006a6e24)(psVar12,iVar5);
                                      pAVar13 = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,
                                                                 *(char **)(iVar14 + 4));
                                      if (pAVar13 != (ASN1_INTEGER *)0x0) goto code_r0x00591b80;
                                      uVar15 = 0x8c;
                                      uVar8 = 0x180;
                                      goto LAB_00591bf4;
                                    }
                                    (*(code *)PTR_sk_pop_free_006a7058)
                                              (psVar12,PTR_X509V3_conf_free_006a7b4c);
                                  }
                                  iVar19 = iVar19 + 1;
                                  iVar5 = (*(code *)PTR_sk_num_006a6e2c)(section_00);
                                } while (iVar19 < iVar5);
                              }
                              piVar17 = *ppiVar10;
                              if ((piVar17 == (int *)0x0) || ((piVar17[1] != 0 && (*piVar17 != 0))))
                              {
                                X509V3_section_free(param_2,section_00);
                                iVar5 = piVar7[1];
                                if (iVar5 == 0) {
                                  iVar5 = (*(code *)PTR_sk_new_null_006a6fa4)();
                                  piVar7[1] = iVar5;
                                }
                                iVar5 = (*(code *)PTR_sk_push_006a6fa8)(iVar5,piVar9);
                                if (iVar5 != 0) goto LAB_00591694;
                                goto LAB_005917e8;
                              }
                              uVar15 = 0x8e;
                              uVar8 = 0x168;
                            }
                          }
                          (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x84,uVar15,"v3_cpols.c",uVar8)
                          ;
LAB_00591ac8:
                          (*(code *)PTR_ASN1_item_free_006a8658)(piVar9,POLICYQUALINFO_it);
                          X509V3_section_free(param_2,section_00);
                          goto LAB_00591810;
                        }
                        uVar15 = 0x87;
                        uVar8 = 0x100;
                      }
                      else {
                        uVar15 = 0x89;
                        uVar8 = 0xfa;
                      }
                    }
                    else {
                      uVar15 = 0x8a;
                      uVar8 = 0x10e;
                    }
LAB_00591db0:
                    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x83,uVar15,"v3_cpols.c",uVar8);
                    (*(code *)PTR_ERR_add_error_data_006a813c)
                              (6,"section:",*puVar6,",name:",puVar6[1],",value:",puVar6[2]);
                    goto LAB_00591810;
                  }
                  if (piVar7[1] == 0) {
                    iVar5 = (*(code *)PTR_sk_new_null_006a6fa4)();
                    piVar7[1] = iVar5;
                  }
                  piVar9 = (int *)(*(code *)PTR_ASN1_item_new_006a8654)(POLICYQUALINFO_it);
                  if ((piVar9 == (int *)0x0) ||
                     (iVar5 = (*(code *)PTR_sk_push_006a6fa8)(piVar7[1],piVar9), iVar5 == 0))
                  goto LAB_005917e8;
                  iVar5 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0xa4);
                  *piVar9 = iVar5;
                  if (iVar5 == 0) {
                    uVar15 = 0x44;
                    uVar8 = 0xee;
                    goto LAB_005917fc;
                  }
                  iVar5 = (*(code *)PTR_ASN1_STRING_type_new_006a8680)(0x16);
                  piVar9[1] = iVar5;
                  if (iVar5 == 0) goto LAB_005917e8;
                  uVar15 = puVar6[2];
                  uVar8 = (*(code *)PTR_strlen_006a9a24)(uVar15);
                  iVar5 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)(iVar5,uVar15,uVar8);
                  if (iVar5 == 0) goto LAB_005917e8;
                }
LAB_00591694:
                iVar20 = iVar20 + 1;
                iVar5 = (*(code *)PTR_sk_num_006a6e2c)(section);
              } while (iVar20 < iVar5);
            }
            if (*piVar7 != 0) {
              X509V3_section_free(param_2,section);
              iVar5 = (*(code *)PTR_sk_push_006a6fa8)(iVar3,piVar7);
              if (iVar5 == 0) goto LAB_005916e4;
              goto LAB_0059155c;
            }
            uVar15 = 0x8b;
            uVar8 = 0x115;
          }
LAB_005917fc:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x83,uVar15,"v3_cpols.c",uVar8);
LAB_00591810:
          (*(code *)PTR_ASN1_item_free_006a8658)(piVar7,POLICYINFO_it);
          X509V3_section_free(param_2,section);
          goto LAB_0059183c;
        }
        iVar5 = (*(code *)PTR_OBJ_txt2obj_006a7000)(pcVar16,0);
        if (iVar5 != 0) {
          piVar7 = (int *)(*(code *)PTR_ASN1_item_new_006a8654)(POLICYINFO_it);
          puVar2 = PTR_sk_push_006a6fa8;
          if (piVar7 == (int *)0x0) {
            uVar15 = 0x41;
            uVar8 = 0xbe;
          }
          else {
            *piVar7 = iVar5;
            iVar5 = (*(code *)puVar2)(iVar3,piVar7);
            if (iVar5 != 0) goto LAB_0059155c;
LAB_005916e4:
            (*(code *)PTR_ASN1_item_free_006a8658)(piVar7,POLICYINFO_it);
            uVar15 = 0x41;
            uVar8 = 0xc5;
          }
          goto LAB_00591710;
        }
        uVar15 = 0x6e;
        uVar8 = 0xb8;
      }
      else {
        uVar15 = 0x86;
        uVar8 = 0xa0;
      }
LAB_00591d18:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x82,uVar15,"v3_cpols.c",uVar8);
      (*(code *)PTR_ERR_add_error_data_006a813c)
                (6,"section:",*puVar6,",name:",puVar6[1],",value:",puVar6[2]);
      goto LAB_0059183c;
    }
    uVar15 = 0x22;
    uVar8 = 0x98;
LAB_00591710:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x82,uVar15,"v3_cpols.c",uVar8);
LAB_0059183c:
    (*(code *)PTR_sk_pop_free_006a7058)(psVar4,PTR_X509V3_conf_free_006a7b4c);
    (*(code *)PTR_sk_pop_free_006a7058)(iVar3,POLICYINFO_free);
  }
  return 0;
code_r0x00591b80:
  iVar14 = (*(code *)PTR_sk_push_006a6fa8)(iVar18,pAVar13);
  iVar5 = iVar5 + 1;
  if (iVar14 == 0) {
    uVar15 = 0x41;
    uVar8 = 0x189;
LAB_00591bf4:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x85,uVar15,"v3_cpols.c",uVar8);
    (*(code *)PTR_sk_pop_free_006a7058)(iVar18,PTR_ASN1_STRING_free_006a879c);
    (*(code *)PTR_sk_pop_free_006a7058)(psVar12,PTR_X509V3_conf_free_006a7b4c);
    goto LAB_00591ac8;
  }
  goto LAB_00591b90;
}

