
lhash_st_CONF_VALUE * CONF_load_bio(lhash_st_CONF_VALUE *conf,BIO *bp,long *eline)

{
  undefined *puVar1;
  int iVar2;
  stack_st_CONF_VALUE *psVar3;
  lhash_st_CONF_VALUE *plVar4;
  BIO *pBVar5;
  CONF *pCVar6;
  CONF_METHOD *meth;
  char *pcVar7;
  BIO *pBVar8;
  long *name;
  CONF CStack_180;
  CONF_METHOD *pCStack_174;
  BIO *pBStack_16c;
  undefined *puStack_168;
  CONF *pCStack_164;
  CONF *pCStack_160;
  code *pcStack_15c;
  undefined4 uStack_148;
  undefined *puStack_140;
  CONF CStack_138;
  lhash_st_CONF_VALUE *plStack_12c;
  CONF *pCStack_124;
  undefined *puStack_120;
  CONF *pCStack_11c;
  BIO *pBStack_118;
  code *pcStack_114;
  undefined *puStack_100;
  CONF CStack_f8;
  lhash_st_CONF_VALUE *plStack_ec;
  CONF *pCStack_e8;
  undefined *puStack_e4;
  BIO *pBStack_e0;
  code *pcStack_dc;
  long *plStack_c8;
  undefined *puStack_c0;
  lhash_st_CONF_VALUE *plStack_b4;
  CONF CStack_b0;
  CONF *pCStack_a4;
  undefined *puStack_a0;
  char *pcStack_9c;
  BIO *pBStack_98;
  BIO *pBStack_94;
  long *plStack_90;
  code *pcStack_8c;
  undefined4 uStack_78;
  undefined *puStack_70;
  BIO BStack_68;
  CONF local_28;
  char *local_1c;
  
  BStack_68.retry_reason = (int)PTR___stack_chk_guard_006aabf0;
  BStack_68.ex_data.sk = (stack_st_void *)&_gp;
  local_1c = *(char **)PTR___stack_chk_guard_006aabf0;
  if (default_CONF_method == (CONF_METHOD *)0x0) {
    default_CONF_method = NCONF_default();
  }
  BStack_68.flags = (int)&local_28;
  (*default_CONF_method->init)((CONF *)BStack_68.flags);
  pBVar8 = bp;
  name = eline;
  local_28.data = conf;
  iVar2 = (*(local_28.meth)->load_bio)((CONF *)BStack_68.flags,bp,eline);
  plVar4 = local_28.data;
  if (iVar2 == 0) {
    plVar4 = (lhash_st_CONF_VALUE *)0x0;
  }
  if (local_1c == *(char **)BStack_68.retry_reason) {
    return plVar4;
  }
  BStack_68.next_bio = (bio_st *)CONF_get_section;
  pcVar7 = local_1c;
  (*(code *)BStack_68.ex_data.sk[-0x429].stack.num_alloc)();
  puStack_a0 = PTR___stack_chk_guard_006aabf0;
  puStack_70 = &_gp;
  BStack_68.init = *(int *)PTR___stack_chk_guard_006aabf0;
  psVar3 = (stack_st_CONF_VALUE *)0x0;
  pcStack_9c = (char *)BStack_68.retry_reason;
  pBStack_e0 = (BIO *)conf;
  BStack_68.num = (int)conf;
  BStack_68.ptr = bp;
  if (pcVar7 != (char *)0x0) {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    bp = &BStack_68;
    (*default_CONF_method->init)((CONF *)bp);
    pcStack_9c = pcVar7;
    pBStack_e0 = pBVar8;
    BStack_68.cb_arg = pcVar7;
    if (pBVar8 == (BIO *)0x0) {
      name = (long *)&DAT_0000006b;
      uStack_78 = 0x139;
      pBVar8 = (BIO *)&DAT_0000006c;
      (**(code **)(puStack_70 + -0x6eb0))(0xe,0x6c,0x6b,"conf_lib.c");
      psVar3 = (stack_st_CONF_VALUE *)0x0;
    }
    else {
      psVar3 = _CONF_get_section_values((CONF *)bp,(char *)pBVar8);
    }
  }
  if ((BIO *)BStack_68.init == *(BIO **)puStack_a0) {
    return (lhash_st_CONF_VALUE *)psVar3;
  }
  pcStack_8c = CONF_get_string;
  pBVar5 = (BIO *)BStack_68.init;
  (**(code **)(puStack_70 + -0x5328))();
  puStack_e4 = PTR___stack_chk_guard_006aabf0;
  puStack_c0 = &_gp;
  pCStack_a4 = *(CONF **)PTR___stack_chk_guard_006aabf0;
  pCStack_e8 = (CONF *)&_ITM_registerTMCloneTable;
  pBStack_98 = pBStack_e0;
  pBStack_94 = bp;
  plStack_90 = eline;
  if (pBVar5 == (BIO *)0x0) {
    plVar4 = (lhash_st_CONF_VALUE *)_CONF_get_string((CONF *)0x0,(char *)pBVar8,(char *)name);
    pcVar7 = (char *)pBVar8;
    if (plVar4 == (lhash_st_CONF_VALUE *)0x0) {
      plStack_c8 = (long *)0x14b;
      pcVar7 = &DAT_0000006d;
      (**(code **)(puStack_c0 + -0x6eb0))(0xe,0x6d,0x6a,"conf_lib.c");
      plVar4 = (lhash_st_CONF_VALUE *)0x0;
    }
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    pCStack_e8 = &CStack_b0;
    (*default_CONF_method->init)(pCStack_e8);
    pcVar7 = (char *)pBVar8;
    CStack_b0.data = (lhash_st_CONF_VALUE *)pBVar5;
    plVar4 = (lhash_st_CONF_VALUE *)_CONF_get_string(pCStack_e8,(char *)pBVar8,(char *)name);
    pBStack_e0 = pBVar5;
    bp = pBVar8;
    if (plVar4 == (lhash_st_CONF_VALUE *)0x0) {
      plStack_c8 = (long *)0x14f;
      plStack_b4 = plVar4;
      (**(code **)(puStack_c0 + -0x6eb0))(0xe,0x6d,0x6c,"conf_lib.c");
      pcVar7 = "group=";
      plStack_c8 = name;
      (**(code **)(puStack_c0 + -0x6c7c))(4,"group=",pBVar8," name=");
      plVar4 = plStack_b4;
    }
  }
  if (pCStack_a4 != *(CONF **)puStack_e4) {
    pcStack_dc = CONF_free;
    pCStack_164 = pCStack_a4;
    (**(code **)(puStack_c0 + -0x5328))();
    puStack_120 = PTR___stack_chk_guard_006aabf0;
    puStack_100 = &_gp;
    plStack_ec = *(lhash_st_CONF_VALUE **)PTR___stack_chk_guard_006aabf0;
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    pCStack_124 = &CStack_f8;
    (*default_CONF_method->init)(pCStack_124);
    pCStack_160 = pCStack_124;
    CStack_f8.data = (lhash_st_CONF_VALUE *)pCStack_164;
    (*(CStack_f8.meth)->destroy_data)(pCStack_124);
    plVar4 = *(lhash_st_CONF_VALUE **)puStack_120;
    if (plStack_ec == plVar4) {
      return plVar4;
    }
    pcStack_114 = CONF_dump_fp;
    (**(code **)(puStack_100 + -0x5328))();
    puStack_168 = PTR___stack_chk_guard_006aabf0;
    puStack_140 = &_gp;
    plStack_12c = *(lhash_st_CONF_VALUE **)PTR___stack_chk_guard_006aabf0;
    pCStack_11c = pCStack_164;
    pBStack_118 = bp;
    pBStack_16c = (BIO *)(*(code *)PTR_BIO_new_fp_006a835c)(pcVar7,0);
    if (pBStack_16c == (BIO *)0x0) {
      uStack_148 = 0xd4;
      pBVar8 = (BIO *)&DAT_00000068;
      (**(code **)(puStack_140 + -0x6eb0))(0xe,0x68,7,"conf_lib.c");
    }
    else {
      if (default_CONF_method == (CONF_METHOD *)0x0) {
        default_CONF_method = NCONF_default();
      }
      pCStack_164 = &CStack_138;
      (*default_CONF_method->init)(pCStack_164);
      pBVar8 = pBStack_16c;
      CStack_138.data = (lhash_st_CONF_VALUE *)pCStack_160;
      pBVar5 = (BIO *)(*(CStack_138.meth)->dump)(pCStack_164,pBStack_16c);
      (**(code **)(puStack_140 + -0x7f70))(pBStack_16c);
      pBStack_16c = pBVar5;
    }
    if (plStack_12c != *(lhash_st_CONF_VALUE **)puStack_168) {
      pcStack_15c = CONF_dump_bio;
      CStack_180.data = plStack_12c;
      (**(code **)(puStack_140 + -0x5328))();
      puVar1 = PTR___stack_chk_guard_006aabf0;
      pCStack_174 = *(CONF_METHOD **)PTR___stack_chk_guard_006aabf0;
      if (default_CONF_method == (CONF_METHOD *)0x0) {
        default_CONF_method = NCONF_default();
      }
      (*default_CONF_method->init)(&CStack_180);
      plVar4 = (lhash_st_CONF_VALUE *)(*(CStack_180.meth)->dump)(&CStack_180,pBVar8);
      if (pCStack_174 != *(CONF_METHOD **)puVar1) {
        meth = pCStack_174;
        (*(code *)PTR___stack_chk_fail_006aabb8)();
        if (meth == (CONF_METHOD *)0x0) {
          meth = NCONF_default();
        }
        pCVar6 = (*meth->create)(meth);
        if (pCVar6 == (CONF *)0x0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x6f,0x41,"conf_lib.c",0xf4);
        }
        return (lhash_st_CONF_VALUE *)pCVar6;
      }
      return plVar4;
    }
    return (lhash_st_CONF_VALUE *)pBStack_16c;
  }
  return plVar4;
}

