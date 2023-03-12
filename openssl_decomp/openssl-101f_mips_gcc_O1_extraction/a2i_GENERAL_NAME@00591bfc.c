
GENERAL_NAME *
a2i_GENERAL_NAME(GENERAL_NAME *out,X509V3_EXT_METHOD *method,X509V3_CTX *ctx,int gen_type,
                char *value,int is_nc)

{
  undefined *puVar1;
  int iVar2;
  X509_NAME *nm;
  stack_st_CONF_VALUE *dn_sk;
  OTHERNAME *pOVar3;
  ASN1_TYPE *pAVar4;
  int iVar5;
  ASN1_OBJECT *pAVar6;
  ASN1_OCTET_STRING *pAVar7;
  char *pcVar8;
  undefined4 uVar9;
  GENERAL_NAME *a;
  undefined4 uVar10;
  
  if (value == (char *)0x0) {
    uVar10 = 0x7c;
    uVar9 = 0x1b1;
LAB_00591f84:
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0xa4,uVar10,"v3_alt.c",uVar9);
    return (GENERAL_NAME *)0x0;
  }
  a = out;
  if ((out == (GENERAL_NAME *)0x0) && (a = GENERAL_NAME_new(), a == (GENERAL_NAME *)0x0)) {
    uVar10 = 0x41;
    uVar9 = 0x1bc;
    goto LAB_00591f84;
  }
  switch(gen_type) {
  case 0:
    iVar2 = (*(code *)PTR_strchr_006aab34)(value,0x3b);
    if (iVar2 != 0) {
      pOVar3 = OTHERNAME_new();
      (a->d).otherName = pOVar3;
      if (pOVar3 != (OTHERNAME *)0x0) {
        (*(code *)PTR_ASN1_TYPE_free_006a8598)(pOVar3->value);
        pOVar3 = (a->d).otherName;
        pAVar4 = (ASN1_TYPE *)(*(code *)PTR_ASN1_generate_v3_006aa114)(iVar2 + 1,ctx);
        pOVar3->value = pAVar4;
        if (pAVar4 != (ASN1_TYPE *)0x0) {
          iVar2 = iVar2 - (int)value;
          iVar5 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2 + 1,"v3_alt.c",0x245);
          (*(code *)PTR_strncpy_006aaaec)(iVar5,value,iVar2);
          *(undefined *)(iVar5 + iVar2) = 0;
          pOVar3 = (a->d).otherName;
          pAVar6 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_txt2obj_006a8100)(iVar5,0);
          puVar1 = PTR_CRYPTO_free_006a7f88;
          pOVar3->type_id = pAVar6;
          (*(code *)puVar1)(iVar5);
          if (((a->d).otherName)->type_id != (ASN1_OBJECT *)0x0) goto LAB_00591d60;
        }
      }
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0xa4,0x93,"v3_alt.c",0x1ee);
    goto LAB_00591cdc;
  case 1:
  case 2:
  case 6:
    pcVar8 = (char *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(0x16);
    (a->d).ptr = pcVar8;
    if (pcVar8 != (char *)0x0) {
      uVar9 = (*(code *)PTR_strlen_006aab30)(value);
      iVar2 = (*(code *)PTR_ASN1_STRING_set_006a8e0c)(pcVar8,value,uVar9);
      if (iVar2 != 0) goto LAB_00591d60;
    }
    uVar10 = 0x41;
    uVar9 = 0x1fd;
    break;
  default:
    uVar10 = 0xa7;
    uVar9 = 499;
    break;
  case 4:
    nm = (X509_NAME *)(*(code *)PTR_X509_NAME_new_006a8238)();
    if (nm != (X509_NAME *)0x0) {
      dn_sk = X509V3_get_section(ctx,value);
      if (dn_sk == (stack_st_CONF_VALUE *)0x0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x90,0x96,"v3_alt.c",0x259);
        (*(code *)PTR_ERR_add_error_data_006a9264)(2,"section=",value);
        (*(code *)PTR_X509_NAME_free_006a80f8)(nm);
      }
      else {
        iVar2 = X509V3_NAME_from_section(nm,dn_sk,0x1001);
        if (iVar2 != 0) {
          (a->d).directoryName = nm;
          X509V3_section_free(ctx,dn_sk);
          goto LAB_00591d60;
        }
        (*(code *)PTR_X509_NAME_free_006a80f8)(nm);
        (a->d).directoryName = nm;
        X509V3_section_free(ctx,dn_sk);
      }
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0xa4,0x95,"v3_alt.c",0x1e6);
    goto LAB_00591cdc;
  case 7:
    if (is_nc == 0) {
      pAVar7 = a2i_IPADDRESS(value);
      (a->d).iPAddress = pAVar7;
    }
    else {
      pAVar7 = a2i_IPADDRESS_NC(value);
      (a->d).iPAddress = pAVar7;
    }
    if (pAVar7 != (ASN1_OCTET_STRING *)0x0) {
LAB_00591d60:
      a->type = gen_type;
      return a;
    }
    uVar10 = 0x76;
    uVar9 = 0x1dd;
    goto LAB_00591ed0;
  case 8:
    pcVar8 = (char *)(*(code *)PTR_OBJ_txt2obj_006a8100)(value,0);
    if (pcVar8 != (char *)0x0) {
      (a->d).ptr = pcVar8;
      goto LAB_00591d60;
    }
    uVar10 = 0x77;
    uVar9 = 0x1ce;
LAB_00591ed0:
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0xa4,uVar10,"v3_alt.c",uVar9);
    (*(code *)PTR_ERR_add_error_data_006a9264)(2,"value=",value);
    goto LAB_00591cdc;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0xa4,uVar10,"v3_alt.c",uVar9);
LAB_00591cdc:
  if (out == (GENERAL_NAME *)0x0) {
    GENERAL_NAME_free(a);
  }
  return (GENERAL_NAME *)0x0;
}

