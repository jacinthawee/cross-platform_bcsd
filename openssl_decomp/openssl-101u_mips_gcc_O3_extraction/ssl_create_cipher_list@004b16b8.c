
int * ssl_create_cipher_list(int param_1,int **param_2,uint *param_3,char *param_4)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int **ppiVar17;
  int *piVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int *piVar22;
  int *piVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint unaff_s0;
  uint uVar28;
  int *unaff_s1;
  uint uVar29;
  uint uVar30;
  int *unaff_s4;
  int iVar31;
  int iVar32;
  uint *unaff_s6;
  int *piVar33;
  uint unaff_s8;
  uint local_58;
  char *local_54;
  uint local_4c;
  char *local_44;
  int *local_3c;
  int *local_38;
  int local_34;
  int local_30;
  int *local_2c;
  
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  local_3c = (int *)0x0;
  local_38 = (int *)0x0;
  local_2c = *(int **)PTR___stack_chk_guard_006a9ae8;
  local_54 = param_4;
  if (((param_4 == (char *)0x0) || (param_2 == (int **)0x0)) ||
     (unaff_s6 = param_3, param_3 == (uint *)0x0)) {
    piVar33 = (int *)0x0;
    param_3 = unaff_s6;
    goto LAB_004b2324;
  }
  local_34 = 0;
  local_30 = 0;
  iVar5 = (*(code *)PTR_EVP_PKEY_asn1_find_str_006a6fbc)(&local_34,"gost94",0xffffffff);
  if ((iVar5 == 0) ||
     (iVar5 = (*(code *)PTR_EVP_PKEY_asn1_get0_info_006a6fc0)(&local_30,0,0,0,0,iVar5), 0 < iVar5))
  {
    if (local_34 != 0) goto LAB_004b178c;
LAB_004b17a0:
    uVar29 = 0x300;
    unaff_s0 = 0x328;
    if (local_30 != 0) {
      uVar29 = 0x200;
    }
    uVar28 = 0x128;
    if (local_30 != 0) {
      unaff_s0 = 0x228;
      uVar28 = 0x28;
    }
  }
  else {
    local_30 = 0;
    if (local_34 != 0) {
LAB_004b178c:
      (*(code *)PTR_ENGINE_finish_006a6fc4)();
      goto LAB_004b17a0;
    }
    uVar29 = 0x300;
    unaff_s0 = 0x328;
    uVar28 = 0x128;
  }
  local_34 = 0;
  local_30 = 0;
  iVar5 = (*(code *)PTR_EVP_PKEY_asn1_find_str_006a6fbc)(&local_34,"gost2001",0xffffffff);
  if ((iVar5 == 0) ||
     (iVar5 = (*(code *)PTR_EVP_PKEY_asn1_get0_info_006a6fc0)(&local_30,0,0,0,0,iVar5), 0 < iVar5))
  {
    if (local_34 != 0) goto LAB_004b1820;
LAB_004b1830:
    if (local_30 == 0) goto LAB_004b2374;
    unaff_s8 = 0xffffffe9;
    uVar30 = 0x16;
    unaff_s0 = uVar28;
  }
  else {
    local_30 = 0;
    if (local_34 != 0) {
LAB_004b1820:
      (*(code *)PTR_ENGINE_finish_006a6fc4)();
      goto LAB_004b1830;
    }
LAB_004b2374:
    unaff_s8 = 0xfffffde9;
    if ((uVar29 ^ 0x300) != 0) {
      unaff_s8 = 0xffffffe9;
    }
    uVar30 = 0x16;
    if ((uVar29 ^ 0x300) == 0) {
      uVar30 = 0x216;
    }
  }
  uVar21 = 4;
  uVar29 = 2;
  uVar19 = 4;
  uVar24 = 0x10;
  uVar28 = 8;
  if (ssl_cipher_methods._4_4_ != 0) {
    uVar29 = 0;
  }
  if (ssl_cipher_methods._8_4_ != 0) {
    uVar19 = 0;
  }
  uVar12 = 0x10;
  uVar20 = 8;
  if (ssl_cipher_methods._16_4_ != 0) {
    uVar12 = 0;
  }
  if (ssl_cipher_methods._12_4_ != 0) {
    uVar20 = 0;
  }
  uVar13 = 0x40;
  if (ssl_cipher_methods._24_4_ != 0) {
    uVar13 = 0;
  }
  uVar6 = 0x1000;
  uVar27 = 0x80;
  if (ssl_digest_methods._16_4_ != 0) {
    uVar24 = 0;
  }
  if (ssl_cipher_methods._48_4_ != 0) {
    uVar6 = 0;
  }
  if (ssl_cipher_methods._28_4_ != 0) {
    uVar27 = 0;
  }
  uVar7 = 0x2000;
  if (ssl_cipher_methods._52_4_ != 0) {
    uVar7 = 0;
  }
  uVar14 = 0x100;
  if (ssl_cipher_methods._32_4_ != 0) {
    uVar14 = 0;
  }
  uVar16 = 0x200;
  uVar15 = 2;
  if (ssl_digest_methods._4_4_ != 0) {
    uVar15 = 0;
  }
  if (ssl_cipher_methods._36_4_ != 0) {
    uVar16 = 0;
  }
  uVar26 = 0x400;
  uVar8 = 0x20;
  if (ssl_cipher_methods._40_4_ != 0) {
    uVar26 = 0;
  }
  uVar25 = 0x800;
  if (ssl_digest_methods._20_4_ != 0) {
    uVar8 = 0;
  }
  if (ssl_cipher_methods._44_4_ != 0) {
    uVar25 = 0;
  }
  if (ssl_digest_methods._8_4_ != 0) {
    uVar21 = 0;
  }
  local_58 = ssl_cipher_methods._0_4_ == 0 | uVar29 | uVar19 | uVar20 | uVar12 | uVar13 | uVar27 |
             uVar6 | uVar7 | uVar14 | uVar16 | uVar26 | uVar25;
  if (ssl_digest_methods._12_4_ == 0) {
    uVar28 = 8;
  }
  else if (ssl_mac_pkey_id._12_4_ != 0) {
    uVar28 = 0;
  }
  local_4c = uVar15 | ssl_digest_methods._0_4_ == 0 | uVar24 | uVar8 | uVar21 | uVar28;
  unaff_s1 = (int *)(**(code **)(param_1 + 0x54))();
  local_44 = "-check_ss_sig";
  unaff_s4 = (int *)CRYPTO_malloc((int)unaff_s1 * 0x14,"ssl_ciph.c",0x584);
  if (unaff_s4 == (int *)0x0) {
    uVar11 = 0x586;
    goto LAB_004b2560;
  }
  if (0 < (int)unaff_s1) {
    piVar33 = (int *)0x0;
    iVar5 = 0;
    do {
      piVar9 = (int *)(**(code **)(param_1 + 0x58))(piVar33);
      iVar31 = iVar5;
      if (((((piVar9 != (int *)0x0) && (*piVar9 != 0)) && ((uVar30 & piVar9[3]) == 0)) &&
          (((unaff_s0 & piVar9[4]) == 0 && ((local_58 & piVar9[5]) == 0)))) &&
         ((local_4c & piVar9[6]) == 0)) {
        iVar31 = iVar5 + 1;
        ppiVar17 = (int **)(unaff_s4 + iVar5 * 5);
        *ppiVar17 = piVar9;
        ppiVar17[3] = (int *)0x0;
        ppiVar17[4] = (int *)0x0;
        ppiVar17[1] = (int *)0x0;
      }
      piVar33 = (int *)((int)piVar33 + 1);
      iVar5 = iVar31;
    } while (unaff_s1 != piVar33);
    if (iVar31 == 0) goto LAB_004b2458;
    unaff_s4[4] = 0;
    local_38 = unaff_s4;
    if (iVar31 != 1) {
      unaff_s4[3] = (int)(unaff_s4 + 5);
      if (iVar31 == 2) {
        iVar5 = 8;
        iVar32 = 0x20;
      }
      else {
        iVar5 = iVar31 * 4;
        iVar32 = iVar31 * 0x10;
        piVar33 = unaff_s4 + 10;
        do {
          piVar33[-2] = (int)piVar33;
          piVar9 = piVar33 + 5;
          piVar33[-1] = (int)(piVar33 + -10);
          piVar33 = piVar9;
        } while (unaff_s4 + iVar31 * 5 != piVar9);
      }
      local_38 = (int *)((int)unaff_s4 + iVar5 + iVar32 + -0x14);
      local_38[4] = (int)unaff_s4 + iVar5 + iVar32 + -0x28;
    }
    local_38[3] = 0;
    local_3c = unaff_s4;
LAB_004b1af0:
    piVar9 = local_3c;
    piVar33 = local_38;
    if (local_3c != (int *)0x0) {
      do {
        piVar22 = (int *)local_3c[3];
        if (((*(uint *)(*local_3c + 0xc) & 0x80) != 0) && (local_3c[1] == 0)) {
          if (piVar33 != local_3c) {
            iVar5 = local_3c[4];
            if (piVar9 == local_3c) {
              piVar9 = piVar22;
            }
            piVar18 = piVar22;
            if (iVar5 != 0) {
              *(int **)(iVar5 + 0xc) = piVar22;
              piVar18 = (int *)local_3c[3];
            }
            if (piVar18 != (int *)0x0) {
              piVar18[4] = iVar5;
            }
            piVar33[3] = (int)local_3c;
            local_3c[4] = (int)piVar33;
            local_3c[3] = 0;
          }
          local_3c[1] = 1;
          piVar33 = local_3c;
        }
      } while ((local_38 != local_3c) && (local_3c = piVar22, piVar22 != (int *)0x0));
      goto LAB_004b1b6c;
    }
LAB_004b2530:
    local_3c = (int *)0x0;
    goto LAB_004b208c;
  }
