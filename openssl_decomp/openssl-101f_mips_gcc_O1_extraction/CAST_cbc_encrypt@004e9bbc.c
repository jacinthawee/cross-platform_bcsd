
void CAST_cbc_encrypt(uchar *in,uchar *out,long length,CAST_KEY *ks,uchar *iv,int enc)

{
  uint *puVar1;
  uchar *puVar2;
  byte *pbVar3;
  int *piVar4;
  uint uVar5;
  undefined *puVar6;
  uint uVar7;
  uint uVar8;
  uchar uVar9;
  uint uVar10;
  uchar uVar11;
  int iVar12;
  CAMELLIA_KEY *key;
  uchar uVar13;
  uint in_t0;
  uchar uVar14;
  uchar uVar15;
  uchar *puVar16;
  uchar *puVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint *local_48;
  uchar *local_44;
  uint local_34;
  uint local_30;
  int local_2c;
  
  puVar6 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar7 = length - 8;
  local_48 = (uint *)in;
  local_44 = out;
  if (enc != 0) {
    uVar19 = *(uint *)(iv + 4);
    uVar20 = *(uint *)iv;
    if (-1 < (int)uVar7) {
      local_30 = *(uint *)(iv + 4);
      local_34 = *(uint *)iv;
      puVar16 = in;
      puVar17 = out;
      uVar19 = uVar7;
      do {
        uVar20 = (uint)puVar16 & 3;
        piVar4 = (int *)(puVar16 + -uVar20);
        puVar1 = (uint *)(puVar16 + 4);
        uVar19 = uVar19 - 8;
        puVar2 = puVar16 + 3;
        uVar8 = (uint)puVar2 & 3;
        puVar16 = puVar16 + 8;
        local_34 = ((*piVar4 << uVar20 * 8 | in_t0 & 0xffffffffU >> (4 - uVar20) * 8) &
                    -1 << (uVar8 + 1) * 8 | *(uint *)(puVar2 + -uVar8) >> (3 - uVar8) * 8) ^
                   local_34;
        local_30 = *puVar1 ^ local_30;
        CAST_encrypt(&local_34,ks);
        puVar17[3] = (uchar)local_34;
        in_t0 = local_34 >> 8;
        puVar17[7] = (uchar)local_30;
        *puVar17 = (uchar)(local_34 >> 0x18);
        puVar17[1] = (uchar)(local_34 >> 0x10);
        puVar17[2] = (uchar)(local_34 >> 8);
        puVar17[4] = (uchar)(local_30 >> 0x18);
        puVar17[5] = (uchar)(local_30 >> 0x10);
        puVar17[6] = (uchar)(local_30 >> 8);
        puVar17 = puVar17 + 8;
      } while (-1 < (int)uVar19);
      iVar12 = ((uVar7 >> 3) + 1) * 8;
      uVar7 = (length + -0x10) - (uVar7 & 0xfffffff8);
      local_48 = (uint *)(in + iVar12);
      local_44 = out + iVar12;
      uVar19 = local_30;
      uVar20 = local_34;
    }
    if (uVar7 == 0xfffffff8) {
      uVar15 = (uchar)(uVar20 >> 0x18);
      uVar14 = (uchar)(uVar20 >> 0x10);
      uVar13 = (uchar)(uVar20 >> 8);
      uVar11 = (uchar)uVar20;
      uVar9 = (uchar)uVar19;
    }
    else {
      puVar16 = (uchar *)((int)local_48 + uVar7 + 8);
      switch(uVar7) {
      default:
        local_30 = 0;
        local_34 = 0;
        goto LAB_004ea024;
      case 0xfffffff9:
        local_30 = 0;
        local_34 = 0;
        goto LAB_004ea018;
      case 0xfffffffa:
        local_30 = 0;
        local_34 = 0;
        goto LAB_004ea008;
      case 0xfffffffb:
        local_30 = 0;
        local_34 = 0;
        goto LAB_004e9ff8;
      case 0xfffffffc:
        local_30 = 0;
        goto LAB_004e9ff0;
      case 0xfffffffd:
        local_30 = 0;
        goto LAB_004e9fe0;
      case 0xfffffffe:
        local_30 = 0;
        break;
      case 0xffffffff:
        pbVar3 = puVar16 + -1;
        puVar16 = puVar16 + -1;
        local_30 = (uint)*pbVar3 << 8;
      }
      pbVar3 = puVar16 + -1;
      puVar16 = puVar16 + -1;
      local_30 = (uint)*pbVar3 << 0x10 | local_30;
LAB_004e9fe0:
      pbVar3 = puVar16 + -1;
      puVar16 = puVar16 + -1;
      local_30 = (uint)*pbVar3 << 0x18 | local_30;
LAB_004e9ff0:
      local_34 = (uint)puVar16[-1];
      puVar16 = puVar16 + -1;
LAB_004e9ff8:
      pbVar3 = puVar16 + -1;
      puVar16 = puVar16 + -1;
      local_34 = (uint)*pbVar3 << 8 | local_34;
LAB_004ea008:
      pbVar3 = puVar16 + -1;
      puVar16 = puVar16 + -1;
      local_34 = (uint)*pbVar3 << 0x10 | local_34;
LAB_004ea018:
      local_34 = (uint)puVar16[-1] << 0x18 | local_34;
LAB_004ea024:
      local_34 = local_34 ^ uVar20;
      local_30 = local_30 ^ uVar19;
      CAST_encrypt(&local_34,ks);
      uVar14 = (uchar)(local_34 >> 0x10);
      uVar13 = (uchar)(local_34 >> 8);
      uVar15 = (uchar)(local_34 >> 0x18);
      *local_44 = uVar15;
      local_44[1] = uVar14;
      local_44[2] = uVar13;
      uVar11 = (uchar)local_34;
      local_44[4] = (uchar)(local_30 >> 0x18);
      uVar9 = (uchar)local_30;
      local_44[5] = (uchar)(local_30 >> 0x10);
      local_44[3] = uVar11;
      local_44[6] = (uchar)(local_30 >> 8);
      local_44[7] = uVar9;
      uVar19 = local_30;
    }
    ks = (CAST_KEY *)((uVar19 << 8) >> 0x18);
    puVar16 = (uchar *)((uVar19 << 0x10) >> 0x18);
    key = (CAMELLIA_KEY *)(uVar19 >> 0x18);
    *iv = uVar15;
    iv[1] = uVar14;
    iv[2] = uVar13;
    iv[3] = uVar11;
    iv[4] = (uchar)(uVar19 >> 0x18);
    iv[5] = (uchar)(uVar19 >> 0x10);
    iv[6] = (uchar)(uVar19 >> 8);
    iv[7] = uVar9;
    goto LAB_004e9f40;
  }
  uVar19 = *(uint *)(iv + 4);
  uVar20 = length - 8;
  uVar7 = *(uint *)iv;
  if (-1 < (int)uVar20) {
    uVar8 = uVar7;
    uVar18 = length;
    puVar16 = in;
    puVar17 = out;
    uVar10 = uVar19;
    uVar21 = uVar20;
    do {
      uVar7 = (uint)puVar16 & 3;
      uVar19 = (uint)(puVar16 + 4) & 3;
      uVar21 = uVar21 - 8;
      uVar5 = (uint)(puVar16 + 3) & 3;
      uVar7 = (*(int *)(puVar16 + -uVar7) << uVar7 * 8 | in_t0 & 0xffffffffU >> (4 - uVar7) * 8) &
              -1 << (uVar5 + 1) * 8 | *(uint *)(puVar16 + 3 + -uVar5) >> (3 - uVar5) * 8;
      uVar5 = (uint)(puVar16 + 7) & 3;
      uVar19 = (*(int *)(puVar16 + 4 + -uVar19) << uVar19 * 8 |
               uVar18 & 0xffffffffU >> (4 - uVar19) * 8) & -1 << (uVar5 + 1) * 8 |
               *(uint *)(puVar16 + 7 + -uVar5) >> (3 - uVar5) * 8;
      puVar16 = puVar16 + 8;
      uVar18 = uVar19;
      in_t0 = uVar7;
      local_34 = uVar7;
      local_30 = uVar19;
      CAST_decrypt(&local_34,ks);
      uVar8 = uVar8 ^ local_34;
      puVar17[3] = (uchar)uVar8;
      uVar10 = uVar10 ^ local_30;
      *puVar17 = (uchar)(uVar8 >> 0x18);
      puVar17[1] = (uchar)(uVar8 >> 0x10);
      puVar17[7] = (uchar)uVar10;
      puVar17[2] = (uchar)(uVar8 >> 8);
      puVar17[4] = (uchar)(uVar10 >> 0x18);
      puVar17[5] = (uchar)(uVar10 >> 0x10);
      puVar17[6] = (uchar)(uVar10 >> 8);
      uVar8 = uVar7;
      puVar17 = puVar17 + 8;
      uVar10 = uVar19;
    } while (-1 < (int)uVar21);
    iVar12 = ((uVar20 >> 3) + 1) * 8;
    uVar20 = (length + -0x10) - (uVar20 & 0xfffffff8);
    local_48 = (uint *)(in + iVar12);
    local_44 = out + iVar12;
  }
  uVar8 = *local_48;
  uVar18 = local_48[1];
  local_34 = uVar8;
  local_30 = uVar18;
  CAST_decrypt(&local_34,ks);
  local_44 = local_44 + uVar20 + 8;
  uVar7 = uVar7 ^ local_34;
  uVar19 = uVar19 ^ local_30;
  puVar16 = local_44;
  switch(uVar20) {
  default:
    goto switchD_004e9eac_caseD_7;
  case 0xfffffff9:
    goto LAB_004e9ef8;
  case 0xfffffffa:
    goto switchD_004e9eac_caseD_fffffffa;
  case 0xfffffffb:
    goto LAB_004e9ee0;
  case 0xfffffffc:
    goto switchD_004e9eac_caseD_fffffffc;
  case 0xfffffffd:
    break;
  case 0xffffffff:
    puVar16 = local_44 + -1;
    *puVar16 = (uchar)(uVar19 >> 8);
  case 0xfffffffe:
    local_44 = puVar16 + -1;
    puVar16[-1] = (uchar)(uVar19 >> 0x10);
  }
  puVar16 = local_44 + -1;
  local_44[-1] = (uchar)(uVar19 >> 0x18);
switchD_004e9eac_caseD_fffffffc:
  local_44 = puVar16 + -1;
  puVar16[-1] = (uchar)uVar7;
LAB_004e9ee0:
  puVar16 = local_44 + -1;
  local_44[-1] = (uchar)(uVar7 >> 8);
switchD_004e9eac_caseD_fffffffa:
  local_44 = puVar16 + -1;
  puVar16[-1] = (uchar)(uVar7 >> 0x10);
LAB_004e9ef8:
  local_44[-1] = (uchar)(uVar7 >> 0x18);
switchD_004e9eac_caseD_7:
  iv[3] = (uchar)uVar8;
  puVar16 = (uchar *)(uVar8 >> 0x10);
  iv[7] = (uchar)uVar18;
  *iv = (uchar)(uVar8 >> 0x18);
  key = (CAMELLIA_KEY *)(uVar18 >> 8);
  iv[1] = (uchar)(uVar8 >> 0x10);
  iv[2] = (uchar)(uVar8 >> 8);
  iv[4] = (uchar)(uVar18 >> 0x18);
  iv[6] = (uchar)(uVar18 >> 8);
  iv[5] = (uchar)(uVar18 >> 0x10);
LAB_004e9f40:
  if (local_2c != *(int *)puVar6) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    private_Camellia_set_key(puVar16,(int)ks,key);
    return;
  }
  return;
}

