
void do_all_fn_LHASH_DOALL_ARG(int *param_1,int *param_2)

{
  if (*param_1 != *param_2) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0006e37a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_2[1])(param_1,param_2[2]);
  return;
}

