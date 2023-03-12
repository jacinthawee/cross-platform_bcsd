
/* WARNING: Could not reconcile some variable overlaps */

undefined4 *
dtls1_reassemble_fragment(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  byte *pbVar1;
  undefined *puVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int *ptr;
  int *piVar10;
  byte *pbVar11;
  int *extraout_v1;
  int *piVar12;
  int *piVar13;
  undefined4 uVar14;
  char *file;
  undefined4 uVar15;
  int iVar16;
  undefined4 *puVar17;
  undefined4 uVar18;
  int iVar19;
  undefined4 *unaff_s2;
  undefined4 *puVar20;
  undefined4 *unaff_s5;
  void *pvVar21;
  undefined4 *unaff_s7;
  undefined4 *unaff_s8;
  uint uVar22;
  int iStack_2cc;
  undefined4 *puStack_2c8;
  uint uStack_2c4;
  uint uStack_2c0;
  undefined4 *puStack_2bc;
  undefined4 uStack_2b8;
  undefined4 uStack_2b4;
  undefined4 uStack_2b0;
  int iStack_2ac;
  undefined4 uStack_2a8;
  undefined4 uStack_2a4;
  undefined4 uStack_2a0;
  uint uStack_29c;
  byte bStack_298;
  byte bStack_297;
  byte bStack_296;
  byte bStack_295;
  ushort uStack_294;
  byte bStack_292;
  byte bStack_291;
  byte bStack_290;
  byte bStack_28f;
  byte bStack_28e;
  byte bStack_28d;
  undefined auStack_28c [256];
  int iStack_18c;
  undefined4 *puStack_188;
  undefined4 *puStack_184;
  undefined4 *puStack_180;
  undefined *puStack_17c;
  undefined4 *puStack_178;
  undefined4 *puStack_174;
  int iStack_170;
  undefined4 *puStack_16c;
  undefined4 *puStack_168;
  code *pcStack_164;
  int *local_150;
  undefined *local_148;
  undefined4 *local_13c;
  undefined4 local_134;
  uint local_130;
  undefined4 auStack_12c [64];
  undefined4 *local_2c;
  
  puStack_17c = PTR___stack_chk_guard_006aabf0;
  puStack_184 = (undefined4 *)param_2[4];
  local_148 = &_gp;
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  puStack_188 = (undefined4 *)0xffffffff;
  file = (char *)param_2;
  puVar17 = param_3;
  puVar6 = puStack_188;
  if ((byte *)param_2[1] < (byte *)((int)puStack_184 + param_2[3])) {
LAB_004a51a4:
    *param_3 = 0;
    puStack_188 = puVar6;
    param_2 = unaff_s2;
  }
  else {
    pbVar11 = *(byte **)(param_1 + 0x108);
    file = (char *)0x454c;
    if ((int)pbVar11 < 0x454d) {
      pbVar11 = (byte *)0x454c;
    }
    unaff_s8 = &local_134;
    unaff_s2 = param_2;
    if (pbVar11 < (byte *)((int)puStack_184 + param_2[3])) {
LAB_004a51a0:
      puVar6 = (undefined4 *)0xffffffff;
      goto LAB_004a51a4;
    }
    local_134 = 0;
    local_130 = (uint)*(ushort *)(param_2 + 2);
    file = (char *)unaff_s8;
    unaff_s7 = (undefined4 *)
               (*(code *)PTR_pqueue_find_006a93f4)
                         (*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x244),unaff_s8);
    if (unaff_s7 == (undefined4 *)0x0) {
      puVar17 = (undefined4 *)0xb3;
      uVar22 = param_2[1];
      file = "d1_both.c";
      local_13c = (undefined4 *)0x640000;
      unaff_s5 = (undefined4 *)CRYPTO_malloc(0x34,"d1_both.c",0xb3);
      if (unaff_s5 != (undefined4 *)0x0) {
        if (uVar22 == 0) {
          file = (char *)(local_13c + 0x1f5f);
          unaff_s5[0xb] = 0;
          puVar17 = (undefined4 *)&DAT_000000c7;
          puVar6 = (undefined4 *)CRYPTO_malloc(0,file,199);
          if (puVar6 != (undefined4 *)0x0) {
LAB_004a5570:
            local_13c = puVar6;
            (**(code **)(local_148 + -0x53e0))(puVar6,0,uVar22);
            unaff_s5[0xc] = local_13c;
            puVar17 = unaff_s5;
            puVar6 = param_2;
            do {
              puVar20 = puVar6;
              puVar9 = puVar17;
              puVar6 = puVar20 + 4;
              uVar18 = puVar20[1];
              uVar15 = puVar20[2];
              uVar14 = puVar20[3];
              *puVar9 = *puVar20;
              puVar9[1] = uVar18;
              puVar9[2] = uVar15;
              puVar9[3] = uVar14;
              puVar17 = puVar9 + 4;
            } while (puVar6 != param_2 + 8);
            uVar15 = puVar20[5];
            uVar14 = puVar20[6];
            puVar9[4] = *puVar6;
            puVar9[5] = uVar15;
            puVar9[6] = uVar14;
            unaff_s5[3] = 0;
            unaff_s5[4] = unaff_s5[1];
            goto LAB_004a5230;
          }
        }
        else {
          file = (char *)(local_13c + 0x1f5f);
          puVar17 = (undefined4 *)0xb9;
          puVar6 = (undefined4 *)CRYPTO_malloc(uVar22,file,0xb9);
          if (puVar6 != (undefined4 *)0x0) {
            file = (char *)(local_13c + 0x1f5f);
            unaff_s5[0xb] = puVar6;
            uVar22 = uVar22 + 7 >> 3;
            puVar17 = (undefined4 *)&DAT_000000c7;
            local_13c = puVar6;
            puVar6 = (undefined4 *)CRYPTO_malloc(uVar22,file,199);
            if (puVar6 != (undefined4 *)0x0) goto LAB_004a5570;
            param_4 = local_13c;
            CRYPTO_free(local_13c);
          }
        }
        puVar6 = (undefined4 *)0xffffffff;
        CRYPTO_free(unaff_s5);
        goto LAB_004a51a4;
      }
      goto LAB_004a51a0;
    }
    unaff_s5 = (undefined4 *)unaff_s7[2];
    if (unaff_s5[0xc] == 0) {
      unaff_s8 = auStack_12c;
      param_2 = (undefined4 *)0x100;
      for (; puStack_184 != (undefined4 *)0x0;
          puStack_184 = (undefined4 *)((int)puStack_184 - (int)puStack_188)) {
        local_150 = (int *)0x0;
        param_4 = (undefined4 *)0x100;
        if (puStack_184 < (undefined4 *)0x101) {
          param_4 = puStack_184;
        }
        file = &DAT_00000016;
        puVar17 = unaff_s8;
        puStack_188 = (undefined4 *)(**(code **)(*(int *)(param_1 + 8) + 0x34))(param_1,0x16);
        if ((int)puStack_188 < 1) goto LAB_004a526c;
      }
LAB_004a5340:
      puVar6 = (undefined4 *)0xfffffffd;
    }
    else {
LAB_004a5230:
      file = &DAT_00000016;
      local_150 = (int *)0x0;
      puVar17 = (undefined4 *)(unaff_s5[0xb] + param_2[3]);
      param_4 = puStack_184;
      puStack_188 = (undefined4 *)(**(code **)(*(int *)(param_1 + 8) + 0x34))(param_1,0x16);
      if (((int)puStack_188 < 1) || (puStack_184 != puStack_188)) {
LAB_004a526c:
        if (unaff_s5[5] != 0) {
          (**(code **)(local_148 + -0x6ae8))(unaff_s5[6]);
          (**(code **)(local_148 + -0x6d18))(unaff_s5[7]);
        }
        if ((void *)unaff_s5[0xb] != (void *)0x0) {
          CRYPTO_free((void *)unaff_s5[0xb]);
        }
        if ((void *)unaff_s5[0xc] != (void *)0x0) {
          CRYPTO_free((void *)unaff_s5[0xc]);
        }
        CRYPTO_free(unaff_s5);
        puVar6 = puStack_188;
        unaff_s2 = param_2;
        if (unaff_s7 != (undefined4 *)0x0) {
          CRYPTO_free(unaff_s7);
        }
        goto LAB_004a51a4;
      }
      if ((int)puStack_188 < 9) {
        uVar22 = param_2[3];
        if ((int)uVar22 < (int)((int)puStack_188 + uVar22)) {
          do {
            uVar5 = uVar22 & 7;
            pbVar11 = (byte *)(unaff_s5[0xc] + ((int)uVar22 >> 3));
            uVar22 = uVar22 + 1;
            *pbVar11 = (byte)(1 << uVar5) | *pbVar11;
          } while ((int)uVar22 < (int)((int)puStack_184 + param_2[3]));
        }
      }
      else {
        pbVar11 = (byte *)(unaff_s5[0xc] + ((int)param_2[3] >> 3));
        *pbVar11 = *(byte *)((int)&bitmask_start_values + (param_2[3] & 7)) | *pbVar11;
        pbVar11 = (byte *)((int)puStack_184 + param_2[3]);
        iVar8 = ((int)param_2[3] >> 3) + 1;
        iVar16 = (int)(pbVar11 + -1) >> 3;
        if (iVar8 < iVar16) {
          do {
            puVar7 = (undefined *)(unaff_s5[0xc] + iVar8);
            iVar8 = iVar8 + 1;
            *puVar7 = 0xff;
            pbVar11 = (byte *)((int)puStack_184 + param_2[3]);
            iVar16 = (int)(pbVar11 + -1) >> 3;
          } while (iVar8 < iVar16);
        }
        *(byte *)(unaff_s5[0xc] + iVar16) =
             *(byte *)((int)&bitmask_end_values + ((uint)pbVar11 & 7)) |
             *(byte *)(unaff_s5[0xc] + iVar16);
      }
      uVar22 = param_2[1];
      if ((int)uVar22 < 1) {
        OpenSSLDie("d1_both.c",0x294,"((long)msg_hdr->msg_len) > 0");
        uVar22 = param_2[1];
      }
      pvVar21 = (void *)unaff_s5[0xc];
      iVar8 = (int)(uVar22 - 1) >> 3;
      puStack_184 = (undefined4 *)((int)&bitmask_end_values + (uVar22 & 7));
      pbVar11 = (byte *)((int)pvVar21 + iVar8);
      puVar17 = (undefined4 *)(uint)*pbVar11;
      iVar8 = iVar8 + -1;
      if (puVar17 == (undefined4 *)(uint)*(byte *)puStack_184) {
        if (iVar8 < 0) {
LAB_004a5610:
          CRYPTO_free(pvVar21);
          unaff_s5[0xc] = 0;
        }
        else if (*(char *)((int)pvVar21 + iVar8) == -1) {
          puVar17 = (undefined4 *)0xff;
          do {
            if (pbVar11 == (byte *)((int)pvVar21 + 1)) goto LAB_004a5610;
            pbVar1 = pbVar11 + -2;
            pbVar11 = pbVar11 + -1;
          } while (*pbVar1 == 0xff);
        }
      }
      file = (char *)unaff_s5;
      if (unaff_s7 != (undefined4 *)0x0) goto LAB_004a5340;
      local_134 = 0;
      local_130 = (uint)*(ushort *)(param_2 + 2);
      unaff_s7 = (undefined4 *)(**(code **)(local_148 + -0x6b24))(unaff_s8,unaff_s5);
      if (unaff_s7 == (undefined4 *)0x0) goto LAB_004a526c;
      file = (char *)unaff_s7;
      (**(code **)(local_148 + -0x6b20))(*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x244),unaff_s7)
      ;
      puVar6 = (undefined4 *)0xfffffffd;
    }
  }
  if (local_2c == *(undefined4 **)puStack_17c) {
    return puVar6;
  }
  pcStack_164 = dtls1_get_message_fragment;
  puVar6 = local_2c;
  (**(code **)(local_148 + -0x5328))();
  piVar3 = local_150;
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puVar7 = PTR_pqueue_peek_006a93c4;
  iStack_18c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar14 = *(undefined4 *)(puVar6[0x17] + 0x244);
  *local_150 = 0;
  puStack_180 = param_2;
  puStack_178 = param_3;
  puStack_174 = unaff_s5;
  iStack_170 = param_1;
  puStack_16c = unaff_s7;
  puStack_168 = unaff_s8;
  iVar8 = (*(code *)puVar7)(uVar14);
  if (((iVar8 == 0) || (pvVar21 = *(void **)(iVar8 + 8), *(int *)((int)pvVar21 + 0x30) != 0)) ||
     (*(short *)(puVar6[0x17] + 0x228) != *(short *)((int)pvVar21 + 8))) {
    puVar9 = (undefined4 *)0x0;
    if (*piVar3 == 0) {
      puVar9 = (undefined4 *)(**(code **)(puVar6[2] + 0x34))(puVar6,0x16,&bStack_298,0xc,0);
      if ((int)puVar9 < 1) {
LAB_004a5b2c:
        puVar6[6] = 3;
        *piVar3 = 0;
        goto LAB_004a5768;
      }
      if (puVar9 == (undefined4 *)&SUB_0000000c) {
        piVar12 = &iStack_2cc;
        iVar8 = puVar6[0x17];
        puStack_2c8 = (undefined4 *)
                      ((uint)bStack_297 << 0x10 | (uint)bStack_296 << 8 | (uint)bStack_295);
        uVar22 = (uint)bStack_292 << 0x10 | (uint)bStack_291 << 8 | (uint)bStack_290;
        puVar20 = (undefined4 *)
                  ((uint)bStack_28f << 0x10 | (uint)bStack_28e << 8 | (uint)bStack_28d);
        uStack_2b8 = 0;
        uStack_2b4 = 0;
        uStack_2b0 = 0;
        iStack_2ac = 0;
        uStack_2a8 = 0;
        uStack_2a4 = 0;
        iStack_2cc = (uint)bStack_298 << 0x18;
        uStack_2c4 = (uint)uStack_294 << 0x10;
        uStack_2c0 = uVar22;
        puStack_2bc = puVar20;
        if ((*(ushort *)(iVar8 + 0x228) == uStack_294) ||
           ((*(int *)(iVar8 + 0x254) != 0 && (uStack_294 == 1)))) {
          if ((puVar20 == (undefined4 *)0x0) || (puStack_2c8 <= puVar20)) {
            if (((puVar6[9] == 0) && (*(int *)(iVar8 + 0x294) == 0)) && (bStack_298 == 0)) {
              if (((bStack_297 == 0) && (bStack_296 == 0)) && (bStack_295 == 0)) {
                if ((code *)puVar6[0x19] != (code *)0x0) {
                  (*(code *)puVar6[0x19])(0,*puVar6,0x16,&bStack_298,0xc,puVar6,puVar6[0x1a]);
                }
                puVar6[0x11] = 0;
                puVar9 = (undefined4 *)
                         dtls1_get_message_fragment(puVar6,file,puVar17,param_4,piVar3);
                goto LAB_004a5768;
              }
              uVar14 = 0x353;
              goto LAB_004a5be4;
            }
            iVar8 = dtls1_preprocess_fragment(puVar6,piVar12,param_4);
            if (iVar8 == 0) {
              puVar6[0xd] = puVar17;
              if (puVar20 == (undefined4 *)0x0) {
                puVar9 = (undefined4 *)0x0;
              }
              else {
                puVar9 = (undefined4 *)
                         (**(code **)(puVar6[2] + 0x34))
                                   (puVar6,0x16,*(int *)(puVar6[0xf] + 4) + uVar22 + 0xc,puVar20,0);
                if ((int)puVar9 < 1) goto LAB_004a5b2c;
                if (puVar20 != puVar9) {
                  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xfd,0x2f,"d1_both.c",0x374);
                  iVar8 = 0x2f;
                  goto LAB_004a5ba8;
                }
              }
              *piVar3 = 1;
              puVar6[0x11] = puVar9;
              goto LAB_004a5768;
            }
            goto LAB_004a5ba8;
          }
        }
        else {
          if (puStack_2c8 < (undefined4 *)(uVar22 + (int)puVar20)) goto LAB_004a589c;
          param_4 = &uStack_2a0;
          uStack_2a0 = 0;
          uStack_29c = (uint)uStack_294;
          ptr = (int *)(*(code *)PTR_pqueue_find_006a93f4)(*(undefined4 *)(iVar8 + 0x244),param_4);
          if ((ptr != (int *)0x0) && (puVar20 < puStack_2c8)) {
            ptr = (int *)0x0;
          }
          uVar22 = (uint)*(ushort *)(puVar6[0x17] + 0x228);
          if (((uStack_2c4 >> 0x10 <= uVar22) || (uVar22 + 10 < uStack_2c4 >> 0x10)) ||
             ((ptr != (int *)0x0 || ((uVar22 == 0 && (iStack_2cc._0_1_ == '\x14')))))) {
            param_4 = (undefined4 *)0x100;
            if (puVar20 == (undefined4 *)0x0) {
              puVar9 = (undefined4 *)0xfffffffd;
            }
            else {
              do {
                puVar17 = (undefined4 *)0x100;
                if (puVar20 < (undefined4 *)0x101) {
                  puVar17 = puVar20;
                }
                puVar9 = (undefined4 *)
                         (**(code **)(puVar6[2] + 0x34))(puVar6,0x16,auStack_28c,puVar17,0);
                if ((int)puVar9 < 1) {
                  if (ptr == (int *)0x0) goto LAB_004a58a0;
                  goto LAB_004a5adc;
                }
                puVar20 = (undefined4 *)((int)puVar20 - (int)puVar9);
                puVar9 = (undefined4 *)0xfffffffd;
              } while (puVar20 != (undefined4 *)0x0);
            }
            goto LAB_004a5768;
          }
          if (puVar20 == (undefined4 *)0x0) goto LAB_004a5dd4;
          if (puStack_2c8 <= puVar20) {
            ptr = (int *)CRYPTO_malloc(0x34,"d1_both.c",0xb3);
            if (ptr == (int *)0x0) goto LAB_004a589c;
            pvVar21 = CRYPTO_malloc((int)puVar20,"d1_both.c",0xb9);
            if (pvVar21 != (void *)0x0) {
              ptr[0xb] = (int)pvVar21;
              ptr[0xc] = 0;
              piVar4 = ptr;
              do {
                piVar13 = piVar4;
                piVar10 = piVar12;
                piVar12 = piVar10 + 4;
                iVar19 = piVar10[1];
                iVar16 = piVar10[2];
                iVar8 = piVar10[3];
                *piVar13 = *piVar10;
                piVar13[1] = iVar19;
                piVar13[2] = iVar16;
                piVar13[3] = iVar8;
                piVar4 = piVar13 + 4;
              } while (piVar12 != &iStack_2ac);
              iVar16 = piVar10[5];
              iVar8 = piVar10[6];
              piVar13[4] = *piVar12;
              piVar13[5] = iVar16;
              piVar13[6] = iVar8;
              puVar9 = (undefined4 *)(**(code **)(puVar6[2] + 0x34))(puVar6,0x16,pvVar21,puVar20,0);
              if ((int)puVar9 < 1) goto LAB_004a5ea0;
              if (puVar20 != puVar9) goto LAB_004a5ea0;
              goto LAB_004a5e78;
            }
            puVar9 = (undefined4 *)0xffffffff;
            CRYPTO_free(ptr);
            goto LAB_004a58a0;
          }
        }
        puVar9 = (undefined4 *)dtls1_reassemble_fragment(puVar6,piVar12,piVar3);
      }
      else {
        uVar14 = 0x327;
LAB_004a5be4:
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xfd,0xf4,"d1_both.c",uVar14);
        iVar8 = 10;
LAB_004a5ba8:
        ssl3_send_alert(puVar6,2,iVar8);
        puVar9 = (undefined4 *)0xffffffff;
        puVar6[0x11] = 0;
        *piVar3 = 0;
      }
      goto LAB_004a5768;
    }
  }
  else {
    puVar9 = *(undefined4 **)((int)pvVar21 + 0x10);
    (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(puVar6[0x17] + 0x244));
    param_4 = (undefined4 *)dtls1_preprocess_fragment(puVar6,pvVar21,param_4);
    if (param_4 == (undefined4 *)0x0) {
      (*(code *)PTR_memcpy_006aabf4)
                (*(int *)(puVar6[0xf] + 4) + *(int *)((int)pvVar21 + 0xc) + 0xc,
                 *(undefined4 *)((int)pvVar21 + 0x2c),*(undefined4 *)((int)pvVar21 + 0x10));
    }
    if (*(int *)((int)pvVar21 + 0x14) != 0) {
      (*(code *)PTR_EVP_CIPHER_CTX_free_006a93f8)(*(undefined4 *)((int)pvVar21 + 0x18));
      (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)(*(undefined4 *)((int)pvVar21 + 0x1c));
    }
    if (*(void **)((int)pvVar21 + 0x2c) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)pvVar21 + 0x2c));
    }
    if (*(void **)((int)pvVar21 + 0x30) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)pvVar21 + 0x30));
    }
    CRYPTO_free(pvVar21);
    (*(code *)PTR_pitem_free_006a939c)(iVar8);
    if (param_4 != (undefined4 *)0x0) {
      ssl3_send_alert(puVar6,2,param_4);
      puVar9 = (undefined4 *)0xffffffff;
      puVar6[0x11] = 0;
      *piVar3 = 0;
      goto LAB_004a5768;
    }
    *piVar3 = 1;
  }
  puVar6[0x11] = puVar9;
