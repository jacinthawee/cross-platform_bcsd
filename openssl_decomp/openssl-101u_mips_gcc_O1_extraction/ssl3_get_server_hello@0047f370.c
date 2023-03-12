
int ssl3_get_server_hello(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
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
  uint uVar26;
  uint uVar27;
  undefined *puVar28;
  undefined *puVar29;
  int iVar30;
  int iVar31;
  uint uVar32;
  int iVar33;
  byte *pbVar34;
  uint uVar35;
  uint uVar36;
  undefined4 uVar37;
  uint uVar38;
  uint uVar39;
  uint in_t1;
  uint in_t2;
  uint in_t3;
  byte *pbVar40;
  code *pcVar41;
  undefined4 uVar42;
  byte *local_34;
  undefined4 local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  puVar28 = PTR___stack_chk_guard_006a9ae8;
  uVar39 = 20000;
  uVar38 = 0xffffffff;
  uVar36 = 0x1121;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar30 = (**(code **)(param_1[2] + 0x30))(param_1,0x1120,0x1121,0xffffffff,20000,&local_2c);
  if (local_2c == 0) goto LAB_0047f3ec;
  iVar31 = (*(code *)PTR_SSL_version_006a77ec)(param_1);
  if ((iVar31 == 0xfeff) || (iVar31 = (*(code *)PTR_SSL_version_006a77ec)(param_1), iVar31 == 0x100)
     ) {
    uVar35 = param_1[0x16];
    iVar31 = *(int *)(uVar35 + 0x340);
    if (iVar31 == 3) {
      if (*(int *)param_1[0x17] != 0) {
        uVar37 = 0x72;
        uVar42 = 0x361;
        local_30 = 10;
        goto LAB_0047f7e8;
      }
      iVar30 = 1;
      *(undefined4 *)(uVar35 + 0x354) = 1;
      goto LAB_0047f3ec;
    }
  }
  else {
    uVar35 = param_1[0x16];
    iVar31 = *(int *)(uVar35 + 0x340);
  }
  if (iVar31 != 2) {
    uVar37 = 0x72;
    uVar42 = 0x369;
    local_30 = 10;
    goto LAB_0047f7e8;
  }
  pbVar40 = (byte *)param_1[0x10];
  if ((uint)*pbVar40 != (int)*param_1 >> 8) {
LAB_0047f820:
    local_34 = pbVar40;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x92,0x10a,"s3_clnt.c",0x370);
    local_30 = 0x46;
    *param_1 = *param_1 & 0xff00 | (uint)local_34[1];
    goto LAB_0047f86c;
  }
  uVar32 = *param_1 & 0xff;
  if (pbVar40[1] != uVar32) goto LAB_0047f820;
  local_34 = pbVar40 + 0x23;
  uVar2 = (uint)(pbVar40 + 6) & 3;
  iVar31 = *(int *)(pbVar40 + 6 + -uVar2);
  uVar3 = (uint)(pbVar40 + 10) & 3;
  iVar33 = *(int *)(pbVar40 + 10 + -uVar3);
  uVar4 = (uint)(pbVar40 + 0xe) & 3;
  iVar9 = *(int *)(pbVar40 + 0xe + -uVar4);
  uVar5 = (uint)(pbVar40 + 0x12) & 3;
  iVar10 = *(int *)(pbVar40 + 0x12 + -uVar5);
  uVar6 = (uint)(pbVar40 + 0x16) & 3;
  iVar11 = *(int *)(pbVar40 + 0x16 + -uVar6);
  uVar7 = (uint)(pbVar40 + 0x1a) & 3;
  iVar12 = *(int *)(pbVar40 + 0x1a + -uVar7);
  uVar8 = (uint)(pbVar40 + 0x1e) & 3;
  iVar13 = *(int *)(pbVar40 + 0x1e + -uVar8);
  uVar14 = (uint)(pbVar40 + 9) & 3;
  uVar21 = *(uint *)(pbVar40 + 9 + -uVar14);
  uVar15 = (uint)(pbVar40 + 0xd) & 3;
  uVar22 = *(uint *)(pbVar40 + 0xd + -uVar15);
  uVar16 = (uint)(pbVar40 + 0x11) & 3;
  uVar23 = *(uint *)(pbVar40 + 0x11 + -uVar16);
  uVar17 = (uint)(pbVar40 + 0x15) & 3;
  uVar24 = *(uint *)(pbVar40 + 0x15 + -uVar17);
  uVar18 = (uint)(pbVar40 + 0x19) & 3;
  uVar25 = *(uint *)(pbVar40 + 0x19 + -uVar18);
  uVar19 = (uint)(pbVar40 + 0x1d) & 3;
  uVar26 = *(uint *)(pbVar40 + 0x1d + -uVar19);
  uVar20 = (uint)(pbVar40 + 0x21) & 3;
  uVar27 = *(uint *)(pbVar40 + 0x21 + -uVar20);
  *(undefined4 *)(uVar35 + 0xa0) = *(undefined4 *)(pbVar40 + 2);
  *(uint *)(uVar35 + 0xa4) =
       (iVar31 << uVar2 * 8 | in_t3 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar14 + 1) * 8 |
       uVar21 >> (3 - uVar14) * 8;
  *(uint *)(uVar35 + 0xa8) =
       (iVar33 << uVar3 * 8 | in_t2 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar15 + 1) * 8 |
       uVar22 >> (3 - uVar15) * 8;
  *(uint *)(uVar35 + 0xac) =
       (iVar9 << uVar4 * 8 | in_t1 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar16 + 1) * 8 |
       uVar23 >> (3 - uVar16) * 8;
  *(uint *)(uVar35 + 0xb0) =
       (iVar10 << uVar5 * 8 | uVar39 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar17 + 1) * 8 |
       uVar24 >> (3 - uVar17) * 8;
  *(uint *)(uVar35 + 0xb4) =
       (iVar11 << uVar6 * 8 | uVar38 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar18 + 1) * 8 |
       uVar25 >> (3 - uVar18) * 8;
  *(uint *)(uVar35 + 0xb8) =
       (iVar12 << uVar7 * 8 | uVar36 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar19 + 1) * 8 |
       uVar26 >> (3 - uVar19) * 8;
  *(uint *)(uVar35 + 0xbc) =
       (iVar13 << uVar8 * 8 | uVar32 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar20 + 1) * 8 |
       uVar27 >> (3 - uVar20) * 8;
  param_1[0x1b] = 0;
  uVar36 = (uint)pbVar40[0x22];
  if (0x20 < uVar36) {
    uVar37 = 300;
    uVar42 = 899;
    local_30 = 0x2f;
    goto LAB_0047f7e8;
  }
  if (((int)*param_1 < 0x301) || (pcVar41 = (code *)param_1[0x5a], pcVar41 == (code *)0x0)) {
    uVar38 = param_1[0x30];
  }
  else {
    uVar38 = param_1[0x30];
    if (*(int *)(uVar38 + 0xe4) != 0) {
      uVar39 = param_1[0x5b];
      local_28 = 0;
      *(undefined4 *)(uVar38 + 0x10) = 0x30;
      iVar31 = (*pcVar41)(param_1,uVar38 + 0x14,uVar38 + 0x10,0,&local_28,uVar39);
      if (iVar31 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x92,0x44,"s3_clnt.c",0x39e);
        local_30 = 0x50;
        goto LAB_0047f86c;
      }
      uVar39 = param_1[0x30];
      if (local_28 == 0) {
        uVar37 = (**(code **)(param_1[2] + 0x48))(local_34 + uVar36);
        uVar38 = param_1[0x30];
        *(undefined4 *)(uVar39 + 0xb4) = uVar37;
      }
      else {
        *(int *)(uVar39 + 0xb4) = local_28;
        uVar38 = uVar39;
      }
    }
  }
  pbVar34 = local_34;
  if ((uVar36 == 0) || (uVar36 != *(uint *)(uVar38 + 0x44))) {
    if (*(uint *)(uVar38 + 0x44) != 0) goto LAB_0047f804;
LAB_0047f5f8:
    pbVar34 = local_34;
    puVar29 = PTR_memcpy_006a9aec;
    *(uint *)(uVar38 + 0x44) = uVar36;
    (*(code *)puVar29)(uVar38 + 0x48,local_34,uVar36);
  }
  else {
    iVar31 = (*(code *)PTR_memcmp_006a9ad0)(local_34,uVar38 + 0x48,uVar36);
    if (iVar31 != 0) {
LAB_0047f804:
      iVar31 = (*(code *)PTR_ssl_get_new_session_006a7f40)(param_1,0);
      if (iVar31 == 0) goto LAB_0047f9ac;
      uVar38 = param_1[0x30];
      goto LAB_0047f5f8;
    }
    if ((param_1[0x27] != *(uint *)(uVar38 + 0x68)) ||
       (iVar31 = (*(code *)PTR_memcmp_006a9ad0)(uVar38 + 0x6c,param_1 + 0x28), iVar31 != 0)) {
      uVar37 = 0x110;
      uVar42 = 0x3ac;
      local_30 = 0x2f;
      goto LAB_0047f7e8;
    }
    param_1[0x1b] = 1;
  }
  local_34 = pbVar34 + uVar36;
  iVar31 = (**(code **)(param_1[2] + 0x48))(local_34);
  if (iVar31 == 0) {
    uVar37 = 0xf8;
    uVar42 = 0x3c6;
    local_30 = 0x2f;
    goto LAB_0047f7e8;
  }
  if (((*(uint *)(iVar31 + 0x1c) & 4) != 0) &&
     (((int)*param_1 >> 8 != 3 || ((int)*param_1 < 0x303)))) {
    uVar37 = 0x105;
    uVar42 = 0x3cd;
    local_30 = 0x2f;
    goto LAB_0047f7e8;
  }
  if ((((*(uint *)(iVar31 + 0xc) & 0x400) != 0) || ((*(uint *)(iVar31 + 0x10) & 0x400) != 0)) &&
     ((param_1[0x74] & 0x400) == 0)) {
    uVar37 = 0x105;
    uVar42 = 0x3d4;
    local_30 = 0x2f;
    goto LAB_0047f7e8;
  }
  iVar33 = (**(code **)(param_1[2] + 0x4c))(0,0);
  local_34 = local_34 + iVar33;
  uVar37 = (*(code *)PTR_ssl_get_ciphers_by_id_006a8040)(param_1);
  iVar33 = (*(code *)PTR_sk_find_006a8044)(uVar37,iVar31);
  if (iVar33 < 0) {
    uVar37 = 0x105;
    uVar42 = 0x3df;
    local_30 = 0x2f;
    goto LAB_0047f7e8;
  }
  uVar36 = param_1[0x30];
  if (*(int *)(uVar36 + 0xb4) != 0) {
    *(undefined4 *)(uVar36 + 0xb8) = *(undefined4 *)(*(int *)(uVar36 + 0xb4) + 8);
  }
  uVar38 = param_1[0x1b];
  if ((uVar38 != 0) && (*(int *)(uVar36 + 0xb8) != *(int *)(iVar31 + 8))) {
    uVar37 = 0xc5;
    uVar42 = 0x3f2;
    local_30 = 0x2f;
    goto LAB_0047f7e8;
  }
  uVar36 = *param_1;
  *(int *)(param_1[0x16] + 0x344) = iVar31;
  if (((int)uVar36 >> 8 != 3) || ((int)uVar36 < 0x303)) {
    iVar31 = ssl3_digest_cached_records(param_1);
    if (iVar31 == 0) {
LAB_0047f9ac:
      local_30 = 0x50;
      goto LAB_0047f86c;
    }
    uVar38 = param_1[0x1b];
  }
  pbVar34 = local_34 + 1;
  bVar1 = *local_34;
  local_34 = pbVar34;
  if ((uVar38 != 0) && ((uint)bVar1 != *(uint *)(param_1[0x30] + 0xb0))) {
    uVar37 = 0x158;
    uVar42 = 0x417;
    local_30 = 0x2f;
    goto LAB_0047f7e8;
  }
  iVar31 = 0;
  if (bVar1 != 0) {
    if ((int)(param_1[0x40] << 0xe) < 0) {
      uVar37 = 0x157;
      uVar42 = 0x41e;
      local_30 = 0x2f;
      goto LAB_0047f7e8;
    }
    iVar31 = (*(code *)PTR_ssl3_comp_find_006a8048)(*(undefined4 *)(param_1[0x39] + 0x98));
    if (iVar31 == 0) goto LAB_0047fb64;
  }
  uVar36 = *param_1;
  *(int *)(param_1[0x16] + 0x38c) = iVar31;
  if (0x2ff < (int)uVar36) {
    iVar31 = ssl_parse_serverhello_tlsext(param_1,&local_34,pbVar40,iVar30,&local_30);
    if (iVar31 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x92,0xe3,"s3_clnt.c",0x432);
      goto LAB_0047f86c;
    }
    iVar31 = ssl_check_serverhello_tlsext(param_1);
    if (iVar31 < 1) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x92,0x113,"s3_clnt.c",0x436);
      goto LAB_0047f880;
    }
  }
  pbVar40 = pbVar40 + iVar30;
  iVar30 = 1;
  if (local_34 != pbVar40) {
    uVar37 = 0x73;
    uVar42 = 0x43f;
    local_30 = 0x32;
    goto LAB_0047f7e8;
  }
LAB_0047f3ec:
  while (local_24 != *(int *)puVar28) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0047fb64:
    uVar37 = 0x101;
    uVar42 = 0x426;
    local_30 = 0x2f;
LAB_0047f7e8:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x92,uVar37,"s3_clnt.c",uVar42);
LAB_0047f86c:
    ssl3_send_alert(param_1,2,local_30);
LAB_0047f880:
    iVar30 = -1;
    param_1[0xd] = 5;
  }
  return iVar30;
}

