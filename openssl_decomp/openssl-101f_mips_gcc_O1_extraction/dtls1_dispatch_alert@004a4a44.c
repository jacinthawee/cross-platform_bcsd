
uint * dtls1_dispatch_alert(undefined4 *param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  undefined *puVar9;
  undefined4 uVar10;
  int iVar11;
  undefined *puVar12;
  undefined *puVar13;
  code *pcVar14;
  int iVar15;
  undefined local_30;
  undefined local_2f;
  undefined *local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar11 = param_1[0x16];
  *(undefined4 *)(iVar11 + 0x18c) = 0;
  local_30 = *(undefined *)(iVar11 + 400);
  puVar9 = *(undefined **)puVar1;
  local_2f = *(undefined *)(iVar11 + 0x191);
  local_2c = puVar9;
  if (*(int *)(iVar11 + 0x108) == 0) {
    if (((param_1[0x30] == 0) || (param_1[0x23] == 0)) ||
       (iVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(param_1[0x24]), iVar2 == 0)) {
      iVar2 = 0;
LAB_004a4b00:
      puVar12 = *(undefined **)(iVar11 + 0xfc);
      *puVar12 = 0x15;
      uVar3 = *param_1;
      *(undefined4 *)(iVar11 + 0x130) = 0x15;
      puVar12[1] = (char)((uint)uVar3 >> 8);
      puVar12[2] = (char)*param_1;
      puVar13 = puVar12 + 0xd;
      if (((undefined4 *)param_1[0x23] == (undefined4 *)0x0) ||
         (uVar4 = (*(code *)PTR_EVP_CIPHER_flags_006a9270)(*(undefined4 *)param_1[0x23]),
         (uVar4 & 2) == 0)) {
        iVar7 = param_1[0x25];
        *(undefined **)(iVar11 + 0x140) = &local_30;
        iVar15 = 0;
        *(undefined4 *)(iVar11 + 0x134) = 2;
        *(undefined **)(iVar11 + 0x13c) = puVar13;
        puVar9 = puVar13;
        if (iVar7 != 0) goto LAB_004a4b70;
LAB_004a4e24:
        *puVar9 = local_30;
        puVar9[1] = local_2f;
        *(undefined4 *)(iVar11 + 0x140) = *(undefined4 *)(iVar11 + 0x13c);
      }
      else {
        iVar15 = (*(code *)PTR_EVP_CIPHER_block_size_006a921c)(*(undefined4 *)param_1[0x23]);
        iVar7 = param_1[0x25];
        puVar9 = puVar13 + iVar15;
        *(undefined **)(iVar11 + 0x140) = &local_30;
        *(undefined4 *)(iVar11 + 0x134) = 2;
        *(undefined **)(iVar11 + 0x13c) = puVar9;
        if (iVar7 == 0) goto LAB_004a4e24;
LAB_004a4b70:
        iVar7 = ssl3_do_compress(param_1);
        if (iVar7 == 0) {
          puVar9 = (undefined *)0xf5;
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xf5,0x8d,"d1_pkt.c",0x632);
          goto LAB_004a4e9c;
        }
      }
      if (iVar2 == 0) {
        *(undefined **)(iVar11 + 0x140) = puVar13;
        *(undefined **)(iVar11 + 0x13c) = puVar13;
      }
      else {
        puVar9 = puVar13 + iVar15 + *(int *)(iVar11 + 0x134);
        iVar7 = (**(code **)(*(int *)(param_1[2] + 100) + 4))(param_1,puVar9,1);
        if (iVar7 < 0) goto LAB_004a4e9c;
        *(undefined **)(iVar11 + 0x140) = puVar13;
        *(undefined **)(iVar11 + 0x13c) = puVar13;
        *(int *)(iVar11 + 0x134) = *(int *)(iVar11 + 0x134) + iVar2;
      }
      if (iVar15 != 0) {
        (*(code *)PTR_RAND_pseudo_bytes_006a8664)(puVar13,iVar15);
        *(int *)(iVar11 + 0x134) = *(int *)(iVar11 + 0x134) + iVar15;
      }
      (***(code ***)(param_1[2] + 100))(param_1,1);
      puVar12[3] = (char)((ushort)*(undefined2 *)(param_1[0x17] + 0x20a) >> 8);
      puVar12[4] = (char)*(undefined2 *)(param_1[0x17] + 0x20a);
      iVar2 = param_1[0x16];
      uVar8 = *(uint *)(iVar2 + 0x56);
      puVar9 = puVar12 + 5;
      uVar4 = (uint)puVar9 & 3;
      *(uint *)(puVar9 + -uVar4) =
           *(uint *)(puVar9 + -uVar4) & -1 << (4 - uVar4) * 8 | uVar8 >> uVar4 * 8;
      puVar9 = puVar12 + 8;
      uVar4 = (uint)puVar9 & 3;
      *(uint *)(puVar9 + -uVar4) =
           *(uint *)(puVar9 + -uVar4) & 0xffffffffU >> (uVar4 + 1) * 8 | uVar8 << (3 - uVar4) * 8;
      puVar12[9] = *(undefined *)(iVar2 + 0x5a);
      puVar12[10] = *(undefined *)(iVar2 + 0x5b);
      puVar12[0xb] = (char)((uint)*(undefined4 *)(iVar11 + 0x134) >> 8);
      puVar12[0xc] = (char)*(undefined4 *)(iVar11 + 0x134);
      iVar2 = param_1[0x16];
      *(undefined4 *)(iVar11 + 0x130) = 0x15;
      *(int *)(iVar11 + 0x134) = *(int *)(iVar11 + 0x134) + 0xd;
      ssl3_record_sequence_update(iVar2 + 0x54);
      puVar9 = &DAT_00000015;
      iVar2 = param_1[0x16];
      *(undefined4 *)(iVar11 + 0x104) = 0;
      *(undefined4 *)(iVar11 + 0x108) = *(undefined4 *)(iVar11 + 0x134);
      *(undefined4 *)(iVar2 + 0x168) = 2;
      *(undefined **)(iVar2 + 0x174) = &local_30;
      *(undefined4 *)(iVar2 + 0x16c) = 0x15;
      *(undefined4 *)(iVar2 + 0x170) = 2;
      puVar5 = (uint *)ssl3_write_pending(param_1,0x15,&local_30,2);
      goto joined_r0x004a4dd4;
    }
    uVar3 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(param_1[0x24]);
    iVar2 = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar3);
    if (-1 < iVar2) goto LAB_004a4b00;
