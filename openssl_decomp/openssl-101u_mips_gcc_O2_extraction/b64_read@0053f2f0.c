
int ** b64_read(BIO *param_1,int **param_2,int **param_3)

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
  int **ppiVar12;
  int **ppiVar13;
  int *piVar14;
  BIO *b;
  int **ppiVar15;
  int **ppiVar16;
  int iVar17;
  int **ppiVar18;
  int **ppiVar19;
  int **ppiVar20;
  int **ppiVar21;
  int **ppiVar22;
  int iVar23;
  int **ppiStack_a4;
  int **local_48;
  int **local_40;
  int **local_38;
  int *local_30;
  BIO *local_2c;
  
  puVar5 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(BIO **)PTR___stack_chk_guard_006a9ae8;
  local_38 = (int **)0x0;
  if ((param_2 != (int **)0x0) && (ppiVar22 = (int **)param_1->ptr, ppiVar22 != (int **)0x0)) {
    if (param_1->next_bio == (bio_st *)0x0) {
      local_38 = (int **)0x0;
    }
    else {
      ppiVar15 = (int **)&DAT_0000000f;
      ppiVar16 = param_3;
      (*(code *)PTR_BIO_clear_flags_006a8138)();
      puVar4 = PTR_EVP_DecodeInit_006a8ae8;
      if (ppiVar22[4] != (int *)&SUB_00000002) {
        ppiVar22[4] = (int *)&SUB_00000002;
        *ppiVar22 = (int *)0x0;
        ppiVar22[1] = (int *)0x0;
        ppiVar22[2] = (int *)0x0;
        (*(code *)puVar4)(ppiVar22 + 7);
      }
      piVar6 = *ppiVar22;
      if ((int)piVar6 < 1) {
        if ((0 < (int)param_3) && (0 < (int)ppiVar22[6])) {
          local_40 = (int **)0x0;
          local_48 = param_2;
          goto LAB_0053f430;
        }
        BIO_copy_next_retry(param_1);
        local_38 = (int **)0x0;
        param_2 = ppiVar15;
        param_3 = ppiVar16;
      }
      else {
        piVar14 = ppiVar22[1];
        if ((int)piVar6 < (int)piVar14) {
          (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0xad,"ctx->buf_len >= ctx->buf_off");
          piVar6 = *ppiVar22;
          piVar14 = ppiVar22[1];
        }
        local_40 = (int **)((int)piVar6 - (int)piVar14);
        if ((int)param_3 <= (int)(int **)((int)piVar6 - (int)piVar14)) {
          local_40 = param_3;
        }
        if (0x5dd < (int)local_40 + (int)piVar14) {
          (*(code *)PTR_OpenSSLDie_006a7c5c)
                    ("bio_b64.c",0xb1,"ctx->buf_off + i < (int)sizeof(ctx->buf)");
          piVar14 = ppiVar22[1];
        }
        ppiVar16 = (int **)((int)ppiVar22 + (int)piVar14 + 0x7c);
        ppiVar15 = local_40;
        (*(code *)PTR_memcpy_006a9aec)(param_2);
        local_48 = (int **)((int)param_2 + (int)local_40);
        param_3 = (int **)((int)param_3 - (int)local_40);
        piVar6 = ppiVar22[1];
        ppiVar22[1] = (int *)((int)local_40 + (int)piVar6);
        if ((int *)((int)local_40 + (int)piVar6) == *ppiVar22) {
          *ppiVar22 = (int *)0x0;
          ppiVar22[1] = (int *)0x0;
        }
        if ((0 < (int)param_3) && (0 < (int)ppiVar22[6])) {
LAB_0053f430:
          ppiVar7 = ppiVar22 + 0x1f;
          local_38 = (int **)0x0;
          ppiVar8 = ppiVar22 + 7;
LAB_0053f44c:
          do {
            ppiVar15 = (int **)(0x400 - (int)ppiVar22[2]);
            ppiVar9 = (int **)(*(code *)PTR_BIO_read_006a74c0)
                                        (param_1->next_bio,(int)ppiVar22 + (int)ppiVar22[2] + 0x65a)
            ;
            if ((int)ppiVar9 < 1) {
              ppiVar16 = (int **)&DAT_00000008;
              iVar23 = (*(code *)PTR_BIO_test_flags_006a7868)(param_1->next_bio);
              local_38 = ppiVar9;
              if (iVar23 != 0) goto LAB_0053f5a4;
              piVar6 = ppiVar22[2];
              ppiVar22[6] = (int *)ppiVar9;
              if (piVar6 == (int *)0x0) goto LAB_0053f5a4;
              ppiVar9 = (int **)0x0;
            }
            else {
              piVar6 = ppiVar22[2];
            }
            ppiVar9 = (int **)((int)ppiVar9 + (int)piVar6);
            ppiVar22[2] = (int *)ppiVar9;
            if (ppiVar22[5] != (int *)0x0) {
              ppiVar16 = (int **)0xffffffff;
              uVar10 = (*(code *)PTR_BIO_test_flags_006a7868)(param_1);
              if ((uVar10 & 0x100) != 0) {
                ppiVar22[2] = (int *)0x0;
                goto LAB_0053f4a8;
              }
              ppiVar11 = (int **)((int)ppiVar22 + 0x65a);
              if (ppiVar22[5] == (int *)0x0) goto LAB_0053f48c;
              local_30 = (int *)0x0;
              if (0 < (int)ppiVar9) {
                ppiVar20 = (int **)((int)ppiVar11 + (int)ppiVar9);
                ppiVar18 = ppiVar11;
                ppiVar12 = ppiVar11;
                ppiVar19 = (int **)0x0;
LAB_0053f6b8:
                do {
                  ppiVar21 = ppiVar19;
                  ppiVar19 = (int **)((int)ppiVar12 + 1);
                  if (*(char *)ppiVar12 != '\n') goto LAB_0053f6b0;
                  if (ppiVar22[3] == (int *)0x0) {
                    ppiVar16 = ppiVar7;
                    ppiVar15 = &local_30;
                    iVar23 = (*(code *)PTR_EVP_DecodeUpdate_006a8af0)
                                       (ppiVar8,ppiVar7,&local_30,ppiVar18,
                                        (int)ppiVar19 - (int)ppiVar18);
                    if (((iVar23 < 1) && (local_30 == (int *)0x0)) && (ppiVar22[5] != (int *)0x0)) {
                      (*(code *)PTR_EVP_DecodeInit_006a8ae8)(ppiVar8);
                      ppiVar18 = ppiVar19;
                      goto LAB_0053f6b0;
                    }
                    if (ppiVar18 != ppiVar11) {
                      ppiVar9 = (int **)((int)ppiVar9 - ((int)ppiVar18 - (int)ppiVar11));
                      ppiVar15 = (int **)((int)ppiVar9 + 0x65a);
                      if (0 < (int)ppiVar9) {
                        ppiVar15 = (int **)((int)ppiVar22 + (int)ppiVar15);
                        ppiVar12 = ppiVar11;
                        ppiVar20 = ppiVar18;
                        do {
                          bVar2 = *(byte *)ppiVar20;
                          ppiVar16 = (int **)(uint)bVar2;
                          ppiVar13 = (int **)((int)ppiVar12 + 1);
                          ppiVar20 = (int **)((int)ppiVar20 + 1);
                          *(byte *)ppiVar12 = bVar2;
                          ppiVar12 = ppiVar13;
                        } while (ppiVar15 != ppiVar13);
                      }
                    }
                    (*(code *)PTR_EVP_DecodeInit_006a8ae8)(ppiVar8);
                    ppiVar22[5] = (int *)0x0;
                    if (ppiVar9 == ppiVar21) goto LAB_0053f748;
                    goto LAB_0053f6ec;
                  }
                  ppiVar22[3] = (int *)0x0;
                  ppiVar18 = ppiVar19;
                  ppiVar12 = ppiVar19;
                  ppiVar19 = (int **)((int)ppiVar21 + 1);
                } while (ppiVar19 != ppiVar20);
                goto LAB_0053f6e4;
              }
              if (ppiVar9 != (int **)0x0) {
                ppiVar22[2] = (int *)0x0;
                goto LAB_0053f4a8;
              }
              goto LAB_0053f598;
            }
LAB_0053f48c:
            if ((0x3ff < (int)ppiVar9) || ((int)ppiVar22[6] < 1)) goto LAB_0053f4a8;
          } while( true );
        }
        local_38 = (int **)0x0;
LAB_0053f5a4:
        BIO_copy_next_retry(param_1);
        param_2 = ppiVar16;
        param_3 = ppiVar15;
        if (local_40 != (int **)0x0) {
          local_38 = local_40;
        }
      }
    }
  }
  if (local_2c == *(BIO **)puVar5) {
    return local_38;
  }
  b = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  piVar6 = (int *)b->ptr;
  (*(code *)PTR_BIO_clear_flags_006a8138)();
  puVar5 = PTR_EVP_EncodeInit_006a8af4;
  if (piVar6[4] != 1) {
    piVar6[4] = 1;
    *piVar6 = 0;
    piVar6[1] = 0;
    piVar6[2] = 0;
    (*(code *)puVar5)(piVar6 + 7);
  }
  if (0x5dd < piVar6[1]) {
    (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x17a,"ctx->buf_off < (int)sizeof(ctx->buf)");
  }
  iVar23 = *piVar6;
  if (0x5de < iVar23) {
    (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x17b,"ctx->buf_len <= (int)sizeof(ctx->buf)");
    iVar23 = *piVar6;
  }
  iVar17 = piVar6[1];
  if (iVar23 < iVar17) {
    (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x17c,"ctx->buf_len >= ctx->buf_off");
    iVar23 = *piVar6;
    iVar17 = piVar6[1];
  }
  iVar23 = iVar23 - iVar17;
  if (iVar23 < 1) {
LAB_0053fa6c:
    piVar6[1] = 0;
    *piVar6 = 0;
    if ((param_2 == (int **)0x0) || ((int)param_3 < 1)) {
      return (int **)0x0;
    }
    ppiStack_a4 = (int **)0x0;
    do {
      ppiVar22 = (int **)&DAT_00000400;
      if ((int)param_3 < 0x401) {
        ppiVar22 = param_3;
      }
      uVar10 = (*(code *)PTR_BIO_test_flags_006a7868)(b,0xffffffff);
      if ((uVar10 & 0x100) == 0) {
        (*(code *)PTR_EVP_EncodeUpdate_006a8afc)(piVar6 + 7,piVar6 + 0x1f,piVar6,param_2,ppiVar22);
        iVar23 = *piVar6;
        if (0x5de < iVar23) {
          (*(code *)PTR_OpenSSLDie_006a7c5c)
                    ("bio_b64.c",0x1bf,"ctx->buf_len <= (int)sizeof(ctx->buf)");
          iVar23 = *piVar6;
        }
        if (iVar23 < piVar6[1]) {
          (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x1c0,"ctx->buf_len >= ctx->buf_off");
          iVar23 = *piVar6;
        }
        ppiStack_a4 = (int **)((int)ppiStack_a4 + (int)ppiVar22);
      }
      else {
        iVar23 = piVar6[2];
        if (iVar23 < 1) {
          if ((int)ppiVar22 < 3) {
            (*(code *)PTR_memcpy_006a9aec)((int)piVar6 + 0x65a,param_2,ppiVar22);
            piVar6[2] = (int)ppiVar22;
            return (int **)((int)ppiVar22 + (int)ppiStack_a4);
          }
          ppiVar22 = (int **)(((int)ppiVar22 / 3) * 3);
          iVar23 = (*(code *)PTR_EVP_EncodeBlock_006a8af8)(piVar6 + 0x1f,param_2,ppiVar22);
          *piVar6 = iVar23;
          if (0x5de < iVar23) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)
                      ("bio_b64.c",0x1b7,"ctx->buf_len <= (int)sizeof(ctx->buf)");
            iVar23 = *piVar6;
          }
          if (iVar23 < piVar6[1]) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x1b8,"ctx->buf_len >= ctx->buf_off");
            iVar23 = *piVar6;
          }
          ppiStack_a4 = (int **)((int)ppiStack_a4 + (int)ppiVar22);
        }
        else {
          if (3 < iVar23) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x196,"ctx->tmp_len <= 3");
            iVar23 = piVar6[2];
          }
          ppiVar22 = (int **)(3 - iVar23);
          if ((int)param_3 < (int)(int **)(3 - iVar23)) {
            ppiVar22 = param_3;
          }
          (*(code *)PTR_memcpy_006a9aec)((int)piVar6 + iVar23 + 0x65a,param_2,ppiVar22);
          iVar23 = piVar6[2];
          ppiStack_a4 = (int **)((int)ppiStack_a4 + (int)ppiVar22);
          piVar6[2] = (int)ppiVar22 + iVar23;
          if ((int)ppiVar22 + iVar23 < 3) {
            return ppiStack_a4;
          }
          iVar23 = (*(code *)PTR_EVP_EncodeBlock_006a8af8)(piVar6 + 0x1f,(int)piVar6 + 0x65a);
          *piVar6 = iVar23;
          if (0x5de < iVar23) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)
                      ("bio_b64.c",0x1a5,"ctx->buf_len <= (int)sizeof(ctx->buf)");
            iVar23 = *piVar6;
          }
          if (iVar23 < piVar6[1]) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x1a6,"ctx->buf_len >= ctx->buf_off");
            iVar23 = *piVar6;
          }
          piVar6[2] = 0;
        }
      }
      param_2 = (int **)((int)param_2 + (int)ppiVar22);
      piVar6[1] = 0;
      if (0 < iVar23) {
        ppiVar16 = (int **)(*(code *)PTR_BIO_write_006a6e14)(b->next_bio,piVar6 + 0x1f,iVar23);
        bVar3 = iVar23 < (int)ppiVar16;
        while( true ) {
          if ((int)ppiVar16 < 1) {
            BIO_copy_next_retry(b);
            if (ppiStack_a4 != (int **)0x0) {
              ppiVar16 = ppiStack_a4;
            }
            return ppiVar16;
          }
          if (bVar3) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x1ce,"i <= n");
          }
          iVar23 = iVar23 - (int)ppiVar16;
          iVar17 = (int)ppiVar16 + piVar6[1];
          piVar6[1] = iVar17;
          if (0x5de < iVar17) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)
                      ("bio_b64.c",0x1d1,"ctx->buf_off <= (int)sizeof(ctx->buf)");
            iVar17 = piVar6[1];
          }
          if (*piVar6 < iVar17) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x1d2,"ctx->buf_len >= ctx->buf_off");
          }
          if (iVar23 < 1) break;
          ppiVar16 = (int **)(*(code *)PTR_BIO_write_006a6e14)
                                       (b->next_bio,(int)piVar6 + piVar6[1] + 0x7c,iVar23);
          bVar3 = iVar23 < (int)ppiVar16;
        }
      }
      param_3 = (int **)((int)param_3 - (int)ppiVar22);
      *piVar6 = 0;
      piVar6[1] = 0;
    } while (0 < (int)param_3);
  }
  else {
    while( true ) {
      ppiStack_a4 = (int **)(*(code *)PTR_BIO_write_006a6e14)
                                      (b->next_bio,(int)piVar6 + iVar17 + 0x7c,iVar23);
      bVar3 = iVar23 < (int)ppiStack_a4;
      if ((int)ppiStack_a4 < 1) break;
      iVar23 = iVar23 - (int)ppiStack_a4;
      if (bVar3) {
        (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x184,"i <= n");
      }
      iVar17 = (int)ppiStack_a4 + piVar6[1];
      piVar6[1] = iVar17;
      if (0x5de < iVar17) {
        (*(code *)PTR_OpenSSLDie_006a7c5c)
                  ("bio_b64.c",0x186,"ctx->buf_off <= (int)sizeof(ctx->buf)");
        iVar17 = piVar6[1];
      }
      if (*piVar6 < iVar17) {
        (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x187,"ctx->buf_len >= ctx->buf_off");
      }
      if (iVar23 < 1) goto LAB_0053fa6c;
      iVar17 = piVar6[1];
    }
    BIO_copy_next_retry(b);
  }
  return ppiStack_a4;
