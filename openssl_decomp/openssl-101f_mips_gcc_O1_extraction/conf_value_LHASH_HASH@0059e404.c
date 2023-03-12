
uint conf_value_LHASH_HASH(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (*(code *)PTR_lh_strhash_006a84ac)(*param_1);
  uVar2 = (*(code *)PTR_lh_strhash_006a84ac)(param_1[1]);
  return iVar1 << 2 ^ uVar2;
}

