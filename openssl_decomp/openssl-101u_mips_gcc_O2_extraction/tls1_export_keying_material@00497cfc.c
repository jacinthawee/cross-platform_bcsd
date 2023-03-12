
undefined4
tls1_export_keying_material
          (int param_1,undefined4 param_2,undefined4 param_3,uint param_4,uint param_5,int param_6,
          int param_7,int param_8)

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
  int iVar20;
  int iVar21;
  uint *puVar22;
  uint *puVar23;
  int iVar24;
  int iVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint in_t0;
  uint uVar31;
  uint in_t1;
  uint uVar32;
  uint in_t2;
  uint uVar33;
  uint in_t3;
  uint uVar34;
  uint uVar35;
  undefined4 uVar36;
  int iVar37;
  int iVar38;
  
  uVar29 = param_4;
  iVar20 = (*(code *)PTR_CRYPTO_malloc_006a7008)(param_3,&DAT_0064760c,0x4a2);
  if (iVar20 == 0) {
    uVar36 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13a,0x41,&DAT_0064760c,0x4ec);
  }
  else {
    iVar37 = param_5 + 0x40;
    if (param_8 == 0) {
      iVar21 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar37,&DAT_0064760c,0x4b0);
      iVar38 = iVar37;
    }
    else {
      iVar38 = param_7 + 2 + iVar37;
      iVar21 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar38,&DAT_0064760c,0x4b0);
    }
    if (iVar21 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13a,0x41,&DAT_0064760c,0x4ec);
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar20);
      return 0;
    }
    uVar27 = param_5;
    (*(code *)PTR_memcpy_006a9aec)(iVar21);
    puVar23 = (uint *)(iVar21 + param_5);
    iVar24 = *(int *)(param_1 + 0x58);
    puVar22 = (uint *)(iVar21 + param_5 + 0x20);
    uVar35 = *(uint *)(iVar24 + 0xc0);
    uVar1 = iVar24 + 0xc4U & 3;
    uVar2 = iVar24 + 200U & 3;
    uVar3 = iVar24 + 0xccU & 3;
    uVar4 = iVar24 + 0xd0U & 3;
    uVar5 = iVar24 + 0xd4U & 3;
    uVar6 = iVar24 + 0xd8U & 3;
    iVar8 = *(int *)((iVar24 + 0xd8U) - uVar6);
    uVar7 = iVar24 + 0xdcU & 3;
    iVar9 = *(int *)((iVar24 + 0xdcU) - uVar7);
    uVar12 = iVar24 + 199U & 3;
    uVar34 = (*(int *)((iVar24 + 0xc4U) - uVar1) << uVar1 * 8 |
             in_t3 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar12 + 1) * 8 |
             *(uint *)((iVar24 + 199U) - uVar12) >> (3 - uVar12) * 8;
    uVar1 = iVar24 + 0xcbU & 3;
    uVar33 = (*(int *)((iVar24 + 200U) - uVar2) << uVar2 * 8 |
             in_t2 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar1 + 1) * 8 |
             *(uint *)((iVar24 + 0xcbU) - uVar1) >> (3 - uVar1) * 8;
    uVar1 = iVar24 + 0xcfU & 3;
    uVar32 = (*(int *)((iVar24 + 0xccU) - uVar3) << uVar3 * 8 |
             in_t1 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar1 + 1) * 8 |
             *(uint *)((iVar24 + 0xcfU) - uVar1) >> (3 - uVar1) * 8;
    uVar1 = iVar24 + 0xd3U & 3;
    uVar31 = (*(int *)((iVar24 + 0xd0U) - uVar4) << uVar4 * 8 |
             in_t0 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar1 + 1) * 8 |
             *(uint *)((iVar24 + 0xd3U) - uVar1) >> (3 - uVar1) * 8;
    uVar1 = iVar24 + 0xd7U & 3;
    uVar30 = (*(int *)((iVar24 + 0xd4U) - uVar5) << uVar5 * 8 |
             uVar29 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar1 + 1) * 8 |
             *(uint *)((iVar24 + 0xd7U) - uVar1) >> (3 - uVar1) * 8;
    uVar29 = iVar24 + 0xdbU & 3;
    uVar2 = *(uint *)((iVar24 + 0xdbU) - uVar29);
    uVar1 = iVar24 + 0xdfU & 3;
    uVar3 = *(uint *)((iVar24 + 0xdfU) - uVar1);
    *puVar23 = uVar35;
    puVar23[1] = uVar34;
    puVar23[2] = uVar33;
    puVar23[3] = uVar32;
    puVar23[4] = uVar31;
    puVar23[5] = uVar30;
    puVar23[6] = (iVar8 << uVar6 * 8 | uVar27 & 0xffffffffU >> (4 - uVar6) * 8) &
                 -1 << (uVar29 + 1) * 8 | uVar2 >> (3 - uVar29) * 8;
    puVar23[7] = (iVar9 << uVar7 * 8 | param_4 & 0xffffffffU >> (4 - uVar7) * 8) &
                 -1 << (uVar1 + 1) * 8 | uVar3 >> (3 - uVar1) * 8;
    iVar25 = *(int *)(param_1 + 0x58);
    uVar29 = iVar25 + 0xa0U & 3;
    uVar1 = iVar25 + 0xa4U & 3;
    iVar8 = *(int *)((iVar25 + 0xa4U) - uVar1);
    uVar2 = iVar25 + 0xa8U & 3;
    iVar9 = *(int *)((iVar25 + 0xa8U) - uVar2);
    uVar3 = iVar25 + 0xacU & 3;
    iVar24 = *(int *)((iVar25 + 0xacU) - uVar3);
    uVar4 = iVar25 + 0xb0U & 3;
    iVar10 = *(int *)((iVar25 + 0xb0U) - uVar4);
    uVar5 = iVar25 + 0xb4U & 3;
    iVar11 = *(int *)((iVar25 + 0xb4U) - uVar5);
    uVar6 = iVar25 + 0xa3U & 3;
    uVar7 = iVar25 + 0xa7U & 3;
    uVar15 = *(uint *)((iVar25 + 0xa7U) - uVar7);
    uVar12 = iVar25 + 0xabU & 3;
    uVar16 = *(uint *)((iVar25 + 0xabU) - uVar12);
    uVar27 = iVar25 + 0xafU & 3;
    uVar17 = *(uint *)((iVar25 + 0xafU) - uVar27);
    uVar13 = iVar25 + 0xb3U & 3;
    uVar18 = *(uint *)((iVar25 + 0xb3U) - uVar13);
    uVar14 = iVar25 + 0xb7U & 3;
    uVar19 = *(uint *)((iVar25 + 0xb7U) - uVar14);
    uVar28 = *(uint *)(iVar25 + 0xb8);
    uVar26 = *(uint *)(iVar25 + 0xbc);
    *puVar22 = (*(int *)((iVar25 + 0xa0U) - uVar29) << uVar29 * 8 |
               uVar35 & 0xffffffffU >> (4 - uVar29) * 8) & -1 << (uVar6 + 1) * 8 |
               *(uint *)((iVar25 + 0xa3U) - uVar6) >> (3 - uVar6) * 8;
    puVar22[1] = (iVar8 << uVar1 * 8 | uVar34 & 0xffffffffU >> (4 - uVar1) * 8) &
                 -1 << (uVar7 + 1) * 8 | uVar15 >> (3 - uVar7) * 8;
    puVar22[2] = (iVar9 << uVar2 * 8 | uVar33 & 0xffffffffU >> (4 - uVar2) * 8) &
                 -1 << (uVar12 + 1) * 8 | uVar16 >> (3 - uVar12) * 8;
    puVar22[3] = (iVar24 << uVar3 * 8 | uVar32 & 0xffffffffU >> (4 - uVar3) * 8) &
                 -1 << (uVar27 + 1) * 8 | uVar17 >> (3 - uVar27) * 8;
    puVar22[4] = (iVar10 << uVar4 * 8 | uVar31 & 0xffffffffU >> (4 - uVar4) * 8) &
                 -1 << (uVar13 + 1) * 8 | uVar18 >> (3 - uVar13) * 8;
    puVar22[5] = (iVar11 << uVar5 * 8 | uVar30 & 0xffffffffU >> (4 - uVar5) * 8) &
                 -1 << (uVar14 + 1) * 8 | uVar19 >> (3 - uVar14) * 8;
    puVar22[6] = uVar28;
    puVar22[7] = uVar26;
    if (param_8 != 0) {
      *(char *)(iVar21 + iVar37) = (char)((uint)param_7 >> 8);
      *(undefined *)((int)puVar23 + 0x41) = (undefined)param_7;
      if ((param_7 != 0) || (param_6 != 0)) {
        (*(code *)PTR_memcpy_006a9aec)(iVar21 + param_5 + 0x42,param_6,param_7);
      }
    }
    iVar37 = (*(code *)PTR_memcmp_006a9ad0)(iVar21,"client finished",0xf);
    if ((((iVar37 == 0) ||
         (iVar37 = (*(code *)PTR_memcmp_006a9ad0)(iVar21,"server finished",0xf), iVar37 == 0)) ||
        (iVar37 = (*(code *)PTR_memcmp_006a9ad0)(iVar21,"master secret",0xd), iVar37 == 0)) ||
       (iVar37 = (*(code *)PTR_memcmp_006a9ad0)(iVar21,"key expansion",0xd), iVar37 == 0)) {
      uVar36 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13a,0x16f,&DAT_0064760c,0x4e8);
    }
    else {
      uVar36 = ssl_get_algorithm2(param_1);
      uVar36 = tls1_PRF_constprop_1
                         (uVar36,iVar21,iVar38,0,0,0,0,0,0,*(int *)(param_1 + 0xc0) + 0x14,
                          *(undefined4 *)(*(int *)(param_1 + 0xc0) + 0x10),param_2,iVar20,param_3);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar21,iVar38);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar20,param_3);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar20);
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar21);
  }
  return uVar36;
}

