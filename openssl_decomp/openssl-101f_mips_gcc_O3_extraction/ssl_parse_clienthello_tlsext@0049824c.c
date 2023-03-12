
int ssl_parse_clienthello_tlsext
              (int *param_1,ushort **param_2,int param_3,int param_4,undefined4 *param_5)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  bool bVar5;
  undefined *puVar6;
  undefined *puVar7;
  uint uVar8;
  ushort *puVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  ushort *puVar13;
  int iVar14;
  int iVar15;
  ushort *puVar16;
  ushort *puVar17;
  char *pcVar18;
  uint uVar19;
  int iVar20;
  undefined4 uVar21;
  ushort *puVar22;
  ushort *local_30;
  int local_2c;
  
  puVar7 = PTR___stack_chk_guard_006aabf0;
  uVar12 = param_1[0x61];
  iVar14 = param_1[0x16];
  puVar17 = *param_2;
  uVar8 = param_1[0x40];
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  param_1[0x49] = 0;
  param_1[0x4a] = -1;
  *(undefined4 *)(iVar14 + 0x41c) = 0;
  param_1[0x61] = uVar12 & 0xfffffffc;
  if ((uVar8 & 0x40) == 0) {
    if ((ushort *)(param_3 + param_4 + -2) <= puVar17) goto LAB_004982f8;
LAB_0049835c:
    puVar22 = puVar17 + 1;
    if ((ushort *)(param_3 + (param_4 - (uint)*puVar17)) < puVar22) goto LAB_004982f8;
    puVar9 = (ushort *)(param_3 + param_4 + -4);
    if (puVar22 <= puVar9) {
      puVar13 = puVar17 + 3;
      uVar3 = puVar17[1];
      uVar8 = (uint)puVar17[2];
      puVar17 = (ushort *)((int)puVar13 + uVar8);
      if (puVar17 <= (ushort *)(param_3 + param_4)) {
        bVar5 = false;
        bVar4 = false;
        puVar16 = puVar22;
LAB_004983e4:
        if ((code *)param_1[0x46] != (code *)0x0) {
          (*(code *)param_1[0x46])(param_1,0,uVar3,puVar13,uVar8,param_1[0x47]);
        }
        puVar6 = PTR_CRYPTO_malloc_006a8108;
        if (uVar3 == 0) {
          if (1 < uVar8) {
            uVar12 = uVar8 - 2 & 0xffff;
            uVar8 = (uint)*puVar13;
            if (uVar8 <= uVar12) {
              iVar14 = uVar8 - 3;
              if (uVar8 < 4) {
LAB_004985a0:
                if (uVar8 == 0) {
                  puVar22 = (ushort *)((int)puVar16 + uVar12 + 6);
                  goto LAB_004985b0;
                }
              }
              else {
                uVar8 = (uint)*(ushort *)((int)puVar16 + 7);
                cVar1 = *(char *)(puVar16 + 3);
                if ((int)uVar8 <= iVar14) {
                  uVar19 = param_1[0x49];
                  pcVar18 = (char *)((int)puVar16 + 9);
                  do {
                    if ((uVar19 == 0) && (cVar1 == '\0')) {
                      iVar15 = param_1[0x1b];
                      if (iVar15 == 0) {
                        iVar20 = param_1[0x30];
                        if (*(int *)(iVar20 + 0xd0) != 0) break;
                        if (uVar8 < 0x100) {
                          iVar10 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar8 + 1,"t1_lib.c",0x423)
                          ;
                          *(int *)(iVar20 + 0xd0) = iVar10;
                          if (iVar10 == 0) goto LAB_004989a4;
                          (*(code *)PTR_memcpy_006aabf4)
                                    (*(undefined4 *)(param_1[0x30] + 0xd0),pcVar18,uVar8);
                          puVar6 = PTR_strlen_006aab30;
                          *(undefined *)(*(int *)(param_1[0x30] + 0xd0) + uVar8) = 0;
                          uVar21 = *(undefined4 *)(param_1[0x30] + 0xd0);
                          uVar19 = (*(code *)puVar6)(uVar21);
                          if (uVar8 == uVar19) {
                            uVar19 = 1;
                            param_1[0x49] = 1;
                            goto joined_r0x00498598;
                          }
                          (*(code *)PTR_CRYPTO_free_006a7f88)(uVar21);
                          *(undefined4 *)(param_1[0x30] + 0xd0) = 0;
                        }
                        *param_5 = 0x70;
                        goto LAB_00498318;
                      }
                      iVar15 = *(int *)(param_1[0x30] + 0xd0);
                      if ((iVar15 == 0) ||
                         (uVar11 = (*(code *)PTR_strlen_006aab30)(iVar15), uVar11 != uVar8)) {
                        param_1[0x49] = 0;
                      }
                      else {
                        iVar15 = (*(code *)PTR_strncmp_006aaa7c)(iVar15,pcVar18,uVar8);
                        uVar19 = (uint)(iVar15 == 0);
                        param_1[0x49] = uVar19;
                      }
                    }
joined_r0x00498598:
                    uVar8 = iVar14 - uVar8;
                    if ((int)uVar8 < 4) goto LAB_004985a0;
                    iVar14 = uVar8 - 3;
                    uVar8 = (uint)*(ushort *)(pcVar18 + 1);
                    cVar1 = *pcVar18;
                    pcVar18 = pcVar18 + 3;
                    if (iVar14 < (int)uVar8) break;
                  } while( true );
                }
              }
            }
          }
        }
        else {
          puVar22 = puVar17;
          if (uVar3 != 0xc) {
            if (uVar3 == 0xb) {
              if (*param_1 != 0xfeff) {
                uVar12 = (uint)*(byte *)(puVar16 + 2);
                if (uVar12 != uVar8 - 1) goto LAB_00498560;
                if (param_1[0x1b] == 0) {
                  iVar14 = param_1[0x30];
                  if (*(int *)(iVar14 + 0xd8) != 0) {
                    (*(code *)PTR_CRYPTO_free_006a7f88)();
                    iVar14 = param_1[0x30];
                    *(undefined4 *)(iVar14 + 0xd8) = 0;
                  }
                  puVar6 = PTR_CRYPTO_malloc_006a8108;
                  *(undefined4 *)(iVar14 + 0xd4) = 0;
                  iVar15 = (*(code *)puVar6)(uVar12,"t1_lib.c",0x475);
                  *(int *)(iVar14 + 0xd8) = iVar15;
                  puVar6 = PTR_memcpy_006aabf4;
                  if (iVar15 == 0) goto LAB_004989a4;
                  iVar14 = param_1[0x30];
                  *(uint *)(iVar14 + 0xd4) = uVar12;
                  (*(code *)puVar6)(*(undefined4 *)(iVar14 + 0xd8),(int)puVar16 + 5,uVar12);
                }
              }
            }
            else if (uVar3 == 10) {
              if (*param_1 != 0xfeff) {
                iVar14 = (uint)*(byte *)((int)puVar16 + 5) + (uint)*(byte *)(puVar16 + 2) * 0x100;
                if ((iVar14 != uVar8 - 2) || (iVar14 == 0)) goto LAB_00498560;
                if (param_1[0x1b] == 0) {
                  iVar15 = param_1[0x30];
                  if (*(int *)(iVar15 + 0xe0) != 0) goto LAB_00498560;
                  *(undefined4 *)(iVar15 + 0xdc) = 0;
                  iVar20 = (*(code *)puVar6)(iVar14,"t1_lib.c",0x49a);
                  *(int *)(iVar15 + 0xe0) = iVar20;
                  puVar6 = PTR_memcpy_006aabf4;
                  if (iVar20 == 0) goto LAB_004989a4;
                  iVar15 = param_1[0x30];
                  *(int *)(iVar15 + 0xdc) = iVar14;
                  (*(code *)puVar6)(*(undefined4 *)(iVar15 + 0xe0),puVar16 + 3,iVar14);
                }
              }
            }
            else if (uVar3 == 0x23) {
              if (((code *)param_1[0x58] != (code *)0x0) &&
                 (iVar14 = (*(code *)param_1[0x58])(param_1,puVar13,uVar8,param_1[0x59]),
                 iVar14 == 0)) {
LAB_004989a4:
                iVar15 = 0;
                *param_5 = 0x50;
                goto LAB_00498318;
              }
            }
            else if (uVar3 == 0xff01) {
              iVar14 = (*(code *)PTR_ssl_parse_clienthello_renegotiate_ext_006a930c)
                                 (param_1,puVar13,uVar8,param_5);
              if (iVar14 == 0) goto LAB_00498770;
              bVar4 = true;
            }
            else {
              if (uVar3 == 0xd) {
                if ((!bVar5) && (1 < uVar8)) {
                  uVar8 = uVar8 - 2 & 0xffff;
                  if ((*puVar13 == uVar8) &&
                     (((*puVar13 & 1) == 0 &&
                      (iVar14 = tls1_process_sigalgs(param_1,puVar16 + 3), iVar14 != 0)))) {
                    bVar5 = true;
                    puVar22 = (ushort *)((int)(puVar16 + 3) + uVar8);
                    goto LAB_004985b0;
                  }
                }
                goto LAB_00498560;
              }
              if (uVar3 == 5) {
                if ((*param_1 != 0xfeff) && (*(int *)(param_1[0x39] + 0x13c) != 0)) {
                  if (uVar8 < 5) goto LAB_00498560;
                  bVar2 = *(byte *)(puVar16 + 2);
                  param_1[0x4a] = (uint)bVar2;
                  if (bVar2 == 1) {
                    uVar12 = uVar8 - 3 & 0xffff;
                    uVar8 = (uint)*(ushort *)((int)puVar16 + 5);
                    puVar22 = (ushort *)((int)puVar16 + 7);
                    if (uVar8 <= uVar12) {
                      if (uVar8 == 0) {
LAB_00498c38:
                        uVar8 = uVar12 - 2 & 0xffff;
                        uVar12 = (uint)*puVar22;
                        puVar22 = puVar22 + 1;
                        if (uVar12 == uVar8) {
                          local_30 = puVar22;
                          if (uVar12 != 0) {
                            if (param_1[0x4d] != 0) {
                              (*(code *)PTR_sk_pop_free_006a8158)
                                        (param_1[0x4d],PTR_X509_EXTENSION_free_006a8268);
                            }
                            iVar14 = (*(code *)PTR_d2i_X509_EXTENSIONS_006a9318)(0,&local_30,uVar12)
                            ;
                            param_1[0x4d] = iVar14;
                            if ((iVar14 == 0) || (local_30 != (ushort *)((int)puVar22 + uVar12)))
                            goto LAB_00498c14;
                            puVar22 = (ushort *)((int)puVar22 + uVar8);
                          }
                          goto LAB_004985b0;
                        }
                      }
                      else {
                        puVar17 = (ushort *)((int)puVar16 + 9);
                        if (3 < uVar8) {
                          uVar19 = (uint)*(ushort *)((int)puVar16 + 7);
                          uVar12 = (uVar12 - uVar19) - 2;
                          iVar14 = uVar8 - (uVar19 + 2);
                          if (-1 < iVar14) {
                            while( true ) {
                              uVar12 = uVar12 & 0xffff;
                              puVar22 = (ushort *)((int)puVar17 + uVar19);
                              local_30 = puVar17;
                              iVar15 = (*(code *)PTR_d2i_OCSP_RESPID_006a9310)(0,&local_30,uVar19);
                              if (iVar15 == 0) goto LAB_00498c14;
                              if (puVar22 != local_30) {
                                (*(code *)PTR_OCSP_RESPID_free_006a9314)(iVar15);
                                goto LAB_00498c14;
                              }
                              iVar20 = param_1[0x4c];
                              if (iVar20 == 0) {
                                iVar20 = (*(code *)PTR_sk_new_null_006a80a4)();
                                param_1[0x4c] = iVar20;
                                if (iVar20 == 0) goto LAB_00498ccc;
                              }
                              iVar20 = (*(code *)PTR_sk_push_006a80a8)(iVar20,iVar15);
                              if (iVar20 == 0) goto LAB_00498ccc;
                              if (iVar14 == 0) break;
                              puVar17 = puVar22 + 1;
                              if (iVar14 < 4) goto LAB_00498c14;
                              uVar19 = (uint)*puVar22;
                              iVar14 = iVar14 - (uVar19 + 2);
                              uVar12 = uVar12 + (-2 - uVar19);
                              if (iVar14 < 0) goto LAB_00498c14;
                            }
                            if (1 < uVar12) goto LAB_00498c38;
                          }
                        }
                      }
                    }
LAB_00498c14:
                    iVar15 = 0;
                    *param_5 = 0x32;
                    goto LAB_00498318;
                  }
                  param_1[0x4a] = -1;
                  puVar22 = (ushort *)((int)puVar16 + (uVar8 - 1 & 0xffff) + 5);
                }
              }
              else if (uVar3 == 0xf) {
                if (*(char *)(puVar16 + 2) == '\x01') {
                  param_1[0x61] = param_1[0x61] | 1;
                }
                else {
                  if (*(char *)(puVar16 + 2) != '\x02') {
                    iVar15 = 0;
                    *param_5 = 0x2f;
                    goto LAB_00498318;
                  }
                  param_1[0x61] = param_1[0x61] | 3;
                }
              }
              else if (uVar3 == 0x3374) {
                if (*(int *)(param_1[0x16] + 0x2b4) == 0) {
                  *(undefined4 *)(param_1[0x16] + 0x41c) = 1;
                }
              }
              else if ((uVar3 == 0xe) &&
                      (iVar14 = ssl_parse_clienthello_use_srtp_ext(param_1,puVar13,uVar8,param_5),
                      iVar14 != 0)) {
                iVar15 = 0;
                goto LAB_00498318;
              }
            }
LAB_004985b0:
            if (puVar9 < puVar22) goto LAB_00498a60;
            puVar13 = puVar22 + 2;
            uVar3 = *puVar22;
            uVar8 = (uint)puVar22[1];
            puVar17 = (ushort *)((int)puVar13 + uVar8);
            puVar16 = puVar22;
            if ((ushort *)(param_3 + param_4) < puVar17) goto LAB_004985f0;
            goto LAB_004983e4;
          }
          if (((uVar8 != 0) && (uVar12 = (uint)*(byte *)(puVar16 + 2), uVar12 == uVar8 - 1)) &&
             (param_1[0x69] == 0)) {
            iVar14 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar8,"t1_lib.c",0x454);
            param_1[0x69] = iVar14;
            if (iVar14 != 0) {
              (*(code *)PTR_memcpy_006aabf4)(iVar14,(int)puVar16 + 5,uVar12);
              puVar6 = PTR_strlen_006aab30;
              *(undefined *)(param_1[0x69] + uVar12) = 0;
              uVar8 = (*(code *)puVar6)(param_1[0x69]);
              if (uVar12 == uVar8) goto LAB_004985b0;
              goto LAB_00498560;
            }
            iVar15 = -1;
            goto LAB_00498318;
          }
        }
LAB_00498560:
        iVar15 = 0;
        *param_5 = 0x32;
        goto LAB_00498318;
      }
      goto LAB_004982f8;
    }
    bVar4 = false;
