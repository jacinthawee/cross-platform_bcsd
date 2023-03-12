
void CONF_free(lhash_st_CONF_VALUE *conf)

{
  int in_GS_OFFSET;
  CONF local_1c;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (default_CONF_method == (CONF_METHOD *)0x0) {
    default_CONF_method = NCONF_default();
  }
  (*default_CONF_method->init)(&local_1c);
  local_1c.data = conf;
  (*(local_1c.meth)->destroy_data)(&local_1c);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

