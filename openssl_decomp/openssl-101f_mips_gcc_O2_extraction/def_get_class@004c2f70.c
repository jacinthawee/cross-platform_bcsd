
undefined4 * def_get_class(undefined4 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  void *ptr;
  undefined4 local_28 [3];
  void *local_1c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(void **)PTR___stack_chk_guard_006aabf0;
  if (ex_data == 0) {
    CRYPTO_lock(9,2,"ex_data.c",0x10e);
    if (ex_data == 0) {
      ex_data = (*(code *)PTR_lh_new_006a850c)(ex_class_item_LHASH_HASH,ex_class_item_LHASH_COMP);
      if (ex_data == 0) {
        CRYPTO_lock(10,2,"ex_data.c",0x112);
        puVar3 = (undefined4 *)0x0;
        goto LAB_004c3014;
      }
    }
    CRYPTO_lock(10,2,"ex_data.c",0x112);
  }
  local_28[0] = param_1;
  CRYPTO_lock(9,2,"ex_data.c",0x130);
  puVar3 = (undefined4 *)(*(code *)PTR_lh_retrieve_006a84b0)(ex_data,local_28);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)CRYPTO_malloc(0xc,"ex_data.c",0x134);
    puVar1 = PTR_sk_new_null_006a80a4;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = param_1;
      puVar3[2] = 0;
      iVar4 = (*(code *)puVar1)();
      puVar3[1] = iVar4;
      if (iVar4 != 0) {
        (*(code *)PTR_lh_insert_006a8514)(ex_data,puVar3);
        goto LAB_004c2ff4;
      }
      CRYPTO_free(puVar3);
    }
    CRYPTO_lock(10,2,"ex_data.c",0x145);
    (*(code *)PTR_ERR_put_error_006a9030)(0xf,0x69,0x41,"ex_data.c",0x147);
    puVar3 = (undefined4 *)0x0;
  }
  else {
LAB_004c2ff4:
    CRYPTO_lock(10,2,"ex_data.c",0x145);
  }
LAB_004c3014:
  if (local_1c == *(void **)puVar2) {
    return puVar3;
  }
  ptr = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar3 = (undefined4 *)
           (*(code *)PTR_sk_pop_free_006a8158)(*(undefined4 *)((int)ptr + 4),def_cleanup_util_cb);
  CRYPTO_free(ptr);
  return puVar3;
}

