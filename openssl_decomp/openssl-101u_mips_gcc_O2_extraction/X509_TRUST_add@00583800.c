
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
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  uVar2 = id - 1;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (uVar2 < 8) {
LAB_0058386c:
    if ((int)uVar2 < 8) {
      piVar5 = (int *)(trstandard + uVar2 * 0x18);
    }
    else {
LAB_005839c8:
      piVar5 = (int *)(*(code *)PTR_sk_value_006a6e24)(trtable,uVar2 - 8);
    }
    if ((piVar5[1] & 2U) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(piVar5[3]);
    }
  }
  else {
    local_44[0] = id;
    if (((trtable != 0) && (iVar3 = (*(code *)PTR_sk_find_006a8044)(trtable,local_44), iVar3 != -1))
       && (uVar2 = iVar3 + 8, uVar2 != 0xffffffff)) {
      if (-1 < (int)uVar2) goto LAB_0058386c;
      trap(0);
      goto LAB_005839c8;
    }
    piVar5 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x18,"x509_trs.c",0xb9);
    if (piVar5 == (int *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x85,0x41,"x509_trs.c",0xba);
      iVar3 = 0;
      goto LAB_005838f4;
    }
    uVar2 = 0xffffffff;
    piVar5[1] = 1;
  }
  iVar3 = (*(code *)PTR_BUF_strdup_006a6fdc)(name);
  piVar5[3] = iVar3;
  if (iVar3 == 0) {
    uVar4 = 0xc6;
LAB_00583a4c:
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x85,0x41,"x509_trs.c",uVar4);
    iVar3 = 0;
  }
  else {
    *piVar5 = id;
    piVar5[2] = (int)ck;
    piVar5[5] = (int)arg2;
    piVar5[4] = arg1;
    piVar5[1] = piVar5[1] & 1U | 2 | flags & 0xfffffffeU;
    if (uVar2 == 0xffffffff) {
      if ((trtable == 0) && (trtable = (*(code *)PTR_sk_new_006a806c)(tr_cmp), trtable == 0)) {
        uVar4 = 0xd6;
        goto LAB_00583a4c;
      }
      iVar3 = (*(code *)PTR_sk_push_006a6fa8)(trtable,piVar5);
      if (iVar3 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x85,0x41,"x509_trs.c",0xda);
        goto LAB_005838f4;
      }
    }
    iVar3 = 1;
  }
LAB_005838f4:
  if (local_2c == *(int *)puVar1) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar6 = trstandard;
  do {
    if (((undefined **)puVar6 != (undefined **)0x0) &&
       (((uint)*(undefined **)((int)puVar6 + 4) & 1) != 0)) {
      if (((uint)*(undefined **)((int)puVar6 + 4) & 2) != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined **)((int)puVar6 + 0xc));
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(puVar6);
    }
    puVar6 = (undefined1 *)((int)puVar6 + 0x18);
  } while ((undefined **)puVar6 != &default_trust);
  iVar3 = (*(code *)PTR_sk_pop_free_006a7058)(trtable,trtable_free);
  trtable = 0;
  return iVar3;
}

