
uint obj_name_LHASH_HASH(uint *param_1)

{
  int iVar1;
  uint uVar2;
  code **ppcVar3;
  
  if (name_funcs_stack != 0) {
    iVar1 = (*(code *)PTR_sk_num_006a7f2c)();
    if ((int)*param_1 < iVar1) {
      ppcVar3 = (code **)(*(code *)PTR_sk_value_006a7f24)(name_funcs_stack);
      uVar2 = (**ppcVar3)(param_1[2]);
      return uVar2 ^ *param_1;
    }
  }
  uVar2 = (*(code *)PTR_lh_strhash_006a84ac)(param_1[2]);
  return uVar2 ^ *param_1;
}

