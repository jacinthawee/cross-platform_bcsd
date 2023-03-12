
int i2d_SSL_SESSION(SSL_SESSION *in,uchar **pp)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  SSL_SESSION *pSVar10;
  int extraout_v1;
  SSL_SESSION **ppSVar11;
  uint **ppuVar12;
  undefined4 **in_a2;
  uint **unaff_s0;
  int iVar13;
  uint uVar14;
  SSL_SESSION *pSVar15;
  uint **ppuVar16;
  uchar **unaff_s2;
  undefined4 *unaff_s3;
  undefined4 *unaff_s4;
  undefined4 **unaff_s5;
  SSL_SESSION *unaff_s6;
  byte *pbVar17;
  uint **unaff_s7;
  code *pcVar18;
  undefined4 **unaff_s8;
  undefined4 *puStack_264;
  uint *puStack_260;
  undefined auStack_25c [4];
  undefined auStack_258 [4];
  int iStack_254;
  undefined4 auStack_250 [2];
  void *pvStack_248;
  uint auStack_240 [2];
  byte *pbStack_238;
  uint *apuStack_230 [2];
  undefined4 uStack_228;
  int iStack_218;
  byte *pbStack_214;
  uint *puStack_210;
  uint **ppuStack_20c;
  undefined4 uStack_208;
  uint *puStack_204;
  uint **ppuStack_200;
  undefined *puStack_1fc;
  uchar **ppuStack_1f8;
  undefined4 *puStack_1f4;
  undefined4 *puStack_1f0;
  undefined4 **ppuStack_1ec;
  SSL_SESSION *pSStack_1e8;
  uint **ppuStack_1e4;
  undefined4 **ppuStack_1e0;
  code *pcStack_1dc;
  undefined4 **appuStack_1d0 [2];
  undefined4 local_1c8;
  undefined *local_1c0;
  int local_1b4;
  undefined4 *local_1b0;
  int *local_1ac;
  uint *local_1a8;
  uint *local_1a4;
  undefined4 **local_1a0;
  undefined4 **local_19c;
  undefined4 **local_198;
  undefined4 **local_194;
  undefined4 local_190;
  undefined4 **local_18c;
  undefined4 local_188;
  undefined4 **local_184;
  undefined4 **local_180;
  undefined4 local_17c;
  undefined local_175;
  uint *local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined *local_168;
  undefined4 local_160;
  undefined4 local_15c;
  undefined *local_158;
  undefined4 local_150;
  undefined4 local_14c;
  undefined *local_148;
  undefined4 local_140;
  undefined4 local_13c;
  undefined *local_138;
  int local_130;
  undefined4 local_12c;
  uchar *local_128;
  uint local_120;
  undefined4 local_11c;
  uchar *local_118;
  uint local_110;
  undefined4 local_10c;
  uchar *local_108;
  uint local_100;
  undefined4 local_fc;
  uchar *local_f8;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined *local_e8;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined *local_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined *local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  int local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined *local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  int local_98;
  undefined4 local_90;
  undefined4 local_8c;
  uint local_88;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  undefined4 local_70;
  undefined4 local_6c;
  int local_68;
  undefined local_60;
  undefined local_5f;
  undefined local_5e;
  undefined auStack_5c [8];
  undefined auStack_54 [8];
  undefined auStack_4c [8];
  undefined auStack_44 [8];
  undefined auStack_3c [8];
  undefined auStack_34 [8];
  SSL_SESSION **local_2c;
  
  ppuVar16 = (uint **)PTR___stack_chk_guard_006aabf0;
  local_1c0 = &_gp;
  local_2c = *(SSL_SESSION ***)PTR___stack_chk_guard_006aabf0;
  iVar13 = 0;
  ppuVar12 = (uint **)pp;
  ppuStack_1f8 = unaff_s2;
  pSStack_1e8 = unaff_s6;
  if ((in != (SSL_SESSION *)0x0) &&
     ((ppuStack_1f8 = pp, pSStack_1e8 = in, *(int *)(in->krb5_client_princ + 0x24) != 0 ||
      (iVar13 = 0, *(int *)(in->krb5_client_princ + 0x28) != 0)))) {
    local_168 = auStack_5c;
    unaff_s3 = &local_170;
    local_170 = 8;
    local_16c = 2;
    (*(code *)PTR_ASN1_INTEGER_set_006a8264)(unaff_s3,1);
    local_158 = auStack_54;
    unaff_s4 = &local_160;
    local_160 = 8;
    local_15c = 2;
    (**(code **)(local_1c0 + -0x7c7c))(unaff_s4,in->ssl_version);
    local_14c = 4;
    local_148 = &local_60;
    if (*(int *)(in->krb5_client_princ + 0x24) == 0) {
      uVar4 = *(undefined4 *)(in->krb5_client_princ + 0x28);
    }
    else {
      uVar4 = *(undefined4 *)(*(int *)(in->krb5_client_princ + 0x24) + 8);
    }
    local_5f = (undefined)((uint)uVar4 >> 8);
    if (in->ssl_version == 2) {
      local_60 = (undefined)((uint)uVar4 >> 0x10);
      local_150 = 3;
      local_5e = (char)uVar4;
    }
    else {
      local_150 = 2;
      local_60 = local_5f;
      local_5f = (char)uVar4;
    }
    if (*(int *)(in->krb5_client_princ + 0x20) != 0) {
      local_175 = (undefined)*(int *)(in->krb5_client_princ + 0x20);
      local_140 = 1;
      local_13c = 4;
      local_138 = &local_175;
    }
    local_130 = in->master_key_length;
    local_120 = in->session_id_length;
    local_128 = in->master_key;
    local_110 = in->sid_ctx_length;
    local_118 = in->session_id;
    local_100 = in->key_arg_length;
    local_108 = in->sid_ctx;
    local_f8 = in->key_arg;
    local_12c = 4;
    local_11c = 4;
    local_10c = 4;
    local_fc = 4;
    if (*(int *)(in->krb5_client_princ + 0x1c) != 0) {
      local_f0 = 8;
      local_ec = 2;
      local_e8 = auStack_4c;
      (**(code **)(local_1c0 + -0x7c7c))(&local_f0);
    }
    if (*(int *)(in->krb5_client_princ + 0x18) != 0) {
      local_e0 = 8;
      local_dc = 2;
      local_d8 = auStack_44;
      (**(code **)(local_1c0 + -0x7c7c))(&local_e0);
    }
    if (*(int *)(in->krb5_client_princ + 0x10) != 0) {
      local_d0 = 8;
      local_cc = 2;
      local_c8 = auStack_3c;
      (**(code **)(local_1c0 + -0x7c7c))(&local_d0);
    }
    iVar13 = *(int *)(in->krb5_client_princ + 0x40);
    if (iVar13 != 0) {
      local_c0 = (**(code **)(local_1c0 + -0x53b0))(iVar13);
      local_bc = 4;
      local_b8 = iVar13;
    }
    if (*(int *)(in->krb5_client_princ + 0x54) != 0) {
      local_a0 = *(undefined4 *)(in->krb5_client_princ + 0x58);
      local_9c = 4;
      local_98 = *(int *)(in->krb5_client_princ + 0x54);
    }
    if (0 < *(int *)(in->krb5_client_princ + 0x5c)) {
      local_b0 = 8;
      local_ac = 2;
      local_a8 = auStack_34;
      (**(code **)(local_1c0 + -0x7c7c))(&local_b0);
    }
    uVar14 = in->krb5_client_princ_len;
    if (uVar14 != 0) {
      local_90 = (**(code **)(local_1c0 + -0x53b0))(uVar14);
      local_8c = 4;
      local_88 = uVar14;
    }
    iVar13 = *(int *)in->krb5_client_princ;
    if (iVar13 != 0) {
      local_80 = (**(code **)(local_1c0 + -0x53b0))(iVar13);
      local_7c = 4;
      local_78 = iVar13;
    }
    iVar13 = *(int *)(in->krb5_client_princ + 0x60);
    if (iVar13 != 0) {
      local_70 = (**(code **)(local_1c0 + -0x53b0))(iVar13);
      local_6c = 4;
      local_68 = iVar13;
    }
    local_1b0 = &local_150;
    iVar13 = (**(code **)(local_1c0 + -0x69ec))(unaff_s3,0);
    local_1a8 = &local_120;
    iVar5 = (**(code **)(local_1c0 + -0x69ec))(unaff_s4,0);
    local_1ac = &local_130;
    iVar6 = (**(code **)(local_1c0 + -0x69e8))(&local_150,0);
    iVar7 = (**(code **)(local_1c0 + -0x69e8))(&local_120,0);
    iVar8 = (**(code **)(local_1c0 + -0x69e8))(&local_130,0);
    unaff_s0 = (uint **)(iVar13 + iVar5 + iVar6 + iVar7 + iVar8);
    if (in->key_arg_length != 0) {
      iVar13 = (**(code **)(local_1c0 + -0x69e8))(&local_100,0);
      unaff_s0 = (uint **)((int)unaff_s0 + iVar13);
    }
    pcVar18 = *(code **)(local_1c0 + -0x69ec);
    if (*(int *)(in->krb5_client_princ + 0x1c) == 0) {
      local_188 = 0;
      if (*(int *)(in->krb5_client_princ + 0x18) != 0) goto LAB_004ba874;
LAB_004ba238:
      local_17c = 0;
    }
    else {
      local_188 = (*pcVar18)(&local_f0,0);
      iVar13 = (**(code **)(local_1c0 + -0x69e4))(1,local_188,1);
      unaff_s0 = (uint **)((int)unaff_s0 + iVar13);
      if (*(int *)(in->krb5_client_princ + 0x18) == 0) goto LAB_004ba238;
      pcVar18 = *(code **)(local_1c0 + -0x69ec);
LAB_004ba874:
      local_17c = (*pcVar18)(&local_e0,0);
      iVar13 = (**(code **)(local_1c0 + -0x69e4))(1,local_17c,2);
      unaff_s0 = (uint **)((int)unaff_s0 + iVar13);
    }
    if (*(int *)(in->krb5_client_princ + 0xc) == 0) {
      local_190 = 0;
    }
    else {
      local_190 = (**(code **)(local_1c0 + -0x770c))(*(int *)(in->krb5_client_princ + 0xc),0);
      iVar13 = (**(code **)(local_1c0 + -0x69e4))(1,local_190,3);
      unaff_s0 = (uint **)((int)unaff_s0 + iVar13);
    }
    local_1a4 = &local_110;
    unaff_s5 = (undefined4 **)(**(code **)(local_1c0 + -0x69e8))(local_1a4,0);
    iVar13 = (**(code **)(local_1c0 + -0x69e4))(1,unaff_s5,4);
    unaff_s7 = (uint **)((int)unaff_s0 + iVar13);
    if (*(int *)(in->krb5_client_princ + 0x10) == 0) {
      local_184 = (undefined4 **)0x0;
    }
    else {
      local_184 = (undefined4 **)(**(code **)(local_1c0 + -0x69ec))(&local_d0,0);
      iVar13 = (**(code **)(local_1c0 + -0x69e4))(1,local_184,5);
      unaff_s7 = (uint **)((int)unaff_s7 + iVar13);
    }
    if (*(int *)(in->krb5_client_princ + 0x5c) < 1) {
      local_18c = (undefined4 **)0x0;
      if (*(int *)(in->krb5_client_princ + 0x54) != 0) goto LAB_004ba300;
LAB_004ba788:
      local_198 = (undefined4 **)0x0;
      if (*(int *)(in->krb5_client_princ + 0x40) != 0) goto LAB_004ba33c;
LAB_004ba794:
      unaff_s8 = (undefined4 **)0x0;
      if (*(int *)(in->krb5_client_princ + 0x20) == 0) goto LAB_004ba378;
LAB_004ba7a0:
      local_180 = (undefined4 **)(**(code **)(local_1c0 + -0x69e8))(&local_140,0);
      iVar13 = (**(code **)(local_1c0 + -0x69e4))(1,local_180,0xb);
      unaff_s7 = (uint **)((int)unaff_s7 + iVar13);
      if (in->krb5_client_princ_len != 0) goto LAB_004ba384;
LAB_004ba7dc:
      local_1a0 = (undefined4 **)0x0;
      if (*(int *)in->krb5_client_princ != 0) goto LAB_004ba3c0;
LAB_004ba7e8:
      local_19c = (undefined4 **)0x0;
      if (*(int *)(in->krb5_client_princ + 0x60) != 0) goto LAB_004ba3fc;
LAB_004ba7f4:
      local_194 = (undefined4 **)0x0;
    }
    else {
      local_18c = (undefined4 **)(**(code **)(local_1c0 + -0x69ec))(&local_b0,0);
      iVar13 = (**(code **)(local_1c0 + -0x69e4))(1,local_18c,9);
      unaff_s7 = (uint **)((int)unaff_s7 + iVar13);
      if (*(int *)(in->krb5_client_princ + 0x54) == 0) goto LAB_004ba788;
LAB_004ba300:
      local_198 = (undefined4 **)(**(code **)(local_1c0 + -0x69e8))(&local_a0,0);
      iVar13 = (**(code **)(local_1c0 + -0x69e4))(1,local_198,10);
      unaff_s7 = (uint **)((int)unaff_s7 + iVar13);
      if (*(int *)(in->krb5_client_princ + 0x40) == 0) goto LAB_004ba794;
LAB_004ba33c:
      unaff_s8 = (undefined4 **)(**(code **)(local_1c0 + -0x69e8))(&local_c0,0);
      iVar13 = (**(code **)(local_1c0 + -0x69e4))(1,unaff_s8,6);
      unaff_s7 = (uint **)((int)unaff_s7 + iVar13);
      if (*(int *)(in->krb5_client_princ + 0x20) != 0) goto LAB_004ba7a0;
LAB_004ba378:
      local_180 = (undefined4 **)0x0;
      if (in->krb5_client_princ_len == 0) goto LAB_004ba7dc;
LAB_004ba384:
      local_1a0 = (undefined4 **)(**(code **)(local_1c0 + -0x69e8))(&local_90,0);
      iVar13 = (**(code **)(local_1c0 + -0x69e4))(1,local_1a0,7);
      unaff_s7 = (uint **)((int)unaff_s7 + iVar13);
      if (*(int *)in->krb5_client_princ == 0) goto LAB_004ba7e8;
LAB_004ba3c0:
      local_19c = (undefined4 **)(**(code **)(local_1c0 + -0x69e8))(&local_80,0);
      iVar13 = (**(code **)(local_1c0 + -0x69e4))(1,local_19c,8);
      unaff_s7 = (uint **)((int)unaff_s7 + iVar13);
      if (*(int *)(in->krb5_client_princ + 0x60) == 0) goto LAB_004ba7f4;
LAB_004ba3fc:
      local_194 = (undefined4 **)(**(code **)(local_1c0 + -0x69e8))(&local_70,0);
      iVar13 = (**(code **)(local_1c0 + -0x69e4))(1,local_194,0xc);
      unaff_s7 = (uint **)((int)unaff_s7 + iVar13);
    }
    in_a2 = (undefined4 **)&SUB_00000010;
    ppuVar12 = unaff_s7;
    local_1b4 = (**(code **)(local_1c0 + -0x69e4))(1);
    iVar13 = local_1b4;
    if (pp != (uchar **)0x0) {
      local_174 = (uint *)*pp;
      unaff_s0 = &local_174;
      local_1c8 = 0;
      (**(code **)(local_1c0 + -0x69e0))(unaff_s0,1,unaff_s7,0x10);
      (**(code **)(local_1c0 + -0x69ec))(unaff_s3,unaff_s0);
      (**(code **)(local_1c0 + -0x69ec))(unaff_s4,unaff_s0);
      (**(code **)(local_1c0 + -0x69e8))(local_1b0,unaff_s0);
      (**(code **)(local_1c0 + -0x69e8))(local_1a8,unaff_s0);
      (**(code **)(local_1c0 + -0x69e8))(local_1ac,unaff_s0);
      puVar9 = local_174;
      if (in->key_arg_length != 0) {
        (**(code **)(local_1c0 + -0x69e8))(&local_100,unaff_s0);
        *(byte *)puVar9 = *(byte *)puVar9 & 0x20 | 0x80;
      }
      if (*(int *)(in->krb5_client_princ + 0x1c) == 0) {
        iVar13 = *(int *)(in->krb5_client_princ + 0x18);
      }
      else {
        local_1c8 = 0x80;
        (**(code **)(local_1c0 + -0x69e0))(unaff_s0,1,local_188,1);
        (**(code **)(local_1c0 + -0x69ec))(&local_f0,unaff_s0);
        iVar13 = *(int *)(in->krb5_client_princ + 0x18);
      }
      if (iVar13 != 0) {
        local_1c8 = 0x80;
        (**(code **)(local_1c0 + -0x69e0))(unaff_s0,1,local_17c,2);
        (**(code **)(local_1c0 + -0x69ec))(&local_e0,unaff_s0);
      }
      if (*(int *)(in->krb5_client_princ + 0xc) != 0) {
        local_1c8 = 0x80;
        (**(code **)(local_1c0 + -0x69e0))(unaff_s0,1,local_190,3);
        (**(code **)(local_1c0 + -0x770c))(*(undefined4 *)(in->krb5_client_princ + 0xc),unaff_s0);
      }
      unaff_s3 = (undefined4 *)&DAT_00000080;
      local_1c8 = 0x80;
      in_a2 = unaff_s5;
      (**(code **)(local_1c0 + -0x69e0))(unaff_s0,1,unaff_s5,4);
      ppuVar12 = unaff_s0;
      (**(code **)(local_1c0 + -0x69e8))(local_1a4);
      if (*(int *)(in->krb5_client_princ + 0x10) != 0) {
        local_1c8 = 0x80;
        in_a2 = local_184;
        (**(code **)(local_1c0 + -0x69e0))(unaff_s0,1,local_184,5);
        ppuVar12 = unaff_s0;
        (**(code **)(local_1c0 + -0x69ec))(&local_d0);
      }
      if (*(int *)(in->krb5_client_princ + 0x40) != 0) {
        local_1c8 = 0x80;
        in_a2 = unaff_s8;
        (**(code **)(local_1c0 + -0x69e0))(unaff_s0,1,unaff_s8,6);
        ppuVar12 = unaff_s0;
        (**(code **)(local_1c0 + -0x69e8))(&local_c0);
      }
      if (in->krb5_client_princ_len != 0) {
        local_1c8 = 0x80;
        in_a2 = local_1a0;
        (**(code **)(local_1c0 + -0x69e0))(unaff_s0,1,local_1a0,7);
        ppuVar12 = unaff_s0;
        (**(code **)(local_1c0 + -0x69e8))(&local_90);
      }
      if (*(int *)in->krb5_client_princ != 0) {
        local_1c8 = 0x80;
        in_a2 = local_19c;
        (**(code **)(local_1c0 + -0x69e0))(unaff_s0,1,local_19c,8);
        ppuVar12 = unaff_s0;
        (**(code **)(local_1c0 + -0x69e8))(&local_80);
      }
      if (0 < *(int *)(in->krb5_client_princ + 0x5c)) {
        local_1c8 = 0x80;
        in_a2 = local_18c;
        (**(code **)(local_1c0 + -0x69e0))(unaff_s0,1,local_18c,9);
        ppuVar12 = unaff_s0;
        (**(code **)(local_1c0 + -0x69ec))(&local_b0);
      }
      if (*(int *)(in->krb5_client_princ + 0x54) != 0) {
        local_1c8 = 0x80;
        in_a2 = local_198;
        (**(code **)(local_1c0 + -0x69e0))(unaff_s0,1,local_198,10);
        ppuVar12 = unaff_s0;
        (**(code **)(local_1c0 + -0x69e8))(&local_a0);
      }
      if (*(int *)(in->krb5_client_princ + 0x20) != 0) {
        local_1c8 = 0x80;
        in_a2 = local_180;
        (**(code **)(local_1c0 + -0x69e0))(unaff_s0,1,local_180,0xb);
        ppuVar12 = unaff_s0;
        (**(code **)(local_1c0 + -0x69e8))(&local_140);
      }
      if (*(int *)(in->krb5_client_princ + 0x60) != 0) {
        local_1c8 = 0x80;
        in_a2 = local_194;
        (**(code **)(local_1c0 + -0x69e0))(unaff_s0,1,local_194,0xc);
        ppuVar12 = unaff_s0;
        (**(code **)(local_1c0 + -0x69e8))(&local_70);
      }
      *pp = (uchar *)local_174;
      iVar13 = local_1b4;
    }
  }
  if (local_2c == (SSL_SESSION **)*ppuVar16) {
    return iVar13;
  }
  pcStack_1dc = d2i_SSL_SESSION;
  ppSVar11 = local_2c;
  (**(code **)(local_1c0 + -0x5328))();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  puVar9 = *ppuVar12;
  puStack_1fc = (undefined *)ppuVar16;
  uStack_228 = 0x3a;
  puStack_204 = *(uint **)PTR___stack_chk_guard_006aabf0;
  puStack_210 = puVar9;
  ppuStack_20c = ppuVar12;
  ppuStack_200 = unaff_s0;
  puStack_1f4 = unaff_s3;
  puStack_1f0 = unaff_s4;
  ppuStack_1ec = unaff_s5;
  ppuStack_1e4 = unaff_s7;
  ppuStack_1e0 = unaff_s8;
  appuStack_1d0[0] = in_a2;
  if ((ppSVar11 == (SSL_SESSION **)0x0) || (pSVar15 = *ppSVar11, pSVar15 == (SSL_SESSION *)0x0)) {
    pSVar15 = SSL_SESSION_new();
    if (pSVar15 == (SSL_SESSION *)0x0) {
      uStack_208 = 0x182;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x67,uStack_228,"ssl_asn1.c",0x182);
      (*(code *)PTR_asn1_add_error_006a9508)(*ppuVar12,(int)puStack_210 - (int)*ppuVar12);
      pSVar10 = (SSL_SESSION *)0x0;
      goto LAB_004babc4;
    }
    puVar9 = *ppuVar12;
  }
  puStack_264 = auStack_250;
  puStack_260 = auStack_240;
  apuStack_230[0] = puVar9;
  if (appuStack_1d0[0] == (undefined4 **)0x0) {
    pbStack_214 = (byte *)0x0;
    iVar13 = (*(code *)PTR_asn1_GetSequence_006a9504)(apuStack_230,appuStack_1d0);
  }
  else {
    pbStack_214 = (byte *)((int)puVar9 + (int)appuStack_1d0[0]);
    iVar13 = (*(code *)PTR_asn1_GetSequence_006a9504)(apuStack_230,appuStack_1d0);
  }
  if (iVar13 == 0) {
    ppuVar16 = apuStack_230;
    uStack_208 = 0x188;
    goto LAB_004bab64;
  }
  ppuVar16 = apuStack_230;
  unaff_s5 = &puStack_264;
  pvStack_248 = (void *)0x0;
  auStack_250[0] = 0;
  puStack_210 = apuStack_230[0];
  iVar13 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,ppuVar16,iStack_218);
  if (iVar13 == 0) {
    uStack_208 = 0x18b;
    goto LAB_004bab64;
  }
  iStack_218 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
  if (pvStack_248 != (void *)0x0) {
    CRYPTO_free(pvStack_248);
    pvStack_248 = (void *)0x0;
    auStack_250[0] = 0;
  }
  puStack_210 = apuStack_230[0];
  iVar13 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,ppuVar16,iStack_218);
  if (iVar13 == 0) {
    uStack_208 = 399;
    goto LAB_004bab64;
  }
  iStack_218 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
  iVar13 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)(puStack_264);
  pSVar15->ssl_version = iVar13;
  if (pvStack_248 != (void *)0x0) {
    CRYPTO_free(pvStack_248);
    pvStack_248 = (void *)0x0;
    auStack_250[0] = 0;
  }
  unaff_s7 = &puStack_260;
  pbStack_238 = (byte *)0x0;
  auStack_240[0] = 0;
  puStack_210 = apuStack_230[0];
  iVar5 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,ppuVar16,iStack_218);
  puVar2 = PTR_d2i_ASN1_OCTET_STRING_006a9510;
  if (iVar5 == 0) {
    uStack_208 = 0x195;
    goto LAB_004bab64;
  }
  iStack_218 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
  if (iVar13 == 2) {
    if (auStack_240[0] == 3) {
      uVar14 = (uint)*pbStack_238 << 0x10 | pbStack_238[2] | 0x2000000 | (uint)pbStack_238[1] << 8;
LAB_004bae24:
      *(undefined4 *)(pSVar15->krb5_client_princ + 0x24) = 0;
      *(uint *)(pSVar15->krb5_client_princ + 0x28) = uVar14;
      puStack_210 = apuStack_230[0];
      iVar13 = (*(code *)puVar2)(unaff_s7,ppuVar16);
      puVar9 = apuStack_230[0];
      puVar2 = PTR_memcpy_006aabf4;
      if (iVar13 == 0) {
        uStack_208 = 0x1b6;
        goto LAB_004bab64;
      }
      iVar13 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
      if (0x20 < (int)auStack_240[0]) {
        auStack_240[0] = 0x20;
      }
      pSVar15->session_id_length = auStack_240[0];
      iStack_218 = iVar13;
      (*(code *)puVar2)(pSVar15->session_id,pbStack_238,auStack_240[0]);
      puStack_210 = puVar9;
      iVar13 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,ppuVar16,iVar13);
      puVar9 = apuStack_230[0];
      pbVar17 = pbStack_238;
      puVar2 = PTR_memcpy_006aabf4;
      if (iVar13 == 0) {
        uStack_208 = 0x1c5;
        goto LAB_004bab64;
      }
      uVar14 = auStack_240[0];
      if (0x30 < (int)auStack_240[0]) {
        uVar14 = 0x30;
      }
      iStack_218 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
      pSVar15->master_key_length = uVar14;
      (*(code *)puVar2)(pSVar15->master_key,pbStack_238,uVar14);
      puVar2 = PTR_d2i_ASN1_OCTET_STRING_006a9510;
      auStack_240[0] = 0;
      if (iStack_218 == 0) {
LAB_004baf1c:
        uVar14 = 0;
      }
      else {
        bVar1 = *(byte *)puVar9;
        if ((bVar1 & 0xdf) != 0x80) goto LAB_004baf1c;
        *(byte *)puVar9 = bVar1 & 0x20 | 4;
        puStack_210 = apuStack_230[0];
        iVar13 = (*(code *)puVar2)(unaff_s7,ppuVar16,iStack_218);
        if (iVar13 == 0) {
          uStack_208 = 0x1e0;
          *(byte *)puStack_210 = bVar1;
          goto LAB_004bab64;
        }
        iStack_218 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
        *(byte *)puStack_210 = bVar1;
        uVar14 = auStack_240[0];
        pbVar17 = pbStack_238;
        if (8 < (int)auStack_240[0]) {
          uVar14 = 8;
        }
      }
      puVar2 = PTR_memcpy_006aabf4;
      pSVar15->key_arg_length = uVar14;
      (*(code *)puVar2)(pSVar15->key_arg,pbVar17);
      if (pbStack_238 != (byte *)0x0) {
        CRYPTO_free(pbStack_238);
      }
      auStack_250[0] = 0;
      if ((iStack_218 != 0) && (*(byte *)apuStack_230[0] == 0xa1)) {
        puStack_210 = apuStack_230[0];
        uVar14 = (*(code *)PTR_ASN1_get_object_006a9514)
                           (ppuVar16,&iStack_254,auStack_25c,auStack_258,iStack_218);
        if ((uVar14 & 0x80) != 0) {
          uStack_228 = 0x3b;
          uStack_208 = 0x1e9;
          goto LAB_004bab64;
        }
        if (uVar14 == 0x21) {
          iStack_254 = (iStack_218 - ((int)apuStack_230[0] - (int)puStack_210)) + -2;
          iVar13 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,ppuVar16,iStack_254);
          if (iVar13 != 0) {
            iStack_254 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
            iVar13 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(ppuVar16,iStack_254);
            if (iVar13 != 0) goto LAB_004bb61c;
            uStack_228 = 0x3f;
          }
        }
        else {
          iVar13 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,ppuVar16,iStack_254);
          if (iVar13 != 0) {
LAB_004bb61c:
            iStack_218 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
            goto LAB_004baf70;
          }
        }
        uStack_208 = 0x1e9;
        goto LAB_004bab64;
      }
