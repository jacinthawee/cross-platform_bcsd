
int X509V3_add_value_int(char *name,ASN1_INTEGER *aint,stack_st_CONF_VALUE **extlist)

{
  int iVar1;
  char *value;
  
  if (aint == (ASN1_INTEGER *)0x0) {
    return 1;
  }
  iVar1 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)(aint,0);
  if (iVar1 != 0) {
    value = (char *)(*(code *)PTR_BN_bn2dec_006a8f28)(iVar1);
    if (value != (char *)0x0) {
      (*(code *)PTR_BN_free_006a811c)(iVar1);
      iVar1 = X509V3_add_value(name,value,extlist);
      (*(code *)PTR_CRYPTO_free_006a7f88)(value);
      return iVar1;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x78,0x41,"v3_utl.c",0x9a);
  (*(code *)PTR_BN_free_006a811c)(iVar1);
  return 0;
}

