
void engine_table_doall(_LHASH *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = param_2;
  local_c = param_3;
  lh_doall_arg(param_1,int_cb_LHASH_DOALL_ARG + 1,&local_10);
  return;
}

