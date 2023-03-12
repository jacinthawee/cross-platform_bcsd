
/* WARNING: Removing unreachable block (ram,0x08176d93) */
/* WARNING: Removing unreachable block (ram,0x08176e7b) */
/* WARNING: Removing unreachable block (ram,0x08176e91) */
/* WARNING: Removing unreachable block (ram,0x08176ebf) */
/* WARNING: Removing unreachable block (ram,0x08176eca) */
/* WARNING: Removing unreachable block (ram,0x08176f42) */
/* WARNING: Removing unreachable block (ram,0x08176e99) */
/* WARNING: Removing unreachable block (ram,0x08176daf) */

undefined4 r2i_pci(undefined4 param_1,X509V3_CTX *param_2,char *param_3)

{
  char *pcVar1;
  _STACK *st;
  int iVar2;
  undefined4 *puVar3;
  _STACK *section;
  int iVar4;
  int iVar5;
  int in_GS_OFFSET;
  ASN1_OCTET_STRING *local_24;
  int local_20;
  
  iVar5 = 0;
  local_24 = (ASN1_OCTET_STRING *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  st = (_STACK *)X509V3_parse_list(param_3);
  do {
    iVar2 = sk_num(st);
    if (iVar2 <= iVar5) {
      ERR_put_error(0x22,0x9b,0x9a,"v3_pci.c",299);
LAB_08176d8b:
      if (local_24 != (ASN1_OCTET_STRING *)0x0) {
        ASN1_OCTET_STRING_free(local_24);
        local_24 = (ASN1_OCTET_STRING *)0x0;
      }
      sk_pop_free(st,X509V3_conf_free);
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        return 0;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    puVar3 = (undefined4 *)sk_value(st,iVar5);
    pcVar1 = (char *)puVar3[1];
    if (pcVar1 == (char *)0x0) {
LAB_08176e28:
      iVar2 = 0x103;
      iVar5 = 0x99;
LAB_08176e3a:
      ERR_put_error(0x22,0x9b,iVar5,"v3_pci.c",iVar2);
LAB_08176e49:
      ERR_add_error_data(6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
      goto LAB_08176d8b;
    }
    if (*pcVar1 != '@') {
      if (puVar3[2] == 0) goto LAB_08176e28;
      iVar2 = process_pci_value(&local_24);
      if (iVar2 != 0) goto LAB_08176ce5;
      goto LAB_08176e49;
    }
    section = (_STACK *)X509V3_get_section(param_2,pcVar1 + 1);
    if (section == (_STACK *)0x0) {
      iVar2 = 0x10f;
      iVar5 = 0x87;
      goto LAB_08176e3a;
    }
    iVar2 = 0;
    while (iVar4 = sk_num(section), iVar2 < iVar4) {
      sk_value(section,iVar2);
      iVar4 = process_pci_value(&local_24);
      iVar2 = iVar2 + 1;
      if (iVar4 == 0) {
        X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section);
        goto LAB_08176d8b;
      }
    }
    X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section);
LAB_08176ce5:
    iVar5 = iVar5 + 1;
  } while( true );
}