LAB_004baf70:
      if (pvStack_248 == (void *)0x0) {
        uVar4 = (*(code *)PTR_time_006aabe4)(0);
        *(undefined4 *)(pSVar15->krb5_client_princ + 0x1c) = uVar4;
      }
      else {
        uVar4 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)(puStack_264);
        *(undefined4 *)(pSVar15->krb5_client_princ + 0x1c) = uVar4;
        CRYPTO_free(pvStack_248);
        pvStack_248 = (void *)0x0;
      }
      auStack_250[0] = 0;
      if ((iStack_218 != 0) && (*(byte *)apuStack_230[0] == 0xa2)) {
        puStack_210 = apuStack_230[0];
        uVar14 = (*(code *)PTR_ASN1_get_object_006a9514)
                           (ppuVar16,&iStack_254,auStack_25c,auStack_258,iStack_218);
        if ((uVar14 & 0x80) != 0) {
          uStack_228 = 0x3b;
          uStack_208 = 499;
          goto LAB_004bab64;
        }
        if (uVar14 == 0x21) {
          iStack_254 = (iStack_218 - ((int)apuStack_230[0] - (int)puStack_210)) + -2;
          iVar13 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,ppuVar16,iStack_254);
          if (iVar13 != 0) {
            iStack_254 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
            iVar13 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(ppuVar16,iStack_254);
            if (iVar13 != 0) goto LAB_004bb5dc;
            uStack_228 = 0x3f;
          }
        }
        else {
          iVar13 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,ppuVar16,iStack_254);
          if (iVar13 != 0) {
LAB_004bb5dc:
            iStack_218 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
            goto LAB_004bafc0;
          }
        }
        uStack_208 = 499;
        goto LAB_004bab64;
      }