LAB_004b2458:
  if (local_38 != (int *)0x0) goto LAB_004b1af0;
  piVar33 = (int *)0x0;
  piVar9 = local_3c;
LAB_004b1b6c:
  if (piVar9 == (int *)0x0) {
    local_3c = piVar33;
    if (piVar33 != (int *)0x0) goto LAB_004b25b8;
  }
  else {
    local_3c = piVar9;
    piVar22 = piVar33;
    if (piVar33 != (int *)0x0) {
      do {
        piVar18 = (int *)piVar33[4];
        if (((*(uint *)(*piVar33 + 0xc) & 0x80) != 0) && (piVar33[1] != 0)) {
          if (local_3c != piVar33) {
            iVar5 = piVar33[3];
            if (piVar33 == piVar22) {
              piVar22 = piVar18;
            }
            piVar23 = piVar18;
            if (iVar5 != 0) {
              *(int **)(iVar5 + 0x10) = piVar18;
              piVar23 = (int *)piVar33[4];
            }
            if (piVar23 != (int *)0x0) {
              piVar23[3] = iVar5;
            }
            local_3c[4] = (int)piVar33;
            piVar33[3] = (int)local_3c;
            piVar33[4] = 0;
          }
          piVar33[1] = 0;
          local_3c = piVar33;
        }
      } while ((piVar9 != piVar33) && (piVar33 = piVar18, piVar18 != (int *)0x0));
      piVar33 = local_3c;
      piVar9 = piVar22;
      if (piVar22 != (int *)0x0) {
        do {
          piVar18 = (int *)piVar33[3];
          if (((*(uint *)(*piVar33 + 0x14) & 0x30c0) != 0) && (piVar33[1] == 0)) {
            if (piVar33 != piVar9) {
              iVar5 = piVar33[4];
              if (piVar33 == local_3c) {
                local_3c = piVar18;
              }
              piVar23 = piVar18;
              if (iVar5 != 0) {
                *(int **)(iVar5 + 0xc) = piVar18;
                piVar23 = (int *)piVar33[3];
              }
              if (piVar23 != (int *)0x0) {
                piVar23[4] = iVar5;
              }
              piVar9[3] = (int)piVar33;
              piVar33[4] = (int)piVar9;
              piVar33[3] = 0;
              piVar9 = piVar33;
            }
            piVar33[1] = 1;
          }
        } while ((piVar33 != piVar22) && (piVar33 = piVar18, piVar18 != (int *)0x0));
        piVar22 = local_3c;
        piVar33 = piVar9;
        if (local_3c == (int *)0x0) goto LAB_004b25d0;
        do {
          piVar18 = (int *)piVar22[3];
          if (piVar22[1] == 0) {
            if (piVar22 != piVar33) {
              iVar5 = piVar22[4];
              if (local_3c == piVar22) {
                local_3c = piVar18;
              }
              piVar23 = piVar18;
              if (iVar5 != 0) {
                *(int **)(iVar5 + 0xc) = piVar18;
                piVar23 = (int *)piVar22[3];
              }
              if (piVar23 != (int *)0x0) {
                piVar23[4] = iVar5;
              }
              piVar33[3] = (int)piVar22;
              piVar22[4] = (int)piVar33;
              piVar22[3] = 0;
              piVar33 = piVar22;
            }
            piVar22[1] = 1;
          }
        } while ((piVar22 != piVar9) && (piVar22 = piVar18, piVar18 != (int *)0x0));
        piVar9 = local_3c;
        piVar22 = piVar33;
        if (local_3c == (int *)0x0) goto LAB_004b2530;
        do {
          piVar18 = (int *)local_3c[3];
          if ((((*(uint *)(*local_3c + 0x18) & 1) != 0) && (local_3c[1] != 0)) &&
             (piVar22 != local_3c)) {
            iVar5 = local_3c[4];
            if (piVar9 == local_3c) {
              piVar9 = piVar18;
            }
            piVar23 = piVar18;
            if (iVar5 != 0) {
              *(int **)(iVar5 + 0xc) = piVar18;
              piVar23 = (int *)local_3c[3];
            }
            if (piVar23 != (int *)0x0) {
              piVar23[4] = iVar5;
            }
            piVar22[3] = (int)local_3c;
            local_3c[4] = (int)piVar22;
            local_3c[3] = 0;
            piVar22 = local_3c;
          }
        } while ((piVar33 != local_3c) && (local_3c = piVar18, piVar18 != (int *)0x0));
        local_3c = piVar9;
        if (piVar22 != (int *)0x0) {
          piVar33 = piVar22;
          if (piVar9 != (int *)0x0) {
            do {
              piVar18 = (int *)piVar9[3];
              if ((((*(uint *)(*piVar9 + 0x10) & 4) != 0) && (piVar9[1] != 0)) &&
                 (piVar9 != piVar33)) {
                iVar5 = piVar9[4];
                if (piVar9 == local_3c) {
                  local_3c = piVar18;
                }
                piVar23 = piVar18;
                if (iVar5 != 0) {
                  *(int **)(iVar5 + 0xc) = piVar18;
                  piVar23 = (int *)piVar9[3];
                }
                if (piVar23 != (int *)0x0) {
                  piVar23[4] = iVar5;
                }
                piVar33[3] = (int)piVar9;
                piVar9[4] = (int)piVar33;
                piVar9[3] = 0;
                piVar33 = piVar9;
              }
            } while ((piVar9 != piVar22) && (piVar9 = piVar18, piVar18 != (int *)0x0));
            if (piVar33 == (int *)0x0) goto LAB_004b2520;
            piVar9 = local_3c;
            piVar22 = piVar33;
            if (local_3c == (int *)0x0) goto LAB_004b25b8;
            do {
              piVar18 = (int *)piVar9[3];
              if ((((*(uint *)(*piVar9 + 0x10) & 0x10) != 0) && (piVar9[1] != 0)) &&
                 (piVar22 != piVar9)) {
                iVar5 = piVar9[4];
                if (local_3c == piVar9) {
                  local_3c = piVar18;
                }
                piVar23 = piVar18;
                if (iVar5 != 0) {
                  *(int **)(iVar5 + 0xc) = piVar18;
                  piVar23 = (int *)piVar9[3];
                }
                if (piVar23 != (int *)0x0) {
                  piVar23[4] = iVar5;
                }
                piVar22[3] = (int)piVar9;
                piVar9[4] = (int)piVar22;
                piVar9[3] = 0;
                piVar22 = piVar9;
              }
            } while ((piVar9 != piVar33) && (piVar9 = piVar18, piVar18 != (int *)0x0));
            if (piVar22 == (int *)0x0) {
LAB_004b25d8:
              piVar33 = (int *)0x0;
              goto LAB_004b208c;
            }
            piVar9 = local_3c;
            piVar33 = piVar22;
            if (local_3c != (int *)0x0) {
              do {
                piVar18 = (int *)piVar9[3];
                if ((((*(uint *)(*piVar9 + 0xc) & 1) != 0) && (piVar9[1] != 0)) &&
                   (piVar9 != piVar33)) {
                  iVar5 = piVar9[4];
                  if (piVar9 == local_3c) {
                    local_3c = piVar18;
                  }
                  piVar23 = piVar18;
                  if (iVar5 != 0) {
                    *(int **)(iVar5 + 0xc) = piVar18;
                    piVar23 = (int *)piVar9[3];
                  }
                  if (piVar23 != (int *)0x0) {
                    piVar23[4] = iVar5;
                  }
                  piVar33[3] = (int)piVar9;
                  piVar9[4] = (int)piVar33;
                  piVar9[3] = 0;
                  piVar33 = piVar9;
                }
              } while ((piVar22 != piVar9) && (piVar9 = piVar18, piVar18 != (int *)0x0));
              if ((piVar33 == (int *)0x0) ||
                 (piVar9 = local_3c, piVar22 = piVar33, local_3c == (int *)0x0)) goto LAB_004b208c;
              do {
                piVar18 = (int *)piVar9[3];
                if ((((*(uint *)(*piVar9 + 0xc) & 0x100) != 0) && (piVar9[1] != 0)) &&
                   (piVar22 != piVar9)) {
                  iVar5 = piVar9[4];
                  if (piVar9 == local_3c) {
                    local_3c = piVar18;
                  }
                  piVar23 = piVar18;
                  if (iVar5 != 0) {
                    *(int **)(iVar5 + 0xc) = piVar18;
                    piVar23 = (int *)piVar9[3];
                  }
                  if (piVar23 != (int *)0x0) {
                    piVar23[4] = iVar5;
                  }
                  piVar22[3] = (int)piVar9;
                  piVar9[4] = (int)piVar22;
                  piVar9[3] = 0;
                  piVar22 = piVar9;
                }
              } while ((piVar33 != piVar9) && (piVar9 = piVar18, piVar18 != (int *)0x0));
              if (piVar22 == (int *)0x0) goto LAB_004b25d8;
              piVar9 = local_3c;
              piVar18 = piVar22;
              piVar33 = piVar22;
              if (local_3c != (int *)0x0) {
                do {
                  piVar33 = (int *)local_3c[3];
                  if ((((*(uint *)(*local_3c + 0xc) & 0x10) != 0) && (local_3c[1] != 0)) &&
                     (piVar18 != local_3c)) {
                    iVar5 = local_3c[4];
                    if (piVar9 == local_3c) {
                      piVar9 = piVar33;
                    }
                    piVar23 = piVar33;
                    if (iVar5 != 0) {
                      *(int **)(iVar5 + 0xc) = piVar33;
                      piVar23 = (int *)local_3c[3];
                    }
                    if (piVar23 != (int *)0x0) {
                      piVar23[4] = iVar5;
                    }
                    piVar18[3] = (int)local_3c;
                    local_3c[4] = (int)piVar18;
                    local_3c[3] = 0;
                    piVar18 = local_3c;
                  }
                } while ((piVar22 != local_3c) && (local_3c = piVar33, piVar33 != (int *)0x0));
                local_3c = piVar9;
                piVar33 = piVar18;
                if (piVar18 != (int *)0x0) {
                  do {
                    if (piVar9 == (int *)0x0) break;
                    piVar22 = (int *)piVar9[3];
                    if ((((*(uint *)(*piVar9 + 0x14) & 4) != 0) && (piVar9[1] != 0)) &&
                       (piVar33 != piVar9)) {
                      iVar5 = piVar9[4];
                      if (local_3c == piVar9) {
                        local_3c = piVar22;
                      }
                      piVar23 = piVar22;
                      if (iVar5 != 0) {
                        *(int **)(iVar5 + 0xc) = piVar22;
                        piVar23 = (int *)piVar9[3];
                      }
                      if (piVar23 != (int *)0x0) {
                        piVar23[4] = iVar5;
                      }
                      piVar33[3] = (int)piVar9;
                      piVar9[4] = (int)piVar33;
                      piVar9[3] = 0;
                      piVar33 = piVar9;
                    }
                    bVar1 = piVar18 != piVar9;
                    piVar9 = piVar22;
                  } while (bVar1);
                  goto LAB_004b208c;
                }
                goto LAB_004b2520;
              }
            }
          }
LAB_004b25d0:
          local_3c = (int *)0x0;
          goto LAB_004b208c;
        }
      }
    }
  }
