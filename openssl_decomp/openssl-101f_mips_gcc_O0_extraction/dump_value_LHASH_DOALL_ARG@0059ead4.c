
void dump_value_LHASH_DOALL_ARG(undefined4 *param_1,undefined4 param_2)

{
  if (param_1[1] != 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(param_2,"[%s] %s=%s\n",*param_1,param_1[1],param_1[2]);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0059eb38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BIO_printf_006a7f38)(param_2,&UNK_0066fa14,*param_1);
  return;
}
