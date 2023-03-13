
int * v2i_idp(undefined4 param_1,X509V3_CTX *param_2,undefined4 param_3)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  CONF_VALUE *value;
  X509_NAME *nm;
  stack_st_CONF_VALUE *psVar4;
  undefined4 *puVar5;
  int iVar6;
  char *pcVar7;
  stack_st_X509_NAME_ENTRY *psVar8;
  GENERAL_NAMES *pGVar9;
  char *line;
  
  piVar2 = (int *)(*(code *)PTR_ASN1_item_new_006a8654)(ISSUING_DIST_POINT_it);
  if (piVar2 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x9d,0x41,"v3_crld.c",0x1cb);
LAB_00592adc:
    (*(code *)PTR_ASN1_item_free_006a8658)(piVar2,ISSUING_DIST_POINT_it);
    return (int *)0x0;
  }
  iVar6 = 0;
  iVar3 = (*(code *)PTR_sk_num_006a6e2c)(param_3);
  if (0 < iVar3) {
    do {
      value = (CONF_VALUE *)(*(code *)PTR_sk_value_006a6e24)(param_3,iVar6);
      pcVar7 = value->name;
      line = value->value;
      iVar3 = (*(code *)PTR_strcmp_006a9b18)(pcVar7,"fullname");
      if (iVar3 == 0) {
        if (*line == '@') {
          psVar4 = X509V3_get_section(param_2,line + 1);
        }
        else {
          psVar4 = X509V3_parse_list(line);
        }
        if (psVar4 == (stack_st_CONF_VALUE *)0x0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x9c,0x96,"v3_crld.c",0x66);
        }
        else {
          pGVar9 = v2i_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,param_2,psVar4);
          if (*line == '@') {
            X509V3_section_free(param_2,psVar4);
          }
          else {
            (*(code *)PTR_sk_pop_free_006a7058)(psVar4,PTR_X509V3_conf_free_006a7b4c);
          }
          if (pGVar9 != (GENERAL_NAMES *)0x0) {
            iVar3 = *piVar2;
            psVar8 = (stack_st_X509_NAME_ENTRY *)0x0;
joined_r0x00592a78:
            if (iVar3 == 0) {
              puVar5 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a8654)(DIST_POINT_NAME_it);
              *piVar2 = (int)puVar5;
              if (puVar5 != (undefined4 *)0x0) {
                if (pGVar9 == (GENERAL_NAMES *)0x0) {
                  puVar5[1] = psVar8;
                  *puVar5 = 1;
                }
                else {
                  puVar5[1] = pGVar9;
                  *puVar5 = 0;
                }
                goto LAB_005929c0;
              }
            }
            else {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x9e,0xa0,"v3_crld.c",0x9c);
            }
            if (pGVar9 != (GENERAL_NAMES *)0x0) {
              (*(code *)PTR_sk_pop_free_006a7058)(pGVar9,PTR_GENERAL_NAME_free_006a73a4);
            }
LAB_00592ac0:
            if (psVar8 != (stack_st_X509_NAME_ENTRY *)0x0) {
              (*(code *)PTR_sk_pop_free_006a7058)(psVar8,PTR_X509_NAME_ENTRY_free_006a7150);
            }
          }
        }
        goto LAB_00592adc;
      }
      iVar3 = (*(code *)PTR_strcmp_006a9b18)(pcVar7,"relativename");
      if (iVar3 == 0) {
        nm = (X509_NAME *)(*(code *)PTR_X509_NAME_new_006a7138)();
        if (nm != (X509_NAME *)0x0) {
          psVar4 = X509V3_get_section(param_2,value->value);
          if (psVar4 != (stack_st_CONF_VALUE *)0x0) {
            iVar3 = X509V3_NAME_from_section(nm,psVar4,0x1001);
            X509V3_section_free(param_2,psVar4);
            puVar1 = PTR_X509_NAME_free_006a6ff8;
            psVar8 = nm->entries;
            nm->entries = (stack_st_X509_NAME_ENTRY *)0x0;
            (*(code *)puVar1)(nm);
            if ((iVar3 != 0) && (iVar3 = (*(code *)PTR_sk_num_006a6e2c)(psVar8), 0 < iVar3)) {
              iVar3 = (*(code *)PTR_sk_num_006a6e2c)(psVar8);
              iVar3 = (*(code *)PTR_sk_value_006a6e24)(psVar8,iVar3 + -1);
              if (*(int *)(iVar3 + 8) == 0) {
                iVar3 = *piVar2;
                pGVar9 = (GENERAL_NAMES *)0x0;
                goto joined_r0x00592a78;
              }
              (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x9e,0xa1,"v3_crld.c",0x94);
            }
            goto LAB_00592ac0;
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x9e,0x96,"v3_crld.c",0x84);
        }
        goto LAB_00592adc;
      }
      iVar3 = (*(code *)PTR_strcmp_006a9b18)(pcVar7,"onlyuser");
      if (iVar3 == 0) {
        iVar3 = X509V3_get_value_bool(value,piVar2 + 1);
      }
      else {
        iVar3 = (*(code *)PTR_strcmp_006a9b18)(pcVar7,"onlyCA");
        if (iVar3 == 0) {
          iVar3 = X509V3_get_value_bool(value,piVar2 + 2);
        }
        else {
          iVar3 = (*(code *)PTR_strcmp_006a9b18)(pcVar7,"onlyAA");
          if (iVar3 == 0) {
            iVar3 = X509V3_get_value_bool(value,piVar2 + 5);
          }
          else {
            iVar3 = (*(code *)PTR_strcmp_006a9b18)(pcVar7,"indirectCRL");
            if (iVar3 != 0) {
              iVar3 = (*(code *)PTR_strcmp_006a9b18)(pcVar7,"onlysomereasons");
              if (iVar3 == 0) {
                iVar3 = set_reasons(piVar2 + 3,line);
                if (iVar3 != 0) goto LAB_005929c0;
              }
              else {
                (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x9d,0x6a,"v3_crld.c",0x1c3);
                (*(code *)PTR_ERR_add_error_data_006a813c)
                          (6,"section:",value->section,",name:",value->name,",value:",value->value);
              }
              goto LAB_00592adc;
            }
            iVar3 = X509V3_get_value_bool(value,piVar2 + 4);
          }
        }
      }
      if (iVar3 == 0) goto LAB_00592adc;
LAB_005929c0:
      iVar6 = iVar6 + 1;
      iVar3 = (*(code *)PTR_sk_num_006a6e2c)(param_3);
    } while (iVar6 < iVar3);
  }
  return piVar2;
}

