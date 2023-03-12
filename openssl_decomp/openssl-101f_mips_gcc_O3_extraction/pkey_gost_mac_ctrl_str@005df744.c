
int pkey_gost_mac_ctrl_str(uint param_1,char *param_2,undefined4 *param_3,uint param_4)

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
  undefined *puVar26;
  int iVar27;
  int iVar28;
  undefined4 *puVar29;
  undefined4 *puVar30;
  undefined4 uVar31;
  undefined4 *puVar32;
  undefined4 *puVar33;
  char *pcVar34;
  int *piVar35;
  undefined4 *puVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  uint in_t0;
  uint in_t1;
  uint in_t2;
  uint in_t3;
  int iVar39;
  int local_20;
  int local_1c;
  
  puVar26 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((((*param_2 == 'k') && (param_2[1] == 'e')) && (param_2[2] == 'y')) && (param_2[3] == '\0')) {
    puVar36 = param_3;
    iVar27 = (*(code *)PTR_strlen_006aab30)(param_3);
    if (iVar27 == 0x20) {
      iVar39 = 1;
      puVar30 = (undefined4 *)(*(code *)PTR_EVP_PKEY_CTX_get_data_006aa6dc)();
      uVar1 = (uint)(param_3 + 1) & 3;
      iVar27 = *(int *)((int)(param_3 + 1) - uVar1);
      uVar2 = (uint)(param_3 + 2) & 3;
      iVar28 = *(int *)((int)(param_3 + 2) - uVar2);
      uVar3 = (uint)(param_3 + 3) & 3;
      iVar8 = *(int *)((int)(param_3 + 3) - uVar3);
      uVar4 = (uint)(param_3 + 4) & 3;
      iVar9 = *(int *)((int)(param_3 + 4) - uVar4);
      uVar5 = (uint)(param_3 + 5) & 3;
      iVar10 = *(int *)((int)(param_3 + 5) - uVar5);
      uVar6 = (uint)(param_3 + 6) & 3;
      uVar7 = (uint)(param_3 + 7) & 3;
      iVar11 = *(int *)((int)(param_3 + 7) - uVar7);
      uVar12 = (int)param_3 + 7U & 3;
      uVar18 = *(uint *)(((int)param_3 + 7U) - uVar12);
      uVar13 = (int)param_3 + 0xbU & 3;
      uVar19 = *(uint *)(((int)param_3 + 0xbU) - uVar13);
      uVar14 = (int)param_3 + 0xfU & 3;
      uVar20 = *(uint *)(((int)param_3 + 0xfU) - uVar14);
      uVar15 = (int)param_3 + 0x13U & 3;
      uVar21 = *(uint *)(((int)param_3 + 0x13U) - uVar15);
      uVar16 = (int)param_3 + 0x17U & 3;
      uVar22 = *(uint *)(((int)param_3 + 0x17U) - uVar16);
      uVar17 = (int)param_3 + 0x1bU & 3;
      pcVar34 = (char *)((*(int *)((int)(param_3 + 6) - uVar6) << uVar6 * 8 |
                         (uint)param_2 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar17 + 1) * 8 |
                        *(uint *)(((int)param_3 + 0x1bU) - uVar17) >> (3 - uVar17) * 8);
      uVar6 = (int)param_3 + 0x1fU & 3;
      uVar17 = *(uint *)(((int)param_3 + 0x1fU) - uVar6);
      puVar30[2] = *param_3;
      puVar30[3] = (iVar27 << uVar1 * 8 | in_t2 & 0xffffffffU >> (4 - uVar1) * 8) &
                   -1 << (uVar12 + 1) * 8 | uVar18 >> (3 - uVar12) * 8;
      puVar30[4] = (iVar28 << uVar2 * 8 | in_t1 & 0xffffffffU >> (4 - uVar2) * 8) &
                   -1 << (uVar13 + 1) * 8 | uVar19 >> (3 - uVar13) * 8;
      puVar30[5] = (iVar8 << uVar3 * 8 | in_t0 & 0xffffffffU >> (4 - uVar3) * 8) &
                   -1 << (uVar14 + 1) * 8 | uVar20 >> (3 - uVar14) * 8;
      puVar30[6] = (iVar9 << uVar4 * 8 | param_4 & 0xffffffffU >> (4 - uVar4) * 8) &
                   -1 << (uVar15 + 1) * 8 | uVar21 >> (3 - uVar15) * 8;
      puVar30[7] = (iVar10 << uVar5 * 8 | (uint)puVar36 & 0xffffffffU >> (4 - uVar5) * 8) &
                   -1 << (uVar16 + 1) * 8 | uVar22 >> (3 - uVar16) * 8;
      puVar30[8] = pcVar34;
      puVar30[9] = (iVar11 << uVar7 * 8 | param_1 & 0xffffffffU >> (4 - uVar7) * 8) &
                   -1 << (uVar6 + 1) * 8 | uVar17 >> (3 - uVar6) * 8;
      *puVar30 = 1;
    }
    else {
      pcVar34 = (char *)0x6f;
      iVar39 = 0;
      (*(code *)PTR_ERR_GOST_error_006aa6f0)(0x81,0x6f,"gost_pmeth.c",0x204);
    }
  }
  else {
    pcVar34 = "hexkey";
    puVar36 = param_3;
    iVar39 = (*(code *)PTR_strcmp_006aac20)(param_2,"hexkey");
    if (iVar39 == 0) {
      piVar35 = &local_20;
      puVar30 = (undefined4 *)(*(code *)PTR_string_to_hex_006a848c)(param_3);
      if (local_20 == 0x20) {
        iVar39 = 1;
        puVar29 = (undefined4 *)(*(code *)PTR_EVP_PKEY_CTX_get_data_006aa6dc)(param_1);
        uVar1 = (uint)(puVar30 + 1) & 3;
        iVar27 = *(int *)((int)(puVar30 + 1) - uVar1);
        uVar2 = (uint)(puVar30 + 2) & 3;
        iVar28 = *(int *)((int)(puVar30 + 2) - uVar2);
        uVar3 = (uint)(puVar30 + 3) & 3;
        iVar8 = *(int *)((int)(puVar30 + 3) - uVar3);
        uVar4 = (uint)(puVar30 + 4) & 3;
        iVar9 = *(int *)((int)(puVar30 + 4) - uVar4);
        uVar5 = (uint)(puVar30 + 5) & 3;
        iVar10 = *(int *)((int)(puVar30 + 5) - uVar5);
        uVar6 = (uint)(puVar30 + 6) & 3;
        iVar11 = *(int *)((int)(puVar30 + 6) - uVar6);
        uVar7 = (uint)(puVar30 + 7) & 3;
        uVar12 = (int)puVar30 + 7U & 3;
        uVar19 = *(uint *)(((int)puVar30 + 7U) - uVar12);
        uVar13 = (int)puVar30 + 0xbU & 3;
        uVar20 = *(uint *)(((int)puVar30 + 0xbU) - uVar13);
        uVar14 = (int)puVar30 + 0xfU & 3;
        uVar21 = *(uint *)(((int)puVar30 + 0xfU) - uVar14);
        uVar15 = (int)puVar30 + 0x13U & 3;
        uVar22 = *(uint *)(((int)puVar30 + 0x13U) - uVar15);
        uVar16 = (int)puVar30 + 0x17U & 3;
        uVar23 = *(uint *)(((int)puVar30 + 0x17U) - uVar16);
        uVar17 = (int)puVar30 + 0x1bU & 3;
        uVar24 = *(uint *)(((int)puVar30 + 0x1bU) - uVar17);
        uVar18 = (int)puVar30 + 0x1fU & 3;
        pcVar34 = (char *)((*(int *)((int)(puVar30 + 7) - uVar7) << uVar7 * 8 |
                           (uint)piVar35 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar18 + 1) * 8
                          | *(uint *)(((int)puVar30 + 0x1fU) - uVar18) >> (3 - uVar18) * 8);
        puVar29[2] = *puVar30;
        puVar29[3] = (iVar27 << uVar1 * 8 | in_t3 & 0xffffffffU >> (4 - uVar1) * 8) &
                     -1 << (uVar12 + 1) * 8 | uVar19 >> (3 - uVar12) * 8;
        puVar29[4] = (iVar28 << uVar2 * 8 | in_t2 & 0xffffffffU >> (4 - uVar2) * 8) &
                     -1 << (uVar13 + 1) * 8 | uVar20 >> (3 - uVar13) * 8;
        puVar29[5] = (iVar8 << uVar3 * 8 | in_t1 & 0xffffffffU >> (4 - uVar3) * 8) &
                     -1 << (uVar14 + 1) * 8 | uVar21 >> (3 - uVar14) * 8;
        puVar29[6] = (iVar9 << uVar4 * 8 | in_t0 & 0xffffffffU >> (4 - uVar4) * 8) &
                     -1 << (uVar15 + 1) * 8 | uVar22 >> (3 - uVar15) * 8;
        puVar29[7] = (iVar10 << uVar5 * 8 | param_4 & 0xffffffffU >> (4 - uVar5) * 8) &
                     -1 << (uVar16 + 1) * 8 | uVar23 >> (3 - uVar16) * 8;
        puVar29[8] = (iVar11 << uVar6 * 8 | (uint)puVar36 & 0xffffffffU >> (4 - uVar6) * 8) &
                     -1 << (uVar17 + 1) * 8 | uVar24 >> (3 - uVar17) * 8;
        puVar29[9] = pcVar34;
        puVar25 = PTR_CRYPTO_free_006a7f88;
        *puVar29 = 1;
        (*(code *)puVar25)(puVar30);
      }
      else {
        pcVar34 = (char *)0x6f;
        (*(code *)PTR_ERR_GOST_error_006aa6f0)(0x81,0x6f,"gost_pmeth.c",0x211);
        (*(code *)PTR_CRYPTO_free_006a7f88)(puVar30);
      }
    }
    else {
      iVar39 = -2;
    }
  }
  if (local_1c != *(int *)puVar26) {
    iVar27 = local_1c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    iVar28 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x28,"gost_pmeth.c",0x1a8);
    if (iVar28 == 0) {
      return 0;
    }
    (*(code *)PTR_memset_006aab00)(iVar28,0,0x28);
    (*(code *)PTR_EVP_PKEY_CTX_set_data_006aa6ec)(iVar27,iVar28);
    puVar29 = (undefined4 *)(*(code *)PTR_EVP_PKEY_CTX_get_data_006aa6dc)(pcVar34);
    puVar30 = (undefined4 *)(*(code *)PTR_EVP_PKEY_CTX_get_data_006aa6dc)(iVar27);
    puVar36 = puVar29;
    do {
      puVar33 = puVar30;
      puVar32 = puVar36;
      puVar36 = puVar32 + 4;
      uVar38 = puVar32[1];
      uVar37 = puVar32[2];
      uVar31 = puVar32[3];
      *puVar33 = *puVar32;
      puVar33[1] = uVar38;
      puVar33[2] = uVar37;
      puVar33[3] = uVar31;
      puVar30 = puVar33 + 4;
    } while (puVar36 != puVar29 + 8);
    uVar31 = puVar32[5];
    puVar33[4] = *puVar36;
    puVar33[5] = uVar31;
    return 1;
  }
  return iVar39;
}

