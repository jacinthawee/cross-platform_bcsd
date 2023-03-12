
void CONF_free(lhash_st_CONF_VALUE *conf)

{
  undefined *puVar1;
  BIO *pBVar2;
  CONF *pCVar3;
  CONF_METHOD *meth;
  undefined4 in_a1;
  BIO *bp;
  CONF CStack_a8;
  CONF_METHOD *pCStack_9c;
  BIO *pBStack_94;
  undefined *puStack_90;
  CONF *pCStack_8c;
  CONF *pCStack_88;
  code *pcStack_84;
  undefined4 uStack_70;
  undefined *puStack_68;
  CONF CStack_60;
  lhash_st_CONF_VALUE *plStack_54;
  CONF *pCStack_4c;
  undefined *puStack_48;
  lhash_st_CONF_VALUE *plStack_44;
  CONF local_20;
  int local_14;
  
  puStack_48 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (default_CONF_method == (CONF_METHOD *)0x0) {
    default_CONF_method = NCONF_default();
  }
  pCStack_4c = &local_20;
  (*default_CONF_method->init)(pCStack_4c);
  pCStack_88 = pCStack_4c;
  local_20.data = conf;
  (*(local_20.meth)->destroy_data)(pCStack_4c);
  if (local_14 == *(int *)puStack_48) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_90 = PTR___stack_chk_guard_006aabf0;
  puStack_68 = &_gp;
  plStack_54 = *(lhash_st_CONF_VALUE **)PTR___stack_chk_guard_006aabf0;
  plStack_44 = conf;
  pBStack_94 = (BIO *)(*(code *)PTR_BIO_new_fp_006a835c)(in_a1,0);
  if (pBStack_94 == (BIO *)0x0) {
    uStack_70 = 0xd4;
    bp = (BIO *)&DAT_00000068;
    (**(code **)(puStack_68 + -0x6eb0))(0xe,0x68,7,"conf_lib.c");
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    conf = (lhash_st_CONF_VALUE *)&CStack_60;
    (*default_CONF_method->init)((CONF *)conf);
    bp = pBStack_94;
    CStack_60.data = (lhash_st_CONF_VALUE *)pCStack_88;
    pBVar2 = (BIO *)(*(CStack_60.meth)->dump)((CONF *)conf,pBStack_94);
    (**(code **)(puStack_68 + -0x7f70))(pBStack_94);
    pBStack_94 = pBVar2;
  }
  if (plStack_54 == *(lhash_st_CONF_VALUE **)puStack_90) {
    return;
  }
  pcStack_84 = CONF_dump_bio;
  CStack_a8.data = plStack_54;
  (**(code **)(puStack_68 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pCStack_9c = *(CONF_METHOD **)PTR___stack_chk_guard_006aabf0;
  pCStack_8c = (CONF *)conf;
  if (default_CONF_method == (CONF_METHOD *)0x0) {
    default_CONF_method = NCONF_default();
  }
  (*default_CONF_method->init)(&CStack_a8);
  (*(CStack_a8.meth)->dump)(&CStack_a8,bp);
  if (pCStack_9c == *(CONF_METHOD **)puVar1) {
    return;
  }
  meth = pCStack_9c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (meth == (CONF_METHOD *)0x0) {
    meth = NCONF_default();
  }
  pCVar3 = (*meth->create)(meth);
  if (pCVar3 == (CONF *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x6f,0x41,"conf_lib.c",0xf4);
  }
  return;
}