LAB_004bafc0:
      if (pvStack_248 == (void *)0x0) {
        *(undefined4 *)(pSVar15->krb5_client_princ + 0x18) = 3;
      }
      else {
        uVar4 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)(puStack_264);
        *(undefined4 *)(pSVar15->krb5_client_princ + 0x18) = uVar4;
        CRYPTO_free(pvStack_248);
        pvStack_248 = (void *)0x0;
        auStack_250[0] = 0;
      }
      if (*(int *)(pSVar15->krb5_client_princ + 0xc) != 0) {
        (*(code *)PTR_X509_free_006a7f90)();
        *(undefined4 *)(pSVar15->krb5_client_princ + 0xc) = 0;
      }
      if (iStack_218 == 0) {
        auStack_240[0] = 0;
        pbStack_238 = (byte *)0x0;
LAB_004bb048:
        pSVar15->sid_ctx_length = 0;
      }
      else {
        if (*(byte *)apuStack_230[0] != 0xa3) {
LAB_004bb038:
          pbStack_238 = (byte *)0x0;
          auStack_240[0] = 0;
          if (*(byte *)apuStack_230[0] == 0xa4) {
            puStack_210 = apuStack_230[0];
            uVar14 = (*(code *)PTR_ASN1_get_object_006a9514)
                               (ppuVar16,&iStack_254,auStack_25c,auStack_258,iStack_218);
            if ((uVar14 & 0x80) != 0) {
              uStack_228 = 0x3b;
              uStack_208 = 0x205;
              goto LAB_004bab64;
            }
            if (uVar14 == 0x21) {
              iStack_254 = (iStack_218 - ((int)apuStack_230[0] - (int)puStack_210)) + -2;
              iVar13 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,ppuVar16,iStack_254);
              if (iVar13 != 0) {
                iStack_254 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
                iVar13 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(ppuVar16,iStack_254);
                if (iVar13 != 0) goto LAB_004bb65c;
                uStack_228 = 0x3f;
              }
            }
            else {
              iVar13 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,ppuVar16,iStack_254);
              if (iVar13 != 0) {
LAB_004bb65c:
                pbVar17 = pbStack_238;
                puVar2 = PTR_memcpy_006aabf4;
                iStack_218 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
                if (pbStack_238 != (byte *)0x0) {
                  if (0x20 < (int)auStack_240[0]) {
                    uStack_228 = 0x10f;
                    goto LAB_004bab64;
                  }
                  pSVar15->sid_ctx_length = auStack_240[0];
                  (*(code *)puVar2)(pSVar15->sid_ctx,pbStack_238);
                  CRYPTO_free(pbVar17);
                  pbStack_238 = (byte *)0x0;
                  auStack_240[0] = 0;
                  goto LAB_004bb04c;
                }
                goto LAB_004bb048;
              }
            }
            uStack_208 = 0x205;
            goto LAB_004bab64;
          }
          goto LAB_004bb048;
        }
        puStack_210 = apuStack_230[0];
        uVar14 = (*(code *)PTR_ASN1_get_object_006a9514)
                           (ppuVar16,&iStack_254,auStack_25c,auStack_258,iStack_218);
        if ((uVar14 & 0x80) != 0) {
          uStack_228 = 0x3b;
          uStack_208 = 0x201;
          goto LAB_004bab64;
        }
        if (uVar14 == 0x21) {
          iStack_254 = (iStack_218 - ((int)apuStack_230[0] - (int)puStack_210)) + -2;
          iVar13 = (*(code *)PTR_d2i_X509_006a9070)
                             (pSVar15->krb5_client_princ + 0xc,ppuVar16,iStack_254);
          if (iVar13 != 0) {
            iStack_254 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
            iVar13 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(ppuVar16,iStack_254);
            if (iVar13 != 0) goto LAB_004bb588;
            uStack_228 = 0x3f;
          }
LAB_004bbc9c:
          uStack_208 = 0x201;
          goto LAB_004bab64;
        }
        iVar13 = (*(code *)PTR_d2i_X509_006a9070)
                           (pSVar15->krb5_client_princ + 0xc,ppuVar16,iStack_254);
        if (iVar13 == 0) goto LAB_004bbc9c;
