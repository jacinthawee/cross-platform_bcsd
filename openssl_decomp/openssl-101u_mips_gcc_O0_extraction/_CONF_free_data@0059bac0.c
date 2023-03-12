
void _CONF_free_data(CONF *conf)

{
  undefined *puVar1;
  lhash_st_CONF_VALUE *plVar2;
  
  puVar1 = PTR_lh_doall_arg_006a83a0;
  if ((conf != (CONF *)0x0) && (plVar2 = conf->data, plVar2 != (lhash_st_CONF_VALUE *)0x0)) {
    plVar2[8].dummy = 0;
    (*(code *)puVar1)(plVar2,value_free_hash_LHASH_DOALL_ARG);
    (*(code *)PTR_lh_doall_006a8490)(conf->data,value_free_stack_LHASH_DOALL);
                    /* WARNING: Could not recover jumptable at 0x0059bb30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_lh_free_006a7418)(conf->data);
    return;
  }
  return;
}

