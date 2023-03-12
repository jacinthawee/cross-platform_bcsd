
EVP_PKEY_METHOD * EVP_PKEY_meth_find(int type)

{
  undefined *puVar1;
  undefined1 *puVar2;
  EVP_PKEY_METHOD **ppEVar3;
  EVP_PKEY_METHOD *pEVar4;
  int *piVar5;
  int iVar6;
  int *local_84;
  int local_80 [27];
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_84 = local_80;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  local_80[0] = type;
  if (app_pkey_methods != (_STACK *)0x0) {
    puVar2 = (undefined1 *)sk_find(app_pkey_methods,local_84);
    if (-1 < (int)puVar2) {
      pEVar4 = (EVP_PKEY_METHOD *)sk_value(app_pkey_methods,(int)puVar2);
      goto LAB_00547c08;
    }
  }
  puVar2 = standard_methods;
  ppEVar3 = (EVP_PKEY_METHOD **)
            (*(code *)PTR_OBJ_bsearch__006a9488)
                      (&local_84,standard_methods,6,4,pmeth_cmp_BSEARCH_CMP_FN);
  if (ppEVar3 == (EVP_PKEY_METHOD **)0x0) {
    pEVar4 = (EVP_PKEY_METHOD *)0x0;
  }
  else {
    pEVar4 = *ppEVar3;
  }
LAB_00547c08:
  if (local_14 == *(int *)puVar1) {
    return pEVar4;
  }
  iVar6 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  piVar5 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x6c,"pmeth_lib.c",0xcb);
  if (piVar5 != (int *)0x0) {
    (*(code *)PTR_memset_006aab00)(piVar5,0,0x6c);
    *piVar5 = iVar6;
    piVar5[1] = (uint)puVar2 | 1;
    piVar5[2] = 0;
    piVar5[3] = 0;
    piVar5[4] = 0;
    piVar5[5] = 0;
    piVar5[6] = 0;
    piVar5[7] = 0;
    piVar5[8] = 0;
    piVar5[9] = 0;
    piVar5[10] = 0;
    piVar5[0xb] = 0;
    piVar5[0xc] = 0;
    piVar5[0xd] = 0;
    piVar5[0xe] = 0;
    piVar5[0xf] = 0;
    piVar5[0x10] = 0;
    piVar5[0x11] = 0;
    piVar5[0x12] = 0;
    piVar5[0x13] = 0;
    piVar5[0x14] = 0;
    piVar5[0x15] = 0;
    piVar5[0x16] = 0;
    piVar5[0x17] = 0;
    piVar5[0x18] = 0;
    piVar5[0x19] = 0;
    piVar5[0x1a] = 0;
  }
  return (EVP_PKEY_METHOD *)piVar5;
}

