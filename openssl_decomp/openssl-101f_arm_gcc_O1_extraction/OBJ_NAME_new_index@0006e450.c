
int OBJ_NAME_new_index(hash_func *hash_func,cmp_func *cmp_func,free_func *free_func)

{
  int iVar1;
  int iVar2;
  undefined4 *data;
  hash_func **pphVar3;
  
  if (name_funcs_stack == (_STACK *)0x0) {
    CRYPTO_mem_ctrl(3);
    name_funcs_stack = sk_new_null();
    CRYPTO_mem_ctrl(2);
    if (name_funcs_stack == (_STACK *)0x0) {
      return 0;
    }
  }
  iVar1 = names_type_num;
  names_type_num = names_type_num + 1;
  iVar2 = sk_num(name_funcs_stack);
  if (iVar2 < names_type_num) {
    do {
      iVar2 = iVar2 + 1;
      CRYPTO_mem_ctrl(3);
      data = (undefined4 *)CRYPTO_malloc(0xc,"o_names.c",0x56);
      CRYPTO_mem_ctrl(2);
      if (data == (undefined4 *)0x0) {
        ERR_put_error(8,0x6a,0x41,"o_names.c",0x5a);
        return 0;
      }
      data[2] = 0;
      *data = 0xa59d9;
      data[1] = strcmp;
      CRYPTO_mem_ctrl(3);
      sk_push(name_funcs_stack,data);
      CRYPTO_mem_ctrl(2);
    } while (iVar2 < names_type_num);
  }
  pphVar3 = (hash_func **)sk_value(name_funcs_stack,iVar1);
  if (hash_func != (hash_func *)0x0) {
    *pphVar3 = hash_func;
  }
  if (cmp_func != (cmp_func *)0x0) {
    pphVar3[1] = (hash_func *)cmp_func;
  }
  if (free_func == (free_func *)0x0) {
    return iVar1;
  }
  pphVar3[2] = (hash_func *)free_func;
  return iVar1;
}

