
BIO * conf_lhash_get_string(lhash_st_CONF_VALUE *param_1,char *param_2,char *param_3)

{
  undefined *puVar1;
  BIO *pBVar2;
  BIO *pBVar3;
  CONF_METHOD *meth;
  char *pcVar4;
  lhash_st_CONF_VALUE *unaff_s2;
  char *unaff_s3;
  CONF CStack_f8;
  CONF_METHOD *pCStack_ec;
  BIO *pBStack_e4;
  undefined *puStack_e0;
  CONF *pCStack_dc;
  CONF *pCStack_d8;
  code *pcStack_d4;
  undefined4 uStack_c0;
  undefined *puStack_b8;
  CONF CStack_b0;
  lhash_st_CONF_VALUE *plStack_a4;
  CONF *pCStack_9c;
  undefined *puStack_98;
  CONF *pCStack_94;
  char *pcStack_90;
  code *pcStack_8c;
  undefined *puStack_78;
  CONF CStack_70;
  BIO *pBStack_64;
  CONF *pCStack_60;
  undefined *puStack_5c;
  lhash_st_CONF_VALUE *plStack_58;
  code *pcStack_54;
  char *pcStack_40;
  undefined *puStack_38;
  BIO *pBStack_2c;
  CONF CStack_28;
  CONF *pCStack_1c;
  
  puStack_5c = PTR___stack_chk_guard_006a9ae8;
  puStack_38 = &_gp;
  pCStack_1c = *(CONF **)PTR___stack_chk_guard_006a9ae8;
  pCStack_60 = (CONF *)&_gp_1;
  if (param_1 == (lhash_st_CONF_VALUE *)0x0) {
    pBVar2 = (BIO *)_CONF_get_string((CONF *)0x0,param_2,param_3);
    pcVar4 = param_2;
    if (pBVar2 == (BIO *)0x0) {
      pcStack_40 = (char *)0x141;
      pcVar4 = &DAT_0000006d;
      (**(code **)(puStack_38 + -0x6eac))(0xe,0x6d,0x6a,"conf_lib.c");
      pBVar2 = (BIO *)0x0;
    }
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    pCStack_60 = &CStack_28;
    (*default_CONF_method->init)(pCStack_60);
    pcVar4 = param_2;
    CStack_28.data = param_1;
    pBVar2 = (BIO *)_CONF_get_string(pCStack_60,param_2,param_3);
    unaff_s2 = param_1;
    unaff_s3 = param_2;
    if (pBVar2 == (BIO *)0x0) {
      pcStack_40 = (char *)0x144;
      pBStack_2c = pBVar2;
      (**(code **)(puStack_38 + -0x6eac))(0xe,0x6d,0x6c,"conf_lib.c");
      pcVar4 = "group=";
      pcStack_40 = param_3;
      (**(code **)(puStack_38 + -0x6ca4))(4,"group=",param_2," name=");
      pBVar2 = pBStack_2c;
    }
  }
  if (pCStack_1c == *(CONF **)puStack_5c) {
    return pBVar2;
  }
  pcStack_54 = CONF_free;
  pCStack_dc = pCStack_1c;
  (**(code **)(puStack_38 + -0x5330))();
  puStack_98 = PTR___stack_chk_guard_006a9ae8;
  puStack_78 = &_gp;
  pBStack_64 = *(BIO **)PTR___stack_chk_guard_006a9ae8;
  plStack_58 = unaff_s2;
  if (default_CONF_method == (CONF_METHOD *)0x0) {
    default_CONF_method = NCONF_default();
  }
  pCStack_9c = &CStack_70;
  (*default_CONF_method->init)(pCStack_9c);
  pCStack_d8 = pCStack_9c;
  CStack_70.data = (lhash_st_CONF_VALUE *)pCStack_dc;
  (*(CStack_70.meth)->destroy_data)(pCStack_9c);
  pBVar2 = *(BIO **)puStack_98;
  if (pBStack_64 == pBVar2) {
    return pBVar2;
  }
  pcStack_8c = CONF_dump_fp;
  (**(code **)(puStack_78 + -0x5330))();
  puStack_e0 = PTR___stack_chk_guard_006a9ae8;
  puStack_b8 = &_gp;
  plStack_a4 = *(lhash_st_CONF_VALUE **)PTR___stack_chk_guard_006a9ae8;
  pCStack_94 = pCStack_dc;
  pcStack_90 = unaff_s3;
  pBStack_e4 = (BIO *)(*(code *)PTR_BIO_new_fp_006a7248)(pcVar4,0);
  if (pBStack_e4 == (BIO *)0x0) {
    uStack_c0 = 0xcc;
    pBVar2 = (BIO *)&DAT_00000068;
    (**(code **)(puStack_b8 + -0x6eac))(0xe,0x68,7,"conf_lib.c");
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    pCStack_dc = &CStack_b0;
    (*default_CONF_method->init)(pCStack_dc);
    pBVar2 = pBStack_e4;
    CStack_b0.data = (lhash_st_CONF_VALUE *)pCStack_d8;
    pBVar3 = (BIO *)(*(CStack_b0.meth)->dump)(pCStack_dc,pBStack_e4);
    (**(code **)(puStack_b8 + -0x7f70))(pBStack_e4);
    pBStack_e4 = pBVar3;
  }
  if (plStack_a4 == *(lhash_st_CONF_VALUE **)puStack_e0) {
    return pBStack_e4;
  }
  pcStack_d4 = CONF_dump_bio;
  CStack_f8.data = plStack_a4;
  (**(code **)(puStack_b8 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pCStack_ec = *(CONF_METHOD **)PTR___stack_chk_guard_006a9ae8;
  if (default_CONF_method == (CONF_METHOD *)0x0) {
    default_CONF_method = NCONF_default();
  }
  (*default_CONF_method->init)(&CStack_f8);
  pBVar2 = (BIO *)(*(CStack_f8.meth)->dump)(&CStack_f8,pBVar2);
  if (pCStack_ec == *(CONF_METHOD **)puVar1) {
    return pBVar2;
  }
  meth = pCStack_ec;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (meth == (CONF_METHOD *)0x0) {
    meth = NCONF_default();
  }
  pBVar2 = (BIO *)(*meth->create)(meth);
  if (pBVar2 == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x6f,0x41,"conf_lib.c",0xed);
  }
  return pBVar2;
}

