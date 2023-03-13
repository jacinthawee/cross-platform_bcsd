
int v2i_subject_alt(undefined4 param_1,X509V3_CTX *param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  GENERAL_NAME *pGVar5;
  undefined4 uVar6;
  OTHERNAME *pOVar7;
  ASN1_TYPE *pAVar8;
  ASN1_OBJECT *pAVar9;
  X509_NAME_ENTRY *pXVar10;
  ASN1_STRING *pAVar11;
  ASN1_OCTET_STRING *pAVar12;
  X509_NAME *pXVar13;
  stack_st_CONF_VALUE *dn_sk;
  undefined4 uVar14;
  int iVar15;
  char *pcVar16;
  char *pcVar17;
  
  iVar2 = (*(code *)PTR_sk_new_null_006a6fa4)();
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x9a,0x41,"v3_alt.c",0x13c);
    return 0;
  }
  iVar15 = 0;
  iVar3 = (*(code *)PTR_sk_num_006a6e2c)(param_3);
  if (0 < iVar3) {
    do {
      iVar3 = (*(code *)PTR_sk_value_006a6e24)(param_3,iVar15);
      iVar4 = name_cmp(*(char **)(iVar3 + 4),"email");
      if (((iVar4 == 0) && (*(int *)(iVar3 + 8) != 0)) &&
         (iVar4 = (*(code *)PTR_strcmp_006a9b18)(*(int *)(iVar3 + 8),&DAT_0063fb8c), iVar4 == 0)) {
        if (param_2 == (X509V3_CTX *)0x0) {
LAB_0058d710:
          pGVar5 = (GENERAL_NAME *)0x0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x7a,0x7d,"v3_alt.c",0x164);
          pcVar17 = (char *)0x0;
LAB_0058d5a0:
          GENERAL_NAME_free(pGVar5);
          (*(code *)PTR_ASN1_STRING_free_006a879c)(pcVar17);
          goto LAB_0058d0a8;
        }
        if (param_2->flags != 1) {
          if (param_2->subject_cert == (X509 *)0x0) {
            if (param_2->subject_req == (X509_REQ *)0x0) goto LAB_0058d710;
            pXVar13 = param_2->subject_req->req_info->subject;
          }
          else {
            pXVar13 = X509_get_subject_name(param_2->subject_cert);
          }
          iVar3 = -1;
          while (iVar3 = X509_NAME_get_index_by_NID(pXVar13,0x30,iVar3), -1 < iVar3) {
            pXVar10 = X509_NAME_get_entry(pXVar13,iVar3);
            pAVar11 = X509_NAME_ENTRY_get_data(pXVar10);
            pcVar17 = (char *)(*(code *)PTR_ASN1_STRING_dup_006a8cbc)(pAVar11);
            if ((pcVar17 == (char *)0x0) ||
               (pGVar5 = GENERAL_NAME_new(), puVar1 = PTR_sk_push_006a6fa8,
               pGVar5 == (GENERAL_NAME *)0x0)) {
              pGVar5 = (GENERAL_NAME *)0x0;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x7a,0x41,"v3_alt.c",0x179);
              goto LAB_0058d5a0;
            }
            (pGVar5->d).ptr = pcVar17;
            pGVar5->type = 1;
            iVar4 = (*(code *)puVar1)(iVar2,pGVar5);
            if (iVar4 == 0) {
              pcVar17 = (char *)0x0;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x7a,0x41,"v3_alt.c",0x180);
              goto LAB_0058d5a0;
            }
          }
        }
        goto LAB_0058d314;
      }
      iVar4 = name_cmp(*(char **)(iVar3 + 4),"email");
      pcVar17 = *(char **)(iVar3 + 8);
      if (iVar4 == 0) {
        if (pcVar17 == (char *)0x0) {
LAB_0058d190:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x75,0x7c,"v3_alt.c",0x213);
          goto LAB_0058d0a8;
        }
        iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar17,&DAT_0066e35c);
        if (iVar4 == 0) {
          if (param_2 == (X509V3_CTX *)0x0) {
LAB_0058d744:
            pGVar5 = (GENERAL_NAME *)0x0;
            (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x7a,0x7d,"v3_alt.c",0x164);
            pcVar17 = (char *)0x0;
LAB_0058d5f0:
            GENERAL_NAME_free(pGVar5);
            (*(code *)PTR_ASN1_STRING_free_006a879c)(pcVar17);
            goto LAB_0058d0a8;
          }
          if (param_2->flags == 1) goto LAB_0058d314;
          if (param_2->subject_cert == (X509 *)0x0) {
            if (param_2->subject_req == (X509_REQ *)0x0) goto LAB_0058d744;
            pXVar13 = param_2->subject_req->req_info->subject;
          }
          else {
            pXVar13 = X509_get_subject_name(param_2->subject_cert);
          }
          iVar3 = -1;
          while (iVar4 = X509_NAME_get_index_by_NID(pXVar13,0x30,iVar3), -1 < iVar4) {
            iVar3 = iVar4 + -1;
            pXVar10 = X509_NAME_get_entry(pXVar13,iVar4);
            pAVar11 = X509_NAME_ENTRY_get_data(pXVar10);
            pcVar17 = (char *)(*(code *)PTR_ASN1_STRING_dup_006a8cbc)(pAVar11);
            X509_NAME_delete_entry(pXVar13,iVar4);
            (*(code *)PTR_X509_NAME_ENTRY_free_006a7150)(pXVar10);
            if ((pcVar17 == (char *)0x0) ||
               (pGVar5 = GENERAL_NAME_new(), puVar1 = PTR_sk_push_006a6fa8,
               pGVar5 == (GENERAL_NAME *)0x0)) {
              pGVar5 = (GENERAL_NAME *)0x0;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x7a,0x41,"v3_alt.c",0x179);
              goto LAB_0058d5f0;
            }
            (pGVar5->d).ptr = pcVar17;
            pGVar5->type = 1;
            iVar4 = (*(code *)puVar1)(iVar2,pGVar5);
            if (iVar4 == 0) {
              pcVar17 = (char *)0x0;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x7a,0x41,"v3_alt.c",0x180);
              goto LAB_0058d5f0;
            }
          }
          goto LAB_0058d314;
        }
        pcVar16 = *(char **)(iVar3 + 4);
      }
      else {
        pcVar16 = *(char **)(iVar3 + 4);
        if (pcVar17 == (char *)0x0) goto LAB_0058d190;
      }
      iVar3 = name_cmp(pcVar16,"email");
      if (iVar3 != 0) {
        iVar3 = name_cmp(pcVar16,"URI");
        if (iVar3 == 0) {
          iVar3 = 6;
LAB_0058d068:
          pGVar5 = GENERAL_NAME_new();
          goto joined_r0x0058d0fc;
        }
        iVar3 = name_cmp(pcVar16,"DNS");
        if (iVar3 == 0) {
          iVar3 = 2;
          goto LAB_0058d068;
        }
        iVar3 = name_cmp(pcVar16,"RID");
        if (iVar3 != 0) {
          iVar3 = name_cmp(pcVar16,"IP");
          if (iVar3 != 0) {
            iVar3 = name_cmp(pcVar16,"dirName");
            if (iVar3 == 0) {
              pGVar5 = GENERAL_NAME_new();
              if (pGVar5 != (GENERAL_NAME *)0x0) {
                pXVar13 = (X509_NAME *)(*(code *)PTR_X509_NAME_new_006a7138)();
                if (pXVar13 == (X509_NAME *)0x0) {
                  dn_sk = (stack_st_CONF_VALUE *)0x0;
                }
                else {
                  dn_sk = X509V3_get_section(param_2,pcVar17);
                  if (dn_sk == (stack_st_CONF_VALUE *)0x0) {
                    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x90,0x96,"v3_alt.c",0x252);
                    (*(code *)PTR_ERR_add_error_data_006a813c)(2,"section=",pcVar17);
                  }
                  else {
                    iVar3 = X509V3_NAME_from_section(pXVar13,dn_sk,0x1001);
                    if (iVar3 != 0) {
                      (pGVar5->d).directoryName = pXVar13;
                      X509V3_section_free(param_2,dn_sk);
                      puVar1 = PTR_sk_push_006a6fa8;
                      pGVar5->type = 4;
                      (*(code *)puVar1)(iVar2,pGVar5);
                      goto LAB_0058d314;
                    }
                  }
                }
                (*(code *)PTR_X509_NAME_free_006a6ff8)(pXVar13);
                X509V3_section_free(param_2,dn_sk);
                (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,0x95,"v3_alt.c",0x1e4);
                goto LAB_0058d174;
              }
              goto LAB_0058d080;
            }
            iVar3 = name_cmp(pcVar16,"otherName");
            if (iVar3 != 0) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x75,0x75,"v3_alt.c",0x226);
              (*(code *)PTR_ERR_add_error_data_006a813c)(2,"name=",pcVar16);
              goto LAB_0058d0a8;
            }
            pGVar5 = GENERAL_NAME_new();
            if (pGVar5 == (GENERAL_NAME *)0x0) goto LAB_0058d080;
            iVar3 = (*(code *)PTR_strchr_006a9a28)(pcVar17,0x3b);
            if (iVar3 == 0) {
LAB_0058d944:
              (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,0x93,"v3_alt.c",0x1eb);
              goto LAB_0058d174;
            }
            pOVar7 = OTHERNAME_new();
            (pGVar5->d).otherName = pOVar7;
            if (pOVar7 == (OTHERNAME *)0x0) goto LAB_0058d944;
            (*(code *)PTR_ASN1_TYPE_free_006a7498)(pOVar7->value);
            pOVar7 = (pGVar5->d).otherName;
            pAVar8 = (ASN1_TYPE *)(*(code *)PTR_ASN1_generate_v3_006a8ffc)(iVar3 + 1,param_2);
            pOVar7->value = pAVar8;
            if (pAVar8 == (ASN1_TYPE *)0x0) goto LAB_0058d944;
            iVar3 = iVar3 - (int)pcVar17;
            iVar4 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar3 + 1,"v3_alt.c",0x23f);
            (*(code *)PTR_strncpy_006a99e0)(iVar4,pcVar17,iVar3);
            *(undefined *)(iVar4 + iVar3) = 0;
            pOVar7 = (pGVar5->d).otherName;
            pAVar9 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_txt2obj_006a7000)(iVar4,0);
            puVar1 = PTR_CRYPTO_free_006a6e88;
            pOVar7->type_id = pAVar9;
            (*(code *)puVar1)(iVar4);
            if (((pGVar5->d).otherName)->type_id == (ASN1_OBJECT *)0x0) goto LAB_0058d944;
            iVar3 = 0;
            goto LAB_0058d2f8;
          }
          pGVar5 = GENERAL_NAME_new();
          if (pGVar5 != (GENERAL_NAME *)0x0) {
            pAVar12 = a2i_IPADDRESS(pcVar17);
            (pGVar5->d).iPAddress = pAVar12;
            puVar1 = PTR_sk_push_006a6fa8;
            if (pAVar12 == (ASN1_OCTET_STRING *)0x0) {
              uVar14 = 0x76;
              uVar6 = 0x1dc;
              goto LAB_0058d7f8;
            }
            pGVar5->type = 7;
            (*(code *)puVar1)(iVar2,pGVar5);
            goto LAB_0058d314;
          }
          goto LAB_0058d080;
        }
        pGVar5 = GENERAL_NAME_new();
        if (pGVar5 == (GENERAL_NAME *)0x0) goto LAB_0058d080;
        pcVar16 = (char *)(*(code *)PTR_OBJ_txt2obj_006a7000)(pcVar17,0);
        puVar1 = PTR_sk_push_006a6fa8;
        if (pcVar16 != (char *)0x0) {
          (pGVar5->d).ptr = pcVar16;
          pGVar5->type = 8;
          (*(code *)puVar1)(iVar2,pGVar5);
          goto LAB_0058d314;
        }
        uVar14 = 0x77;
        uVar6 = 0x1ce;
