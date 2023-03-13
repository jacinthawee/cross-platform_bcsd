
GENERAL_NAMES *
v2i_GENERAL_NAMES(X509V3_EXT_METHOD *method,X509V3_CTX *ctx,stack_st_CONF_VALUE *nval)

{
  undefined *puVar1;
  GENERAL_NAMES *pGVar2;
  int iVar3;
  GENERAL_NAME *a;
  undefined4 uVar4;
  int iVar5;
  OTHERNAME *pOVar6;
  ASN1_TYPE *pAVar7;
  ASN1_OBJECT *pAVar8;
  ASN1_OCTET_STRING *pAVar9;
  X509_NAME *nm;
  stack_st_CONF_VALUE *dn_sk;
  undefined4 uVar10;
  int iVar11;
  char *section;
  char *pcVar12;
  
  pGVar2 = (GENERAL_NAMES *)(*(code *)PTR_sk_new_null_006a6fa4)();
  if (pGVar2 == (GENERAL_NAMES *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x76,0x41,"v3_alt.c",0x197);
    return (GENERAL_NAMES *)0x0;
  }
  iVar11 = 0;
  iVar3 = (*(code *)PTR_sk_num_006a6e2c)(nval);
  if (0 < iVar3) {
    do {
      iVar3 = (*(code *)PTR_sk_value_006a6e24)(nval,iVar11);
      section = *(char **)(iVar3 + 8);
      pcVar12 = *(char **)(iVar3 + 4);
      if (section == (char *)0x0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x75,0x7c,"v3_alt.c",0x213);
        goto LAB_0058e288;
      }
      iVar3 = name_cmp(pcVar12,"email");
      if (iVar3 != 0) {
        iVar3 = name_cmp(pcVar12,"URI");
        if (iVar3 == 0) {
          iVar3 = 6;
LAB_0058e248:
          a = GENERAL_NAME_new();
          goto joined_r0x0058e2dc;
        }
        iVar3 = name_cmp(pcVar12,"DNS");
        if (iVar3 == 0) {
          iVar3 = 2;
          goto LAB_0058e248;
        }
        iVar3 = name_cmp(pcVar12,"RID");
        if (iVar3 != 0) {
          iVar3 = name_cmp(pcVar12,"IP");
          if (iVar3 != 0) {
            iVar3 = name_cmp(pcVar12,"dirName");
            if (iVar3 == 0) {
              a = GENERAL_NAME_new();
              if (a != (GENERAL_NAME *)0x0) {
                nm = (X509_NAME *)(*(code *)PTR_X509_NAME_new_006a7138)();
                if (nm == (X509_NAME *)0x0) {
                  dn_sk = (stack_st_CONF_VALUE *)0x0;
                }
                else {
                  dn_sk = X509V3_get_section(ctx,section);
                  if (dn_sk == (stack_st_CONF_VALUE *)0x0) {
                    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x90,0x96,"v3_alt.c",0x252);
                    (*(code *)PTR_ERR_add_error_data_006a813c)(2,"section=",section);
                  }
                  else {
                    iVar3 = X509V3_NAME_from_section(nm,dn_sk,0x1001);
                    if (iVar3 != 0) {
                      (a->d).directoryName = nm;
                      X509V3_section_free(ctx,dn_sk);
                      puVar1 = PTR_sk_push_006a6fa8;
                      a->type = 4;
                      (*(code *)puVar1)(pGVar2,a);
                      goto LAB_0058e49c;
                    }
                  }
                }
                (*(code *)PTR_X509_NAME_free_006a6ff8)(nm);
                X509V3_section_free(ctx,dn_sk);
                (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,0x95,"v3_alt.c",0x1e4);
                goto LAB_0058e354;
              }
              goto LAB_0058e260;
            }
            iVar3 = name_cmp(pcVar12,"otherName");
            if (iVar3 != 0) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x75,0x75,"v3_alt.c",0x226);
              (*(code *)PTR_ERR_add_error_data_006a813c)(2,"name=",pcVar12);
              goto LAB_0058e288;
            }
            a = GENERAL_NAME_new();
            if (a == (GENERAL_NAME *)0x0) goto LAB_0058e260;
            iVar3 = (*(code *)PTR_strchr_006a9a28)(section,0x3b);
            if (iVar3 == 0) {
LAB_0058e7ec:
              (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,0x93,"v3_alt.c",0x1eb);
              goto LAB_0058e354;
            }
            pOVar6 = OTHERNAME_new();
            (a->d).otherName = pOVar6;
            if (pOVar6 == (OTHERNAME *)0x0) goto LAB_0058e7ec;
            (*(code *)PTR_ASN1_TYPE_free_006a7498)(pOVar6->value);
            pOVar6 = (a->d).otherName;
            pAVar7 = (ASN1_TYPE *)(*(code *)PTR_ASN1_generate_v3_006a8ffc)(iVar3 + 1,ctx);
            pOVar6->value = pAVar7;
            if (pAVar7 == (ASN1_TYPE *)0x0) goto LAB_0058e7ec;
            iVar3 = iVar3 - (int)section;
            iVar5 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar3 + 1,"v3_alt.c",0x23f);
            (*(code *)PTR_strncpy_006a99e0)(iVar5,section,iVar3);
            *(undefined *)(iVar5 + iVar3) = 0;
            pOVar6 = (a->d).otherName;
            pAVar8 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_txt2obj_006a7000)(iVar5,0);
            puVar1 = PTR_CRYPTO_free_006a6e88;
            pOVar6->type_id = pAVar8;
            (*(code *)puVar1)(iVar5);
            if (((a->d).otherName)->type_id == (ASN1_OBJECT *)0x0) goto LAB_0058e7ec;
            iVar3 = 0;
            goto LAB_0058e480;
          }
          a = GENERAL_NAME_new();
          if (a != (GENERAL_NAME *)0x0) {
            pAVar9 = a2i_IPADDRESS(section);
            (a->d).iPAddress = pAVar9;
            puVar1 = PTR_sk_push_006a6fa8;
            if (pAVar9 == (ASN1_OCTET_STRING *)0x0) {
              uVar10 = 0x76;
              uVar4 = 0x1dc;
              goto LAB_0058e62c;
            }
            a->type = 7;
            (*(code *)puVar1)(pGVar2,a);
            goto LAB_0058e49c;
          }
          goto LAB_0058e260;
        }
        a = GENERAL_NAME_new();
        if (a == (GENERAL_NAME *)0x0) goto LAB_0058e260;
        pcVar12 = (char *)(*(code *)PTR_OBJ_txt2obj_006a7000)(section,0);
        puVar1 = PTR_sk_push_006a6fa8;
        if (pcVar12 != (char *)0x0) {
          (a->d).ptr = pcVar12;
          a->type = 8;
          (*(code *)puVar1)(pGVar2,a);
          goto LAB_0058e49c;
        }
        uVar10 = 0x77;
        uVar4 = 0x1ce;
