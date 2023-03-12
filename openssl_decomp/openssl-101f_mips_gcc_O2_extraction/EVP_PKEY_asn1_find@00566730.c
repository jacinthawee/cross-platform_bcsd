
/* WARNING: Restarted to delay deadcode elimination for space: ram */

EVP_PKEY_ASN1_METHOD * EVP_PKEY_asn1_find(ENGINE **pe,int type)

{
  undefined *puVar1;
  EVP_PKEY_ASN1_METHOD **ppEVar2;
  undefined1 *puVar3;
  ENGINE *pEVar4;
  EVP_PKEY_ASN1_METHOD *pEVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int in_a2;
  undefined1 *puVar9;
  undefined4 uVar10;
  code *pcVar11;
  undefined4 uStack_f0;
  int iStack_ec;
  EVP_PKEY_ASN1_METHOD *pEStack_e4;
  undefined1 *puStack_e0;
  undefined1 *puStack_dc;
  undefined1 *puStack_d8;
  code *pcStack_d4;
  undefined1 *puStack_d0;
  undefined *puStack_cc;
  ENGINE **ppEStack_c8;
  code *pcStack_c4;
  code *local_b0;
  undefined *local_a8;
  undefined1 **local_9c;
  undefined1 *local_98 [27];
  undefined4 *local_2c;
  
  puStack_cc = PTR___stack_chk_guard_006aabf0;
  local_a8 = &_gp;
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
LAB_005667e4:
  local_9c = local_98;
  local_98[0] = (undefined1 *)type;
  if ((app_methods != 0) &&
     (puVar3 = (undefined1 *)(**(code **)(local_a8 + -0x6e74))(app_methods,local_98),
     -1 < (int)puVar3)) {
    pEStack_e4 = (EVP_PKEY_ASN1_METHOD *)(**(code **)(local_a8 + -0x7fbc))(app_methods,puVar3);
    if (pEStack_e4 == (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_00566820;
LAB_005667d0:
    if ((*(uint *)(pEStack_e4 + 8) & 1) == 0) goto LAB_00566820;
    type = *(int *)(pEStack_e4 + 4);
    goto LAB_005667e4;
  }
  in_a2 = 0xb;
  local_b0 = ameth_cmp_BSEARCH_CMP_FN;
  puVar3 = standard_methods;
  ppEVar2 = (EVP_PKEY_ASN1_METHOD **)
            (**(code **)(local_a8 + -0x6a58))(&local_9c,standard_methods,0xb,4);
  if ((ppEVar2 != (EVP_PKEY_ASN1_METHOD **)0x0) &&
     (pEStack_e4 = *ppEVar2, pEStack_e4 != (EVP_PKEY_ASN1_METHOD *)0x0)) goto LAB_005667d0;
  pEStack_e4 = (EVP_PKEY_ASN1_METHOD *)0x0;
LAB_00566820:
  if (pe != (ENGINE **)0x0) {
    pEVar4 = (ENGINE *)(**(code **)(local_a8 + -0x600c))(type);
    if (pEVar4 == (ENGINE *)0x0) {
      *pe = (ENGINE *)0x0;
    }
    else {
      pcVar11 = *(code **)(local_a8 + -0x6008);
      *pe = pEVar4;
      puVar3 = (undefined1 *)type;
      pEStack_e4 = (EVP_PKEY_ASN1_METHOD *)(*pcVar11)(pEVar4,type);
    }
  }
  if (local_2c == *(undefined4 **)puStack_cc) {
    return pEStack_e4;
  }
  pcStack_c4 = EVP_PKEY_asn1_find_str;
  puVar8 = local_2c;
  (**(code **)(local_a8 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  puStack_d0 = &_ITM_registerTMCloneTable;
  pcStack_d4 = ameth_cmp_BSEARCH_CMP_FN;
  puStack_d8 = standard_methods;
  puStack_dc = &_ITM_registerTMCloneTable;
  iStack_ec = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_e0 = (undefined1 *)type;
  ppEStack_c8 = pe;
  if (in_a2 == -1) {
    in_a2 = (*(code *)PTR_strlen_006aab30)(puVar3);
  }
  if (puVar8 != (undefined4 *)0x0) {
    pEVar5 = (EVP_PKEY_ASN1_METHOD *)
             (*(code *)PTR_ENGINE_pkey_asn1_find_str_006a9edc)(&uStack_f0,puVar3,in_a2);
    if (pEVar5 != (EVP_PKEY_ASN1_METHOD *)0x0) {
      iVar6 = (*(code *)PTR_ENGINE_init_006a8e68)(uStack_f0);
      if (iVar6 == 0) {
        pEVar5 = (EVP_PKEY_ASN1_METHOD *)0x0;
      }
      (*(code *)PTR_ENGINE_free_006a7f84)(uStack_f0);
      *puVar8 = uStack_f0;
      goto LAB_00566958;
    }
    *puVar8 = 0;
  }
  iVar6 = 0;
  puVar9 = standard_methods;
  if (app_methods == 0) goto LAB_00566a14;
  while (iVar7 = (*(code *)PTR_sk_num_006a7f2c)(), iVar6 < iVar7 + 0xb) {
    while( true ) {
      if (iVar6 < 0xb) {
        pEVar5 = *(EVP_PKEY_ASN1_METHOD **)puVar9;
      }
      else {
        pEVar5 = (EVP_PKEY_ASN1_METHOD *)(*(code *)PTR_sk_value_006a7f24)(app_methods,iVar6 + -0xb);
      }
      if ((*(uint *)(pEVar5 + 8) & 1) == 0) {
        uVar10 = *(undefined4 *)(pEVar5 + 0xc);
        iVar7 = (*(code *)PTR_strlen_006aab30)(uVar10);
        if ((in_a2 == iVar7) &&
           (iVar7 = (*(code *)PTR_strncasecmp_006aaae0)(uVar10,puVar3,in_a2), iVar7 == 0))
        goto LAB_00566958;
      }
      puVar9 = (undefined1 *)((int)puVar9 + 4);
      iVar6 = iVar6 + 1;
      if (app_methods != 0) break;
LAB_00566a14:
      if (10 < iVar6) goto LAB_00566a24;
    }
  }
LAB_00566a24:
  pEVar5 = (EVP_PKEY_ASN1_METHOD *)0x0;
LAB_00566958:
  if (iStack_ec == *(int *)puVar1) {
    return pEVar5;
  }
  iVar6 = iStack_ec;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (((app_methods != 0) ||
      (app_methods = (*(code *)PTR_sk_new_006a91b4)(ameth_cmp), app_methods != 0)) &&
     (iVar6 = (*(code *)PTR_sk_push_006a80a8)(app_methods,iVar6), iVar6 != 0)) {
    (*(code *)PTR_sk_sort_006a94d8)(app_methods);
    return (EVP_PKEY_ASN1_METHOD *)0x1;
  }
  return (EVP_PKEY_ASN1_METHOD *)0x0;
}

