
int X509_VERIFY_PARAM_set_trust(X509_VERIFY_PARAM *param,int trust)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int in_a2;
  char *in_a3;
  int *piVar7;
  undefined1 *puVar8;
  int aiStack_94 [6];
  int iStack_7c;
  int iStack_74;
  undefined *puStack_70;
  int *piStack_6c;
  int iStack_40;
  int iStack_3c;
  int aiStack_2c [6];
  int iStack_14;
  
  puStack_70 = PTR___stack_chk_guard_006aabf0;
  piStack_6c = &param->trust;
  iStack_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  piVar6 = (int *)trust;
  if (trust - 1U < 8) {
LAB_005864f8:
    iVar2 = 1;
    *piStack_6c = trust;
  }
  else {
    aiStack_2c[0] = trust;
    if (trtable != 0) {
      piVar6 = aiStack_2c;
      iVar2 = (*(code *)PTR_sk_find_006a906c)();
      if ((iVar2 != -1) && (iVar2 != -9)) goto LAB_005864f8;
    }
    in_a2 = 0x7b;
    in_a3 = "x509_trs.c";
    iStack_40 = 0x98;
    piVar6 = (int *)0x8d;
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x8d,0x7b,"x509_trs.c");
    iVar2 = 0;
  }
  if (iStack_14 == *(int *)puStack_70) {
    return iVar2;
  }
  iVar2 = iStack_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  uVar3 = iVar2 - 1;
  iStack_7c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_74 = trust;
  if (uVar3 < 8) {
LAB_005865fc:
    if ((int)uVar3 < 8) {
      piVar7 = (int *)(trstandard + uVar3 * 0x18);
    }
    else {
LAB_00586758:
      piVar7 = (int *)(*(code *)PTR_sk_value_006a7f24)(trtable,uVar3 - 8);
    }
    if ((piVar7[1] & 2U) != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(piVar7[3]);
    }
  }
  else {
    aiStack_94[0] = iVar2;
    if (((trtable != 0) &&
        (iVar4 = (*(code *)PTR_sk_find_006a906c)(trtable,aiStack_94), iVar4 != -1)) &&
       (uVar3 = iVar4 + 8, uVar3 != 0xffffffff)) {
      if (-1 < (int)uVar3) goto LAB_005865fc;
      trap(0);
      goto LAB_00586758;
    }
    piVar7 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x18,"x509_trs.c",0xac);
    if (piVar7 == (int *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x85,0x41,"x509_trs.c",0xad);
      iVar2 = 0;
      goto LAB_00586684;
    }
    uVar3 = 0xffffffff;
    piVar7[1] = 1;
  }
  iVar4 = (*(code *)PTR_BUF_strdup_006a80dc)(in_a3);
  piVar7[3] = iVar4;
  if (iVar4 == 0) {
    uVar5 = 0xb7;
LAB_005867dc:
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x85,0x41,"x509_trs.c",uVar5);
    iVar2 = 0;
  }
  else {
    *piVar7 = iVar2;
    piVar7[2] = in_a2;
    piVar7[5] = iStack_3c;
    piVar7[4] = iStack_40;
    piVar7[1] = piVar7[1] & 1U | 2 | (uint)piVar6 & 0xfffffffe;
    if (uVar3 == 0xffffffff) {
      if ((trtable == 0) && (trtable = (*(code *)PTR_sk_new_006a91b4)(tr_cmp), trtable == 0)) {
        uVar5 = 199;
        goto LAB_005867dc;
      }
      iVar2 = (*(code *)PTR_sk_push_006a80a8)(trtable,piVar7);
      if (iVar2 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x85,0x41,"x509_trs.c",0xcb);
        goto LAB_00586684;
      }
    }
    iVar2 = 1;
  }
LAB_00586684:
  if (iStack_7c == *(int *)puVar1) {
    return iVar2;
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
  iVar2 = (*(code *)PTR_sk_pop_free_006a8158)(trtable,trtable_free);
  trtable = 0;
  return iVar2;
}

