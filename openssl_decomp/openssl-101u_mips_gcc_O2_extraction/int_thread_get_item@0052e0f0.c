
undefined1 * int_thread_get_item(void *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  void *pvVar4;
  ulong uVar5;
  int iVar6;
  _LHASH *p_Stack_90;
  undefined1 *puStack_8c;
  undefined1 *puStack_88;
  undefined *puStack_84;
  undefined *puStack_80;
  void *pvStack_7c;
  _LHASH *p_Stack_58;
  void *pvStack_54;
  undefined1 *puStack_4c;
  undefined *puStack_48;
  undefined *puStack_44;
  void *pvStack_40;
  code *pcStack_3c;
  undefined *local_28;
  _LHASH *local_20;
  void *local_1c;
  
  puStack_44 = PTR___stack_chk_guard_006a9ae8;
  local_28 = &_gp;
  local_1c = *(void **)PTR___stack_chk_guard_006a9ae8;
  puStack_4c = CAST_S_table3 + 0x110;
  if (err_fns == (undefined1 *)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
    if (err_fns == (undefined1 *)0x0) {
      err_fns = err_defaults;
    }
    (**(code **)(local_28 + -0x6c9c))(10,1,"err.c",0x12a);
  }
  local_20 = (_LHASH *)(**(code **)(err_fns + 0x14))(0);
  if (local_20 == (_LHASH *)0x0) {
    puVar3 = (undefined1 *)0x0;
  }
  else {
    (**(code **)(local_28 + -0x6c9c))(5,1,"err.c",499);
    puVar3 = (undefined1 *)lh_retrieve(local_20,param_1);
    (**(code **)(local_28 + -0x6c9c))(6,1,"err.c",0x1f5);
    (**(code **)(err_fns + 0x18))(&local_20);
    puStack_4c = puVar3;
  }
  if (local_1c == *(void **)puStack_44) {
    return puVar3;
  }
  pcStack_3c = int_thread_set_item;
  pvStack_7c = local_1c;
  (**(code **)(local_28 + -0x5330))();
  puStack_80 = PTR___stack_chk_guard_006a9ae8;
  puStack_48 = &_gp_1;
  pvStack_54 = *(void **)PTR___stack_chk_guard_006a9ae8;
  puStack_88 = CAST_S_table3 + 0x110;
  pvStack_40 = param_1;
  if (err_fns == (undefined1 *)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
    if (err_fns == (undefined1 *)0x0) {
      err_fns = err_defaults;
    }
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x12a);
  }
  p_Stack_58 = (_LHASH *)(**(code **)(err_fns + 0x14))(1);
  if (p_Stack_58 == (_LHASH *)0x0) {
    puVar3 = (undefined1 *)0x0;
  }
  else {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x205);
    puVar3 = (undefined1 *)lh_insert(p_Stack_58,pvStack_7c);
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x207);
    (**(code **)(err_fns + 0x18))(&p_Stack_58);
    puStack_88 = puVar3;
  }
  if (pvStack_54 == *(void **)puStack_80) {
    return puVar3;
  }
  pvVar4 = pvStack_54;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puStack_84 = &_gp_1;
  puStack_8c = *(undefined1 **)PTR___stack_chk_guard_006a9ae8;
  if (err_fns == (undefined1 *)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
    if (err_fns == (undefined1 *)0x0) {
      err_fns = err_defaults;
    }
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x12a);
  }
  p_Stack_90 = (_LHASH *)(**(code **)(err_fns + 0x14))(0);
  if (p_Stack_90 == (_LHASH *)0x0) goto LAB_0052e644;
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x217);
  pvVar4 = lh_delete(p_Stack_90,pvVar4);
  if (((int_thread_hash_references == 1) && (int_thread_hash != (_LHASH *)0x0)) &&
     (uVar5 = lh_num_items(int_thread_hash), uVar5 == 0)) {
    lh_free(int_thread_hash);
    int_thread_hash = (_LHASH *)0x0;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x21f);
  (**(code **)(err_fns + 0x18))(&p_Stack_90);
  if (pvVar4 == (void *)0x0) goto LAB_0052e644;
  if ((*(int *)((int)pvVar4 + 0x88) == 0) || ((*(uint *)((int)pvVar4 + 200) & 1) == 0)) {
    *(undefined4 *)((int)pvVar4 + 200) = 0;
    if (*(int *)((int)pvVar4 + 0x8c) != 0) goto LAB_0052e498;
LAB_0052e4a8:
    iVar6 = *(int *)((int)pvVar4 + 0x90);
LAB_0052e4ac:
    *(undefined4 *)((int)pvVar4 + 0xcc) = 0;
    if (iVar6 == 0) {
LAB_0052e4c4:
      iVar6 = *(int *)((int)pvVar4 + 0x94);
      goto LAB_0052e4c8;
    }
LAB_0052e4b4:
    if ((*(uint *)((int)pvVar4 + 0xd0) & 1) == 0) goto LAB_0052e4c4;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar4 + 0x90) = 0;
    *(undefined4 *)((int)pvVar4 + 0xd0) = 0;
    if (*(int *)((int)pvVar4 + 0x94) != 0) goto LAB_0052e4d0;
    iVar6 = *(int *)((int)pvVar4 + 0x98);
