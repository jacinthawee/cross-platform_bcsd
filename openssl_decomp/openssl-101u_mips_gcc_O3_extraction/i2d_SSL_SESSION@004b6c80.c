
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
  undefined4 ***pppuVar9;
  SSL_SESSION *pSVar10;
  undefined4 ***extraout_v1;
  SSL_SESSION **ppSVar11;
  undefined4 ****ppppuVar12;
  byte ****ppppbVar13;
  int in_a2;
  undefined4 ****unaff_s0;
  int iVar14;
  uint uVar15;
  SSL_SESSION *pSVar16;
  byte ****ppppbVar17;
  uchar **unaff_s2;
  undefined4 *unaff_s3;
  undefined4 *unaff_s4;
  int unaff_s5;
  SSL_SESSION *unaff_s6;
  byte *pbVar18;
  undefined4 ****unaff_s7;
  code *pcVar19;
  int unaff_s8;
  undefined4 *puStack_264;
  undefined4 ****ppppuStack_260;
  undefined auStack_25c [4];
  undefined auStack_258 [4];
  byte ****ppppbStack_254;
  undefined4 auStack_250 [2];
  void *pvStack_248;
  byte ****appppbStack_240 [2];
  byte *pbStack_238;
  undefined4 ***apppuStack_230 [2];
  undefined4 uStack_228;
  byte ****ppppbStack_218;
  byte *pbStack_214;
  undefined4 ***pppuStack_210;
  undefined4 ****ppppuStack_20c;
  undefined4 uStack_208;
  int iStack_204;
  undefined4 ****ppppuStack_200;
  undefined *puStack_1fc;
  uchar **ppuStack_1f8;
  undefined4 *puStack_1f4;
  undefined4 *puStack_1f0;
  int iStack_1ec;
  SSL_SESSION *pSStack_1e8;
  undefined4 ****ppppuStack_1e4;
  int iStack_1e0;
  code *pcStack_1dc;
  int aiStack_1d0 [2];
  undefined4 local_1c8;
  undefined *local_1c0;
  int local_1b4;
  undefined4 *local_1b0;
  int *local_1ac;
  uint *local_1a8;
  uint *local_1a4;
  int local_1a0;
  int local_19c;
  int local_198;
  int local_194;
  undefined4 local_190;
  int local_18c;
  undefined4 local_188;
  int local_184;
  int local_180;
  undefined4 local_17c;
  undefined local_175;
  undefined4 ***local_174;
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
  
  ppppbVar17 = (byte ****)PTR___stack_chk_guard_006a9ae8;
  local_1c0 = &_gp;
  local_2c = *(SSL_SESSION ***)PTR___stack_chk_guard_006a9ae8;
  iVar14 = 0;
  ppppuVar12 = (undefined4 ****)pp;
  ppuStack_1f8 = unaff_s2;
  pSStack_1e8 = unaff_s6;
  if ((in != (SSL_SESSION *)0x0) &&
     ((ppuStack_1f8 = pp, pSStack_1e8 = in, *(int *)(in->krb5_client_princ + 0x24) != 0 ||
      (iVar14 = 0, *(int *)(in->krb5_client_princ + 0x28) != 0)))) {
    local_168 = auStack_5c;
    unaff_s3 = &local_170;
    local_170 = 8;
    local_16c = 2;
    (*(code *)PTR_ASN1_INTEGER_set_006a7164)(unaff_s3,1);
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
    iVar14 = *(int *)(in->krb5_client_princ + 0x40);
    if (iVar14 != 0) {
      local_c0 = (**(code **)(local_1c0 + -0x53bc))(iVar14);
      local_bc = 4;
      local_b8 = iVar14;
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
    uVar15 = in->krb5_client_princ_len;
    if (uVar15 != 0) {
      local_90 = (**(code **)(local_1c0 + -0x53bc))(uVar15);
      local_8c = 4;
      local_88 = uVar15;
    }
    iVar14 = *(int *)in->krb5_client_princ;
    if (iVar14 != 0) {
      local_80 = (**(code **)(local_1c0 + -0x53bc))(iVar14);
      local_7c = 4;
      local_78 = iVar14;
    }
    iVar14 = *(int *)(in->krb5_client_princ + 0x60);
    if (iVar14 != 0) {
      local_70 = (**(code **)(local_1c0 + -0x53bc))(iVar14);
      local_6c = 4;
      local_68 = iVar14;
    }
    local_1b0 = &local_150;
    iVar14 = (**(code **)(local_1c0 + -0x6a04))(unaff_s3,0);
    local_1a8 = &local_120;
    iVar5 = (**(code **)(local_1c0 + -0x6a04))(unaff_s4,0);
    local_1ac = &local_130;
    iVar6 = (**(code **)(local_1c0 + -0x6a00))(&local_150,0);
    iVar7 = (**(code **)(local_1c0 + -0x6a00))(&local_120,0);
    iVar8 = (**(code **)(local_1c0 + -0x6a00))(&local_130,0);
    unaff_s0 = (undefined4 ****)(iVar14 + iVar5 + iVar6 + iVar7 + iVar8);
    if (in->key_arg_length != 0) {
      iVar14 = (**(code **)(local_1c0 + -0x6a00))(&local_100,0);
      unaff_s0 = (undefined4 ****)((int)unaff_s0 + iVar14);
    }
    pcVar19 = *(code **)(local_1c0 + -0x6a04);
    if (*(int *)(in->krb5_client_princ + 0x1c) == 0) {
      local_188 = 0;
      if (*(int *)(in->krb5_client_princ + 0x18) != 0) goto LAB_004b75d4;
LAB_004b6f98:
      local_17c = 0;
    }
    else {
      local_188 = (*pcVar19)(&local_f0,0);
      iVar14 = (**(code **)(local_1c0 + -0x69fc))(1,local_188,1);
      unaff_s0 = (undefined4 ****)((int)unaff_s0 + iVar14);
      if (*(int *)(in->krb5_client_princ + 0x18) == 0) goto LAB_004b6f98;
      pcVar19 = *(code **)(local_1c0 + -0x6a04);
LAB_004b75d4:
      local_17c = (*pcVar19)(&local_e0,0);
      iVar14 = (**(code **)(local_1c0 + -0x69fc))(1,local_17c,2);
      unaff_s0 = (undefined4 ****)((int)unaff_s0 + iVar14);
    }
    if (*(int *)(in->krb5_client_princ + 0xc) == 0) {
      local_190 = 0;
    }
    else {
      local_190 = (**(code **)(local_1c0 + -0x76f8))(*(int *)(in->krb5_client_princ + 0xc),0);
      iVar14 = (**(code **)(local_1c0 + -0x69fc))(1,local_190,3);
      unaff_s0 = (undefined4 ****)((int)unaff_s0 + iVar14);
    }
    local_1a4 = &local_110;
    unaff_s5 = (**(code **)(local_1c0 + -0x6a00))(local_1a4,0);
    iVar14 = (**(code **)(local_1c0 + -0x69fc))(1,unaff_s5,4);
    unaff_s7 = (undefined4 ****)((int)unaff_s0 + iVar14);
    if (*(int *)(in->krb5_client_princ + 0x10) == 0) {
      local_184 = 0;
    }
    else {
      local_184 = (**(code **)(local_1c0 + -0x6a04))(&local_d0,0);
      iVar14 = (**(code **)(local_1c0 + -0x69fc))(1,local_184,5);
      unaff_s7 = (undefined4 ****)((int)unaff_s7 + iVar14);
    }
    if (*(int *)(in->krb5_client_princ + 0x5c) < 1) {
      local_18c = 0;
      if (*(int *)(in->krb5_client_princ + 0x54) != 0) goto LAB_004b7060;
LAB_004b74e8:
      unaff_s8 = 0;
      if (*(int *)(in->krb5_client_princ + 0x40) != 0) goto LAB_004b709c;
LAB_004b74f4:
      local_1a0 = 0;
      if (*(int *)(in->krb5_client_princ + 0x20) == 0) goto LAB_004b70d8;
LAB_004b7500:
      local_180 = (**(code **)(local_1c0 + -0x6a00))(&local_140,0);
      iVar14 = (**(code **)(local_1c0 + -0x69fc))(1,local_180,0xb);
      unaff_s7 = (undefined4 ****)((int)unaff_s7 + iVar14);
      if (in->krb5_client_princ_len != 0) goto LAB_004b70e4;
LAB_004b753c:
      local_19c = 0;
      if (*(int *)in->krb5_client_princ != 0) goto LAB_004b7120;
LAB_004b7548:
      local_198 = 0;
      if (*(int *)(in->krb5_client_princ + 0x60) != 0) goto LAB_004b715c;
LAB_004b7554:
      local_194 = 0;
    }
    else {
      local_18c = (**(code **)(local_1c0 + -0x6a04))(&local_b0,0);
      iVar14 = (**(code **)(local_1c0 + -0x69fc))(1,local_18c,9);
      unaff_s7 = (undefined4 ****)((int)unaff_s7 + iVar14);
      if (*(int *)(in->krb5_client_princ + 0x54) == 0) goto LAB_004b74e8;
LAB_004b7060:
      unaff_s8 = (**(code **)(local_1c0 + -0x6a00))(&local_a0,0);
      iVar14 = (**(code **)(local_1c0 + -0x69fc))(1,unaff_s8,10);
      unaff_s7 = (undefined4 ****)((int)unaff_s7 + iVar14);
      if (*(int *)(in->krb5_client_princ + 0x40) == 0) goto LAB_004b74f4;
LAB_004b709c:
      local_1a0 = (**(code **)(local_1c0 + -0x6a00))(&local_c0,0);
      iVar14 = (**(code **)(local_1c0 + -0x69fc))(1,local_1a0,6);
      unaff_s7 = (undefined4 ****)((int)unaff_s7 + iVar14);
      if (*(int *)(in->krb5_client_princ + 0x20) != 0) goto LAB_004b7500;
LAB_004b70d8:
      local_180 = 0;
      if (in->krb5_client_princ_len == 0) goto LAB_004b753c;
LAB_004b70e4:
      local_19c = (**(code **)(local_1c0 + -0x6a00))(&local_90,0);
      iVar14 = (**(code **)(local_1c0 + -0x69fc))(1,local_19c,7);
      unaff_s7 = (undefined4 ****)((int)unaff_s7 + iVar14);
      if (*(int *)in->krb5_client_princ == 0) goto LAB_004b7548;
LAB_004b7120:
      local_198 = (**(code **)(local_1c0 + -0x6a00))(&local_80,0);
      iVar14 = (**(code **)(local_1c0 + -0x69fc))(1,local_198,8);
      unaff_s7 = (undefined4 ****)((int)unaff_s7 + iVar14);
      if (*(int *)(in->krb5_client_princ + 0x60) == 0) goto LAB_004b7554;
LAB_004b715c:
      local_194 = (**(code **)(local_1c0 + -0x6a00))(&local_70,0);
      iVar14 = (**(code **)(local_1c0 + -0x69fc))(1,local_194,0xc);
      unaff_s7 = (undefined4 ****)((int)unaff_s7 + iVar14);
    }
    in_a2 = 0x10;
    ppppuVar12 = unaff_s7;
    local_1b4 = (**(code **)(local_1c0 + -0x69fc))(1);
    iVar14 = local_1b4;
    if (pp != (uchar **)0x0) {
      local_174 = (undefined4 ***)*pp;
      unaff_s0 = &local_174;
      local_1c8 = 0;
      (**(code **)(local_1c0 + -0x69f8))(unaff_s0,1,unaff_s7,0x10);
      (**(code **)(local_1c0 + -0x6a04))(unaff_s3,unaff_s0);
      (**(code **)(local_1c0 + -0x6a04))(unaff_s4,unaff_s0);
      (**(code **)(local_1c0 + -0x6a00))(local_1b0,unaff_s0);
      (**(code **)(local_1c0 + -0x6a00))(local_1a8,unaff_s0);
      (**(code **)(local_1c0 + -0x6a00))(local_1ac,unaff_s0);
      pppuVar9 = local_174;
      if (in->key_arg_length != 0) {
        (**(code **)(local_1c0 + -0x6a00))(&local_100,unaff_s0);
        *(byte *)pppuVar9 = *(byte *)pppuVar9 & 0x20 | 0x80;
      }
      if (*(int *)(in->krb5_client_princ + 0x1c) == 0) {
        iVar14 = *(int *)(in->krb5_client_princ + 0x18);
      }
      else {
        local_1c8 = 0x80;
        (**(code **)(local_1c0 + -0x69f8))(unaff_s0,1,local_188,1);
        (**(code **)(local_1c0 + -0x6a04))(&local_f0,unaff_s0);
        iVar14 = *(int *)(in->krb5_client_princ + 0x18);
      }
      if (iVar14 != 0) {
        local_1c8 = 0x80;
        (**(code **)(local_1c0 + -0x69f8))(unaff_s0,1,local_17c,2);
        (**(code **)(local_1c0 + -0x6a04))(&local_e0,unaff_s0);
      }
      if (*(int *)(in->krb5_client_princ + 0xc) != 0) {
        local_1c8 = 0x80;
        (**(code **)(local_1c0 + -0x69f8))(unaff_s0,1,local_190,3);
        (**(code **)(local_1c0 + -0x76f8))(*(undefined4 *)(in->krb5_client_princ + 0xc),unaff_s0);
      }
      unaff_s3 = (undefined4 *)&DAT_00000080;
      local_1c8 = 0x80;
      in_a2 = unaff_s5;
      (**(code **)(local_1c0 + -0x69f8))(unaff_s0,1,unaff_s5,4);
      ppppuVar12 = unaff_s0;
      (**(code **)(local_1c0 + -0x6a00))(local_1a4);
      if (*(int *)(in->krb5_client_princ + 0x10) != 0) {
        local_1c8 = 0x80;
        in_a2 = local_184;
        (**(code **)(local_1c0 + -0x69f8))(unaff_s0,1,local_184,5);
        ppppuVar12 = unaff_s0;
        (**(code **)(local_1c0 + -0x6a04))(&local_d0);
      }
      if (*(int *)(in->krb5_client_princ + 0x40) != 0) {
        local_1c8 = 0x80;
        in_a2 = local_1a0;
        (**(code **)(local_1c0 + -0x69f8))(unaff_s0,1,local_1a0,6);
        ppppuVar12 = unaff_s0;
        (**(code **)(local_1c0 + -0x6a00))(&local_c0);
      }
      if (in->krb5_client_princ_len != 0) {
        local_1c8 = 0x80;
        in_a2 = local_19c;
        (**(code **)(local_1c0 + -0x69f8))(unaff_s0,1,local_19c,7);
        ppppuVar12 = unaff_s0;
        (**(code **)(local_1c0 + -0x6a00))(&local_90);
      }
      if (*(int *)in->krb5_client_princ != 0) {
        local_1c8 = 0x80;
        in_a2 = local_198;
        (**(code **)(local_1c0 + -0x69f8))(unaff_s0,1,local_198,8);
        ppppuVar12 = unaff_s0;
        (**(code **)(local_1c0 + -0x6a00))(&local_80);
      }
      if (0 < *(int *)(in->krb5_client_princ + 0x5c)) {
        local_1c8 = 0x80;
        in_a2 = local_18c;
        (**(code **)(local_1c0 + -0x69f8))(unaff_s0,1,local_18c,9);
        ppppuVar12 = unaff_s0;
        (**(code **)(local_1c0 + -0x6a04))(&local_b0);
      }
      if (*(int *)(in->krb5_client_princ + 0x54) != 0) {
        local_1c8 = 0x80;
        in_a2 = unaff_s8;
        (**(code **)(local_1c0 + -0x69f8))(unaff_s0,1,unaff_s8,10);
        ppppuVar12 = unaff_s0;
        (**(code **)(local_1c0 + -0x6a00))(&local_a0);
      }
      if (*(int *)(in->krb5_client_princ + 0x20) != 0) {
        local_1c8 = 0x80;
        in_a2 = local_180;
        (**(code **)(local_1c0 + -0x69f8))(unaff_s0,1,local_180,0xb);
        ppppuVar12 = unaff_s0;
        (**(code **)(local_1c0 + -0x6a00))(&local_140);
      }
      if (*(int *)(in->krb5_client_princ + 0x60) != 0) {
        local_1c8 = 0x80;
        in_a2 = local_194;
        (**(code **)(local_1c0 + -0x69f8))(unaff_s0,1,local_194,0xc);
        ppppuVar12 = unaff_s0;
        (**(code **)(local_1c0 + -0x6a00))(&local_70);
      }
      *pp = (uchar *)local_174;
      iVar14 = local_1b4;
    }
  }
  if (local_2c == (SSL_SESSION **)*ppppbVar17) {
    return iVar14;
  }
  pcStack_1dc = d2i_SSL_SESSION;
  ppSVar11 = local_2c;
  (**(code **)(local_1c0 + -0x5330))();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  pppuVar9 = *ppppuVar12;
  puStack_1fc = (undefined *)ppppbVar17;
  uStack_228 = 0x3a;
  iStack_204 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pppuStack_210 = pppuVar9;
  ppppuStack_20c = ppppuVar12;
  ppppuStack_200 = unaff_s0;
  puStack_1f4 = unaff_s3;
  puStack_1f0 = unaff_s4;
  iStack_1ec = unaff_s5;
  ppppuStack_1e4 = unaff_s7;
  iStack_1e0 = unaff_s8;
  aiStack_1d0[0] = in_a2;
  if ((ppSVar11 == (SSL_SESSION **)0x0) || (pSVar16 = *ppSVar11, pSVar16 == (SSL_SESSION *)0x0)) {
    pSVar16 = SSL_SESSION_new();
    if (pSVar16 == (SSL_SESSION *)0x0) {
      uStack_208 = 0x184;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x67,uStack_228,"ssl_asn1.c",0x184);
      ppppbVar13 = (byte ****)((int)pppuStack_210 - (int)*ppppuVar12);
      (*(code *)PTR_asn1_add_error_006a83f0)(*ppppuVar12);
      pSVar10 = (SSL_SESSION *)0x0;
      goto LAB_004b7924;
    }
    pppuVar9 = *ppppuVar12;
  }
  puStack_264 = auStack_250;
  ppppuStack_260 = appppbStack_240;
  apppuStack_230[0] = pppuVar9;
  if (aiStack_1d0[0] == 0) {
    pbStack_214 = (byte *)0x0;
    iVar14 = (*(code *)PTR_asn1_GetSequence_006a83ec)(apppuStack_230,aiStack_1d0);
  }
  else {
    pbStack_214 = (byte *)((int)pppuVar9 + aiStack_1d0[0]);
    iVar14 = (*(code *)PTR_asn1_GetSequence_006a83ec)(apppuStack_230,aiStack_1d0);
  }
  if (iVar14 == 0) {
    ppppbVar17 = (byte ****)apppuStack_230;
    uStack_208 = 0x18a;
    goto LAB_004b78c4;
  }
  ppppbVar17 = (byte ****)apppuStack_230;
  pvStack_248 = (void *)0x0;
  auStack_250[0] = 0;
  pppuStack_210 = apppuStack_230[0];
  iVar14 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&puStack_264,ppppbVar17,ppppbStack_218);
  if (iVar14 == 0) {
    uStack_208 = 0x18e;
    goto LAB_004b78c4;
  }
  ppppbStack_218 = (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
  if (pvStack_248 != (void *)0x0) {
    CRYPTO_free(pvStack_248);
    pvStack_248 = (void *)0x0;
    auStack_250[0] = 0;
  }
  pppuStack_210 = apppuStack_230[0];
  iVar14 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&puStack_264,ppppbVar17,ppppbStack_218);
  if (iVar14 == 0) {
    uStack_208 = 0x196;
    goto LAB_004b78c4;
  }
  ppppbStack_218 = (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
  iVar14 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)(puStack_264);
  pSVar16->ssl_version = iVar14;
  if (pvStack_248 != (void *)0x0) {
    CRYPTO_free(pvStack_248);
    pvStack_248 = (void *)0x0;
    auStack_250[0] = 0;
  }
  unaff_s7 = &ppppuStack_260;
  pbStack_238 = (byte *)0x0;
  appppbStack_240[0] = (byte ****)0x0;
  pppuStack_210 = apppuStack_230[0];
  iVar5 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,ppppbVar17,ppppbStack_218);
  puVar2 = PTR_d2i_ASN1_OCTET_STRING_006a83f8;
  if (iVar5 == 0) {
    uStack_208 = 0x1a1;
    goto LAB_004b78c4;
  }
  ppppbStack_218 = (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
  if (iVar14 == 2) {
    if (appppbStack_240[0] != (byte ****)0x3) {
      uStack_228 = 0x89;
      uStack_208 = 0x1a5;
      goto LAB_004b78c4;
    }
    uVar15 = (uint)*pbStack_238 << 0x10 | pbStack_238[2] | 0x2000000 | (uint)pbStack_238[1] << 8;
  }
  else {
    if (((iVar14 >> 8 != 3) && (iVar14 >> 8 != 0xfe)) && (iVar14 != 0x100)) {
      uStack_228 = 0xfe;
      uStack_208 = 0x1b7;
      goto LAB_004b78c4;
    }
    if (appppbStack_240[0] != (byte ****)&SUB_00000002) {
      uStack_228 = 0x89;
      uStack_208 = 0x1b0;
      goto LAB_004b78c4;
    }
    uVar15 = (uint)*pbStack_238 << 8 | pbStack_238[1] | 0x3000000;
  }
  *(undefined4 *)(pSVar16->krb5_client_princ + 0x24) = 0;
  *(uint *)(pSVar16->krb5_client_princ + 0x28) = uVar15;
  pppuStack_210 = apppuStack_230[0];
  iVar14 = (*(code *)puVar2)(unaff_s7,ppppbVar17);
  pppuVar9 = apppuStack_230[0];
  puVar2 = PTR_memcpy_006a9aec;
  if (iVar14 == 0) {
    uStack_208 = 0x1be;
    goto LAB_004b78c4;
  }
  ppppbVar13 = (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
  if (0x20 < (int)appppbStack_240[0]) {
    appppbStack_240[0] = (byte ****)&DAT_00000020;
  }
  pSVar16->session_id_length = (uint)appppbStack_240[0];
  ppppbStack_218 = ppppbVar13;
  (*(code *)puVar2)(pSVar16->session_id,pbStack_238,appppbStack_240[0]);
  pppuStack_210 = pppuVar9;
  iVar14 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,ppppbVar17,ppppbVar13);
  pppuVar9 = apppuStack_230[0];
  pbVar18 = pbStack_238;
  puVar2 = PTR_memcpy_006a9aec;
  if (iVar14 == 0) {
    uStack_208 = 0x1cd;
    goto LAB_004b78c4;
  }
  ppppbVar13 = appppbStack_240[0];
  if (0x30 < (int)appppbStack_240[0]) {
    ppppbVar13 = (byte ****)&DAT_00000030;
  }
  ppppbStack_218 = (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
  pSVar16->master_key_length = (int)ppppbVar13;
  (*(code *)puVar2)(pSVar16->master_key,pbStack_238,ppppbVar13);
  puVar2 = PTR_d2i_ASN1_OCTET_STRING_006a83f8;
  appppbStack_240[0] = (byte ****)0x0;
  if (ppppbStack_218 == (byte ****)0x0) {
LAB_004b7ca0:
    ppppbVar13 = (byte ****)0x0;
  }
  else {
    bVar1 = *(byte *)pppuVar9;
    if ((bVar1 & 0xdf) != 0x80) goto LAB_004b7ca0;
    *(byte *)pppuVar9 = bVar1 & 0x20 | 4;
    pppuStack_210 = apppuStack_230[0];
    iVar14 = (*(code *)puVar2)(unaff_s7,ppppbVar17,ppppbStack_218);
    if (iVar14 == 0) {
      uStack_208 = 0x1e7;
      *(byte *)pppuStack_210 = bVar1;
      goto LAB_004b78c4;
    }
    ppppbStack_218 =
         (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
    *(byte *)pppuStack_210 = bVar1;
    ppppbVar13 = appppbStack_240[0];
    pbVar18 = pbStack_238;
    if (8 < (int)appppbStack_240[0]) {
      ppppbVar13 = (byte ****)&DAT_00000008;
    }
  }
  puVar2 = PTR_memcpy_006a9aec;
  pSVar16->key_arg_length = (uint)ppppbVar13;
  (*(code *)puVar2)(pSVar16->key_arg,pbVar18);
  if (pbStack_238 != (byte *)0x0) {
    CRYPTO_free(pbStack_238);
  }
  auStack_250[0] = 0;
  if ((ppppbStack_218 != (byte ****)0x0) && (*(byte *)apppuStack_230[0] == 0xa1)) {
    pppuStack_210 = apppuStack_230[0];
    uVar15 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                       (ppppbVar17,&ppppbStack_254,auStack_25c,auStack_258,ppppbStack_218);
    if ((uVar15 & 0x80) != 0) {
      uStack_228 = 0x3b;
      uStack_208 = 0x1f1;
      goto LAB_004b78c4;
    }
    if (uVar15 == 0x21) {
      ppppbStack_254 =
           (byte ****)((int)ppppbStack_218 + (-2 - ((int)apppuStack_230[0] - (int)pppuStack_210)));
      iVar14 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&puStack_264,ppppbVar17,ppppbStack_254);
      if (iVar14 != 0) {
        ppppbStack_254 =
             (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
        iVar14 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(ppppbVar17,ppppbStack_254);
        if (iVar14 != 0) goto LAB_004b83b8;
        uStack_228 = 0x3f;
      }
    }
    else {
      iVar14 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&puStack_264,ppppbVar17,ppppbStack_254);
      if (iVar14 != 0) {
LAB_004b83b8:
        ppppbStack_218 =
             (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
        goto LAB_004b7cf4;
      }
    }
    uStack_208 = 0x1f1;
    goto LAB_004b78c4;
  }
LAB_004b7cf4:
  if (pvStack_248 == (void *)0x0) {
    uVar4 = (*(code *)PTR_time_006a9adc)(0);
    *(undefined4 *)(pSVar16->krb5_client_princ + 0x1c) = uVar4;
  }
  else {
    uVar4 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)(puStack_264);
    *(undefined4 *)(pSVar16->krb5_client_princ + 0x1c) = uVar4;
    CRYPTO_free(pvStack_248);
    pvStack_248 = (void *)0x0;
  }
  auStack_250[0] = 0;
  if ((ppppbStack_218 != (byte ****)0x0) && (*(byte *)apppuStack_230[0] == 0xa2)) {
    pppuStack_210 = apppuStack_230[0];
    uVar15 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                       (ppppbVar17,&ppppbStack_254,auStack_25c,auStack_258,ppppbStack_218);
    if ((uVar15 & 0x80) != 0) {
      uStack_228 = 0x3b;
      uStack_208 = 0x1fb;
      goto LAB_004b78c4;
    }
    if (uVar15 == 0x21) {
      ppppbStack_254 =
           (byte ****)((int)ppppbStack_218 + (-2 - ((int)apppuStack_230[0] - (int)pppuStack_210)));
      iVar14 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&puStack_264,ppppbVar17,ppppbStack_254);
      if (iVar14 != 0) {
        ppppbStack_254 =
             (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
        iVar14 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(ppppbVar17,ppppbStack_254);
        if (iVar14 != 0) goto LAB_004b8378;
        uStack_228 = 0x3f;
      }
    }
    else {
      iVar14 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&puStack_264,ppppbVar17,ppppbStack_254);
      if (iVar14 != 0) {
LAB_004b8378:
        ppppbStack_218 =
             (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
        goto LAB_004b7d44;
      }
    }
    uStack_208 = 0x1fb;
    goto LAB_004b78c4;
  }
LAB_004b7d44:
  if (pvStack_248 == (void *)0x0) {
    *(undefined4 *)(pSVar16->krb5_client_princ + 0x18) = 3;
  }
  else {
    uVar4 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)(puStack_264);
    *(undefined4 *)(pSVar16->krb5_client_princ + 0x18) = uVar4;
    CRYPTO_free(pvStack_248);
    pvStack_248 = (void *)0x0;
    auStack_250[0] = 0;
  }
  if (*(int *)(pSVar16->krb5_client_princ + 0xc) != 0) {
    (*(code *)PTR_X509_free_006a6e90)();
    *(undefined4 *)(pSVar16->krb5_client_princ + 0xc) = 0;
  }
  if (ppppbStack_218 == (byte ****)0x0) {
    appppbStack_240[0] = (byte ****)0x0;
    pbStack_238 = (byte *)0x0;
LAB_004b7dcc:
    pSVar16->sid_ctx_length = 0;
  }
  else {
    if (*(byte *)apppuStack_230[0] != 0xa3) {
LAB_004b7dbc:
      pbStack_238 = (byte *)0x0;
      appppbStack_240[0] = (byte ****)0x0;
      if (*(byte *)apppuStack_230[0] == 0xa4) {
        pppuStack_210 = apppuStack_230[0];
        uVar15 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                           (ppppbVar17,&ppppbStack_254,auStack_25c,auStack_258,ppppbStack_218);
        if ((uVar15 & 0x80) != 0) {
          uStack_228 = 0x3b;
          uStack_208 = 0x20c;
          goto LAB_004b78c4;
        }
        if (uVar15 == 0x21) {
          ppppbStack_254 =
               (byte ****)
               ((int)ppppbStack_218 + (-2 - ((int)apppuStack_230[0] - (int)pppuStack_210)));
          iVar14 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,ppppbVar17,ppppbStack_254)
          ;
          if (iVar14 != 0) {
            ppppbStack_254 =
                 (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
            iVar14 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)
                               (ppppbVar17,ppppbStack_254);
            if (iVar14 != 0) goto LAB_004b83f8;
            uStack_228 = 0x3f;
          }
        }
        else {
          iVar14 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,ppppbVar17,ppppbStack_254)
          ;
          if (iVar14 != 0) {
LAB_004b83f8:
            pbVar18 = pbStack_238;
            puVar2 = PTR_memcpy_006a9aec;
            ppppbStack_218 =
                 (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
            if (pbStack_238 != (byte *)0x0) {
              if (0x20 < (int)appppbStack_240[0]) {
                uStack_228 = 0x10f;
                uStack_208 = 0x211;
                goto LAB_004b78c4;
              }
              pSVar16->sid_ctx_length = (uint)appppbStack_240[0];
              (*(code *)puVar2)(pSVar16->sid_ctx,pbStack_238);
              CRYPTO_free(pbVar18);
              pbStack_238 = (byte *)0x0;
              appppbStack_240[0] = (byte ****)0x0;
              goto LAB_004b7dd0;
            }
            goto LAB_004b7dcc;
          }
        }
        uStack_208 = 0x20c;
        goto LAB_004b78c4;
      }
      goto LAB_004b7dcc;
    }
    pppuStack_210 = apppuStack_230[0];
    uVar15 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                       (ppppbVar17,&ppppbStack_254,auStack_25c,auStack_258,ppppbStack_218);
    if ((uVar15 & 0x80) != 0) {
      uStack_228 = 0x3b;
      uStack_208 = 0x208;
      goto LAB_004b78c4;
    }
    if (uVar15 == 0x21) {
      ppppbStack_254 =
           (byte ****)((int)ppppbStack_218 + (-2 - ((int)apppuStack_230[0] - (int)pppuStack_210)));
      iVar14 = (*(code *)PTR_d2i_X509_006a7fe0)
                         (pSVar16->krb5_client_princ + 0xc,ppppbVar17,ppppbStack_254);
      if (iVar14 != 0) {
        ppppbStack_254 =
             (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
        iVar14 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(ppppbVar17,ppppbStack_254);
        if (iVar14 != 0) goto LAB_004b8324;
        uStack_228 = 0x3f;
      }
LAB_004b8acc:
      uStack_208 = 0x208;
      goto LAB_004b78c4;
    }
    iVar14 = (*(code *)PTR_d2i_X509_006a7fe0)
                       (pSVar16->krb5_client_princ + 0xc,ppppbVar17,ppppbStack_254);
    if (iVar14 == 0) goto LAB_004b8acc;
LAB_004b8324:
    appppbStack_240[0] = (byte ****)0x0;
    pbStack_238 = (byte *)0x0;
    ppppbStack_218 =
         (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
    if (ppppbStack_218 != (byte ****)0x0) goto LAB_004b7dbc;
    pSVar16->sid_ctx_length = 0;
  }
LAB_004b7dd0:
  auStack_250[0] = 0;
  if ((ppppbStack_218 != (byte ****)0x0) && (*(byte *)apppuStack_230[0] == 0xa5)) {
    pppuStack_210 = apppuStack_230[0];
    uVar15 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                       (ppppbVar17,&ppppbStack_254,auStack_25c,auStack_258,ppppbStack_218);
    if ((uVar15 & 0x80) != 0) {
      uStack_228 = 0x3b;
      uStack_208 = 0x21e;
      goto LAB_004b78c4;
    }
    if (uVar15 == 0x21) {
      ppppbStack_254 =
           (byte ****)((int)ppppbStack_218 + (-2 - ((int)apppuStack_230[0] - (int)pppuStack_210)));
      iVar14 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&puStack_264,ppppbVar17,ppppbStack_254);
      if (iVar14 != 0) {
        ppppbStack_254 =
             (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
        iVar14 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(ppppbVar17,ppppbStack_254);
        if (iVar14 != 0) goto LAB_004b891c;
        uStack_228 = 0x3f;
      }
    }
    else {
      iVar14 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&puStack_264,ppppbVar17,ppppbStack_254);
      if (iVar14 != 0) {
LAB_004b891c:
        ppppbStack_218 =
             (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
        goto LAB_004b7dec;
      }
    }
    uStack_208 = 0x21e;
    goto LAB_004b78c4;
  }
LAB_004b7dec:
  if (pvStack_248 == (void *)0x0) {
    *(undefined4 *)(pSVar16->krb5_client_princ + 0x10) = 0;
  }
  else {
    uVar4 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)(puStack_264);
    *(undefined4 *)(pSVar16->krb5_client_princ + 0x10) = uVar4;
    CRYPTO_free(pvStack_248);
    pvStack_248 = (void *)0x0;
    auStack_250[0] = 0;
  }
  appppbStack_240[0] = (byte ****)0x0;
  pbStack_238 = (byte *)0x0;
  if ((ppppbStack_218 != (byte ****)0x0) && (*(byte *)apppuStack_230[0] == 0xa6)) {
    pppuStack_210 = apppuStack_230[0];
    uVar15 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                       (ppppbVar17,&ppppbStack_254,auStack_25c,auStack_258,ppppbStack_218);
    if ((uVar15 & 0x80) != 0) {
      uStack_228 = 0x3b;
      uStack_208 = 0x22a;
      goto LAB_004b78c4;
    }
    if (uVar15 == 0x21) {
      ppppbStack_254 =
           (byte ****)((int)ppppbStack_218 + (-2 - ((int)apppuStack_230[0] - (int)pppuStack_210)));
      iVar14 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,ppppbVar17,ppppbStack_254);
      if (iVar14 != 0) {
        ppppbStack_254 =
             (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
        iVar14 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(ppppbVar17,ppppbStack_254);
        if (iVar14 != 0) goto LAB_004b882c;
        uStack_228 = 0x3f;
      }
    }
    else {
      iVar14 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,ppppbVar17,ppppbStack_254);
      if (iVar14 != 0) {
LAB_004b882c:
        ppppbStack_218 =
             (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
        if (pbStack_238 == (byte *)0x0) goto LAB_004b7e34;
        uVar4 = (*(code *)PTR_BUF_strndup_006a7fcc)(pbStack_238,appppbStack_240[0]);
        *(undefined4 *)(pSVar16->krb5_client_princ + 0x40) = uVar4;
        CRYPTO_free(pbStack_238);
        goto LAB_004b7e38;
      }
    }
    uStack_208 = 0x22a;
    goto LAB_004b78c4;
  }
LAB_004b7e34:
  *(undefined4 *)(pSVar16->krb5_client_princ + 0x40) = 0;
LAB_004b7e38:
  appppbStack_240[0] = (byte ****)0x0;
  pbStack_238 = (byte *)0x0;
  if ((ppppbStack_218 != (byte ****)0x0) && (*(byte *)apppuStack_230[0] == 0xa7)) {
    pppuStack_210 = apppuStack_230[0];
    uVar15 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                       (ppppbVar17,&ppppbStack_254,auStack_25c,auStack_258,ppppbStack_218);
    if ((uVar15 & 0x80) != 0) {
      uStack_228 = 0x3b;
      uStack_208 = 0x237;
      goto LAB_004b78c4;
    }
    if (uVar15 == 0x21) {
      ppppbStack_254 =
           (byte ****)((int)ppppbStack_218 + (-2 - ((int)apppuStack_230[0] - (int)pppuStack_210)));
      iVar14 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,ppppbVar17,ppppbStack_254);
      if (iVar14 != 0) {
        ppppbStack_254 =
             (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
        iVar14 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(ppppbVar17,ppppbStack_254);
        if (iVar14 != 0) goto LAB_004b88a4;
        uStack_228 = 0x3f;
      }
    }
    else {
      iVar14 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,ppppbVar17,ppppbStack_254);
      if (iVar14 != 0) {
LAB_004b88a4:
        ppppbStack_218 =
             (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
        if (pbStack_238 == (byte *)0x0) goto LAB_004b7e44;
        uVar15 = (*(code *)PTR_BUF_strndup_006a7fcc)(pbStack_238,appppbStack_240[0]);
        pSVar16->krb5_client_princ_len = uVar15;
        CRYPTO_free(pbStack_238);
        goto LAB_004b7e48;
      }
    }
    uStack_208 = 0x237;
    goto LAB_004b78c4;
  }
LAB_004b7e44:
  pSVar16->krb5_client_princ_len = 0;
LAB_004b7e48:
  appppbStack_240[0] = (byte ****)0x0;
  pbStack_238 = (byte *)0x0;
  if ((ppppbStack_218 != (byte ****)0x0) && (*(byte *)apppuStack_230[0] == 0xa8)) {
    pppuStack_210 = apppuStack_230[0];
    uVar15 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                       (ppppbVar17,&ppppbStack_254,auStack_25c,auStack_258,ppppbStack_218);
    if ((uVar15 & 0x80) != 0) {
      uStack_228 = 0x3b;
      uStack_208 = 0x242;
      goto LAB_004b78c4;
    }
    if (uVar15 == 0x21) {
      ppppbStack_254 =
           (byte ****)((int)ppppbStack_218 + (-2 - ((int)apppuStack_230[0] - (int)pppuStack_210)));
      iVar14 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,ppppbVar17,ppppbStack_254);
      if (iVar14 != 0) {
        ppppbStack_254 =
             (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
        iVar14 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(ppppbVar17,ppppbStack_254);
        if (iVar14 != 0) goto LAB_004b8738;
        uStack_228 = 0x3f;
      }
    }
    else {
      iVar14 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,ppppbVar17,ppppbStack_254);
      if (iVar14 != 0) {
LAB_004b8738:
        ppppbStack_218 =
             (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
        if (pbStack_238 == (byte *)0x0) goto LAB_004b7e54;
        uVar4 = (*(code *)PTR_BUF_strndup_006a7fcc)(pbStack_238,appppbStack_240[0]);
        *(undefined4 *)pSVar16->krb5_client_princ = uVar4;
        CRYPTO_free(pbStack_238);
        pbStack_238 = (byte *)0x0;
        appppbStack_240[0] = (byte ****)0x0;
        goto LAB_004b7e58;
      }
    }
    uStack_208 = 0x242;
    goto LAB_004b78c4;
  }
LAB_004b7e54:
  *(undefined4 *)pSVar16->krb5_client_princ = 0;
LAB_004b7e58:
  auStack_250[0] = 0;
  if ((ppppbStack_218 != (byte ****)0x0) && (*(byte *)apppuStack_230[0] == 0xa9)) {
    pppuStack_210 = apppuStack_230[0];
    uVar15 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                       (ppppbVar17,&ppppbStack_254,auStack_25c,auStack_258,ppppbStack_218);
    if ((uVar15 & 0x80) != 0) {
      uStack_228 = 0x3b;
      uStack_208 = 0x24e;
      goto LAB_004b78c4;
    }
    if (uVar15 == 0x21) {
      ppppbStack_254 =
           (byte ****)((int)ppppbStack_218 + (-2 - ((int)apppuStack_230[0] - (int)pppuStack_210)));
      iVar14 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&puStack_264,ppppbVar17,ppppbStack_254);
      if (iVar14 != 0) {
        ppppbStack_254 =
             (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
        iVar14 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(ppppbVar17,ppppbStack_254);
        if (iVar14 != 0) goto LAB_004b89e8;
        uStack_228 = 0x3f;
      }
    }
    else {
      iVar14 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&puStack_264,ppppbVar17,ppppbStack_254);
      if (iVar14 != 0) {
LAB_004b89e8:
        ppppbStack_218 =
             (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
        goto LAB_004b7e74;
      }
    }
    uStack_208 = 0x24e;
    goto LAB_004b78c4;
  }
LAB_004b7e74:
  if (pvStack_248 == (void *)0x0) {
    if ((*(int *)(pSVar16->krb5_client_princ + 0x58) == 0) || (pSVar16->session_id_length == 0)) {
      *(undefined4 *)(pSVar16->krb5_client_princ + 0x5c) = 0;
    }
    else {
      *(undefined4 *)(pSVar16->krb5_client_princ + 0x5c) = 0xffffffff;
    }
  }
  else {
    uVar4 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)(puStack_264);
    *(undefined4 *)(pSVar16->krb5_client_princ + 0x5c) = uVar4;
    CRYPTO_free(pvStack_248);
    pvStack_248 = (void *)0x0;
    auStack_250[0] = 0;
  }
  appppbStack_240[0] = (byte ****)0x0;
  pbStack_238 = (byte *)0x0;
  if (ppppbStack_218 == (byte ****)0x0) {
    *(undefined4 *)(pSVar16->krb5_client_princ + 0x54) = 0;
    appppbStack_240[0] = (byte ****)0x0;
    pbStack_238 = (byte *)0x0;
    ppppbVar13 = ppppbStack_218;
    goto LAB_004b7f04;
  }
  if (*(byte *)apppuStack_230[0] != 0xaa) {
    *(undefined4 *)(pSVar16->krb5_client_princ + 0x54) = 0;
    goto LAB_004b7edc;
  }
  pppuStack_210 = apppuStack_230[0];
  uVar15 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                     (ppppbVar17,&ppppbStack_254,auStack_25c,auStack_258,ppppbStack_218);
  if ((uVar15 & 0x80) != 0) {
    uStack_228 = 0x3b;
    uStack_208 = 0x25a;
    goto LAB_004b78c4;
  }
  if (uVar15 == 0x21) {
    ppppbStack_254 =
         (byte ****)((int)ppppbStack_218 + (-2 - ((int)apppuStack_230[0] - (int)pppuStack_210)));
    iVar14 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,ppppbVar17,ppppbStack_254);
    if (iVar14 != 0) {
      ppppbStack_254 =
           (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
      iVar14 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(ppppbVar17,ppppbStack_254);
      if (iVar14 != 0) goto LAB_004b85b8;
      uStack_228 = 0x3f;
    }
  }
  else {
    iVar14 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,ppppbVar17,ppppbStack_254);
    if (iVar14 != 0) {
LAB_004b85b8:
      ppppbStack_218 =
           (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
      if (pbStack_238 != (byte *)0x0) {
        *(byte *****)(pSVar16->krb5_client_princ + 0x58) = appppbStack_240[0];
      }
      *(byte **)(pSVar16->krb5_client_princ + 0x54) = pbStack_238;
      if (ppppbStack_218 == (byte ****)0x0) {
        appppbStack_240[0] = (byte ****)0x0;
        pbStack_238 = (byte *)0x0;
        ppppbVar13 = ppppbStack_218;
        goto LAB_004b7f04;
      }
LAB_004b7edc:
      pbStack_238 = (byte *)0x0;
      appppbStack_240[0] = (byte ****)0x0;
      pppuVar9 = apppuStack_230[0];
      ppppbVar13 = ppppbStack_218;
      pcVar19 = (code *)PTR_ASN1_get_object_006a7fb0;
      if (*(byte *)apppuStack_230[0] == 0xab) goto LAB_004b8514;
      goto LAB_004b7ef4;
    }
  }
  uStack_208 = 0x25a;
