
uint names_lh_free_LHASH_DOALL(uint *param_1)

{
  undefined *puVar1;
  int *ptr;
  int iVar2;
  uint local_24 [2];
  uint local_1c;
  uint local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(uint *)PTR___stack_chk_guard_006aabf0;
  if ((param_1 != (uint *)0x0) &&
     ((((int)free_type < 0 || (free_type == *param_1)) && (names_lh != 0)))) {
    local_1c = param_1[2];
    local_24[0] = *param_1 & 0xffff7fff;
    ptr = (int *)(*(code *)PTR_lh_delete_006a94ac)(names_lh,local_24);
    if (ptr != (int *)0x0) {
      if ((name_funcs_stack != 0) && (iVar2 = (*(code *)PTR_sk_num_006a7f2c)(), *ptr < iVar2)) {
        iVar2 = (*(code *)PTR_sk_value_006a7f24)(name_funcs_stack);
        (**(code **)(iVar2 + 8))(ptr[2],*ptr,ptr[3]);
      }
      CRYPTO_free(ptr);
    }
  }
  if (local_14 != *(uint *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    if (names_lh == 0) {
      CRYPTO_mem_ctrl(3);
      names_lh = (*(code *)PTR_lh_new_006a850c)(obj_name_LHASH_HASH,obj_name_LHASH_COMP);
      CRYPTO_mem_ctrl(2);
      return (uint)(names_lh != 0);
    }
    return 1;
  }
  return *(uint *)puVar1;
}