LAB_0052e4e4:
    *(undefined4 *)((int)pvVar4 + 0xd4) = 0;
    if (iVar6 == 0) {
LAB_0052e4fc:
      iVar6 = *(int *)((int)pvVar4 + 0x9c);
      goto LAB_0052e500;
    }
LAB_0052e4ec:
    if ((*(uint *)((int)pvVar4 + 0xd8) & 1) == 0) goto LAB_0052e4fc;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar4 + 0x98) = 0;
    *(undefined4 *)((int)pvVar4 + 0xd8) = 0;
    if (*(int *)((int)pvVar4 + 0x9c) != 0) goto LAB_0052e508;
    iVar6 = *(int *)((int)pvVar4 + 0xa0);
LAB_0052e51c:
    *(undefined4 *)((int)pvVar4 + 0xdc) = 0;
    if (iVar6 == 0) {
LAB_0052e534:
      iVar6 = *(int *)((int)pvVar4 + 0xa4);
      goto LAB_0052e538;
    }
LAB_0052e524:
    if ((*(uint *)((int)pvVar4 + 0xe0) & 1) == 0) goto LAB_0052e534;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar4 + 0xa0) = 0;
    *(undefined4 *)((int)pvVar4 + 0xe0) = 0;
    if (*(int *)((int)pvVar4 + 0xa4) != 0) goto LAB_0052e540;
    iVar6 = *(int *)((int)pvVar4 + 0xa8);
LAB_0052e554:
    *(undefined4 *)((int)pvVar4 + 0xe4) = 0;
    if (iVar6 == 0) {
LAB_0052e56c:
      iVar6 = *(int *)((int)pvVar4 + 0xac);
      goto LAB_0052e570;
    }
LAB_0052e55c:
    if ((*(uint *)((int)pvVar4 + 0xe8) & 1) == 0) goto LAB_0052e56c;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar4 + 0xa8) = 0;
    *(undefined4 *)((int)pvVar4 + 0xe8) = 0;
    if (*(int *)((int)pvVar4 + 0xac) != 0) goto LAB_0052e578;
    iVar6 = *(int *)((int)pvVar4 + 0xb0);
LAB_0052e58c:
    *(undefined4 *)((int)pvVar4 + 0xec) = 0;
    if (iVar6 == 0) {
LAB_0052e5a4:
      iVar6 = *(int *)((int)pvVar4 + 0xb4);
      goto LAB_0052e5a8;
    }
LAB_0052e594:
    if ((*(uint *)((int)pvVar4 + 0xf0) & 1) == 0) goto LAB_0052e5a4;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar4 + 0xb0) = 0;
    *(undefined4 *)((int)pvVar4 + 0xf0) = 0;
    if (*(int *)((int)pvVar4 + 0xb4) != 0) goto LAB_0052e5b0;
    iVar6 = *(int *)((int)pvVar4 + 0xb8);
LAB_0052e5c4:
    *(undefined4 *)((int)pvVar4 + 0xf4) = 0;
    if (iVar6 == 0) {
LAB_0052e5dc:
      iVar6 = *(int *)((int)pvVar4 + 0xbc);
      goto LAB_0052e5e0;
    }
LAB_0052e5cc:
    if ((*(uint *)((int)pvVar4 + 0xf8) & 1) == 0) goto LAB_0052e5dc;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar4 + 0xb8) = 0;
    *(undefined4 *)((int)pvVar4 + 0xf8) = 0;
    if (*(int *)((int)pvVar4 + 0xbc) != 0) goto LAB_0052e5e8;
    iVar6 = *(int *)((int)pvVar4 + 0xc0);
LAB_0052e5fc:
    *(undefined4 *)((int)pvVar4 + 0xfc) = 0;
    if (iVar6 == 0) {
LAB_0052e614:
      iVar6 = *(int *)((int)pvVar4 + 0xc4);
      goto LAB_0052e618;
    }
LAB_0052e604:
    if ((*(uint *)((int)pvVar4 + 0x100) & 1) == 0) goto LAB_0052e614;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    iVar6 = *(int *)((int)pvVar4 + 0xc4);
    *(undefined4 *)((int)pvVar4 + 0xc0) = 0;
    *(undefined4 *)((int)pvVar4 + 0x100) = 0;
  }
  else {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar4 + 0x88) = 0;
    *(undefined4 *)((int)pvVar4 + 200) = 0;
    if (*(int *)((int)pvVar4 + 0x8c) == 0) {
      iVar6 = *(int *)((int)pvVar4 + 0x90);
      goto LAB_0052e4ac;
    }
LAB_0052e498:
    if ((*(uint *)((int)pvVar4 + 0xcc) & 1) == 0) goto LAB_0052e4a8;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar4 + 0x8c) = 0;
    *(undefined4 *)((int)pvVar4 + 0xcc) = 0;
    if (*(int *)((int)pvVar4 + 0x90) != 0) goto LAB_0052e4b4;
    iVar6 = *(int *)((int)pvVar4 + 0x94);
