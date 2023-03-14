
int CONF_dump_fp(lhash_st_CONF_VALUE *conf,FILE *out)

{
  BIO *bp;
  int iVar1;
  int in_GS_OFFSET;
  CONF local_1c;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  bp = BIO_new_fp(out,0);
  if (bp == (BIO *)0x0) {
    iVar1 = 0;
    ERR_put_error(0xe,0x68,7,"conf_lib.c",0xcc);
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    (*default_CONF_method->init)(&local_1c);
    local_1c.data = conf;
    iVar1 = (*(local_1c.meth)->dump)(&local_1c,bp);
    BIO_free(bp);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
