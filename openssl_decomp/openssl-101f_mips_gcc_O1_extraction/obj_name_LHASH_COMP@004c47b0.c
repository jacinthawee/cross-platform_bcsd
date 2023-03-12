
void obj_name_LHASH_COMP(int *param_1,int *param_2)

{
  int iVar1;
  
  if (*param_1 != *param_2) {
    return;
  }
  if (name_funcs_stack != 0) {
    iVar1 = (*(code *)PTR_sk_num_006a7f2c)();
    if (*param_1 < iVar1) {
      iVar1 = (*(code *)PTR_sk_value_006a7f24)(name_funcs_stack);
                    /* WARNING: Could not recover jumptable at 0x004c4868. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar1 + 4))(param_1[2],param_2[2]);
      return;
    }
  }
  (*(code *)PTR_strcmp_006aac20)(param_1[2],param_2[2]);
  return;
}

