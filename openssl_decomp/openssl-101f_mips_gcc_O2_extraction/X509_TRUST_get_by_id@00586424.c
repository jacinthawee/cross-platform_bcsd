
int X509_TRUST_get_by_id(int id)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int ****ppppiVar6;
  int in_a2;
  char *in_a3;
  int *piVar7;
  undefined1 *puVar8;
  int aiStack_d4 [6];
  int iStack_bc;
  int ****ppppiStack_b4;
  undefined *puStack_b0;
  int ****ppppiStack_ac;
  int iStack_80;
  int iStack_7c;
  int ****appppiStack_6c [6];
  int iStack_54;
  undefined *puStack_50;
  int ***local_24 [6];
  int ****local_c;
  
  puStack_50 = PTR___stack_chk_guard_006aabf0;
  uVar2 = id - 1;
  local_c = *(int *****)PTR___stack_chk_guard_006aabf0;
  ppppiStack_b4 = local_c;
  if (7 < uVar2) {
    local_24[0] = (int ***)id;
    if (trtable != 0) {
      ppppiStack_b4 = local_24;
      iVar3 = (*(code *)PTR_sk_find_006a906c)();
      if (iVar3 != -1) {
        uVar2 = iVar3 + 8;
        goto LAB_00586484;
      }
    }
    uVar2 = 0xffffffff;
  }
LAB_00586484:
  if (local_c == *(int *****)puStack_50) {
    return uVar2;
  }
  ppppiStack_ac = local_c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_b0 = PTR___stack_chk_guard_006aabf0;
  iStack_54 = *(int *)PTR___stack_chk_guard_006aabf0;
  ppppiVar6 = ppppiStack_b4;
  if ((int)ppppiStack_b4 - 1U < 8) {
LAB_005864f8:
    iVar3 = 1;
    *ppppiStack_ac = (int ***)ppppiStack_b4;
  }
  else {
    appppiStack_6c[0] = ppppiStack_b4;
    if (trtable != 0) {
      ppppiVar6 = (int ****)appppiStack_6c;
      iVar3 = (*(code *)PTR_sk_find_006a906c)();
      if ((iVar3 != -1) && (iVar3 != -9)) goto LAB_005864f8;
    }
    in_a2 = 0x7b;
    in_a3 = "x509_trs.c";
    iStack_80 = 0x98;
    ppppiVar6 = (int ****)0x8d;
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x8d,0x7b,"x509_trs.c");
    iVar3 = 0;
  }
  if (iStack_54 == *(int *)puStack_b0) {
    return iVar3;
  }
  iVar3 = iStack_54;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  uVar2 = iVar3 - 1;
  iStack_bc = *(int *)PTR___stack_chk_guard_006aabf0;
  if (uVar2 < 8) {
LAB_005865fc:
    if ((int)uVar2 < 8) {
      piVar7 = (int *)(trstandard + uVar2 * 0x18);
    }
    else {
LAB_00586758:
      piVar7 = (int *)(*(code *)PTR_sk_value_006a7f24)(trtable,uVar2 - 8);
    }
    if ((piVar7[1] & 2U) != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(piVar7[3]);
    }
  }
  else {
    aiStack_d4[0] = iVar3;
    if (((trtable != 0) &&
        (iVar4 = (*(code *)PTR_sk_find_006a906c)(trtable,aiStack_d4), iVar4 != -1)) &&
       (uVar2 = iVar4 + 8, uVar2 != 0xffffffff)) {
      if (-1 < (int)uVar2) goto LAB_005865fc;
      trap(0);
      goto LAB_00586758;
    }
    piVar7 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x18,"x509_trs.c",0xac);
    if (piVar7 == (int *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x85,0x41,"x509_trs.c",0xad);
      iVar3 = 0;
      goto LAB_00586684;
    }
    uVar2 = 0xffffffff;
    piVar7[1] = 1;
  }
  iVar4 = (*(code *)PTR_BUF_strdup_006a80dc)(in_a3);
  piVar7[3] = iVar4;
  if (iVar4 == 0) {
    uVar5 = 0xb7;
LAB_005867dc:
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x85,0x41,"x509_trs.c",uVar5);
    iVar3 = 0;
  }
  else {
    *piVar7 = iVar3;
    piVar7[2] = in_a2;
    piVar7[5] = iStack_7c;
    piVar7[4] = iStack_80;
    piVar7[1] = piVar7[1] & 1U | 2 | (uint)ppppiVar6 & 0xfffffffe;
    if (uVar2 == 0xffffffff) {
      if ((trtable == 0) && (trtable = (*(code *)PTR_sk_new_006a91b4)(tr_cmp), trtable == 0)) {
        uVar5 = 199;
        goto LAB_005867dc;
      }
      iVar3 = (*(code *)PTR_sk_push_006a80a8)(trtable,piVar7);
      if (iVar3 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x85,0x41,"x509_trs.c",0xcb);
        goto LAB_00586684;
      }
    }
    iVar3 = 1;
  }
LAB_00586684:
  if (iStack_bc == *(int *)puVar1) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar8 = trstandard;
  do {
    if (((undefined **)puVar8 != (undefined **)0x0) &&
       (((uint)*(undefined **)((int)puVar8 + 4) & 1) != 0)) {
      if (((uint)*(undefined **)((int)puVar8 + 4) & 2) != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined **)((int)puVar8 + 0xc));
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(puVar8);
    }
    puVar8 = (undefined1 *)((int)puVar8 + 0x18);
  } while ((undefined **)puVar8 != &default_trust);
  iVar3 = (*(code *)PTR_sk_pop_free_006a8158)(trtable,trtable_free);
  trtable = 0;
  return iVar3;
}