LAB_004b2520:
  piVar33 = (int *)0x0;
LAB_004b208c:
  do {
    local_38 = piVar33;
    iVar5 = ssl_cipher_strength_sort(&local_3c,&local_38);
    if (iVar5 == 0) {
LAB_004b2408:
      CRYPTO_free(unaff_s4);
      piVar33 = (int *)0x0;
    }
    else {
      piVar33 = local_3c;
      piVar9 = local_38;
      if (local_3c == (int *)0x0) {
        piVar33 = (int *)0x0;
      }
      else {
        do {
          if (piVar9 == (int *)0x0) break;
          piVar22 = (int *)piVar9[4];
          if (piVar9[1] != 0) {
            if (piVar9 != piVar33) {
              iVar5 = piVar9[3];
              if (local_38 == piVar9) {
                local_38 = piVar22;
              }
              piVar18 = piVar22;
              if (iVar5 != 0) {
                *(int **)(iVar5 + 0x10) = piVar22;
                piVar18 = (int *)piVar9[4];
              }
              if (piVar18 != (int *)0x0) {
                piVar18[3] = iVar5;
              }
              piVar33[4] = (int)piVar9;
              piVar9[3] = (int)piVar33;
              piVar9[4] = 0;
              piVar33 = piVar9;
            }
            piVar9[1] = 0;
          }
          bVar1 = local_3c != piVar9;
          piVar9 = piVar22;
        } while (bVar1);
      }
      local_3c = piVar33;
      unaff_s1 = (int *)CRYPTO_malloc(((int)unaff_s1 + 0x4b) * 4,local_44 + 0x7db0,0x5d5);
      if (unaff_s1 == (int *)0x0) {
        CRYPTO_free(unaff_s4);
        uVar11 = 0x5d8;
LAB_004b2560:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xa6,0x41,"ssl_ciph.c",uVar11);
        piVar33 = (int *)0x0;
      }
      else {
        unaff_s0 = ~unaff_s0;
        piVar33 = unaff_s1;
        for (piVar9 = local_3c; piVar9 != (int *)0x0; piVar9 = (int *)piVar9[3]) {
          *piVar33 = *piVar9;
          piVar33 = piVar33 + 1;
        }
        puVar10 = cipher_aliases;
        do {
          while ((((*(uint *)(puVar10 + 0xc) == 0 || ((unaff_s8 & *(uint *)(puVar10 + 0xc)) != 0))
                  && (((*(uint *)(puVar10 + 0x10) == 0 ||
                       ((unaff_s0 & *(uint *)(puVar10 + 0x10)) != 0)) &&
                      ((*(uint *)(puVar10 + 0x14) == 0 ||
                       ((~local_58 & *(uint *)(puVar10 + 0x14)) != 0)))))) &&
                 ((*(uint *)(puVar10 + 0x18) == 0 || ((~local_4c & *(uint *)(puVar10 + 0x18)) != 0))
                 ))) {
            *piVar33 = (int)puVar10;
            puVar10 = puVar10 + 0x30;
            piVar33 = piVar33 + 1;
            if (puVar10 == lock_names) goto LAB_004b21fc;
          }
          puVar10 = puVar10 + 0x30;
        } while (puVar10 != lock_names);
LAB_004b21fc:
        puVar2 = PTR_strncmp_006a9970;
        *piVar33 = 0;
        iVar5 = (*(code *)puVar2)(local_54,"DEFAULT",7);
        if (iVar5 == 0) {
          iVar5 = ssl_cipher_process_rulestr
                            ("ALL:!EXPORT:!LOW:!aNULL:!eNULL:!SSLv2",&local_3c,&local_38,unaff_s1);
          if (local_54[7] == ':') {
            local_54 = local_54 + 8;
          }
          else {
            local_54 = local_54 + 7;
          }
          if (iVar5 == 0) {
            CRYPTO_free(unaff_s1);
            goto LAB_004b2408;
          }
        }
        if (*local_54 == '\0') {
          CRYPTO_free(unaff_s1);
        }
        else {
          unaff_s0 = ssl_cipher_process_rulestr(local_54,&local_3c,&local_38,unaff_s1);
          CRYPTO_free(unaff_s1);
          if (unaff_s0 == 0) goto LAB_004b2408;
        }
        unaff_s1 = (int *)(*(code *)PTR_sk_new_null_006a6fa4)();
        piVar33 = local_3c;
        if (unaff_s1 == (int *)0x0) goto LAB_004b2408;
        for (; piVar33 != (int *)0x0; piVar33 = (int *)piVar33[3]) {
          while (piVar33[1] == 0) {
            piVar33 = (int *)piVar33[3];
            if (piVar33 == (int *)0x0) goto LAB_004b2298;
          }
          (*(code *)PTR_sk_push_006a6fa8)(unaff_s1,*piVar33);
        }
LAB_004b2298:
        CRYPTO_free(unaff_s4);
        unaff_s0 = (*(code *)PTR_sk_dup_006a7f54)(unaff_s1);
        if (unaff_s0 == 0) {
          (*(code *)PTR_sk_free_006a6e80)(unaff_s1);
          piVar33 = (int *)0x0;
        }
        else {
          if (*param_2 != (int *)0x0) {
            (*(code *)PTR_sk_free_006a6e80)();
          }
          *param_2 = unaff_s1;
          if (*param_3 != 0) {
            (*(code *)PTR_sk_free_006a6e80)();
          }
          puVar3 = PTR_ssl_cipher_ptr_id_cmp_006a83c4;
          puVar2 = PTR_sk_set_cmp_func_006a8384;
          *param_3 = unaff_s0;
          (*(code *)puVar2)(unaff_s0,puVar3);
          (*(code *)PTR_sk_sort_006a83bc)(*param_3);
          piVar33 = unaff_s1;
        }
      }
    }
LAB_004b2324:
    if (local_2c == *(int **)puVar4) {
      return piVar33;
    }
    piVar33 = local_2c;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004b25b8:
    local_3c = (int *)0x0;
  } while( true );
}

