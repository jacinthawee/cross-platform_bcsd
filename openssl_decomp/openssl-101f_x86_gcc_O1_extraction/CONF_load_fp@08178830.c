
lhash_st_CONF_VALUE * CONF_load_fp(lhash_st_CONF_VALUE *conf,FILE *fp,long *eline)

{
  BIO *bp;
  int iVar1;
  lhash_st_CONF_VALUE *plVar2;
  int in_GS_OFFSET;
  CONF local_2c;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bp = BIO_new_fp(fp,0);
  if (bp == (BIO *)0x0) {
    plVar2 = (lhash_st_CONF_VALUE *)0x0;
    ERR_put_error(0xe,0x67,7,"conf_lib.c",0x78);
  }
  else {
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
    BIO_free(bp);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return plVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

