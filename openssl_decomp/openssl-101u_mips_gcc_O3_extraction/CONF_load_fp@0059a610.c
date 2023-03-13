
lhash_st_CONF_VALUE * CONF_load_fp(lhash_st_CONF_VALUE *conf,FILE *fp,long *eline)

{
  undefined *puVar1;
  BIO *pBVar2;
  int iVar3;
  stack_st_CONF_VALUE *psVar4;
  lhash_st_CONF_VALUE *plVar5;
  BIO *pBVar6;
  CONF *pCVar7;
  CONF_METHOD *meth;
  char *pcVar8;
  long *name;
  BIO *unaff_s1;
  CONF CStack_1c8;
  CONF_METHOD *pCStack_1bc;
  BIO *pBStack_1b4;
  undefined *puStack_1b0;
  CONF *pCStack_1ac;
  CONF *pCStack_1a8;
  code *pcStack_1a4;
  undefined4 uStack_190;
  undefined *puStack_188;
  CONF CStack_180;
  lhash_st_CONF_VALUE *plStack_174;
  CONF *pCStack_16c;
  undefined *puStack_168;
  CONF *pCStack_164;
  BIO *pBStack_160;
  code *pcStack_15c;
  undefined *puStack_148;
  CONF CStack_140;
  lhash_st_CONF_VALUE *plStack_134;
  CONF *pCStack_130;
  undefined *puStack_12c;
  BIO *pBStack_128;
  code *pcStack_124;
  long *plStack_110;
  undefined *puStack_108;
  lhash_st_CONF_VALUE *plStack_fc;
  CONF CStack_f8;
  CONF *pCStack_ec;
  undefined *puStack_e8;
  char *pcStack_e4;
  BIO *pBStack_e0;
  BIO *pBStack_dc;
  long *plStack_d8;
  code *pcStack_d4;
  undefined4 uStack_c0;
  undefined *puStack_b8;
  BIO BStack_b0;
  CONF CStack_70;
  char *pcStack_64;
  lhash_st_CONF_VALUE *plStack_60;
  BIO *pBStack_5c;
  undefined *puStack_58;
  lhash_st_CONF_VALUE *plStack_54;
  long *plStack_50;
  code *pcStack_4c;
  undefined4 local_38;
  undefined *local_30;
  CONF local_28;
  BIO *local_1c;
  
  puStack_58 = PTR___stack_chk_guard_006a9ae8;
  local_30 = &_gp;
  local_1c = *(BIO **)PTR___stack_chk_guard_006a9ae8;
  pBVar2 = (BIO *)(*(code *)PTR_BIO_new_fp_006a7248)(fp,0);
  if (pBVar2 == (BIO *)0x0) {
    plStack_d8 = (long *)&DAT_00000007;
    local_38 = 0x7a;
    pBStack_160 = (BIO *)0x67;
    plStack_60 = (lhash_st_CONF_VALUE *)0x0;
    (**(code **)(local_30 + -0x6eac))(0xe,0x67,7,"conf_lib.c");
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    (*default_CONF_method->init)(&local_28);
    pBStack_160 = pBVar2;
    plStack_d8 = eline;
    local_28.data = conf;
    iVar3 = (*(local_28.meth)->load_bio)(&local_28,pBVar2,eline);
    plStack_60 = local_28.data;
    if (iVar3 == 0) {
      plStack_60 = (lhash_st_CONF_VALUE *)0x0;
    }
    (**(code **)(local_30 + -0x7f70))(pBVar2);
    unaff_s1 = pBVar2;
  }
  if (local_1c == *(BIO **)puStack_58) {
    return plStack_60;
  }
  pcStack_4c = CONF_load_bio;
  BStack_b0.num = (int)local_1c;
  (**(code **)(local_30 + -0x5330))();
  BStack_b0.retry_reason = (int)PTR___stack_chk_guard_006a9ae8;
  BStack_b0.ex_data.sk = (stack_st_void *)&_gp;
  pcStack_64 = *(char **)PTR___stack_chk_guard_006a9ae8;
  pBStack_5c = unaff_s1;
  plStack_54 = conf;
  plStack_50 = eline;
  if (default_CONF_method == (CONF_METHOD *)0x0) {
    default_CONF_method = NCONF_default();
  }
  BStack_b0.flags = (int)&CStack_70;
  (*default_CONF_method->init)((CONF *)BStack_b0.flags);
  pBVar6 = pBStack_160;
  name = plStack_d8;
  CStack_70.data = (lhash_st_CONF_VALUE *)BStack_b0.num;
  iVar3 = (*(CStack_70.meth)->load_bio)((CONF *)BStack_b0.flags,pBStack_160,plStack_d8);
  pBVar2 = (BIO *)CStack_70.data;
  if (iVar3 == 0) {
    pBVar2 = (BIO *)0x0;
  }
  if (pcStack_64 == *(char **)BStack_b0.retry_reason) {
    return (lhash_st_CONF_VALUE *)pBVar2;
  }
  BStack_b0.next_bio = (bio_st *)CONF_get_section;
  pcVar8 = pcStack_64;
  (*(code *)BStack_b0.ex_data.sk[-0x429].stack.data)();
  puStack_e8 = PTR___stack_chk_guard_006a9ae8;
  puStack_b8 = &_gp;
  BStack_b0.init = *(int *)PTR___stack_chk_guard_006a9ae8;
  psVar4 = (stack_st_CONF_VALUE *)0x0;
  pcStack_e4 = (char *)BStack_b0.retry_reason;
  pBStack_128 = (BIO *)BStack_b0.num;
  BStack_b0.ptr = pBStack_160;
  if (pcVar8 != (char *)0x0) {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    pBStack_160 = &BStack_b0;
    (*default_CONF_method->init)((CONF *)pBStack_160);
    pcStack_e4 = pcVar8;
    pBStack_128 = pBVar6;
    BStack_b0.cb_arg = pcVar8;
    if (pBVar6 == (BIO *)0x0) {
      name = (long *)&DAT_0000006b;
      uStack_c0 = 0x12d;
      pBVar6 = (BIO *)&DAT_0000006c;
      (**(code **)(puStack_b8 + -0x6eac))(0xe,0x6c,0x6b,"conf_lib.c");
      psVar4 = (stack_st_CONF_VALUE *)0x0;
    }
    else {
      psVar4 = _CONF_get_section_values((CONF *)pBStack_160,(char *)pBVar6);
    }
  }
  if ((BIO *)BStack_b0.init != *(BIO **)puStack_e8) {
    pcStack_d4 = CONF_get_string;
    pBVar2 = (BIO *)BStack_b0.init;
    (**(code **)(puStack_b8 + -0x5330))();
    puStack_12c = PTR___stack_chk_guard_006a9ae8;
    puStack_108 = &_gp;
    pCStack_ec = *(CONF **)PTR___stack_chk_guard_006a9ae8;
    pCStack_130 = (CONF *)&_gp_1;
    pBStack_e0 = pBStack_128;
    pBStack_dc = pBStack_160;
    if (pBVar2 == (BIO *)0x0) {
      plVar5 = (lhash_st_CONF_VALUE *)_CONF_get_string((CONF *)0x0,(char *)pBVar6,(char *)name);
      pcVar8 = (char *)pBVar6;
      if (plVar5 == (lhash_st_CONF_VALUE *)0x0) {
        plStack_110 = (long *)0x141;
        pcVar8 = &DAT_0000006d;
        (**(code **)(puStack_108 + -0x6eac))(0xe,0x6d,0x6a,"conf_lib.c");
        plVar5 = (lhash_st_CONF_VALUE *)0x0;
      }
    }
    else {
      if (default_CONF_method == (CONF_METHOD *)0x0) {
        default_CONF_method = NCONF_default();
      }
      pCStack_130 = &CStack_f8;
      (*default_CONF_method->init)(pCStack_130);
      pcVar8 = (char *)pBVar6;
      CStack_f8.data = (lhash_st_CONF_VALUE *)pBVar2;
      plVar5 = (lhash_st_CONF_VALUE *)_CONF_get_string(pCStack_130,(char *)pBVar6,(char *)name);
      pBStack_128 = pBVar2;
      pBStack_160 = pBVar6;
      if (plVar5 == (lhash_st_CONF_VALUE *)0x0) {
        plStack_110 = (long *)0x144;
        plStack_fc = plVar5;
        (**(code **)(puStack_108 + -0x6eac))(0xe,0x6d,0x6c,"conf_lib.c");
        pcVar8 = "group=";
        plStack_110 = name;
        (**(code **)(puStack_108 + -0x6ca4))(4,"group=",pBVar6," name=");
        plVar5 = plStack_fc;
      }
    }
    if (pCStack_ec == *(CONF **)puStack_12c) {
      return plVar5;
    }
    pcStack_124 = CONF_free;
    pCStack_1ac = pCStack_ec;
    (**(code **)(puStack_108 + -0x5330))();
    puStack_168 = PTR___stack_chk_guard_006a9ae8;
    puStack_148 = &_gp;
    plStack_134 = *(lhash_st_CONF_VALUE **)PTR___stack_chk_guard_006a9ae8;
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    pCStack_16c = &CStack_140;
    (*default_CONF_method->init)(pCStack_16c);
    pCStack_1a8 = pCStack_16c;
    CStack_140.data = (lhash_st_CONF_VALUE *)pCStack_1ac;
    (*(CStack_140.meth)->destroy_data)(pCStack_16c);
    plVar5 = *(lhash_st_CONF_VALUE **)puStack_168;
    if (plStack_134 == plVar5) {
      return plVar5;
    }
    pcStack_15c = CONF_dump_fp;
    (**(code **)(puStack_148 + -0x5330))();
    puStack_1b0 = PTR___stack_chk_guard_006a9ae8;
    puStack_188 = &_gp;
    plStack_174 = *(lhash_st_CONF_VALUE **)PTR___stack_chk_guard_006a9ae8;
    pCStack_164 = pCStack_1ac;
    pBStack_1b4 = (BIO *)(*(code *)PTR_BIO_new_fp_006a7248)(pcVar8,0);
    if (pBStack_1b4 == (BIO *)0x0) {
      uStack_190 = 0xcc;
      pBVar2 = (BIO *)&DAT_00000068;
      (**(code **)(puStack_188 + -0x6eac))(0xe,0x68,7,"conf_lib.c");
    }
    else {
      if (default_CONF_method == (CONF_METHOD *)0x0) {
        default_CONF_method = NCONF_default();
      }
      pCStack_1ac = &CStack_180;
      (*default_CONF_method->init)(pCStack_1ac);
      pBVar2 = pBStack_1b4;
      CStack_180.data = (lhash_st_CONF_VALUE *)pCStack_1a8;
      pBVar6 = (BIO *)(*(CStack_180.meth)->dump)(pCStack_1ac,pBStack_1b4);
      (**(code **)(puStack_188 + -0x7f70))(pBStack_1b4);
      pBStack_1b4 = pBVar6;
    }
    if (plStack_174 != *(lhash_st_CONF_VALUE **)puStack_1b0) {
      pcStack_1a4 = CONF_dump_bio;
      CStack_1c8.data = plStack_174;
      (**(code **)(puStack_188 + -0x5330))();
      puVar1 = PTR___stack_chk_guard_006a9ae8;
      pCStack_1bc = *(CONF_METHOD **)PTR___stack_chk_guard_006a9ae8;
      if (default_CONF_method == (CONF_METHOD *)0x0) {
        default_CONF_method = NCONF_default();
      }
      (*default_CONF_method->init)(&CStack_1c8);
      plVar5 = (lhash_st_CONF_VALUE *)(*(CStack_1c8.meth)->dump)(&CStack_1c8,pBVar2);
      if (pCStack_1bc != *(CONF_METHOD **)puVar1) {
        meth = pCStack_1bc;
        (*(code *)PTR___stack_chk_fail_006a9ab0)();
        if (meth == (CONF_METHOD *)0x0) {
          meth = NCONF_default();
        }
        pCVar7 = (*meth->create)(meth);
        if (pCVar7 == (CONF *)0x0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x6f,0x41,"conf_lib.c",0xed);
        }
        return (lhash_st_CONF_VALUE *)pCVar7;
      }
      return plVar5;
    }
    return (lhash_st_CONF_VALUE *)pBStack_1b4;
  }
  return (lhash_st_CONF_VALUE *)psVar4;
}

