
int X509_TRUST_add(int id,int flags,ck *ck,char *name,int arg1,void *arg2)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined1 *puVar6;
  int local_44 [6];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  uVar2 = id - 1;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (uVar2 < 8) {
LAB_005865fc:
    if ((int)uVar2 < 8) {
      piVar5 = (int *)(trstandard + uVar2 * 0x18);
    }
    else {
LAB_00586758:
      piVar5 = (int *)(*(code *)PTR_sk_value_006a7f24)(trtable,uVar2 - 8);
    }
    if ((piVar5[1] & 2U) != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(piVar5[3]);
    }
  }
  else {
    local_44[0] = id;
    if (((trtable != 0) && (iVar3 = (*(code *)PTR_sk_find_006a906c)(trtable,local_44), iVar3 != -1))
       && (uVar2 = iVar3 + 8, uVar2 != 0xffffffff)) {
      if (-1 < (int)uVar2) goto LAB_005865fc;
      trap(0);
      goto LAB_00586758;
    }
    piVar5 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x18,"x509_trs.c",0xac);
    if (piVar5 == (int *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x85,0x41,"x509_trs.c",0xad);
      iVar3 = 0;
      goto LAB_00586684;
    }
    uVar2 = 0xffffffff;
    piVar5[1] = 1;
  }
  iVar3 = (*(code *)PTR_BUF_strdup_006a80dc)(name);
  piVar5[3] = iVar3;
  if (iVar3 == 0) {
    uVar4 = 0xb7;
LAB_005867dc:
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x85,0x41,"x509_trs.c",uVar4);
    iVar3 = 0;
  }
  else {
    *piVar5 = id;
    piVar5[2] = (int)ck;
    piVar5[5] = (int)arg2;
    piVar5[4] = arg1;
    piVar5[1] = piVar5[1] & 1U | 2 | flags & 0xfffffffeU;
    if (uVar2 == 0xffffffff) {
      if ((trtable == 0) && (trtable = (*(code *)PTR_sk_new_006a91b4)(tr_cmp), trtable == 0)) {
        uVar4 = 199;
        goto LAB_005867dc;
      }
      iVar3 = (*(code *)PTR_sk_push_006a80a8)(trtable,piVar5);
      if (iVar3 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x85,0x41,"x509_trs.c",0xcb);
        goto LAB_00586684;
      }
    }
    iVar3 = 1;
  }
LAB_00586684:
  if (local_2c == *(int *)puVar1) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar6 = trstandard;
  do {
    if (((undefined **)puVar6 != (undefined **)0x0) &&
       (((uint)*(undefined **)((int)puVar6 + 4) & 1) != 0)) {
      if (((uint)*(undefined **)((int)puVar6 + 4) & 2) != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined **)((int)puVar6 + 0xc));
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(puVar6);
    }
    puVar6 = (undefined1 *)((int)puVar6 + 0x18);
  } while ((undefined **)puVar6 != &default_trust);
  iVar3 = (*(code *)PTR_sk_pop_free_006a8158)(trtable,trtable_free);
  trtable = 0;
  return iVar3;
}

