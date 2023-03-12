
undefined4 ssl3_send_server_hello(undefined4 *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  undefined *puVar19;
  undefined4 uVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  undefined *puVar25;
  undefined4 uVar26;
  uint uVar27;
  uint in_t0;
  uint in_t1;
  uint in_t2;
  uint in_t3;
  undefined *puVar28;
  undefined *puVar29;
  
  if (param_1[0xd] != 0x2130) {
    uVar20 = ssl3_do_write(param_1,0x16);
    return uVar20;
  }
  puVar28 = *(undefined **)(param_1[0xf] + 4);
  puVar28[4] = (char)((uint)*param_1 >> 8);
  puVar28[5] = (char)*param_1;
  iVar24 = param_1[0x16];
  uVar21 = iVar24 + 0xa0U & 3;
  uVar27 = iVar24 + 0xa4U & 3;
  iVar22 = *(int *)((iVar24 + 0xa4U) - uVar27);
  uVar1 = iVar24 + 0xa8U & 3;
  iVar23 = *(int *)((iVar24 + 0xa8U) - uVar1);
  uVar2 = iVar24 + 0xacU & 3;
  iVar5 = *(int *)((iVar24 + 0xacU) - uVar2);
  uVar3 = iVar24 + 0xb0U & 3;
  iVar6 = *(int *)((iVar24 + 0xb0U) - uVar3);
  uVar4 = iVar24 + 0xb4U & 3;
  iVar7 = *(int *)((iVar24 + 0xb4U) - uVar4);
  uVar8 = iVar24 + 0xa3U & 3;
  uVar9 = iVar24 + 0xa7U & 3;
  uVar14 = *(uint *)((iVar24 + 0xa7U) - uVar9);
  uVar10 = iVar24 + 0xabU & 3;
  uVar15 = *(uint *)((iVar24 + 0xabU) - uVar10);
  uVar11 = iVar24 + 0xafU & 3;
  uVar16 = *(uint *)((iVar24 + 0xafU) - uVar11);
  uVar12 = iVar24 + 0xb3U & 3;
  uVar17 = *(uint *)((iVar24 + 0xb3U) - uVar12);
  uVar13 = iVar24 + 0xb7U & 3;
  uVar18 = *(uint *)((iVar24 + 0xb7U) - uVar13);
  uVar26 = *(undefined4 *)(iVar24 + 0xb8);
  uVar20 = *(undefined4 *)(iVar24 + 0xbc);
  *(uint *)(puVar28 + 6) =
       (*(int *)((iVar24 + 0xa0U) - uVar21) << uVar21 * 8 | in_t3 & 0xffffffffU >> (4 - uVar21) * 8)
       & -1 << (uVar8 + 1) * 8 | *(uint *)((iVar24 + 0xa3U) - uVar8) >> (3 - uVar8) * 8;
  *(uint *)(puVar28 + 10) =
       (iVar22 << uVar27 * 8 | in_t2 & 0xffffffffU >> (4 - uVar27) * 8) & -1 << (uVar9 + 1) * 8 |
       uVar14 >> (3 - uVar9) * 8;
  *(uint *)(puVar28 + 0xe) =
       (iVar23 << uVar1 * 8 | in_t1 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar10 + 1) * 8 |
       uVar15 >> (3 - uVar10) * 8;
  *(uint *)(puVar28 + 0x12) =
       (iVar5 << uVar2 * 8 | in_t0 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar11 + 1) * 8 |
       uVar16 >> (3 - uVar11) * 8;
  *(uint *)(puVar28 + 0x16) =
       (iVar6 << uVar3 * 8 | param_4 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar12 + 1) * 8 |
       uVar17 >> (3 - uVar12) * 8;
  *(uint *)(puVar28 + 0x1a) =
       (iVar7 << uVar4 * 8 | param_3 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar13 + 1) * 8 |
       uVar18 >> (3 - uVar13) * 8;
  *(undefined4 *)(puVar28 + 0x1e) = uVar26;
  *(undefined4 *)(puVar28 + 0x22) = uVar20;
  if ((*(uint *)(param_1[0x39] + 0x20) & 2) == 0) {
    uVar21 = param_1[0x1b];
    uVar27 = 0;
    if (uVar21 != 0) goto LAB_0047ef30;
    *(undefined4 *)(param_1[0x30] + 0x44) = 0;
  }
  else {
LAB_0047ef30:
    uVar27 = *(uint *)(param_1[0x30] + 0x44);
    uVar21 = uVar27 & 0xff;
    if (0x20 < (int)uVar27) {
      uVar26 = 0x44;
      uVar20 = 0x5c5;
      goto LAB_0047ef58;
    }
  }
  puVar19 = PTR_memcpy_006aabf4;
  puVar25 = puVar28 + 0x27;
  puVar28[0x26] = (char)uVar21;
  puVar29 = puVar25 + uVar27;
  (*(code *)puVar19)(puVar25,param_1[0x30] + 0x48);
  iVar22 = ssl3_put_cipher_by_char(*(undefined4 *)(param_1[0x16] + 0x344),puVar29);
  uVar21 = *(uint *)(param_1[0x16] + 0x38c);
  if (uVar21 != 0) {
    uVar21 = (uint)*(byte *)(uVar21 + 3);
  }
  puVar29[iVar22] = (char)uVar21;
  iVar23 = ssl_prepare_serverhello_tlsext(param_1);
  if (iVar23 < 1) {
    uVar26 = 0x113;
    uVar20 = 0x5dc;
  }
  else {
    iVar22 = ssl_add_serverhello_tlsext(param_1,puVar29 + iVar22 + 1,puVar28 + 0x4000);
    if (iVar22 != 0) {
      iVar23 = iVar22 - (int)(puVar28 + 4);
      puVar28[3] = (char)iVar23;
      puVar28[1] = (char)((uint)iVar23 >> 0x10);
      puVar28[2] = (char)((uint)iVar23 >> 8);
      *puVar28 = 2;
      param_1[0x11] = iVar22 - (int)puVar28;
      param_1[0x12] = 0;
      param_1[0xd] = 0x2131;
      uVar20 = ssl3_do_write(param_1,0x16);
      return uVar20;
    }
    uVar26 = 0x44;
    uVar20 = 0x5e1;
  }
LAB_0047ef58:
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xf2,uVar26,"s3_srvr.c",uVar20);
  return 0xffffffff;
}