LAB_0058e62c:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,uVar10,"v3_alt.c",uVar4);
        (*(code *)PTR_ERR_add_error_data_006a813c)(2,"value=",section);
LAB_0058e354:
        GENERAL_NAME_free(a);
LAB_0058e288:
        (*(code *)PTR_sk_pop_free_006a7058)(pGVar2,PTR_GENERAL_NAME_free_006a73a4);
        return (GENERAL_NAMES *)0x0;
      }
      iVar3 = 1;
      a = GENERAL_NAME_new();
joined_r0x0058e2dc:
      if (a == (GENERAL_NAME *)0x0) {
LAB_0058e260:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,0x41,"v3_alt.c",0x1be);
        goto LAB_0058e288;
      }
      pcVar12 = (char *)(*(code *)PTR_ASN1_STRING_type_new_006a8680)(0x16);
      (a->d).ptr = pcVar12;
      if (pcVar12 == (char *)0x0) {
LAB_0058e32c:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,0x41,"v3_alt.c",0x1f8);
        goto LAB_0058e354;
      }
      uVar4 = (*(code *)PTR_strlen_006a9a24)(section);
      iVar5 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)(pcVar12,section,uVar4);
      if (iVar5 == 0) goto LAB_0058e32c;
LAB_0058e480:
      puVar1 = PTR_sk_push_006a6fa8;
      a->type = iVar3;
      (*(code *)puVar1)(pGVar2,a);
LAB_0058e49c:
      iVar11 = iVar11 + 1;
      iVar3 = (*(code *)PTR_sk_num_006a6e2c)(nval);
    } while (iVar11 < iVar3);
  }
  return pGVar2;
}

