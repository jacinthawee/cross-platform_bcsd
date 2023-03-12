
ASN1_TYPE * ASN1_generate_nconf(char *str,CONF *nconf)

{
  ASN1_TYPE *pAVar1;
  X509V3_CTX XStack_24;
  
  if (nconf != (CONF *)0x0) {
    X509V3_set_nconf(&XStack_24,nconf);
    nconf = (CONF *)&XStack_24;
  }
  pAVar1 = ASN1_generate_v3(str,(X509V3_CTX *)nconf);
  return pAVar1;
}

