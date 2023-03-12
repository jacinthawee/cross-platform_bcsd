
lhash_st_CONF_VALUE * CONF_load_bio(lhash_st_CONF_VALUE *conf,BIO *bp,long *eline)

{
  int iVar1;
  lhash_st_CONF_VALUE *plVar2;
  int in_GS_OFFSET;
  CONF local_2c;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (default_CONF_method == (CONF_METHOD *)0x0) {
    default_CONF_method = NCONF_default();
  }
  (*default_CONF_method->init)(&local_2c);
  local_2c.data = conf;
  iVar1 = (*(local_2c.meth)->load_bio)(&local_2c,bp,eline);
  plVar2 = (lhash_st_CONF_VALUE *)0x0;
  if (iVar1 != 0) {
    plVar2 = local_2c.data;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return plVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

