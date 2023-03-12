
stack_st_CONF_VALUE * CONF_get_section(lhash_st_CONF_VALUE *conf,char *section)

{
  undefined *puVar1;
  stack_st_CONF_VALUE *psVar2;
  BIO *pBVar3;
  CONF *pCVar4;
  CONF_METHOD *meth;
  lhash_st_CONF_VALUE *plVar5;
  char *pcVar6;
  BIO *bp;
  char *in_a2;
  lhash_st_CONF_VALUE *unaff_s1;
  lhash_st_CONF_VALUE *unaff_s2;
  CONF *unaff_s3;
  CONF CStack_140;
  CONF_METHOD *pCStack_134;
  BIO *pBStack_12c;
  undefined *puStack_128;
  CONF *pCStack_124;
  CONF *pCStack_120;
  code *pcStack_11c;
  undefined4 uStack_108;
  undefined *puStack_100;
  CONF CStack_f8;
  lhash_st_CONF_VALUE *plStack_ec;
  CONF *pCStack_e4;
  undefined *puStack_e0;
  CONF *pCStack_dc;
  CONF *pCStack_d8;
  code *pcStack_d4;
  undefined *puStack_c0;
  CONF CStack_b8;
  stack_st_CONF_VALUE *psStack_ac;
  CONF *pCStack_a8;
  undefined *puStack_a4;
  lhash_st_CONF_VALUE *plStack_a0;
  code *pcStack_9c;
  char *pcStack_88;
  undefined *puStack_80;
  stack_st_CONF_VALUE *psStack_74;
  CONF CStack_70;
  CONF *pCStack_64;
  undefined *puStack_60;
  lhash_st_CONF_VALUE *plStack_5c;
  lhash_st_CONF_VALUE *plStack_58;
  CONF *pCStack_54;
  CONF CStack_28;
  lhash_st_CONF_VALUE *local_1c;
  
  puStack_60 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(lhash_st_CONF_VALUE **)PTR___stack_chk_guard_006aabf0;
  psVar2 = (stack_st_CONF_VALUE *)0x0;
  pCVar4 = (CONF *)section;
  plStack_5c = unaff_s1;
  plStack_a0 = unaff_s2;
  if (conf != (lhash_st_CONF_VALUE *)0x0) {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    unaff_s3 = &CStack_28;
    (*default_CONF_method->init)(unaff_s3);
    plStack_5c = conf;
    plStack_a0 = (lhash_st_CONF_VALUE *)section;
    CStack_28.data = conf;
    if (section == (char *)0x0) {
      in_a2 = &DAT_0000006b;
      pCVar4 = (CONF *)&DAT_0000006c;
      (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x6c,0x6b,"conf_lib.c");
      psVar2 = (stack_st_CONF_VALUE *)0x0;
    }
    else {
      psVar2 = _CONF_get_section_values(unaff_s3,section);
    }
  }
  if (local_1c == *(lhash_st_CONF_VALUE **)puStack_60) {
    return psVar2;
  }
  plVar5 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_a4 = PTR___stack_chk_guard_006aabf0;
  puStack_80 = &_gp;
  pCStack_64 = *(CONF **)PTR___stack_chk_guard_006aabf0;
  pCStack_a8 = (CONF *)&_ITM_registerTMCloneTable;
  plStack_58 = plStack_a0;
  pCStack_54 = unaff_s3;
  if (plVar5 == (lhash_st_CONF_VALUE *)0x0) {
    psVar2 = (stack_st_CONF_VALUE *)_CONF_get_string((CONF *)0x0,(char *)pCVar4,in_a2);
    pcVar6 = (char *)pCVar4;
    if (psVar2 == (stack_st_CONF_VALUE *)0x0) {
      pcStack_88 = (char *)0x14b;
      pcVar6 = &DAT_0000006d;
      (**(code **)(puStack_80 + -0x6eb0))(0xe,0x6d,0x6a,"conf_lib.c");
      psVar2 = (stack_st_CONF_VALUE *)0x0;
    }
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    pCStack_a8 = &CStack_70;
    (*default_CONF_method->init)(pCStack_a8);
    pcVar6 = (char *)pCVar4;
    CStack_70.data = plVar5;
    psVar2 = (stack_st_CONF_VALUE *)_CONF_get_string(pCStack_a8,(char *)pCVar4,in_a2);
    plStack_a0 = plVar5;
    unaff_s3 = pCVar4;
    if (psVar2 == (stack_st_CONF_VALUE *)0x0) {
      pcStack_88 = (char *)0x14f;
      psStack_74 = psVar2;
      (**(code **)(puStack_80 + -0x6eb0))(0xe,0x6d,0x6c,"conf_lib.c");
      pcVar6 = "group=";
      pcStack_88 = in_a2;
      (**(code **)(puStack_80 + -0x6c7c))(4,"group=",pCVar4," name=");
      psVar2 = psStack_74;
    }
  }
  if (pCStack_64 == *(CONF **)puStack_a4) {
    return psVar2;
  }
  pcStack_9c = CONF_free;
  pCStack_124 = pCStack_64;
  (**(code **)(puStack_80 + -0x5328))();
  puStack_e0 = PTR___stack_chk_guard_006aabf0;
  puStack_c0 = &_gp;
  psStack_ac = *(stack_st_CONF_VALUE **)PTR___stack_chk_guard_006aabf0;
  if (default_CONF_method == (CONF_METHOD *)0x0) {
    default_CONF_method = NCONF_default();
  }
  pCStack_e4 = &CStack_b8;
  (*default_CONF_method->init)(pCStack_e4);
  pCStack_120 = pCStack_e4;
  CStack_b8.data = (lhash_st_CONF_VALUE *)pCStack_124;
  (*(CStack_b8.meth)->destroy_data)(pCStack_e4);
  psVar2 = *(stack_st_CONF_VALUE **)puStack_e0;
  if (psStack_ac == psVar2) {
    return psVar2;
  }
  pcStack_d4 = CONF_dump_fp;
  (**(code **)(puStack_c0 + -0x5328))();
  puStack_128 = PTR___stack_chk_guard_006aabf0;
  puStack_100 = &_gp;
  plStack_ec = *(lhash_st_CONF_VALUE **)PTR___stack_chk_guard_006aabf0;
  pCStack_dc = pCStack_124;
  pCStack_d8 = unaff_s3;
  pBStack_12c = (BIO *)(*(code *)PTR_BIO_new_fp_006a835c)(pcVar6,0);
  if (pBStack_12c == (BIO *)0x0) {
    uStack_108 = 0xd4;
    bp = (BIO *)&DAT_00000068;
    (**(code **)(puStack_100 + -0x6eb0))(0xe,0x68,7,"conf_lib.c");
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    pCStack_124 = &CStack_f8;
    (*default_CONF_method->init)(pCStack_124);
    bp = pBStack_12c;
    CStack_f8.data = (lhash_st_CONF_VALUE *)pCStack_120;
    pBVar3 = (BIO *)(*(CStack_f8.meth)->dump)(pCStack_124,pBStack_12c);
    (**(code **)(puStack_100 + -0x7f70))(pBStack_12c);
    pBStack_12c = pBVar3;
  }
  if (plStack_ec == *(lhash_st_CONF_VALUE **)puStack_128) {
    return (stack_st_CONF_VALUE *)pBStack_12c;
  }
  pcStack_11c = CONF_dump_bio;
  CStack_140.data = plStack_ec;
  (**(code **)(puStack_100 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pCStack_134 = *(CONF_METHOD **)PTR___stack_chk_guard_006aabf0;
  if (default_CONF_method == (CONF_METHOD *)0x0) {
    default_CONF_method = NCONF_default();
  }
  (*default_CONF_method->init)(&CStack_140);
  psVar2 = (stack_st_CONF_VALUE *)(*(CStack_140.meth)->dump)(&CStack_140,bp);
  if (pCStack_134 == *(CONF_METHOD **)puVar1) {
    return psVar2;
  }
  meth = pCStack_134;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (meth == (CONF_METHOD *)0x0) {
    meth = NCONF_default();
  }
  pCVar4 = (*meth->create)(meth);
  if (pCVar4 == (CONF *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x6f,0x41,"conf_lib.c",0xf4);
  }
  return (stack_st_CONF_VALUE *)pCVar4;
}

