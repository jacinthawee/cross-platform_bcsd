
ASN1_INTEGER * s2i_ASN1_INTEGER(X509V3_EXT_METHOD *meth,char *value)

{
  char cVar1;
  int iVar2;
  ASN1_INTEGER *pAVar3;
  int in_GS_OFFSET;
  bool bVar4;
  int line;
  BIGNUM *local_14;
  int local_10;
  
  local_14 = (BIGNUM *)0x0;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (value == (char *)0x0) {
    line = 0xb6;
    iVar2 = 0x6d;
  }
  else {
    local_14 = BN_new();
    cVar1 = *value;
    bVar4 = cVar1 == '-';
    if (bVar4) {
      cVar1 = value[1];
      value = value + 1;
    }
    if ((cVar1 == '0') && ((value[1] & 0xdfU) == 0x58)) {
      value = value + 2;
      iVar2 = BN_hex2bn(&local_14,value);
    }
    else {
      iVar2 = BN_dec2bn(&local_14,value);
    }
    if ((iVar2 == 0) || (value[iVar2] != '\0')) {
      BN_free(local_14);
      line = 0xcd;
      iVar2 = 100;
    }
    else {
      if ((bVar4) && (local_14->top != 0)) {
        pAVar3 = BN_to_ASN1_INTEGER(local_14,(ASN1_INTEGER *)0x0);
        BN_free(local_14);
        if (pAVar3 != (ASN1_INTEGER *)0x0) {
          pAVar3->type = pAVar3->type | 0x100;
          goto LAB_0816a57c;
        }
      }
      else {
        pAVar3 = BN_to_ASN1_INTEGER(local_14,(ASN1_INTEGER *)0x0);
        BN_free(local_14);
        if (pAVar3 != (ASN1_INTEGER *)0x0) goto LAB_0816a57c;
      }
      line = 0xd8;
      iVar2 = 0x65;
    }
  }
  ERR_put_error(0x22,0x6c,iVar2,"v3_utl.c",line);
  pAVar3 = (ASN1_INTEGER *)0x0;
LAB_0816a57c:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pAVar3;
}

