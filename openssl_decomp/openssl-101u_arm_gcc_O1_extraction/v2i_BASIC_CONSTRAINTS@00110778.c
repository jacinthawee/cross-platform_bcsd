
int * v2i_BASIC_CONSTRAINTS(undefined4 param_1,undefined4 param_2,_STACK *param_3)

{
  int *asn1_bool;
  int iVar1;
  CONF_VALUE *value;
  char *__s1;
  int iVar2;
  
  asn1_bool = (int *)ASN1_item_new((ASN1_ITEM *)&BASIC_CONSTRAINTS_it);
  if (asn1_bool == (int *)0x0) {
    ERR_put_error(0x22,0x66,0x41,"v3_bcons.c",0x6f);
  }
  else {
    iVar2 = 0;
    do {
      while( true ) {
        iVar1 = sk_num(param_3);
        if (iVar1 <= iVar2) {
          return asn1_bool;
        }
        value = (CONF_VALUE *)sk_value(param_3,iVar2);
        __s1 = value->name;
        if (((*__s1 != 'C') || (__s1[1] != 'A')) || (__s1[2] != '\0')) break;
        iVar1 = X509V3_get_value_bool(value,asn1_bool);
        iVar2 = iVar2 + 1;
        if (iVar1 == 0) goto LAB_001107d2;
      }
      iVar1 = strcmp(__s1,"pathlen");
      if (iVar1 != 0) {
        ERR_put_error(0x22,0x66,0x6a,"v3_bcons.c",0x7b);
        ERR_add_error_data(6,"section:",value->section,",name:",value->name,",value:",value->value);
        break;
      }
      iVar1 = X509V3_get_value_int(value,(ASN1_INTEGER **)(asn1_bool + 1));
      iVar2 = iVar2 + 1;
    } while (iVar1 != 0);
LAB_001107d2:
    ASN1_item_free((ASN1_VALUE *)asn1_bool,(ASN1_ITEM *)&BASIC_CONSTRAINTS_it);
    asn1_bool = (int *)0x0;
  }
  return asn1_bool;
}

