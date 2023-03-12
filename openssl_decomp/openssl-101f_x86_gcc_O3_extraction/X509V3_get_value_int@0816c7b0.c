
int X509V3_get_value_int(CONF_VALUE *value,ASN1_INTEGER **aint)

{
  char cVar1;
  int iVar2;
  ASN1_INTEGER *pAVar3;
  char *str;
  int in_GS_OFFSET;
  bool bVar4;
  BIGNUM *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (BIGNUM *)0x0;
  str = value->value;
  if (str == (char *)0x0) {
    ERR_put_error(0x22,0x6c,0x6d,"v3_utl.c",0xa6);
  }
  else {
    local_24 = BN_new();
    cVar1 = *str;
    bVar4 = cVar1 == '-';
    if (bVar4) {
      cVar1 = str[1];
      str = str + 1;
    }
    if ((cVar1 == '0') && ((str[1] & 0xdfU) == 0x58)) {
      str = str + 2;
      iVar2 = BN_hex2bn(&local_24,str);
    }
    else {
      iVar2 = BN_dec2bn(&local_24,str);
    }
    if ((iVar2 != 0) && (str[iVar2] == '\0')) {
      if ((bVar4) && (local_24->top != 0)) {
        pAVar3 = BN_to_ASN1_INTEGER(local_24,(ASN1_INTEGER *)0x0);
        BN_free(local_24);
        if (pAVar3 == (ASN1_INTEGER *)0x0) {
LAB_0816c95d:
          ERR_put_error(0x22,0x6c,0x65,"v3_utl.c",0xc2);
          goto LAB_0816c90e;
        }
        pAVar3->type = pAVar3->type | 0x100;
      }
      else {
        pAVar3 = BN_to_ASN1_INTEGER(local_24,(ASN1_INTEGER *)0x0);
        BN_free(local_24);
        if (pAVar3 == (ASN1_INTEGER *)0x0) goto LAB_0816c95d;
      }
      *aint = pAVar3;
      iVar2 = 1;
      goto LAB_0816c852;
    }
    BN_free(local_24);
    ERR_put_error(0x22,0x6c,100,"v3_utl.c",0xb9);
  }
LAB_0816c90e:
  ERR_add_error_data(6,"section:",value->section,",name:",value->name,",value:",value->value);
  iVar2 = 0;
LAB_0816c852:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

