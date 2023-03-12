
/* WARNING: Could not reconcile some variable overlaps */

int * dtls1_get_message(int *param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                       int **param_6)

{
  bool bVar1;
  undefined2 uVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  void *pvVar8;
  int *piVar9;
  int *piVar10;
  undefined uVar12;
  int *piVar11;
  undefined uVar15;
  uint uVar13;
  int iVar14;
  undefined4 uVar16;
  int *piVar17;
  int *piVar18;
  int *unaff_s5;
  int *piVar19;
  undefined *puVar20;
  int *unaff_s8;
  char *local_188;
  int local_184;
  int local_180;
  char *local_17c;
  char *local_178;
  int local_16c;
  int *local_168;
  uint local_164;
  int *local_160;
  int *local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  int local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  uint local_13c;
  byte local_138;
  byte local_137;
  byte local_136;
  byte local_135;
  ushort local_134;
  byte local_132;
  byte local_131;
  byte local_130;
  byte local_12f;
  byte local_12e;
  byte local_12d;
  int aiStack_12c [64];
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iVar4 = param_1[0x16];
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  piVar19 = unaff_s5;
  if (*(int *)(iVar4 + 0x354) == 0) {
    local_184 = param_1[0x17];
    local_180 = local_184 + 0x28c;
    (*(code *)PTR_memset_006a99f4)(local_180,0,0x2c);
    local_188 = "-check_ss_sig";
    local_178 = "d1_both.c";
    local_17c = "item != NULL";
    goto LAB_004a2d00;
  }
  *(undefined4 *)(iVar4 + 0x354) = 0;
  if ((-1 < param_4) && (param_4 != *(int *)(iVar4 + 0x340))) {
    uVar7 = 0x1ef;
    goto LAB_004a3558;
  }
  piVar10 = *(int **)(iVar4 + 0x33c);
  iVar4 = *(int *)(param_1[0xf] + 4);
  *param_6 = (int *)0x1;
  param_1[0x11] = (int)piVar10;
  param_1[0x10] = iVar4 + 0xc;
LAB_004a2c84:
  if (local_2c == *(int *)puVar3) {
    return piVar10;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004a3754:
  puVar20 = (undefined *)((int)unaff_s8 + 3);
LAB_004a36ac:
  if (piVar19[5] != 0) {
    (*(code *)PTR_EVP_CIPHER_CTX_free_006a82dc)(piVar19[6]);
    (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(piVar19[7]);
  }
  if ((void *)piVar19[0xb] != (void *)0x0) {
    CRYPTO_free((void *)piVar19[0xb]);
  }
  if ((void *)piVar19[0xc] != (void *)0x0) {
    CRYPTO_free((void *)piVar19[0xc]);
  }
  CRYPTO_free(piVar19);
  unaff_s5 = unaff_s8;
LAB_004a2ee8:
  *param_6 = (int *)0x0;
  unaff_s8 = unaff_s5;
LAB_004a2ef0:
  if (puVar20 < (undefined *)0x2) goto LAB_004a2d00;
  goto LAB_004a308c;
LAB_004a2d00:
  iVar4 = param_1[0x17];
LAB_004a2d0c:
  *param_6 = (int *)0x0;
  while (iVar4 = (*(code *)PTR_pqueue_peek_006a82a4)(*(undefined4 *)(iVar4 + 0x244)), iVar4 != 0) {
    unaff_s8 = *(int **)(iVar4 + 8);
    iVar5 = param_1[0x17];
    if (*(ushort *)(iVar5 + 0x228) <= *(ushort *)(unaff_s8 + 2)) {
      if ((unaff_s8[0xc] == 0) && (*(ushort *)(unaff_s8 + 2) == *(ushort *)(iVar5 + 0x228))) {
        unaff_s5 = (int *)unaff_s8[4];
        (*(code *)PTR_pqueue_pop_006a827c)(*(undefined4 *)(iVar5 + 0x244));
        iVar5 = dtls1_preprocess_fragment(param_1,unaff_s8,param_5);
        if (iVar5 == 0) {
          (*(code *)PTR_memcpy_006a9aec)
                    (*(int *)(param_1[0xf] + 4) + unaff_s8[3] + 0xc,unaff_s8[0xb],unaff_s8[4]);
        }
        if (unaff_s8[5] != 0) {
          (*(code *)PTR_EVP_CIPHER_CTX_free_006a82dc)(unaff_s8[6]);
          (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(unaff_s8[7]);
        }
        if ((void *)unaff_s8[0xb] != (void *)0x0) {
          CRYPTO_free((void *)unaff_s8[0xb]);
        }
        if ((void *)unaff_s8[0xc] != (void *)0x0) {
          CRYPTO_free((void *)unaff_s8[0xc]);
        }
        CRYPTO_free(unaff_s8);
        (*(code *)PTR_pitem_free_006a8278)(iVar4);
        if (iVar5 != 0) {
          ssl3_send_alert(param_1,2,iVar5);
          piVar10 = (int *)0xffffffff;
          param_1[0x11] = 0;
          *param_6 = (int *)0x0;
          goto LAB_004a35c8;
        }
        puVar20 = (undefined *)((int)unaff_s5 + 3);
        *param_6 = (int *)0x1;
        piVar19 = unaff_s5;
        if (unaff_s5 == (int *)0x0) goto LAB_004a3040;
        param_1[0x11] = (int)unaff_s5;
        goto LAB_004a2ef0;
      }
      break;
    }
    (*(code *)PTR_pqueue_pop_006a827c)(*(undefined4 *)(iVar5 + 0x244));
    if (unaff_s8[5] != 0) {
      (*(code *)PTR_EVP_CIPHER_CTX_free_006a82dc)(unaff_s8[6]);
      (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(unaff_s8[7]);
    }
    if ((void *)unaff_s8[0xb] != (void *)0x0) {
      CRYPTO_free((void *)unaff_s8[0xb]);
    }
    if ((void *)unaff_s8[0xc] != (void *)0x0) {
      CRYPTO_free((void *)unaff_s8[0xc]);
    }
    CRYPTO_free(unaff_s8);
    (*(code *)PTR_pitem_free_006a8278)(iVar4);
    iVar4 = param_1[0x17];
  }
  unaff_s8 = *param_6;
  if (unaff_s8 != (int *)0x0) {
LAB_004a3040:
    unaff_s5 = (int *)0x0;
    puVar20 = (undefined *)0x3;
    param_1[0x11] = 0;
    goto LAB_004a2ef0;
  }
  unaff_s5 = (int *)(**(code **)(param_1[2] + 0x34))(param_1,0x16,&local_138,0xc,0);
  if ((int)unaff_s5 < 1) goto LAB_004a322c;
  if (unaff_s5 != (int *)&SUB_0000000c) {
    uVar7 = 0x392;
LAB_004a31bc:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xfd,0xf4,"d1_both.c",uVar7);
    iVar4 = 10;
    goto LAB_004a31d4;
  }
  piVar10 = (int *)((uint)local_12f << 0x10 | (uint)local_12e << 8 | (uint)local_12d);
  piVar19 = (int *)((uint)local_132 << 0x10 | (uint)local_131 << 8 | (uint)local_130);
  local_168 = (int *)((uint)local_137 << 0x10 | (uint)local_136 << 8 | (uint)local_135);
  local_158 = 0;
  local_154 = 0;
  local_150 = 0;
  local_14c = 0;
  local_148 = 0;
  local_144 = 0;
  local_16c = (uint)local_138 << 0x18;
  local_164 = (uint)local_134 << 0x10;
  local_160 = piVar19;
  local_15c = piVar10;
  if (*(int **)(param_1[0x16] + 0x110) < piVar10) {
    uVar16 = 0x10f;
    uVar7 = 0x3a3;
    goto LAB_004a326c;
  }
  iVar4 = param_1[0x17];
  if ((*(ushort *)(iVar4 + 0x228) == local_134) ||
     ((*(int *)(iVar4 + 0x254) != 0 && (local_134 == 1)))) {
    if ((piVar10 != (int *)0x0) && (piVar10 < local_168)) {
LAB_004a34cc:
      unaff_s5 = (int *)dtls1_reassemble_fragment(param_1,&local_16c,param_6);
      puVar20 = (undefined *)((int)unaff_s5 + 3);
      goto LAB_004a2ef0;
    }
    if (((param_1[9] != 0) || (*(int *)(iVar4 + 0x298) != 0)) || (local_138 != 0))
    goto LAB_004a3050;
    if (((local_137 != 0) || (local_136 != 0)) || (local_135 != 0)) {
      uVar7 = 0x3c7;
      goto LAB_004a31bc;
    }
    if ((code *)param_1[0x19] != (code *)0x0) {
      (*(code *)param_1[0x19])(0,*param_1,0x16,&local_138,0xc,param_1,param_1[0x1a]);
      iVar4 = param_1[0x17];
    }
    param_1[0x11] = 0;
    goto LAB_004a2d0c;
  }
  if (local_168 < (int *)((int)piVar19 + (int)piVar10)) {
LAB_004a2ee0:
    puVar20 = (undefined *)0x2;
    unaff_s5 = (int *)0xffffffff;
    goto LAB_004a2ee8;
  }
  local_140 = 0;
  local_13c = (uint)local_134;
  iVar4 = (*(code *)PTR_pqueue_find_006a82d8)(*(undefined4 *)(iVar4 + 0x244),&local_140);
  piVar9 = local_168;
  if ((iVar4 != 0) && (piVar10 != local_168)) {
    iVar4 = 0;
  }
  uVar13 = (uint)*(ushort *)(param_1[0x17] + 0x228);
  piVar19 = aiStack_12c;
  if ((((local_164 >> 0x10 <= uVar13) || (uVar13 + 10 < local_164 >> 0x10)) || (iVar4 != 0)) ||
     ((uVar13 == 0 && (local_16c._0_1_ == '\x14')))) {
    if (piVar10 == (int *)0x0) goto LAB_004a3540;
    goto LAB_004a348c;
  }
  if (piVar10 != local_168) goto LAB_004a34cc;
  piVar6 = (int *)param_1[0x42];
  if (piVar6 < (int *)0x454c) {
    piVar6 = (int *)0x454c;
  }
  if ((piVar6 < piVar10) ||
     (piVar19 = (int *)CRYPTO_malloc(0x34,local_188 + 0x77ac,0xb5), piVar19 == (int *)0x0))
  goto LAB_004a2ee0;
  if (piVar10 == (int *)0x0) {
    piVar19[0xb] = 0;
    piVar19[0xc] = 0;
    piVar10 = piVar19;
    piVar9 = &local_16c;
    do {
      piVar17 = piVar9;
      piVar6 = piVar10;
      piVar9 = piVar17 + 4;
      iVar14 = piVar17[1];
      iVar5 = piVar17[2];
      iVar4 = piVar17[3];
      *piVar6 = *piVar17;
      piVar6[1] = iVar14;
      piVar6[2] = iVar5;
      piVar6[3] = iVar4;
      piVar10 = piVar6 + 4;
    } while (piVar9 != &local_14c);
    iVar5 = piVar17[5];
    unaff_s8 = (int *)0xffffffff;
    iVar4 = piVar17[6];
    piVar6[4] = *piVar9;
    piVar6[5] = iVar5;
    piVar6[6] = iVar4;
  }
  else {
    pvVar8 = CRYPTO_malloc((int)piVar10,local_178,0xba);
    if (pvVar8 == (void *)0x0) {
      puVar20 = (undefined *)0x2;
      unaff_s5 = (int *)0xffffffff;
      CRYPTO_free(piVar19);
      goto LAB_004a2ee8;
    }
    piVar19[0xb] = (int)pvVar8;
    piVar19[0xc] = 0;
    piVar6 = &local_16c;
    piVar17 = piVar19;
    do {
      piVar18 = piVar17;
      piVar11 = piVar6;
      piVar6 = piVar11 + 4;
      iVar14 = piVar11[1];
      iVar5 = piVar11[2];
      iVar4 = piVar11[3];
      *piVar18 = *piVar11;
      piVar18[1] = iVar14;
      piVar18[2] = iVar5;
      piVar18[3] = iVar4;
      piVar17 = piVar18 + 4;
    } while (piVar6 != &local_14c);
    iVar5 = piVar11[5];
    iVar4 = piVar11[6];
    piVar18[4] = *piVar6;
    piVar18[5] = iVar5;
    piVar18[6] = iVar4;
    unaff_s8 = (int *)(**(code **)(param_1[2] + 0x34))(param_1,0x16,pvVar8,piVar10,0);
    if (piVar9 != unaff_s8) {
      puVar20 = (undefined *)0x2;
      unaff_s8 = (int *)0xffffffff;
      goto LAB_004a36ac;
    }
    if ((int)unaff_s8 < 1) goto LAB_004a3754;
  }
  iVar4 = (*(code *)PTR_pitem_new_006a829c)(&local_140,piVar19);
  if (iVar4 == 0) {
    puVar20 = (undefined *)((int)unaff_s8 + 3);
    goto LAB_004a36ac;
  }
  iVar4 = (*(code *)PTR_pqueue_insert_006a82a0)(*(undefined4 *)(param_1[0x17] + 0x244),iVar4);
  if (iVar4 != 0) goto LAB_004a3540;
  puVar20 = (undefined *)0x0;
  OpenSSLDie(local_188 + 0x77ac,0x36b,local_17c);
  unaff_s5 = (int *)0xfffffffd;
  goto LAB_004a2ef0;
LAB_004a3050:
  iVar4 = dtls1_preprocess_fragment(param_1,&local_16c,param_5);
  if (iVar4 != 0) {
LAB_004a31d4:
    ssl3_send_alert(param_1,2,iVar4);
    piVar10 = (int *)0xffffffff;
    param_1[0x11] = 0;
    *param_6 = (int *)0x0;
    goto LAB_004a2c84;
  }
  unaff_s5 = unaff_s8;
  if (piVar10 != (int *)0x0) {
    unaff_s5 = (int *)(**(code **)(param_1[2] + 0x34))
                                (param_1,0x16,
                                 (undefined *)((int)piVar19 + *(int *)(param_1[0xf] + 4) + 0xc),
                                 piVar10,0);
    unaff_s8 = piVar10;
    if ((int)unaff_s5 < 1) {
LAB_004a322c:
      puVar20 = (undefined *)((int)unaff_s5 + 3);
      param_1[6] = 3;
      *param_6 = (int *)0x0;
      goto LAB_004a2ef0;
    }
    bVar1 = piVar10 != unaff_s5;
    unaff_s5 = piVar10;
    if (bVar1) {
      uVar16 = 0x2f;
      uVar7 = 1000;
LAB_004a326c:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xfd,uVar16,"d1_both.c",uVar7);
      ssl3_send_alert(param_1,2,0x2f);
      piVar10 = (int *)0xffffffff;
      param_1[0x11] = 0;
      *param_6 = (int *)0x0;
      goto LAB_004a2c84;
    }
  }
  *param_6 = (int *)0x1;
  param_1[0x11] = (int)unaff_s5;
  param_1[0xd] = param_3;
  unaff_s8 = unaff_s5;
LAB_004a308c:
  bVar1 = (int)unaff_s5 < 1;
  piVar10 = unaff_s5;
  unaff_s5 = piVar19;
  if (bVar1) {
LAB_004a35c8:
    piVar19 = unaff_s5;
    if (*param_6 == (int *)0x0) goto LAB_004a2c84;
  }
  if ((param_4 < 0) || (param_4 == *(int *)(param_1[0x16] + 0x340))) {
    param_4 = *(int *)(local_184 + 0x290);
    param_6 = *(int ***)(param_1[0xf] + 4);
    *(undefined *)param_6 = *(undefined *)(local_184 + 0x28c);
    uVar15 = (undefined)((uint)param_4 >> 0x10);
    *(undefined *)((int)param_6 + 1) = uVar15;
    uVar12 = (undefined)((uint)param_4 >> 8);
    *(undefined *)((int)param_6 + 2) = uVar12;
    *(char *)((int)param_6 + 3) = (char)param_4;
    *(char *)(param_6 + 1) = (char)((ushort)*(undefined2 *)(local_184 + 0x294) >> 8);
    uVar2 = *(undefined2 *)(local_184 + 0x294);
    *(undefined *)((int)param_6 + 6) = 0;
    *(undefined *)((int)param_6 + 7) = 0;
    *(undefined *)(param_6 + 2) = 0;
    *(char *)((int)param_6 + 5) = (char)uVar2;
    *(undefined *)((int)param_6 + 9) = uVar15;
    *(undefined *)((int)param_6 + 10) = uVar12;
    *(char *)((int)param_6 + 0xb) = (char)param_4;
    if (*param_1 == 0x100) {
      param_6 = param_6 + 3;
    }
    else {
      param_4 = param_4 + 0xc;
    }
    ssl3_finish_mac(param_1,param_6,param_4);
    if ((code *)param_1[0x19] != (code *)0x0) {
      (*(code *)param_1[0x19])(0,*param_1,0x16,param_6,param_4,param_1,param_1[0x1a]);
    }
    (*(code *)PTR_memset_006a99f4)(local_180,0,0x2c);
    iVar4 = param_1[0x17];
    if (*(int *)(iVar4 + 0x254) == 0) {
      *(short *)(iVar4 + 0x228) = *(short *)(iVar4 + 0x228) + 1;
    }
    piVar10 = (int *)param_1[0x11];
    param_1[0x10] = *(int *)(param_1[0xf] + 4) + 0xc;
    piVar19 = unaff_s5;
  }
  else {
    uVar7 = 0x206;
LAB_004a3558:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xfc,0xf4,"d1_both.c",uVar7);
    ssl3_send_alert(param_1,2,10);
    piVar10 = (int *)0xffffffff;
    *param_6 = (int *)0x0;
    piVar19 = unaff_s5;
  }
  goto LAB_004a2c84;
  while (piVar10 = (int *)((int)piVar10 - (int)unaff_s5), unaff_s8 = unaff_s5, piVar10 != (int *)0x0
        ) {
LAB_004a348c:
    piVar9 = (int *)0x100;
    if (piVar10 < (int *)0x101) {
      piVar9 = piVar10;
    }
    unaff_s5 = (int *)(**(code **)(param_1[2] + 0x34))(param_1,0x16,piVar19,piVar9,0);
    if ((int)unaff_s5 < 1) {
      puVar20 = (undefined *)((int)unaff_s5 + 3);
      goto LAB_004a2ee8;
    }
  }
LAB_004a3540:
  puVar20 = (undefined *)0x0;
  unaff_s5 = (int *)0xfffffffd;
  goto LAB_004a2ef0;
}

