
int X509_PURPOSE_add(int id,int trust,int flags,ck *ck,char *name,char *sname,void *arg)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined1 *puVar6;
  uint uVar7;
  int local_48 [7];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  uVar7 = id - 1;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (uVar7 < 9) {
LAB_00597e84:
    if ((int)uVar7 < 9) {
      piVar5 = (int *)(xstandard + uVar7 * 0x1c);
    }
    else {
LAB_0059801c:
      piVar5 = (int *)(*(code *)PTR_sk_value_006a7f24)(xptable,uVar7 - 9);
    }
    if ((piVar5[2] & 2U) != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(piVar5[4]);
      (*(code *)PTR_CRYPTO_free_006a7f88)(piVar5[5]);
    }
  }
  else {
    local_48[0] = id;
    if (((xptable != 0) && (iVar3 = (*(code *)PTR_sk_find_006a906c)(xptable,local_48), iVar3 != -1))
       && (uVar7 = iVar3 + 9, uVar7 != 0xffffffff)) {
      if (-1 < (int)uVar7) goto LAB_00597e84;
      trap(0);
      goto LAB_0059801c;
    }
    piVar5 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x1c,"v3_purp.c",0xba);
    if (piVar5 == (int *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x89,0x41,"v3_purp.c",0xbb);
      iVar3 = 0;
      goto LAB_00597f40;
    }
    uVar7 = 0xffffffff;
    piVar5[2] = 1;
  }
  iVar3 = (*(code *)PTR_BUF_strdup_006a80dc)(name);
  puVar1 = PTR_BUF_strdup_006a80dc;
  piVar5[4] = iVar3;
  iVar3 = (*(code *)puVar1)(sname);
  piVar5[5] = iVar3;
  if ((piVar5[4] == 0) || (iVar3 == 0)) {
    uVar4 = 0xca;
LAB_00598094:
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x89,0x41,"v3_purp.c",uVar4);
    iVar3 = 0;
  }
  else {
    *piVar5 = id;
    piVar5[1] = trust;
    piVar5[3] = (int)ck;
    piVar5[6] = (int)arg;
    piVar5[2] = piVar5[2] & 1U | 2 | flags & 0xfffffffeU;
    if (uVar7 == 0xffffffff) {
      if ((xptable == 0) && (xptable = (*(code *)PTR_sk_new_006a91b4)(xp_cmp), xptable == 0)) {
        uVar4 = 0xda;
        goto LAB_00598094;
      }
      iVar3 = (*(code *)PTR_sk_push_006a80a8)(xptable,piVar5);
      if (iVar3 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x89,0x41,"v3_purp.c",0xde);
        goto LAB_00597f40;
      }
    }
    iVar3 = 1;
  }
LAB_00597f40:
  if (local_2c == *(int *)puVar2) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar6 = xstandard;
  uVar7 = (*(code *)PTR_sk_pop_free_006a8158)(xptable,xptable_free);
  do {
    if ((puVar6 != (undefined *)0x0) &&
       (uVar7 = *(uint *)(puVar6 + 8) & 2, (*(uint *)(puVar6 + 8) & 1) != 0)) {
      if (uVar7 != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(puVar6 + 0x10));
        (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(puVar6 + 0x14));
      }
      uVar7 = (*(code *)PTR_CRYPTO_free_006a7f88)(puVar6);
    }
    puVar6 = puVar6 + 0x1c;
  } while (puVar6 != &UNK_006a2f4c);
  xptable = 0;
  return uVar7;
}