LAB_00498a60:
    *param_2 = puVar22;
LAB_004985f0:
    if (!bVar4) {
      iVar14 = param_1[100];
      goto LAB_004982fc;
    }
  }
  else {
    if (puVar17 < (ushort *)(param_3 + param_4 + -2)) {
      if ((puVar17 + 1 <= (ushort *)(param_3 + param_4 + -4)) && (puVar17[1] == 0)) {
        uVar8 = param_3 + param_4;
        uVar12 = (int)puVar17 + puVar17[2] + 6;
        if (uVar12 <= uVar8) {
          if ((param_1[0x44] >> 8 == 3) && (0x302 < param_1[0x44])) {
            if ((uVar8 == uVar12 + 0x22) &&
               ((iVar15 = (*(code *)PTR_memcmp_006aabd8)(uVar12,kSafariExtensionsBlock_17581,0x12),
                iVar15 == 0 &&
                (iVar15 = (*(code *)PTR_memcmp_006aabd8)
                                    (uVar12 + 0x12,kSafariTLS12ExtensionsBlock_17582,0x10),
                iVar15 == 0)))) {
              *(undefined *)(iVar14 + 0x420) = 1;
            }
          }
          else if ((uVar8 == uVar12 + 0x12) &&
                  (iVar15 = (*(code *)PTR_memcmp_006aabd8)(uVar12,kSafariExtensionsBlock_17581,0x12)
                  , iVar15 == 0)) {
            *(undefined *)(iVar14 + 0x420) = 1;
          }
        }
      }
      goto LAB_0049835c;
    }
LAB_004982f8:
    iVar14 = param_1[100];
LAB_004982fc:
    puVar6 = PTR_ERR_put_error_006a9030;
    if ((iVar14 != 0) && (-1 < param_1[0x40] << 0xd)) {
      *param_5 = 0x28;
      (*(code *)puVar6)(0x14,0x12e,0x152,"t1_lib.c",0x59f);
LAB_00498770:
      iVar15 = 0;
      goto LAB_00498318;
    }
  }
  iVar15 = 1;
LAB_00498318:
  while (local_2c != *(int *)puVar7) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00498ccc:
    (*(code *)PTR_OCSP_RESPID_free_006a9314)(iVar15);
    *param_5 = 0x50;
    iVar15 = 0;
  }
  return iVar15;
}

