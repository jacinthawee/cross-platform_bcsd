
int v2i_crld(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  CONF_VALUE *cnf;
  GENERAL_NAME *a;
  GENERAL_NAMES *pGVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  stack_st_CONF_VALUE *section;
  int *piVar7;
  int iVar8;
  stack_st_CONF_VALUE *psVar9;
  X509_NAME *nm;
  int iVar10;
  undefined4 uVar11;
  char *pcVar12;
  stack_st_X509_NAME_ENTRY *psVar13;
  int iVar14;
  
  iVar2 = (*(code *)PTR_sk_new_null_006a80a4)();
  if (iVar2 == 0) {
    a = (GENERAL_NAME *)0x0;
    pGVar4 = (GENERAL_NAMES *)0x0;
LAB_00596254:
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x86,0x41,"v3_crld.c",0x16d);
LAB_0059627c:
    GENERAL_NAME_free(a);
    GENERAL_NAMES_free(pGVar4);
    (*(code *)PTR_sk_pop_free_006a8158)(iVar2,DIST_POINT_free);
    return 0;
  }
  iVar14 = 0;
  iVar3 = (*(code *)PTR_sk_num_006a7f2c)(param_3);
  if (0 < iVar3) {
    do {
      cnf = (CONF_VALUE *)(*(code *)PTR_sk_value_006a7f24)(param_3,iVar14);
      if (cnf->value != (char *)0x0) {
        a = v2i_GENERAL_NAME(param_1,param_2,cnf);
        if (a != (GENERAL_NAME *)0x0) {
          pGVar4 = GENERAL_NAMES_new();
          if ((pGVar4 == (GENERAL_NAMES *)0x0) ||
             (iVar3 = (*(code *)PTR_sk_push_006a80a8)(pGVar4,a), iVar3 == 0)) goto LAB_00596254;
          puVar5 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(DIST_POINT_it);
          if (puVar5 != (undefined4 *)0x0) {
            iVar3 = (*(code *)PTR_sk_push_006a80a8)(iVar2,puVar5);
            if (iVar3 == 0) {
              a = (GENERAL_NAME *)0x0;
              (*(code *)PTR_ASN1_item_free_006a977c)(puVar5,DIST_POINT_it);
              goto LAB_00596254;
            }
            puVar6 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(DIST_POINT_NAME_it);
            *puVar5 = puVar6;
            if (puVar6 != (undefined4 *)0x0) {
              puVar6[1] = pGVar4;
              *puVar6 = 0;
              goto LAB_005960b4;
            }
          }
          a = (GENERAL_NAME *)0x0;
          goto LAB_00596254;
        }
LAB_0059636c:
        a = (GENERAL_NAME *)0x0;
        pGVar4 = (GENERAL_NAMES *)0x0;
        goto LAB_0059627c;
      }
      section = X509V3_get_section(param_2,cnf->name);
      if (section == (stack_st_CONF_VALUE *)0x0) goto LAB_0059636c;
      piVar7 = (int *)(*(code *)PTR_ASN1_item_new_006a9778)(DIST_POINT_it);
      if (piVar7 == (int *)0x0) {
        X509V3_section_free(param_2,section);
        goto LAB_0059636c;
      }
      iVar10 = 0;
      iVar3 = (*(code *)PTR_sk_num_006a7f2c)(section);
      if (0 < iVar3) {
        do {
          iVar3 = (*(code *)PTR_sk_value_006a7f24)(section,iVar10);
          uVar11 = *(undefined4 *)(iVar3 + 4);
          iVar8 = (*(code *)PTR_strcmp_006aac20)(uVar11,"fullname");
          if (iVar8 == 0) {
            pcVar12 = *(char **)(iVar3 + 8);
            if (*pcVar12 == '@') {
              psVar9 = X509V3_get_section(param_2,pcVar12 + 1);
            }
            else {
              psVar9 = X509V3_parse_list(pcVar12);
            }
            if (psVar9 == (stack_st_CONF_VALUE *)0x0) {
              (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x9c,0x96,"v3_crld.c",0x68);
            }
            else {
              pGVar4 = v2i_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,param_2,psVar9);
              if (*pcVar12 == '@') {
                X509V3_section_free(param_2,psVar9);
              }
              else {
                (*(code *)PTR_sk_pop_free_006a8158)(psVar9,PTR_X509V3_conf_free_006a8c38);
              }
              if (pGVar4 != (GENERAL_NAMES *)0x0) {
                psVar13 = (stack_st_X509_NAME_ENTRY *)0x0;
                if (*piVar7 == 0) {
LAB_00596544:
                  puVar5 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(DIST_POINT_NAME_it);
                  *piVar7 = (int)puVar5;
                  if (puVar5 != (undefined4 *)0x0) {
                    if (pGVar4 == (GENERAL_NAMES *)0x0) {
                      puVar5[1] = psVar13;
                      *puVar5 = 1;
                    }
                    else {
                      puVar5[1] = pGVar4;
                      *puVar5 = 0;
                    }
                    goto LAB_005961f0;
                  }
                }
                else {
LAB_005963f0:
                  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x9e,0xa0,"v3_crld.c",0xa5);
                }
                if (pGVar4 != (GENERAL_NAMES *)0x0) {
                  (*(code *)PTR_sk_pop_free_006a8158)(pGVar4,PTR_GENERAL_NAME_free_006a84a4);
                }
LAB_00596430:
                if (psVar13 != (stack_st_X509_NAME_ENTRY *)0x0) {
                  (*(code *)PTR_sk_pop_free_006a8158)(psVar13,PTR_X509_NAME_ENTRY_free_006a8250);
                }
              }
            }
LAB_0059644c:
            (*(code *)PTR_ASN1_item_free_006a977c)(piVar7,DIST_POINT_it);
            X509V3_section_free(param_2,section);
            goto LAB_0059636c;
          }
          iVar8 = (*(code *)PTR_strcmp_006aac20)(uVar11,"relativename");
          if (iVar8 == 0) {
            nm = (X509_NAME *)(*(code *)PTR_X509_NAME_new_006a8238)();
            if (nm != (X509_NAME *)0x0) {
              psVar9 = X509V3_get_section(param_2,*(char **)(iVar3 + 8));
              if (psVar9 != (stack_st_CONF_VALUE *)0x0) {
                iVar3 = X509V3_NAME_from_section(nm,psVar9,0x1001);
                X509V3_section_free(param_2,psVar9);
                puVar1 = PTR_X509_NAME_free_006a80f8;
                psVar13 = nm->entries;
                nm->entries = (stack_st_X509_NAME_ENTRY *)0x0;
                (*(code *)puVar1)(nm);
                if ((iVar3 != 0) && (iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psVar13), 0 < iVar3)) {
                  iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psVar13);
                  iVar3 = (*(code *)PTR_sk_value_006a7f24)(psVar13,iVar3 + -1);
                  if (*(int *)(iVar3 + 8) == 0) {
                    pGVar4 = (GENERAL_NAMES *)0x0;
                    if (*piVar7 != 0) goto LAB_005963f0;
                    goto LAB_00596544;
                  }
                  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x9e,0xa1,"v3_crld.c",0x9b);
                }
                goto LAB_00596430;
              }
              (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x9e,0x96,"v3_crld.c",0x8a);
            }
            goto LAB_0059644c;
          }
          iVar8 = (*(code *)PTR_strcmp_006aac20)(uVar11,"reasons");
          if (iVar8 == 0) {
            iVar3 = set_reasons(piVar7 + 1,*(undefined4 *)(iVar3 + 8));
            if (iVar3 == 0) goto LAB_0059644c;
          }
          else {
            iVar8 = (*(code *)PTR_strcmp_006aac20)(uVar11,"CRLissuer");
            if (iVar8 == 0) {
              pcVar12 = *(char **)(iVar3 + 8);
              if (*pcVar12 == '@') {
                psVar9 = X509V3_get_section(param_2,pcVar12 + 1);
              }
              else {
                psVar9 = X509V3_parse_list(pcVar12);
              }
              if (psVar9 == (stack_st_CONF_VALUE *)0x0) {
                (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x9c,0x96,"v3_crld.c",0x68);
                piVar7[2] = 0;
              }
              else {
                pGVar4 = v2i_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,param_2,psVar9);
                if (*pcVar12 == '@') {
                  X509V3_section_free(param_2,psVar9);
                }
                else {
                  (*(code *)PTR_sk_pop_free_006a8158)(psVar9,PTR_X509V3_conf_free_006a8c38);
                }
                piVar7[2] = (int)pGVar4;
                if (pGVar4 != (GENERAL_NAMES *)0x0) goto LAB_005961f0;
              }
              goto LAB_0059644c;
            }
          }
LAB_005961f0:
          iVar10 = iVar10 + 1;
          iVar3 = (*(code *)PTR_sk_num_006a7f2c)(section);
        } while (iVar10 < iVar3);
      }
      X509V3_section_free(param_2,section);
      iVar3 = (*(code *)PTR_sk_push_006a80a8)(iVar2,piVar7);
      if (iVar3 == 0) {
        a = (GENERAL_NAME *)0x0;
        pGVar4 = (GENERAL_NAMES *)0x0;
        (*(code *)PTR_ASN1_item_free_006a977c)(piVar7,DIST_POINT_it);
        goto LAB_00596254;
      }
LAB_005960b4:
      iVar14 = iVar14 + 1;
      iVar3 = (*(code *)PTR_sk_num_006a7f2c)(param_3);
    } while (iVar14 < iVar3);
  }
  return iVar2;
}

