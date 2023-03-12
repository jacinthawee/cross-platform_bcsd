
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ERR_STATE * ERR_get_state(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  int iVar4;
  ERR_STATE *pEVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  char *pcVar9;
  char *in_a2;
  char *in_a3;
  char acStack_1b4 [8];
  undefined auStack_1ac [400];
  int local_1c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (err_fns == (undefined1 *)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
    if (err_fns == (undefined1 *)0x0) {
      err_fns = err_defaults;
    }
    in_a3 = (char *)0x12a;
    in_a2 = "err.c";
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,1);
  }
  (*(code *)PTR_CRYPTO_THREADID_current_006a848c)(acStack_1b4);
  pcVar9 = acStack_1b4;
  (*(code *)PTR_CRYPTO_THREADID_cpy_006a8488)(auStack_1ac);
  puVar3 = (undefined1 *)(**(code **)(err_fns + 0x1c))(auStack_1ac);
  if ((ERR_STATE *)puVar3 == (ERR_STATE *)0x0) {
    in_a2 = (char *)0x403;
    pcVar9 = "err.c";
    puVar3 = (undefined1 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(400);
    if ((ERR_STATE *)puVar3 == (ERR_STATE *)0x0) {
      puVar3 = fallback_5580;
    }
    else {
      (*(code *)PTR_CRYPTO_THREADID_cpy_006a8488)(puVar3,acStack_1b4);
      *(int *)((int)puVar3 + 0x188) = 0;
      puVar1 = PTR_memset_006a99f4;
      *(int *)((int)puVar3 + 0x18c) = 0;
      (*(code *)puVar1)((char **)((int)puVar3 + 0x88),0,0x40);
      in_a2 = (char *)0x40;
      pcVar9 = (char *)0x0;
      (*(code *)PTR_memset_006a99f4)((int *)((int)puVar3 + 200));
      iVar4 = (**(code **)(err_fns + 0x20))(puVar3);
      pEVar5 = (ERR_STATE *)(**(code **)(err_fns + 0x1c))(puVar3);
      if ((ERR_STATE *)puVar3 == pEVar5) {
        if (iVar4 != 0) {
          if ((*(int *)(iVar4 + 0x88) != 0) && ((*(uint *)(iVar4 + 200) & 1) != 0)) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            *(undefined4 *)(iVar4 + 0x88) = 0;
          }
          *(undefined4 *)(iVar4 + 200) = 0;
          if ((*(int *)(iVar4 + 0x8c) != 0) && ((*(uint *)(iVar4 + 0xcc) & 1) != 0)) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            *(undefined4 *)(iVar4 + 0x8c) = 0;
          }
          *(undefined4 *)(iVar4 + 0xcc) = 0;
          if ((*(int *)(iVar4 + 0x90) != 0) && ((*(uint *)(iVar4 + 0xd0) & 1) != 0)) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            *(undefined4 *)(iVar4 + 0x90) = 0;
          }
          *(undefined4 *)(iVar4 + 0xd0) = 0;
          if ((*(int *)(iVar4 + 0x94) != 0) && ((*(uint *)(iVar4 + 0xd4) & 1) != 0)) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            *(undefined4 *)(iVar4 + 0x94) = 0;
          }
          *(undefined4 *)(iVar4 + 0xd4) = 0;
          if ((*(int *)(iVar4 + 0x98) != 0) && ((*(uint *)(iVar4 + 0xd8) & 1) != 0)) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            *(undefined4 *)(iVar4 + 0x98) = 0;
          }
          *(undefined4 *)(iVar4 + 0xd8) = 0;
          if ((*(int *)(iVar4 + 0x9c) != 0) && ((*(uint *)(iVar4 + 0xdc) & 1) != 0)) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            *(undefined4 *)(iVar4 + 0x9c) = 0;
          }
          *(undefined4 *)(iVar4 + 0xdc) = 0;
          if ((*(int *)(iVar4 + 0xa0) != 0) && ((*(uint *)(iVar4 + 0xe0) & 1) != 0)) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            *(undefined4 *)(iVar4 + 0xa0) = 0;
          }
          *(undefined4 *)(iVar4 + 0xe0) = 0;
          if ((*(int *)(iVar4 + 0xa4) != 0) && ((*(uint *)(iVar4 + 0xe4) & 1) != 0)) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            *(undefined4 *)(iVar4 + 0xa4) = 0;
          }
          *(undefined4 *)(iVar4 + 0xe4) = 0;
          if ((*(int *)(iVar4 + 0xa8) != 0) && ((*(uint *)(iVar4 + 0xe8) & 1) != 0)) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            *(undefined4 *)(iVar4 + 0xa8) = 0;
          }
          *(undefined4 *)(iVar4 + 0xe8) = 0;
          if ((*(int *)(iVar4 + 0xac) != 0) && ((*(uint *)(iVar4 + 0xec) & 1) != 0)) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            *(undefined4 *)(iVar4 + 0xac) = 0;
          }
          *(undefined4 *)(iVar4 + 0xec) = 0;
          if ((*(int *)(iVar4 + 0xb0) != 0) && ((*(uint *)(iVar4 + 0xf0) & 1) != 0)) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            *(undefined4 *)(iVar4 + 0xb0) = 0;
          }
          *(undefined4 *)(iVar4 + 0xf0) = 0;
          if ((*(int *)(iVar4 + 0xb4) != 0) && ((*(uint *)(iVar4 + 0xf4) & 1) != 0)) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            *(undefined4 *)(iVar4 + 0xb4) = 0;
          }
          *(undefined4 *)(iVar4 + 0xf4) = 0;
          if ((*(int *)(iVar4 + 0xb8) != 0) && ((*(uint *)(iVar4 + 0xf8) & 1) != 0)) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            *(undefined4 *)(iVar4 + 0xb8) = 0;
          }
          *(undefined4 *)(iVar4 + 0xf8) = 0;
          if ((*(int *)(iVar4 + 0xbc) != 0) && ((*(uint *)(iVar4 + 0xfc) & 1) != 0)) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            *(undefined4 *)(iVar4 + 0xbc) = 0;
          }
          *(undefined4 *)(iVar4 + 0xfc) = 0;
          if ((*(int *)(iVar4 + 0xc0) != 0) && ((*(uint *)(iVar4 + 0x100) & 1) != 0)) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            *(undefined4 *)(iVar4 + 0xc0) = 0;
          }
          *(undefined4 *)(iVar4 + 0x100) = 0;
          if ((*(int *)(iVar4 + 0xc4) != 0) && ((*(uint *)(iVar4 + 0x104) & 1) != 0)) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            *(undefined4 *)(iVar4 + 0xc4) = 0;
          }
          puVar1 = PTR_CRYPTO_free_006a6e88;
          *(undefined4 *)(iVar4 + 0x104) = 0;
          (*(code *)puVar1)(iVar4);
        }
      }
      else {
        if ((*(char **)((int)puVar3 + 0x88) != (char *)0x0) &&
           ((*(int *)((int)puVar3 + 200) & 1U) != 0)) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          *(char **)((int)puVar3 + 0x88) = (char *)0x0;
        }
        pcVar7 = ((char **)((int)puVar3 + 0x88))[1];
        *(int *)((int)puVar3 + 200) = 0;
        if ((pcVar7 != (char *)0x0) && ((((int *)((int)puVar3 + 200))[1] & 1U) != 0)) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          ((char **)((int)puVar3 + 0x88))[1] = (char *)0x0;
        }
        pcVar7 = ((char **)((int)puVar3 + 0x88))[2];
        ((int *)((int)puVar3 + 200))[1] = 0;
        if ((pcVar7 != (char *)0x0) && ((((int *)((int)puVar3 + 200))[2] & 1U) != 0)) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          ((char **)((int)puVar3 + 0x88))[2] = (char *)0x0;
        }
        pcVar7 = ((char **)((int)puVar3 + 0x88))[3];
        ((int *)((int)puVar3 + 200))[2] = 0;
        if ((pcVar7 != (char *)0x0) && ((((int *)((int)puVar3 + 200))[3] & 1U) != 0)) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          ((char **)((int)puVar3 + 0x88))[3] = (char *)0x0;
        }
        pcVar7 = ((char **)((int)puVar3 + 0x88))[4];
        ((int *)((int)puVar3 + 200))[3] = 0;
        if ((pcVar7 != (char *)0x0) && ((((int *)((int)puVar3 + 200))[4] & 1U) != 0)) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          ((char **)((int)puVar3 + 0x88))[4] = (char *)0x0;
        }
        pcVar7 = ((char **)((int)puVar3 + 0x88))[5];
        ((int *)((int)puVar3 + 200))[4] = 0;
        if ((pcVar7 != (char *)0x0) && ((((int *)((int)puVar3 + 200))[5] & 1U) != 0)) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          ((char **)((int)puVar3 + 0x88))[5] = (char *)0x0;
        }
        pcVar7 = ((char **)((int)puVar3 + 0x88))[6];
        ((int *)((int)puVar3 + 200))[5] = 0;
        if ((pcVar7 != (char *)0x0) && ((((int *)((int)puVar3 + 200))[6] & 1U) != 0)) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          ((char **)((int)puVar3 + 0x88))[6] = (char *)0x0;
        }
        pcVar7 = ((char **)((int)puVar3 + 0x88))[7];
        ((int *)((int)puVar3 + 200))[6] = 0;
        if ((pcVar7 != (char *)0x0) && ((((int *)((int)puVar3 + 200))[7] & 1U) != 0)) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          ((char **)((int)puVar3 + 0x88))[7] = (char *)0x0;
        }
        pcVar7 = ((char **)((int)puVar3 + 0x88))[8];
        ((int *)((int)puVar3 + 200))[7] = 0;
        if ((pcVar7 != (char *)0x0) && ((((int *)((int)puVar3 + 200))[8] & 1U) != 0)) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          ((char **)((int)puVar3 + 0x88))[8] = (char *)0x0;
        }
        pcVar7 = ((char **)((int)puVar3 + 0x88))[9];
        ((int *)((int)puVar3 + 200))[8] = 0;
        if ((pcVar7 != (char *)0x0) && ((((int *)((int)puVar3 + 200))[9] & 1U) != 0)) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          ((char **)((int)puVar3 + 0x88))[9] = (char *)0x0;
        }
        pcVar7 = ((char **)((int)puVar3 + 0x88))[10];
        ((int *)((int)puVar3 + 200))[9] = 0;
        if ((pcVar7 != (char *)0x0) && ((((int *)((int)puVar3 + 200))[10] & 1U) != 0)) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          ((char **)((int)puVar3 + 0x88))[10] = (char *)0x0;
        }
        pcVar7 = ((char **)((int)puVar3 + 0x88))[0xb];
        ((int *)((int)puVar3 + 200))[10] = 0;
        if ((pcVar7 != (char *)0x0) && ((((int *)((int)puVar3 + 200))[0xb] & 1U) != 0)) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          ((char **)((int)puVar3 + 0x88))[0xb] = (char *)0x0;
        }
        pcVar7 = ((char **)((int)puVar3 + 0x88))[0xc];
        ((int *)((int)puVar3 + 200))[0xb] = 0;
        if ((pcVar7 != (char *)0x0) && ((((int *)((int)puVar3 + 200))[0xc] & 1U) != 0)) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          ((char **)((int)puVar3 + 0x88))[0xc] = (char *)0x0;
        }
        pcVar7 = ((char **)((int)puVar3 + 0x88))[0xd];
        ((int *)((int)puVar3 + 200))[0xc] = 0;
        if ((pcVar7 != (char *)0x0) && ((((int *)((int)puVar3 + 200))[0xd] & 1U) != 0)) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          ((char **)((int)puVar3 + 0x88))[0xd] = (char *)0x0;
        }
        pcVar7 = ((char **)((int)puVar3 + 0x88))[0xe];
        ((int *)((int)puVar3 + 200))[0xd] = 0;
        if ((pcVar7 != (char *)0x0) && ((((int *)((int)puVar3 + 200))[0xe] & 1U) != 0)) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          ((char **)((int)puVar3 + 0x88))[0xe] = (char *)0x0;
        }
        pcVar7 = ((char **)((int)puVar3 + 0x88))[0xf];
        ((int *)((int)puVar3 + 200))[0xe] = 0;
        if ((pcVar7 != (char *)0x0) && ((((int *)((int)puVar3 + 200))[0xf] & 1U) != 0)) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          ((char **)((int)puVar3 + 0x88))[0xf] = (char *)0x0;
        }
        puVar1 = PTR_CRYPTO_free_006a6e88;
        ((int *)((int)puVar3 + 200))[0xf] = 0;
        (*(code *)puVar1)(puVar3);
        puVar3 = fallback_5580;
      }
    }
  }
  if (local_1c != *(int *)puVar2) {
    iVar4 = local_1c;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    pEVar5 = ERR_get_state();
    uVar6 = pEVar5->top + 1U & 0x8000000f;
    if ((int)uVar6 < 0) {
      uVar6 = (uVar6 - 1 | 0xfffffff0) + 1;
    }
    pEVar5->top = uVar6;
    if (uVar6 == pEVar5->bottom) {
      uVar8 = uVar6 + 1 & 0x8000000f;
      if ((int)uVar8 < 0) {
        pEVar5->bottom = (uVar8 - 1 | 0xfffffff0) + 1;
      }
      else {
        pEVar5->bottom = uVar8;
      }
    }
    pEVar5->err_line[uVar6] = (int)&_gp;
    pEVar5->err_flags[uVar6] = 0;
    pEVar5->err_file[uVar6] = in_a3;
    pEVar5->err_buffer[uVar6] = ((uint)pcVar9 & 0xfff) << 0xc | (uint)in_a2 & 0xfff | iVar4 << 0x18;
    if ((pEVar5->err_data[uVar6] != (char *)0x0) && ((pEVar5->err_data_flags[uVar6] & 1U) != 0)) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
      uVar6 = pEVar5->top;
      pEVar5->err_data[uVar6] = (char *)0x0;
    }
    (((ERR_STATE *)(pEVar5->err_data_flags + uVar6))->tid).ptr = (void *)0x0;
    return (ERR_STATE *)(pEVar5->err_data_flags + uVar6);
  }
  return (ERR_STATE *)puVar3;
}

