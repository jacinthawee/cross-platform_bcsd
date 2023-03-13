
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
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int **)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"eng_table.c",0x8a);
  if (*param_1 == 0) {
    iVar4 = (*(code *)PTR_lh_new_006a740c)(engine_pile_LHASH_HASH,engine_pile_LHASH_COMP);
    puVar1 = PTR_engine_cleanup_add_first_006a9794;
    if (iVar4 == 0) {
LAB_006026c4:
      uVar7 = 0;
      goto LAB_006026c8;
    }
    *param_1 = iVar4;
    (*(code *)puVar1)(param_2);
  }
  if (param_5 != 0) {
    do {
      while( true ) {
        local_3c[0] = *param_4;
        puVar3 = (undefined4 *)(*(code *)PTR_lh_retrieve_006a73b0)(*param_1,local_3c);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x10,"eng_table.c",0x96);
          puVar1 = PTR_sk_new_null_006a6fa4;
          if (puVar3 == (undefined4 *)0x0) goto LAB_006026c4;
          puVar3[3] = 1;
          *puVar3 = *param_4;
          iVar4 = (*(code *)puVar1)();
          puVar3[1] = iVar4;
          puVar1 = PTR_lh_insert_006a7414;
          if (iVar4 == 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)(puVar3);
            goto LAB_006026c4;
          }
          puVar3[2] = 0;
          (*(code *)puVar1)(*param_1,puVar3);
        }
        (*(code *)PTR_sk_delete_ptr_006a8f00)(puVar3[1],param_3);
        iVar4 = (*(code *)PTR_sk_push_006a6fa8)(puVar3[1],param_3);
        if (iVar4 == 0) goto LAB_006026c4;
        puVar3[3] = 0;
        if (param_6 == 0) break;
        iVar4 = (*(code *)PTR_engine_unlocked_init_006a9790)(param_3);
        if (iVar4 == 0) {
          uVar7 = 0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x26,0xb8,0x6d,"eng_table.c",0xaf);
          goto LAB_006026c8;
        }
        if (puVar3[2] != 0) {
          (*(code *)PTR_engine_unlocked_finish_006a978c)(puVar3[2],0);
        }
        param_5 = param_5 + -1;
        puVar3[2] = param_3;
        puVar3[3] = 1;
        param_4 = param_4 + 1;
        if (param_5 == 0) goto LAB_00602650;
      }
      param_5 = param_5 + -1;
      param_4 = param_4 + 1;
    } while (param_5 != 0);
  }
LAB_00602650:
  uVar7 = 1;
LAB_006026c8:
  uVar6 = 0x1e;
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_table.c",0xbb);
  if (local_2c == *(int **)puVar2) {
    return uVar7;
  }
  piVar5 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"eng_table.c",0xd1);
  if (*piVar5 != 0) {
    (*(code *)PTR_lh_doall_arg_006a83a0)(*piVar5,int_unregister_cb_LHASH_DOALL_ARG,uVar6);
  }
                    /* WARNING: Could not recover jumptable at 0x00602824. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar7 = (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_table.c",0xd6);
  return uVar7;
}