LAB_004a4e9c:
    puVar5 = (uint *)0xffffffff;
  }
  else {
    OpenSSLDie("d1_pkt.c",0x5cc,"0");
    puVar9 = &DAT_00000015;
    puVar5 = (uint *)ssl3_write_pending(param_1,0x15,&local_30,2);
joined_r0x004a4dd4:
    if (0 < (int)puVar5) {
      if (*(char *)(param_1[0x16] + 400) == '\x02') {
        puVar9 = &DAT_0000000b;
        (*(code *)PTR_BIO_ctrl_006a7f18)(param_1[4],0xb,0,0);
      }
      if ((code *)param_1[0x19] != (code *)0x0) {
        puVar9 = (undefined *)*param_1;
        (*(code *)param_1[0x19])(1,puVar9,0x15,param_1[0x16] + 400,2,param_1,param_1[0x1a]);
      }
      pcVar14 = (code *)param_1[0x34];
      if ((pcVar14 != (code *)0x0) ||
         (pcVar14 = *(code **)(param_1[0x39] + 0x9c), pcVar14 != (code *)0x0)) {
        puVar9 = (undefined *)0x0;
        (*pcVar14)(param_1,0x4008,*(undefined2 *)(param_1[0x16] + 400));
      }
      goto LAB_004a4cf0;
    }
  }
  *(undefined4 *)(param_1[0x16] + 0x18c) = 1;
