
lhash_st_CONF_VALUE * CONF_load(lhash_st_CONF_VALUE *conf,char *file,long *eline)

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
  CONF CStack_210;
  CONF_METHOD *pCStack_204;
  BIO *pBStack_1fc;
  undefined *puStack_1f8;
  CONF *pCStack_1f4;
  CONF *pCStack_1f0;
  code *pcStack_1ec;
  undefined4 uStack_1d8;
  undefined *puStack_1d0;
  CONF CStack_1c8;
  lhash_st_CONF_VALUE *plStack_1bc;
  CONF *pCStack_1b4;
  undefined *puStack_1b0;
  CONF *pCStack_1ac;
  BIO *pBStack_1a8;
  code *pcStack_1a4;
  undefined *puStack_190;
  CONF CStack_188;
  lhash_st_CONF_VALUE *plStack_17c;
  CONF *pCStack_178;
  undefined *puStack_174;
  BIO *pBStack_170;
  code *pcStack_16c;
  long *plStack_158;
  undefined *puStack_150;
  lhash_st_CONF_VALUE *plStack_144;
  CONF CStack_140;
  CONF *pCStack_134;
  undefined *puStack_130;
  char *pcStack_12c;
  BIO *pBStack_128;
  BIO *pBStack_124;
  long *plStack_120;
  code *pcStack_11c;
  undefined4 uStack_108;
  undefined *puStack_100;
  BIO BStack_f8;
  CONF CStack_b8;
  char *pcStack_ac;
  lhash_st_CONF_VALUE *plStack_a8;
  BIO *pBStack_a4;
  undefined *puStack_a0;
  lhash_st_CONF_VALUE *plStack_9c;
  long *plStack_98;
  code *pcStack_94;
  undefined4 uStack_80;
  undefined *puStack_78;
  CONF CStack_70;
  BIO *pBStack_64;
  lhash_st_CONF_VALUE *plStack_60;
  BIO *pBStack_5c;
  undefined *puStack_58;
  lhash_st_CONF_VALUE *plStack_54;
  long *plStack_50;
  code *pcStack_4c;
  undefined4 local_38;
  undefined *local_30;
  CONF local_28;
  lhash_st_CONF_VALUE *local_1c;
  
  puStack_58 = PTR___stack_chk_guard_006aabf0;
  local_30 = &_gp;
  local_1c = *(lhash_st_CONF_VALUE **)PTR___stack_chk_guard_006aabf0;
  pBVar2 = (BIO *)(*(code *)PTR_BIO_new_file_006a7fac)(file,&DAT_006347ac);
  if (pBVar2 == (BIO *)0x0) {
    plStack_98 = (long *)&SUB_00000002;
    local_38 = 0x67;
    pBVar6 = (BIO *)&DAT_00000064;
    plStack_60 = (lhash_st_CONF_VALUE *)0x0;
    (**(code **)(local_30 + -0x6eb0))(0xe,100,2,"conf_lib.c");
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    (*default_CONF_method->init)(&local_28);
    pBVar6 = pBVar2;
    plStack_98 = eline;
    local_28.data = conf;
    iVar3 = (*(local_28.meth)->load_bio)(&local_28,pBVar2,eline);
    plStack_60 = local_28.data;
    if (iVar3 == 0) {
      plStack_60 = (lhash_st_CONF_VALUE *)0x0;
    }
    (**(code **)(local_30 + -0x7f70))(pBVar2);
    unaff_s1 = pBVar2;
  }
  if (local_1c == *(lhash_st_CONF_VALUE **)puStack_58) {
    return plStack_60;
  }
  pcStack_4c = CONF_load_fp;
  plStack_9c = local_1c;
  (**(code **)(local_30 + -0x5328))();
  puStack_a0 = PTR___stack_chk_guard_006aabf0;
  puStack_78 = &_gp;
  pBStack_64 = *(BIO **)PTR___stack_chk_guard_006aabf0;
  pBStack_5c = unaff_s1;
  plStack_54 = conf;
  plStack_50 = eline;
  pBVar2 = (BIO *)(*(code *)PTR_BIO_new_fp_006a835c)(pBVar6,0);
  if (pBVar2 == (BIO *)0x0) {
    plStack_120 = (long *)&DAT_00000007;
    uStack_80 = 0x78;
    pBStack_1a8 = (BIO *)0x67;
    plStack_a8 = (lhash_st_CONF_VALUE *)0x0;
    (**(code **)(puStack_78 + -0x6eb0))(0xe,0x67,7,"conf_lib.c");
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    (*default_CONF_method->init)(&CStack_70);
    pBStack_1a8 = pBVar2;
    plStack_120 = plStack_98;
    CStack_70.data = plStack_9c;
    iVar3 = (*(CStack_70.meth)->load_bio)(&CStack_70,pBVar2,plStack_98);
    plStack_a8 = CStack_70.data;
    if (iVar3 == 0) {
      plStack_a8 = (lhash_st_CONF_VALUE *)0x0;
    }
    (**(code **)(puStack_78 + -0x7f70))(pBVar2);
    unaff_s1 = pBVar2;
  }
  if (pBStack_64 == *(BIO **)puStack_a0) {
    return plStack_a8;
  }
  pcStack_94 = CONF_load_bio;
  BStack_f8.num = (int)pBStack_64;
  (**(code **)(puStack_78 + -0x5328))();
  BStack_f8.retry_reason = (int)PTR___stack_chk_guard_006aabf0;
  BStack_f8.ex_data.sk = (stack_st_void *)&_gp;
  pcStack_ac = *(char **)PTR___stack_chk_guard_006aabf0;
  pBStack_a4 = unaff_s1;
  if (default_CONF_method == (CONF_METHOD *)0x0) {
    default_CONF_method = NCONF_default();
  }
  BStack_f8.flags = (int)&CStack_b8;
  (*default_CONF_method->init)((CONF *)BStack_f8.flags);
  pBVar6 = pBStack_1a8;
  name = plStack_120;
  CStack_b8.data = (lhash_st_CONF_VALUE *)BStack_f8.num;
  iVar3 = (*(CStack_b8.meth)->load_bio)((CONF *)BStack_f8.flags,pBStack_1a8,plStack_120);
  pBVar2 = (BIO *)CStack_b8.data;
  if (iVar3 == 0) {
    pBVar2 = (BIO *)0x0;
  }
  if (pcStack_ac == *(char **)BStack_f8.retry_reason) {
    return (lhash_st_CONF_VALUE *)pBVar2;
  }
  BStack_f8.next_bio = (bio_st *)CONF_get_section;
  pcVar8 = pcStack_ac;
  (*(code *)BStack_f8.ex_data.sk[-0x429].stack.num_alloc)();
  puStack_130 = PTR___stack_chk_guard_006aabf0;
  puStack_100 = &_gp;
  BStack_f8.init = *(int *)PTR___stack_chk_guard_006aabf0;
  psVar4 = (stack_st_CONF_VALUE *)0x0;
  pcStack_12c = (char *)BStack_f8.retry_reason;
  pBStack_170 = (BIO *)BStack_f8.num;
  BStack_f8.ptr = pBStack_1a8;
  if (pcVar8 != (char *)0x0) {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    pBStack_1a8 = &BStack_f8;
    (*default_CONF_method->init)((CONF *)pBStack_1a8);
    pcStack_12c = pcVar8;
    pBStack_170 = pBVar6;
    BStack_f8.cb_arg = pcVar8;
    if (pBVar6 == (BIO *)0x0) {
      name = (long *)&DAT_0000006b;
      uStack_108 = 0x139;
      pBVar6 = (BIO *)&DAT_0000006c;
      (**(code **)(puStack_100 + -0x6eb0))(0xe,0x6c,0x6b,"conf_lib.c");
      psVar4 = (stack_st_CONF_VALUE *)0x0;
    }
    else {
      psVar4 = _CONF_get_section_values((CONF *)pBStack_1a8,(char *)pBVar6);
    }
  }
  if ((BIO *)BStack_f8.init != *(BIO **)puStack_130) {
    pcStack_11c = CONF_get_string;
    pBVar2 = (BIO *)BStack_f8.init;
    (**(code **)(puStack_100 + -0x5328))();
    puStack_174 = PTR___stack_chk_guard_006aabf0;
    puStack_150 = &_gp;
    pCStack_134 = *(CONF **)PTR___stack_chk_guard_006aabf0;
    pCStack_178 = (CONF *)&_ITM_registerTMCloneTable;
    pBStack_128 = pBStack_170;
    pBStack_124 = pBStack_1a8;
    if (pBVar2 == (BIO *)0x0) {
      plVar5 = (lhash_st_CONF_VALUE *)_CONF_get_string((CONF *)0x0,(char *)pBVar6,(char *)name);
      pcVar8 = (char *)pBVar6;
      if (plVar5 == (lhash_st_CONF_VALUE *)0x0) {
        plStack_158 = (long *)0x14b;
        pcVar8 = &DAT_0000006d;
        (**(code **)(puStack_150 + -0x6eb0))(0xe,0x6d,0x6a,"conf_lib.c");
        plVar5 = (lhash_st_CONF_VALUE *)0x0;
      }
    }
    else {
      if (default_CONF_method == (CONF_METHOD *)0x0) {
        default_CONF_method = NCONF_default();
      }
      pCStack_178 = &CStack_140;
      (*default_CONF_method->init)(pCStack_178);
      pcVar8 = (char *)pBVar6;
      CStack_140.data = (lhash_st_CONF_VALUE *)pBVar2;
      plVar5 = (lhash_st_CONF_VALUE *)_CONF_get_string(pCStack_178,(char *)pBVar6,(char *)name);
      pBStack_170 = pBVar2;
      pBStack_1a8 = pBVar6;
      if (plVar5 == (lhash_st_CONF_VALUE *)0x0) {
        plStack_158 = (long *)0x14f;
        plStack_144 = plVar5;
        (**(code **)(puStack_150 + -0x6eb0))(0xe,0x6d,0x6c,"conf_lib.c");
        pcVar8 = "group=";
        plStack_158 = name;
        (**(code **)(puStack_150 + -0x6c7c))(4,"group=",pBVar6," name=");
        plVar5 = plStack_144;
      }
    }
    if (pCStack_134 == *(CONF **)puStack_174) {
      return plVar5;
    }
    pcStack_16c = CONF_free;
    pCStack_1f4 = pCStack_134;
    (**(code **)(puStack_150 + -0x5328))();
    puStack_1b0 = PTR___stack_chk_guard_006aabf0;
    puStack_190 = &_gp;
    plStack_17c = *(lhash_st_CONF_VALUE **)PTR___stack_chk_guard_006aabf0;
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    pCStack_1b4 = &CStack_188;
    (*default_CONF_method->init)(pCStack_1b4);
    pCStack_1f0 = pCStack_1b4;
    CStack_188.data = (lhash_st_CONF_VALUE *)pCStack_1f4;
    (*(CStack_188.meth)->destroy_data)(pCStack_1b4);
    plVar5 = *(lhash_st_CONF_VALUE **)puStack_1b0;
    if (plStack_17c == plVar5) {
      return plVar5;
    }
    pcStack_1a4 = CONF_dump_fp;
    (**(code **)(puStack_190 + -0x5328))();
    puStack_1f8 = PTR___stack_chk_guard_006aabf0;
    puStack_1d0 = &_gp;
    plStack_1bc = *(lhash_st_CONF_VALUE **)PTR___stack_chk_guard_006aabf0;
    pCStack_1ac = pCStack_1f4;
    pBStack_1fc = (BIO *)(*(code *)PTR_BIO_new_fp_006a835c)(pcVar8,0);
    if (pBStack_1fc == (BIO *)0x0) {
      uStack_1d8 = 0xd4;
      pBVar2 = (BIO *)&DAT_00000068;
      (**(code **)(puStack_1d0 + -0x6eb0))(0xe,0x68,7,"conf_lib.c");
    }
    else {
      if (default_CONF_method == (CONF_METHOD *)0x0) {
        default_CONF_method = NCONF_default();
      }
      pCStack_1f4 = &CStack_1c8;
      (*default_CONF_method->init)(pCStack_1f4);
      pBVar2 = pBStack_1fc;
      CStack_1c8.data = (lhash_st_CONF_VALUE *)pCStack_1f0;
      pBVar6 = (BIO *)(*(CStack_1c8.meth)->dump)(pCStack_1f4,pBStack_1fc);
      (**(code **)(puStack_1d0 + -0x7f70))(pBStack_1fc);
      pBStack_1fc = pBVar6;
    }
    if (plStack_1bc != *(lhash_st_CONF_VALUE **)puStack_1f8) {
      pcStack_1ec = CONF_dump_bio;
      CStack_210.data = plStack_1bc;
      (**(code **)(puStack_1d0 + -0x5328))();
      puVar1 = PTR___stack_chk_guard_006aabf0;
      pCStack_204 = *(CONF_METHOD **)PTR___stack_chk_guard_006aabf0;
      if (default_CONF_method == (CONF_METHOD *)0x0) {
        default_CONF_method = NCONF_default();
      }
      (*default_CONF_method->init)(&CStack_210);
      plVar5 = (lhash_st_CONF_VALUE *)(*(CStack_210.meth)->dump)(&CStack_210,pBVar2);
      if (pCStack_204 != *(CONF_METHOD **)puVar1) {
        meth = pCStack_204;
        (*(code *)PTR___stack_chk_fail_006aabb8)();
        if (meth == (CONF_METHOD *)0x0) {
          meth = NCONF_default();
        }
        pCVar7 = (*meth->create)(meth);
        if (pCVar7 == (CONF *)0x0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x6f,0x41,"conf_lib.c",0xf4);
        }
        return (lhash_st_CONF_VALUE *)pCVar7;
      }
      return plVar5;
    }
    return (lhash_st_CONF_VALUE *)pBStack_1fc;
  }
  return (lhash_st_CONF_VALUE *)psVar4;
}