LAB_0052e4c8:
    *(undefined4 *)((int)pvVar4 + 0xd0) = 0;
    if (iVar6 == 0) {
LAB_0052e4e0:
      iVar6 = *(int *)((int)pvVar4 + 0x98);
      goto LAB_0052e4e4;
    }
LAB_0052e4d0:
    if ((*(uint *)((int)pvVar4 + 0xd4) & 1) == 0) goto LAB_0052e4e0;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar4 + 0x94) = 0;
    *(undefined4 *)((int)pvVar4 + 0xd4) = 0;
    if (*(int *)((int)pvVar4 + 0x98) != 0) goto LAB_0052e4ec;
    iVar6 = *(int *)((int)pvVar4 + 0x9c);
LAB_0052e500:
    *(undefined4 *)((int)pvVar4 + 0xd8) = 0;
    if (iVar6 == 0) {
LAB_0052e518:
      iVar6 = *(int *)((int)pvVar4 + 0xa0);
      goto LAB_0052e51c;
    }
LAB_0052e508:
    if ((*(uint *)((int)pvVar4 + 0xdc) & 1) == 0) goto LAB_0052e518;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar4 + 0x9c) = 0;
    *(undefined4 *)((int)pvVar4 + 0xdc) = 0;
    if (*(int *)((int)pvVar4 + 0xa0) != 0) goto LAB_0052e524;
    iVar6 = *(int *)((int)pvVar4 + 0xa4);
LAB_0052e538:
    *(undefined4 *)((int)pvVar4 + 0xe0) = 0;
    if (iVar6 == 0) {
LAB_0052e550:
      iVar6 = *(int *)((int)pvVar4 + 0xa8);
      goto LAB_0052e554;
    }
LAB_0052e540:
    if ((*(uint *)((int)pvVar4 + 0xe4) & 1) == 0) goto LAB_0052e550;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar4 + 0xa4) = 0;
    *(undefined4 *)((int)pvVar4 + 0xe4) = 0;
    if (*(int *)((int)pvVar4 + 0xa8) != 0) goto LAB_0052e55c;
    iVar6 = *(int *)((int)pvVar4 + 0xac);
LAB_0052e570:
    *(undefined4 *)((int)pvVar4 + 0xe8) = 0;
    if (iVar6 == 0) {
LAB_0052e588:
      iVar6 = *(int *)((int)pvVar4 + 0xb0);
      goto LAB_0052e58c;
    }
LAB_0052e578:
    if ((*(uint *)((int)pvVar4 + 0xec) & 1) == 0) goto LAB_0052e588;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar4 + 0xac) = 0;
    *(undefined4 *)((int)pvVar4 + 0xec) = 0;
    if (*(int *)((int)pvVar4 + 0xb0) != 0) goto LAB_0052e594;
    iVar6 = *(int *)((int)pvVar4 + 0xb4);
LAB_0052e5a8:
    *(undefined4 *)((int)pvVar4 + 0xf0) = 0;
    if (iVar6 == 0) {
LAB_0052e5c0:
      iVar6 = *(int *)((int)pvVar4 + 0xb8);
      goto LAB_0052e5c4;
    }
LAB_0052e5b0:
    if ((*(uint *)((int)pvVar4 + 0xf4) & 1) == 0) goto LAB_0052e5c0;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar4 + 0xb4) = 0;
    *(undefined4 *)((int)pvVar4 + 0xf4) = 0;
    if (*(int *)((int)pvVar4 + 0xb8) != 0) goto LAB_0052e5cc;
    iVar6 = *(int *)((int)pvVar4 + 0xbc);
LAB_0052e5e0:
    *(undefined4 *)((int)pvVar4 + 0xf8) = 0;
    if (iVar6 == 0) {
LAB_0052e5f8:
      iVar6 = *(int *)((int)pvVar4 + 0xc0);
      goto LAB_0052e5fc;
    }
LAB_0052e5e8:
    if ((*(uint *)((int)pvVar4 + 0xfc) & 1) == 0) goto LAB_0052e5f8;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar4 + 0xbc) = 0;
    *(undefined4 *)((int)pvVar4 + 0xfc) = 0;
    if (*(int *)((int)pvVar4 + 0xc0) != 0) goto LAB_0052e604;
    iVar6 = *(int *)((int)pvVar4 + 0xc4);
LAB_0052e618:
    *(undefined4 *)((int)pvVar4 + 0x100) = 0;
  }
  if ((iVar6 != 0) && ((*(uint *)((int)pvVar4 + 0x104) & 1) != 0)) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar4 + 0xc4) = 0;
  }
  puVar1 = PTR_CRYPTO_free_006a6e88;
  *(undefined4 *)((int)pvVar4 + 0x104) = 0;
  (*(code *)puVar1)(pvVar4);
LAB_0052e644:
  if (puStack_8c == *(undefined1 **)puVar2) {
    return *(undefined1 **)puVar2;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (err_fns != (undefined1 *)0x0) {
    return err_fns;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
  if (err_fns == (undefined1 *)0x0) {
    err_fns = err_defaults;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x12a);
  return err_fns;
}

