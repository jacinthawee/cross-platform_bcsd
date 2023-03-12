
int OBJ_NAME_add(char *name,int type,char *data)

{
  undefined *puVar1;
  uint *puVar2;
  int *ptr;
  int iVar3;
  
  if (names_lh == 0) {
    CRYPTO_mem_ctrl(3);
    names_lh = (*(code *)PTR_lh_new_006a740c)(obj_name_LHASH_HASH,obj_name_LHASH_COMP);
    CRYPTO_mem_ctrl(2);
    if (names_lh == 0) {
      return 0;
    }
  }
  puVar2 = (uint *)CRYPTO_malloc(0x10,"o_names.c",0xbf);
  iVar3 = names_lh;
  puVar1 = PTR_lh_insert_006a7414;
  if (puVar2 == (uint *)0x0) {
    return 0;
  }
  *puVar2 = type & 0xffff7fff;
  puVar2[2] = (uint)name;
  puVar2[1] = type & 0x8000;
  puVar2[3] = (uint)data;
  ptr = (int *)(*(code *)puVar1)(iVar3,puVar2);
  if (ptr == (int *)0x0) {
    return (uint)(*(int *)(names_lh + 0x5c) == 0);
  }
  if ((name_funcs_stack != 0) && (iVar3 = (*(code *)PTR_sk_num_006a6e2c)(), *ptr < iVar3)) {
    iVar3 = (*(code *)PTR_sk_value_006a6e24)(name_funcs_stack);
    (**(code **)(iVar3 + 8))(ptr[2],*ptr,ptr[3]);
  }
  CRYPTO_free(ptr);
  return 1;
}

