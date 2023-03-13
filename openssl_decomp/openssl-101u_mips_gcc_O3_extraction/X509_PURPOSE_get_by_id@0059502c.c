
int X509_PURPOSE_get_by_id(int id)

{
  undefined *puVar1;
  undefined *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int **ppiVar7;
  int **ppiVar8;
  uint in_a2;
  int in_a3;
  int *piVar9;
  undefined1 *puVar10;
  int **appiStack_88 [7];
  int iStack_6c;
  undefined *puStack_68;
  undefined4 uStack_2c;
  int *local_28 [7];
  int **local_c;
  
  puStack_68 = PTR___stack_chk_guard_006a9ae8;
  uVar4 = id - 1;
  local_c = *(int ***)PTR___stack_chk_guard_006a9ae8;
  ppiVar8 = local_c;
  if (8 < uVar4) {
    local_28[0] = (int *)id;
    if (xptable != 0) {
      ppiVar8 = local_28;
      iVar5 = (*(code *)PTR_sk_find_006a8044)();
      if (iVar5 != -1) {
        uVar4 = iVar5 + 9;
        goto LAB_0059508c;
      }
    }
    uVar4 = 0xffffffff;
  }
LAB_0059508c:
  if (local_c == *(int ***)puStack_68) {
    return uVar4;
  }
  ppiVar7 = local_c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  piVar3 = local_28[0];
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  uVar4 = (int)ppiVar7 - 1;
  iStack_6c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (uVar4 < 9) {
LAB_00595134:
    if ((int)uVar4 < 9) {
      piVar9 = (int *)(xstandard + uVar4 * 0x1c);
    }
    else {
LAB_005952cc:
      piVar9 = (int *)(*(code *)PTR_sk_value_006a6e24)(xptable,uVar4 - 9);
    }
    if ((piVar9[2] & 2U) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(piVar9[4]);
      (*(code *)PTR_CRYPTO_free_006a6e88)(piVar9[5]);
    }
  }
  else {
    appiStack_88[0] = ppiVar7;
    if (((xptable != 0) &&
        (iVar5 = (*(code *)PTR_sk_find_006a8044)(xptable,appiStack_88), iVar5 != -1)) &&
       (uVar4 = iVar5 + 9, uVar4 != 0xffffffff)) {
      if (-1 < (int)uVar4) goto LAB_00595134;
      trap(0);
      goto LAB_005952cc;
    }
    piVar9 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x1c,"v3_purp.c",0xd6);
    if (piVar9 == (int *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x89,0x41,"v3_purp.c",0xd7);
      iVar5 = 0;
      goto LAB_005951f0;
    }
    uVar4 = 0xffffffff;
    piVar9[2] = 1;
  }
  iVar5 = (*(code *)PTR_BUF_strdup_006a6fdc)(&_gp);
  puVar1 = PTR_BUF_strdup_006a6fdc;
  piVar9[4] = iVar5;
  iVar5 = (*(code *)puVar1)(uStack_2c);
  piVar9[5] = iVar5;
  if ((piVar9[4] == 0) || (iVar5 == 0)) {
    uVar6 = 0xe7;
LAB_00595344:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x89,0x41,"v3_purp.c",uVar6);
    iVar5 = 0;
  }
  else {
    *piVar9 = (int)ppiVar7;
    piVar9[1] = (int)ppiVar8;
    piVar9[3] = in_a3;
    piVar9[6] = (int)piVar3;
    piVar9[2] = piVar9[2] & 1U | 2 | in_a2 & 0xfffffffe;
    if (uVar4 == 0xffffffff) {
      if ((xptable == 0) && (xptable = (*(code *)PTR_sk_new_006a806c)(xp_cmp), xptable == 0)) {
        uVar6 = 0xf7;
        goto LAB_00595344;
      }
      iVar5 = (*(code *)PTR_sk_push_006a6fa8)(xptable,piVar9);
      if (iVar5 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x89,0x41,"v3_purp.c",0xfb);
        goto LAB_005951f0;
      }
    }
    iVar5 = 1;
  }
LAB_005951f0:
  if (iStack_6c == *(int *)puVar2) {
    return iVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar10 = xstandard;
  uVar4 = (*(code *)PTR_sk_pop_free_006a7058)(xptable,xptable_free);
  do {
    if ((puVar10 != (undefined *)0x0) &&
       (uVar4 = *(uint *)(puVar10 + 8) & 2, (*(uint *)(puVar10 + 8) & 1) != 0)) {
      if (uVar4 != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(puVar10 + 0x10));
        (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(puVar10 + 0x14));
      }
      uVar4 = (*(code *)PTR_CRYPTO_free_006a6e88)(puVar10);
    }
    puVar10 = puVar10 + 0x1c;
  } while (puVar10 != &UNK_006a1dec);
  xptable = 0;
  return uVar4;
}