LAB_004bb588:
        auStack_240[0] = 0;
        pbStack_238 = (byte *)0x0;
        iStack_218 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
        if (iStack_218 != 0) goto LAB_004bb038;
        pSVar15->sid_ctx_length = 0;
      }
LAB_004bb04c:
      auStack_250[0] = 0;
      if ((iStack_218 != 0) && (*(byte *)apuStack_230[0] == 0xa5)) {
        puStack_210 = apuStack_230[0];
        uVar14 = (*(code *)PTR_ASN1_get_object_006a9514)
                           (ppuVar16,&iStack_254,auStack_25c,auStack_258,iStack_218);
        if ((uVar14 & 0x80) != 0) {
          uStack_228 = 0x3b;
          uStack_208 = 0x219;
          goto LAB_004bab64;
        }
        if (uVar14 == 0x21) {
          iStack_254 = (iStack_218 - ((int)apuStack_230[0] - (int)puStack_210)) + -2;
          iVar13 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,ppuVar16,iStack_254);
          if (iVar13 != 0) {
            iStack_254 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
            iVar13 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(ppuVar16,iStack_254);
            if (iVar13 != 0) goto LAB_004bb9b8;
            uStack_228 = 0x3f;
          }
        }
        else {
          iVar13 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,ppuVar16,iStack_254);
          if (iVar13 != 0) {
LAB_004bb9b8:
            iStack_218 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
            goto LAB_004bb068;
          }
        }
        uStack_208 = 0x219;
        goto LAB_004bab64;
      }
