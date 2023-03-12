
int i2r_crldp(undefined4 param_1,X509V3_CTX *param_2,BIO *param_3,BIO *param_4)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  int **ppiVar4;
  int iVar5;
  CONF_VALUE *cnf;
  GENERAL_NAME *pGVar6;
  GENERAL_NAMES *pGVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  stack_st_CONF_VALUE *section;
  int iVar10;
  stack_st_CONF_VALUE *psVar11;
  X509_NAME *nm;
  X509V3_EXT_METHOD *method;
  char *ctx;
  BIO *pBVar12;
  int iVar13;
  undefined4 uVar14;
  char *pcVar15;
  stack_st_X509_NAME_ENTRY *psVar16;
  int *piVar17;
  bool bVar18;
  int iVar19;
  BIO *pBVar20;
  int local_40 [5];
  X509V3_EXT_METHOD *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iVar19 = 0;
  local_2c = *(X509V3_EXT_METHOD **)PTR___stack_chk_guard_006aabf0;
  ctx = (char *)param_2;
  pBVar12 = param_3;
  iVar3 = (*(code *)PTR_sk_num_006a7f2c)(param_2);
  if (0 < iVar3) {
    do {
      (*(code *)PTR_BIO_puts_006a8058)(param_3,"\n");
      ppiVar4 = (int **)(*(code *)PTR_sk_value_006a7f24)(param_2,iVar19);
      piVar17 = *ppiVar4;
      if (piVar17 == (int *)0x0) {
LAB_00595c8c:
        piVar17 = ppiVar4[1];
      }
      else {
        if (*piVar17 != 0) {
          local_40[0] = piVar17[1];
          (*(code *)PTR_BIO_printf_006a7f38)
                    (param_3,"%*sRelative Name:\n%*s",param_4,"",
                     (undefined *)((int)&param_4->method + 2),"");
          pBVar12 = (BIO *)0x0;
          (*(code *)PTR_X509_NAME_print_ex_006a8cb0)(param_3,local_40,0,0x82031f);
          (*(code *)PTR_BIO_puts_006a8058)(param_3,"\n");
          goto LAB_00595c8c;
        }
        pBVar12 = param_4;
        (*(code *)PTR_BIO_printf_006a7f38)(param_3,"%*sFull Name:\n",param_4,"");
        pBVar20 = (BIO *)((int)&param_4->method + 2);
        iVar5 = piVar17[1];
        for (iVar3 = 0; iVar13 = (*(code *)PTR_sk_num_006a7f2c)(iVar5), iVar3 < iVar13;
            iVar3 = iVar3 + 1) {
          pBVar12 = pBVar20;
          (*(code *)PTR_BIO_printf_006a7f38)(param_3,&DAT_0066df84,pBVar20,"");
          pGVar6 = (GENERAL_NAME *)(*(code *)PTR_sk_value_006a7f24)(iVar5,iVar3);
          GENERAL_NAME_print(param_3,pGVar6);
          (*(code *)PTR_BIO_puts_006a8058)(param_3,"\n");
        }
        piVar17 = ppiVar4[1];
      }
      if (piVar17 != (int *)0x0) {
        pBVar12 = param_4;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (param_3,"%*s%s:\n%*s",param_4,"","Reasons",
                   (undefined *)((int)&param_4->method + 2),"");
        bVar18 = true;
        puVar8 = (undefined4 *)reason_flags;
        do {
          iVar3 = (*(code *)PTR_ASN1_BIT_STRING_get_bit_006aa184)(piVar17,*puVar8);
          if (iVar3 != 0) {
            if (!bVar18) {
              (*(code *)PTR_BIO_puts_006a8058)(param_3,", ");
            }
            bVar18 = false;
            (*(code *)PTR_BIO_puts_006a8058)(param_3,puVar8[1]);
          }
          piVar1 = puVar8 + 4;
          puVar8 = puVar8 + 3;
        } while (*piVar1 != 0);
        if (bVar18) {
          (*(code *)PTR_BIO_puts_006a8058)(param_3,"<EMPTY>\n");
        }
        else {
          (*(code *)PTR_BIO_puts_006a8058)(param_3,"\n");
        }
      }
      ctx = "r";
      if (ppiVar4[2] != (int *)0x0) {
        ctx = "%*sCRL Issuer:\n";
        pBVar12 = param_4;
        (*(code *)PTR_BIO_printf_006a7f38)(param_3,"%*sCRL Issuer:\n",param_4,"");
        pBVar20 = (BIO *)((int)&param_4->method + 2);
        piVar17 = ppiVar4[2];
        for (iVar3 = 0; iVar5 = (*(code *)PTR_sk_num_006a7f2c)(piVar17), iVar3 < iVar5;
            iVar3 = iVar3 + 1) {
          pBVar12 = pBVar20;
          (*(code *)PTR_BIO_printf_006a7f38)(param_3,&DAT_0066df84,pBVar20,"");
          pGVar6 = (GENERAL_NAME *)(*(code *)PTR_sk_value_006a7f24)(piVar17,iVar3);
          GENERAL_NAME_print(param_3,pGVar6);
          ctx = (char *)(X509V3_CTX *)0x63bac8;
          (*(code *)PTR_BIO_puts_006a8058)(param_3);
        }
      }
      iVar19 = iVar19 + 1;
      iVar3 = (*(code *)PTR_sk_num_006a7f2c)(param_2);
    } while (iVar19 < iVar3);
  }
  if (local_2c == *(X509V3_EXT_METHOD **)puVar2) {
    return 1;
  }
  method = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar3 = (*(code *)PTR_sk_new_null_006a80a4)();
  if (iVar3 != 0) {
    iVar5 = 0;
    iVar19 = (*(code *)PTR_sk_num_006a7f2c)(pBVar12);
    if (0 < iVar19) {
      do {
        cnf = (CONF_VALUE *)(*(code *)PTR_sk_value_006a7f24)(pBVar12,iVar5);
        if (cnf->value != (char *)0x0) {
          pGVar6 = v2i_GENERAL_NAME(method,(X509V3_CTX *)ctx,cnf);
          if (pGVar6 != (GENERAL_NAME *)0x0) {
            pGVar7 = GENERAL_NAMES_new();
            if ((pGVar7 == (GENERAL_NAMES *)0x0) ||
               (iVar19 = (*(code *)PTR_sk_push_006a80a8)(pGVar7,pGVar6), iVar19 == 0))
            goto LAB_00596254;
            puVar8 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(DIST_POINT_it);
            if (puVar8 != (undefined4 *)0x0) {
              iVar19 = (*(code *)PTR_sk_push_006a80a8)(iVar3,puVar8);
              if (iVar19 == 0) {
                pGVar6 = (GENERAL_NAME *)0x0;
                (*(code *)PTR_ASN1_item_free_006a977c)(puVar8,DIST_POINT_it);
                goto LAB_00596254;
              }
              puVar9 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(DIST_POINT_NAME_it);
              *puVar8 = puVar9;
              if (puVar9 != (undefined4 *)0x0) {
                puVar9[1] = pGVar7;
                *puVar9 = 0;
                goto LAB_005960b4;
              }
            }
            pGVar6 = (GENERAL_NAME *)0x0;
            goto LAB_00596254;
          }
LAB_0059636c:
          pGVar6 = (GENERAL_NAME *)0x0;
          pGVar7 = (GENERAL_NAMES *)0x0;
          goto LAB_0059627c;
        }
        section = X509V3_get_section((X509V3_CTX *)ctx,cnf->name);
        if (section == (stack_st_CONF_VALUE *)0x0) goto LAB_0059636c;
        piVar17 = (int *)(*(code *)PTR_ASN1_item_new_006a9778)(DIST_POINT_it);
        if (piVar17 == (int *)0x0) {
          X509V3_section_free((X509V3_CTX *)ctx,section);
          goto LAB_0059636c;
        }
        iVar13 = 0;
        iVar19 = (*(code *)PTR_sk_num_006a7f2c)(section);
        if (0 < iVar19) {
          do {
            iVar19 = (*(code *)PTR_sk_value_006a7f24)(section,iVar13);
            uVar14 = *(undefined4 *)(iVar19 + 4);
            iVar10 = (*(code *)PTR_strcmp_006aac20)(uVar14,"fullname");
            if (iVar10 == 0) {
              pcVar15 = *(char **)(iVar19 + 8);
              if (*pcVar15 == '@') {
                psVar11 = X509V3_get_section((X509V3_CTX *)ctx,pcVar15 + 1);
              }
              else {
                psVar11 = X509V3_parse_list(pcVar15);
              }
              if (psVar11 == (stack_st_CONF_VALUE *)0x0) {
                (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x9c,0x96,"v3_crld.c",0x68);
              }
              else {
                pGVar7 = v2i_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,(X509V3_CTX *)ctx,psVar11);
                if (*pcVar15 == '@') {
                  X509V3_section_free((X509V3_CTX *)ctx,psVar11);
                }
                else {
                  (*(code *)PTR_sk_pop_free_006a8158)(psVar11,PTR_X509V3_conf_free_006a8c38);
                }
                if (pGVar7 != (GENERAL_NAMES *)0x0) {
                  psVar16 = (stack_st_X509_NAME_ENTRY *)0x0;
                  if (*piVar17 == 0) {
LAB_00596544:
                    puVar8 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(DIST_POINT_NAME_it)
                    ;
                    *piVar17 = (int)puVar8;
                    if (puVar8 != (undefined4 *)0x0) {
                      if (pGVar7 == (GENERAL_NAMES *)0x0) {
                        puVar8[1] = psVar16;
                        *puVar8 = 1;
                      }
                      else {
                        puVar8[1] = pGVar7;
                        *puVar8 = 0;
                      }
                      goto LAB_005961f0;
                    }
                  }
                  else {
LAB_005963f0:
                    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x9e,0xa0,"v3_crld.c",0xa5);
                  }
                  if (pGVar7 != (GENERAL_NAMES *)0x0) {
                    (*(code *)PTR_sk_pop_free_006a8158)(pGVar7,PTR_GENERAL_NAME_free_006a84a4);
                  }
LAB_00596430:
                  if (psVar16 != (stack_st_X509_NAME_ENTRY *)0x0) {
                    (*(code *)PTR_sk_pop_free_006a8158)(psVar16,PTR_X509_NAME_ENTRY_free_006a8250);
                  }
                }
              }
LAB_0059644c:
              (*(code *)PTR_ASN1_item_free_006a977c)(piVar17,DIST_POINT_it);
              X509V3_section_free((X509V3_CTX *)ctx,section);
              goto LAB_0059636c;
            }
            iVar10 = (*(code *)PTR_strcmp_006aac20)(uVar14,"relativename");
            if (iVar10 == 0) {
              nm = (X509_NAME *)(*(code *)PTR_X509_NAME_new_006a8238)();
              if (nm != (X509_NAME *)0x0) {
                psVar11 = X509V3_get_section((X509V3_CTX *)ctx,*(char **)(iVar19 + 8));
                if (psVar11 != (stack_st_CONF_VALUE *)0x0) {
                  iVar19 = X509V3_NAME_from_section(nm,psVar11,0x1001);
                  X509V3_section_free((X509V3_CTX *)ctx,psVar11);
                  puVar2 = PTR_X509_NAME_free_006a80f8;
                  psVar16 = nm->entries;
                  nm->entries = (stack_st_X509_NAME_ENTRY *)0x0;
                  (*(code *)puVar2)(nm);
                  if ((iVar19 != 0) &&
                     (iVar19 = (*(code *)PTR_sk_num_006a7f2c)(psVar16), 0 < iVar19)) {
                    iVar19 = (*(code *)PTR_sk_num_006a7f2c)(psVar16);
                    iVar19 = (*(code *)PTR_sk_value_006a7f24)(psVar16,iVar19 + -1);
                    if (*(int *)(iVar19 + 8) == 0) {
                      pGVar7 = (GENERAL_NAMES *)0x0;
                      if (*piVar17 != 0) goto LAB_005963f0;
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
            iVar10 = (*(code *)PTR_strcmp_006aac20)(uVar14,"reasons");
            if (iVar10 == 0) {
              iVar19 = set_reasons(piVar17 + 1,*(undefined4 *)(iVar19 + 8));
              if (iVar19 == 0) goto LAB_0059644c;
            }
            else {
              iVar10 = (*(code *)PTR_strcmp_006aac20)(uVar14,"CRLissuer");
              if (iVar10 == 0) {
                pcVar15 = *(char **)(iVar19 + 8);
                if (*pcVar15 == '@') {
                  psVar11 = X509V3_get_section((X509V3_CTX *)ctx,pcVar15 + 1);
                }
                else {
                  psVar11 = X509V3_parse_list(pcVar15);
                }
                if (psVar11 == (stack_st_CONF_VALUE *)0x0) {
                  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x9c,0x96,"v3_crld.c",0x68);
                  piVar17[2] = 0;
                }
                else {
                  pGVar7 = v2i_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,(X509V3_CTX *)ctx,psVar11);
                  if (*pcVar15 == '@') {
                    X509V3_section_free((X509V3_CTX *)ctx,psVar11);
                  }
                  else {
                    (*(code *)PTR_sk_pop_free_006a8158)(psVar11,PTR_X509V3_conf_free_006a8c38);
                  }
                  piVar17[2] = (int)pGVar7;
                  if (pGVar7 != (GENERAL_NAMES *)0x0) goto LAB_005961f0;
                }
                goto LAB_0059644c;
              }
            }
LAB_005961f0:
            iVar13 = iVar13 + 1;
            iVar19 = (*(code *)PTR_sk_num_006a7f2c)(section);
          } while (iVar13 < iVar19);
        }
        X509V3_section_free((X509V3_CTX *)ctx,section);
        iVar19 = (*(code *)PTR_sk_push_006a80a8)(iVar3,piVar17);
        if (iVar19 == 0) {
          pGVar6 = (GENERAL_NAME *)0x0;
          pGVar7 = (GENERAL_NAMES *)0x0;
          (*(code *)PTR_ASN1_item_free_006a977c)(piVar17,DIST_POINT_it);
          goto LAB_00596254;
        }
LAB_005960b4:
        iVar5 = iVar5 + 1;
        iVar19 = (*(code *)PTR_sk_num_006a7f2c)(pBVar12);
      } while (iVar5 < iVar19);
    }
    return iVar3;
  }
  pGVar6 = (GENERAL_NAME *)0x0;
  pGVar7 = (GENERAL_NAMES *)0x0;
LAB_00596254:
  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x86,0x41,"v3_crld.c",0x16d);
LAB_0059627c:
  GENERAL_NAME_free(pGVar6);
  GENERAL_NAMES_free(pGVar7);
  (*(code *)PTR_sk_pop_free_006a8158)(iVar3,DIST_POINT_free);
  return 0;
}

