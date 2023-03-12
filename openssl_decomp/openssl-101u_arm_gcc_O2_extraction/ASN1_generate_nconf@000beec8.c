
ASN1_TYPE * ASN1_generate_nconf(char *str,CONF *nconf)

{
  CONF *reason;
  ASN1_TYPE *pAVar1;
  CONF *local_30;
  X509V3_CTX local_2c;
  
  if (nconf == (CONF *)0x0) {
    local_2c.flags = (int)nconf;
    pAVar1 = (ASN1_TYPE *)generate_v3(str,0,0,&local_2c);
    reason = (CONF *)local_2c.flags;
  }
  else {
    X509V3_set_nconf(&local_2c,nconf);
    local_30 = (CONF *)0x0;
    pAVar1 = (ASN1_TYPE *)generate_v3(str,&local_2c,0,&local_30);
    reason = local_30;
  }
  if (reason == (CONF *)0x0) {
    return pAVar1;
  }
  ERR_put_error(0xd,0xb2,(int)reason,"asn1_gen.c",0x90);
  return pAVar1;
}