LAB_004bb068:
      if (pvStack_248 == (void *)0x0) {
        *(undefined4 *)(pSVar15->krb5_client_princ + 0x10) = 0;
      }
      else {
        uVar4 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)(puStack_264);
        *(undefined4 *)(pSVar15->krb5_client_princ + 0x10) = uVar4;
        CRYPTO_free(pvStack_248);
        pvStack_248 = (void *)0x0;
        auStack_250[0] = 0;
      }
      auStack_240[0] = 0;
      pbStack_238 = (byte *)0x0;
      if ((iStack_218 != 0) && (*(byte *)apuStack_230[0] == 0xa6)) {
        puStack_210 = apuStack_230[0];
        uVar14 = (*(code *)PTR_ASN1_get_object_006a9514)
                           (ppuVar16,&iStack_254,auStack_25c,auStack_258,iStack_218);
        if ((uVar14 & 0x80) != 0) {
          uStack_228 = 0x3b;
          uStack_208 = 0x225;
          goto LAB_004bab64;
        }
        if (uVar14 == 0x21) {
          iStack_254 = (iStack_218 - ((int)apuStack_230[0] - (int)puStack_210)) + -2;
          iVar13 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,ppuVar16,iStack_254);
          if (iVar13 != 0) {
            iStack_254 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
            iVar13 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(ppuVar16,iStack_254);
            if (iVar13 != 0) goto LAB_004bbb00;
            uStack_228 = 0x3f;
          }
        }
        else {
          iVar13 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,ppuVar16,iStack_254);
          if (iVar13 != 0) {
LAB_004bbb00:
            iStack_218 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
            if (pbStack_238 == (byte *)0x0) goto LAB_004bb0b0;
            uVar4 = (*(code *)PTR_BUF_strndup_006a9520)(pbStack_238,auStack_240[0]);
            *(undefined4 *)(pSVar15->krb5_client_princ + 0x40) = uVar4;
            CRYPTO_free(pbStack_238);
            goto LAB_004bb0b4;
          }
        }
        uStack_208 = 0x225;
        goto LAB_004bab64;
      }