LAB_004a5768:
  while (iStack_18c != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    piVar12 = extraout_v1;
LAB_004a5dd4:
    ptr = (int *)CRYPTO_malloc(0x34,"d1_both.c",0xb3);
    if (ptr == (int *)0x0) {
LAB_004a589c:
      puVar9 = (undefined4 *)0xffffffff;
LAB_004a58a0:
      *piVar3 = 0;
    }
    else {
      ptr[0xb] = 0;
      ptr[0xc] = 0;
      piVar4 = ptr;
      do {
        piVar13 = piVar12;
        piVar10 = piVar4;
        piVar12 = piVar13 + 4;
        iVar19 = piVar13[1];
        iVar16 = piVar13[2];
        iVar8 = piVar13[3];
        *piVar10 = *piVar13;
        piVar10[1] = iVar19;
        piVar10[2] = iVar16;
        piVar10[3] = iVar8;
        piVar4 = piVar10 + 4;
      } while (piVar12 != &iStack_2ac);
      puVar9 = (undefined4 *)0xffffffff;
      iVar16 = piVar13[5];
      iVar8 = piVar13[6];
      piVar10[4] = *piVar12;
      piVar10[5] = iVar16;
      piVar10[6] = iVar8;
LAB_004a5e78:
      param_4[1] = 0;
      uStack_2a0 = 0;
      uStack_29c = uStack_29c & 0xffff0000 | (uint)uStack_2c4._0_2_;
      iVar8 = (*(code *)PTR_pitem_new_006a93bc)(param_4,ptr);
      if (iVar8 == 0) {
LAB_004a5ea0:
        if (ptr[5] != 0) {
          (*(code *)PTR_EVP_CIPHER_CTX_free_006a93f8)(ptr[6]);
          (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)(ptr[7]);
        }
        if ((void *)ptr[0xb] != (void *)0x0) {
          CRYPTO_free((void *)ptr[0xb]);
        }
        if ((void *)ptr[0xc] != (void *)0x0) {
          CRYPTO_free((void *)ptr[0xc]);
        }
LAB_004a5adc:
        CRYPTO_free(ptr);
        *piVar3 = 0;
      }
      else {
        (*(code *)PTR_pqueue_insert_006a93c0)(*(undefined4 *)(puVar6[0x17] + 0x244),iVar8);
        puVar9 = (undefined4 *)0xfffffffd;
      }
    }
  }
  return puVar9;
}