LAB_0053f6b0:
  ppiVar12 = ppiVar19;
  ppiVar19 = (int **)((int)ppiVar21 + 1);
  if (ppiVar19 == ppiVar20) goto LAB_0053f6e4;
  goto LAB_0053f6b8;
LAB_0053f6e4:
  ppiVar19 = ppiVar20;
  if (ppiVar9 == (int **)((int)ppiVar21 + 1)) {
LAB_0053f748:
    if (local_30 == (int *)0x0) {
      if (ppiVar18 == ppiVar11) {
        if (ppiVar9 == (int **)&DAT_00000400) {
          ppiVar22[2] = (int *)0x0;
          ppiVar22[3] = (int *)0x1;
        }
      }
      else {
        piVar6 = (int *)((int)ppiVar19 - (int)ppiVar18);
        if (ppiVar19 != ppiVar18) {
          if (0 < (int)piVar6) {
            do {
              uVar1 = *(undefined *)ppiVar18;
              ppiVar9 = (int **)((int)ppiVar11 + 1);
              ppiVar18 = (int **)((int)ppiVar18 + 1);
              *(undefined *)ppiVar11 = uVar1;
              ppiVar11 = ppiVar9;
            } while (ppiVar9 != (int **)((int)ppiVar22 + (int)piVar6 + 0x65a));
          }
          ppiVar22[2] = piVar6;
        }
      }
      goto LAB_0053f598;
    }
  }
