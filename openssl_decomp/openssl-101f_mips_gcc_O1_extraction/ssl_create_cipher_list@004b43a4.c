
/* WARNING: Type propagation algorithm not settling */

char ********
ssl_create_cipher_list(int param_1,char ********param_2,char ********param_3,char ********param_4)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char ********ptr;
  char *******pppppppcVar9;
  int **ptr_00;
  char ********ppppppppcVar10;
  undefined1 *puVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int **ppiVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  char ********ppppppppcVar23;
  uint uVar24;
  char ********ppppppppcVar25;
  char ********ppppppppcVar26;
  char ********ppppppppcVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  char ********ppppppppcVar34;
  char *pcVar35;
  uint uVar36;
  char *pcVar37;
  char *pcVar38;
  int iVar39;
  char *pcVar40;
  char *pcVar41;
  int iVar42;
  char *pcVar43;
  char ********local_58;
  char ********local_3c;
  char ********local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_3c = (char ********)0x0;
  local_38 = (char ********)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (((param_4 == (char ********)0x0) || (param_2 == (char ********)0x0)) ||
     (param_3 == (char ********)0x0)) {
    ppppppppcVar10 = (char ********)0x0;
  }
  else {
    local_34 = 0;
    local_30 = 0;
    iVar4 = (*(code *)PTR_EVP_PKEY_asn1_find_str_006a80bc)(&local_34,"gost94",0xffffffff);
    if (iVar4 != 0) {
      (*(code *)PTR_EVP_PKEY_asn1_get0_info_006a80c0)(&local_30,0,0,0,0,iVar4);
    }
    if (local_34 != 0) {
      (*(code *)PTR_ENGINE_finish_006a80c4)();
    }
    uVar5 = 0x28;
    local_34 = 0;
    if (local_30 == 0) {
      uVar5 = 0x128;
    }
    local_30 = 0;
    iVar4 = (*(code *)PTR_EVP_PKEY_asn1_find_str_006a80bc)(&local_34,"gost2001",0xffffffff);
    if (iVar4 != 0) {
      (*(code *)PTR_EVP_PKEY_asn1_get0_info_006a80c0)(&local_30,0,0,0,0,iVar4);
    }
    if (local_34 != 0) {
      (*(code *)PTR_ENGINE_finish_006a80c4)();
    }
    uVar24 = 4;
    uVar16 = 2;
    uVar30 = 4;
    uVar19 = 8;
    uVar32 = 0x10;
    if (ssl_cipher_methods._4_4_ != 0) {
      uVar16 = 0;
    }
    if (ssl_cipher_methods._8_4_ != 0) {
      uVar30 = 0;
    }
    uVar36 = 0x216;
    uVar31 = 8;
    if (ssl_cipher_methods._12_4_ != 0) {
      uVar31 = 0;
    }
    uVar13 = 0x10;
    if (ssl_cipher_methods._16_4_ != 0) {
      uVar13 = 0;
    }
    uVar6 = 0x80;
    uVar14 = 0x40;
    if (ssl_cipher_methods._28_4_ != 0) {
      uVar6 = 0;
    }
    if (ssl_cipher_methods._24_4_ != 0) {
      uVar14 = 0;
    }
    uVar7 = 0x1000;
    if (ssl_digest_methods._16_4_ != 0) {
      uVar32 = 0;
    }
    if (ssl_cipher_methods._48_4_ != 0) {
      uVar7 = 0;
    }
    uVar28 = 0x2000;
    if (ssl_cipher_methods._52_4_ != 0) {
      uVar28 = 0;
    }
    uVar15 = 0x100;
    if (ssl_cipher_methods._32_4_ != 0) {
      uVar15 = 0;
    }
    uVar21 = 2;
    uVar33 = 0x400;
    if (ssl_digest_methods._4_4_ != 0) {
      uVar21 = 0;
    }
    if (local_30 == 0) {
      uVar5 = uVar5 | 0x200;
    }
    uVar17 = 0x200;
    if (ssl_cipher_methods._36_4_ != 0) {
      uVar17 = 0;
    }
    if (ssl_cipher_methods._40_4_ != 0) {
      uVar33 = 0;
    }
    uVar22 = uVar5 & 0x300 ^ 0x300;
    uVar8 = 0x20;
    if (ssl_digest_methods._20_4_ != 0) {
      uVar8 = 0;
    }
    uVar29 = 0x800;
    if (ssl_cipher_methods._44_4_ != 0) {
      uVar29 = 0;
    }
    if (ssl_digest_methods._8_4_ != 0) {
      uVar24 = 0;
    }
    uVar29 = ssl_cipher_methods._0_4_ == 0 | uVar16 | uVar30 | uVar31 | uVar13 | uVar14 | uVar6 |
             uVar7 | uVar28 | uVar15 | uVar17 | uVar33 | uVar29;
    uVar16 = 0xffffffe9;
    if (uVar22 == 0) {
      uVar16 = 0xfffffde9;
    }
    if (uVar22 != 0) {
      uVar36 = 0x16;
    }
    if (ssl_digest_methods._12_4_ == 0) {
      uVar19 = 8;
    }
    else if (ssl_mac_pkey_id._12_4_ != 0) {
      uVar19 = 0;
    }
    uVar19 = uVar21 | ssl_digest_methods._0_4_ == 0 | uVar32 | uVar8 | uVar24 | uVar19;
    iVar4 = (**(code **)(param_1 + 0x54))();
    ppppppppcVar23 = (char ********)0x56a;
    ptr = (char ********)CRYPTO_malloc(iVar4 * 0x14,"ssl_ciph.c",0x56a);
    if (ptr == (char ********)0x0) {
      uVar12 = 0x56d;
LAB_004b51d4:
      param_3 = (char ********)&DAT_00000041;
      param_2 = (char ********)0xa6;
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xa6,0x41,"ssl_ciph.c",uVar12);
      ppppppppcVar10 = (char ********)0x0;
    }
    else {
      if (iVar4 < 1) {
LAB_004b50ac:
        if (local_3c != (char ********)0x0) goto LAB_004b47d0;
        if (local_38 != (char ********)0x0) {
          local_3c = (char ********)0x0;
          ppppppppcVar10 = local_38;
          goto LAB_004b4850;
        }
        goto LAB_004b516c;
      }
      iVar42 = 0;
      iVar20 = 0;
      do {
        pppppppcVar9 = (char *******)(**(code **)(param_1 + 0x58))(iVar42);
        iVar39 = iVar20;
        if ((((pppppppcVar9 != (char *******)0x0) && (*pppppppcVar9 != (char ******)0x0)) &&
            (((uVar36 & (uint)pppppppcVar9[3]) == 0 &&
             (((uVar5 & (uint)pppppppcVar9[4]) == 0 && ((uVar29 & (uint)pppppppcVar9[5]) == 0))))))
           && ((uVar19 & (uint)pppppppcVar9[6]) == 0)) {
          iVar39 = iVar20 + 1;
          ppppppppcVar10 = ptr + iVar20 * 5;
          *ppppppppcVar10 = pppppppcVar9;
          ppppppppcVar10[3] = (char *******)0x0;
          ppppppppcVar10[4] = (char *******)0x0;
          ppppppppcVar10[1] = (char *******)0x0;
        }
        iVar42 = iVar42 + 1;
        iVar20 = iVar39;
      } while (iVar4 != iVar42);
      if (iVar39 == 0) goto LAB_004b50ac;
      ptr[4] = (char *******)0x0;
      local_38 = ptr;
      if (iVar39 != 1) {
        ptr[3] = (char *******)(ptr + 5);
        if (iVar39 == 2) {
          iVar20 = 8;
          iVar42 = 0x20;
        }
        else {
          iVar20 = iVar39 * 4;
          iVar42 = iVar39 * 0x10;
          ppppppppcVar10 = ptr + 10;
          do {
            ppppppppcVar10[-2] = (char *******)ppppppppcVar10;
            ppppppppcVar26 = ppppppppcVar10 + 5;
            ppppppppcVar10[-1] = (char *******)(ppppppppcVar10 + -10);
            ppppppppcVar10 = ppppppppcVar26;
          } while (ptr + iVar39 * 5 != ppppppppcVar26);
        }
        local_38 = (char ********)((int)ptr + iVar20 + iVar42 + -0x14);
        local_38[4] = (char *******)((int)ptr + iVar20 + iVar42 + -0x28);
      }
      local_38[3] = (char *******)0x0;
      local_3c = ptr;
LAB_004b47d0:
      ppppppppcVar25 = local_38;
      ppppppppcVar10 = local_3c;
      ppppppppcVar26 = local_3c;
      if (local_3c == local_38) {
LAB_004b4850:
        local_38 = ppppppppcVar10;
        if (ppppppppcVar10 != local_3c) {
          pppppppcVar9 = *ppppppppcVar10;
          ppppppppcVar26 = local_3c;
          while( true ) {
            ppppppppcVar23 = (char ********)ppppppppcVar10[4];
            if ((((uint)pppppppcVar9[3] & 0x80) != 0) && (ppppppppcVar10[1] != (char *******)0x0)) {
              if (ppppppppcVar10 != ppppppppcVar26) {
                pppppppcVar9 = ppppppppcVar10[3];
                if (local_38 == ppppppppcVar10) {
                  local_38 = ppppppppcVar23;
                }
                ppppppppcVar25 = ppppppppcVar23;
                if (pppppppcVar9 != (char *******)0x0) {
                  pppppppcVar9[4] = (char ******)ppppppppcVar23;
                  ppppppppcVar25 = (char ********)ppppppppcVar10[4];
                }
                if (ppppppppcVar25 != (char ********)0x0) {
                  ppppppppcVar25[3] = pppppppcVar9;
                }
                ppppppppcVar26[4] = (char *******)ppppppppcVar10;
                ppppppppcVar10[3] = (char *******)ppppppppcVar26;
                ppppppppcVar10[4] = (char *******)0x0;
                ppppppppcVar26 = ppppppppcVar10;
              }
              ppppppppcVar10[1] = (char *******)0x0;
            }
            if (ppppppppcVar10 == local_3c) break;
            pppppppcVar9 = *ppppppppcVar23;
            ppppppppcVar10 = ppppppppcVar23;
          }
          goto LAB_004b48d4;
        }
      }
      else {
        do {
          ppppppppcVar23 = (char ********)local_3c[3];
          if ((((uint)(*local_3c)[3] & 0x80) != 0) && (local_3c[1] == (char *******)0x0)) {
            if (local_3c != ppppppppcVar25) {
              pppppppcVar9 = local_3c[4];
              if (local_3c == ppppppppcVar26) {
                ppppppppcVar26 = ppppppppcVar23;
              }
              ppppppppcVar10 = ppppppppcVar23;
              if (pppppppcVar9 != (char *******)0x0) {
                pppppppcVar9[3] = (char ******)ppppppppcVar23;
                ppppppppcVar10 = (char ********)local_3c[3];
              }
              if (ppppppppcVar10 != (char ********)0x0) {
                ppppppppcVar10[4] = pppppppcVar9;
              }
              ppppppppcVar25[3] = (char *******)local_3c;
              local_3c[4] = (char *******)ppppppppcVar25;
              local_3c[3] = (char *******)0x0;
              ppppppppcVar25 = local_3c;
            }
            local_3c[1] = (char *******)0x1;
          }
          bVar1 = local_3c != local_38;
          local_3c = ppppppppcVar23;
        } while (bVar1);
        ppppppppcVar10 = ppppppppcVar25;
        local_3c = ppppppppcVar26;
        if (ppppppppcVar25 != (char ********)0x0) goto LAB_004b4850;
        local_38 = (char ********)0x0;
LAB_004b48d4:
        ppppppppcVar10 = ppppppppcVar26;
        if (ppppppppcVar26 == (char ********)0x0) goto LAB_004b516c;
      }
      ppppppppcVar26 = ppppppppcVar10;
      ppppppppcVar25 = local_38;
      ppppppppcVar27 = ppppppppcVar10;
      if (ppppppppcVar10 == local_38) goto LAB_004b4a48;
      do {
        ppppppppcVar23 = ppppppppcVar25;
        ppppppppcVar25 = (char ********)ppppppppcVar10[3];
        if ((((uint)(*ppppppppcVar10)[5] & 0x30c0) != 0) && (ppppppppcVar10[1] == (char *******)0x0)
           ) {
          if (ppppppppcVar10 != ppppppppcVar23) {
            pppppppcVar9 = ppppppppcVar10[4];
            if (ppppppppcVar10 == ppppppppcVar26) {
              ppppppppcVar26 = ppppppppcVar25;
            }
            ppppppppcVar27 = ppppppppcVar25;
            if (pppppppcVar9 != (char *******)0x0) {
              pppppppcVar9[3] = (char ******)ppppppppcVar25;
              ppppppppcVar27 = (char ********)ppppppppcVar10[3];
            }
            if (ppppppppcVar27 != (char ********)0x0) {
              ppppppppcVar27[4] = pppppppcVar9;
            }
            ppppppppcVar23[3] = (char *******)ppppppppcVar10;
            ppppppppcVar10[4] = (char *******)ppppppppcVar23;
            ppppppppcVar10[3] = (char *******)0x0;
            ppppppppcVar23 = ppppppppcVar10;
          }
          ppppppppcVar10[1] = (char *******)0x1;
        }
        bVar1 = ppppppppcVar10 != local_38;
        ppppppppcVar10 = ppppppppcVar25;
        ppppppppcVar25 = ppppppppcVar23;
      } while (bVar1);
      if (ppppppppcVar26 == (char ********)0x0) {
LAB_004b525c:
        local_3c = (char ********)0x0;
        local_38 = ppppppppcVar23;
      }
      else {
        ppppppppcVar10 = ppppppppcVar26;
        local_38 = ppppppppcVar23;
        if (ppppppppcVar26 != ppppppppcVar23) {
          do {
            ppppppppcVar25 = (char ********)ppppppppcVar10[3];
            if (ppppppppcVar10[1] == (char *******)0x0) {
              if (ppppppppcVar10 != local_38) {
                pppppppcVar9 = ppppppppcVar10[4];
                if (ppppppppcVar10 == ppppppppcVar26) {
                  ppppppppcVar26 = ppppppppcVar25;
                }
                ppppppppcVar27 = ppppppppcVar25;
                if (pppppppcVar9 != (char *******)0x0) {
                  pppppppcVar9[3] = (char ******)ppppppppcVar25;
                  ppppppppcVar27 = (char ********)ppppppppcVar10[3];
                }
                if (ppppppppcVar27 != (char ********)0x0) {
                  ppppppppcVar27[4] = pppppppcVar9;
                }
                local_38[3] = (char *******)ppppppppcVar10;
                ppppppppcVar10[4] = (char *******)local_38;
                ppppppppcVar10[3] = (char *******)0x0;
                local_38 = ppppppppcVar10;
              }
              ppppppppcVar10[1] = (char *******)0x1;
            }
            bVar1 = ppppppppcVar23 != ppppppppcVar10;
            ppppppppcVar10 = ppppppppcVar25;
          } while (bVar1);
          ppppppppcVar10 = local_38;
          if (ppppppppcVar26 == (char ********)0x0) goto LAB_004b516c;
        }
        ppppppppcVar25 = ppppppppcVar26;
        ppppppppcVar27 = ppppppppcVar10;
        if (ppppppppcVar10 == ppppppppcVar26) {
LAB_004b4a48:
          local_3c = ppppppppcVar10;
          local_38 = ppppppppcVar27;
          ppppppppcVar26 = ppppppppcVar10;
          if (ppppppppcVar27 != ppppppppcVar10) {
            do {
              ppppppppcVar23 = (char ********)ppppppppcVar26[3];
              if (((((uint)(*ppppppppcVar26)[4] & 4) != 0) &&
                  (ppppppppcVar26[1] != (char *******)0x0)) && (ppppppppcVar26 != local_38)) {
                pppppppcVar9 = ppppppppcVar26[4];
                if (ppppppppcVar26 == ppppppppcVar10) {
                  ppppppppcVar10 = ppppppppcVar23;
                }
                ppppppppcVar25 = ppppppppcVar23;
                if (pppppppcVar9 != (char *******)0x0) {
                  pppppppcVar9[3] = (char ******)ppppppppcVar23;
                  ppppppppcVar25 = (char ********)ppppppppcVar26[3];
                }
                if (ppppppppcVar25 != (char ********)0x0) {
                  ppppppppcVar25[4] = pppppppcVar9;
                }
                local_38[3] = (char *******)ppppppppcVar26;
                ppppppppcVar26[4] = (char *******)local_38;
                ppppppppcVar26[3] = (char *******)0x0;
                local_38 = ppppppppcVar26;
              }
              bVar1 = ppppppppcVar26 != ppppppppcVar27;
              ppppppppcVar26 = ppppppppcVar23;
            } while (bVar1);
            if (ppppppppcVar10 == (char ********)0x0) {
LAB_004b516c:
              local_3c = (char ********)0x0;
              goto LAB_004b4cac;
            }
            local_3c = ppppppppcVar10;
            ppppppppcVar23 = local_38;
            if (ppppppppcVar10 != local_38) {
              do {
                ppppppppcVar26 = (char ********)ppppppppcVar10[3];
                if (((((uint)(*ppppppppcVar10)[4] & 0x10) != 0) &&
                    (ppppppppcVar10[1] != (char *******)0x0)) && (ppppppppcVar23 != ppppppppcVar10))
                {
                  pppppppcVar9 = ppppppppcVar10[4];
                  if (ppppppppcVar10 == local_3c) {
                    local_3c = ppppppppcVar26;
                  }
                  ppppppppcVar25 = ppppppppcVar26;
                  if (pppppppcVar9 != (char *******)0x0) {
                    pppppppcVar9[3] = (char ******)ppppppppcVar26;
                    ppppppppcVar25 = (char ********)ppppppppcVar10[3];
                  }
                  if (ppppppppcVar25 != (char ********)0x0) {
                    ppppppppcVar25[4] = pppppppcVar9;
                  }
                  ppppppppcVar23[3] = (char *******)ppppppppcVar10;
                  ppppppppcVar10[4] = (char *******)ppppppppcVar23;
                  ppppppppcVar10[3] = (char *******)0x0;
                  ppppppppcVar23 = ppppppppcVar10;
                }
                bVar1 = ppppppppcVar10 != local_38;
                ppppppppcVar10 = ppppppppcVar26;
              } while (bVar1);
              if (local_3c == (char ********)0x0) goto LAB_004b525c;
              local_38 = local_3c;
              ppppppppcVar26 = local_3c;
              ppppppppcVar10 = ppppppppcVar23;
              if (local_3c == ppppppppcVar23) goto LAB_004b4cac;
              do {
                ppppppppcVar25 = (char ********)local_3c[3];
                if (((((uint)(*local_3c)[3] & 1) != 0) && (local_3c[1] != (char *******)0x0)) &&
                   (local_3c != ppppppppcVar10)) {
                  pppppppcVar9 = local_3c[4];
                  if (local_3c == ppppppppcVar26) {
                    ppppppppcVar26 = ppppppppcVar25;
                  }
                  ppppppppcVar27 = ppppppppcVar25;
                  if (pppppppcVar9 != (char *******)0x0) {
                    pppppppcVar9[3] = (char ******)ppppppppcVar25;
                    ppppppppcVar27 = (char ********)local_3c[3];
                  }
                  if (ppppppppcVar27 != (char ********)0x0) {
                    ppppppppcVar27[4] = pppppppcVar9;
                  }
                  ppppppppcVar10[3] = (char *******)local_3c;
                  local_3c[4] = (char *******)ppppppppcVar10;
                  local_3c[3] = (char *******)0x0;
                  ppppppppcVar10 = local_3c;
                }
                bVar1 = ppppppppcVar23 != local_3c;
                local_3c = ppppppppcVar25;
              } while (bVar1);
              local_38 = ppppppppcVar10;
              if (ppppppppcVar26 == (char ********)0x0) goto LAB_004b516c;
              local_3c = ppppppppcVar10;
              ppppppppcVar25 = ppppppppcVar26;
              if (ppppppppcVar10 != ppppppppcVar26) {
                do {
                  ppppppppcVar23 = (char ********)((uint)(*ppppppppcVar25)[3] & 0x100);
                  ppppppppcVar27 = (char ********)ppppppppcVar25[3];
                  if (((ppppppppcVar23 != (char ********)0x0) &&
                      (ppppppppcVar23 = (char ********)ppppppppcVar25[1],
                      ppppppppcVar23 != (char ********)0x0)) && (local_38 != ppppppppcVar25)) {
                    ppppppppcVar23 = (char ********)ppppppppcVar25[4];
                    if (ppppppppcVar26 == ppppppppcVar25) {
                      ppppppppcVar26 = ppppppppcVar27;
                    }
                    ppppppppcVar34 = ppppppppcVar27;
                    if (ppppppppcVar23 != (char ********)0x0) {
                      ppppppppcVar23[3] = (char *******)ppppppppcVar27;
                      ppppppppcVar34 = (char ********)ppppppppcVar25[3];
                    }
                    if (ppppppppcVar34 != (char ********)0x0) {
                      ppppppppcVar34[4] = (char *******)ppppppppcVar23;
                    }
                    local_38[3] = (char *******)ppppppppcVar25;
                    ppppppppcVar25[4] = (char *******)local_38;
                    ppppppppcVar25[3] = (char *******)0x0;
                    local_38 = ppppppppcVar25;
                  }
                  bVar1 = ppppppppcVar10 != ppppppppcVar25;
                  ppppppppcVar25 = ppppppppcVar27;
                } while (bVar1);
                ppppppppcVar10 = local_38;
                local_3c = ppppppppcVar26;
                if (ppppppppcVar26 == (char ********)0x0) {
                  local_3c = (char ********)0x0;
                  goto LAB_004b4cac;
                }
              }
            }
          }
          local_38 = local_3c;
          if (ppppppppcVar10 != local_3c) {
            pppppppcVar9 = *local_3c;
            ppppppppcVar26 = local_3c;
            ppppppppcVar25 = ppppppppcVar10;
            while( true ) {
              ppppppppcVar23 = (char ********)ppppppppcVar26[3];
              if (((((uint)pppppppcVar9[3] & 0x10) != 0) && (ppppppppcVar26[1] != (char *******)0x0)
                  ) && (ppppppppcVar26 != ppppppppcVar25)) {
                pppppppcVar9 = ppppppppcVar26[4];
                if (ppppppppcVar26 == local_3c) {
                  local_3c = ppppppppcVar23;
                }
                ppppppppcVar27 = ppppppppcVar23;
                if (pppppppcVar9 != (char *******)0x0) {
                  pppppppcVar9[3] = (char ******)ppppppppcVar23;
                  ppppppppcVar27 = (char ********)ppppppppcVar26[3];
                }
                if (ppppppppcVar27 != (char ********)0x0) {
                  ppppppppcVar27[4] = pppppppcVar9;
                }
                ppppppppcVar25[3] = (char *******)ppppppppcVar26;
                ppppppppcVar26[4] = (char *******)ppppppppcVar25;
                ppppppppcVar26[3] = (char *******)0x0;
                ppppppppcVar25 = ppppppppcVar26;
              }
              if (ppppppppcVar10 == ppppppppcVar26) break;
              pppppppcVar9 = *ppppppppcVar23;
              ppppppppcVar26 = ppppppppcVar23;
            }
            local_38 = ppppppppcVar25;
            if ((local_3c != (char ********)0x0) &&
               (local_38 = local_3c, local_3c != ppppppppcVar25)) {
              pppppppcVar9 = *local_3c;
              ppppppppcVar10 = local_3c;
              local_38 = ppppppppcVar25;
              while( true ) {
                ppppppppcVar23 = (char ********)ppppppppcVar10[3];
                if (((((uint)pppppppcVar9[5] & 4) != 0) && (ppppppppcVar10[1] != (char *******)0x0))
                   && (local_38 != ppppppppcVar10)) {
                  pppppppcVar9 = ppppppppcVar10[4];
                  if (local_3c == ppppppppcVar10) {
                    local_3c = ppppppppcVar23;
                  }
                  ppppppppcVar26 = ppppppppcVar23;
                  if (pppppppcVar9 != (char *******)0x0) {
                    pppppppcVar9[3] = (char ******)ppppppppcVar23;
                    ppppppppcVar26 = (char ********)ppppppppcVar10[3];
                  }
                  if (ppppppppcVar26 != (char ********)0x0) {
                    ppppppppcVar26[4] = pppppppcVar9;
                  }
                  local_38[3] = (char *******)ppppppppcVar10;
                  ppppppppcVar10[4] = (char *******)local_38;
                  ppppppppcVar10[3] = (char *******)0x0;
                  local_38 = ppppppppcVar10;
                }
                if (ppppppppcVar25 == ppppppppcVar10) break;
                pppppppcVar9 = *ppppppppcVar23;
                ppppppppcVar10 = ppppppppcVar23;
              }
            }
          }
        }
        else {
          do {
            ppppppppcVar23 = (char ********)ppppppppcVar25[3];
            if (((((uint)(*ppppppppcVar25)[6] & 1) != 0) && (ppppppppcVar25[1] != (char *******)0x0)
                ) && (ppppppppcVar25 != ppppppppcVar27)) {
              pppppppcVar9 = ppppppppcVar25[4];
              if (ppppppppcVar25 == ppppppppcVar26) {
                ppppppppcVar26 = ppppppppcVar23;
              }
              ppppppppcVar34 = ppppppppcVar23;
              if (pppppppcVar9 != (char *******)0x0) {
                pppppppcVar9[3] = (char ******)ppppppppcVar23;
                ppppppppcVar34 = (char ********)ppppppppcVar25[3];
              }
              if (ppppppppcVar34 != (char ********)0x0) {
                ppppppppcVar34[4] = pppppppcVar9;
              }
              ppppppppcVar27[3] = (char *******)ppppppppcVar25;
              ppppppppcVar25[4] = (char *******)ppppppppcVar27;
              ppppppppcVar25[3] = (char *******)0x0;
              ppppppppcVar27 = ppppppppcVar25;
            }
            bVar1 = ppppppppcVar25 != ppppppppcVar10;
            ppppppppcVar25 = ppppppppcVar23;
          } while (bVar1);
          ppppppppcVar10 = ppppppppcVar26;
          if (ppppppppcVar26 != (char ********)0x0) goto LAB_004b4a48;
          local_3c = (char ********)0x0;
          local_38 = ppppppppcVar27;
        }
      }
LAB_004b4cac:
      ppppppppcVar25 = (char ********)&local_38;
      ppppppppcVar26 = (char ********)&local_3c;
      ppppppppcVar27 = ppppppppcVar25;
      iVar20 = ssl_cipher_strength_sort(ppppppppcVar26);
      if (iVar20 != 0) {
        ppppppppcVar10 = local_3c;
        if ((local_38 != (char ********)0x0) && (ppppppppcVar10 = local_38, local_3c != local_38)) {
          pppppppcVar9 = local_38[1];
          ppppppppcVar23 = local_38;
          ppppppppcVar10 = local_3c;
          while( true ) {
            ppppppppcVar27 = (char ********)ppppppppcVar23[4];
            if (pppppppcVar9 != (char *******)0x0) {
              if (ppppppppcVar23 != ppppppppcVar10) {
                pppppppcVar9 = ppppppppcVar23[3];
                if (ppppppppcVar23 == local_38) {
                  local_38 = ppppppppcVar27;
                }
                ppppppppcVar34 = ppppppppcVar27;
                if (pppppppcVar9 != (char *******)0x0) {
                  pppppppcVar9[4] = (char ******)ppppppppcVar27;
                  ppppppppcVar34 = (char ********)ppppppppcVar23[4];
                }
                if (ppppppppcVar34 != (char ********)0x0) {
                  ppppppppcVar34[3] = pppppppcVar9;
                }
                ppppppppcVar10[4] = (char *******)ppppppppcVar23;
                ppppppppcVar23[3] = (char *******)ppppppppcVar10;
                ppppppppcVar23[4] = (char *******)0x0;
                ppppppppcVar10 = ppppppppcVar23;
              }
              ppppppppcVar23[1] = (char *******)0x0;
            }
            if (local_3c == ppppppppcVar23) break;
            pppppppcVar9 = ppppppppcVar27[1];
            ppppppppcVar23 = ppppppppcVar27;
          }
        }
        local_3c = ppppppppcVar10;
        ptr_00 = (int **)CRYPTO_malloc((iVar4 + 0x4a) * 4,"ssl_ciph.c",0x5aa);
        if (ptr_00 == (int **)0x0) {
          CRYPTO_free(ptr);
          uVar12 = 0x5ae;
          goto LAB_004b51d4;
        }
        ppiVar18 = ptr_00;
        for (ppppppppcVar10 = local_3c; ppppppppcVar10 != (char ********)0x0;
            ppppppppcVar10 = (char ********)ppppppppcVar10[3]) {
          *ppiVar18 = (int *)*ppppppppcVar10;
          ppiVar18 = ppiVar18 + 1;
        }
        puVar11 = cipher_aliases;
        do {
          while (((((*(uint *)((int)puVar11 + 0xc) == 0 ||
                    ((uVar16 & *(uint *)((int)puVar11 + 0xc)) != 0)) &&
                   ((*(uint *)((int)puVar11 + 0x10) == 0 ||
                    ((~uVar5 & *(uint *)((int)puVar11 + 0x10)) != 0)))) &&
                  ((*(uint *)((int)puVar11 + 0x14) == 0 ||
                   ((~uVar29 & *(uint *)((int)puVar11 + 0x14)) != 0)))) &&
                 ((*(uint *)((int)puVar11 + 0x18) == 0 ||
                  ((~uVar19 & *(uint *)((int)puVar11 + 0x18)) != 0))))) {
            *ppiVar18 = (int *)puVar11;
            puVar11 = (undefined1 *)((int)puVar11 + 0x30);
            ppiVar18 = ppiVar18 + 1;
            if (puVar11 == lock_names) goto LAB_004b4e9c;
          }
          puVar11 = (undefined1 *)((int)puVar11 + 0x30);
        } while (puVar11 != lock_names);
LAB_004b4e9c:
        puVar2 = PTR_strncmp_006aaa7c;
        *ppiVar18 = (int *)0x0;
        ppppppppcVar23 = (char ********)&DAT_00000007;
        ppppppppcVar10 = (char ********)0x6486f4;
        iVar4 = (*(code *)puVar2)(param_4);
        local_58 = param_4;
        if (iVar4 == 0) {
          ppppppppcVar23 = ppppppppcVar25;
          iVar4 = ssl_cipher_process_rulestr
                            ("ALL:!aNULL:!eNULL:!SSLv2",ppppppppcVar26,ppppppppcVar25,ptr_00);
          if (*(char *)((int)param_4 + 7) == ':') {
            local_58 = param_4 + 2;
          }
          else {
            local_58 = (char ********)((int)param_4 + 7);
          }
          ppppppppcVar10 = param_4;
          if (iVar4 == 0) {
            CRYPTO_free(ptr_00);
            ppppppppcVar27 = param_4;
            goto LAB_004b5078;
          }
        }
        if (*(char *)local_58 == '\0') {
          CRYPTO_free(ptr_00);
          ppppppppcVar26 = ppppppppcVar10;
          ppppppppcVar25 = ppppppppcVar23;
        }
        else {
          iVar4 = ssl_cipher_process_rulestr(local_58,ppppppppcVar26,ppppppppcVar25,ptr_00);
          CRYPTO_free(ptr_00);
          ppppppppcVar27 = ppppppppcVar26;
          ppppppppcVar23 = ppppppppcVar25;
          if (iVar4 == 0) goto LAB_004b5078;
        }
        ppppppppcVar10 = (char ********)(*(code *)PTR_sk_new_null_006a80a4)();
        ppppppppcVar27 = ppppppppcVar26;
        ppppppppcVar23 = ppppppppcVar25;
        ppppppppcVar34 = local_3c;
        if (ppppppppcVar10 != (char ********)0x0) {
          for (; ppppppppcVar34 != (char ********)0x0;
              ppppppppcVar34 = (char ********)ppppppppcVar34[3]) {
            while (ppppppppcVar34[1] != (char *******)0x0) {
              ppppppppcVar26 = (char ********)*ppppppppcVar34;
              (*(code *)PTR_sk_push_006a80a8)(ppppppppcVar10);
              ppppppppcVar34 = (char ********)ppppppppcVar34[3];
              if (ppppppppcVar34 == (char ********)0x0) goto LAB_004b4f38;
            }
          }
LAB_004b4f38:
          CRYPTO_free(ptr);
          pppppppcVar9 = (char *******)(*(code *)PTR_sk_dup_006a9074)(ppppppppcVar10);
          if (pppppppcVar9 == (char *******)0x0) {
            (*(code *)PTR_sk_free_006a7f80)(ppppppppcVar10);
            ppppppppcVar10 = (char ********)0x0;
            param_2 = ppppppppcVar26;
            param_3 = ppppppppcVar25;
          }
          else {
            if (*param_2 != (char *******)0x0) {
              (*(code *)PTR_sk_free_006a7f80)();
            }
            *param_2 = (char *******)ppppppppcVar10;
            if (*param_3 != (char *******)0x0) {
              (*(code *)PTR_sk_free_006a7f80)();
            }
            puVar2 = PTR_sk_set_cmp_func_006a9090;
            param_2 = (char ********)PTR_ssl_cipher_ptr_id_cmp_006a908c;
            *param_3 = pppppppcVar9;
            (*(code *)puVar2)(pppppppcVar9);
            (*(code *)PTR_sk_sort_006a94d8)(*param_3);
            param_3 = ppppppppcVar25;
          }
          goto LAB_004b4fc4;
        }
      }
LAB_004b5078:
      param_3 = ppppppppcVar23;
      param_2 = ppppppppcVar27;
      CRYPTO_free(ptr);
      ppppppppcVar10 = (char ********)0x0;
    }
  }
