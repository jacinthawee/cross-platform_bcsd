
GENERAL_NAME * v2i_GENERAL_NAME(X509V3_EXT_METHOD *method,X509V3_CTX *ctx,CONF_VALUE *cnf)

{
  undefined *puVar1;
  int iVar2;
  GENERAL_NAME *a;
  undefined4 uVar3;
  int iVar4;
  OTHERNAME *pOVar5;
  ASN1_TYPE *pAVar6;
  ASN1_OBJECT *pAVar7;
  ASN1_OCTET_STRING *pAVar8;
  X509_NAME *nm;
  stack_st_CONF_VALUE *dn_sk;
  undefined4 uVar9;
  char *pcVar10;
  char *section;
  
  section = cnf->value;
  pcVar10 = cnf->name;
  if (section == (char *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x75,0x7c,"v3_alt.c",0x219);
    return (GENERAL_NAME *)0x0;
  }
  iVar2 = name_cmp(pcVar10,"email");
  if (iVar2 == 0) {
    iVar2 = 1;
    a = GENERAL_NAME_new();
  }
  else {
    iVar2 = name_cmp(pcVar10,"URI");
    if (iVar2 == 0) {
      iVar2 = 6;
    }
    else {
      iVar2 = name_cmp(pcVar10,"DNS");
      if (iVar2 != 0) {
        iVar2 = name_cmp(pcVar10,"RID");
        if (iVar2 == 0) {
          a = GENERAL_NAME_new();
          if (a == (GENERAL_NAME *)0x0) goto LAB_0059168c;
          pcVar10 = (char *)(*(code *)PTR_OBJ_txt2obj_006a8100)(section,0);
          if (pcVar10 != (char *)0x0) {
            (a->d).ptr = pcVar10;
            a->type = 8;
            return a;
          }
          uVar9 = 0x77;
          uVar3 = 0x1ce;
        }
        else {
          iVar2 = name_cmp(pcVar10,"IP");
          if (iVar2 != 0) {
            iVar2 = name_cmp(pcVar10,"dirName");
            if (iVar2 != 0) {
              iVar2 = name_cmp(pcVar10,"otherName");
              if (iVar2 != 0) {
                (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x75,0x75,"v3_alt.c",0x22d);
                (*(code *)PTR_ERR_add_error_data_006a9264)(2,"name=",pcVar10);
                return (GENERAL_NAME *)0x0;
              }
              a = GENERAL_NAME_new();
              if (a == (GENERAL_NAME *)0x0) goto LAB_0059168c;
              iVar2 = (*(code *)PTR_strchr_006aab34)(section,0x3b);
              if (iVar2 != 0) {
                pOVar5 = OTHERNAME_new();
                (a->d).otherName = pOVar5;
                if (pOVar5 != (OTHERNAME *)0x0) {
                  (*(code *)PTR_ASN1_TYPE_free_006a8598)(pOVar5->value);
                  pOVar5 = (a->d).otherName;
                  pAVar6 = (ASN1_TYPE *)(*(code *)PTR_ASN1_generate_v3_006aa114)(iVar2 + 1,ctx);
                  pOVar5->value = pAVar6;
                  if (pAVar6 != (ASN1_TYPE *)0x0) {
                    iVar2 = iVar2 - (int)section;
                    iVar4 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2 + 1,"v3_alt.c",0x245);
                    (*(code *)PTR_strncpy_006aaaec)(iVar4,section,iVar2);
                    *(undefined *)(iVar4 + iVar2) = 0;
                    pOVar5 = (a->d).otherName;
                    pAVar7 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_txt2obj_006a8100)(iVar4,0);
                    puVar1 = PTR_CRYPTO_free_006a7f88;
                    pOVar5->type_id = pAVar7;
                    (*(code *)puVar1)(iVar4);
                    if (((a->d).otherName)->type_id != (ASN1_OBJECT *)0x0) {
                      iVar2 = 0;
                      goto LAB_005918a4;
                    }
                  }
                }
              }
              (*(code *)PTR_ERR_put_error_006a9030)(0x22,0xa4,0x93,"v3_alt.c",0x1ee);
              goto LAB_0059175c;
            }
            a = GENERAL_NAME_new();
            if (a != (GENERAL_NAME *)0x0) {
              nm = (X509_NAME *)(*(code *)PTR_X509_NAME_new_006a8238)();
              if (nm != (X509_NAME *)0x0) {
                dn_sk = X509V3_get_section(ctx,section);
                if (dn_sk == (stack_st_CONF_VALUE *)0x0) {
                  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x90,0x96,"v3_alt.c",0x259);
                  (*(code *)PTR_ERR_add_error_data_006a9264)(2,"section=",section);
                  (*(code *)PTR_X509_NAME_free_006a80f8)(nm);
                }
                else {
                  iVar2 = X509V3_NAME_from_section(nm,dn_sk,0x1001);
                  if (iVar2 != 0) {
                    (a->d).directoryName = nm;
                    X509V3_section_free(ctx,dn_sk);
                    a->type = 4;
                    return a;
                  }
                  (*(code *)PTR_X509_NAME_free_006a80f8)(nm);
                  (a->d).directoryName = nm;
                  X509V3_section_free(ctx,dn_sk);
                }
              }
              (*(code *)PTR_ERR_put_error_006a9030)(0x22,0xa4,0x95,"v3_alt.c",0x1e6);
              goto LAB_0059175c;
            }
            goto LAB_0059168c;
          }
          a = GENERAL_NAME_new();
          if (a == (GENERAL_NAME *)0x0) goto LAB_0059168c;
          iVar2 = 7;
          pAVar8 = a2i_IPADDRESS(section);
          (a->d).iPAddress = pAVar8;
          if (pAVar8 != (ASN1_OCTET_STRING *)0x0) goto LAB_005918a4;
          uVar9 = 0x76;
          uVar3 = 0x1dd;
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0x22,0xa4,uVar9,"v3_alt.c",uVar3);
        (*(code *)PTR_ERR_add_error_data_006a9264)(2,"value=",section);
        goto LAB_0059175c;
      }
      iVar2 = 2;
    }
    a = GENERAL_NAME_new();
  }
  if (a == (GENERAL_NAME *)0x0) {
LAB_0059168c:
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0xa4,0x41,"v3_alt.c",0x1bc);
    return (GENERAL_NAME *)0x0;
  }
  pcVar10 = (char *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(0x16);
  (a->d).ptr = pcVar10;
  if (pcVar10 != (char *)0x0) {
    uVar3 = (*(code *)PTR_strlen_006aab30)(section);
    iVar4 = (*(code *)PTR_ASN1_STRING_set_006a8e0c)(pcVar10,section,uVar3);
    if (iVar4 != 0) {
LAB_005918a4:
      a->type = iVar2;
      return a;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0xa4,0x41,"v3_alt.c",0x1fd);
LAB_0059175c:
  GENERAL_NAME_free(a);
  return (GENERAL_NAME *)0x0;
}

