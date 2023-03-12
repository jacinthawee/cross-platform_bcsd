
GENERAL_NAME *
v2i_GENERAL_NAME_ex(GENERAL_NAME *out,X509V3_EXT_METHOD *method,X509V3_CTX *ctx,CONF_VALUE *cnf,
                   int is_nc)

{
  undefined *puVar1;
  int iVar2;
  GENERAL_NAME *pGVar3;
  X509_NAME *nm;
  stack_st_CONF_VALUE *dn_sk;
  undefined4 uVar4;
  ASN1_OCTET_STRING *pAVar5;
  OTHERNAME *pOVar6;
  ASN1_TYPE *pAVar7;
  int iVar8;
  ASN1_OBJECT *pAVar9;
  undefined4 uVar10;
  char *pcVar11;
  uint uVar12;
  char *ipasc;
  
  ipasc = cnf->value;
  pcVar11 = cnf->name;
  if (ipasc == (char *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x75,0x7c,"v3_alt.c",0x219);
    return (GENERAL_NAME *)0x0;
  }
  iVar2 = name_cmp(pcVar11,"email");
  pGVar3 = out;
  if (iVar2 == 0) {
    uVar12 = 1;
joined_r0x005921c4:
    if (out != (GENERAL_NAME *)0x0) goto LAB_005921d4;
    pGVar3 = GENERAL_NAME_new();
    if (pGVar3 == (GENERAL_NAME *)0x0) {
LAB_00592360:
      (*(code *)PTR_ERR_put_error_006a9030)(0x22,0xa4,0x41,"v3_alt.c",0x1bc);
      return (GENERAL_NAME *)0x0;
    }
    if (uVar12 == 4) goto LAB_00592130;
    if (uVar12 < 5) {
      if (1 < uVar12 - 1) {
LAB_00592284:
        (*(code *)PTR_ERR_put_error_006a9030)(0x22,0xa4,0xa7,"v3_alt.c",499);
        goto LAB_005922a8;
      }
    }
    else if (uVar12 != 6) goto LAB_00592284;
LAB_005921d4:
    pcVar11 = (char *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(0x16);
    (pGVar3->d).ptr = pcVar11;
    if (pcVar11 != (char *)0x0) {
      uVar4 = (*(code *)PTR_strlen_006aab30)(ipasc);
      iVar2 = (*(code *)PTR_ASN1_STRING_set_006a8e0c)(pcVar11,ipasc,uVar4);
      if (iVar2 != 0) {
LAB_00592198:
        pGVar3->type = uVar12;
        return pGVar3;
      }
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0xa4,0x41,"v3_alt.c",0x1fd);
  }
  else {
    iVar2 = name_cmp(pcVar11,"URI");
    if (iVar2 == 0) {
      uVar12 = 6;
      goto joined_r0x005921c4;
    }
    iVar2 = name_cmp(pcVar11,"DNS");
    if (iVar2 == 0) {
      uVar12 = 2;
      goto joined_r0x005921c4;
    }
    iVar2 = name_cmp(pcVar11,"RID");
    if (iVar2 == 0) {
      if ((out == (GENERAL_NAME *)0x0) &&
         (pGVar3 = GENERAL_NAME_new(), pGVar3 == (GENERAL_NAME *)0x0)) goto LAB_00592360;
      pcVar11 = (char *)(*(code *)PTR_OBJ_txt2obj_006a8100)(ipasc,0);
      if (pcVar11 != (char *)0x0) {
        (pGVar3->d).ptr = pcVar11;
        uVar12 = 8;
        goto LAB_00592198;
      }
      uVar10 = 0x77;
      uVar4 = 0x1ce;
LAB_005924e4:
      (*(code *)PTR_ERR_put_error_006a9030)(0x22,0xa4,uVar10,"v3_alt.c",uVar4);
      (*(code *)PTR_ERR_add_error_data_006a9264)(2,"value=",ipasc);
    }
    else {
      iVar2 = name_cmp(pcVar11,"IP");
      if (iVar2 == 0) {
        if ((out == (GENERAL_NAME *)0x0) &&
           (pGVar3 = GENERAL_NAME_new(), pGVar3 == (GENERAL_NAME *)0x0)) goto LAB_00592360;
        if (is_nc == 0) {
          pAVar5 = a2i_IPADDRESS(ipasc);
          (pGVar3->d).iPAddress = pAVar5;
        }
        else {
          pAVar5 = a2i_IPADDRESS_NC(ipasc);
          (pGVar3->d).iPAddress = pAVar5;
        }
        uVar12 = 7;
        if (pAVar5 != (ASN1_OCTET_STRING *)0x0) goto LAB_00592198;
        uVar10 = 0x76;
        uVar4 = 0x1dd;
        goto LAB_005924e4;
      }
      iVar2 = name_cmp(pcVar11,"dirName");
      if (iVar2 != 0) {
        iVar2 = name_cmp(pcVar11,"otherName");
        if (iVar2 != 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x75,0x75,"v3_alt.c",0x22d);
          (*(code *)PTR_ERR_add_error_data_006a9264)(2,"name=",pcVar11);
          return (GENERAL_NAME *)0x0;
        }
        if ((out == (GENERAL_NAME *)0x0) &&
           (pGVar3 = GENERAL_NAME_new(), pGVar3 == (GENERAL_NAME *)0x0)) goto LAB_00592360;
        iVar2 = (*(code *)PTR_strchr_006aab34)(ipasc,0x3b);
        if (iVar2 != 0) {
          pOVar6 = OTHERNAME_new();
          (pGVar3->d).otherName = pOVar6;
          if (pOVar6 != (OTHERNAME *)0x0) {
            (*(code *)PTR_ASN1_TYPE_free_006a8598)(pOVar6->value);
            pOVar6 = (pGVar3->d).otherName;
            pAVar7 = (ASN1_TYPE *)(*(code *)PTR_ASN1_generate_v3_006aa114)(iVar2 + 1,ctx);
            pOVar6->value = pAVar7;
            if (pAVar7 != (ASN1_TYPE *)0x0) {
              iVar2 = iVar2 - (int)ipasc;
              iVar8 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2 + 1,"v3_alt.c",0x245);
              (*(code *)PTR_strncpy_006aaaec)(iVar8,ipasc,iVar2);
              *(undefined *)(iVar8 + iVar2) = 0;
              pOVar6 = (pGVar3->d).otherName;
              pAVar9 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_txt2obj_006a8100)(iVar8,0);
              puVar1 = PTR_CRYPTO_free_006a7f88;
              pOVar6->type_id = pAVar9;
              (*(code *)puVar1)(iVar8);
              if (((pGVar3->d).otherName)->type_id != (ASN1_OBJECT *)0x0) {
                uVar12 = 0;
                goto LAB_00592198;
              }
            }
          }
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0x22,0xa4,0x93,"v3_alt.c",0x1ee);
        goto LAB_00592240;
      }
      if ((out == (GENERAL_NAME *)0x0) &&
         (pGVar3 = GENERAL_NAME_new(), pGVar3 == (GENERAL_NAME *)0x0)) goto LAB_00592360;
LAB_00592130:
      nm = (X509_NAME *)(*(code *)PTR_X509_NAME_new_006a8238)();
      if (nm != (X509_NAME *)0x0) {
        dn_sk = X509V3_get_section(ctx,ipasc);
        if (dn_sk == (stack_st_CONF_VALUE *)0x0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x90,0x96,"v3_alt.c",0x259);
          (*(code *)PTR_ERR_add_error_data_006a9264)(2,"section=",ipasc);
          (*(code *)PTR_X509_NAME_free_006a80f8)(nm);
        }
        else {
          iVar2 = X509V3_NAME_from_section(nm,dn_sk,0x1001);
          if (iVar2 != 0) {
            (pGVar3->d).directoryName = nm;
            uVar12 = 4;
            X509V3_section_free(ctx,dn_sk);
            goto LAB_00592198;
          }
          (*(code *)PTR_X509_NAME_free_006a80f8)(nm);
          (pGVar3->d).directoryName = nm;
          X509V3_section_free(ctx,dn_sk);
        }
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x22,0xa4,0x95,"v3_alt.c",0x1e6);
    }
  }
LAB_00592240:
  if (out != (GENERAL_NAME *)0x0) {
    return (GENERAL_NAME *)0x0;
  }
LAB_005922a8:
  GENERAL_NAME_free(pGVar3);
  return (GENERAL_NAME *)0x0;
}

