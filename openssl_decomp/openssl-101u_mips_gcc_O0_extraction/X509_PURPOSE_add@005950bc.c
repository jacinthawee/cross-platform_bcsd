
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
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  uVar7 = id - 1;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (uVar7 < 9) {
LAB_00595134:
    if ((int)uVar7 < 9) {
      piVar5 = (int *)(xstandard + uVar7 * 0x1c);
    }
    else {
LAB_005952cc:
      piVar5 = (int *)(*(code *)PTR_sk_value_006a6e24)(xptable,uVar7 - 9);
    }
    if ((piVar5[2] & 2U) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(piVar5[4]);
      (*(code *)PTR_CRYPTO_free_006a6e88)(piVar5[5]);
    }
  }
  else {
    local_48[0] = id;
    if (((xptable != 0) && (iVar3 = (*(code *)PTR_sk_find_006a8044)(xptable,local_48), iVar3 != -1))
       && (uVar7 = iVar3 + 9, uVar7 != 0xffffffff)) {
      if (-1 < (int)uVar7) goto LAB_00595134;
      trap(0);
      goto LAB_005952cc;
    }
    piVar5 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x1c,"v3_purp.c",0xd6);
    if (piVar5 == (int *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x89,0x41,"v3_purp.c",0xd7);
      iVar3 = 0;
      goto LAB_005951f0;
    }
    uVar7 = 0xffffffff;
    piVar5[2] = 1;
  }
  iVar3 = (*(code *)PTR_BUF_strdup_006a6fdc)(name);
  puVar1 = PTR_BUF_strdup_006a6fdc;
  piVar5[4] = iVar3;
  iVar3 = (*(code *)puVar1)(sname);
  piVar5[5] = iVar3;
  if ((piVar5[4] == 0) || (iVar3 == 0)) {
    uVar4 = 0xe7;
LAB_00595344:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x89,0x41,"v3_purp.c",uVar4);
    iVar3 = 0;
  }
  else {
    *piVar5 = id;
    piVar5[1] = trust;
    piVar5[3] = (int)ck;
    piVar5[6] = (int)arg;
    piVar5[2] = piVar5[2] & 1U | 2 | flags & 0xfffffffeU;
    if (uVar7 == 0xffffffff) {
      if ((xptable == 0) && (xptable = (*(code *)PTR_sk_new_006a806c)(xp_cmp), xptable == 0)) {
        uVar4 = 0xf7;
        goto LAB_00595344;
      }
      iVar3 = (*(code *)PTR_sk_push_006a6fa8)(xptable,piVar5);
      if (iVar3 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x89,0x41,"v3_purp.c",0xfb);
        goto LAB_005951f0;
      }
    }
    iVar3 = 1;
  }
LAB_005951f0:
  if (local_2c == *(int *)puVar2) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar6 = xstandard;
  uVar7 = (*(code *)PTR_sk_pop_free_006a7058)(xptable,xptable_free);
  do {
    if ((puVar6 != (undefined *)0x0) &&
       (uVar7 = *(uint *)(puVar6 + 8) & 2, (*(uint *)(puVar6 + 8) & 1) != 0)) {
      if (uVar7 != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(puVar6 + 0x10));
        (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(puVar6 + 0x14));
      }
      uVar7 = (*(code *)PTR_CRYPTO_free_006a6e88)(puVar6);
    }
    puVar6 = puVar6 + 0x1c;
  } while (puVar6 != &UNK_006a1dec);
  xptable = 0;
  return uVar7;
}