LAB_004b78c4:
  do {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x67,uStack_228,"ssl_asn1.c",uStack_208);
    ppppbVar13 = (byte ****)((int)pppuStack_210 - (int)*ppppuVar12);
    (*(code *)PTR_asn1_add_error_006a83f0)(*ppppuVar12);
    if ((ppSVar11 == (SSL_SESSION **)0x0) || (pSVar10 = (SSL_SESSION *)0x0, pSVar16 != *ppSVar11)) {
      SSL_SESSION_free(pSVar16);
      pSVar10 = (SSL_SESSION *)0x0;
    }
LAB_004b7924:
    if (iStack_204 == *(int *)puVar3) {
      return (int)pSVar10;
    }
    pcVar19 = (code *)PTR___stack_chk_fail_006a9ab0;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    pppuVar9 = extraout_v1;
LAB_004b8514:
    pppuStack_210 = pppuVar9;
    uVar15 = (*pcVar19)(ppppbVar17,&ppppbStack_254,auStack_25c,auStack_258,ppppbVar13);
    if ((uVar15 & 0x80) != 0) {
      uStack_228 = 0x3b;
      uStack_208 = 0x266;
      goto LAB_004b78c4;
    }
    if (uVar15 == 0x21) {
      ppppbStack_254 =
           (byte ****)((int)ppppbStack_218 + (-2 - ((int)apppuStack_230[0] - (int)pppuStack_210)));
      iVar14 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,ppppbVar17,ppppbStack_254);
      if (iVar14 != 0) {
        ppppbStack_254 =
             (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
        iVar14 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(ppppbVar17,ppppbStack_254);
        if (iVar14 != 0) goto LAB_004b8620;
        uStack_228 = 0x3f;
      }
LAB_004b8d78:
      uStack_208 = 0x266;
      goto LAB_004b78c4;
    }
    iVar14 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,ppppbVar17,ppppbStack_254);
    if (iVar14 == 0) goto LAB_004b8d78;
