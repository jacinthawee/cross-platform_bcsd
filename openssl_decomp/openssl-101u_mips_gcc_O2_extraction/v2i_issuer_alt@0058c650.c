
int v2i_issuer_alt(undefined4 param_1,X509V3_CTX *param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  GENERAL_NAME *a;
  undefined4 uVar5;
  OTHERNAME *pOVar6;
  ASN1_TYPE *pAVar7;
  ASN1_OBJECT *pAVar8;
  X509_EXTENSION *ext;
  void *pvVar9;
  ASN1_OCTET_STRING *pAVar10;
  X509_NAME *nm;
  stack_st_CONF_VALUE *dn_sk;
  undefined4 uVar11;
  int iVar12;
  char *section;
  char *pcVar13;
  
  iVar2 = (*(code *)PTR_sk_new_null_006a6fa4)();
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x99,0x41,"v3_alt.c",0xf7);
    return 0;
  }
  iVar12 = 0;
  iVar3 = (*(code *)PTR_sk_num_006a6e2c)(param_3);
  if (0 < iVar3) {
    do {
      iVar3 = (*(code *)PTR_sk_value_006a6e24)(param_3,iVar12);
      iVar4 = name_cmp(*(char **)(iVar3 + 4),"issuer");
      section = *(char **)(iVar3 + 8);
      if (iVar4 != 0) {
        pcVar13 = *(char **)(iVar3 + 4);
        if (section == (char *)0x0) goto LAB_0058c8a8;
LAB_0058c744:
        iVar3 = name_cmp(pcVar13,"email");
        if (iVar3 == 0) {
          iVar3 = 1;
          a = GENERAL_NAME_new();
joined_r0x0058c810:
          if (a == (GENERAL_NAME *)0x0) {
LAB_0058c794:
            (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,0x41,"v3_alt.c",0x1be);
            goto LAB_0058c7bc;
          }
          pcVar13 = (char *)(*(code *)PTR_ASN1_STRING_type_new_006a8680)(0x16);
          (a->d).ptr = pcVar13;
          if (pcVar13 != (char *)0x0) {
            uVar5 = (*(code *)PTR_strlen_006a9a24)(section);
            iVar4 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)(pcVar13,section,uVar5);
            if (iVar4 != 0) {
LAB_0058c9fc:
              puVar1 = PTR_sk_push_006a6fa8;
              a->type = iVar3;
              (*(code *)puVar1)(iVar2,a);
              goto LAB_0058ca18;
            }
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,0x41,"v3_alt.c",0x1f8);
        }
        else {
          iVar3 = name_cmp(pcVar13,"URI");
          if (iVar3 == 0) {
            iVar3 = 6;
LAB_0058c77c:
            a = GENERAL_NAME_new();
            goto joined_r0x0058c810;
          }
          iVar3 = name_cmp(pcVar13,"DNS");
          if (iVar3 == 0) {
            iVar3 = 2;
            goto LAB_0058c77c;
          }
          iVar3 = name_cmp(pcVar13,"RID");
          if (iVar3 != 0) {
            iVar3 = name_cmp(pcVar13,"IP");
            if (iVar3 != 0) {
              iVar3 = name_cmp(pcVar13,"dirName");
              if (iVar3 == 0) {
                a = GENERAL_NAME_new();
                if (a != (GENERAL_NAME *)0x0) {
                  nm = (X509_NAME *)(*(code *)PTR_X509_NAME_new_006a7138)();
                  if (nm == (X509_NAME *)0x0) {
                    dn_sk = (stack_st_CONF_VALUE *)0x0;
                  }
                  else {
                    dn_sk = X509V3_get_section(param_2,section);
                    if (dn_sk == (stack_st_CONF_VALUE *)0x0) {
                      (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x90,0x96,"v3_alt.c",0x252);
                      (*(code *)PTR_ERR_add_error_data_006a813c)(2,"section=",section);
                    }
                    else {
                      iVar3 = X509V3_NAME_from_section(nm,dn_sk,0x1001);
                      if (iVar3 != 0) {
                        (a->d).directoryName = nm;
                        X509V3_section_free(param_2,dn_sk);
                        puVar1 = PTR_sk_push_006a6fa8;
                        a->type = 4;
                        (*(code *)puVar1)(iVar2,a);
                        goto LAB_0058ca18;
                      }
                    }
                  }
                  (*(code *)PTR_X509_NAME_free_006a6ff8)(nm);
                  X509V3_section_free(param_2,dn_sk);
                  (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,0x95,"v3_alt.c",0x1e4);
                  goto LAB_0058c88c;
                }
                goto LAB_0058c794;
              }
              iVar3 = name_cmp(pcVar13,"otherName");
              if (iVar3 != 0) {
                (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x75,0x75,"v3_alt.c",0x226);
                (*(code *)PTR_ERR_add_error_data_006a813c)(2,"name=",pcVar13);
                goto LAB_0058c7bc;
              }
              a = GENERAL_NAME_new();
              if (a == (GENERAL_NAME *)0x0) goto LAB_0058c794;
              iVar3 = (*(code *)PTR_strchr_006a9a28)(section,0x3b);
              if (iVar3 == 0) {
LAB_0058ce68:
                (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,0x93,"v3_alt.c",0x1eb);
                goto LAB_0058c88c;
              }
              pOVar6 = OTHERNAME_new();
              (a->d).otherName = pOVar6;
              if (pOVar6 == (OTHERNAME *)0x0) goto LAB_0058ce68;
              (*(code *)PTR_ASN1_TYPE_free_006a7498)(pOVar6->value);
              pOVar6 = (a->d).otherName;
              pAVar7 = (ASN1_TYPE *)(*(code *)PTR_ASN1_generate_v3_006a8ffc)(iVar3 + 1,param_2);
              pOVar6->value = pAVar7;
              if (pAVar7 == (ASN1_TYPE *)0x0) goto LAB_0058ce68;
              iVar3 = iVar3 - (int)section;
              iVar4 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar3 + 1,"v3_alt.c",0x23f);
              (*(code *)PTR_strncpy_006a99e0)(iVar4,section,iVar3);
              *(undefined *)(iVar4 + iVar3) = 0;
              pOVar6 = (a->d).otherName;
              pAVar8 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_txt2obj_006a7000)(iVar4,0);
              puVar1 = PTR_CRYPTO_free_006a6e88;
              pOVar6->type_id = pAVar8;
              (*(code *)puVar1)(iVar4);
              if (((a->d).otherName)->type_id == (ASN1_OBJECT *)0x0) goto LAB_0058ce68;
              iVar3 = 0;
              goto LAB_0058c9fc;
            }
            a = GENERAL_NAME_new();
            if (a != (GENERAL_NAME *)0x0) {
              pAVar10 = a2i_IPADDRESS(section);
              (a->d).iPAddress = pAVar10;
              puVar1 = PTR_sk_push_006a6fa8;
              if (pAVar10 == (ASN1_OCTET_STRING *)0x0) {
                uVar11 = 0x76;
                uVar5 = 0x1dc;
                goto LAB_0058cc9c;
              }
              a->type = 7;
              (*(code *)puVar1)(iVar2,a);
              goto LAB_0058ca18;
            }
            goto LAB_0058c794;
          }
          a = GENERAL_NAME_new();
          if (a == (GENERAL_NAME *)0x0) goto LAB_0058c794;
          pcVar13 = (char *)(*(code *)PTR_OBJ_txt2obj_006a7000)(section,0);
          puVar1 = PTR_sk_push_006a6fa8;
          if (pcVar13 != (char *)0x0) {
            (a->d).ptr = pcVar13;
            a->type = 8;
            (*(code *)puVar1)(iVar2,a);
            goto LAB_0058ca18;
          }
          uVar11 = 0x77;
          uVar5 = 0x1ce;
LAB_0058cc9c:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,uVar11,"v3_alt.c",uVar5);
          (*(code *)PTR_ERR_add_error_data_006a813c)(2,"value=",section);
        }
