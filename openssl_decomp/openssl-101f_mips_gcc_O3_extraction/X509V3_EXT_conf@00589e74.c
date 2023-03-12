
X509_EXTENSION * X509V3_EXT_conf(lhash_st_CONF_VALUE *conf,X509V3_CTX *ctx,char *name,char *value)

{
  undefined *puVar1;
  X509_EXTENSION *pXVar2;
  lhash_st_CONF_VALUE *hash;
  X509V3_CTX *ctx_00;
  char *ext_nid;
  char *value_00;
  CONF CStack_60;
  int iStack_54;
  CONF *pCStack_50;
  undefined *puStack_4c;
  X509V3_CTX *pXStack_48;
  code *pcStack_44;
  undefined *local_30;
  char *local_28;
  char *local_24;
  CONF CStack_20;
  lhash_st_CONF_VALUE *local_14;
  
  puStack_4c = PTR___stack_chk_guard_006aabf0;
  pCStack_50 = &CStack_20;
  local_30 = &_gp;
  local_14 = *(lhash_st_CONF_VALUE **)PTR___stack_chk_guard_006aabf0;
  local_28 = value;
  local_24 = name;
  CONF_set_nconf(pCStack_50,conf);
  ctx_00 = ctx;
  ext_nid = local_24;
  value_00 = local_28;
  pXVar2 = X509V3_EXT_nconf(pCStack_50,ctx,local_24,local_28);
  if (local_14 == *(lhash_st_CONF_VALUE **)puStack_4c) {
    return pXVar2;
  }
  pcStack_44 = X509V3_EXT_conf_nid;
  hash = local_14;
  (**(code **)(local_30 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_54 = *(int *)PTR___stack_chk_guard_006aabf0;
  pXStack_48 = ctx;
  CONF_set_nconf(&CStack_60,hash);
  pXVar2 = X509V3_EXT_nconf_nid(&CStack_60,ctx_00,(int)ext_nid,value_00);
  if (iStack_54 == *(int *)puVar1) {
    return pXVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  *(X509V3_CTX **)(iStack_54 + 0x18) = ctx_00;
  *(undefined1 **)(iStack_54 + 0x14) = conf_lhash_method;
  return (X509_EXTENSION *)conf_lhash_method;
}

