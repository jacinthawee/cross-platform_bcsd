
GENERAL_NAME *
a2i_GENERAL_NAME(GENERAL_NAME *out,X509V3_EXT_METHOD *method,X509V3_CTX *ctx,int gen_type,
                char *value,int is_nc)

{
  undefined *puVar1;
  int iVar2;
  char *pcVar3;
  OTHERNAME *pOVar4;
  ASN1_TYPE *pAVar5;
  int iVar6;
  ASN1_OBJECT *pAVar7;
  X509_NAME *nm;
  stack_st_CONF_VALUE *dn_sk;
  ASN1_OCTET_STRING *pAVar8;
  undefined4 uVar9;
  GENERAL_NAME *a;
  undefined4 uVar10;
  
  if (value == (char *)0x0) {
    uVar10 = 0x7c;
    uVar9 = 0x1b5;
LAB_0058f260:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,uVar10,"v3_alt.c",uVar9);
    return (GENERAL_NAME *)0x0;
  }
  a = out;
  if ((out == (GENERAL_NAME *)0x0) && (a = GENERAL_NAME_new(), a == (GENERAL_NAME *)0x0)) {
    uVar10 = 0x41;
    uVar9 = 0x1be;
    goto LAB_0058f260;
  }
  switch(gen_type) {
  case 0:
    iVar2 = (*(code *)PTR_strchr_006a9a28)(value,0x3b);
    if (iVar2 != 0) {
      pOVar4 = OTHERNAME_new();
      (a->d).otherName = pOVar4;
      if (pOVar4 != (OTHERNAME *)0x0) {
        (*(code *)PTR_ASN1_TYPE_free_006a7498)(pOVar4->value);
        pOVar4 = (a->d).otherName;
        pAVar5 = (ASN1_TYPE *)(*(code *)PTR_ASN1_generate_v3_006a8ffc)(iVar2 + 1,ctx);
        pOVar4->value = pAVar5;
        if (pAVar5 != (ASN1_TYPE *)0x0) {
          iVar2 = iVar2 - (int)value;
          iVar6 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2 + 1,"v3_alt.c",0x23f);
          (*(code *)PTR_strncpy_006a99e0)(iVar6,value,iVar2);
          *(undefined *)(iVar6 + iVar2) = 0;
          pOVar4 = (a->d).otherName;
          pAVar7 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_txt2obj_006a7000)(iVar6,0);
          puVar1 = PTR_CRYPTO_free_006a6e88;
          pOVar4->type_id = pAVar7;
          (*(code *)puVar1)(iVar6);
          if (((a->d).otherName)->type_id != (ASN1_OBJECT *)0x0) goto LAB_0058ef9c;
        }
      }
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,0x93,"v3_alt.c",0x1eb);
    goto LAB_0058ef60;
  case 1:
  case 2:
  case 6:
    pcVar3 = (char *)(*(code *)PTR_ASN1_STRING_type_new_006a8680)(0x16);
    (a->d).ptr = pcVar3;
    if (pcVar3 != (char *)0x0) {
      uVar9 = (*(code *)PTR_strlen_006a9a24)(value);
      iVar2 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)(pcVar3,value,uVar9);
      if (iVar2 != 0) goto LAB_0058ef9c;
    }
    uVar10 = 0x41;
    uVar9 = 0x1f8;
    break;
  default:
    uVar10 = 0xa7;
    uVar9 = 0x1f0;
    break;
  case 4:
    nm = (X509_NAME *)(*(code *)PTR_X509_NAME_new_006a7138)();
    if (nm == (X509_NAME *)0x0) {
      dn_sk = (stack_st_CONF_VALUE *)0x0;
    }
    else {
      dn_sk = X509V3_get_section(ctx,value);
      if (dn_sk == (stack_st_CONF_VALUE *)0x0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x90,0x96,"v3_alt.c",0x252);
        (*(code *)PTR_ERR_add_error_data_006a813c)(2,"section=",value);
      }
      else {
        iVar2 = X509V3_NAME_from_section(nm,dn_sk,0x1001);
        if (iVar2 != 0) {
          (a->d).directoryName = nm;
          X509V3_section_free(ctx,dn_sk);
          a->type = gen_type;
          return a;
        }
      }
    }
    (*(code *)PTR_X509_NAME_free_006a6ff8)(nm);
    X509V3_section_free(ctx,dn_sk);
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,0x95,"v3_alt.c",0x1e4);
    goto LAB_0058ef60;
  case 7:
    if (is_nc == 0) {
      pAVar8 = a2i_IPADDRESS(value);
      (a->d).iPAddress = pAVar8;
    }
    else {
      pAVar8 = a2i_IPADDRESS_NC(value);
      (a->d).iPAddress = pAVar8;
    }
    if (pAVar8 != (ASN1_OCTET_STRING *)0x0) {
LAB_0058ef9c:
      a->type = gen_type;
      return a;
    }
    uVar10 = 0x76;
    uVar9 = 0x1dc;
    goto LAB_0058f1b0;
  case 8:
    pcVar3 = (char *)(*(code *)PTR_OBJ_txt2obj_006a7000)(value,0);
    if (pcVar3 != (char *)0x0) {
      (a->d).ptr = pcVar3;
      goto LAB_0058ef9c;
    }
    uVar10 = 0x77;
    uVar9 = 0x1ce;
LAB_0058f1b0:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,uVar10,"v3_alt.c",uVar9);
    (*(code *)PTR_ERR_add_error_data_006a813c)(2,"value=",value);
    goto LAB_0058ef60;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0xa4,uVar10,"v3_alt.c",uVar9);
LAB_0058ef60:
  if (out == (GENERAL_NAME *)0x0) {
    GENERAL_NAME_free(a);
  }
  return (GENERAL_NAME *)0x0;
}

