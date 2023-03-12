
int OBJ_NAME_new_index(hash_func *hash_func,cmp_func *cmp_func,free_func *free_func)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 *puVar5;
  hash_func **pphVar6;
  
  if (name_funcs_stack == 0) {
    CRYPTO_mem_ctrl(3);
    name_funcs_stack = (*(code *)PTR_sk_new_null_006a80a4)();
    CRYPTO_mem_ctrl(2);
    if (name_funcs_stack == 0) {
      return 0;
    }
  }
  iVar1 = names_type_num;
  names_type_num = names_type_num + 1;
  iVar4 = (*(code *)PTR_sk_num_006a7f2c)();
  puVar3 = PTR_strcmp_006aac20;
  puVar2 = PTR_lh_strhash_006a84ac;
  if (iVar4 < names_type_num) {
    do {
      iVar4 = iVar4 + 1;
      CRYPTO_mem_ctrl(3);
      puVar5 = (undefined4 *)CRYPTO_malloc(0xc,"o_names.c",0x56);
      CRYPTO_mem_ctrl(2);
      if (puVar5 == (undefined4 *)0x0) {
        (*(code *)PTR_ERR_put_error_006a9030)(8,0x6a,0x41,"o_names.c",0x5a);
        return 0;
      }
      *puVar5 = puVar2;
      puVar5[1] = puVar3;
      puVar5[2] = 0;
      CRYPTO_mem_ctrl(3);
      (*(code *)PTR_sk_push_006a80a8)(name_funcs_stack,puVar5);
      CRYPTO_mem_ctrl(2);
    } while (iVar4 < names_type_num);
  }
  pphVar6 = (hash_func **)(*(code *)PTR_sk_value_006a7f24)(name_funcs_stack,iVar1);
  if (hash_func != (hash_func *)0x0) {
    *pphVar6 = hash_func;
  }
  if (cmp_func != (cmp_func *)0x0) {
    pphVar6[1] = (hash_func *)cmp_func;
  }
  if (free_func == (free_func *)0x0) {
    return iVar1;
  }
  pphVar6[2] = (hash_func *)free_func;
  return iVar1;
}