LAB_0058c88c:
        GENERAL_NAME_free(a);
LAB_0058c7bc:
        (*(code *)PTR_sk_pop_free_006a7058)(iVar2,PTR_GENERAL_NAME_free_006a73a4);
        return 0;
      }
      if (section == (char *)0x0) {
LAB_0058c8a8:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x75,0x7c,"v3_alt.c",0x213);
        goto LAB_0058c7bc;
      }
      iVar4 = (*(code *)PTR_strcmp_006a9b18)(section,&DAT_0063fb8c);
      if (iVar4 != 0) {
        pcVar13 = *(char **)(iVar3 + 4);
        goto LAB_0058c744;
      }
      if (param_2 == (X509V3_CTX *)0x0) {
LAB_0058cb50:
        uVar11 = 0x7f;
        uVar5 = 0x118;
LAB_0058cb64:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x7b,uVar11,"v3_alt.c",uVar5);
        goto LAB_0058c7bc;
      }
      if (param_2->flags != 1) {
        if (param_2->issuer_cert == (X509 *)0x0) goto LAB_0058cb50;
        iVar3 = X509_get_ext_by_NID(param_2->issuer_cert,0x55,-1);
        if (-1 < iVar3) {
          ext = X509_get_ext(param_2->issuer_cert,iVar3);
          if ((ext == (X509_EXTENSION *)0x0) ||
             (pvVar9 = X509V3_EXT_d2i(ext), pvVar9 == (void *)0x0)) {
            uVar11 = 0x7e;
            uVar5 = 0x120;
            goto LAB_0058cb64;
          }
          iVar3 = 0;
          while( true ) {
            iVar4 = (*(code *)PTR_sk_num_006a6e2c)(pvVar9);
            if (iVar4 <= iVar3) break;
            uVar5 = (*(code *)PTR_sk_value_006a6e24)(pvVar9,iVar3);
            iVar4 = (*(code *)PTR_sk_push_006a6fa8)(iVar2,uVar5);
            iVar3 = iVar3 + 1;
            if (iVar4 == 0) {
              uVar11 = 0x41;
              uVar5 = 0x127;
              goto LAB_0058cb64;
            }
          }
          (*(code *)PTR_sk_free_006a6e80)();
        }
      }
LAB_0058ca18:
      iVar12 = iVar12 + 1;
      iVar3 = (*(code *)PTR_sk_num_006a6e2c)(param_3);
    } while (iVar12 < iVar3);
  }
  return iVar2;
}

