
void idea_cbc_encrypt(uchar *in,uchar *out,long length,IDEA_KEY_SCHEDULE *ks,uchar *iv,int enc)

{
  uint *puVar1;
  uchar *puVar2;
  byte *pbVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  undefined *puVar7;
  uint uVar8;
  uchar uVar9;
  uint uVar10;
  uchar uVar11;
  int iVar12;
  uchar uVar13;
  uchar uVar14;
  uchar uVar15;
  uchar uVar16;
  uchar uVar17;
  uchar *puVar18;
  uchar *puVar19;
  uint uVar20;
  uint unaff_s7;
  IDEA_KEY_SCHEDULE *ks_00;
  uint uVar21;
  uint uVar22;
  uint local_34;
  uint local_30;
  int local_2c;
  
  puVar7 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar8 = length - 8;
  if (enc != 0) {
    uVar20 = *(uint *)(iv + 4);
    uVar21 = *(uint *)iv;
    ks_00 = ks;
    if (-1 < (int)uVar8) {
      local_30 = *(uint *)(iv + 4);
      local_34 = *(uint *)iv;
      puVar18 = in;
      puVar19 = out;
      uVar20 = uVar8;
      do {
        uVar21 = (uint)puVar18 & 3;
        piVar5 = (int *)(puVar18 + -uVar21);
        puVar1 = (uint *)(puVar18 + 4);
        puVar19 = puVar19 + 8;
        uVar20 = uVar20 - 8;
        puVar2 = puVar18 + 3;
        uVar10 = (uint)puVar2 & 3;
        puVar18 = puVar18 + 8;
        local_34 = ((*piVar5 << uVar21 * 8 | (uint)ks & 0xffffffffU >> (4 - uVar21) * 8) &
                    -1 << (uVar10 + 1) * 8 | *(uint *)(puVar2 + -uVar10) >> (3 - uVar10) * 8) ^
                   local_34;
        local_30 = *puVar1 ^ local_30;
        idea_encrypt(&local_34,ks_00);
        puVar19[-5] = (uchar)local_34;
        ks = (IDEA_KEY_SCHEDULE *)(local_34 >> 8);
        puVar19[-1] = (uchar)local_30;
        puVar19[-8] = (uchar)(local_34 >> 0x18);
        puVar19[-7] = (uchar)(local_34 >> 0x10);
        puVar19[-6] = (uchar)(local_34 >> 8);
        puVar19[-4] = (uchar)(local_30 >> 0x18);
        puVar19[-3] = (uchar)(local_30 >> 0x10);
        puVar19[-2] = (uchar)(local_30 >> 8);
      } while (-1 < (int)uVar20);
      iVar12 = ((uVar8 >> 3) + 1) * 8;
      uVar8 = (length + -0x10) - (uVar8 & 0xfffffff8);
      in = in + iVar12;
      out = out + iVar12;
      uVar20 = local_30;
      uVar21 = local_34;
    }
    if (uVar8 == 0xfffffff8) {
      uVar17 = (uchar)(uVar21 >> 0x18);
      uVar16 = (uchar)(uVar21 >> 0x10);
      uVar15 = (uchar)(uVar21 >> 8);
      uVar14 = (uchar)(uVar20 >> 0x18);
      uVar13 = (uchar)(uVar20 >> 0x10);
      uVar11 = (uchar)uVar21;
      uVar9 = (uchar)uVar20;
    }
    else {
      puVar18 = in + uVar8 + 8;
      switch(uVar8) {
      default:
        local_30 = 0;
        local_34 = 0;
        goto LAB_004e6374;
      case 0xfffffff9:
        local_30 = 0;
        local_34 = 0;
        goto LAB_004e6368;
      case 0xfffffffa:
        local_30 = 0;
        local_34 = 0;
        goto LAB_004e6358;
      case 0xfffffffb:
        local_30 = 0;
        local_34 = 0;
        goto LAB_004e6348;
      case 0xfffffffc:
        local_30 = 0;
        goto LAB_004e6340;
      case 0xfffffffd:
        local_30 = 0;
        goto LAB_004e6330;
      case 0xfffffffe:
        local_30 = 0;
        break;
      case 0xffffffff:
        pbVar3 = puVar18 + -1;
        puVar18 = puVar18 + -1;
        local_30 = (uint)*pbVar3 << 8;
      }
      pbVar3 = puVar18 + -1;
      puVar18 = puVar18 + -1;
      local_30 = (uint)*pbVar3 << 0x10 | local_30;
LAB_004e6330:
      pbVar3 = puVar18 + -1;
      puVar18 = puVar18 + -1;
      local_30 = (uint)*pbVar3 << 0x18 | local_30;
LAB_004e6340:
      local_34 = (uint)puVar18[-1];
      puVar18 = puVar18 + -1;
LAB_004e6348:
      pbVar3 = puVar18 + -1;
      puVar18 = puVar18 + -1;
      local_34 = (uint)*pbVar3 << 8 | local_34;
LAB_004e6358:
      pbVar3 = puVar18 + -1;
      puVar18 = puVar18 + -1;
      local_34 = (uint)*pbVar3 << 0x10 | local_34;
LAB_004e6368:
      local_34 = (uint)puVar18[-1] << 0x18 | local_34;
LAB_004e6374:
      local_34 = local_34 ^ uVar21;
      local_30 = local_30 ^ uVar20;
      idea_encrypt(&local_34,ks_00);
      uVar16 = (uchar)(local_34 >> 0x10);
      uVar15 = (uchar)(local_34 >> 8);
      uVar17 = (uchar)(local_34 >> 0x18);
      *out = uVar17;
      uVar13 = (uchar)(local_30 >> 0x10);
      out[1] = uVar16;
      out[2] = uVar15;
      uVar11 = (uchar)local_34;
      uVar14 = (uchar)(local_30 >> 0x18);
      out[4] = uVar14;
      uVar9 = (uchar)local_30;
      out[5] = uVar13;
      out[3] = uVar11;
      out[6] = (uchar)(local_30 >> 8);
      out[7] = uVar9;
      uVar20 = local_30;
    }
    *iv = uVar17;
    iv[1] = uVar16;
    iv[2] = uVar15;
    iv[3] = uVar11;
    iv[4] = uVar14;
    iv[5] = uVar13;
    iv[6] = (uchar)(uVar20 >> 8);
    iv[7] = uVar9;
    goto LAB_004e6294;
  }
  uVar21 = length - 8;
  uVar8 = *(uint *)iv;
  uVar20 = *(uint *)(iv + 4);
  if (-1 < (int)uVar21) {
    puVar18 = in;
    puVar19 = out;
    uVar10 = uVar20;
    uVar22 = uVar21;
    do {
      uVar4 = (uint)puVar18 & 3;
      uVar20 = *(uint *)(puVar18 + 4);
      puVar19 = puVar19 + 8;
      uVar22 = uVar22 - 8;
      uVar6 = (uint)(puVar18 + 3) & 3;
      unaff_s7 = (*(int *)(puVar18 + -uVar4) << uVar4 * 8 |
                 unaff_s7 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar6 + 1) * 8 |
                 *(uint *)(puVar18 + 3 + -uVar6) >> (3 - uVar6) * 8;
      puVar18 = puVar18 + 8;
      local_34 = unaff_s7;
      local_30 = uVar20;
      idea_encrypt(&local_34,ks);
      uVar8 = uVar8 ^ local_34;
      puVar19[-5] = (uchar)uVar8;
      uVar10 = uVar10 ^ local_30;
      puVar19[-8] = (uchar)(uVar8 >> 0x18);
      puVar19[-7] = (uchar)(uVar8 >> 0x10);
      puVar19[-1] = (uchar)uVar10;
      puVar19[-6] = (uchar)(uVar8 >> 8);
      puVar19[-4] = (uchar)(uVar10 >> 0x18);
      puVar19[-3] = (uchar)(uVar10 >> 0x10);
      puVar19[-2] = (uchar)(uVar10 >> 8);
      uVar8 = unaff_s7;
      uVar10 = uVar20;
    } while (-1 < (int)uVar22);
    iVar12 = ((uVar21 >> 3) + 1) * 8;
    uVar21 = (length + -0x10) - (uVar21 & 0xfffffff8);
    in = in + iVar12;
    out = out + iVar12;
  }
  uVar10 = *(uint *)in;
  uVar22 = *(uint *)((int)in + 4);
  local_34 = uVar10;
  local_30 = uVar22;
  idea_encrypt(&local_34,ks);
  puVar19 = out + uVar21 + 8;
  uVar8 = uVar8 ^ local_34;
  uVar20 = uVar20 ^ local_30;
  puVar18 = puVar19;
  switch(uVar21) {
  default:
    goto switchD_004e6200_caseD_7;
  case 0xfffffff9:
    goto LAB_004e624c;
  case 0xfffffffa:
    goto switchD_004e6200_caseD_fffffffa;
  case 0xfffffffb:
    goto LAB_004e6234;
  case 0xfffffffc:
    goto switchD_004e6200_caseD_fffffffc;
  case 0xfffffffd:
    break;
  case 0xffffffff:
    puVar18 = puVar19 + -1;
    *puVar18 = (uchar)(uVar20 >> 8);
  case 0xfffffffe:
    puVar19 = puVar18 + -1;
    puVar18[-1] = (uchar)(uVar20 >> 0x10);
  }
  puVar18 = puVar19 + -1;
  puVar19[-1] = (uchar)(uVar20 >> 0x18);
switchD_004e6200_caseD_fffffffc:
  puVar19 = puVar18 + -1;
  puVar18[-1] = (uchar)uVar8;
LAB_004e6234:
  puVar18 = puVar19 + -1;
  puVar19[-1] = (uchar)(uVar8 >> 8);
switchD_004e6200_caseD_fffffffa:
  puVar19 = puVar18 + -1;
  puVar18[-1] = (uchar)(uVar8 >> 0x10);
LAB_004e624c:
  puVar19[-1] = (uchar)(uVar8 >> 0x18);
switchD_004e6200_caseD_7:
  iv[3] = (uchar)uVar10;
  iv[7] = (uchar)uVar22;
  *iv = (uchar)(uVar10 >> 0x18);
  iv[1] = (uchar)(uVar10 >> 0x10);
  iv[4] = (uchar)(uVar22 >> 0x18);
  iv[2] = (uchar)(uVar10 >> 8);
  iv[5] = (uchar)(uVar22 >> 0x10);
  iv[6] = (uchar)(uVar22 >> 8);
LAB_004e6294:
  if (local_2c != *(int *)puVar7) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    return;
  }
  return;
}

