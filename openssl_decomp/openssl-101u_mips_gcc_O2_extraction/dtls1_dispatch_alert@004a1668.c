
int dtls1_dispatch_alert(undefined4 *param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined4 uVar9;
  int iVar10;
  undefined *puVar11;
  undefined *puVar12;
  code *pcVar13;
  undefined *puVar14;
  undefined local_30;
  undefined local_2f;
  undefined *local_2c;
  
  puVar7 = PTR___stack_chk_guard_006a9ae8;
  iVar10 = param_1[0x16];
  *(undefined4 *)(iVar10 + 0x18c) = 0;
  local_30 = *(undefined *)(iVar10 + 400);
  puVar8 = *(undefined **)puVar7;
  local_2f = *(undefined *)(iVar10 + 0x191);
  local_2c = puVar8;
  if (*(int *)(iVar10 + 0x108) == 0) {
    if (((param_1[0x30] == 0) || (param_1[0x23] == 0)) ||
       (iVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(param_1[0x24]), iVar2 == 0)) {
      iVar2 = 0;
LAB_004a1724:
      puVar11 = *(undefined **)(iVar10 + 0xfc);
      *puVar11 = 0x15;
      uVar3 = *param_1;
      *(undefined4 *)(iVar10 + 0x130) = 0x15;
      puVar11[1] = (char)((uint)uVar3 >> 8);
      puVar11[2] = (char)*param_1;
      puVar12 = puVar11 + 0xd;
      if (((undefined4 *)param_1[0x23] == (undefined4 *)0x0) ||
         (uVar4 = (*(code *)PTR_EVP_CIPHER_flags_006a7544)(*(undefined4 *)param_1[0x23]),
         (uVar4 & 2) == 0)) {
        iVar5 = param_1[0x25];
        *(undefined **)(iVar10 + 0x140) = &local_30;
        puVar14 = (undefined *)0x0;
        *(undefined4 *)(iVar10 + 0x134) = 2;
        *(undefined **)(iVar10 + 0x13c) = puVar12;
        puVar8 = puVar12;
        if (iVar5 != 0) goto LAB_004a1794;
LAB_004a1a48:
        *puVar8 = local_30;
        puVar8[1] = local_2f;
        *(undefined4 *)(iVar10 + 0x140) = *(undefined4 *)(iVar10 + 0x13c);
      }
      else {
        puVar14 = (undefined *)
                  (*(code *)PTR_EVP_CIPHER_block_size_006a80f0)(*(undefined4 *)param_1[0x23]);
        iVar5 = param_1[0x25];
        puVar8 = puVar12 + (int)puVar14;
        *(undefined **)(iVar10 + 0x140) = &local_30;
        *(undefined4 *)(iVar10 + 0x134) = 2;
        *(undefined **)(iVar10 + 0x13c) = puVar8;
        if (iVar5 == 0) goto LAB_004a1a48;
LAB_004a1794:
        iVar5 = ssl3_do_compress(param_1);
        if (iVar5 == 0) {
          puVar8 = (undefined *)0xf5;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xf5,0x8d,"d1_pkt.c",0x676);
          goto LAB_004a1ac0;
        }
      }
      if (iVar2 != 0) {
        puVar8 = puVar12 + (int)(puVar14 + *(int *)(iVar10 + 0x134));
        iVar5 = (**(code **)(*(int *)(param_1[2] + 100) + 4))(param_1,puVar8,1);
        if (iVar5 < 0) goto LAB_004a1ac0;
        *(int *)(iVar10 + 0x134) = *(int *)(iVar10 + 0x134) + iVar2;
      }
      *(undefined **)(iVar10 + 0x140) = puVar12;
      *(undefined **)(iVar10 + 0x13c) = puVar12;
      if (puVar14 != (undefined *)0x0) {
        puVar8 = puVar14;
        iVar2 = (*(code *)PTR_RAND_bytes_006a7574)(puVar12);
        if (iVar2 < 1) goto LAB_004a1ac0;
        *(undefined **)(iVar10 + 0x134) = puVar14 + *(int *)(iVar10 + 0x134);
      }
      puVar8 = (undefined *)0x1;
      iVar2 = (***(code ***)(param_1[2] + 100))(param_1);
      if (0 < iVar2) {
        puVar11[3] = (char)((ushort)*(undefined2 *)(param_1[0x17] + 0x20a) >> 8);
        puVar11[4] = (char)*(undefined2 *)(param_1[0x17] + 0x20a);
        iVar2 = param_1[0x16];
        uVar6 = *(uint *)(iVar2 + 0x56);
        puVar8 = puVar11 + 5;
        uVar4 = (uint)puVar8 & 3;
        *(uint *)(puVar8 + -uVar4) =
             *(uint *)(puVar8 + -uVar4) & -1 << (4 - uVar4) * 8 | uVar6 >> uVar4 * 8;
        puVar8 = puVar11 + 8;
        uVar4 = (uint)puVar8 & 3;
        *(uint *)(puVar8 + -uVar4) =
             *(uint *)(puVar8 + -uVar4) & 0xffffffffU >> (uVar4 + 1) * 8 | uVar6 << (3 - uVar4) * 8;
        puVar11[9] = *(undefined *)(iVar2 + 0x5a);
        puVar11[10] = *(undefined *)(iVar2 + 0x5b);
        puVar11[0xb] = (char)((uint)*(undefined4 *)(iVar10 + 0x134) >> 8);
        puVar11[0xc] = (char)*(undefined4 *)(iVar10 + 0x134);
        iVar2 = param_1[0x16];
        *(undefined4 *)(iVar10 + 0x130) = 0x15;
        *(int *)(iVar10 + 0x134) = *(int *)(iVar10 + 0x134) + 0xd;
        ssl3_record_sequence_update(iVar2 + 0x54);
        puVar8 = &DAT_00000015;
        iVar2 = param_1[0x16];
        *(undefined4 *)(iVar10 + 0x104) = 0;
        *(undefined4 *)(iVar10 + 0x108) = *(undefined4 *)(iVar10 + 0x134);
        *(undefined4 *)(iVar2 + 0x168) = 2;
        *(undefined **)(iVar2 + 0x174) = &local_30;
        *(undefined4 *)(iVar2 + 0x16c) = 0x15;
        *(undefined4 *)(iVar2 + 0x170) = 2;
        iVar10 = ssl3_write_pending(param_1,0x15,&local_30,2);
        goto joined_r0x004a19f8;
      }
    }
    else {
      uVar3 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(param_1[0x24]);
      iVar2 = (*(code *)PTR_EVP_MD_size_006a7e3c)(uVar3);
      if (-1 < iVar2) goto LAB_004a1724;
    }
LAB_004a1ac0:
    iVar10 = -1;
  }
  else {
    OpenSSLDie("d1_pkt.c",0x60f,"0");
    puVar8 = &DAT_00000015;
    iVar10 = ssl3_write_pending(param_1,0x15,&local_30,2);
joined_r0x004a19f8:
    if (0 < iVar10) {
      if (*(char *)(param_1[0x16] + 400) == '\x02') {
        puVar8 = &DAT_0000000b;
        (*(code *)PTR_BIO_ctrl_006a6e18)(param_1[4],0xb,0,0);
      }
      if ((code *)param_1[0x19] != (code *)0x0) {
        puVar8 = (undefined *)*param_1;
        (*(code *)param_1[0x19])(1,puVar8,0x15,param_1[0x16] + 400,2,param_1,param_1[0x1a]);
      }
      pcVar13 = (code *)param_1[0x34];
      if ((pcVar13 != (code *)0x0) ||
         (pcVar13 = *(code **)(param_1[0x39] + 0x9c), pcVar13 != (code *)0x0)) {
        puVar8 = (undefined *)0x0;
        (*pcVar13)(param_1,&DAT_00004008,*(undefined2 *)(param_1[0x16] + 400));
      }
      goto LAB_004a193c;
    }
  }
  *(undefined4 *)(param_1[0x16] + 0x18c) = 1;
