
int X509V3_get_value_int(CONF_VALUE *value,ASN1_INTEGER **aint)

{
  char cVar1;
  int iVar2;
  ASN1_INTEGER *pAVar3;
  char *str;
  bool bVar4;
  BIGNUM *local_1c [2];
  
  str = value->value;
  local_1c[0] = (BIGNUM *)0x0;
  if (str == (char *)0x0) {
    ERR_put_error(0x22,0x6c,0x6d,"v3_utl.c",0xb6);
  }
  else {
    local_1c[0] = BN_new();
    cVar1 = *str;
    bVar4 = cVar1 == '-';
    if (bVar4) {
      cVar1 = str[1];
    }
    if (bVar4) {
      str = str + bVar4;
    }
    if ((cVar1 == '0') && ((str[1] & 0xdfU) == 0x58)) {
      str = str + 2;
      iVar2 = BN_hex2bn(local_1c,str);
    }
    else {
      iVar2 = BN_dec2bn(local_1c,str);
    }
    if ((iVar2 == 0) || (str[iVar2] != '\0')) {
      BN_free(local_1c[0]);
      ERR_put_error(0x22,0x6c,100,"v3_utl.c",0xcd);
    }
    else {
      if (bVar4 == 0) {
        pAVar3 = BN_to_ASN1_INTEGER(local_1c[0],(ASN1_INTEGER *)0x0);
        BN_free(local_1c[0]);
        if (pAVar3 != (ASN1_INTEGER *)0x0) goto LAB_000cfe22;
      }
      else {
        iVar2 = local_1c[0]->top;
        pAVar3 = BN_to_ASN1_INTEGER(local_1c[0],(ASN1_INTEGER *)0x0);
        BN_free(local_1c[0]);
        if (pAVar3 != (ASN1_INTEGER *)0x0) {
          if (iVar2 != 0) {
            pAVar3->type = pAVar3->type | 0x100;
          }
LAB_000cfe22:
          *aint = pAVar3;
          return 1;
        }
      }
      ERR_put_error(0x22,0x6c,0x65,"v3_utl.c",0xd8);
    }
  }
  ERR_add_error_data(6,"section:",value->section,",name:",value->name,",value:",value->value);
  return 0;
}

