
ASN1_TYPE * ASN1_generate_nconf(char *str,CONF *nconf)

{
  int reason;
  ASN1_TYPE *pAVar1;
  int in_GS_OFFSET;
  int local_30;
  X509V3_CTX local_2c;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (nconf == (CONF *)0x0) {
    local_2c.flags = 0;
    pAVar1 = (ASN1_TYPE *)generate_v3(&local_2c);
    reason = local_2c.flags;
  }
  else {
    X509V3_set_nconf(&local_2c,nconf);
    local_30 = 0;
    pAVar1 = (ASN1_TYPE *)generate_v3(&local_30);
    reason = local_30;
  }
  if (reason != 0) {
    ERR_put_error(0xd,0xb2,reason,"asn1_gen.c",0x90);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

