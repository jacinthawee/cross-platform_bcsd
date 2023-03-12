
X509_EXTENSION *
X509V3_EXT_conf_nid(lhash_st_CONF_VALUE *conf,X509V3_CTX *ctx,int ext_nid,char *value)

{
  undefined *puVar1;
  X509_EXTENSION *pXVar2;
  CONF CStack_20;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  CONF_set_nconf(&CStack_20,conf);
  pXVar2 = X509V3_EXT_nconf_nid(&CStack_20,ctx,ext_nid,value);
  if (local_14 == *(int *)puVar1) {
    return pXVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  *(X509V3_CTX **)(local_14 + 0x18) = ctx;
  *(undefined1 **)(local_14 + 0x14) = conf_lhash_method;
  return (X509_EXTENSION *)conf_lhash_method;
}

