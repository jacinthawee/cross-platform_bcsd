
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Could not reconcile some variable overlaps */

undefined4 *******
dgram_ctrl(undefined4 *******param_1,int param_2,undefined4 *******param_3,undefined4 *param_4)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
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
  uint *puVar19;
  undefined *puVar20;
  int *piVar21;
  int iVar22;
  undefined4 *******pppppppuVar23;
  undefined4 ******ppppppuVar24;
  undefined4 *****pppppuVar25;
  undefined4 *****pppppuVar26;
  BIO *b;
  undefined4 uVar27;
  undefined4 ******ppppppuVar28;
  undefined4 uVar29;
  uint in_t0;
  uint in_t1;
  uint in_t2;
  void *pvVar30;
  undefined4 ******unaff_s3;
  undefined4 *******unaff_s4;
  undefined4 uStack_c8;
  int iStack_c4;
  int iStack_c0;
  int iStack_bc;
  int iStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  int iStack_94;
  undefined4 ******ppppppuStack_90;
  undefined *puStack_8c;
  undefined4 *******pppppppuStack_88;
  undefined4 ******ppppppuStack_84;
  undefined4 *******pppppppuStack_80;
  uint local_44;
  undefined4 local_40;
  undefined4 *******local_3c;
  undefined4 *****local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  BIO *local_1c;
  
  puStack_8c = PTR___stack_chk_guard_006aabf0;
  puVar20 = PTR_memset_006aab00;
  ppppppuStack_90 = param_1[8];
  local_44 = 0;
  local_1c = *(BIO **)PTR___stack_chk_guard_006aabf0;
  ppppppuVar28 = (undefined4 ******)(&switchD_0052cdf4::switchdataD_00668400 + param_2 + -8);
  switch(param_2 + -8) {
  case 0:
    pppppppuVar23 = (undefined4 *******)param_1[4];
    break;
  case 1:
    param_1[4] = param_3;
    pppppppuVar23 = (undefined4 *******)0x1;
    break;
  default:
    goto switchD_0052cdf4_caseD_a;
  case 3:
  case 4:
    goto switchD_0052cdf4_caseD_b;
  case 0x17:
  case 0x24:
    sVar1 = *(short *)param_4;
    pppppppuVar23 = param_1;
joined_r0x0052cee8:
    if ((sVar1 == 2) || (sVar1 != 10)) {
      param_3 = (undefined4 *******)*param_4;
      ppppppuVar28 = (undefined4 ******)param_4[1];
      pppppuVar25 = (undefined4 *****)param_4[2];
      pppppuVar26 = (undefined4 *****)param_4[3];
      *ppppppuStack_90 = param_3;
      ppppppuStack_90[1] = ppppppuVar28;
      ppppppuStack_90[2] = pppppuVar25;
      ppppppuStack_90[3] = pppppuVar26;
      pppppppuVar23 = (undefined4 *******)0x1;
    }
    else {
      uVar18 = (uint)param_4 & 3;
      uVar2 = (uint)(param_4 + 1) & 3;
      iVar22 = *(int *)((int)(param_4 + 1) - uVar2);
      uVar3 = (uint)(param_4 + 2) & 3;
      iVar8 = *(int *)((int)(param_4 + 2) - uVar3);
      uVar4 = (uint)(param_4 + 3) & 3;
      uVar5 = (uint)(param_4 + 4) & 3;
      uVar6 = (uint)(param_4 + 5) & 3;
      iVar9 = *(int *)((int)(param_4 + 5) - uVar6);
      uVar7 = (uint)(param_4 + 6) & 3;
      iVar10 = *(int *)((int)(param_4 + 6) - uVar7);
      uVar11 = (int)param_4 + 3U & 3;
      uVar12 = (int)param_4 + 7U & 3;
      uVar15 = *(uint *)(((int)param_4 + 7U) - uVar12);
      uVar13 = (int)param_4 + 0xbU & 3;
      uVar16 = *(uint *)(((int)param_4 + 0xbU) - uVar13);
      uVar14 = (int)param_4 + 0xfU & 3;
      param_3 = (undefined4 *******)
                ((*(int *)((int)(param_4 + 3) - uVar4) << uVar4 * 8 |
                 (uint)param_3 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar14 + 1) * 8 |
                *(uint *)(((int)param_4 + 0xfU) - uVar14) >> (3 - uVar14) * 8);
      uVar4 = (int)param_4 + 0x13U & 3;
      ppppppuVar28 = (undefined4 ******)
                     ((*(int *)((int)(param_4 + 4) - uVar5) << uVar5 * 8 |
                      (uint)ppppppuVar28 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar4 + 1) * 8 |
                     *(uint *)(((int)param_4 + 0x13U) - uVar4) >> (3 - uVar4) * 8);
      uVar4 = (int)param_4 + 0x17U & 3;
      uVar14 = *(uint *)(((int)param_4 + 0x17U) - uVar4);
      uVar5 = (int)param_4 + 0x1bU & 3;
      uVar17 = *(uint *)(((int)param_4 + 0x1bU) - uVar5);
      *ppppppuStack_90 =
           (undefined4 *****)
           ((*(int *)((int)param_4 - uVar18) << uVar18 * 8 | in_t2 & 0xffffffffU >> (4 - uVar18) * 8
            ) & -1 << (uVar11 + 1) * 8 | *(uint *)(((int)param_4 + 3U) - uVar11) >> (3 - uVar11) * 8
           );
      ppppppuStack_90[1] =
           (undefined4 *****)
           ((iVar22 << uVar2 * 8 | in_t1 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar12 + 1) * 8
           | uVar15 >> (3 - uVar12) * 8);
      ppppppuStack_90[2] =
           (undefined4 *****)
           ((iVar8 << uVar3 * 8 | in_t0 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar13 + 1) * 8 |
           uVar16 >> (3 - uVar13) * 8);
      ppppppuStack_90[3] = param_3;
      ppppppuStack_90[4] = ppppppuVar28;
      ppppppuStack_90[5] =
           (undefined4 *****)
           ((iVar9 << uVar6 * 8 | (uint)pppppppuVar23 & 0xffffffffU >> (4 - uVar6) * 8) &
            -1 << (uVar4 + 1) * 8 | uVar14 >> (3 - uVar4) * 8);
      ppppppuStack_90[6] =
           (undefined4 *****)
           ((iVar10 << uVar7 * 8 | 0xffffffffU >> (4 - uVar7) * 8 & 10) & -1 << (uVar5 + 1) * 8 |
           uVar17 >> (3 - uVar5) * 8);
      pppppppuVar23 = (undefined4 *******)0x1;
    }
    break;
  case 0x18:
    if (param_4 != (undefined4 *)0x0) {
      sVar1 = *(short *)param_4;
      ppppppuStack_90[7] = (undefined4 *****)0x1;
      pppppppuVar23 = (undefined4 *******)0x1;
      goto joined_r0x0052cee8;
    }
    param_3 = (undefined4 *******)0x1c;
    ppppppuVar28 = (undefined4 ******)0x0;
    ppppppuStack_90[7] = (undefined4 *****)0x0;
    (*(code *)puVar20)(ppppppuStack_90,0,0x1c);
    pppppppuVar23 = (undefined4 *******)0x1;
    break;
  case 0x19:
    ppppppuVar24 = param_1[7];
    param_3 = (undefined4 *******)0x1006;
    goto LAB_0052d0a8;
  case 0x1a:
    ppppppuVar24 = param_1[7];
    param_3 = (undefined4 *******)0x1006;
    goto LAB_0052d0f8;
  case 0x1b:
    ppppppuVar24 = param_1[7];
    param_3 = (undefined4 *******)0x1005;
LAB_0052d0a8:
    ppppppuVar28 = (undefined4 ******)0xffff;
    iVar22 = (*(code *)PTR_setsockopt_006aac34)(ppppppuVar24,0xffff,param_3);
    if (iVar22 < 0) {
      (*(code *)PTR_perror_006aab88)("setsockopt");
      pppppppuVar23 = (undefined4 *******)0xffffffff;
    }
    else {
switchD_0052cdf4_caseD_b:
      pppppppuVar23 = (undefined4 *******)0x1;
    }
    break;
  case 0x1c:
    ppppppuVar24 = param_1[7];
    param_3 = (undefined4 *******)0x1005;
LAB_0052d0f8:
    ppppppuVar28 = (undefined4 ******)0xffff;
    local_3c = (undefined4 *******)&DAT_00000008;
    iVar22 = (*(code *)PTR_getsockopt_006aab98)(ppppppuVar24,0xffff,param_3);
    pppppppuVar23 = local_3c;
    if (iVar22 < 0) {
      (*(code *)PTR_perror_006aab88)("getsockopt");
      pppppppuVar23 = (undefined4 *******)0xffffffff;
    }
    break;
  case 0x1d:
  case 0x1e:
    if (ppppppuStack_90[8] != (undefined4 *****)&DAT_0000000b) goto switchD_0052cdf4_caseD_a;
LAB_0052d140:
    ppppppuStack_90[8] = (undefined4 *****)0x0;
    pppppppuVar23 = (undefined4 *******)0x1;
    break;
  case 0x1f:
    unaff_s3 = &local_38;
    unaff_s4 = &local_3c;
    local_38 = (undefined4 *****)0x0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_3c = (undefined4 *******)0x1c;
    ppppppuVar28 = unaff_s3;
    param_3 = unaff_s4;
    iVar22 = (*(code *)PTR_getsockname_006aaaa0)(param_1[7],unaff_s3,unaff_s4);
    if (-1 < iVar22) {
      uVar18 = (uint)local_38 >> 0x10;
      if (uVar18 == 2) {
        ppppppuVar28 = param_1[7];
        uVar29 = 10;
        uVar27 = 0;
        local_44 = uVar18;
      }
      else {
        if (uVar18 != 10) goto LAB_0052d000;
        ppppppuVar28 = param_1[7];
        uVar29 = 0x17;
        uVar27 = 0x29;
        local_44 = 2;
      }
      iVar22 = (*(code *)PTR_setsockopt_006aac34)(ppppppuVar28,uVar27,uVar29,&local_44);
      if (iVar22 < 0) {
        (*(code *)PTR_perror_006aab88)("setsockopt");
      }
      goto LAB_0052d000;
    }
    goto switchD_0052cdf4_caseD_a;
  case 0x20:
LAB_0052d000:
    unaff_s4 = &local_3c;
    unaff_s3 = &local_38;
    local_38 = (undefined4 *****)0x0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_3c = (undefined4 *******)0x1c;
    ppppppuVar28 = unaff_s3;
    param_3 = unaff_s4;
    iVar22 = (*(code *)PTR_getsockname_006aaaa0)(param_1[7],unaff_s3,unaff_s4);
    if (iVar22 < 0) goto switchD_0052cdf4_caseD_a;
    local_40 = 4;
    if (local_38._0_2_ == 2) {
      param_3 = (undefined4 *******)&DAT_0000000e;
      ppppppuVar28 = (undefined4 ******)0x0;
      iVar22 = (*(code *)PTR_getsockopt_006aab98)(param_1[7],0,0xe,&local_44);
      if ((iVar22 < 0) || (pppppppuVar23 = (undefined4 *******)(local_44 - 0x1c), (int)local_44 < 0)
         ) goto switchD_0052cdf4_caseD_a;
      ppppppuStack_90[9] = pppppppuVar23;
    }
    else {
      pppppppuVar23 = (undefined4 *******)0x0;
      if (local_38._0_2_ == 10) {
        param_3 = (undefined4 *******)&DAT_00000018;
        ppppppuVar28 = (undefined4 ******)0x29;
        iVar22 = (*(code *)PTR_getsockopt_006aab98)(param_1[7],0x29,0x18,&local_44);
        if ((iVar22 < 0) ||
           (pppppppuVar23 = (undefined4 *******)(local_44 - 0x30), (int)local_44 < 0))
        goto switchD_0052cdf4_caseD_a;
        ppppppuStack_90[9] = pppppppuVar23;
      }
    }
    break;
  case 0x21:
    pppppppuVar23 = (undefined4 *******)ppppppuStack_90[9];
    break;
  case 0x22:
    ppppppuStack_90[9] = param_3;
    pppppppuVar23 = param_3;
    break;
  case 0x23:
    if (ppppppuStack_90[8] == (undefined4 *****)&DAT_00000061) goto LAB_0052d140;
switchD_0052cdf4_caseD_a:
    pppppppuVar23 = (undefined4 *******)0x0;
    break;
  case 0x25:
    ppppppuVar28 = (undefined4 ******)*param_4;
    pppppuVar26 = (undefined4 *****)param_4[1];
    uVar18 = (uint)(ppppppuStack_90 + 10) & 3;
    puVar19 = (uint *)((int)(ppppppuStack_90 + 10) - uVar18);
    *puVar19 = *puVar19 & -1 << (4 - uVar18) * 8 | (uint)ppppppuVar28 >> uVar18 * 8;
    uVar18 = (uint)(undefined *)((int)ppppppuStack_90 + 0x2b) & 3;
    puVar19 = (uint *)((undefined *)((int)ppppppuStack_90 + 0x2b) + -uVar18);
    *puVar19 = *puVar19 & 0xffffffffU >> (uVar18 + 1) * 8 | (int)ppppppuVar28 << (3 - uVar18) * 8;
    ppppppuStack_90[0xb] = pppppuVar26;
    pppppppuVar23 = (undefined4 *******)0x1;
    break;
  case 0x26:
    pppppppuVar23 = (undefined4 *******)&SUB_00000010;
    if (*(short *)ppppppuStack_90 == 10) {
      pppppppuVar23 = (undefined4 *******)0x1c;
    }
    param_1 = pppppppuVar23;
    if ((param_3 != (undefined4 *******)0x0) &&
       (param_1 = param_3, (int)pppppppuVar23 <= (int)param_3)) {
      param_1 = pppppppuVar23;
    }
    ppppppuVar28 = ppppppuStack_90;
    param_3 = param_1;
    (*(code *)PTR_memcpy_006aabf4)(param_4,ppppppuStack_90,param_1);
    pppppppuVar23 = param_1;
    break;
  case 0x27:
    pppppppuVar23 = (undefined4 *******)0x224;
    if ((*(short *)ppppppuStack_90 == 10) &&
       (pppppppuVar23 = (undefined4 *******)0x4d0, ppppppuStack_90[2] == (undefined4 *****)0x0)) {
      if (ppppppuStack_90[3] == (undefined4 *****)0x0) {
        pppppppuVar23 = (undefined4 *******)0x224;
        if (ppppppuStack_90[4] != (undefined4 *****)0xffff) {
          pppppppuVar23 = (undefined4 *******)0x4d0;
        }
      }
      else {
        pppppppuVar23 = (undefined4 *******)0x4d0;
      }
    }
    break;
  case 0x60:
    if (param_1[4] != (undefined4 ******)0x0) {
      if (param_1[3] == (undefined4 ******)0x0) {
        param_1[3] = (undefined4 ******)0x0;
        param_1[5] = (undefined4 ******)0x0;
      }
      else {
        ppppppuVar28 = (undefined4 ******)&SUB_00000002;
        (*(code *)PTR_shutdown_006aaa6c)(param_1[7]);
        (*(code *)PTR_close_006aaa5c)(param_1[7]);
        param_1[3] = (undefined4 ******)0x0;
        param_1[5] = (undefined4 ******)0x0;
      }
    }
    ppppppuVar24 = (undefined4 ******)*param_4;
    param_1[4] = param_3;
    param_1[3] = (undefined4 ******)0x1;
    param_1[7] = ppppppuVar24;
    pppppppuVar23 = (undefined4 *******)0x1;
    break;
  case 0x61:
    if (param_1[3] == (undefined4 ******)0x0) {
      pppppppuVar23 = (undefined4 *******)0xffffffff;
    }
    else {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = param_1[7];
      }
      pppppppuVar23 = (undefined4 *******)param_1[7];
    }
  }
  if (local_1c == *(BIO **)puStack_8c) {
    return pppppppuVar23;
  }
  b = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar20 = PTR___stack_chk_guard_006aabf0;
  pvVar30 = b->ptr;
  uStack_b4 = 0x1c;
  iStack_94 = *(int *)PTR___stack_chk_guard_006aabf0;
  pppppppuStack_88 = param_1;
  ppppppuStack_84 = unaff_s3;
  pppppppuStack_80 = unaff_s4;
  if (ppppppuVar28 == (undefined4 ******)0x0) {
    pppppppuVar23 = (undefined4 *******)0x0;
    goto LAB_0052d568;
  }
  piVar21 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
  uStack_a4 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  uStack_98 = 0;
  *piVar21 = 0;
  uStack_b0 = 0;
  uStack_c8 = 0;
  uStack_ac = 0;
  uStack_a8 = 0;
  if ((*(int *)((int)pvVar30 + 0x28) < 1) && (*(int *)((int)pvVar30 + 0x2c) < 1)) {
    iVar22 = b->num;
  }
  else {
    uStack_c8 = 8;
    iVar22 = (*(code *)PTR_getsockopt_006aab98)(b->num,0xffff,0x1006,(int)pvVar30 + 0x30,&uStack_c8)
    ;
    if (iVar22 < 0) {
      (*(code *)PTR_perror_006aab88)("getsockopt");
    }
    (*(code *)PTR_gettimeofday_006aabd4)(&iStack_c4,0);
    iStack_bc = *(int *)((int)pvVar30 + 0x28) - iStack_c4;
    iStack_b8 = *(int *)((int)pvVar30 + 0x2c) - iStack_c0;
    if (iStack_b8 < 0) {
      iStack_bc = iStack_bc + -1;
      iStack_b8 = iStack_b8 + 1000000;
    }
    if (iStack_bc < 0) {
      iStack_bc = 0;
      iStack_b8 = 1;
    }
    iVar22 = *(int *)((int)pvVar30 + 0x30);
    if (iVar22 == 0) {
      if (*(int *)((int)pvVar30 + 0x34) != 0) goto LAB_0052d5c0;
LAB_0052d4a0:
      iVar22 = (*(code *)PTR_setsockopt_006aac34)(b->num,0xffff,0x1006,&iStack_bc,8);
      if (iVar22 < 0) {
        (*(code *)PTR_perror_006aab88)("setsockopt");
      }
    }
    else {
      if (iStack_bc < iVar22) goto LAB_0052d4a0;
LAB_0052d5c0:
      if ((iStack_bc == iVar22) && (iStack_b8 <= *(int *)((int)pvVar30 + 0x34))) goto LAB_0052d4a0;
    }
    iVar22 = b->num;
  }
  pppppppuVar23 =
       (undefined4 *******)
       (*(code *)PTR_recvfrom_006aabc0)(iVar22,ppppppuVar28,param_3,0,&uStack_b0,&uStack_b4);
  if (*(int *)((int)pvVar30 + 0x1c) == 0) {
    if ((int)pppppppuVar23 < 0) {
      BIO_clear_flags(b,0xf);
      if ((int)pppppppuVar23 + 1U < 2) {
        iVar22 = *piVar21;
        goto LAB_0052d60c;
      }
    }
    else {
      BIO_ctrl(b,0x2c,0,&uStack_b0);
      BIO_clear_flags(b,0xf);
    }
  }
  else {
    BIO_clear_flags(b,0xf);
    if (((int)pppppppuVar23 < 0) && ((int)pppppppuVar23 + 1U < 2)) {
      iVar22 = *piVar21;
LAB_0052d60c:
      if (iVar22 == 0x47) {
LAB_0052d638:
        BIO_set_flags(b,9);
        *(int *)((int)pvVar30 + 0x20) = *piVar21;
      }
      else if (iVar22 < 0x48) {
        if ((iVar22 == 4) || (iVar22 == 0xb)) goto LAB_0052d638;
      }
      else if (iVar22 - 0x95U < 2) goto LAB_0052d638;
    }
  }
  pvVar30 = b->ptr;
  if (((0 < *(int *)((int)pvVar30 + 0x28)) || (0 < *(int *)((int)pvVar30 + 0x2c))) &&
     (iVar22 = (*(code *)PTR_setsockopt_006aac34)(b->num,0xffff,0x1006,(int)pvVar30 + 0x30,8),
     iVar22 < 0)) {
    (*(code *)PTR_perror_006aab88)("setsockopt");
  }
LAB_0052d568:
  if (iStack_94 == *(int *)puVar20) {
    return pppppppuVar23;
  }
  iVar22 = iStack_94;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (iVar22 == 0) {
    return (undefined4 *******)0x0;
  }
  if (*(int *)(iVar22 + 0x10) == 0) {
    iVar22 = *(int *)(iVar22 + 0x20);
  }
  else {
    if (*(int *)(iVar22 + 0xc) == 0) {
      *(undefined4 *)(iVar22 + 0xc) = 0;
      *(undefined4 *)(iVar22 + 0x14) = 0;
    }
    else {
      (*(code *)PTR_shutdown_006aaa6c)(*(undefined4 *)(iVar22 + 0x1c),2);
      (*(code *)PTR_close_006aaa5c)(*(undefined4 *)(iVar22 + 0x1c));
      *(undefined4 *)(iVar22 + 0xc) = 0;
      *(undefined4 *)(iVar22 + 0x14) = 0;
    }
    iVar22 = *(int *)(iVar22 + 0x20);
  }
  if (iVar22 == 0) {
    return (undefined4 *******)0x1;
  }
  (*(code *)PTR_CRYPTO_free_006a7f88)();
  return (undefined4 *******)0x1;
}

