
int CONF_dump_fp(lhash_st_CONF_VALUE *conf,FILE *out)

{
  undefined *puVar1;
  BIO *pBVar2;
  int iVar3;
  CONF *pCVar4;
  CONF_METHOD *meth;
  BIO *bp;
  CONF *unaff_s2;
  CONF CStack_70;
  CONF_METHOD *pCStack_64;
  BIO *pBStack_5c;
  undefined *puStack_58;
  CONF *pCStack_54;
  lhash_st_CONF_VALUE *plStack_50;
  code *pcStack_4c;
  undefined4 local_38;
  undefined *local_30;
  CONF local_28;
  lhash_st_CONF_VALUE *local_1c;
  
  puStack_58 = PTR___stack_chk_guard_006a9ae8;
  local_30 = &_gp;
  local_1c = *(lhash_st_CONF_VALUE **)PTR___stack_chk_guard_006a9ae8;
  pBStack_5c = (BIO *)(*(code *)PTR_BIO_new_fp_006a7248)(out,0);
  if (pBStack_5c == (BIO *)0x0) {
    local_38 = 0xcc;
    bp = (BIO *)&DAT_00000068;
    (**(code **)(local_30 + -0x6eac))(0xe,0x68,7,"conf_lib.c");
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    unaff_s2 = &local_28;
    (*default_CONF_method->init)(unaff_s2);
    bp = pBStack_5c;
    local_28.data = conf;
    pBVar2 = (BIO *)(*(local_28.meth)->dump)(unaff_s2,pBStack_5c);
    (**(code **)(local_30 + -0x7f70))(pBStack_5c);
    pBStack_5c = pBVar2;
  }
  if (local_1c == *(lhash_st_CONF_VALUE **)puStack_58) {
    return (int)pBStack_5c;
  }
  pcStack_4c = CONF_dump_bio;
  CStack_70.data = local_1c;
  (**(code **)(local_30 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pCStack_64 = *(CONF_METHOD **)PTR___stack_chk_guard_006a9ae8;
  pCStack_54 = unaff_s2;
  plStack_50 = conf;
  if (default_CONF_method == (CONF_METHOD *)0x0) {
    default_CONF_method = NCONF_default();
  }
  (*default_CONF_method->init)(&CStack_70);
  iVar3 = (*(CStack_70.meth)->dump)(&CStack_70,bp);
  if (pCStack_64 == *(CONF_METHOD **)puVar1) {
    return iVar3;
  }
  meth = pCStack_64;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (meth == (CONF_METHOD *)0x0) {
    meth = NCONF_default();
  }
  pCVar4 = (*meth->create)(meth);
  if (pCVar4 == (CONF *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x6f,0x41,"conf_lib.c",0xed);
  }
  return (int)pCVar4;
}

