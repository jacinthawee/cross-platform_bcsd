
int * v2i_BASIC_CONSTRAINTS(undefined4 param_1,undefined4 param_2,_STACK *param_3)

{
  int *asn1_bool;
  int iVar1;
  CONF_VALUE *value;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  byte bVar6;
  
  bVar6 = 0;
  asn1_bool = (int *)ASN1_item_new((ASN1_ITEM *)BASIC_CONSTRAINTS_it);
  if (asn1_bool == (int *)0x0) {
    ERR_put_error(0x22,0x66,0x41,"v3_bcons.c",0x6f);
  }
  else {
    for (iVar2 = 0; iVar1 = sk_num(param_3), iVar2 < iVar1; iVar2 = iVar2 + 1) {
      value = (CONF_VALUE *)sk_value(param_3,iVar2);
      pcVar3 = value->name;
      bVar5 = *pcVar3 == 'C';
      if (((bVar5) && (bVar5 = pcVar3[1] == 'A', bVar5)) && (bVar5 = pcVar3[2] == '\0', bVar5)) {
        iVar1 = X509V3_get_value_bool(value,asn1_bool);
      }
      else {
        iVar1 = 8;
        pcVar4 = "pathlen";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar5 = *pcVar3 == *pcVar4;
          pcVar3 = pcVar3 + (uint)bVar6 * -2 + 1;
          pcVar4 = pcVar4 + (uint)bVar6 * -2 + 1;
        } while (bVar5);
        if (!bVar5) {
          ERR_put_error(0x22,0x66,0x6a,"v3_bcons.c",0x7b);
          ERR_add_error_data(6,"section:",value->section,",name:",value->name,",value:",value->value
                            );
          goto LAB_081d12fa;
        }
        iVar1 = X509V3_get_value_int(value,(ASN1_INTEGER **)(asn1_bool + 1));
      }
      if (iVar1 == 0) {
LAB_081d12fa:
        ASN1_item_free((ASN1_VALUE *)asn1_bool,(ASN1_ITEM *)BASIC_CONSTRAINTS_it);
        return (int *)0x0;
      }
    }
  }
  return asn1_bool;
}

