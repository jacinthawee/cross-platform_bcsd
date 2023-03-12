
int ** b64_read(int param_1,int **param_2,int **param_3)

{
  undefined uVar1;
  byte bVar2;
  bool bVar3;
  undefined *puVar4;
  undefined *puVar5;
  int *piVar6;
  int **ppiVar7;
  int **ppiVar8;
  int **ppiVar9;
  uint uVar10;
  int **ppiVar11;
  int iVar12;
  int **ppiVar13;
  int **ppiVar14;
  int *piVar15;
  int **ppiVar16;
  int **ppiVar17;
  int iVar18;
  int **ppiVar19;
  int **ppiVar20;
  int **ppiVar21;
  int **ppiVar22;
  int **ppiVar23;
  int iVar24;
  int **ppiStack_a4;
  int **local_44;
  int **local_40;
  int **local_38;
  int *local_30;
  int local_2c;
  
  puVar5 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_38 = (int **)0x0;
  if ((param_2 != (int **)0x0) && (ppiVar23 = *(int ***)(param_1 + 0x20), ppiVar23 != (int **)0x0))
  {
    if (*(int *)(param_1 + 0x24) == 0) {
      local_38 = (int **)0x0;
    }
    else {
      ppiVar16 = (int **)&DAT_0000000f;
      ppiVar17 = param_3;
      (*(code *)PTR_BIO_clear_flags_006a9260)();
      puVar4 = PTR_EVP_DecodeInit_006a9c04;
      if (ppiVar23[4] != (int *)&SUB_00000002) {
        ppiVar23[4] = (int *)&SUB_00000002;
        *ppiVar23 = (int *)0x0;
        ppiVar23[1] = (int *)0x0;
        ppiVar23[2] = (int *)0x0;
        (*(code *)puVar4)(ppiVar23 + 7);
      }
      piVar6 = *ppiVar23;
      if ((int)piVar6 < 1) {
        if ((0 < (int)param_3) && (0 < (int)ppiVar23[6])) {
          local_40 = (int **)0x0;
          local_44 = param_2;
          goto LAB_00542740;
        }
        (*(code *)PTR_BIO_copy_next_retry_006a9554)(param_1);
        local_38 = (int **)0x0;
        param_2 = ppiVar16;
        param_3 = ppiVar17;
      }
      else {
        piVar15 = ppiVar23[1];
        if ((int)piVar6 < (int)piVar15) {
          (*(code *)PTR_OpenSSLDie_006a8d4c)("bio_b64.c",0xa9,"ctx->buf_len >= ctx->buf_off");
          piVar6 = *ppiVar23;
          piVar15 = ppiVar23[1];
        }
        local_40 = (int **)((int)piVar6 - (int)piVar15);
        if ((int)param_3 <= (int)(int **)((int)piVar6 - (int)piVar15)) {
          local_40 = param_3;
        }
        if (0x5dd < (int)local_40 + (int)piVar15) {
          (*(code *)PTR_OpenSSLDie_006a8d4c)
                    ("bio_b64.c",0xac,"ctx->buf_off+i < (int)sizeof(ctx->buf)");
          piVar15 = ppiVar23[1];
        }
        ppiVar17 = (int **)((int)ppiVar23 + (int)piVar15 + 0x7c);
        ppiVar16 = local_40;
        (*(code *)PTR_memcpy_006aabf4)(param_2);
        local_44 = (int **)((int)param_2 + (int)local_40);
        param_3 = (int **)((int)param_3 - (int)local_40);
        piVar6 = ppiVar23[1];
        ppiVar23[1] = (int *)((int)local_40 + (int)piVar6);
        if ((int *)((int)local_40 + (int)piVar6) == *ppiVar23) {
          *ppiVar23 = (int *)0x0;
          ppiVar23[1] = (int *)0x0;
        }
        if ((0 < (int)param_3) && (0 < (int)ppiVar23[6])) {
LAB_00542740:
          ppiVar7 = ppiVar23 + 0x1f;
          local_38 = (int **)0x0;
          ppiVar8 = ppiVar23 + 7;
LAB_0054275c:
          do {
            ppiVar16 = (int **)(0x400 - (int)ppiVar23[2]);
            ppiVar9 = (int **)(*(code *)PTR_BIO_read_006a85bc)
                                        (*(undefined4 *)(param_1 + 0x24),
                                         (int)ppiVar23 + (int)ppiVar23[2] + 0x65a);
            if ((int)ppiVar9 < 1) {
              ppiVar17 = (int **)&DAT_00000008;
              iVar12 = (*(code *)PTR_BIO_test_flags_006a8954)(*(undefined4 *)(param_1 + 0x24));
              local_38 = ppiVar9;
              if (iVar12 != 0) goto LAB_005428b4;
              piVar6 = ppiVar23[2];
              ppiVar23[6] = (int *)ppiVar9;
              if (piVar6 == (int *)0x0) goto LAB_005428b4;
              ppiVar9 = (int **)0x0;
            }
            else {
              piVar6 = ppiVar23[2];
            }
            ppiVar9 = (int **)((int)ppiVar9 + (int)piVar6);
            ppiVar23[2] = (int *)ppiVar9;
            if (ppiVar23[5] != (int *)0x0) {
              ppiVar17 = (int **)0xffffffff;
              uVar10 = (*(code *)PTR_BIO_test_flags_006a8954)(param_1);
              if ((uVar10 & 0x100) != 0) {
                ppiVar23[2] = (int *)0x0;
                goto LAB_005427b8;
              }
              ppiVar11 = (int **)((int)ppiVar23 + 0x65a);
              if (ppiVar23[5] == (int *)0x0) goto LAB_0054279c;
              if (0 < (int)ppiVar9) {
                ppiVar22 = (int **)((int)ppiVar11 + (int)ppiVar9);
                ppiVar19 = ppiVar11;
                ppiVar13 = ppiVar11;
                ppiVar20 = (int **)0x0;
LAB_005429c4:
                do {
                  ppiVar21 = ppiVar20;
                  ppiVar20 = (int **)((int)ppiVar13 + 1);
                  if (*(char *)ppiVar13 != '\n') goto LAB_005429bc;
                  if (ppiVar23[3] == (int *)0x0) {
                    ppiVar17 = ppiVar7;
                    ppiVar16 = &local_30;
                    iVar12 = (*(code *)PTR_EVP_DecodeUpdate_006a9c0c)
                                       (ppiVar8,ppiVar7,&local_30,ppiVar19,
                                        (int)ppiVar20 - (int)ppiVar19);
                    if (((iVar12 < 1) && (local_30 == (int *)0x0)) && (ppiVar23[5] != (int *)0x0)) {
                      (*(code *)PTR_EVP_DecodeInit_006a9c04)(ppiVar8);
                      ppiVar19 = ppiVar20;
                      goto LAB_005429bc;
                    }
                    if (ppiVar19 != ppiVar11) {
                      ppiVar9 = (int **)((int)ppiVar9 - ((int)ppiVar19 - (int)ppiVar11));
                      ppiVar16 = (int **)((int)ppiVar9 + 0x65a);
                      if (0 < (int)ppiVar9) {
                        ppiVar16 = (int **)((int)ppiVar23 + (int)ppiVar16);
                        ppiVar13 = ppiVar11;
                        ppiVar22 = ppiVar19;
                        do {
                          bVar2 = *(byte *)ppiVar22;
                          ppiVar17 = (int **)(uint)bVar2;
                          ppiVar14 = (int **)((int)ppiVar13 + 1);
                          ppiVar22 = (int **)((int)ppiVar22 + 1);
                          *(byte *)ppiVar13 = bVar2;
                          ppiVar13 = ppiVar14;
                        } while (ppiVar16 != ppiVar14);
                      }
                    }
                    (*(code *)PTR_EVP_DecodeInit_006a9c04)(ppiVar8);
                    ppiVar23[5] = (int *)0x0;
                    if (ppiVar9 == ppiVar21) goto LAB_00542a54;
                    goto LAB_005429f8;
                  }
                  ppiVar23[3] = (int *)0x0;
                  ppiVar19 = ppiVar20;
                  ppiVar13 = ppiVar20;
                  ppiVar20 = (int **)((int)ppiVar21 + 1);
                } while (ppiVar20 != ppiVar22);
                goto LAB_005429f0;
              }
              if (ppiVar9 != (int **)0x0) {
                ppiVar23[2] = (int *)0x0;
                goto LAB_005427b8;
              }
              goto LAB_005428a8;
            }
LAB_0054279c:
            if ((0x3ff < (int)ppiVar9) || ((int)ppiVar23[6] < 1)) goto LAB_005427b8;
          } while( true );
        }
        local_38 = (int **)0x0;
LAB_005428b4:
        (*(code *)PTR_BIO_copy_next_retry_006a9554)(param_1);
        param_2 = ppiVar17;
        param_3 = ppiVar16;
        if (local_40 != (int **)0x0) {
          local_38 = local_40;
        }
      }
    }
  }
  if (local_2c == *(int *)puVar5) {
    return local_38;
  }
  iVar12 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  piVar6 = *(int **)(iVar12 + 0x20);
  (*(code *)PTR_BIO_clear_flags_006a9260)();
  puVar5 = PTR_EVP_EncodeInit_006a9c10;
  if (piVar6[4] != 1) {
    piVar6[4] = 1;
    *piVar6 = 0;
    piVar6[1] = 0;
    piVar6[2] = 0;
    (*(code *)puVar5)(piVar6 + 7);
  }
  if (0x5dd < piVar6[1]) {
    (*(code *)PTR_OpenSSLDie_006a8d4c)("bio_b64.c",0x188,"ctx->buf_off < (int)sizeof(ctx->buf)");
  }
  iVar24 = *piVar6;
  if (0x5de < iVar24) {
    (*(code *)PTR_OpenSSLDie_006a8d4c)("bio_b64.c",0x189,"ctx->buf_len <= (int)sizeof(ctx->buf)");
    iVar24 = *piVar6;
  }
  iVar18 = piVar6[1];
  if (iVar24 < iVar18) {
    (*(code *)PTR_OpenSSLDie_006a8d4c)("bio_b64.c",0x18a,"ctx->buf_len >= ctx->buf_off");
    iVar24 = *piVar6;
    iVar18 = piVar6[1];
  }
  iVar24 = iVar24 - iVar18;
  if (iVar24 < 1) {
LAB_00542d70:
    piVar6[1] = 0;
    *piVar6 = 0;
    if ((param_2 == (int **)0x0) || ((int)param_3 < 1)) {
      return (int **)0x0;
    }
    ppiStack_a4 = (int **)0x0;
    do {
      ppiVar23 = (int **)&DAT_00000400;
      if ((int)param_3 < 0x401) {
        ppiVar23 = param_3;
      }
      uVar10 = (*(code *)PTR_BIO_test_flags_006a8954)(iVar12,0xffffffff);
      if ((uVar10 & 0x100) == 0) {
        (*(code *)PTR_EVP_EncodeUpdate_006a9c18)(piVar6 + 7,piVar6 + 0x1f,piVar6,param_2,ppiVar23);
        iVar24 = *piVar6;
        if (0x5de < iVar24) {
          (*(code *)PTR_OpenSSLDie_006a8d4c)
                    ("bio_b64.c",0x1ce,"ctx->buf_len <= (int)sizeof(ctx->buf)");
          iVar24 = *piVar6;
        }
        if (iVar24 < piVar6[1]) {
          (*(code *)PTR_OpenSSLDie_006a8d4c)("bio_b64.c",0x1cf,"ctx->buf_len >= ctx->buf_off");
          iVar24 = *piVar6;
        }
        ppiStack_a4 = (int **)((int)ppiStack_a4 + (int)ppiVar23);
      }
      else {
        iVar24 = piVar6[2];
        if (iVar24 < 1) {
          if ((int)ppiVar23 < 3) {
            (*(code *)PTR_memcpy_006aabf4)((int)piVar6 + 0x65a,param_2,ppiVar23);
            piVar6[2] = (int)ppiVar23;
            return (int **)((int)ppiVar23 + (int)ppiStack_a4);
          }
          ppiVar23 = (int **)(((int)ppiVar23 / 3) * 3);
          iVar24 = (*(code *)PTR_EVP_EncodeBlock_006a9c14)(piVar6 + 0x1f,param_2,ppiVar23);
          *piVar6 = iVar24;
          if (0x5de < iVar24) {
            (*(code *)PTR_OpenSSLDie_006a8d4c)
                      ("bio_b64.c",0x1c4,"ctx->buf_len <= (int)sizeof(ctx->buf)");
            iVar24 = *piVar6;
          }
          if (iVar24 < piVar6[1]) {
            (*(code *)PTR_OpenSSLDie_006a8d4c)("bio_b64.c",0x1c5,"ctx->buf_len >= ctx->buf_off");
            iVar24 = *piVar6;
          }
          ppiStack_a4 = (int **)((int)ppiStack_a4 + (int)ppiVar23);
        }
        else {
          if (3 < iVar24) {
            (*(code *)PTR_OpenSSLDie_006a8d4c)("bio_b64.c",0x1a8,"ctx->tmp_len <= 3");
            iVar24 = piVar6[2];
          }
          ppiVar23 = (int **)(3 - iVar24);
          if ((int)param_3 < (int)(int **)(3 - iVar24)) {
            ppiVar23 = param_3;
          }
          (*(code *)PTR_memcpy_006aabf4)((int)piVar6 + iVar24 + 0x65a,param_2,ppiVar23);
          iVar24 = piVar6[2];
          ppiStack_a4 = (int **)((int)ppiStack_a4 + (int)ppiVar23);
          piVar6[2] = (int)ppiVar23 + iVar24;
          if ((int)ppiVar23 + iVar24 < 3) {
            return ppiStack_a4;
          }
          iVar24 = (*(code *)PTR_EVP_EncodeBlock_006a9c14)(piVar6 + 0x1f,(int)piVar6 + 0x65a);
          *piVar6 = iVar24;
          if (0x5de < iVar24) {
            (*(code *)PTR_OpenSSLDie_006a8d4c)
                      ("bio_b64.c",0x1b3,"ctx->buf_len <= (int)sizeof(ctx->buf)");
            iVar24 = *piVar6;
          }
          if (iVar24 < piVar6[1]) {
            (*(code *)PTR_OpenSSLDie_006a8d4c)("bio_b64.c",0x1b4,"ctx->buf_len >= ctx->buf_off");
            iVar24 = *piVar6;
          }
          piVar6[2] = 0;
        }
      }
      param_2 = (int **)((int)param_2 + (int)ppiVar23);
      piVar6[1] = 0;
      if (0 < iVar24) {
        ppiVar17 = (int **)(*(code *)PTR_BIO_write_006a7f14)
                                     (*(undefined4 *)(iVar12 + 0x24),piVar6 + 0x1f,iVar24);
        bVar3 = iVar24 < (int)ppiVar17;
        while( true ) {
          if ((int)ppiVar17 < 1) {
            (*(code *)PTR_BIO_copy_next_retry_006a9554)(iVar12);
            if (ppiStack_a4 != (int **)0x0) {
              ppiVar17 = ppiStack_a4;
            }
            return ppiVar17;
          }
          if (bVar3) {
            (*(code *)PTR_OpenSSLDie_006a8d4c)("bio_b64.c",0x1df,"i <= n");
          }
          iVar24 = iVar24 - (int)ppiVar17;
          iVar18 = (int)ppiVar17 + piVar6[1];
          piVar6[1] = iVar18;
          if (0x5de < iVar18) {
            (*(code *)PTR_OpenSSLDie_006a8d4c)
                      ("bio_b64.c",0x1e2,"ctx->buf_off <= (int)sizeof(ctx->buf)");
            iVar18 = piVar6[1];
          }
          if (*piVar6 < iVar18) {
            (*(code *)PTR_OpenSSLDie_006a8d4c)("bio_b64.c",0x1e3,"ctx->buf_len >= ctx->buf_off");
          }
          if (iVar24 < 1) break;
          ppiVar17 = (int **)(*(code *)PTR_BIO_write_006a7f14)
                                       (*(undefined4 *)(iVar12 + 0x24),
                                        (int)piVar6 + piVar6[1] + 0x7c,iVar24);
          bVar3 = iVar24 < (int)ppiVar17;
        }
      }
      param_3 = (int **)((int)param_3 - (int)ppiVar23);
      *piVar6 = 0;
      piVar6[1] = 0;
    } while (0 < (int)param_3);
  }
  else {
    while( true ) {
      ppiStack_a4 = (int **)(*(code *)PTR_BIO_write_006a7f14)
                                      (*(undefined4 *)(iVar12 + 0x24),(int)piVar6 + iVar18 + 0x7c,
                                       iVar24);
      bVar3 = iVar24 < (int)ppiStack_a4;
      if ((int)ppiStack_a4 < 1) break;
      iVar24 = iVar24 - (int)ppiStack_a4;
      if (bVar3) {
        (*(code *)PTR_OpenSSLDie_006a8d4c)("bio_b64.c",0x194,"i <= n");
      }
      iVar18 = (int)ppiStack_a4 + piVar6[1];
      piVar6[1] = iVar18;
      if (0x5de < iVar18) {
        (*(code *)PTR_OpenSSLDie_006a8d4c)
                  ("bio_b64.c",0x196,"ctx->buf_off <= (int)sizeof(ctx->buf)");
        iVar18 = piVar6[1];
      }
      if (*piVar6 < iVar18) {
        (*(code *)PTR_OpenSSLDie_006a8d4c)("bio_b64.c",0x197,"ctx->buf_len >= ctx->buf_off");
      }
      if (iVar24 < 1) goto LAB_00542d70;
      iVar18 = piVar6[1];
    }
    (*(code *)PTR_BIO_copy_next_retry_006a9554)(iVar12);
  }
  return ppiStack_a4;
LAB_005429bc:
  ppiVar13 = ppiVar20;
  ppiVar20 = (int **)((int)ppiVar21 + 1);
  if (ppiVar20 == ppiVar22) goto LAB_005429f0;
  goto LAB_005429c4;
LAB_005429f0:
  ppiVar20 = ppiVar22;
  if (ppiVar9 == (int **)((int)ppiVar21 + 1)) {
LAB_00542a54:
    if (ppiVar19 == ppiVar11) {
      if (ppiVar9 == (int **)&DAT_00000400) {
        ppiVar23[2] = (int *)0x0;
        ppiVar23[3] = (int *)0x1;
      }
    }
    else {
      piVar6 = (int *)((int)ppiVar20 - (int)ppiVar19);
      if (ppiVar20 != ppiVar19) {
        if (0 < (int)piVar6) {
          do {
            uVar1 = *(undefined *)ppiVar19;
            ppiVar9 = (int **)((int)ppiVar11 + 1);
            ppiVar19 = (int **)((int)ppiVar19 + 1);
            *(undefined *)ppiVar11 = uVar1;
            ppiVar11 = ppiVar9;
          } while (ppiVar9 != (int **)((int)ppiVar23 + (int)piVar6 + 0x65a));
        }
        ppiVar23[2] = piVar6;
      }
    }
    goto LAB_005428a8;
  }
LAB_005429f8:
  ppiVar23[2] = (int *)0x0;
LAB_005427b8:
  iVar12 = (int)ppiVar23 + 0x65a;
  uVar10 = (*(code *)PTR_BIO_test_flags_006a8954)(param_1,0xffffffff);
  if ((uVar10 & 0x100) == 0) {
    ppiVar17 = ppiVar7;
    ppiVar16 = ppiVar23;
    ppiVar11 = (int **)(*(code *)PTR_EVP_DecodeUpdate_006a9c0c)
                                 (ppiVar8,ppiVar7,ppiVar23,iVar12,ppiVar9);
    ppiVar23[2] = (int *)0x0;
    ppiVar23[1] = (int *)0x0;
joined_r0x0054294c:
    if ((int)ppiVar11 < 0) {
      *ppiVar23 = (int *)0x0;
      local_38 = (int **)0x0;
      goto LAB_005428b4;
    }
    ppiVar11 = (int **)*ppiVar23;
  }
  else {
    ppiVar19 = (int **)((uint)ppiVar9 & 0xfffffffc);
    ppiVar16 = ppiVar19;
    ppiVar11 = (int **)(*(code *)PTR_EVP_DecodeBlock_006a9c08)(ppiVar7,iVar12);
    if ((2 < (int)ppiVar19) && (*(char *)((int)ppiVar23 + (int)ppiVar19 + 0x659) == '=')) {
      if (*(char *)((int)ppiVar23 + (int)ppiVar19 + 0x658) == '=') {
        ppiVar11 = (int **)((int)ppiVar11 + -2);
      }
      else {
        ppiVar11 = (int **)((int)ppiVar11 + -1);
      }
    }
    ppiVar17 = (int **)((int)ppiVar23 + (int)ppiVar19);
    if (ppiVar9 != ppiVar19) {
      ppiVar17 = (int **)((int)ppiVar17 + 0x65a);
      ppiVar16 = (int **)((int)ppiVar9 - (int)ppiVar19);
      (*(code *)PTR_memmove_006aabfc)(iVar12);
      ppiVar23[2] = (int *)(int **)((int)ppiVar9 - (int)ppiVar19);
    }
    if ((int)ppiVar11 < 1) {
      *ppiVar23 = (int *)0x0;
      ppiVar23[1] = (int *)0x0;
      goto joined_r0x0054294c;
    }
    *ppiVar23 = (int *)ppiVar11;
  }
  if ((int)param_3 <= (int)ppiVar11) {
    ppiVar11 = param_3;
  }
  ppiVar17 = ppiVar7;
  ppiVar16 = ppiVar11;
  (*(code *)PTR_memcpy_006aabf4)(local_44);
  ppiVar23[1] = (int *)ppiVar11;
  local_40 = (int **)((int)local_40 + (int)ppiVar11);
  if ((int **)*ppiVar23 == ppiVar11) {
    *ppiVar23 = (int *)0x0;
    ppiVar23[1] = (int *)0x0;
  }
  param_3 = (int **)((int)param_3 - (int)ppiVar11);
  local_44 = (int **)((int)local_44 + (int)ppiVar11);
  if ((int)param_3 < 1) goto LAB_005428b4;
LAB_005428a8:
  if ((int)ppiVar23[6] < 1) goto LAB_005428b4;
  goto LAB_0054275c;
}

