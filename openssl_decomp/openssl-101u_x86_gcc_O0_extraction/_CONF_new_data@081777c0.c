
int _CONF_new_data(CONF *conf)

{
  uint uVar1;
  _LHASH *p_Var2;
  
  if (conf != (CONF *)0x0) {
    uVar1 = 1;
    if (conf->data == (lhash_st_CONF_VALUE *)0x0) {
      p_Var2 = lh_new(conf_value_LHASH_HASH,conf_value_LHASH_COMP);
      conf->data = (lhash_st_CONF_VALUE *)p_Var2;
      uVar1 = (uint)(p_Var2 != (_LHASH *)0x0);
    }
    return uVar1;
  }
  return 0;
}

