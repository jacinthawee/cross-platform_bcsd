
undefined4
engine_table_register
          (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,int param_5,
          int param_6)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 local_3c [4];
  int *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int **)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"eng_table.c",0x87);
  if (*param_1 == 0) {
    iVar4 = (*(code *)PTR_lh_new_006a850c)(engine_pile_LHASH_HASH,engine_pile_LHASH_COMP);
    puVar1 = PTR_engine_cleanup_add_first_006aa89c;
    if (iVar4 == 0) {
LAB_00604534:
      uVar7 = 0;
      goto LAB_00604538;
    }
    *param_1 = iVar4;
    (*(code *)puVar1)(param_2);
  }
  if (param_5 != 0) {
    do {
      while( true ) {
        local_3c[0] = *param_4;
        puVar3 = (undefined4 *)(*(code *)PTR_lh_retrieve_006a84b0)(*param_1,local_3c);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x10,"eng_table.c",0x95);
          puVar1 = PTR_sk_new_null_006a80a4;
          if (puVar3 == (undefined4 *)0x0) goto LAB_00604534;
          puVar3[3] = 1;
          *puVar3 = *param_4;
          iVar4 = (*(code *)puVar1)();
          puVar3[1] = iVar4;
          puVar1 = PTR_lh_insert_006a8514;
          if (iVar4 == 0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(puVar3);
            goto LAB_00604534;
          }
          puVar3[2] = 0;
          (*(code *)puVar1)(*param_1,puVar3);
        }
        (*(code *)PTR_sk_delete_ptr_006aa020)(puVar3[1],param_3);
        iVar4 = (*(code *)PTR_sk_push_006a80a8)(puVar3[1],param_3);
        if (iVar4 == 0) goto LAB_00604534;
        puVar3[3] = 0;
        if (param_6 == 0) break;
        iVar4 = (*(code *)PTR_engine_unlocked_init_006aa898)(param_3);
        if (iVar4 == 0) {
          uVar7 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x26,0xb8,0x6d,"eng_table.c",0xae);
          goto LAB_00604538;
        }
        if (puVar3[2] != 0) {
          (*(code *)PTR_engine_unlocked_finish_006aa894)(puVar3[2],0);
        }
        param_5 = param_5 + -1;
        puVar3[2] = param_3;
        puVar3[3] = 1;
        param_4 = param_4 + 1;
        if (param_5 == 0) goto LAB_006044c0;
      }
      param_5 = param_5 + -1;
      param_4 = param_4 + 1;
    } while (param_5 != 0);
  }
LAB_006044c0:
  uVar7 = 1;
LAB_00604538:
  uVar6 = 0x1e;
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"eng_table.c",0xba);
  if (local_2c == *(int **)puVar2) {
    return uVar7;
  }
  piVar5 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"eng_table.c",0xd0);
  if (*piVar5 != 0) {
    (*(code *)PTR_lh_doall_arg_006a94bc)(*piVar5,int_unregister_cb_LHASH_DOALL_ARG,uVar6);
  }
                    /* WARNING: Could not recover jumptable at 0x00604694. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar7 = (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"eng_table.c",0xd5);
  return uVar7;
}