LAB_004b8620:
    ppppbStack_218 =
         (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
    if (pbStack_238 != (byte *)0x0) {
      *(uint *)(pSVar16->krb5_client_princ + 0x20) = (uint)*pbStack_238;
      CRYPTO_free(pbStack_238);
    }
    appppbStack_240[0] = (byte ****)0x0;
    pbStack_238 = (byte *)0x0;
    ppppbVar13 = ppppbStack_218;
    if (ppppbStack_218 == (byte ****)0x0) {
LAB_004b7f04:
      *(undefined4 *)(pSVar16->krb5_client_princ + 0x60) = 0;
      pSVar10 = pSVar16;
    }
    else {
LAB_004b7ef4:
      pbStack_238 = (byte *)0x0;
      appppbStack_240[0] = (byte ****)0x0;
      ppppbVar13 = ppppbStack_218;
      if (*(byte *)apppuStack_230[0] != 0xac) goto LAB_004b7f04;
      pppuStack_210 = apppuStack_230[0];
      uVar15 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                         (ppppbVar17,&ppppbStack_254,auStack_25c,auStack_258,ppppbStack_218);
      if ((uVar15 & 0x80) != 0) {
        uStack_228 = 0x3b;
        uStack_208 = 0x271;
        goto LAB_004b78c4;
      }
      if (uVar15 == 0x21) {
        ppppbStack_254 =
             (byte ****)((int)ppppbStack_218 + (-2 - ((int)apppuStack_230[0] - (int)pppuStack_210)))
        ;
        iVar14 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,ppppbVar17,ppppbStack_254);
        if (iVar14 != 0) {
          ppppbVar13 = (byte ****)
                       ((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
          ppppbStack_254 = ppppbVar13;
          iVar14 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(ppppbVar17);
          if (iVar14 != 0) goto LAB_004b87b8;
          uStack_228 = 0x3f;
        }
LAB_004b8eec:
        uStack_208 = 0x271;
        goto LAB_004b78c4;
      }
      ppppbVar13 = ppppbVar17;
      iVar14 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,ppppbVar17,ppppbStack_254);
      if (iVar14 == 0) goto LAB_004b8eec;
LAB_004b87b8:
      ppppbStack_218 =
           (byte ****)((int)ppppbStack_218 - ((int)apppuStack_230[0] - (int)pppuStack_210));
      if (pbStack_238 == (byte *)0x0) goto LAB_004b7f04;
      ppppbVar13 = appppbStack_240[0];
      uVar4 = (*(code *)PTR_BUF_strndup_006a7fcc)();
      *(undefined4 *)(pSVar16->krb5_client_princ + 0x60) = uVar4;
      CRYPTO_free(pbStack_238);
      pbStack_238 = (byte *)0x0;
      appppbStack_240[0] = (byte ****)0x0;
      pSVar10 = pSVar16;
    }
    iVar14 = (*(code *)PTR_asn1_const_Finish_006a83fc)(ppppbVar17);
    pSVar16 = pSVar10;
    if (iVar14 != 0) {
      *ppppuVar12 = apppuStack_230[0];
      if (ppSVar11 != (SSL_SESSION **)0x0) {
        *ppSVar11 = pSVar10;
      }
      goto LAB_004b7924;
    }
    uStack_208 = 0x27b;
  } while( true );
}

