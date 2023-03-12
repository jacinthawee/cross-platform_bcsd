
undefined1 * int_thread_del_item(void *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  void *pvVar3;
  ulong uVar4;
  int iVar5;
  _LHASH *local_20;
  undefined1 *local_1c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(undefined1 **)PTR___stack_chk_guard_006a9ae8;
  if (err_fns == (undefined1 *)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
    if (err_fns == (undefined1 *)0x0) {
      err_fns = err_defaults;
    }
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x12a);
  }
  local_20 = (_LHASH *)(**(code **)(err_fns + 0x14))(0);
  if (local_20 == (_LHASH *)0x0) goto LAB_0052e644;
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x217);
  pvVar3 = lh_delete(local_20,param_1);
  if (((int_thread_hash_references == 1) && (int_thread_hash != (_LHASH *)0x0)) &&
     (uVar4 = lh_num_items(int_thread_hash), uVar4 == 0)) {
    lh_free(int_thread_hash);
    int_thread_hash = (_LHASH *)0x0;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x21f);
  (**(code **)(err_fns + 0x18))(&local_20);
  if (pvVar3 == (void *)0x0) goto LAB_0052e644;
  if ((*(int *)((int)pvVar3 + 0x88) == 0) || ((*(uint *)((int)pvVar3 + 200) & 1) == 0)) {
    *(undefined4 *)((int)pvVar3 + 200) = 0;
    if (*(int *)((int)pvVar3 + 0x8c) != 0) goto LAB_0052e498;
LAB_0052e4a8:
    iVar5 = *(int *)((int)pvVar3 + 0x90);
LAB_0052e4ac:
    *(undefined4 *)((int)pvVar3 + 0xcc) = 0;
    if (iVar5 == 0) {
LAB_0052e4c4:
      iVar5 = *(int *)((int)pvVar3 + 0x94);
      goto LAB_0052e4c8;
    }
LAB_0052e4b4:
    if ((*(uint *)((int)pvVar3 + 0xd0) & 1) == 0) goto LAB_0052e4c4;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar3 + 0x90) = 0;
    *(undefined4 *)((int)pvVar3 + 0xd0) = 0;
    if (*(int *)((int)pvVar3 + 0x94) != 0) goto LAB_0052e4d0;
    iVar5 = *(int *)((int)pvVar3 + 0x98);
LAB_0052e4e4:
    *(undefined4 *)((int)pvVar3 + 0xd4) = 0;
    if (iVar5 == 0) {
LAB_0052e4fc:
      iVar5 = *(int *)((int)pvVar3 + 0x9c);
      goto LAB_0052e500;
    }
LAB_0052e4ec:
    if ((*(uint *)((int)pvVar3 + 0xd8) & 1) == 0) goto LAB_0052e4fc;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar3 + 0x98) = 0;
    *(undefined4 *)((int)pvVar3 + 0xd8) = 0;
    if (*(int *)((int)pvVar3 + 0x9c) != 0) goto LAB_0052e508;
    iVar5 = *(int *)((int)pvVar3 + 0xa0);
LAB_0052e51c:
    *(undefined4 *)((int)pvVar3 + 0xdc) = 0;
    if (iVar5 == 0) {
LAB_0052e534:
      iVar5 = *(int *)((int)pvVar3 + 0xa4);
      goto LAB_0052e538;
    }
LAB_0052e524:
    if ((*(uint *)((int)pvVar3 + 0xe0) & 1) == 0) goto LAB_0052e534;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar3 + 0xa0) = 0;
    *(undefined4 *)((int)pvVar3 + 0xe0) = 0;
    if (*(int *)((int)pvVar3 + 0xa4) != 0) goto LAB_0052e540;
    iVar5 = *(int *)((int)pvVar3 + 0xa8);
LAB_0052e554:
    *(undefined4 *)((int)pvVar3 + 0xe4) = 0;
    if (iVar5 == 0) {
LAB_0052e56c:
      iVar5 = *(int *)((int)pvVar3 + 0xac);
      goto LAB_0052e570;
    }
