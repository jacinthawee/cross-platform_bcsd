
/* WARNING: Removing unreachable block (ram,0x004bfddc) */
/* WARNING: Removing unreachable block (ram,0x004bfe60) */
/* WARNING: Removing unreachable block (ram,0x004bfe0c) */
/* WARNING: Removing unreachable block (ram,0x004bfe28) */
/* WARNING: Removing unreachable block (ram,0x004bfe84) */
/* WARNING: Removing unreachable block (ram,0x004bfecc) */
/* WARNING: Removing unreachable block (ram,0x004bfef0) */
/* WARNING: Removing unreachable block (ram,0x004bff7c) */
/* WARNING: Removing unreachable block (ram,0x004bff8c) */
/* WARNING: Removing unreachable block (ram,0x004bff9c) */
/* WARNING: Removing unreachable block (ram,0x004bffcc) */
/* WARNING: Removing unreachable block (ram,0x004c0010) */
/* WARNING: Removing unreachable block (ram,0x004bffdc) */
/* WARNING: Removing unreachable block (ram,0x004bff0c) */
/* WARNING: Removing unreachable block (ram,0x004c0000) */
/* WARNING: Removing unreachable block (ram,0x004bff1c) */
/* WARNING: Removing unreachable block (ram,0x004bff40) */
/* WARNING: Removing unreachable block (ram,0x004bff54) */
/* WARNING: Removing unreachable block (ram,0x004bff58) */

undefined1 * int_dup_ex_data(undefined4 param_1,int *param_2,int *param_3)

{
  undefined *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *ptr;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar2 = (undefined1 *)0x1;
  if (*param_3 != 0) {
    iVar3 = def_get_class();
    if (iVar3 == 0) {
      puVar2 = (undefined1 *)0x0;
    }
    else {
      CRYPTO_lock(5,2,"ex_data.c",0x1c9);
      iVar4 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(iVar3 + 4));
      iVar5 = (*(code *)PTR_sk_num_006a7f2c)(*param_3);
      if (iVar4 <= iVar5) {
        iVar5 = iVar4;
      }
      if (iVar5 < 1) {
        CRYPTO_lock(6,2,"ex_data.c",0x1d7);
      }
      else {
        ptr = (undefined4 *)CRYPTO_malloc(iVar5 << 2,"ex_data.c",0x1d0);
        if (ptr == (undefined4 *)0x0) {
          CRYPTO_lock(6,2,"ex_data.c",0x1d7);
          (*(code *)PTR_ERR_put_error_006a9030)(0xf,0x6a,0x41,"ex_data.c",0x1da);
          puVar2 = (undefined1 *)0x0;
          goto LAB_004c3ab4;
        }
        iVar4 = 0;
        puVar9 = ptr;
        do {
          iVar8 = iVar4 + 1;
          uVar6 = (*(code *)PTR_sk_value_006a7f24)(*(undefined4 *)(iVar3 + 4),iVar4);
          *puVar9 = uVar6;
          iVar4 = iVar8;
          puVar9 = puVar9 + 1;
        } while (iVar8 != iVar5);
        CRYPTO_lock(6,2,"ex_data.c",0x1d7);
        iVar3 = 0;
        puVar9 = ptr;
        do {
          if ((*param_3 == 0) || (iVar4 = (*(code *)PTR_sk_num_006a7f2c)(), iVar4 <= iVar3)) {
            uVar6 = 0;
          }
          else {
            uVar6 = (*(code *)PTR_sk_value_006a7f24)(*param_3,iVar3);
          }
          puVar7 = (undefined4 *)*puVar9;
          local_30 = uVar6;
          if ((puVar7 == (undefined4 *)0x0) || ((code *)puVar7[4] == (code *)0x0)) {
            iVar4 = *param_2;
            if (iVar4 == 0) goto LAB_004c3b38;
LAB_004c3a24:
            for (iVar4 = (*(code *)PTR_sk_num_006a7f2c)(iVar4); iVar4 <= iVar3; iVar4 = iVar4 + 1) {
              iVar8 = (*(code *)PTR_sk_push_006a80a8)(*param_2,0);
              if (iVar8 == 0) {
                uVar6 = 0x267;
                goto LAB_004c3a80;
              }
            }
            (*(code *)PTR_sk_set_006a9478)(*param_2,iVar3,uVar6);
          }
          else {
            (*(code *)puVar7[4])(param_2,param_3,&local_30,iVar3,*puVar7,puVar7[1]);
            iVar4 = *param_2;
            uVar6 = local_30;
            if (iVar4 != 0) goto LAB_004c3a24;
LAB_004c3b38:
            uVar6 = local_30;
            iVar4 = (*(code *)PTR_sk_new_null_006a80a4)();
            *param_2 = iVar4;
            if (iVar4 != 0) goto LAB_004c3a24;
            uVar6 = 0x25d;
LAB_004c3a80:
            (*(code *)PTR_ERR_put_error_006a9030)(0xf,0x66,0x41,"ex_data.c",uVar6);
          }
          iVar3 = iVar3 + 1;
          puVar9 = puVar9 + 1;
        } while (iVar3 != iVar5);
        CRYPTO_free(ptr);
      }
      puVar2 = (undefined1 *)0x1;
    }
  }
LAB_004c3ab4:
  if (local_2c == *(int *)puVar1) {
    return puVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (ex_data == 0) {
    CRYPTO_lock(9,2,"ex_data.c",0x10e);
    if (ex_data == 0) {
      ex_data = (*(code *)PTR_lh_new_006a850c)(ex_class_item_LHASH_HASH,ex_class_item_LHASH_COMP);
      if (ex_data == 0) {
        if (locking_callback == (code *)0x0) {
          return &_ITM_registerTMCloneTable;
        }
                    /* WARNING: Could not recover jumptable at 0x004bfdd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        puVar2 = (undefined1 *)(*locking_callback)();
        return puVar2;
      }
    }
    CRYPTO_lock(10,2,"ex_data.c",0x112);
  }
  (*(code *)PTR_lh_doall_006a95b0)(ex_data,def_cleanup_cb);
  (*(code *)PTR_lh_free_006a8518)(ex_data);
  ex_data = 0;
  impl = 0;
  return &_ITM_registerTMCloneTable;
}