LAB_004bb0b0:
      *(undefined4 *)(pSVar15->krb5_client_princ + 0x40) = 0;
LAB_004bb0b4:
      auStack_240[0] = 0;
      pbStack_238 = (byte *)0x0;
      if ((iStack_218 != 0) && (*(byte *)apuStack_230[0] == 0xa7)) {
        puStack_210 = apuStack_230[0];
        uVar14 = (*(code *)PTR_ASN1_get_object_006a9514)
                           (ppuVar16,&iStack_254,auStack_25c,auStack_258,iStack_218);
        if ((uVar14 & 0x80) != 0) {
          uStack_228 = 0x3b;
          uStack_208 = 0x234;
          goto LAB_004bab64;
        }
        if (uVar14 == 0x21) {
          iStack_254 = (iStack_218 - ((int)apuStack_230[0] - (int)puStack_210)) + -2;
          iVar13 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,ppuVar16,iStack_254);
          if (iVar13 != 0) {
            iStack_254 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
            iVar13 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(ppuVar16,iStack_254);
            if (iVar13 != 0) goto LAB_004bba88;
            uStack_228 = 0x3f;
          }
        }
        else {
          iVar13 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,ppuVar16,iStack_254);
          if (iVar13 != 0) {
LAB_004bba88:
            iStack_218 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
            if (pbStack_238 == (byte *)0x0) goto LAB_004bb0c0;
            uVar14 = (*(code *)PTR_BUF_strndup_006a9520)(pbStack_238,auStack_240[0]);
            pSVar15->krb5_client_princ_len = uVar14;
            CRYPTO_free(pbStack_238);
            goto LAB_004bb0c4;
          }
        }
        uStack_208 = 0x234;
        goto LAB_004bab64;
      }