LAB_0053f6ec:
  ppiVar22[2] = (int *)0x0;
LAB_0053f4a8:
  iVar23 = (int)ppiVar22 + 0x65a;
  uVar10 = (*(code *)PTR_BIO_test_flags_006a7868)(param_1,0xffffffff);
  if ((uVar10 & 0x100) == 0) {
    ppiVar16 = ppiVar7;
    ppiVar15 = ppiVar22;
    ppiVar11 = (int **)(*(code *)PTR_EVP_DecodeUpdate_006a8af0)
                                 (ppiVar8,ppiVar7,ppiVar22,iVar23,ppiVar9);
    ppiVar22[2] = (int *)0x0;
    ppiVar22[1] = (int *)0x0;
joined_r0x0053f63c:
    if ((int)ppiVar11 < 0) {
      *ppiVar22 = (int *)0x0;
      local_38 = (int **)0x0;
      goto LAB_0053f5a4;
    }
    ppiVar11 = (int **)*ppiVar22;
  }
  else {
    ppiVar18 = (int **)((uint)ppiVar9 & 0xfffffffc);
    ppiVar15 = ppiVar18;
    ppiVar11 = (int **)(*(code *)PTR_EVP_DecodeBlock_006a8aec)(ppiVar7,iVar23);
    if ((2 < (int)ppiVar18) && (*(char *)((int)ppiVar22 + (int)ppiVar18 + 0x659) == '=')) {
      if (*(char *)((int)ppiVar22 + (int)ppiVar18 + 0x658) == '=') {
        ppiVar11 = (int **)((int)ppiVar11 + -2);
      }
      else {
        ppiVar11 = (int **)((int)ppiVar11 + -1);
      }
    }
    ppiVar16 = (int **)((int)ppiVar22 + (int)ppiVar18);
    if (ppiVar9 != ppiVar18) {
      ppiVar16 = (int **)((int)ppiVar16 + 0x65a);
      ppiVar15 = (int **)((int)ppiVar9 - (int)ppiVar18);
      (*(code *)PTR_memmove_006a9af4)(iVar23);
      ppiVar22[2] = (int *)(int **)((int)ppiVar9 - (int)ppiVar18);
    }
    if ((int)ppiVar11 < 1) {
      *ppiVar22 = (int *)0x0;
      ppiVar22[1] = (int *)0x0;
      goto joined_r0x0053f63c;
    }
    *ppiVar22 = (int *)ppiVar11;
  }
  if ((int)param_3 <= (int)ppiVar11) {
    ppiVar11 = param_3;
  }
  ppiVar16 = ppiVar7;
  ppiVar15 = ppiVar11;
  (*(code *)PTR_memcpy_006a9aec)(local_48);
  ppiVar22[1] = (int *)ppiVar11;
  local_40 = (int **)((int)local_40 + (int)ppiVar11);
  if ((int **)*ppiVar22 == ppiVar11) {
    *ppiVar22 = (int *)0x0;
    ppiVar22[1] = (int *)0x0;
  }
  param_3 = (int **)((int)param_3 - (int)ppiVar11);
  local_48 = (int **)((int)local_48 + (int)ppiVar11);
  if ((int)param_3 < 1) goto LAB_0053f5a4;
LAB_0053f598:
  if ((int)ppiVar22[6] < 1) goto LAB_0053f5a4;
  goto LAB_0053f44c;
}

