
X509_EXTENSION * X509V3_EXT_conf(lhash_st_CONF_VALUE *conf,X509V3_CTX *ctx,char *name,char *value)

{
  X509_EXTENSION *pXVar1;
  int in_GS_OFFSET;
  CONF local_2c;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  CONF_set_nconf(&local_2c,conf);
  pXVar1 = X509V3_EXT_nconf(&local_2c,ctx,name,value);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pXVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

