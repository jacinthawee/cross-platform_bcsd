
PROXY_CERT_INFO_EXTENSION * r2i_pci(undefined4 param_1,X509V3_CTX *param_2,ASN1_INTEGER **param_3)

{
  undefined *puVar1;
  stack_st_CONF_VALUE *psVar2;
  int iVar3;
  char **ppcVar4;
  uint uVar5;
  PROXY_CERT_INFO_EXTENSION *pPVar6;
  PROXY_POLICY *pPVar7;
  stack_st_CONF_VALUE *section;
  int iVar8;
  undefined4 uVar9;
  char *pcVar10;
  int *piVar11;
  undefined4 uVar12;
  int iVar13;
  ASN1_OBJECT *local_38;
  ASN1_INTEGER *local_34;
  ASN1_OCTET_STRING *local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar13 = 0;
  local_38 = (ASN1_OBJECT *)0x0;
  local_34 = (ASN1_INTEGER *)0x0;
  local_30 = (ASN1_OCTET_STRING *)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  psVar2 = X509V3_parse_list((char *)param_3);
  iVar3 = (*(code *)PTR_sk_num_006a6e2c)(psVar2);
  if (0 < iVar3) {
    do {
      ppcVar4 = (char **)(*(code *)PTR_sk_value_006a6e24)(psVar2,iVar13);
      pcVar10 = ppcVar4[1];
      if (pcVar10 == (char *)0x0) {
LAB_005985d4:
        uVar12 = 0x99;
        uVar9 = 0xf1;
LAB_005985e8:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x9b,uVar12,"v3_pci.c",uVar9);
        param_3 = (ASN1_INTEGER **)*ppcVar4;
        pcVar10 = ",name:";
        (*(code *)PTR_ERR_add_error_data_006a813c)
                  (6,"section:",param_3,",name:",ppcVar4[1],",value:",ppcVar4[2]);
        goto LAB_0059850c;
      }
      if (*pcVar10 == '@') {
        section = X509V3_get_section(param_2,pcVar10 + 1);
        if (section == (stack_st_CONF_VALUE *)0x0) {
          uVar12 = 0x87;
          uVar9 = 0xfb;
          goto LAB_005985e8;
        }
        iVar3 = 0;
        while (iVar8 = (*(code *)PTR_sk_num_006a6e2c)(section), iVar3 < iVar8) {
          uVar9 = (*(code *)PTR_sk_value_006a6e24)(section,iVar3);
          param_3 = &local_34;
          pcVar10 = (char *)&local_30;
          iVar8 = process_pci_value(uVar9,&local_38,&local_34,&local_30);
          iVar3 = iVar3 + 1;
          if (iVar8 == 0) {
            X509V3_section_free(param_2,section);
            goto LAB_0059850c;
          }
        }
        X509V3_section_free(param_2,section);
      }
      else {
        if (ppcVar4[2] == (char *)0x0) goto LAB_005985d4;
        param_3 = &local_34;
        iVar3 = process_pci_value(ppcVar4,&local_38,&local_34,&local_30);
        if (iVar3 == 0) {
          param_3 = (ASN1_INTEGER **)*ppcVar4;
          pcVar10 = ",name:";
          (*(code *)PTR_ERR_add_error_data_006a813c)
                    (6,"section:",param_3,",name:",ppcVar4[1],",value:",ppcVar4[2]);
          goto LAB_0059850c;
        }
      }
      iVar13 = iVar13 + 1;
      iVar3 = (*(code *)PTR_sk_num_006a6e2c)(psVar2);
    } while (iVar13 < iVar3);
  }
  pcVar10 = "encrypt";
  if (local_38 == (ASN1_OBJECT *)0x0) {
    param_3 = (ASN1_INTEGER **)0x9a;
    uVar9 = 0x112;
  }
  else {
    uVar5 = (*(code *)PTR_OBJ_obj2nid_006a712c)();
    if (((uVar5 & 0xfffffffd) == 0x299) &&
       (pcVar10 = "encrypt", local_30 != (ASN1_OCTET_STRING *)0x0)) {
      param_3 = (ASN1_INTEGER **)0x9f;
      uVar9 = 0x118;
    }
    else {
      pPVar6 = PROXY_CERT_INFO_EXTENSION_new();
      if (pPVar6 != (PROXY_CERT_INFO_EXTENSION *)0x0) {
        pPVar7 = pPVar6->proxyPolicy;
        pPVar7->policyLanguage = local_38;
        pPVar7->policy = local_30;
        local_38 = (ASN1_OBJECT *)0x0;
        local_30 = (ASN1_OCTET_STRING *)0x0;
        pPVar6->pcPathLengthConstraint = local_34;
        local_34 = (ASN1_INTEGER *)0x0;
        goto LAB_00598560;
      }
      param_3 = (ASN1_INTEGER **)&DAT_00000041;
      uVar9 = 0x11e;
    }
  }
  pcVar10 = "v3_pci.c";
  (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x9b,param_3,"v3_pci.c",uVar9);
LAB_0059850c:
  if (local_38 != (ASN1_OBJECT *)0x0) {
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)();
    local_38 = (ASN1_OBJECT *)0x0;
  }
  if (local_34 != (ASN1_INTEGER *)0x0) {
    (*(code *)PTR_ASN1_INTEGER_free_006a6e94)();
    local_34 = (ASN1_INTEGER *)0x0;
  }
  if (local_30 == (ASN1_OCTET_STRING *)0x0) {
    pPVar6 = (PROXY_CERT_INFO_EXTENSION *)0x0;
  }
  else {
    pPVar6 = (PROXY_CERT_INFO_EXTENSION *)0x0;
    (*(code *)PTR_ASN1_OCTET_STRING_free_006a8cfc)();
    local_30 = (ASN1_OCTET_STRING *)0x0;
  }
LAB_00598560:
  piVar11 = (int *)PTR_X509V3_conf_free_006a7b4c;
  (*(code *)PTR_sk_pop_free_006a7058)(psVar2);
  if (local_2c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    (*(code *)PTR_BIO_printf_006a6e38)(param_3,"%*sPath Length Constraint: ",pcVar10,"");
    if (*piVar11 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(param_3,"infinite");
    }
    else {
      (*(code *)PTR_i2a_ASN1_INTEGER_006a75f0)(param_3);
    }
    (*(code *)PTR_BIO_puts_006a6f58)(param_3,"\n");
    (*(code *)PTR_BIO_printf_006a6e38)(param_3,"%*sPolicy Language: ",pcVar10,"");
    (*(code *)PTR_i2a_ASN1_OBJECT_006a702c)(param_3,*(undefined4 *)piVar11[1]);
    (*(code *)PTR_BIO_puts_006a6f58)(param_3,"\n");
    if ((*(int *)(piVar11[1] + 4) != 0) &&
       (iVar3 = *(int *)(*(int *)(piVar11[1] + 4) + 8), iVar3 != 0)) {
      (*(code *)PTR_BIO_printf_006a6e38)(param_3,"%*sPolicy Text: %s\n",pcVar10,"",iVar3);
    }
    return (PROXY_CERT_INFO_EXTENSION *)0x1;
  }
  return pPVar6;
}