LAB_004b4fc4:
  if (local_2c == *(int *)puVar3) {
    return ppppppppcVar10;
  }
  iVar4 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  uVar5 = *(uint *)(iVar4 + 0xc);
  uVar30 = *(uint *)(iVar4 + 0x20) & 2;
  uVar16 = *(uint *)(iVar4 + 0x10);
  uVar19 = *(uint *)(iVar4 + 0x14);
  uVar32 = *(uint *)(iVar4 + 0x18);
  uVar24 = *(uint *)(iVar4 + 0x1c);
  if ((*(uint *)(iVar4 + 0x20) & 8) == 0) {
    iVar20 = 7;
    iVar42 = 0x400;
    if (uVar19 == 1) {
      iVar20 = 8;
    }
    if (uVar30 != 0) goto LAB_004b52f8;
LAB_004b5338:
    pcVar38 = "";
    if ((uVar24 & 1) == 0) goto LAB_004b5308;
LAB_004b5348:
    pcVar37 = "SSLv2";
  }
  else {
    iVar42 = 0x200;
    iVar20 = 5;
    if (uVar30 == 0) goto LAB_004b5338;
LAB_004b52f8:
    pcVar38 = " export";
    if ((uVar24 & 1) != 0) goto LAB_004b5348;
LAB_004b5308:
    if ((uVar24 & 2) == 0) {
      if ((uVar24 & 4) == 0) {
        pcVar37 = "unknown";
      }
      else {
        pcVar37 = "TLSv1.2";
      }
    }
    else {
      pcVar37 = "SSLv3";
    }
  }
  if (uVar5 == 0x10) {
    pcVar43 = "KRB5";
  }
  else if (uVar5 < 0x11) {
    if (uVar5 == 2) {
      pcVar43 = "DH/RSA";
    }
    else if (uVar5 < 3) {
      if (uVar5 == 1) {
        if (uVar30 == 0) {
          pcVar43 = "RSA";
        }
        else if (iVar42 == 0x200) {
          pcVar43 = "RSA(512)";
        }
        else {
          pcVar43 = "RSA(1024)";
        }
      }
      else {
LAB_004b573c:
        pcVar43 = "unknown";
      }
    }
    else if (uVar5 == 4) {
      pcVar43 = "DH/DSS";
    }
    else {
      if (uVar5 != 8) goto LAB_004b573c;
      if (uVar30 == 0) {
        pcVar43 = "DH";
      }
      else if (iVar42 == 0x200) {
        pcVar43 = "DH(512)";
      }
      else {
        pcVar43 = "DH(1024)";
      }
    }
  }
  else if (uVar5 == 0x80) {
    pcVar43 = "ECDH";
  }
  else if (uVar5 < 0x81) {
    if (uVar5 == 0x20) {
      pcVar43 = "ECDH/RSA";
    }
    else {
      if (uVar5 != 0x40) goto LAB_004b573c;
      pcVar43 = "ECDH/ECDSA";
    }
  }
  else if (uVar5 == 0x100) {
    pcVar43 = "PSK";
  }
  else {
    if (uVar5 != 0x400) goto LAB_004b573c;
    pcVar43 = "SRP";
  }
  if (uVar16 == 8) {
    pcVar40 = "DH";
  }
  else if (uVar16 < 9) {
    if (uVar16 == 2) {
      pcVar40 = "DSS";
    }
    else if (uVar16 == 4) {
      pcVar40 = "None";
    }
    else {
      if (uVar16 != 1) goto LAB_004b55e4;
      pcVar40 = "RSA";
    }
  }
  else if (uVar16 == 0x20) {
    pcVar40 = "KRB5";
  }
  else if (uVar16 < 0x21) {
    if (uVar16 == 0x10) {
      pcVar40 = "ECDH";
    }
    else {
LAB_004b55e4:
      pcVar40 = "unknown";
    }
  }
  else if (uVar16 == 0x40) {
    pcVar40 = "ECDSA";
  }
  else {
    if (uVar16 != 0x80) goto LAB_004b55e4;
    pcVar40 = "PSK";
  }
  if (uVar19 == 0x40) {
    pcVar41 = "AES(128)";
  }
  else if (uVar19 < 0x41) {
    if (uVar19 == 4) {
      if (uVar30 == 0) {
        if ((*(uint *)(iVar4 + 0x24) & 2) == 0) {
          pcVar41 = "RC4(128)";
        }
        else {
          pcVar41 = "RC4(64)";
        }
      }
      else if (iVar20 == 5) {
        pcVar41 = "RC4(40)";
      }
      else {
        pcVar41 = "RC4(56)";
      }
    }
    else if (uVar19 < 5) {
      if (uVar19 == 1) {
        if ((uVar30 == 0) || (iVar20 != 5)) {
          pcVar41 = "DES(56)";
        }
        else {
          pcVar41 = "DES(40)";
        }
      }
      else if (uVar19 == 2) {
        pcVar41 = "3DES(168)";
      }
      else {
LAB_004b540c:
        pcVar41 = "unknown";
      }
    }
    else if (uVar19 == 0x10) {
      pcVar41 = "IDEA(128)";
    }
    else if (uVar19 == 0x20) {
      pcVar41 = "None";
    }
    else {
      if (uVar19 != 8) goto LAB_004b540c;
      if (uVar30 == 0) {
        pcVar41 = "RC2(128)";
      }
      else if (iVar20 == 5) {
        pcVar41 = "RC2(40)";
      }
      else {
        pcVar41 = "RC2(56)";
      }
    }
  }
  else if (uVar19 == 0x200) {
    pcVar41 = "Camellia(256)";
  }
  else if (uVar19 < 0x201) {
    if (uVar19 == 0x80) {
      pcVar41 = "AES(256)";
    }
    else {
      if (uVar19 != 0x100) goto LAB_004b540c;
      pcVar41 = "Camellia(128)";
    }
  }
  else if (uVar19 == 0x1000) {
    pcVar41 = "AESGCM(128)";
  }
  else if (uVar19 == 0x2000) {
    pcVar41 = "AESGCM(256)";
  }
  else {
    if (uVar19 != 0x800) goto LAB_004b540c;
    pcVar41 = "SEED(128)";
  }
  if (uVar32 == 0x10) {
    pcVar35 = "SHA256";
    goto LAB_004b5440;
  }
  if (uVar32 < 0x11) {
    if (uVar32 == 1) {
      pcVar35 = "MD5";
      goto LAB_004b5440;
    }
    if (uVar32 == 2) {
      pcVar35 = "SHA1";
      goto LAB_004b5440;
    }
  }
  else {
    if (uVar32 == 0x20) {
      pcVar35 = "SHA384";
      goto LAB_004b5440;
    }
    if (uVar32 == 0x40) {
      pcVar35 = "AEAD";
      goto LAB_004b5440;
    }
  }
  pcVar35 = "unknown";
LAB_004b5440:
  if (param_2 == (char ********)0x0) {
    param_2 = (char ********)CRYPTO_malloc(0x80,"ssl_ciph.c",0x6ac);
    if (param_2 == (char ********)0x0) {
      return (char ********)"OPENSSL_malloc Error";
    }
    param_3 = (char ********)&DAT_00000080;
  }
  else if ((int)param_3 < 0x80) {
    return (char ********)"Buffer too small";
  }
  (*(code *)PTR_BIO_snprintf_006a8060)
            (param_2,param_3,"%-23s %s Kx=%-8s Au=%-4s Enc=%-9s Mac=%-4s%s\n",
             *(undefined4 *)(iVar4 + 4),pcVar37,pcVar43,pcVar40,pcVar41,pcVar35,pcVar38);
  return param_2;
}

