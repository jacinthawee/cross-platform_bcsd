
undefined4
pkey_gost_mac_keygen(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

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
  int iVar13;
  int iVar14;
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
  uint uVar26;
  uint uVar27;
  uint uVar28;
  int *piVar29;
  int *piVar30;
  uint in_t0;
  uint in_t1;
  uint in_t2;
  uint in_t3;
  uint in_t4;
  uint in_t5;
  
  piVar29 = (int *)(*(code *)PTR_EVP_PKEY_CTX_get_data_006aa6dc)();
  if (*piVar29 != 0) {
    piVar30 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x20,"gost_pmeth.c",0x227);
    uVar1 = (uint)(piVar29 + 3) & 3;
    iVar8 = *(int *)((int)(piVar29 + 3) - uVar1);
    uVar2 = (uint)(piVar29 + 4) & 3;
    iVar9 = *(int *)((int)(piVar29 + 4) - uVar2);
    uVar3 = (uint)(piVar29 + 5) & 3;
    iVar10 = *(int *)((int)(piVar29 + 5) - uVar3);
    uVar4 = (uint)(piVar29 + 6) & 3;
    iVar11 = *(int *)((int)(piVar29 + 6) - uVar4);
    uVar5 = (uint)(piVar29 + 7) & 3;
    iVar12 = *(int *)((int)(piVar29 + 7) - uVar5);
    uVar6 = (uint)(piVar29 + 8) & 3;
    iVar13 = *(int *)((int)(piVar29 + 8) - uVar6);
    uVar7 = (uint)(piVar29 + 9) & 3;
    iVar14 = *(int *)((int)(piVar29 + 9) - uVar7);
    uVar15 = (int)piVar29 + 0xfU & 3;
    uVar22 = *(uint *)(((int)piVar29 + 0xfU) - uVar15);
    uVar16 = (int)piVar29 + 0x13U & 3;
    uVar23 = *(uint *)(((int)piVar29 + 0x13U) - uVar16);
    uVar17 = (int)piVar29 + 0x17U & 3;
    uVar24 = *(uint *)(((int)piVar29 + 0x17U) - uVar17);
    uVar18 = (int)piVar29 + 0x1bU & 3;
    uVar25 = *(uint *)(((int)piVar29 + 0x1bU) - uVar18);
    uVar19 = (int)piVar29 + 0x1fU & 3;
    uVar26 = *(uint *)(((int)piVar29 + 0x1fU) - uVar19);
    uVar20 = (int)piVar29 + 0x23U & 3;
    uVar27 = *(uint *)(((int)piVar29 + 0x23U) - uVar20);
    uVar21 = (int)piVar29 + 0x27U & 3;
    uVar28 = *(uint *)(((int)piVar29 + 0x27U) - uVar21);
    *piVar30 = piVar29[2];
    piVar30[1] = (iVar8 << uVar1 * 8 | in_t5 & 0xffffffffU >> (4 - uVar1) * 8) &
                 -1 << (uVar15 + 1) * 8 | uVar22 >> (3 - uVar15) * 8;
    piVar30[2] = (iVar9 << uVar2 * 8 | in_t4 & 0xffffffffU >> (4 - uVar2) * 8) &
                 -1 << (uVar16 + 1) * 8 | uVar23 >> (3 - uVar16) * 8;
    piVar30[3] = (iVar10 << uVar3 * 8 | in_t3 & 0xffffffffU >> (4 - uVar3) * 8) &
                 -1 << (uVar17 + 1) * 8 | uVar24 >> (3 - uVar17) * 8;
    piVar30[4] = (iVar11 << uVar4 * 8 | in_t2 & 0xffffffffU >> (4 - uVar4) * 8) &
                 -1 << (uVar18 + 1) * 8 | uVar25 >> (3 - uVar18) * 8;
    piVar30[5] = (iVar12 << uVar5 * 8 | in_t1 & 0xffffffffU >> (4 - uVar5) * 8) &
                 -1 << (uVar19 + 1) * 8 | uVar26 >> (3 - uVar19) * 8;
    piVar30[6] = (iVar13 << uVar6 * 8 | in_t0 & 0xffffffffU >> (4 - uVar6) * 8) &
                 -1 << (uVar20 + 1) * 8 | uVar27 >> (3 - uVar20) * 8;
    piVar30[7] = (iVar14 << uVar7 * 8 | param_4 & 0xffffffffU >> (4 - uVar7) * 8) &
                 -1 << (uVar21 + 1) * 8 | uVar28 >> (3 - uVar21) * 8;
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_2,0x32f,piVar30);
    return 1;
  }
  (*(code *)PTR_ERR_GOST_error_006aa6f0)(0x82,0x74,"gost_pmeth.c",0x224);
  return 0;
}

