
X509_EXTENSION *
X509V3_EXT_conf_nid(lhash_st_CONF_VALUE *conf,X509V3_CTX *ctx,int ext_nid,char *value)

{
  X509_EXTENSION *pXVar1;
  int in_GS_OFFSET;
  CONF local_1c;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  CONF_set_nconf(&local_1c,conf);
  pXVar1 = X509V3_EXT_nconf_nid(&local_1c,ctx,ext_nid,value);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pXVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

