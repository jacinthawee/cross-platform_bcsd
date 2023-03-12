
int CONF_dump_bio(lhash_st_CONF_VALUE *conf,BIO *out)

{
  undefined *puVar1;
  int iVar2;
  CONF *pCVar3;
  CONF_METHOD *meth;
  CONF local_28;
  CONF_METHOD *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(CONF_METHOD **)PTR___stack_chk_guard_006aabf0;
  if (default_CONF_method == (CONF_METHOD *)0x0) {
    default_CONF_method = NCONF_default();
  }
  (*default_CONF_method->init)(&local_28);
  local_28.data = conf;
  iVar2 = (*(local_28.meth)->dump)(&local_28,out);
  if (local_1c == *(CONF_METHOD **)puVar1) {
    return iVar2;
  }
  meth = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (meth == (CONF_METHOD *)0x0) {
    meth = NCONF_default();
  }
  pCVar3 = (*meth->create)(meth);
  if (pCVar3 == (CONF *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x6f,0x41,"conf_lib.c",0xf4);
  }
  return (int)pCVar3;
}

