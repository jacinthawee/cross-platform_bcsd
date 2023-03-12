
ASN1_TYPE * ASN1_generate_nconf(char *str,CONF *nconf)

{
  ASN1_TYPE *pAVar1;
  int in_GS_OFFSET;
  X509V3_CTX local_2c;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (nconf == (CONF *)0x0) {
    pAVar1 = ASN1_generate_v3(str,(X509V3_CTX *)0x0);
  }
  else {
    X509V3_set_nconf(&local_2c,nconf);
    pAVar1 = ASN1_generate_v3(str,&local_2c);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

