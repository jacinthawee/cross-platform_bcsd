
uint obj_name_LHASH_HASH(uint *param_1)

{
  int iVar1;
  ulong uVar2;
  code **ppcVar3;
  uint uVar4;
  
  if (name_funcs_stack != (_STACK *)0x0) {
    iVar1 = sk_num(name_funcs_stack);
    if ((int)*param_1 < iVar1) {
      ppcVar3 = (code **)sk_value(name_funcs_stack,*param_1);
      uVar4 = (**ppcVar3)(param_1[2]);
      return uVar4 ^ *param_1;
    }
  }
  uVar2 = lh_strhash((char *)param_1[2]);
  return uVar2 ^ *param_1;
}

