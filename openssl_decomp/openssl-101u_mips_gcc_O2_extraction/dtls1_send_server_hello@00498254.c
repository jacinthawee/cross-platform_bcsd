
undefined4 dtls1_send_server_hello(undefined4 *param_1)

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
  uint uVar11;
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
  undefined4 uVar24;
  uint uVar25;
  int iVar26;
  undefined *puVar27;
  int iVar29;
  uint uVar30;
  uint uVar31;
  undefined4 uVar32;
  uint uVar33;
  uint in_t0;
  uint in_t1;
  uint in_t2;
  uint in_t3;
  int iVar34;
  int iVar35;
  undefined uVar28;
  
  if (param_1[0xd] != 0x2130) {
    uVar24 = dtls1_do_write(param_1,0x16);
    return uVar24;
  }
  uVar33 = 0x20;
  uVar30 = 1;
  uVar31 = param_1[0x16] + 0xa0;
  iVar34 = *(int *)(param_1[0xf] + 4);
  ssl_fill_hello_random();
  *(char *)(iVar34 + 0xc) = (char)((uint)*param_1 >> 8);
  *(char *)(iVar34 + 0xd) = (char)*param_1;
  iVar29 = param_1[0x16];
  uVar25 = iVar29 + 0xa0U & 3;
  uVar1 = iVar29 + 0xa4U & 3;
  iVar35 = *(int *)((iVar29 + 0xa4U) - uVar1);
  uVar2 = iVar29 + 0xa8U & 3;
  iVar26 = *(int *)((iVar29 + 0xa8U) - uVar2);
  uVar3 = iVar29 + 0xacU & 3;
  iVar7 = *(int *)((iVar29 + 0xacU) - uVar3);
  uVar4 = iVar29 + 0xb0U & 3;
  iVar8 = *(int *)((iVar29 + 0xb0U) - uVar4);
  uVar5 = iVar29 + 0xb4U & 3;
  iVar9 = *(int *)((iVar29 + 0xb4U) - uVar5);
  uVar6 = iVar29 + 0xb8U & 3;
  iVar10 = *(int *)((iVar29 + 0xb8U) - uVar6);
  uVar11 = iVar29 + 0xa3U & 3;
  uVar12 = iVar29 + 0xa7U & 3;
  uVar18 = *(uint *)((iVar29 + 0xa7U) - uVar12);
  uVar13 = iVar29 + 0xabU & 3;
  uVar19 = *(uint *)((iVar29 + 0xabU) - uVar13);
  uVar14 = iVar29 + 0xafU & 3;
  uVar20 = *(uint *)((iVar29 + 0xafU) - uVar14);
  uVar15 = iVar29 + 0xb3U & 3;
  uVar21 = *(uint *)((iVar29 + 0xb3U) - uVar15);
  uVar16 = iVar29 + 0xb7U & 3;
  uVar22 = *(uint *)((iVar29 + 0xb7U) - uVar16);
  uVar17 = iVar29 + 0xbbU & 3;
  uVar23 = *(uint *)((iVar29 + 0xbbU) - uVar17);
  uVar24 = *(undefined4 *)(iVar29 + 0xbc);
  *(uint *)(iVar34 + 0xe) =
       (*(int *)((iVar29 + 0xa0U) - uVar25) << uVar25 * 8 | in_t3 & 0xffffffffU >> (4 - uVar25) * 8)
       & -1 << (uVar11 + 1) * 8 | *(uint *)((iVar29 + 0xa3U) - uVar11) >> (3 - uVar11) * 8;
  *(uint *)(iVar34 + 0x12) =
       (iVar35 << uVar1 * 8 | in_t2 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar12 + 1) * 8 |
       uVar18 >> (3 - uVar12) * 8;
  *(uint *)(iVar34 + 0x16) =
       (iVar26 << uVar2 * 8 | in_t1 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar13 + 1) * 8 |
       uVar19 >> (3 - uVar13) * 8;
  *(uint *)(iVar34 + 0x1a) =
       (iVar7 << uVar3 * 8 | in_t0 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar14 + 1) * 8 |
       uVar20 >> (3 - uVar14) * 8;
  *(uint *)(iVar34 + 0x1e) =
       (iVar8 << uVar4 * 8 | uVar33 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar15 + 1) * 8 |
       uVar21 >> (3 - uVar15) * 8;
  *(uint *)(iVar34 + 0x22) =
       (iVar9 << uVar5 * 8 | uVar31 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar16 + 1) * 8 |
       uVar22 >> (3 - uVar16) * 8;
  *(uint *)(iVar34 + 0x26) =
       (iVar10 << uVar6 * 8 | uVar30 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar17 + 1) * 8 |
       uVar23 >> (3 - uVar17) * 8;
  *(undefined4 *)(iVar34 + 0x2a) = uVar24;
  uVar25 = *(uint *)(param_1[0x39] + 0x20) & 2;
  uVar28 = (undefined)uVar25;
  if (uVar25 == 0) {
    uVar25 = 0;
    *(undefined4 *)(param_1[0x30] + 0x44) = 0;
  }
  else {
    uVar25 = *(uint *)(param_1[0x30] + 0x44);
    uVar28 = (undefined)uVar25;
    if (0x20 < uVar25) {
      uVar32 = 0x44;
      uVar24 = 0x3f4;
      goto LAB_004984c0;
    }
  }
  puVar27 = PTR_memcpy_006a9aec;
  *(undefined *)(iVar34 + 0x2e) = uVar28;
  iVar35 = iVar34 + 0x2f + uVar25;
  (*(code *)puVar27)(iVar34 + 0x2f,param_1[0x30] + 0x48);
  if (*(int *)(param_1[0x16] + 0x344) == 0) {
    return 0xffffffff;
  }
  iVar26 = ssl3_put_cipher_by_char(*(int *)(param_1[0x16] + 0x344),iVar35);
  puVar27 = (undefined *)(iVar35 + iVar26);
  uVar25 = *(uint *)(param_1[0x16] + 0x38c);
  if (uVar25 != 0) {
    uVar25 = (uint)*(byte *)(uVar25 + 3);
  }
  *puVar27 = (char)uVar25;
  iVar35 = ssl_prepare_serverhello_tlsext(param_1);
  if (iVar35 < 1) {
    uVar32 = 0x113;
    uVar24 = 0x40d;
  }
  else {
    iVar35 = ssl_add_serverhello_tlsext(param_1,puVar27 + 1,iVar34 + 0x4000);
    if (iVar35 != 0) {
      iVar26 = iVar35 - (iVar34 + 0xc);
      dtls1_set_message_header(param_1,iVar34,2,iVar26,0,iVar26);
      param_1[0x12] = 0;
      param_1[0x11] = iVar35 - iVar34;
      param_1[0xd] = 0x2131;
      dtls1_buffer_message(param_1,0);
      uVar24 = dtls1_do_write(param_1,0x16);
      return uVar24;
    }
    uVar32 = 0x44;
    uVar24 = 0x414;
  }
LAB_004984c0:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x10a,uVar32,"d1_srvr.c",uVar24);
  return 0xffffffff;
}

