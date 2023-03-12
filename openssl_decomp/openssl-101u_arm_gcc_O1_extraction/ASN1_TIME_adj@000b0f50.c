
ASN1_TIME * ASN1_TIME_adj(ASN1_TIME *s,time_t t,int offset_day,long offset_sec)

{
  ASN1_TIME *pAVar1;
  ASN1_GENERALIZEDTIME *pAVar2;
  ASN1_UTCTIME *pAVar3;
  time_t local_4c [2];
  undefined auStack_44 [48];
  
  local_4c[0] = t;
  pAVar1 = (ASN1_TIME *)OPENSSL_gmtime(local_4c,auStack_44);
  if (pAVar1 == (ASN1_TIME *)0x0) {
    ERR_put_error(0xd,0xd9,0xad,"a_time.c",0x72);
    pAVar2 = pAVar1;
  }
  else if ((offset_sec == 0 && offset_day == 0) ||
          (pAVar2 = (ASN1_GENERALIZEDTIME *)OPENSSL_gmtime_adj(pAVar1,offset_day,offset_sec),
          pAVar2 != (ASN1_TIME *)0x0)) {
    if (pAVar1[1].type - 0x32U < 100) {
      pAVar3 = ASN1_UTCTIME_adj(s,local_4c[0],offset_day,offset_sec);
      return pAVar3;
    }
    pAVar2 = ASN1_GENERALIZEDTIME_adj(s,local_4c[0],offset_day,offset_sec);
  }
  return pAVar2;
}