LAB_004a193c:
  if (local_2c == *(undefined **)puVar7) {
    return iVar10;
  }
  puVar7 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (((uint)puVar8 & 1) == 0) {
    iVar2 = *(int *)(puVar7 + 0x58);
    iVar10 = *(int *)(puVar7 + 0x5c);
    uVar6 = *(uint *)(iVar2 + 0x54);
    uVar3 = *(undefined4 *)(iVar2 + 0x58);
    uVar4 = iVar10 + 0x22aU & 3;
    puVar1 = (uint *)((iVar10 + 0x22aU) - uVar4);
    *puVar1 = *puVar1 & -1 << (4 - uVar4) * 8 | uVar6 >> uVar4 * 8;
    uVar4 = iVar10 + 0x22dU & 3;
    puVar1 = (uint *)((iVar10 + 0x22dU) - uVar4);
    *puVar1 = *puVar1 & 0xffffffffU >> (uVar4 + 1) * 8 | uVar6 << (3 - uVar4) * 8;
    *(undefined4 *)(iVar10 + 0x22e) = uVar3;
    iVar10 = *(ushort *)(*(int *)(puVar7 + 0x5c) + 0x20a) + 1;
    *(short *)(*(int *)(puVar7 + 0x5c) + 0x20a) = (short)iVar10;
    *(undefined *)(uint *)(iVar2 + 0x54) = 0;
    *(undefined *)(iVar2 + 0x55) = 0;
    *(undefined *)(iVar2 + 0x56) = 0;
    *(undefined *)(iVar2 + 0x57) = 0;
    *(undefined *)(iVar2 + 0x58) = 0;
    *(undefined *)(iVar2 + 0x59) = 0;
    *(undefined *)(iVar2 + 0x5a) = 0;
    *(undefined *)(iVar2 + 0x5b) = 0;
    return iVar10;
  }
  iVar10 = *(int *)(puVar7 + 0x5c);
  iVar2 = *(int *)(puVar7 + 0x58);
  *(short *)(iVar10 + 0x208) = *(short *)(iVar10 + 0x208) + 1;
  uVar6 = *(uint *)(iVar10 + 0x218);
  uVar9 = *(undefined4 *)(iVar10 + 0x21c);
  uVar3 = *(undefined4 *)(iVar10 + 0x220);
  uVar4 = iVar10 + 0x20cU & 3;
  puVar1 = (uint *)((iVar10 + 0x20cU) - uVar4);
  *puVar1 = *puVar1 & -1 << (4 - uVar4) * 8 | uVar6 >> uVar4 * 8;
  uVar4 = iVar10 + 0x20fU & 3;
  puVar1 = (uint *)((iVar10 + 0x20fU) - uVar4);
  *puVar1 = *puVar1 & 0xffffffffU >> (uVar4 + 1) * 8 | uVar6 << (3 - uVar4) * 8;
  *(undefined4 *)(iVar10 + 0x210) = uVar9;
  *(undefined4 *)(iVar10 + 0x214) = uVar3;
  iVar10 = *(int *)(puVar7 + 0x5c);
  *(undefined *)(iVar10 + 0x218) = 0;
  *(undefined *)(iVar10 + 0x219) = 0;
  *(undefined *)(iVar10 + 0x21a) = 0;
  *(undefined *)(iVar10 + 0x21b) = 0;
  *(undefined *)(iVar10 + 0x21c) = 0;
  *(undefined *)(iVar10 + 0x21d) = 0;
  *(undefined *)(iVar10 + 0x21e) = 0;
  *(undefined *)(iVar10 + 0x21f) = 0;
  *(undefined *)(iVar10 + 0x220) = 0;
  *(undefined *)(iVar10 + 0x221) = 0;
  *(undefined *)(iVar10 + 0x222) = 0;
  *(undefined *)(iVar10 + 0x223) = 0;
  iVar10 = dtls1_clear_received_buffer();
  *(undefined *)(iVar2 + 8) = 0;
  *(undefined *)(iVar2 + 9) = 0;
  *(undefined *)(iVar2 + 10) = 0;
  *(undefined *)(iVar2 + 0xb) = 0;
  *(undefined *)(iVar2 + 0xc) = 0;
  *(undefined *)(iVar2 + 0xd) = 0;
  *(undefined *)(iVar2 + 0xe) = 0;
  *(undefined *)(iVar2 + 0xf) = 0;
  return iVar10;
}

