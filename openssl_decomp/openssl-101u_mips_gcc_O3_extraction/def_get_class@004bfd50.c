
undefined4 * def_get_class(undefined4 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  void *ptr;
  undefined4 local_28 [3];
  void *local_1c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(void **)PTR___stack_chk_guard_006a9ae8;
  if (ex_data == 0) {
    CRYPTO_lock(9,2,"ex_data.c",0x116);
    if (ex_data == 0) {
      ex_data = (*(code *)PTR_lh_new_006a740c)(ex_class_item_LHASH_HASH,ex_class_item_LHASH_COMP);
      if (ex_data == 0) {
        CRYPTO_lock(10,2,"ex_data.c",0x119);
        puVar3 = (undefined4 *)0x0;
        goto LAB_004bfdf4;
      }
    }
    CRYPTO_lock(10,2,"ex_data.c",0x119);
  }
  local_28[0] = param_1;
  CRYPTO_lock(9,2,"ex_data.c",0x13e);
  puVar3 = (undefined4 *)(*(code *)PTR_lh_retrieve_006a73b0)(ex_data,local_28);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)CRYPTO_malloc(0xc,"ex_data.c",0x141);
    puVar1 = PTR_sk_new_null_006a6fa4;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = param_1;
      puVar3[2] = 0;
      iVar4 = (*(code *)puVar1)();
      puVar3[1] = iVar4;
      if (iVar4 != 0) {
        (*(code *)PTR_lh_insert_006a7414)(ex_data,puVar3);
        goto LAB_004bfdd4;
      }
      CRYPTO_free(puVar3);
    }
    CRYPTO_lock(10,2,"ex_data.c",0x152);
    (*(code *)PTR_ERR_put_error_006a7f34)(0xf,0x69,0x41,"ex_data.c",0x154);
    puVar3 = (undefined4 *)0x0;
  }
  else {
LAB_004bfdd4:
    CRYPTO_lock(10,2,"ex_data.c",0x152);
  }
LAB_004bfdf4:
  if (local_1c == *(void **)puVar2) {
    return puVar3;
  }
  ptr = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar3 = (undefined4 *)
           (*(code *)PTR_sk_pop_free_006a7058)(*(undefined4 *)((int)ptr + 4),def_cleanup_util_cb);
  CRYPTO_free(ptr);
  return puVar3;
}

