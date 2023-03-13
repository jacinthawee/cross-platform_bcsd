
void do_all_fn_LHASH_DOALL_ARG(int *param_1,int *param_2)

{
  if (*param_1 != *param_2) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x080d3507. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_2[1])();
  return;
}