LAB_0058d7f8:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,uVar14,"v3_alt.c",uVar6);
        (*(code *)PTR_ERR_add_error_data_006a813c)(2,"value=",pcVar17);
LAB_0058d174:
        GENERAL_NAME_free(pGVar5);
LAB_0058d0a8:
        (*(code *)PTR_sk_pop_free_006a7058)(iVar2,PTR_GENERAL_NAME_free_006a73a4);
        return 0;
      }
      iVar3 = 1;
      pGVar5 = GENERAL_NAME_new();
joined_r0x0058d0fc:
      if (pGVar5 == (GENERAL_NAME *)0x0) {
LAB_0058d080:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,0x41,"v3_alt.c",0x1be);
        goto LAB_0058d0a8;
      }
      pcVar16 = (char *)(*(code *)PTR_ASN1_STRING_type_new_006a8680)(0x16);
      (pGVar5->d).ptr = pcVar16;
      if (pcVar16 == (char *)0x0) {
LAB_0058d14c:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,0x41,"v3_alt.c",0x1f8);
        goto LAB_0058d174;
      }
      uVar6 = (*(code *)PTR_strlen_006a9a24)(pcVar17);
      iVar4 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)(pcVar16,pcVar17,uVar6);
      if (iVar4 == 0) goto LAB_0058d14c;
LAB_0058d2f8:
      puVar1 = PTR_sk_push_006a6fa8;
      pGVar5->type = iVar3;
      (*(code *)puVar1)(iVar2,pGVar5);
LAB_0058d314:
      iVar15 = iVar15 + 1;
      iVar3 = (*(code *)PTR_sk_num_006a6e2c)(param_3);
    } while (iVar15 < iVar3);
  }
  return iVar2;
}

