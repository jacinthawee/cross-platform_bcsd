
PROXY_CERT_INFO_EXTENSION * r2i_pci(undefined4 param_1,X509V3_CTX *param_2,char *param_3)

{
  _STACK *st;
  int iVar1;
  undefined4 *puVar2;
  _STACK *section;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  PROXY_POLICY *pPVar9;
  PROXY_CERT_INFO_EXTENSION *pPVar10;
  undefined4 uVar11;
  int iVar12;
  ASN1_OBJECT *local_24;
  ASN1_INTEGER *local_20;
  ASN1_OCTET_STRING *local_1c;
  
  local_24 = (ASN1_OBJECT *)0x0;
  local_20 = (ASN1_INTEGER *)0x0;
  local_1c = (ASN1_OCTET_STRING *)0x0;
  st = (_STACK *)X509V3_parse_list(param_3);
  for (iVar12 = 0; iVar1 = sk_num(st), iVar12 < iVar1; iVar12 = iVar12 + 1) {
    puVar2 = (undefined4 *)sk_value(st,iVar12);
    pcVar6 = (char *)puVar2[1];
    if (pcVar6 == (char *)0x0) {
LAB_000d874c:
      iVar1 = 0x103;
      iVar12 = 0x99;
LAB_000d8760:
      ERR_put_error(0x22,0x9b,iVar12,"v3_pci.c",iVar1);
      uVar7 = puVar2[1];
      uVar8 = *puVar2;
      uVar11 = puVar2[2];
LAB_000d877e:
      ERR_add_error_data(6,"section:",uVar8,",name:",uVar7,",value:",uVar11);
      goto LAB_000d8706;
    }
    if (*pcVar6 != '@') {
      if (puVar2[2] == 0) goto LAB_000d874c;
      iVar1 = process_pci_value(puVar2,&local_24,&local_20,&local_1c);
      if (iVar1 != 0) goto LAB_000d86a6;
      uVar7 = puVar2[1];
      uVar8 = *puVar2;
      uVar11 = puVar2[2];
      goto LAB_000d877e;
    }
    section = (_STACK *)X509V3_get_section(param_2,pcVar6 + 1);
    if (section == (_STACK *)0x0) {
      iVar1 = 0x10f;
      iVar12 = 0x87;
      goto LAB_000d8760;
    }
    iVar1 = 0;
    while( true ) {
      iVar3 = sk_num(section);
      if (iVar3 <= iVar1) break;
      pvVar4 = sk_value(section,iVar1);
      iVar3 = process_pci_value(pvVar4,&local_24,&local_20,&local_1c);
      iVar1 = iVar1 + 1;
      if (iVar3 == 0) {
        X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section);
        goto LAB_000d8706;
      }
    }
    X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section);
LAB_000d86a6:
  }
  if (local_24 == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0x22,0x9b,0x9a,"v3_pci.c",299);
  }
  else {
    uVar5 = OBJ_obj2nid(local_24);
    if (((uVar5 & 0xfffffffd) == 0x299) && (local_1c != (ASN1_OCTET_STRING *)0x0)) {
      ERR_put_error(0x22,0x9b,0x9f,"v3_pci.c",0x131);
    }
    else {
      pPVar10 = PROXY_CERT_INFO_EXTENSION_new();
      if (pPVar10 != (PROXY_CERT_INFO_EXTENSION *)0x0) {
        pPVar9 = pPVar10->proxyPolicy;
        pPVar9->policyLanguage = local_24;
        pPVar9->policy = local_1c;
        local_24 = (ASN1_OBJECT *)0x0;
        local_1c = (ASN1_OCTET_STRING *)0x0;
        pPVar10->pcPathLengthConstraint = local_20;
        local_20 = (ASN1_INTEGER *)0x0;
        goto LAB_000d872c;
      }
      ERR_put_error(0x22,0x9b,0x41,"v3_pci.c",0x138);
    }
  }
LAB_000d8706:
  if (local_24 != (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free(local_24);
    local_24 = (ASN1_OBJECT *)0x0;
  }
  if (local_20 != (ASN1_INTEGER *)0x0) {
    ASN1_INTEGER_free(local_20);
    local_20 = (ASN1_INTEGER *)0x0;
  }
  if (local_1c != (ASN1_OCTET_STRING *)0x0) {
    ASN1_OCTET_STRING_free(local_1c);
    local_1c = (ASN1_OCTET_STRING *)0x0;
  }
  pPVar10 = (PROXY_CERT_INFO_EXTENSION *)0x0;
LAB_000d872c:
  sk_pop_free(st,X509V3_conf_free + 1);
  return pPVar10;
}

