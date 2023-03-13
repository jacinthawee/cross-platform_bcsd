
void _CONF_free_data(CONF *conf)

{
  _LHASH *lh;
  
  if ((conf != (CONF *)0x0) && (lh = (_LHASH *)conf->data, lh != (_LHASH *)0x0)) {
    lh->down_load = 0;
    lh_doall_arg(lh,value_free_hash_LHASH_DOALL_ARG,lh);
    lh_doall((_LHASH *)conf->data,value_free_stack_LHASH_DOALL);
    lh_free((_LHASH *)conf->data);
    return;
  }
  return;
}