LAB_004bb0c0:
      pSVar15->krb5_client_princ_len = 0;
LAB_004bb0c4:
      auStack_240[0] = 0;
      pbStack_238 = (byte *)0x0;
      if ((iStack_218 == 0) || (*(byte *)apuStack_230[0] != 0xa8)) {
LAB_004bb0d0:
        *(undefined4 *)pSVar15->krb5_client_princ = 0;
LAB_004bb0d4:
        auStack_250[0] = 0;
        pSVar10 = pSVar15;
        if (iStack_218 == 0) goto LAB_004bb0f0;
        iVar13 = iStack_218;
        puVar9 = apuStack_230[0];
        pcVar18 = (code *)PTR_ASN1_get_object_006a9514;
        if (*(byte *)apuStack_230[0] == 0xa9) goto LAB_004bb728;
        goto LAB_004bb0f0;
      }
      puStack_210 = apuStack_230[0];
      uVar14 = (*(code *)PTR_ASN1_get_object_006a9514)
                         (ppuVar16,&iStack_254,auStack_25c,auStack_258,iStack_218);
      if ((uVar14 & 0x80) != 0) {
        uStack_228 = 0x3b;
        uStack_208 = 0x241;
        goto LAB_004bab64;
      }
      if (uVar14 == 0x21) {
        iStack_254 = (iStack_218 - ((int)apuStack_230[0] - (int)puStack_210)) + -2;
        iVar13 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,ppuVar16,iStack_254);
        if (iVar13 != 0) {
          iStack_254 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
          iVar13 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(ppuVar16,iStack_254);
          if (iVar13 != 0) goto LAB_004bbb78;
          uStack_228 = 0x3f;
        }
      }
      else {
        iVar13 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,ppuVar16,iStack_254);
        if (iVar13 != 0) {
LAB_004bbb78:
          iStack_218 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
          if (pbStack_238 != (byte *)0x0) {
            uVar4 = (*(code *)PTR_BUF_strndup_006a9520)(pbStack_238,auStack_240[0]);
            *(undefined4 *)pSVar15->krb5_client_princ = uVar4;
            CRYPTO_free(pbStack_238);
            pbStack_238 = (byte *)0x0;
            auStack_240[0] = 0;
            goto LAB_004bb0d4;
          }
          goto LAB_004bb0d0;
        }
      }
      uStack_208 = 0x241;
      goto LAB_004bab64;
    }
  }
  else {
    if (iVar13 < 0x300) {
      uStack_228 = 0xfe;
      goto LAB_004bab64;
    }
    if (auStack_240[0] == 2) {
      uVar14 = (uint)*pbStack_238 << 8 | pbStack_238[1] | 0x3000000;
      goto LAB_004bae24;
    }
  }
  uStack_228 = 0x89;
LAB_004bab64:
  do {
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x67,uStack_228,"ssl_asn1.c",uStack_208);
    (*(code *)PTR_asn1_add_error_006a9508)(*ppuVar12,(int)puStack_210 - (int)*ppuVar12);
    if ((ppSVar11 == (SSL_SESSION **)0x0) || (pSVar10 = (SSL_SESSION *)0x0, pSVar15 != *ppSVar11)) {
      SSL_SESSION_free(pSVar15);
      pSVar10 = (SSL_SESSION *)0x0;
    }
LAB_004babc4:
    if (puStack_204 == *(uint **)puVar3) {
      return (int)pSVar10;
    }
    puVar9 = puStack_204;
    pcVar18 = (code *)PTR___stack_chk_fail_006aabb8;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    iVar13 = extraout_v1;
LAB_004bb728:
    puStack_210 = puVar9;
    uVar14 = (*pcVar18)(ppuVar16,&iStack_254,auStack_25c,auStack_258,iVar13);
    if ((uVar14 & 0x80) != 0) {
      uStack_228 = 0x3b;
      uStack_208 = 0x24f;
      goto LAB_004bab64;
    }
    if (uVar14 == 0x21) {
      iStack_254 = (iStack_218 - ((int)apuStack_230[0] - (int)puStack_210)) + -2;
      iVar13 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,ppuVar16,iStack_254);
      if (iVar13 != 0) {
        iStack_254 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
        iVar13 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(ppuVar16,iStack_254);
        if (iVar13 != 0) goto LAB_004bb8ec;
        uStack_228 = 0x3f;
      }
LAB_004bc148:
      uStack_208 = 0x24f;
      goto LAB_004bab64;
    }
    iVar13 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,ppuVar16,iStack_254);
    if (iVar13 == 0) goto LAB_004bc148;
LAB_004bb8ec:
    iStack_218 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
    pSVar10 = pSVar15;
