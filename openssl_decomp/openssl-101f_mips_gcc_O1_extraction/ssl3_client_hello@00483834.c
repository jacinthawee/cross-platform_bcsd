
undefined4 ssl3_client_hello(int *param_1)

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
  undefined4 uVar25;
  int *piVar26;
  int iVar27;
  int iVar28;
  undefined4 *puVar29;
  int iVar30;
  uint uVar31;
  uint uVar32;
  undefined4 uVar33;
  uint uVar34;
  uint in_t0;
  uint in_t1;
  uint in_t2;
  uint in_t3;
  undefined *puVar35;
  undefined *puVar36;
  undefined *puVar37;
  undefined *puVar38;
  undefined *puVar39;
  
  if (param_1[0xd] != 0x1110) {
    uVar25 = ssl3_do_write(param_1,0x16);
    return uVar25;
  }
  piVar26 = (int *)param_1[0x30];
  puVar39 = *(undefined **)(param_1[0xf] + 4);
  if ((((piVar26 == (int *)0x0) || (*piVar26 != *param_1)) ||
      ((piVar26[0x11] == 0 && (piVar26[0x39] == 0)))) || (piVar26[0x25] != 0)) {
    iVar27 = (*(code *)PTR_ssl_get_new_session_006a904c)(param_1,0);
    if (iVar27 == 0) {
      return 0xffffffff;
    }
    iVar27 = param_1[0x16];
  }
  else {
    iVar27 = param_1[0x16];
  }
  uVar34 = 0x20;
  uVar31 = 0;
  uVar32 = iVar27 + 0xc0;
  iVar27 = ssl_fill_hello_random(param_1);
  if (iVar27 < 1) {
    return 0xffffffff;
  }
  puVar39[4] = (char)((uint)param_1[0x44] >> 8);
  puVar39[5] = (char)param_1[0x44];
  iVar30 = param_1[0x16];
  uVar1 = iVar30 + 0xc0U & 3;
  uVar2 = iVar30 + 0xc4U & 3;
  iVar27 = *(int *)((iVar30 + 0xc4U) - uVar2);
  uVar3 = iVar30 + 200U & 3;
  iVar28 = *(int *)((iVar30 + 200U) - uVar3);
  uVar4 = iVar30 + 0xccU & 3;
  iVar8 = *(int *)((iVar30 + 0xccU) - uVar4);
  uVar5 = iVar30 + 0xd0U & 3;
  iVar9 = *(int *)((iVar30 + 0xd0U) - uVar5);
  uVar6 = iVar30 + 0xd4U & 3;
  iVar10 = *(int *)((iVar30 + 0xd4U) - uVar6);
  uVar7 = iVar30 + 0xd8U & 3;
  iVar11 = *(int *)((iVar30 + 0xd8U) - uVar7);
  uVar12 = iVar30 + 0xc3U & 3;
  uVar13 = iVar30 + 199U & 3;
  uVar19 = *(uint *)((iVar30 + 199U) - uVar13);
  uVar14 = iVar30 + 0xcbU & 3;
  uVar20 = *(uint *)((iVar30 + 0xcbU) - uVar14);
  uVar15 = iVar30 + 0xcfU & 3;
  uVar21 = *(uint *)((iVar30 + 0xcfU) - uVar15);
  uVar16 = iVar30 + 0xd3U & 3;
  uVar22 = *(uint *)((iVar30 + 0xd3U) - uVar16);
  uVar17 = iVar30 + 0xd7U & 3;
  uVar23 = *(uint *)((iVar30 + 0xd7U) - uVar17);
  uVar18 = iVar30 + 0xdbU & 3;
  uVar24 = *(uint *)((iVar30 + 0xdbU) - uVar18);
  uVar25 = *(undefined4 *)(iVar30 + 0xdc);
  *(uint *)(puVar39 + 6) =
       (*(int *)((iVar30 + 0xc0U) - uVar1) << uVar1 * 8 | in_t3 & 0xffffffffU >> (4 - uVar1) * 8) &
       -1 << (uVar12 + 1) * 8 | *(uint *)((iVar30 + 0xc3U) - uVar12) >> (3 - uVar12) * 8;
  *(uint *)(puVar39 + 10) =
       (iVar27 << uVar2 * 8 | in_t2 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar13 + 1) * 8 |
       uVar19 >> (3 - uVar13) * 8;
  *(uint *)(puVar39 + 0xe) =
       (iVar28 << uVar3 * 8 | in_t1 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar14 + 1) * 8 |
       uVar20 >> (3 - uVar14) * 8;
  *(uint *)(puVar39 + 0x12) =
       (iVar8 << uVar4 * 8 | in_t0 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar15 + 1) * 8 |
       uVar21 >> (3 - uVar15) * 8;
  *(uint *)(puVar39 + 0x16) =
       (iVar9 << uVar5 * 8 | uVar34 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar16 + 1) * 8 |
       uVar22 >> (3 - uVar16) * 8;
  *(uint *)(puVar39 + 0x1a) =
       (iVar10 << uVar6 * 8 | uVar32 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar17 + 1) * 8 |
       uVar23 >> (3 - uVar17) * 8;
  *(uint *)(puVar39 + 0x1e) =
       (iVar11 << uVar7 * 8 | uVar31 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar18 + 1) * 8 |
       uVar24 >> (3 - uVar18) * 8;
  *(undefined4 *)(puVar39 + 0x22) = uVar25;
  if (param_1[10] == 0) {
    puVar35 = puVar39 + 0x27;
    iVar27 = *(int *)(param_1[0x30] + 0x44);
    puVar39[0x26] = (char)iVar27;
    puVar36 = puVar35;
    if (iVar27 != 0) {
      if (0x20 < iVar27) {
        uVar33 = 0x44;
        uVar25 = 0x2e6;
        goto LAB_00483ba0;
      }
      puVar36 = puVar35 + iVar27;
      (*(code *)PTR_memcpy_006aabf4)(puVar35,param_1[0x30] + 0x48);
    }
  }
  else {
    puVar36 = puVar39 + 0x27;
    puVar39[0x26] = 0;
  }
  uVar25 = (*(code *)PTR_SSL_get_ciphers_006a894c)(param_1);
  iVar27 = (*(code *)PTR_ssl_cipher_list_to_bytes_006a9064)(param_1,uVar25,puVar36 + 2,0);
  if (iVar27 == 0) {
    uVar33 = 0xb5;
    uVar25 = 0x2f1;
  }
  else {
    puVar36[1] = (char)iVar27;
    *puVar36 = (char)((uint)iVar27 >> 8);
    if ((param_1[0x40] << 0xe < 0) || (*(int *)(param_1[0x39] + 0x98) == 0)) {
      puVar36[iVar27 + 2] = '\x01';
      puVar36 = puVar36 + iVar27 + 3;
    }
    else {
      puVar35 = puVar36 + iVar27 + 3;
      iVar28 = (*(code *)PTR_sk_num_006a7f2c)();
      puVar36[iVar27 + 2] = (char)iVar28 + '\x01';
      puVar36 = puVar35;
      if (0 < iVar28) {
        puVar36 = puVar35 + iVar28;
        puVar37 = puVar35;
        do {
          puVar38 = puVar37 + 1;
          puVar29 = (undefined4 *)
                    (*(code *)PTR_sk_value_006a7f24)
                              (*(undefined4 *)(param_1[0x39] + 0x98),(int)puVar37 - (int)puVar35);
          *puVar37 = (char)*puVar29;
          puVar37 = puVar38;
        } while (puVar36 != puVar38);
      }
    }
    *puVar36 = 0;
    iVar27 = ssl_prepare_clienthello_tlsext(param_1);
    if (iVar27 < 1) {
      uVar33 = 0xe2;
      uVar25 = 0x317;
    }
    else {
      iVar27 = ssl_add_clienthello_tlsext(param_1,puVar36 + 1,puVar39 + 0x4000);
      if (iVar27 != 0) {
        iVar28 = iVar27 - (int)(puVar39 + 4);
        puVar39[3] = (char)iVar28;
        *puVar39 = 1;
        puVar39[2] = (char)((uint)iVar28 >> 8);
        puVar39[1] = (char)((uint)iVar28 >> 0x10);
        param_1[0x11] = iVar27 - (int)puVar39;
        param_1[0xd] = 0x1111;
        param_1[0x12] = 0;
        uVar25 = ssl3_do_write(param_1,0x16);
        return uVar25;
      }
      uVar33 = 0x44;
      uVar25 = 0x31c;
    }
  }
LAB_00483ba0:
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x83,uVar33,"s3_clnt.c",uVar25);
  return 0xffffffff;
}
