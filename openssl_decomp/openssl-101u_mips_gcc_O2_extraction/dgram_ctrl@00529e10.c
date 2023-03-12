
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Could not reconcile some variable overlaps */

undefined4 ******* dgram_ctrl(uint param_1,int param_2,undefined4 *******param_3,short **param_4)

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
  undefined *puVar21;
  int *piVar22;
  undefined4 uVar23;
  undefined4 *******pppppppuVar24;
  int iVar25;
  undefined4 *******pppppppuVar26;
  short *psVar27;
  BIO *b;
  undefined4 uVar28;
  short **ppsVar29;
  undefined4 uVar30;
  uint in_t0;
  uint in_t1;
  uint in_t2;
  short **ppsVar31;
  short *psVar32;
  uint local_44;
  undefined4 local_40;
  undefined4 *******local_3c;
  short *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  BIO *local_1c;
  
  puVar21 = PTR___stack_chk_guard_006a9ae8;
  puVar20 = PTR_memset_006a99f4;
  ppsVar31 = *(short ***)(param_1 + 0x20);
  local_44 = 0;
  local_1c = *(BIO **)PTR___stack_chk_guard_006a9ae8;
  ppsVar29 = (short **)(&switchD_00529e6c::switchdataD_00667940 + param_2 + -8);
  switch(param_2 + -8) {
  case 0:
    pppppppuVar24 = *(undefined4 ********)(param_1 + 0x10);
    break;
  case 1:
    *(undefined4 ********)(param_1 + 0x10) = param_3;
    pppppppuVar24 = (undefined4 *******)0x1;
    break;
  default:
    goto switchD_00529e6c_caseD_a;
  case 3:
  case 4:
    goto switchD_00529e6c_caseD_b;
  case 0x17:
  case 0x24:
    sVar1 = *(short *)param_4;
    goto joined_r0x00529f74;
  case 0x18:
    param_1 = 1;
    if (param_4 == (short **)0x0) {
      param_3 = (undefined4 *******)0x1c;
      ppsVar29 = (short **)0x0;
      ppsVar31[7] = (short *)0x0;
      (*(code *)puVar20)(ppsVar31);
      pppppppuVar24 = (undefined4 *******)0x1;
      break;
    }
    sVar1 = *(short *)param_4;
    ppsVar31[7] = (short *)0x1;
joined_r0x00529f74:
    if ((sVar1 == 2) || (sVar1 != 10)) {
      param_3 = (undefined4 *******)*param_4;
      ppsVar29 = (short **)param_4[1];
      psVar27 = param_4[2];
      psVar32 = param_4[3];
      *ppsVar31 = (short *)param_3;
      ppsVar31[1] = (short *)ppsVar29;
      ppsVar31[2] = psVar27;
      ppsVar31[3] = psVar32;
      pppppppuVar24 = (undefined4 *******)0x1;
    }
    else {
      uVar18 = (uint)param_4 & 3;
      uVar2 = (uint)(param_4 + 1) & 3;
      iVar25 = *(int *)((int)(param_4 + 1) - uVar2);
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
      ppsVar29 = (short **)
                 ((*(int *)((int)(param_4 + 4) - uVar5) << uVar5 * 8 |
                  (uint)ppsVar29 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar4 + 1) * 8 |
                 *(uint *)(((int)param_4 + 0x13U) - uVar4) >> (3 - uVar4) * 8);
      uVar4 = (int)param_4 + 0x17U & 3;
      uVar14 = *(uint *)(((int)param_4 + 0x17U) - uVar4);
      uVar5 = (int)param_4 + 0x1bU & 3;
      uVar17 = *(uint *)(((int)param_4 + 0x1bU) - uVar5);
      *ppsVar31 = (short *)((*(int *)((int)param_4 - uVar18) << uVar18 * 8 |
                            in_t2 & 0xffffffffU >> (4 - uVar18) * 8) & -1 << (uVar11 + 1) * 8 |
                           *(uint *)(((int)param_4 + 3U) - uVar11) >> (3 - uVar11) * 8);
      ppsVar31[1] = (short *)((iVar25 << uVar2 * 8 | in_t1 & 0xffffffffU >> (4 - uVar2) * 8) &
                              -1 << (uVar12 + 1) * 8 | uVar15 >> (3 - uVar12) * 8);
      ppsVar31[2] = (short *)((iVar8 << uVar3 * 8 | in_t0 & 0xffffffffU >> (4 - uVar3) * 8) &
                              -1 << (uVar13 + 1) * 8 | uVar16 >> (3 - uVar13) * 8);
      ppsVar31[3] = (short *)param_3;
      ppsVar31[4] = (short *)ppsVar29;
      ppsVar31[5] = (short *)((iVar9 << uVar6 * 8 | param_1 & 0xffffffffU >> (4 - uVar6) * 8) &
                              -1 << (uVar4 + 1) * 8 | uVar14 >> (3 - uVar4) * 8);
      ppsVar31[6] = (short *)((iVar10 << uVar7 * 8 | 0xffffffffU >> (4 - uVar7) * 8 & 10) &
                              -1 << (uVar5 + 1) * 8 | uVar17 >> (3 - uVar5) * 8);
      pppppppuVar24 = (undefined4 *******)0x1;
    }
    break;
  case 0x19:
    uVar23 = *(undefined4 *)(param_1 + 0x1c);
    param_3 = (undefined4 *******)0x1006;
    goto LAB_0052a164;
  case 0x1a:
    uVar23 = *(undefined4 *)(param_1 + 0x1c);
    param_3 = (undefined4 *******)0x1006;
    goto LAB_0052a000;
  case 0x1b:
    uVar23 = *(undefined4 *)(param_1 + 0x1c);
    param_3 = (undefined4 *******)0x1005;
LAB_0052a164:
    ppsVar29 = (short **)0xffff;
    iVar25 = (*(code *)PTR_setsockopt_006a9b2c)(uVar23);
    if (iVar25 < 0) {
      (*(code *)PTR_perror_006a9a80)("setsockopt");
      pppppppuVar24 = (undefined4 *******)0xffffffff;
    }
    else {
switchD_00529e6c_caseD_b:
      pppppppuVar24 = (undefined4 *******)0x1;
    }
    break;
  case 0x1c:
    uVar23 = *(undefined4 *)(param_1 + 0x1c);
    param_3 = (undefined4 *******)0x1005;
LAB_0052a000:
    ppsVar29 = (short **)0xffff;
    local_3c = (undefined4 *******)&DAT_00000008;
    iVar25 = (*(code *)PTR_getsockopt_006a9a90)(uVar23);
    pppppppuVar24 = local_3c;
    if (iVar25 < 0) {
      (*(code *)PTR_perror_006a9a80)("getsockopt");
      pppppppuVar24 = (undefined4 *******)0xffffffff;
    }
    break;
  case 0x1d:
  case 0x1e:
    if (ppsVar31[8] == (short *)&DAT_0000000b) {
LAB_00529f58:
      ppsVar31[8] = (short *)0x0;
      goto switchD_00529e6c_caseD_b;
    }
    goto switchD_00529e6c_caseD_a;
  case 0x1f:
    ppsVar29 = &local_38;
    param_3 = &local_3c;
    local_38 = (short *)0x0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_3c = (undefined4 *******)0x1c;
    iVar25 = (*(code *)PTR_getsockname_006a9994)(*(undefined4 *)(param_1 + 0x1c));
    if (-1 < iVar25) {
      uVar18 = (uint)local_38 >> 0x10;
      if (uVar18 == 2) {
        uVar23 = *(undefined4 *)(param_1 + 0x1c);
        uVar30 = 10;
        uVar28 = 0;
        local_44 = uVar18;
      }
      else {
        if (uVar18 != 10) goto LAB_0052a0bc;
        uVar23 = *(undefined4 *)(param_1 + 0x1c);
        uVar30 = 0x17;
        uVar28 = 0x29;
        local_44 = 2;
      }
      iVar25 = (*(code *)PTR_setsockopt_006a9b2c)(uVar23,uVar28,uVar30,&local_44,4);
      if (iVar25 < 0) {
        (*(code *)PTR_perror_006a9a80)("setsockopt");
      }
      goto LAB_0052a0bc;
    }
    goto switchD_00529e6c_caseD_a;
  case 0x20:
LAB_0052a0bc:
    param_3 = &local_3c;
    ppsVar29 = &local_38;
    local_38 = (short *)0x0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_3c = (undefined4 *******)0x1c;
    iVar25 = (*(code *)PTR_getsockname_006a9994)(*(undefined4 *)(param_1 + 0x1c));
    if (-1 < iVar25) {
      local_40 = 4;
      if (local_38._0_2_ == 2) {
        param_3 = (undefined4 *******)&DAT_0000000e;
        ppsVar29 = (short **)0x0;
        iVar25 = (*(code *)PTR_getsockopt_006a9a90)
                           (*(undefined4 *)(param_1 + 0x1c),0,0xe,&local_44,&local_40);
        if ((-1 < iVar25) &&
           (pppppppuVar24 = (undefined4 *******)(local_44 - 0x1c), -1 < (int)local_44)) {
          ppsVar31[9] = (short *)pppppppuVar24;
          break;
        }
      }
      else {
        pppppppuVar24 = (undefined4 *******)0x0;
        if (local_38._0_2_ != 10) break;
        param_3 = (undefined4 *******)&DAT_00000018;
        ppsVar29 = (short **)0x29;
        iVar25 = (*(code *)PTR_getsockopt_006a9a90)
                           (*(undefined4 *)(param_1 + 0x1c),0x29,0x18,&local_44,&local_40);
        if ((-1 < iVar25) &&
           (pppppppuVar24 = (undefined4 *******)(local_44 - 0x30), -1 < (int)local_44)) {
          ppsVar31[9] = (short *)pppppppuVar24;
          break;
        }
      }
    }
    goto switchD_00529e6c_caseD_a;
  case 0x21:
    pppppppuVar24 = (undefined4 *******)ppsVar31[9];
    break;
  case 0x22:
    ppsVar31[9] = (short *)param_3;
    pppppppuVar24 = param_3;
    break;
  case 0x23:
    if (ppsVar31[8] == (short *)&DAT_00000061) goto LAB_00529f58;
switchD_00529e6c_caseD_a:
    pppppppuVar24 = (undefined4 *******)0x0;
    break;
  case 0x25:
    ppsVar29 = (short **)*param_4;
    psVar32 = param_4[1];
    uVar18 = (uint)(ppsVar31 + 10) & 3;
    puVar19 = (uint *)((int)(ppsVar31 + 10) - uVar18);
    *puVar19 = *puVar19 & -1 << (4 - uVar18) * 8 | (uint)ppsVar29 >> uVar18 * 8;
    uVar18 = (uint)(undefined *)((int)ppsVar31 + 0x2b) & 3;
    puVar19 = (uint *)((undefined *)((int)ppsVar31 + 0x2b) + -uVar18);
    *puVar19 = *puVar19 & 0xffffffffU >> (uVar18 + 1) * 8 | (int)ppsVar29 << (3 - uVar18) * 8;
    ppsVar31[0xb] = psVar32;
    pppppppuVar24 = (undefined4 *******)0x1;
    break;
  case 0x26:
    pppppppuVar26 = (undefined4 *******)&SUB_00000010;
    if (*(short *)ppsVar31 == 10) {
      pppppppuVar26 = (undefined4 *******)0x1c;
    }
    pppppppuVar24 = pppppppuVar26;
    if ((param_3 != (undefined4 *******)0x0) &&
       (pppppppuVar24 = param_3, (int)pppppppuVar26 <= (int)param_3)) {
      pppppppuVar24 = pppppppuVar26;
    }
    param_3 = pppppppuVar24;
    (*(code *)PTR_memcpy_006a9aec)(param_4);
    ppsVar29 = ppsVar31;
    break;
  case 0x27:
    pppppppuVar24 = (undefined4 *******)0x224;
    if (*(short *)ppsVar31 == 10) {
      if ((ppsVar31[2] == (short *)0x0) &&
         (param_3 = (undefined4 *******)&DAT_00000030, ppsVar31[3] == (short *)0x0)) {
        ppsVar29 = (short **)0xffff;
        if (ppsVar31[4] == (short *)0xffff) {
          pppppppuVar24 = (undefined4 *******)0x224;
        }
        else {
          pppppppuVar24 = (undefined4 *******)0x4d0;
        }
      }
      else {
        pppppppuVar24 = (undefined4 *******)0x4d0;
      }
    }
    break;
  case 0x29:
    pppppppuVar24 = (undefined4 *******)0x1c;
    if ((*(short *)ppsVar31 == 10) &&
       (pppppppuVar24 = (undefined4 *******)&DAT_00000030, ppsVar31[2] == (short *)0x0)) {
      if (ppsVar31[3] == (short *)0x0) {
        pppppppuVar24 = (undefined4 *******)0x1c;
        if (ppsVar31[4] != (short *)0xffff) {
          pppppppuVar24 = (undefined4 *******)&DAT_00000030;
        }
      }
      else {
        pppppppuVar24 = (undefined4 *******)&DAT_00000030;
      }
    }
    break;
  case 0x60:
    if (*(int *)(param_1 + 0x10) != 0) {
      if (*(int *)(param_1 + 0xc) == 0) {
        *(undefined4 *)(param_1 + 0xc) = 0;
        *(undefined4 *)(param_1 + 0x14) = 0;
      }
      else {
        ppsVar29 = (short **)&SUB_00000002;
        (*(code *)PTR_shutdown_006a995c)(*(undefined4 *)(param_1 + 0x1c));
        (*(code *)PTR_close_006a994c)(*(undefined4 *)(param_1 + 0x1c));
        *(undefined4 *)(param_1 + 0xc) = 0;
        *(undefined4 *)(param_1 + 0x14) = 0;
      }
    }
    psVar32 = *param_4;
    *(undefined4 ********)(param_1 + 0x10) = param_3;
    *(undefined4 *)(param_1 + 0xc) = 1;
    *(short **)(param_1 + 0x1c) = psVar32;
    pppppppuVar24 = (undefined4 *******)0x1;
    break;
  case 0x61:
    if (*(int *)(param_1 + 0xc) == 0) {
      pppppppuVar24 = (undefined4 *******)0xffffffff;
    }
    else {
      if (param_4 != (short **)0x0) {
        *param_4 = *(short **)(param_1 + 0x1c);
      }
      pppppppuVar24 = *(undefined4 ********)(param_1 + 0x1c);
    }
  }
  if (local_1c == *(BIO **)puVar21) {
    return pppppppuVar24;
  }
  b = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  psVar32 = (short *)b->ptr;
  piVar22 = (int *)(*(code *)PTR___errno_location_006a99e8)();
  *piVar22 = 0;
  if (*(int *)(psVar32 + 0xe) == 0) {
    uVar23 = 0x10;
    if (*psVar32 != 2) {
      uVar23 = 0x1c;
    }
    pppppppuVar24 =
         (undefined4 *******)
         (*(code *)PTR_sendto_006a99c0)(b->num,ppsVar29,param_3,0,psVar32,uVar23);
  }
  else {
    pppppppuVar24 = (undefined4 *******)(*(code *)PTR_write_006a9a1c)(b->num,ppsVar29,param_3);
  }
  BIO_clear_flags(b,0xf);
  if ((int)pppppppuVar24 < 1) {
    if (1 < (int)pppppppuVar24 + 1U) {
      return pppppppuVar24;
    }
    iVar25 = *piVar22;
    if (iVar25 != 0x47) {
      if (iVar25 < 0x48) {
        if ((iVar25 != 4) && (iVar25 != 0xb)) {
          return pppppppuVar24;
        }
      }
      else if (1 < iVar25 - 0x95U) {
        return pppppppuVar24;
      }
    }
    BIO_set_flags(b,10);
    *(int *)(psVar32 + 0x10) = *piVar22;
    return pppppppuVar24;
  }
  return pppppppuVar24;
}

