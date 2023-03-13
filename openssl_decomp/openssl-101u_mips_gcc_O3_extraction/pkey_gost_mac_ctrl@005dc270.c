
undefined4 pkey_gost_mac_ctrl(uint param_1,int param_2,int param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
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
  uint uVar25;
  int *piVar26;
  undefined4 uVar27;
  int iVar28;
  int *piVar29;
  int iVar30;
  uint uVar31;
  uint in_t0;
  uint in_t1;
  uint in_t2;
  
  uVar31 = param_1;
  piVar29 = param_4;
  piVar26 = (int *)(*(code *)PTR_EVP_PKEY_CTX_get_data_006a95d0)();
  switch(param_2) {
  default:
    return 0xfffffffe;
  case 1:
    iVar28 = (*(code *)PTR_EVP_MD_type_006a73cc)(param_4);
    if (iVar28 != 0x32f) {
      (*(code *)PTR_ERR_GOST_error_006a95e4)(0x80,0x6c,"gost_pmeth.c",0x1ba);
      return 0;
    }
    piVar26[1] = (int)param_4;
    break;
  case 3:
  case 4:
  case 5:
    break;
  case 6:
    if (param_3 != 0x20) {
      (*(code *)PTR_ERR_GOST_error_006a95e4)(0x80,0x6f,"gost_pmeth.c",0x1c8);
      return 0;
    }
    uVar1 = (uint)param_4 & 3;
    uVar2 = (uint)(param_4 + 1) & 3;
    iVar28 = *(int *)((int)(param_4 + 1) - uVar2);
    uVar3 = (uint)(param_4 + 2) & 3;
    iVar8 = *(int *)((int)(param_4 + 2) - uVar3);
    uVar4 = (uint)(param_4 + 3) & 3;
    iVar9 = *(int *)((int)(param_4 + 3) - uVar4);
    uVar13 = (int)param_4 + 3U & 3;
    uVar5 = (uint)(param_4 + 4) & 3;
    iVar10 = *(int *)((int)(param_4 + 4) - uVar5);
    uVar6 = (uint)(param_4 + 5) & 3;
    iVar11 = *(int *)((int)(param_4 + 5) - uVar6);
    uVar7 = (uint)(param_4 + 6) & 3;
    iVar12 = *(int *)((int)(param_4 + 6) - uVar7);
    iVar30 = param_4[7];
    uVar14 = (int)param_4 + 7U & 3;
    uVar20 = *(uint *)(((int)param_4 + 7U) - uVar14);
    uVar15 = (int)param_4 + 0xbU & 3;
    uVar21 = *(uint *)(((int)param_4 + 0xbU) - uVar15);
    uVar16 = (int)param_4 + 0xfU & 3;
    uVar22 = *(uint *)(((int)param_4 + 0xfU) - uVar16);
    uVar17 = (int)param_4 + 0x13U & 3;
    uVar23 = *(uint *)(((int)param_4 + 0x13U) - uVar17);
    uVar18 = (int)param_4 + 0x17U & 3;
    uVar24 = *(uint *)(((int)param_4 + 0x17U) - uVar18);
    uVar19 = (int)param_4 + 0x1bU & 3;
    uVar25 = *(uint *)(((int)param_4 + 0x1bU) - uVar19);
    piVar26[2] = (*(int *)((int)param_4 - uVar1) << uVar1 * 8 |
                 in_t2 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar13 + 1) * 8 |
                 *(uint *)(((int)param_4 + 3U) - uVar13) >> (3 - uVar13) * 8;
    piVar26[3] = (iVar28 << uVar2 * 8 | in_t1 & 0xffffffffU >> (4 - uVar2) * 8) &
                 -1 << (uVar14 + 1) * 8 | uVar20 >> (3 - uVar14) * 8;
    piVar26[4] = (iVar8 << uVar3 * 8 | in_t0 & 0xffffffffU >> (4 - uVar3) * 8) &
                 -1 << (uVar15 + 1) * 8 | uVar21 >> (3 - uVar15) * 8;
    piVar26[5] = (iVar9 << uVar4 * 8 | (uint)piVar29 & 0xffffffffU >> (4 - uVar4) * 8) &
                 -1 << (uVar16 + 1) * 8 | uVar22 >> (3 - uVar16) * 8;
    piVar26[6] = (iVar10 << uVar5 * 8 | 0xffffffffU >> (4 - uVar5) * 8 & 0x670000) &
                 -1 << (uVar17 + 1) * 8 | uVar23 >> (3 - uVar17) * 8;
    piVar26[7] = (iVar11 << uVar6 * 8 |
                 (uint)(&switchD_005dc2d4::switchdataD_006749f0 + param_2) &
                 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar18 + 1) * 8 |
                 uVar24 >> (3 - uVar18) * 8;
    piVar26[8] = (iVar12 << uVar7 * 8 | uVar31 & 0xffffffffU >> (4 - uVar7) * 8) &
                 -1 << (uVar19 + 1) * 8 | uVar25 >> (3 - uVar19) * 8;
    piVar26[9] = iVar30;
    *piVar26 = 1;
    break;
  case 7:
    piVar29 = piVar26 + 2;
    if (*piVar26 == 0) {
      iVar28 = (*(code *)PTR_EVP_PKEY_CTX_get0_pkey_006a95d4)(param_1);
      if (iVar28 == 0) {
        uVar27 = 0x1d7;
      }
      else {
        piVar29 = (int *)(*(code *)PTR_EVP_PKEY_get0_006a95d8)(iVar28);
        if (piVar29 != (int *)0x0) goto LAB_005dc36c;
        uVar27 = 0x1dd;
      }
      (*(code *)PTR_ERR_GOST_error_006a95e4)(0x80,0x74,"gost_pmeth.c",uVar27);
      return 0;
    }
LAB_005dc36c:
                    /* WARNING: Could not recover jumptable at 0x005dc398. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar27 = (**(code **)(*param_4 + 0x48))(param_4,0x1004,0x20,piVar29);
    return uVar27;
  }
  return 1;
}

