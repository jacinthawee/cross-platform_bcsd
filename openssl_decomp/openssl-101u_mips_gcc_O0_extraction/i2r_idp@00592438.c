
int * i2r_idp(undefined4 param_1,X509V3_CTX *param_2,BIO *param_3,BIO *param_4)

{
  bool bVar1;
  undefined *puVar2;
  X509 *pXVar3;
  int iVar4;
  GENERAL_NAME *gen;
  int iVar5;
  CONF_VALUE *value;
  X509_NAME *nm;
  stack_st_CONF_VALUE *psVar6;
  undefined4 *puVar7;
  char *ctx;
  BIO *pBVar8;
  int iVar9;
  int *piVar10;
  char *pcVar11;
  stack_st_X509_NAME_ENTRY *psVar12;
  GENERAL_NAMES *pGVar13;
  X509_REQ *pXVar14;
  char *line;
  BIO *pBVar15;
  int local_40 [5];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  piVar10 = (int *)param_2->flags;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ctx = (char *)param_2;
  pBVar8 = param_3;
  if (piVar10 != (int *)0x0) {
    if (*piVar10 == 0) {
      ctx = "%*sFull Name:\n";
      pBVar8 = param_4;
      (*(code *)PTR_BIO_printf_006a6e38)(param_3,"%*sFull Name:\n",param_4,"");
      pBVar15 = (BIO *)((int)&param_4->method + 2);
      iVar9 = piVar10[1];
      for (iVar4 = 0; iVar5 = (*(code *)PTR_sk_num_006a6e2c)(iVar9), iVar4 < iVar5;
          iVar4 = iVar4 + 1) {
        pBVar8 = pBVar15;
        (*(code *)PTR_BIO_printf_006a6e38)(param_3,&DAT_0066d674,pBVar15,"");
        gen = (GENERAL_NAME *)(*(code *)PTR_sk_value_006a6e24)(iVar9,iVar4);
        GENERAL_NAME_print(param_3,gen);
        ctx = (char *)(X509V3_CTX *)0x63b2e4;
        (*(code *)PTR_BIO_puts_006a6f58)(param_3);
      }
      pXVar3 = param_2->issuer_cert;
      goto LAB_00592518;
    }
    local_40[0] = piVar10[1];
    (*(code *)PTR_BIO_printf_006a6e38)
              (param_3,"%*sRelative Name:\n%*s",param_4,"",(undefined *)((int)&param_4->method + 2),
               "");
    pBVar8 = (BIO *)0x0;
    (*(code *)PTR_X509_NAME_print_ex_006a7bc4)(param_3,local_40,0,0x82031f);
    ctx = "\n";
    (*(code *)PTR_BIO_puts_006a6f58)(param_3);
  }
  pXVar3 = param_2->issuer_cert;
LAB_00592518:
  if (0 < (int)pXVar3) {
    ctx = "%*sOnly User Certificates\n";
    pBVar8 = param_4;
    (*(code *)PTR_BIO_printf_006a6e38)(param_3,"%*sOnly User Certificates\n",param_4,"");
  }
  if (0 < (int)param_2->subject_cert) {
    ctx = "%*sOnly CA Certificates\n";
    pBVar8 = param_4;
    (*(code *)PTR_BIO_printf_006a6e38)(param_3,"%*sOnly CA Certificates\n",param_4,"");
  }
  if (0 < (int)param_2->crl) {
    ctx = "%*sIndirect CRL\n";
    pBVar8 = param_4;
    (*(code *)PTR_BIO_printf_006a6e38)(param_3,"%*sIndirect CRL\n",param_4,"");
  }
  pXVar14 = param_2->subject_req;
  if (pXVar14 != (X509_REQ *)0x0) {
    pBVar8 = param_4;
    (*(code *)PTR_BIO_printf_006a6e38)
              (param_3,"%*s%s:\n%*s",param_4,"","Only Some Reasons",
               (undefined *)((int)&param_4->method + 2),"");
    bVar1 = true;
    puVar7 = (undefined4 *)reason_flags;
    do {
      iVar4 = (*(code *)PTR_ASN1_BIT_STRING_get_bit_006a9068)(pXVar14,*puVar7);
      if (iVar4 != 0) {
        if (!bVar1) {
          (*(code *)PTR_BIO_puts_006a6f58)(param_3,", ");
        }
        bVar1 = false;
        (*(code *)PTR_BIO_puts_006a6f58)(param_3,puVar7[1]);
      }
      piVar10 = puVar7 + 4;
      puVar7 = puVar7 + 3;
    } while (*piVar10 != 0);
    if (bVar1) {
      ctx = "<EMPTY>\n";
      (*(code *)PTR_BIO_puts_006a6f58)();
    }
    else {
      ctx = "\n";
      (*(code *)PTR_BIO_puts_006a6f58)(param_3);
    }
  }
  if (0 < (int)param_2->db_meth) {
    ctx = "%*sOnly Attribute Certificates\n";
    pBVar8 = param_4;
    (*(code *)PTR_BIO_printf_006a6e38)(param_3,"%*sOnly Attribute Certificates\n",param_4,"");
  }
  if (((((param_2->flags == 0) && ((int)param_2->issuer_cert < 1)) &&
       ((int)param_2->subject_cert < 1)) &&
      (((int)param_2->crl < 1 && (param_2->subject_req == (X509_REQ *)0x0)))) &&
     ((int)param_2->db_meth < 1)) {
    ctx = "%*s<EMPTY>\n";
    (*(code *)PTR_BIO_printf_006a6e38)(param_3,"%*s<EMPTY>\n",param_4,"");
    pBVar8 = param_4;
  }
  if (local_2c == *(int *)puVar2) {
    return (int *)0x1;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  piVar10 = (int *)(*(code *)PTR_ASN1_item_new_006a8654)(ISSUING_DIST_POINT_it);
  if (piVar10 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x9d,0x41,"v3_crld.c",0x1cb);
LAB_00592adc:
    (*(code *)PTR_ASN1_item_free_006a8658)(piVar10,ISSUING_DIST_POINT_it);
    return (int *)0x0;
  }
  iVar9 = 0;
  iVar4 = (*(code *)PTR_sk_num_006a6e2c)(pBVar8);
  if (0 < iVar4) {
    do {
      value = (CONF_VALUE *)(*(code *)PTR_sk_value_006a6e24)(pBVar8,iVar9);
      pcVar11 = value->name;
      line = value->value;
      iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"fullname");
      if (iVar4 == 0) {
        if (*line == '@') {
          psVar6 = X509V3_get_section((X509V3_CTX *)ctx,line + 1);
        }
        else {
          psVar6 = X509V3_parse_list(line);
        }
        if (psVar6 == (stack_st_CONF_VALUE *)0x0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x9c,0x96,"v3_crld.c",0x66);
        }
        else {
          pGVar13 = v2i_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,(X509V3_CTX *)ctx,psVar6);
          if (*line == '@') {
            X509V3_section_free((X509V3_CTX *)ctx,psVar6);
          }
          else {
            (*(code *)PTR_sk_pop_free_006a7058)(psVar6,PTR_X509V3_conf_free_006a7b4c);
          }
          if (pGVar13 != (GENERAL_NAMES *)0x0) {
            iVar4 = *piVar10;
            psVar12 = (stack_st_X509_NAME_ENTRY *)0x0;
joined_r0x00592a78:
            if (iVar4 == 0) {
              puVar7 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a8654)(DIST_POINT_NAME_it);
              *piVar10 = (int)puVar7;
              if (puVar7 != (undefined4 *)0x0) {
                if (pGVar13 == (GENERAL_NAMES *)0x0) {
                  puVar7[1] = psVar12;
                  *puVar7 = 1;
                }
                else {
                  puVar7[1] = pGVar13;
                  *puVar7 = 0;
                }
                goto LAB_005929c0;
              }
            }
            else {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x9e,0xa0,"v3_crld.c",0x9c);
            }
            if (pGVar13 != (GENERAL_NAMES *)0x0) {
              (*(code *)PTR_sk_pop_free_006a7058)(pGVar13,PTR_GENERAL_NAME_free_006a73a4);
            }
LAB_00592ac0:
            if (psVar12 != (stack_st_X509_NAME_ENTRY *)0x0) {
              (*(code *)PTR_sk_pop_free_006a7058)(psVar12,PTR_X509_NAME_ENTRY_free_006a7150);
            }
          }
        }
        goto LAB_00592adc;
      }
      iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"relativename");
      if (iVar4 == 0) {
        nm = (X509_NAME *)(*(code *)PTR_X509_NAME_new_006a7138)();
        if (nm != (X509_NAME *)0x0) {
          psVar6 = X509V3_get_section((X509V3_CTX *)ctx,value->value);
          if (psVar6 != (stack_st_CONF_VALUE *)0x0) {
            iVar4 = X509V3_NAME_from_section(nm,psVar6,0x1001);
            X509V3_section_free((X509V3_CTX *)ctx,psVar6);
            puVar2 = PTR_X509_NAME_free_006a6ff8;
            psVar12 = nm->entries;
            nm->entries = (stack_st_X509_NAME_ENTRY *)0x0;
            (*(code *)puVar2)(nm);
            if ((iVar4 != 0) && (iVar4 = (*(code *)PTR_sk_num_006a6e2c)(psVar12), 0 < iVar4)) {
              iVar4 = (*(code *)PTR_sk_num_006a6e2c)(psVar12);
              iVar4 = (*(code *)PTR_sk_value_006a6e24)(psVar12,iVar4 + -1);
              if (*(int *)(iVar4 + 8) == 0) {
                iVar4 = *piVar10;
                pGVar13 = (GENERAL_NAMES *)0x0;
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
      iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"onlyuser");
      if (iVar4 == 0) {
        iVar4 = X509V3_get_value_bool(value,piVar10 + 1);
      }
      else {
        iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"onlyCA");
        if (iVar4 == 0) {
          iVar4 = X509V3_get_value_bool(value,piVar10 + 2);
        }
        else {
          iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"onlyAA");
          if (iVar4 == 0) {
            iVar4 = X509V3_get_value_bool(value,piVar10 + 5);
          }
          else {
            iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"indirectCRL");
            if (iVar4 != 0) {
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"onlysomereasons");
              if (iVar4 == 0) {
                iVar4 = set_reasons(piVar10 + 3,line);
                if (iVar4 != 0) goto LAB_005929c0;
              }
              else {
                (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x9d,0x6a,"v3_crld.c",0x1c3);
                (*(code *)PTR_ERR_add_error_data_006a813c)
                          (6,"section:",value->section,",name:",value->name,",value:",value->value);
              }
              goto LAB_00592adc;
            }
            iVar4 = X509V3_get_value_bool(value,piVar10 + 4);
          }
        }
      }
      if (iVar4 == 0) goto LAB_00592adc;
LAB_005929c0:
      iVar9 = iVar9 + 1;
      iVar4 = (*(code *)PTR_sk_num_006a6e2c)(pBVar8);
    } while (iVar9 < iVar4);
  }
  return piVar10;
}

