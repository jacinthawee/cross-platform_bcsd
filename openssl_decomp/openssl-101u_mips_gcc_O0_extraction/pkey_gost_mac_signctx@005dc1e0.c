
undefined4 pkey_gost_mac_signctx(undefined4 param_1,int param_2,undefined4 *param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  undefined *puVar25;
  undefined4 uVar26;
  int *piVar27;
  int iVar28;
  int *piVar29;
  int iVar30;
  uint uVar31;
  uint uVar32;
  undefined4 *puVar33;
  uint in_t0;
  uint in_t1;
  uint in_t2;
  undefined4 local_18;
  uint local_14;
  
  puVar25 = PTR___stack_chk_guard_006a9ae8;
  local_18 = *param_3;
  local_14 = *(uint *)PTR___stack_chk_guard_006a9ae8;
  if (param_2 == 0) {
    uVar26 = 1;
    *param_3 = 4;
  }
  else {
    puVar33 = &local_18;
    uVar26 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(param_4);
    *param_3 = local_18;
    param_3 = puVar33;
  }
  if (local_14 == *(uint *)puVar25) {
    return uVar26;
  }
  uVar31 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar32 = uVar31;
  piVar29 = param_4;
  piVar27 = (int *)(*(code *)PTR_EVP_PKEY_CTX_get_data_006a95d0)();
  switch(param_2) {
  default:
    return 0xfffffffe;
  case 1:
    iVar28 = (*(code *)PTR_EVP_MD_type_006a73cc)(param_4);
    if (iVar28 != 0x32f) {
      (*(code *)PTR_ERR_GOST_error_006a95e4)(0x80,0x6c,"gost_pmeth.c",0x1ba);
      return 0;
    }
    piVar27[1] = (int)param_4;
    break;
  case 3:
  case 4:
  case 5:
    break;
  case 6:
    if (param_3 != (undefined4 *)&DAT_00000020) {
      (*(code *)PTR_ERR_GOST_error_006a95e4)(0x80,0x6f,"gost_pmeth.c",0x1c8);
      return 0;
    }
    uVar31 = (uint)param_4 & 3;
    uVar1 = (uint)(param_4 + 1) & 3;
    iVar28 = *(int *)((int)(param_4 + 1) - uVar1);
    uVar2 = (uint)(param_4 + 2) & 3;
    iVar7 = *(int *)((int)(param_4 + 2) - uVar2);
    uVar3 = (uint)(param_4 + 3) & 3;
    iVar8 = *(int *)((int)(param_4 + 3) - uVar3);
    uVar12 = (int)param_4 + 3U & 3;
    uVar4 = (uint)(param_4 + 4) & 3;
    iVar9 = *(int *)((int)(param_4 + 4) - uVar4);
    uVar5 = (uint)(param_4 + 5) & 3;
    iVar10 = *(int *)((int)(param_4 + 5) - uVar5);
    uVar6 = (uint)(param_4 + 6) & 3;
    iVar11 = *(int *)((int)(param_4 + 6) - uVar6);
    iVar30 = param_4[7];
    uVar13 = (int)param_4 + 7U & 3;
    uVar19 = *(uint *)(((int)param_4 + 7U) - uVar13);
    uVar14 = (int)param_4 + 0xbU & 3;
    uVar20 = *(uint *)(((int)param_4 + 0xbU) - uVar14);
    uVar15 = (int)param_4 + 0xfU & 3;
    uVar21 = *(uint *)(((int)param_4 + 0xfU) - uVar15);
    uVar16 = (int)param_4 + 0x13U & 3;
    uVar22 = *(uint *)(((int)param_4 + 0x13U) - uVar16);
    uVar17 = (int)param_4 + 0x17U & 3;
    uVar23 = *(uint *)(((int)param_4 + 0x17U) - uVar17);
    uVar18 = (int)param_4 + 0x1bU & 3;
    uVar24 = *(uint *)(((int)param_4 + 0x1bU) - uVar18);
    piVar27[2] = (*(int *)((int)param_4 - uVar31) << uVar31 * 8 |
                 in_t2 & 0xffffffffU >> (4 - uVar31) * 8) & -1 << (uVar12 + 1) * 8 |
                 *(uint *)(((int)param_4 + 3U) - uVar12) >> (3 - uVar12) * 8;
    piVar27[3] = (iVar28 << uVar1 * 8 | in_t1 & 0xffffffffU >> (4 - uVar1) * 8) &
                 -1 << (uVar13 + 1) * 8 | uVar19 >> (3 - uVar13) * 8;
    piVar27[4] = (iVar7 << uVar2 * 8 | in_t0 & 0xffffffffU >> (4 - uVar2) * 8) &
                 -1 << (uVar14 + 1) * 8 | uVar20 >> (3 - uVar14) * 8;
    piVar27[5] = (iVar8 << uVar3 * 8 | (uint)piVar29 & 0xffffffffU >> (4 - uVar3) * 8) &
                 -1 << (uVar15 + 1) * 8 | uVar21 >> (3 - uVar15) * 8;
    piVar27[6] = (iVar9 << uVar4 * 8 | 0xffffffffU >> (4 - uVar4) * 8 & 0x670000) &
                 -1 << (uVar16 + 1) * 8 | uVar22 >> (3 - uVar16) * 8;
    piVar27[7] = (iVar10 << uVar5 * 8 |
                 (uint)(&switchD_005dc2d4::switchdataD_006749f0 + param_2) &
                 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar17 + 1) * 8 |
                 uVar23 >> (3 - uVar17) * 8;
    piVar27[8] = (iVar11 << uVar6 * 8 | uVar32 & 0xffffffffU >> (4 - uVar6) * 8) &
                 -1 << (uVar18 + 1) * 8 | uVar24 >> (3 - uVar18) * 8;
    piVar27[9] = iVar30;
    *piVar27 = 1;
    break;
  case 7:
    piVar29 = piVar27 + 2;
    if (*piVar27 == 0) {
      iVar28 = (*(code *)PTR_EVP_PKEY_CTX_get0_pkey_006a95d4)(uVar31);
      if (iVar28 == 0) {
        uVar26 = 0x1d7;
      }
      else {
        piVar29 = (int *)(*(code *)PTR_EVP_PKEY_get0_006a95d8)(iVar28);
        if (piVar29 != (int *)0x0) goto LAB_005dc36c;
        uVar26 = 0x1dd;
      }
      (*(code *)PTR_ERR_GOST_error_006a95e4)(0x80,0x74,"gost_pmeth.c",uVar26);
      return 0;
    }
LAB_005dc36c:
                    /* WARNING: Could not recover jumptable at 0x005dc398. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar26 = (**(code **)(*param_4 + 0x48))(param_4,0x1004,0x20,piVar29);
    return uVar26;
  }
  return 1;
}