LAB_0052e55c:
    if ((*(uint *)((int)pvVar3 + 0xe8) & 1) == 0) goto LAB_0052e56c;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar3 + 0xa8) = 0;
    *(undefined4 *)((int)pvVar3 + 0xe8) = 0;
    if (*(int *)((int)pvVar3 + 0xac) != 0) goto LAB_0052e578;
    iVar5 = *(int *)((int)pvVar3 + 0xb0);
LAB_0052e58c:
    *(undefined4 *)((int)pvVar3 + 0xec) = 0;
    if (iVar5 == 0) {
LAB_0052e5a4:
      iVar5 = *(int *)((int)pvVar3 + 0xb4);
      goto LAB_0052e5a8;
    }
LAB_0052e594:
    if ((*(uint *)((int)pvVar3 + 0xf0) & 1) == 0) goto LAB_0052e5a4;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar3 + 0xb0) = 0;
    *(undefined4 *)((int)pvVar3 + 0xf0) = 0;
    if (*(int *)((int)pvVar3 + 0xb4) != 0) goto LAB_0052e5b0;
    iVar5 = *(int *)((int)pvVar3 + 0xb8);
LAB_0052e5c4:
    *(undefined4 *)((int)pvVar3 + 0xf4) = 0;
    if (iVar5 == 0) {
LAB_0052e5dc:
      iVar5 = *(int *)((int)pvVar3 + 0xbc);
      goto LAB_0052e5e0;
    }
LAB_0052e5cc:
    if ((*(uint *)((int)pvVar3 + 0xf8) & 1) == 0) goto LAB_0052e5dc;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar3 + 0xb8) = 0;
    *(undefined4 *)((int)pvVar3 + 0xf8) = 0;
    if (*(int *)((int)pvVar3 + 0xbc) != 0) goto LAB_0052e5e8;
    iVar5 = *(int *)((int)pvVar3 + 0xc0);
LAB_0052e5fc:
    *(undefined4 *)((int)pvVar3 + 0xfc) = 0;
    if (iVar5 == 0) {
LAB_0052e614:
      iVar5 = *(int *)((int)pvVar3 + 0xc4);
      goto LAB_0052e618;
    }
LAB_0052e604:
    if ((*(uint *)((int)pvVar3 + 0x100) & 1) == 0) goto LAB_0052e614;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    iVar5 = *(int *)((int)pvVar3 + 0xc4);
    *(undefined4 *)((int)pvVar3 + 0xc0) = 0;
    *(undefined4 *)((int)pvVar3 + 0x100) = 0;
  }
  else {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar3 + 0x88) = 0;
    *(undefined4 *)((int)pvVar3 + 200) = 0;
    if (*(int *)((int)pvVar3 + 0x8c) == 0) {
      iVar5 = *(int *)((int)pvVar3 + 0x90);
      goto LAB_0052e4ac;
    }
LAB_0052e498:
    if ((*(uint *)((int)pvVar3 + 0xcc) & 1) == 0) goto LAB_0052e4a8;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar3 + 0x8c) = 0;
    *(undefined4 *)((int)pvVar3 + 0xcc) = 0;
    if (*(int *)((int)pvVar3 + 0x90) != 0) goto LAB_0052e4b4;
    iVar5 = *(int *)((int)pvVar3 + 0x94);
LAB_0052e4c8:
    *(undefined4 *)((int)pvVar3 + 0xd0) = 0;
    if (iVar5 == 0) {
LAB_0052e4e0:
      iVar5 = *(int *)((int)pvVar3 + 0x98);
      goto LAB_0052e4e4;
    }
LAB_0052e4d0:
    if ((*(uint *)((int)pvVar3 + 0xd4) & 1) == 0) goto LAB_0052e4e0;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar3 + 0x94) = 0;
    *(undefined4 *)((int)pvVar3 + 0xd4) = 0;
    if (*(int *)((int)pvVar3 + 0x98) != 0) goto LAB_0052e4ec;
    iVar5 = *(int *)((int)pvVar3 + 0x9c);
