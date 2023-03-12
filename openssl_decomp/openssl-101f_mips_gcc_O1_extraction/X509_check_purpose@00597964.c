
int X509_check_purpose(X509 *x,int id,int ca)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  X509 **ppXVar5;
  X509 *pXVar6;
  X509 *apXStack_80 [7];
  int iStack_64;
  undefined *puStack_60;
  int iStack_5c;
  X509 *pXStack_58;
  code *pcStack_54;
  undefined *local_40;
  X509_CINF *local_38;
  X509 **local_1c;
  
  puStack_60 = PTR___stack_chk_guard_006aabf0;
  local_40 = &_gp;
  local_1c = *(X509 ***)PTR___stack_chk_guard_006aabf0;
  if ((x->ex_flags & 0x100) == 0) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,3,"v3_purp.c",0x72);
    if ((x->ex_flags & 0x100) == 0) {
      x509v3_cache_extensions_part_6(x);
    }
    pXVar6 = (X509 *)0x3;
    (**(code **)(local_40 + -0x6c74))(10,3,"v3_purp.c",0x74);
    if (id == -1) {
      uVar2 = 1;
      goto LAB_00597a00;
    }
  }
  else {
    uVar2 = 1;
    pXVar6 = (X509 *)id;
    if (id == -1) goto LAB_00597a00;
  }
  uVar2 = id - 1;
  if (uVar2 < 9) {
LAB_005979cc:
    if ((int)uVar2 < 9) {
      puVar4 = xstandard + uVar2 * 0x1c;
    }
    else {
LAB_00597ac4:
      puVar4 = (undefined1 *)(**(code **)(local_40 + -0x7fbc))(xptable);
    }
    pXVar6 = x;
    uVar2 = (**(code **)(puVar4 + 0xc))(puVar4,x,ca);
  }
  else {
    local_38 = (X509_CINF *)id;
    if (xptable != 0) {
      pXVar6 = (X509 *)&local_38;
      iVar3 = (**(code **)(local_40 + -0x6e74))();
      if (iVar3 != -1) {
        uVar2 = iVar3 + 9;
        if (uVar2 == 0xffffffff) goto LAB_00597a00;
        if (-1 < (int)uVar2) goto LAB_005979cc;
        trap(0);
        goto LAB_00597ac4;
      }
    }
    uVar2 = 0xffffffff;
  }
LAB_00597a00:
  if (local_1c == *(X509 ***)puStack_60) {
    return uVar2;
  }
  pcStack_54 = X509_PURPOSE_set;
  ppXVar5 = local_1c;
  (**(code **)(local_40 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_64 = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_5c = ca;
  pXStack_58 = x;
  if (((undefined *)((int)&pXVar6[-1].aux + 3) < &DAT_00000009) ||
     (((apXStack_80[0] = pXVar6, xptable != 0 &&
       (iVar3 = (*(code *)PTR_sk_find_006a906c)(xptable,apXStack_80), iVar3 != -1)) &&
      (iVar3 != -10)))) {
    iVar3 = 1;
    *ppXVar5 = pXVar6;
  }
  else {
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x8d,0x92,"v3_purp.c",0x80);
    iVar3 = 0;
  }
  if (iStack_64 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    if (xptable == 0) {
      return 9;
    }
    iVar3 = (*(code *)PTR_sk_num_006a7f2c)();
    return iVar3 + 9;
  }
  return iVar3;
}

