
char * int_thread_set_item(void *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  char *pcVar3;
  void *pvVar4;
  ulong uVar5;
  int iVar6;
  _LHASH *p_Stack_58;
  char *pcStack_54;
  char *pcStack_50;
  undefined1 *puStack_4c;
  undefined *puStack_48;
  void *pvStack_44;
  _LHASH *local_20;
  void *local_1c;
  
  puStack_48 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(void **)PTR___stack_chk_guard_006aabf0;
  pcStack_50 = "7 datafinal";
  if (err_fns == (char *)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,1,"err.c",0x127);
    if (err_fns == (char *)0x0) {
      err_fns = err_defaults;
    }
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,1,"err.c",0x12a);
  }
  local_20 = (_LHASH *)(**(code **)(err_fns + 0x14))(1);
  if (local_20 == (_LHASH *)0x0) {
    pcVar3 = (char *)0x0;
  }
  else {
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,1,"err.c",0x201);
    pcVar3 = (char *)lh_insert(local_20,param_1);
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,1,"err.c",0x203);
    (**(code **)(err_fns + 0x18))(&local_20);
    pcStack_50 = pcVar3;
  }
  if (local_1c == *(void **)puStack_48) {
    return pcVar3;
  }
  pvVar4 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puStack_4c = &_ITM_registerTMCloneTable;
  pcStack_54 = *(char **)PTR___stack_chk_guard_006aabf0;
  pvStack_44 = param_1;
  if (err_fns == (char *)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,1,"err.c",0x127);
    if (err_fns == (char *)0x0) {
      err_fns = err_defaults;
    }
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,1,"err.c",0x12a);
  }
  p_Stack_58 = (_LHASH *)(**(code **)(err_fns + 0x14))(0);
  if (p_Stack_58 == (_LHASH *)0x0) goto LAB_00531994;
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,1,"err.c",0x213);
  pvVar4 = lh_delete(p_Stack_58,pvVar4);
  if (((int_thread_hash_references == 1) && (int_thread_hash != (_LHASH *)0x0)) &&
     (uVar5 = lh_num_items(int_thread_hash), uVar5 == 0)) {
    lh_free(int_thread_hash);
    int_thread_hash = (_LHASH *)0x0;
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,1,"err.c",0x21c);
  (**(code **)(err_fns + 0x18))(&p_Stack_58);
  if (pvVar4 == (void *)0x0) goto LAB_00531994;
  if ((*(int *)((int)pvVar4 + 0x88) == 0) || ((*(uint *)((int)pvVar4 + 200) & 1) == 0)) {
    *(undefined4 *)((int)pvVar4 + 200) = 0;
    if (*(int *)((int)pvVar4 + 0x8c) != 0) goto LAB_005317e8;
LAB_005317f8:
    iVar6 = *(int *)((int)pvVar4 + 0x90);
LAB_005317fc:
    *(undefined4 *)((int)pvVar4 + 0xcc) = 0;
    if (iVar6 == 0) {
LAB_00531814:
      iVar6 = *(int *)((int)pvVar4 + 0x94);
      goto LAB_00531818;
    }
LAB_00531804:
    if ((*(uint *)((int)pvVar4 + 0xd0) & 1) == 0) goto LAB_00531814;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    *(undefined4 *)((int)pvVar4 + 0x90) = 0;
    *(undefined4 *)((int)pvVar4 + 0xd0) = 0;
    if (*(int *)((int)pvVar4 + 0x94) != 0) goto LAB_00531820;
    iVar6 = *(int *)((int)pvVar4 + 0x98);
LAB_00531834:
    *(undefined4 *)((int)pvVar4 + 0xd4) = 0;
    if (iVar6 == 0) {
LAB_0053184c:
      iVar6 = *(int *)((int)pvVar4 + 0x9c);
      goto LAB_00531850;
    }
LAB_0053183c:
    if ((*(uint *)((int)pvVar4 + 0xd8) & 1) == 0) goto LAB_0053184c;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    *(undefined4 *)((int)pvVar4 + 0x98) = 0;
    *(undefined4 *)((int)pvVar4 + 0xd8) = 0;
    if (*(int *)((int)pvVar4 + 0x9c) != 0) goto LAB_00531858;
    iVar6 = *(int *)((int)pvVar4 + 0xa0);
LAB_0053186c:
    *(undefined4 *)((int)pvVar4 + 0xdc) = 0;
    if (iVar6 == 0) {
LAB_00531884:
      iVar6 = *(int *)((int)pvVar4 + 0xa4);
      goto LAB_00531888;
    }
LAB_00531874:
    if ((*(uint *)((int)pvVar4 + 0xe0) & 1) == 0) goto LAB_00531884;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    *(undefined4 *)((int)pvVar4 + 0xa0) = 0;
    *(undefined4 *)((int)pvVar4 + 0xe0) = 0;
    if (*(int *)((int)pvVar4 + 0xa4) != 0) goto LAB_00531890;
    iVar6 = *(int *)((int)pvVar4 + 0xa8);
LAB_005318a4:
    *(undefined4 *)((int)pvVar4 + 0xe4) = 0;
    if (iVar6 == 0) {
LAB_005318bc:
      iVar6 = *(int *)((int)pvVar4 + 0xac);
      goto LAB_005318c0;
    }
LAB_005318ac:
    if ((*(uint *)((int)pvVar4 + 0xe8) & 1) == 0) goto LAB_005318bc;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    *(undefined4 *)((int)pvVar4 + 0xa8) = 0;
    *(undefined4 *)((int)pvVar4 + 0xe8) = 0;
    if (*(int *)((int)pvVar4 + 0xac) != 0) goto LAB_005318c8;
    iVar6 = *(int *)((int)pvVar4 + 0xb0);
LAB_005318dc:
    *(undefined4 *)((int)pvVar4 + 0xec) = 0;
    if (iVar6 == 0) {
LAB_005318f4:
      iVar6 = *(int *)((int)pvVar4 + 0xb4);
      goto LAB_005318f8;
    }
LAB_005318e4:
    if ((*(uint *)((int)pvVar4 + 0xf0) & 1) == 0) goto LAB_005318f4;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    *(undefined4 *)((int)pvVar4 + 0xb0) = 0;
    *(undefined4 *)((int)pvVar4 + 0xf0) = 0;
    if (*(int *)((int)pvVar4 + 0xb4) != 0) goto LAB_00531900;
    iVar6 = *(int *)((int)pvVar4 + 0xb8);
LAB_00531914:
    *(undefined4 *)((int)pvVar4 + 0xf4) = 0;
    if (iVar6 == 0) {
LAB_0053192c:
      iVar6 = *(int *)((int)pvVar4 + 0xbc);
      goto LAB_00531930;
    }
LAB_0053191c:
    if ((*(uint *)((int)pvVar4 + 0xf8) & 1) == 0) goto LAB_0053192c;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    *(undefined4 *)((int)pvVar4 + 0xb8) = 0;
    *(undefined4 *)((int)pvVar4 + 0xf8) = 0;
    if (*(int *)((int)pvVar4 + 0xbc) != 0) goto LAB_00531938;
    iVar6 = *(int *)((int)pvVar4 + 0xc0);
LAB_0053194c:
    *(undefined4 *)((int)pvVar4 + 0xfc) = 0;
    if (iVar6 == 0) {
LAB_00531964:
      iVar6 = *(int *)((int)pvVar4 + 0xc4);
      goto LAB_00531968;
    }
LAB_00531954:
    if ((*(uint *)((int)pvVar4 + 0x100) & 1) == 0) goto LAB_00531964;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    iVar6 = *(int *)((int)pvVar4 + 0xc4);
    *(undefined4 *)((int)pvVar4 + 0xc0) = 0;
    *(undefined4 *)((int)pvVar4 + 0x100) = 0;
  }
  else {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    *(undefined4 *)((int)pvVar4 + 0x88) = 0;
    *(undefined4 *)((int)pvVar4 + 200) = 0;
    if (*(int *)((int)pvVar4 + 0x8c) == 0) {
      iVar6 = *(int *)((int)pvVar4 + 0x90);
      goto LAB_005317fc;
    }
LAB_005317e8:
    if ((*(uint *)((int)pvVar4 + 0xcc) & 1) == 0) goto LAB_005317f8;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    *(undefined4 *)((int)pvVar4 + 0x8c) = 0;
    *(undefined4 *)((int)pvVar4 + 0xcc) = 0;
    if (*(int *)((int)pvVar4 + 0x90) != 0) goto LAB_00531804;
    iVar6 = *(int *)((int)pvVar4 + 0x94);
LAB_00531818:
    *(undefined4 *)((int)pvVar4 + 0xd0) = 0;
    if (iVar6 == 0) {
LAB_00531830:
      iVar6 = *(int *)((int)pvVar4 + 0x98);
      goto LAB_00531834;
    }
LAB_00531820:
    if ((*(uint *)((int)pvVar4 + 0xd4) & 1) == 0) goto LAB_00531830;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    *(undefined4 *)((int)pvVar4 + 0x94) = 0;
    *(undefined4 *)((int)pvVar4 + 0xd4) = 0;
    if (*(int *)((int)pvVar4 + 0x98) != 0) goto LAB_0053183c;
    iVar6 = *(int *)((int)pvVar4 + 0x9c);
LAB_00531850:
    *(undefined4 *)((int)pvVar4 + 0xd8) = 0;
    if (iVar6 == 0) {
LAB_00531868:
      iVar6 = *(int *)((int)pvVar4 + 0xa0);
      goto LAB_0053186c;
    }
LAB_00531858:
    if ((*(uint *)((int)pvVar4 + 0xdc) & 1) == 0) goto LAB_00531868;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    *(undefined4 *)((int)pvVar4 + 0x9c) = 0;
    *(undefined4 *)((int)pvVar4 + 0xdc) = 0;
    if (*(int *)((int)pvVar4 + 0xa0) != 0) goto LAB_00531874;
    iVar6 = *(int *)((int)pvVar4 + 0xa4);
LAB_00531888:
    *(undefined4 *)((int)pvVar4 + 0xe0) = 0;
    if (iVar6 == 0) {
LAB_005318a0:
      iVar6 = *(int *)((int)pvVar4 + 0xa8);
      goto LAB_005318a4;
    }
LAB_00531890:
    if ((*(uint *)((int)pvVar4 + 0xe4) & 1) == 0) goto LAB_005318a0;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    *(undefined4 *)((int)pvVar4 + 0xa4) = 0;
    *(undefined4 *)((int)pvVar4 + 0xe4) = 0;
    if (*(int *)((int)pvVar4 + 0xa8) != 0) goto LAB_005318ac;
    iVar6 = *(int *)((int)pvVar4 + 0xac);
LAB_005318c0:
    *(undefined4 *)((int)pvVar4 + 0xe8) = 0;
    if (iVar6 == 0) {
LAB_005318d8:
      iVar6 = *(int *)((int)pvVar4 + 0xb0);
      goto LAB_005318dc;
    }
LAB_005318c8:
    if ((*(uint *)((int)pvVar4 + 0xec) & 1) == 0) goto LAB_005318d8;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    *(undefined4 *)((int)pvVar4 + 0xac) = 0;
    *(undefined4 *)((int)pvVar4 + 0xec) = 0;
    if (*(int *)((int)pvVar4 + 0xb0) != 0) goto LAB_005318e4;
    iVar6 = *(int *)((int)pvVar4 + 0xb4);
LAB_005318f8:
    *(undefined4 *)((int)pvVar4 + 0xf0) = 0;
    if (iVar6 == 0) {
LAB_00531910:
      iVar6 = *(int *)((int)pvVar4 + 0xb8);
      goto LAB_00531914;
    }
LAB_00531900:
    if ((*(uint *)((int)pvVar4 + 0xf4) & 1) == 0) goto LAB_00531910;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    *(undefined4 *)((int)pvVar4 + 0xb4) = 0;
    *(undefined4 *)((int)pvVar4 + 0xf4) = 0;
    if (*(int *)((int)pvVar4 + 0xb8) != 0) goto LAB_0053191c;
    iVar6 = *(int *)((int)pvVar4 + 0xbc);
LAB_00531930:
    *(undefined4 *)((int)pvVar4 + 0xf8) = 0;
    if (iVar6 == 0) {
LAB_00531948:
      iVar6 = *(int *)((int)pvVar4 + 0xc0);
      goto LAB_0053194c;
    }
LAB_00531938:
    if ((*(uint *)((int)pvVar4 + 0xfc) & 1) == 0) goto LAB_00531948;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    *(undefined4 *)((int)pvVar4 + 0xbc) = 0;
    *(undefined4 *)((int)pvVar4 + 0xfc) = 0;
    if (*(int *)((int)pvVar4 + 0xc0) != 0) goto LAB_00531954;
    iVar6 = *(int *)((int)pvVar4 + 0xc4);
LAB_00531968:
    *(undefined4 *)((int)pvVar4 + 0x100) = 0;
  }
  if ((iVar6 != 0) && ((*(uint *)((int)pvVar4 + 0x104) & 1) != 0)) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    *(undefined4 *)((int)pvVar4 + 0xc4) = 0;
  }
  puVar1 = PTR_CRYPTO_free_006a7f88;
  *(undefined4 *)((int)pvVar4 + 0x104) = 0;
  (*(code *)puVar1)(pvVar4);
LAB_00531994:
  if (pcStack_54 == *(char **)puVar2) {
    return *(char **)puVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (err_fns != (char *)0x0) {
    return err_fns;
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,1,"err.c",0x127);
  if (err_fns == (char *)0x0) {
    err_fns = err_defaults;
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,1,"err.c",0x12a);
  return err_fns;
}