LAB_0052e500:
    *(undefined4 *)((int)pvVar3 + 0xd8) = 0;
    if (iVar5 == 0) {
LAB_0052e518:
      iVar5 = *(int *)((int)pvVar3 + 0xa0);
      goto LAB_0052e51c;
    }
LAB_0052e508:
    if ((*(uint *)((int)pvVar3 + 0xdc) & 1) == 0) goto LAB_0052e518;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar3 + 0x9c) = 0;
    *(undefined4 *)((int)pvVar3 + 0xdc) = 0;
    if (*(int *)((int)pvVar3 + 0xa0) != 0) goto LAB_0052e524;
    iVar5 = *(int *)((int)pvVar3 + 0xa4);
LAB_0052e538:
    *(undefined4 *)((int)pvVar3 + 0xe0) = 0;
    if (iVar5 == 0) {
LAB_0052e550:
      iVar5 = *(int *)((int)pvVar3 + 0xa8);
      goto LAB_0052e554;
    }
LAB_0052e540:
    if ((*(uint *)((int)pvVar3 + 0xe4) & 1) == 0) goto LAB_0052e550;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar3 + 0xa4) = 0;
    *(undefined4 *)((int)pvVar3 + 0xe4) = 0;
    if (*(int *)((int)pvVar3 + 0xa8) != 0) goto LAB_0052e55c;
    iVar5 = *(int *)((int)pvVar3 + 0xac);
LAB_0052e570:
    *(undefined4 *)((int)pvVar3 + 0xe8) = 0;
    if (iVar5 == 0) {
LAB_0052e588:
      iVar5 = *(int *)((int)pvVar3 + 0xb0);
      goto LAB_0052e58c;
    }
LAB_0052e578:
    if ((*(uint *)((int)pvVar3 + 0xec) & 1) == 0) goto LAB_0052e588;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar3 + 0xac) = 0;
    *(undefined4 *)((int)pvVar3 + 0xec) = 0;
    if (*(int *)((int)pvVar3 + 0xb0) != 0) goto LAB_0052e594;
    iVar5 = *(int *)((int)pvVar3 + 0xb4);
LAB_0052e5a8:
    *(undefined4 *)((int)pvVar3 + 0xf0) = 0;
    if (iVar5 == 0) {
LAB_0052e5c0:
      iVar5 = *(int *)((int)pvVar3 + 0xb8);
      goto LAB_0052e5c4;
    }
LAB_0052e5b0:
    if ((*(uint *)((int)pvVar3 + 0xf4) & 1) == 0) goto LAB_0052e5c0;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar3 + 0xb4) = 0;
    *(undefined4 *)((int)pvVar3 + 0xf4) = 0;
    if (*(int *)((int)pvVar3 + 0xb8) != 0) goto LAB_0052e5cc;
    iVar5 = *(int *)((int)pvVar3 + 0xbc);
LAB_0052e5e0:
    *(undefined4 *)((int)pvVar3 + 0xf8) = 0;
    if (iVar5 == 0) {
LAB_0052e5f8:
      iVar5 = *(int *)((int)pvVar3 + 0xc0);
      goto LAB_0052e5fc;
    }
LAB_0052e5e8:
    if ((*(uint *)((int)pvVar3 + 0xfc) & 1) == 0) goto LAB_0052e5f8;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar3 + 0xbc) = 0;
    *(undefined4 *)((int)pvVar3 + 0xfc) = 0;
    if (*(int *)((int)pvVar3 + 0xc0) != 0) goto LAB_0052e604;
    iVar5 = *(int *)((int)pvVar3 + 0xc4);
LAB_0052e618:
    *(undefined4 *)((int)pvVar3 + 0x100) = 0;
  }
  if ((iVar5 != 0) && ((*(uint *)((int)pvVar3 + 0x104) & 1) != 0)) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    *(undefined4 *)((int)pvVar3 + 0xc4) = 0;
  }
  puVar1 = PTR_CRYPTO_free_006a6e88;
  *(undefined4 *)((int)pvVar3 + 0x104) = 0;
  (*(code *)puVar1)(pvVar3);
LAB_0052e644:
  if (local_1c == *(undefined1 **)puVar2) {
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

