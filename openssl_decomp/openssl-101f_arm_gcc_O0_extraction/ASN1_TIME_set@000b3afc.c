
ASN1_TIME * ASN1_TIME_set(ASN1_TIME *s,time_t t)

{
  ASN1_TIME *pAVar1;
  ASN1_UTCTIME *pAVar2;
  time_t local_40;
  undefined auStack_3c [48];
  
  local_40 = t;
  pAVar1 = (ASN1_TIME *)OPENSSL_gmtime(&local_40,auStack_3c);
  if (pAVar1 == (ASN1_TIME *)0x0) {
    ERR_put_error(0xd,0xd9,0xad,"a_time.c",0x73);
  }
  else {
    if (pAVar1[1].type - 0x32U < 100) {
      pAVar2 = ASN1_UTCTIME_adj(s,local_40,0,0);
      return pAVar2;
    }
    pAVar1 = ASN1_GENERALIZEDTIME_adj(s,local_40,0,0);
  }
  return pAVar1;
}