LAB_004a4cf0:
  if (local_2c == *(undefined **)puVar1) {
    return puVar5;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (((uint)puVar9 & 1) == 0) {
    iVar11 = *(int *)(local_2c + 0x58);
    iVar2 = *(int *)(local_2c + 0x5c);
    puVar6 = (uint *)(iVar11 + 0x54);
    uVar8 = *puVar6;
    uVar3 = *(undefined4 *)(iVar11 + 0x58);
    uVar4 = iVar2 + 0x22aU & 3;
    puVar5 = (uint *)((iVar2 + 0x22aU) - uVar4);
    *puVar5 = *puVar5 & -1 << (4 - uVar4) * 8 | uVar8 >> uVar4 * 8;
    uVar4 = iVar2 + 0x22dU & 3;
    puVar5 = (uint *)((iVar2 + 0x22dU) - uVar4);
    *puVar5 = *puVar5 & 0xffffffffU >> (uVar4 + 1) * 8 | uVar8 << (3 - uVar4) * 8;
    *(undefined4 *)(iVar2 + 0x22e) = uVar3;
    *(short *)(*(int *)(local_2c + 0x5c) + 0x20a) =
         *(short *)(*(int *)(local_2c + 0x5c) + 0x20a) + 1;
    *(undefined *)puVar6 = 0;
    *(undefined *)(iVar11 + 0x55) = 0;
    *(undefined *)(iVar11 + 0x56) = 0;
    *(undefined *)(iVar11 + 0x57) = 0;
    *(undefined *)(iVar11 + 0x58) = 0;
    *(undefined *)(iVar11 + 0x59) = 0;
    *(undefined *)(iVar11 + 0x5a) = 0;
    *(undefined *)(iVar11 + 0x5b) = 0;
    return puVar6;
  }
  iVar2 = *(int *)(local_2c + 0x5c);
  iVar11 = *(int *)(local_2c + 0x58);
  *(short *)(iVar2 + 0x208) = *(short *)(iVar2 + 0x208) + 1;
  uVar8 = *(uint *)(iVar2 + 0x218);
  uVar10 = *(undefined4 *)(iVar2 + 0x21c);
  uVar3 = *(undefined4 *)(iVar2 + 0x220);
  uVar4 = iVar2 + 0x20cU & 3;
  puVar5 = (uint *)((iVar2 + 0x20cU) - uVar4);
  *puVar5 = *puVar5 & -1 << (4 - uVar4) * 8 | uVar8 >> uVar4 * 8;
  uVar4 = iVar2 + 0x20fU & 3;
  puVar5 = (uint *)((iVar2 + 0x20fU) - uVar4);
  *puVar5 = *puVar5 & 0xffffffffU >> (uVar4 + 1) * 8 | uVar8 << (3 - uVar4) * 8;
  *(undefined4 *)(iVar2 + 0x210) = uVar10;
  *(undefined4 *)(iVar2 + 0x214) = uVar3;
  iVar2 = *(int *)(local_2c + 0x5c);
  *(undefined *)(iVar2 + 0x218) = 0;
  *(undefined *)(iVar2 + 0x219) = 0;
  *(undefined *)(iVar2 + 0x21a) = 0;
  *(undefined *)(iVar2 + 0x21b) = 0;
  *(undefined *)(iVar2 + 0x21c) = 0;
  *(undefined *)(iVar2 + 0x21d) = 0;
  *(undefined *)(iVar2 + 0x21e) = 0;
  *(undefined *)(iVar2 + 0x21f) = 0;
  *(undefined *)(iVar2 + 0x220) = 0;
  *(undefined *)(iVar2 + 0x221) = 0;
  *(undefined *)(iVar2 + 0x222) = 0;
  *(undefined *)(iVar2 + 0x223) = 0;
  *(undefined *)(uint *)(iVar11 + 8) = 0;
  *(undefined *)(iVar11 + 9) = 0;
  *(undefined *)(iVar11 + 10) = 0;
  *(undefined *)(iVar11 + 0xb) = 0;
  *(undefined *)(iVar11 + 0xc) = 0;
  *(undefined *)(iVar11 + 0xd) = 0;
  *(undefined *)(iVar11 + 0xe) = 0;
  *(undefined *)(iVar11 + 0xf) = 0;
  return (uint *)(iVar11 + 8);
}