LAB_004bb0f0:
    if (pvStack_248 == (void *)0x0) {
      if ((*(int *)(pSVar10->krb5_client_princ + 0x58) == 0) || (pSVar10->session_id_length == 0)) {
        *(undefined4 *)(pSVar10->krb5_client_princ + 0x5c) = 0;
      }
      else {
        *(undefined4 *)(pSVar10->krb5_client_princ + 0x5c) = 0xffffffff;
      }
    }
    else {
      uVar4 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)(puStack_264);
      *(undefined4 *)(pSVar10->krb5_client_princ + 0x5c) = uVar4;
      CRYPTO_free(pvStack_248);
      pvStack_248 = (void *)0x0;
      auStack_250[0] = 0;
    }
    auStack_240[0] = 0;
    pbStack_238 = (byte *)0x0;
    pSVar15 = pSVar10;
    if (iStack_218 != 0) {
      if (*(byte *)apuStack_230[0] == 0xaa) {
        puStack_210 = apuStack_230[0];
        uVar14 = (*(code *)PTR_ASN1_get_object_006a9514)
                           (ppuVar16,&iStack_254,auStack_25c,auStack_258,iStack_218);
        if ((uVar14 & 0x80) == 0) {
          if (uVar14 == 0x21) {
            iStack_254 = (iStack_218 - ((int)apuStack_230[0] - (int)puStack_210)) + -2;
            iVar13 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,ppuVar16,iStack_254);
            if (iVar13 != 0) {
              iStack_254 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
              iVar13 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(ppuVar16,iStack_254);
              if (iVar13 != 0) goto LAB_004bb814;
              uStack_228 = 0x3f;
            }
          }
          else {
            iVar13 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,ppuVar16,iStack_254);
            if (iVar13 != 0) {
LAB_004bb814:
              iStack_218 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
              if (pbStack_238 != (byte *)0x0) {
                *(uint *)(pSVar10->krb5_client_princ + 0x58) = auStack_240[0];
              }
              *(byte **)(pSVar10->krb5_client_princ + 0x54) = pbStack_238;
              if (iStack_218 == 0) {
                auStack_240[0] = 0;
                pbStack_238 = (byte *)0x0;
                goto LAB_004bb180;
              }
              goto LAB_004bb158;
            }
          }
          uStack_208 = 0x25b;
        }
        else {
          uStack_228 = 0x3b;
          uStack_208 = 0x25b;
        }
      }
      else {
        *(undefined4 *)(pSVar10->krb5_client_princ + 0x54) = 0;
LAB_004bb158:
        pbStack_238 = (byte *)0x0;
        auStack_240[0] = 0;
        if (*(byte *)apuStack_230[0] == 0xab) {
          puStack_210 = apuStack_230[0];
          uVar14 = (*(code *)PTR_ASN1_get_object_006a9514)
                             (ppuVar16,&iStack_254,auStack_25c,auStack_258,iStack_218);
          if ((uVar14 & 0x80) == 0) {
            if (uVar14 == 0x21) {
              iStack_254 = (iStack_218 - ((int)apuStack_230[0] - (int)puStack_210)) + -2;
              iVar13 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,ppuVar16,iStack_254);
              if (iVar13 != 0) {
                iStack_254 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
                iVar13 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(ppuVar16,iStack_254);
                if (iVar13 != 0) goto LAB_004bb87c;
                uStack_228 = 0x3f;
              }
            }
            else {
              iVar13 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,ppuVar16,iStack_254);
              if (iVar13 != 0) {
LAB_004bb87c:
                iStack_218 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
                if (pbStack_238 != (byte *)0x0) {
                  *(uint *)(pSVar10->krb5_client_princ + 0x20) = (uint)*pbStack_238;
                  CRYPTO_free(pbStack_238);
                }
                auStack_240[0] = 0;
                pbStack_238 = (byte *)0x0;
                if (iStack_218 == 0) goto LAB_004bb180;
                goto LAB_004bb170;
              }
            }
            uStack_208 = 0x269;
          }
          else {
            uStack_228 = 0x3b;
            uStack_208 = 0x269;
          }
        }
        else {
LAB_004bb170:
          pbStack_238 = (byte *)0x0;
          auStack_240[0] = 0;
          if (*(byte *)apuStack_230[0] != 0xac) goto LAB_004bb180;
          puStack_210 = apuStack_230[0];
          uVar14 = (*(code *)PTR_ASN1_get_object_006a9514)
                             (ppuVar16,&iStack_254,auStack_25c,auStack_258,iStack_218);
          if ((uVar14 & 0x80) == 0) {
            if (uVar14 == 0x21) {
              iStack_254 = (iStack_218 - ((int)apuStack_230[0] - (int)puStack_210)) + -2;
              iVar13 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,ppuVar16,iStack_254);
              if (iVar13 != 0) {
                iStack_254 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
                iVar13 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(ppuVar16,iStack_254);
                if (iVar13 != 0) goto LAB_004bba14;
                uStack_228 = 0x3f;
              }
            }
            else {
              iVar13 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,ppuVar16,iStack_254);
              if (iVar13 != 0) {
LAB_004bba14:
                iStack_218 = iStack_218 - ((int)apuStack_230[0] - (int)puStack_210);
                if (pbStack_238 == (byte *)0x0) goto LAB_004bb180;
                uVar4 = (*(code *)PTR_BUF_strndup_006a9520)(pbStack_238,auStack_240[0]);
                *(undefined4 *)(pSVar10->krb5_client_princ + 0x60) = uVar4;
                CRYPTO_free(pbStack_238);
                pbStack_238 = (byte *)0x0;
                auStack_240[0] = 0;
                goto LAB_004bb184;
              }
            }
            uStack_208 = 0x275;
          }
          else {
            uStack_228 = 0x3b;
            uStack_208 = 0x275;
          }
        }
      }
      goto LAB_004bab64;
    }
    *(undefined4 *)(pSVar10->krb5_client_princ + 0x54) = 0;
    auStack_240[0] = 0;
    pbStack_238 = (byte *)0x0;
LAB_004bb180:
    *(undefined4 *)(pSVar10->krb5_client_princ + 0x60) = 0;
LAB_004bb184:
    iVar13 = (*(code *)PTR_asn1_const_Finish_006a9518)(ppuVar16);
    if (iVar13 != 0) {
      *ppuVar12 = apuStack_230[0];
      if (ppSVar11 != (SSL_SESSION **)0x0) {
        *ppSVar11 = pSVar10;
      }
      goto LAB_004babc4;
    }
    uStack_208 = 0x281;
  } while( true );
}

