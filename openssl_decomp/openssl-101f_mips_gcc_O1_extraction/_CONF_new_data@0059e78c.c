
int _CONF_new_data(CONF *conf)

{
  lhash_st_CONF_VALUE *plVar1;
  undefined4 in_a2;
  undefined4 in_a3;
  
  if (conf == (CONF *)0x0) {
    return 0;
  }
  if (conf->data != (lhash_st_CONF_VALUE *)0x0) {
    return 1;
  }
  plVar1 = (lhash_st_CONF_VALUE *)
           (*(code *)PTR_lh_new_006a850c)
                     (conf_value_LHASH_HASH,conf_value_LHASH_COMP,in_a2,in_a3,&_gp);
  conf->data = plVar1;
  return (uint)(plVar1 != (lhash_st_CONF_VALUE *)0x0);
}

