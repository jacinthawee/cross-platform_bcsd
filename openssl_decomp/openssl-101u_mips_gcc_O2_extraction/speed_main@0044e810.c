
/* WARNING: Removing unreachable block (ram,0x00456a44) */
/* WARNING: Removing unreachable block (ram,0x00456a68) */
/* WARNING: Removing unreachable block (ram,0x00456c7c) */
/* WARNING: Removing unreachable block (ram,0x00456a94) */
/* WARNING: Removing unreachable block (ram,0x00456aac) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x006aa8a0 : 0x00450550 */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int speed_main(int param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  int **ppiVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  undefined4 *puVar13;
  char *pcVar14;
  undefined *puVar15;
  char cVar16;
  int iVar17;
  undefined4 uVar18;
  undefined2 *puVar19;
  char *pcVar20;
  char *pcVar21;
  int **ppiVar22;
  double *pdVar23;
  undefined4 *puVar24;
  int **ppiVar25;
  uint uVar26;
  int **ppiVar27;
  undefined1 *puVar28;
  undefined4 uVar29;
  undefined1 *puVar30;
  undefined4 *puVar31;
  code *pcVar32;
  double *pdVar33;
  int **unaff_s6;
  char *unaff_s7;
  int iVar34;
  int **unaff_s8;
  undefined1 *puVar35;
  double dVar36;
  double dVar37;
  double dVar38;
  char *local_2990;
  char *local_298c;
  longlong local_2988;
  ulonglong local_2980;
  int **local_2974;
  longlong local_2960;
  longlong local_2958;
  int local_2950;
  undefined1 *local_294c;
  ulonglong local_2948;
  double local_2938;
  double local_2930;
  double local_2928;
  int *local_291c;
  int *local_2918;
  int local_2914;
  int *local_28f8;
  int *local_28f4;
  double *local_28e4;
  int local_28e0;
  undefined4 local_28bc;
  int *local_28b8;
  int local_28b4 [6];
  int *local_289c [4];
  int *local_288c [2];
  int local_2884;
  int local_2880;
  undefined4 local_287c;
  undefined4 local_2878;
  undefined4 local_2874;
  undefined4 local_2870;
  undefined4 local_286c;
  undefined4 local_2868;
  undefined4 local_2864;
  undefined4 local_2860;
  int *local_285c [16];
  int *local_281c [16];
  int *local_27dc [16];
  int local_279c [33];
  int local_2718;
  int local_2714;
  int local_2710;
  int local_270c;
  int local_2708;
  int local_2704;
  int local_2700;
  int local_26fc;
  int local_26f8;
  int local_26f4;
  int local_26f0;
  int local_26ec;
  int local_26e4;
  int local_26e0;
  int local_26dc;
  int local_26d8;
  int local_26d4;
  int local_26d0;
  int local_26cc;
  int local_26c8;
  int local_26c4;
  int local_26c0;
  int local_26bc;
  int local_26b8;
  int local_26b4;
  int local_26b0;
  int local_26ac;
  int local_26a8;
  int aiStack_26a4 [32];
  undefined auStack_2624 [128];
  undefined auStack_25a4 [128];
  undefined auStack_2524 [128];
  undefined auStack_24a4 [132];
  undefined auStack_2420 [208];
  undefined auStack_2350 [216];
  undefined auStack_2278 [244];
  undefined auStack_2184 [244];
  undefined auStack_2090 [244];
  undefined auStack_1f9c [256];
  undefined auStack_1e9c [260];
  undefined auStack_1d98 [280];
  undefined auStack_1c80 [280];
  undefined auStack_1b68 [284];
  undefined auStack_1a4c [600];
  undefined4 local_17f4;
  undefined4 local_17f0;
  undefined4 local_7ac;
  undefined4 local_7a8;
  undefined auStack_7a4 [16];
  undefined auStack_794 [16];
  undefined auStack_784 [16];
  undefined auStack_774 [16];
  undefined auStack_764 [20];
  undefined auStack_750 [20];
  undefined auStack_73c [32];
  undefined4 local_71c;
  undefined4 local_718;
  undefined4 local_714;
  undefined4 local_710;
  undefined4 local_70c;
  undefined4 local_708;
  undefined4 local_704;
  undefined4 local_700;
  undefined auStack_6fc [64];
  undefined auStack_6bc [64];
  undefined auStack_67c [64];
  undefined auStack_63c [255];
  char acStack_53d [257];
  char local_43c [4];
  char local_438 [1020];
  int local_3c;
  
  puVar6 = PTR___stack_chk_guard_006a9ae8;
  puVar4 = PTR_bio_err_006a6e3c;
  local_3c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_2990 = "";
  usertime = (char *)0xffffffff;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  local_298c = results;
  (*(code *)PTR_memset_006a99f4)(results,0,0x4b0);
  local_28b4[0] = 0;
  local_28b4[1] = 0;
  local_28b4[2] = 0;
  (*(code *)PTR_memset_006a99f4)(local_285c,0,0x40);
  (*(code *)PTR_memset_006a99f4)(local_281c,0,0x40);
  (*(code *)PTR_memset_006a99f4)(local_27dc,0,0x40);
  iVar17 = *(int *)puVar4;
  if (iVar17 == 0) {
    uVar18 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar17 = (*(code *)PTR_BIO_new_006a6ea4)(uVar18);
    *(int *)puVar4 = iVar17;
    puVar15 = PTR_stderr_006a9af8;
    if (iVar17 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar17,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
      iVar17 = *(int *)puVar4;
      unaff_s7 = puVar15;
    }
  }
  iVar17 = load_config(iVar17,0);
  puVar30 = (undefined1 *)local_285c;
  ppiVar7 = local_281c;
  pcVar20 = unaff_s7;
  if (iVar17 != 0) {
    local_289c[0] = (int *)0x0;
    local_289c[1] = (int *)0x0;
    local_289c[2] = (int *)0x0;
    local_289c[3] = (int *)0x0;
    local_2980._0_4_ = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x2001,"speed.c",0x2ab);
    if (local_2980._0_4_ != (undefined4 *)0x0) {
      local_2950 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x2001,"speed.c",0x2af);
      if (local_2950 != 0) {
        local_2958._0_4_ = &local_71c;
        (*(code *)PTR_memset_006a99f4)(auStack_1a4c,0,600);
        local_291c = local_279c + 0x20;
        local_71c = 0;
        local_2960 = ZEXT48(&local_7ac) << 0x20;
        local_28f8 = local_279c;
        local_7ac = 0;
        local_28f4 = local_279c + 0x10;
        local_7a8 = 0;
        local_718 = 0;
        local_714 = 0;
        ppiVar22 = (int **)(param_1 + -1);
        ppiVar27 = (int **)(param_2 + 4);
        local_710 = 0;
        local_70c = 0;
        local_708 = 0;
        local_704 = 0;
        local_700 = 0;
        (*(code *)PTR_memset_006a99f4)(local_291c,0,0x78);
        local_288c[0] = (int *)0x0;
        local_288c[1] = (int *)0x0;
        local_2884 = 0;
        local_2880 = 0;
        local_28b4[3] = 0;
        local_28b4[4] = 0;
        local_28b4[5] = 0;
        (*(code *)PTR_memset_006a99f4)(local_28f8,0,0x40);
        (*(code *)PTR_memset_006a99f4)(local_28f4,0,0x40);
        if (ppiVar22 != (int **)0x0) {
          local_2980 = ZEXT48(local_2980._0_4_) << 0x20;
          local_2958 = ZEXT48(local_2958._0_4_) << 0x20;
          local_2988 = 0;
          local_2938 = 0.0;
          ppiVar7 = (int **)0x0;
          local_294c = "TBEX";
          ppiVar25 = (int **)0x0;
          pcVar20 = "mdc2";
          unaff_s8 = (int **)&UNK_0063e634;
          local_2914 = 0;
          local_2974 = ppiVar22;
          goto LAB_0044ec30;
        }
        local_294c = (undefined1 *)0x0;
        local_2938 = 0.0;
        local_2914 = 0;
        pcVar21 = usertime;
        goto LAB_0044ecd8;
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,"out of memory\n");
      local_2914 = 1;
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
      (*(code *)PTR_CRYPTO_free_006a6e88)(local_2980._0_4_);
      goto LAB_0044e984;
    }
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,"out of memory\n");
  }
  local_2914 = 1;
  (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
LAB_0044e984:
  local_2974 = local_289c;
  do {
    if (*local_2974 != (int *)0x0) {
      (*(code *)PTR_RSA_free_006a7600)();
    }
    local_2974 = local_2974 + 1;
  } while (local_2974 != local_288c);
  piVar8 = local_28b4;
  do {
    if (*piVar8 != 0) {
      (*(code *)PTR_DSA_free_006a7530)();
    }
    piVar8 = piVar8 + 1;
    ppiVar27 = local_285c;
  } while (local_28b4 + 3 != piVar8);
  do {
    if (*ppiVar27 != (int *)0x0) {
      (*(code *)PTR_EC_KEY_free_006a71d4)();
    }
    ppiVar27 = ppiVar27 + 1;
    ppiVar22 = local_281c;
    ppiVar25 = local_27dc;
  } while (local_281c != ppiVar27);
  do {
    if (*ppiVar22 != (int *)0x0) {
      (*(code *)PTR_EC_KEY_free_006a71d4)();
    }
    if (*ppiVar25 != (int *)0x0) {
      (*(code *)PTR_EC_KEY_free_006a71d4)();
    }
    ppiVar22 = ppiVar22 + 1;
    ppiVar25 = (int **)((int *)ppiVar25 + 1);
  } while (local_27dc != ppiVar22);
  if (local_3c == *(int *)puVar6) {
    return local_2914;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  ppiVar27 = local_27dc;
  local_2974 = unaff_s6;
LAB_00456d08:
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"des-cbc");
  if (iVar17 == 0) {
    local_26fc = 1;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"des-ede3");
  if (iVar17 == 0) {
    local_26f8 = 1;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"aes-128-cbc");
  if (iVar17 == 0) {
    local_26dc = 1;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"aes-192-cbc");
  if (iVar17 == 0) {
    local_26d8 = 1;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"aes-256-cbc");
  if (iVar17 == 0) {
    local_26d4 = 1;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"aes-128-ige");
  if (iVar17 == 0) {
    local_26b4 = 1;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"aes-192-ige");
  if (iVar17 == 0) {
    local_26b0 = 1;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"aes-256-ige");
  if (iVar17 == 0) {
    local_26ac = 1;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"camellia-128-cbc");
  if (iVar17 == 0) {
    local_26d0 = 1;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"camellia-192-cbc");
  if (iVar17 == 0) {
    local_26cc = 1;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"camellia-256-cbc");
  if (iVar17 == 0) {
    local_26c8 = 1;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"openssl");
  if (iVar17 == 0) {
    ppiVar25 = (int **)((int)ppiVar25 + -1);
    uVar18 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a7aec)();
    (*(code *)PTR_RSA_set_default_method_006a7af0)(uVar18);
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"dsa512");
  if (iVar17 == 0) {
    local_28b4[3] = 2;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"dsa1024");
  if (iVar17 == 0) {
    local_28b4[4] = 2;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"dsa2048");
  if (iVar17 == 0) {
    local_28b4[5] = 2;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"rsa512");
  if (iVar17 == 0) {
    local_288c[0] = (int *)0x2;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"rsa1024");
  if (iVar17 == 0) {
    local_288c[1] = (int *)0x2;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"rsa2048");
  if (iVar17 == 0) {
    local_2884 = 2;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"rsa4096");
  if (iVar17 == 0) {
    local_2880 = 2;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"rc2-cbc");
  if ((iVar17 == 0) ||
     ((((local_2948._0_4_ == (undefined1 *)0x0 && (*(char *)((int)puVar30 + 1) == 'c')) &&
       (*(char *)((int)puVar30 + 2) == '2')) && (*(char *)((int)puVar30 + 3) == '\0')))) {
    local_26ec = 1;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"idea-cbc");
  if ((iVar17 == 0) || (iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,&DAT_00631c8c), iVar17 == 0)
     ) {
    local_26f4 = 1;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"seed-cbc");
  if ((iVar17 == 0) || (iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"seed"), iVar17 == 0)) {
    local_26f0 = 1;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"bf-cbc");
  if (((iVar17 == 0) || (iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"blowfish"), iVar17 == 0))
     || ((local_2974 == (int **)0x62 &&
         ((*(char *)((int)puVar30 + 1) == 'f' && (*(char *)((int)puVar30 + 2) == '\0')))))) {
    local_26e4 = 1;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"cast-cbc");
  if (((iVar17 == 0) ||
      (iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,&DAT_00631ca8), iVar17 == 0)) ||
     (iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"cast5"), iVar17 == 0)) {
    local_26e0 = 1;
    goto LAB_0044ec20;
  }
  if (local_2974 == (int **)&DAT_00000064) {
    if (((*(char *)((int)puVar30 + 1) == 'e') && (*(char *)((int)puVar30 + 2) == 's')) &&
       (*(char *)((int)puVar30 + 3) == '\0')) {
      local_26fc = 1;
      local_26f8 = 1;
      goto LAB_0044ec20;
    }
  }
  else if (((local_2974 == (int **)&DAT_00000061) && (*(char *)((int)puVar30 + 1) == 'e')) &&
          ((*(char *)((int)puVar30 + 2) == 's' && (*(char *)((int)puVar30 + 3) == '\0')))) {
    local_26dc = 1;
    local_26d8 = 1;
    local_26d4 = 1;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ghash");
  if (iVar17 == 0) {
    local_26a8 = 1;
    goto LAB_0044ec20;
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"camellia");
  if (iVar17 == 0) {
    local_26d0 = 1;
    local_26cc = 1;
    local_26c8 = 1;
    goto LAB_0044ec20;
  }
  if (local_2948._0_4_ == (undefined1 *)0x0) {
    if (*(char *)((int)puVar30 + 1) == 's') {
      cVar16 = *(char *)((int)puVar30 + 2);
      if ((cVar16 == 'a') && (*(char *)((int)puVar30 + 3) == '\0')) {
        local_288c[0] = (int *)0x1;
        local_288c[1] = (int *)0x1;
        local_2884 = 1;
        local_2880 = 1;
        goto LAB_0044ec20;
      }
      if (local_2974 == (int **)&DAT_00000064) goto LAB_00457354;
    }
  }
  else if ((local_2974 == (int **)&DAT_00000064) && (*(char *)((int)puVar30 + 1) == 's')) {
    cVar16 = *(char *)((int)puVar30 + 2);
LAB_00457354:
    if ((cVar16 == 'a') && (*(char *)((int)puVar30 + 3) == '\0')) {
      local_28b4[3] = 1;
      local_28b4[4] = 1;
      local_28b4[5] = 1;
      goto LAB_0044ec20;
    }
  }
  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdsap160");
  if (iVar17 == 0) {
    local_279c[0] = 2;
  }
  else {
    iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdsap192");
    if (iVar17 == 0) {
      local_279c[1] = 2;
    }
    else {
      iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdsap224");
      if (iVar17 == 0) {
        local_279c[2] = 2;
      }
      else {
        iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdsap256");
        if (iVar17 == 0) {
          local_279c[3] = 2;
        }
        else {
          iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdsap384");
          if (iVar17 == 0) {
            local_279c[4] = 2;
          }
          else {
            iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdsap521");
            if (iVar17 == 0) {
              local_279c[5] = 2;
            }
            else {
              iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdsak163");
              if (iVar17 == 0) {
                local_279c[6] = 2;
              }
              else {
                iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdsak233");
                if (iVar17 == 0) {
                  local_279c[7] = 2;
                }
                else {
                  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdsak283");
                  if (iVar17 == 0) {
                    local_279c[8] = 2;
                  }
                  else {
                    iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdsak409");
                    if (iVar17 == 0) {
                      local_279c[9] = 2;
                    }
                    else {
                      iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdsak571");
                      if (iVar17 == 0) {
                        local_279c[10] = 2;
                      }
                      else {
                        iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdsab163");
                        if (iVar17 == 0) {
                          local_279c[11] = 2;
                        }
                        else {
                          iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdsab233");
                          if (iVar17 == 0) {
                            local_279c[12] = 2;
                          }
                          else {
                            iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdsab283");
                            if (iVar17 == 0) {
                              local_279c[13] = 2;
                            }
                            else {
                              iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdsab409");
                              if (iVar17 == 0) {
                                local_279c[14] = 2;
                              }
                              else {
                                iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdsab571");
                                if (iVar17 == 0) {
                                  local_279c[15] = 2;
                                }
                                else {
                                  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdsa");
                                  if (iVar17 == 0) {
                                    local_279c[0] = 1;
                                    local_279c[1] = 1;
                                    local_279c[2] = 1;
                                    local_279c[3] = 1;
                                    local_279c[4] = 1;
                                    local_279c[5] = 1;
                                    local_279c[6] = 1;
                                    local_279c[7] = 1;
                                    local_279c[8] = 1;
                                    local_279c[9] = 1;
                                    local_279c[10] = 1;
                                    local_279c[11] = 1;
                                    local_279c[12] = 1;
                                    local_279c[13] = 1;
                                    local_279c[14] = 1;
                                    local_279c[15] = 1;
                                  }
                                  else {
                                    iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdhp160");
                                    if (iVar17 == 0) {
                                      local_279c[16] = 2;
                                    }
                                    else {
                                      iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdhp192");
                                      if (iVar17 == 0) {
                                        local_279c[17] = 2;
                                      }
                                      else {
                                        iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ecdhp224");
                                        if (iVar17 == 0) {
                                          local_279c[18] = 2;
                                        }
                                        else {
                                          iVar17 = (*(code *)PTR_strcmp_006a9b18)
                                                             (puVar30,"ecdhp256");
                                          if (iVar17 == 0) {
                                            local_279c[19] = 2;
                                          }
                                          else {
                                            iVar17 = (*(code *)PTR_strcmp_006a9b18)
                                                               (puVar30,"ecdhp384");
                                            if (iVar17 == 0) {
                                              local_279c[20] = 2;
                                            }
                                            else {
                                              iVar17 = (*(code *)PTR_strcmp_006a9b18)
                                                                 (puVar30,"ecdhp521");
                                              if (iVar17 == 0) {
                                                local_279c[21] = 2;
                                              }
                                              else {
                                                iVar17 = (*(code *)PTR_strcmp_006a9b18)
                                                                   (puVar30,"ecdhk163");
                                                if (iVar17 == 0) {
                                                  local_279c[22] = 2;
                                                }
                                                else {
                                                  iVar17 = (*(code *)PTR_strcmp_006a9b18)
                                                                     (puVar30,"ecdhk233");
                                                  if (iVar17 == 0) {
                                                    local_279c[23] = 2;
                                                  }
                                                  else {
                                                    iVar17 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (puVar30,"ecdhk283");
                                                    if (iVar17 == 0) {
                                                      local_279c[24] = 2;
                                                    }
                                                    else {
                                                      iVar17 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (puVar30,"ecdhk409");
                                                      if (iVar17 == 0) {
                                                        local_279c[25] = 2;
                                                      }
                                                      else {
                                                        iVar17 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (puVar30,"ecdhk571");
                                                        if (iVar17 == 0) {
                                                          local_279c[26] = 2;
                                                        }
                                                        else {
                                                          iVar17 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (puVar30,"ecdhb163");
                                                          if (iVar17 == 0) {
                                                            local_279c[27] = 2;
                                                          }
                                                          else {
                                                            iVar17 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (puVar30,"ecdhb233");
                                                            if (iVar17 == 0) {
                                                              local_279c[28] = 2;
                                                            }
                                                            else {
                                                              iVar17 = (*(code *)PTR_strcmp_006a9b18
                                                                       )(puVar30,"ecdhb283");
                                                              if (iVar17 == 0) {
                                                                local_279c[29] = 2;
                                                              }
                                                              else {
                                                                iVar17 = (*(code *)
                                                  PTR_strcmp_006a9b18)(puVar30,"ecdhb409");
                                                  if (iVar17 == 0) {
                                                    local_279c[30] = 2;
                                                  }
                                                  else {
                                                    iVar17 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (puVar30,"ecdhb571");
                                                    if (iVar17 == 0) {
                                                      local_279c[31] = 2;
                                                    }
                                                    else {
                                                      iVar17 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (puVar30,&DAT_0063e880);
                                                      if (iVar17 != 0) {
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,
                                                                   "Error: bad option or value\n");
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,"\n");
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,
                                                                   "Available values:\n");
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,"mdc2     "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,"md4      "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,"md5      "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,"hmac     "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,"sha1     "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,"sha256   "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,"sha512   "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,
                                                                   (int)local_2930._0_4_ + -0x19b4);
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,
                                                                   (int)local_2928._0_4_ + 0x1bb0);
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,"\n");
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,"idea-cbc "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,"seed-cbc "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,"rc2-cbc  "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,"bf-cbc");
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,"\n");
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,
                                                                   "des-cbc  des-ede3 ");
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar4,
                                                                                                                                      
                                                  "aes-128-cbc aes-192-cbc aes-256-cbc ");
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,
                                                             "aes-128-ige aes-192-ige aes-256-ige ")
                                                  ;
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,"\n");
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,
                                                                                                                          
                                                  "camellia-128-cbc camellia-192-cbc camellia-256-cbc "
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,&DAT_00631c94);
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,"\n");
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,
                                                             "rsa512   rsa1024  rsa2048  rsa4096\n")
                                                  ;
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,
                                                             "dsa512   dsa1024  dsa2048\n");
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,
                                                                                                                          
                                                  "ecdsap160 ecdsap192 ecdsap224 ecdsap256 ecdsap384 ecdsap521\n"
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,
                                                                                                                          
                                                  "ecdsak163 ecdsak233 ecdsak283 ecdsak409 ecdsak571\n"
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,
                                                                                                                          
                                                  "ecdsab163 ecdsab233 ecdsab283 ecdsab409 ecdsab571\n"
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,"ecdsa\n");
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,
                                                                                                                          
                                                  "ecdhp160  ecdhp192  ecdhp224 ecdhp256  ecdhp384  ecdhp521\n"
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,
                                                                                                                          
                                                  "ecdhk163  ecdhk233  ecdhk283  ecdhk409  ecdhk571\n"
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,
                                                                                                                          
                                                  "ecdhb163  ecdhb233  ecdhb283  ecdhb409  ecdhb571\n"
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,"ecdh\n");
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,"idea     ");
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,"seed     ");
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,&DAT_0063eb7c);
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,&DAT_0063eb88);
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,"aes      ");
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,"camellia ");
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,"rsa      ");
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,"blowfish");
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,"\n");
                                                  local_2914 = 1;
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,"\n");
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,
                                                             "Available options:\n");
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,
                                                                                                                          
                                                  "-engine e       use engine e, possibly a hardware device.\n"
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,
                                                             "-evp e          use EVP e.\n");
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,
                                                                                                                          
                                                  "-decrypt        time decryption instead of encryption (only EVP).\n"
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,
                                                                                                                          
                                                  "-mr             produce machine readable output.\n"
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar4,
                                                                                                                          
                                                  "-multi n        run n benchmarks in parallel.\n")
                                                  ;
                                                  goto LAB_0044ee88;
                                                  }
                                                  local_279c[16] = 1;
                                                  local_279c[17] = 1;
                                                  local_279c[18] = 1;
                                                  local_279c[19] = 1;
                                                  local_279c[20] = 1;
                                                  local_279c[21] = 1;
                                                  local_279c[22] = 1;
                                                  local_279c[23] = 1;
                                                  local_279c[24] = 1;
                                                  local_279c[25] = 1;
                                                  local_279c[26] = 1;
                                                  local_279c[27] = 1;
                                                  local_279c[28] = 1;
                                                  local_279c[29] = 1;
                                                  local_279c[30] = 1;
                                                  local_279c[31] = 1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0044ec20:
  do {
    ppiVar22 = (int **)((int)ppiVar22 + -1);
    ppiVar27 = ppiVar27 + 1;
    while( true ) {
      unaff_s7 = PTR_stderr_006a9af8;
      puVar15 = PTR_stdout_006a99c8;
      ppiVar25 = (int **)((int)ppiVar25 + 1);
      if (ppiVar22 == (int **)0x0) {
        local_2988._0_4_ = (double *)((ulonglong)local_2988 >> 0x20);
        local_2980._0_4_ = (undefined4 *)(local_2980 >> 0x20);
        local_2958._0_4_ = (undefined4 *)((ulonglong)local_2958 >> 0x20);
        if (local_2988._0_4_ == (double *)0x0) {
          pcVar21 = *(char **)(local_2990 + -0x4754);
          unaff_s7 = pcVar20;
          goto LAB_0044ecd0;
        }
        puVar13 = (undefined4 *)(*(code *)PTR_malloc_006a9a58)((int)local_2988._0_4_ << 2);
        local_2928 = (double)(ZEXT48(puVar13) << 0x20);
        local_2948 = local_2980 & 0xffffffff00000000;
        local_2958 = ZEXT48(puVar13) << 0x20;
        local_2980 = 0x63eca000000000;
        iVar17 = 0;
        puVar24 = puVar13;
        goto LAB_004549f0;
      }
LAB_0044ec30:
      puVar30 = (undefined1 *)*ppiVar27;
      if ((int)ppiVar22 < 1) goto LAB_0044ee2c;
      iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"-elapsed");
      if (iVar17 == 0) {
        ppiVar25 = (int **)((int)ppiVar25 + -1);
        *(undefined4 *)(local_2990 + -0x4754) = 0;
        goto LAB_0044ec20;
      }
      iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,&DAT_0063e5b0);
      if (iVar17 != 0) break;
      puVar30 = (undefined1 *)(ppiVar27 + 1);
      if (ppiVar22 == (int **)0x1) {
        local_2914 = 1;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,"no EVP given\n");
        goto LAB_0044ee88;
      }
      ppiVar7 = (int **)(*(code *)PTR_EVP_get_cipherbyname_006a7394)(ppiVar27[1]);
      if (ppiVar7 == (int **)0x0) {
        uVar26 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(ppiVar27[1]);
        local_2938 = (double)((ulonglong)uVar26 << 0x20);
        if (uVar26 == 0) {
          local_2914 = 1;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar4,"%s is an unknown cipher or digest\n",ppiVar27[1]);
          goto LAB_0044ee88;
        }
      }
      ppiVar22 = (int **)((int)ppiVar22 + -2);
      local_26c4 = 1;
      ppiVar27 = ppiVar27 + 2;
    }
    iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"-decrypt");
    if (iVar17 != 0) {
      iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"-engine");
      if (iVar17 == 0) {
        ppiVar22 = (int **)((int)ppiVar22 + -1);
        puVar30 = (undefined1 *)(ppiVar27 + 1);
        if (ppiVar22 == (int **)0x0) {
          local_2914 = 1;
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,"no engine given\n");
          goto LAB_0044ee88;
        }
        ppiVar25 = (int **)((int)ppiVar25 + -1);
        setup_engine(*(undefined4 *)puVar4,ppiVar27[1],0);
        ppiVar27 = (int **)puVar30;
        goto LAB_0044ec20;
      }
      iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"-multi");
      if (iVar17 == 0) {
        ppiVar22 = (int **)((int)ppiVar22 + -1);
        puVar30 = (undefined1 *)(ppiVar27 + 1);
        if (ppiVar22 == (int **)0x0) {
          local_2914 = 1;
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,"no multi count given\n");
          goto LAB_0044ee88;
        }
        uVar26 = (*(code *)PTR_strtol_006a9958)(ppiVar27[1],0,10);
        local_2988 = (ulonglong)uVar26 << 0x20;
        if ((int)uVar26 < 1) {
          local_2914 = 1;
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,"bad multi count\n");
          goto LAB_0044ee88;
        }
        ppiVar25 = (int **)((int)ppiVar25 + -1);
        ppiVar27 = (int **)puVar30;
        goto LAB_0044ec20;
      }
      if ((((*puVar30 == '-') && (*(char *)((int)puVar30 + 1) == 'm')) &&
          (*(char *)((int)puVar30 + 2) == 'r')) && (*(char *)((int)puVar30 + 3) == '\0')) {
        ppiVar25 = (int **)((int)ppiVar25 + -1);
        mr = 1;
      }
      else {
LAB_0044ee2c:
        iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,pcVar20);
        if (iVar17 != 0) {
          local_2974 = (int **)(uint)(byte)*puVar30;
          if ((local_2974 == (int **)&DAT_0000006d) && (*(char *)((int)puVar30 + 1) == 'd')) {
            if ((*(char *)((int)puVar30 + 2) == '4') && (*(char *)((int)puVar30 + 3) == '\0')) {
              local_2714 = 1;
              goto LAB_0044ec20;
            }
            if ((*(char *)((int)puVar30 + 2) == '5') && (*(char *)((int)puVar30 + 3) == '\0')) {
              local_2710 = 1;
              goto LAB_0044ec20;
            }
          }
          iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,unaff_s8);
          if (iVar17 == 0) {
            local_270c = 1;
          }
          else {
            iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,(int **)((int)local_294c + -0x27e8));
            if (iVar17 == 0) {
              local_2708 = 1;
            }
            else if ((((local_2974 == (int **)&DAT_00000073) && (*(char *)((int)puVar30 + 1) == 'h')
                      ) && (*(char *)((int)puVar30 + 2) == 'a')) &&
                    (*(char *)((int)puVar30 + 3) == '\0')) {
              local_2708 = 1;
              local_26c0 = 1;
              local_26bc = 1;
            }
            else {
              iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"sha256");
              if (iVar17 == 0) {
                local_26c0 = 1;
              }
              else {
                iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"sha512");
                if (iVar17 == 0) {
                  local_26bc = 1;
                  goto LAB_0044ec20;
                }
                local_2930 = 8.900295434028806e-307;
                iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"whirlpool");
                if (iVar17 != 0) {
                  iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ripemd");
                  if (iVar17 != 0) {
                    local_2928 = 8.455280662327365e-307;
                    iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"rmd160");
                    if ((iVar17 != 0) &&
                       (iVar17 = (*(code *)PTR_strcmp_006a9b18)(puVar30,"ripemd160"), iVar17 != 0))
                    {
                      local_2948 = (ulonglong)(0x72U - (int)local_2974) << 0x20;
                      if (((0x72U - (int)local_2974 != 0) ||
                          ((*(char *)((int)puVar30 + 1) != 'c' ||
                           (*(char *)((int)puVar30 + 2) != '4')))) ||
                         (*(char *)((int)puVar30 + 3) != '\0')) goto LAB_00456d08;
                      local_2700 = 1;
                      goto LAB_0044ec20;
                    }
                  }
                  local_2704 = 1;
                  goto LAB_0044ec20;
                }
                local_26b8 = 1;
              }
            }
          }
          goto LAB_0044ec20;
        }
        local_2718 = 1;
      }
      goto LAB_0044ec20;
    }
    ppiVar25 = (int **)((int)ppiVar25 + -1);
    local_2914 = 1;
  } while( true );
LAB_004549f0:
  iVar34 = (*(code *)PTR_pipe_006a99d0)(&local_17f4);
  puVar31 = (undefined4 *)PTR_stdout_006a99c8;
  if (iVar34 == -1) {
    uVar29 = *(undefined4 *)unaff_s7;
    uVar18 = 0xd;
    pcVar20 = "pipe failure\n";
LAB_00456c64:
    (*(code *)PTR_fwrite_006a9a74)(pcVar20,1,uVar18,uVar29);
    iVar17 = (*(code *)PTR_exit_006a9a40)(1);
    return iVar17;
  }
  (*(code *)PTR_fflush_006a9b04)(*(undefined4 *)puVar15);
  (*(code *)PTR_fflush_006a9b04)(*(undefined4 *)unaff_s7);
  pcVar21 = (char *)(*(code *)PTR_fork_006a99b8)();
  local_2948._0_4_ = (undefined1 *)(local_2948 >> 0x20);
  local_2980._0_4_ = (undefined4 *)local_2948._0_4_;
  if (pcVar21 != (char *)0x0) goto LAB_004549b0;
  (*(code *)PTR_close_006a994c)(local_17f4);
  (*(code *)PTR_close_006a994c)(1);
  iVar17 = (*(code *)PTR_dup_006a9afc)(local_17f0);
  if (iVar17 == -1) {
    uVar18 = 0xb;
    pcVar20 = "dup failed\n";
    uVar29 = *(undefined4 *)PTR_stderr_006a9af8;
    goto LAB_00456c64;
  }
  (*(code *)PTR_close_006a994c)(local_17f0);
  puVar15 = PTR_free_006a9af0;
  *(undefined4 *)(local_2990 + -0x4754) = 0;
  mr = 1;
  (*(code *)puVar15)(puVar13);
  local_298c = pcVar21;
LAB_0044ecd0:
  pcVar20 = unaff_s7;
  local_294c = (undefined1 *)ppiVar7;
  if (ppiVar25 == (int **)0x0) {
LAB_0044ecd8:
    piVar8 = local_291c;
    for (iVar17 = 1; (iVar17 == 0x17 || (*piVar8 = 1, iVar17 != 0x1e)); iVar17 = iVar17 + 1) {
      piVar8 = piVar8 + 1;
    }
    local_288c[0] = (int *)0x1;
    local_288c[1] = (int *)0x1;
    local_2884 = 1;
    local_2880 = 1;
    local_28b4[3] = 1;
    local_28b4[4] = 1;
    local_28b4[5] = 1;
    local_279c[0] = 1;
    local_279c[1] = 1;
    local_279c[2] = 1;
    local_279c[3] = 1;
    local_279c[4] = 1;
    local_279c[5] = 1;
    local_279c[6] = 1;
    local_279c[7] = 1;
    local_279c[8] = 1;
    local_279c[9] = 1;
    local_279c[10] = 1;
    local_279c[11] = 1;
    local_279c[12] = 1;
    local_279c[13] = 1;
    local_279c[14] = 1;
    local_279c[15] = 1;
    local_279c[16] = 1;
    local_279c[17] = 1;
    local_279c[18] = 1;
    local_279c[19] = 1;
    local_279c[20] = 1;
    local_279c[21] = 1;
    local_279c[22] = 1;
    local_279c[23] = 1;
    local_279c[24] = 1;
    local_279c[25] = 1;
    local_279c[26] = 1;
    local_279c[27] = 1;
    local_279c[28] = 1;
    local_279c[29] = 1;
    local_279c[30] = 1;
    local_279c[31] = 1;
    pcVar20 = unaff_s7;
  }
  local_28e0 = 0;
  piVar8 = local_291c;
  do {
    iVar17 = *piVar8;
    piVar8 = piVar8 + 1;
    local_28e0 = local_28e0 + (uint)(iVar17 != 0);
  } while (aiStack_26a4 != piVar8);
  if ((pcVar21 == (char *)0x0) && (mr == 0)) {
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar4,
               "You have chosen to measure elapsed time instead of user CPU time.\n");
  }
  local_2974 = local_289c;
  puVar30 = rsa_data_17831;
  puVar28 = rsa_data_length_17832;
  ppiVar7 = (int **)0x0;
  unaff_s8 = &local_28b8;
  do {
    local_28b8 = *(int **)puVar30;
    piVar8 = (int *)(*(code *)PTR_d2i_RSAPrivateKey_006a79e4)(0,unaff_s8,*(undefined4 *)puVar28);
    *local_2974 = piVar8;
    if (piVar8 == (int *)0x0) {
      local_2914 = 1;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar4,"internal error loading RSA key number %d\n",ppiVar7);
      goto LAB_0044ee88;
    }
    ppiVar7 = (int **)((int)ppiVar7 + 1);
    puVar30 = (undefined1 *)((int)puVar30 + 4);
    puVar28 = (undefined1 *)((int)puVar28 + 4);
    local_2974 = local_2974 + 1;
  } while (ppiVar7 != (int **)&SUB_00000004);
  local_28b4[0] = get_dsa512();
  local_28b4[1] = get_dsa1024();
  local_28b4[2] = get_dsa2048();
  (*(code *)PTR_DES_set_key_unchecked_006a79e8)(&key_17814,auStack_2624);
  (*(code *)PTR_DES_set_key_unchecked_006a79e8)(&key2_17815,auStack_25a4);
  (*(code *)PTR_DES_set_key_unchecked_006a79e8)(&key3_17816,auStack_2524);
  (*(code *)PTR_AES_set_encrypt_key_006a79ec)(key16_17807,0x80,auStack_2278);
  (*(code *)PTR_AES_set_encrypt_key_006a79ec)(key24_17808,0xc0,auStack_2184);
  (*(code *)PTR_AES_set_encrypt_key_006a79ec)(key32_17809,0x100,auStack_2090);
  (*(code *)PTR_Camellia_set_key_006a79f0)(key16_17807,0x80,auStack_1d98);
  (*(code *)PTR_Camellia_set_key_006a79f0)(ckey24_17810,0xc0,auStack_1c80);
  (*(code *)PTR_Camellia_set_key_006a79f0)(ckey32_17811,0x100,auStack_1b68);
  (*(code *)PTR_idea_set_encrypt_key_006a79f4)(key16_17807,auStack_2350);
  (*(code *)PTR_SEED_set_key_006a79f8)(key16_17807,aiStack_26a4);
  (*(code *)PTR_RC4_set_key_006a79fc)(auStack_1e9c,0x10,key16_17807);
  (*(code *)PTR_RC2_set_key_006a7a00)(auStack_1f9c,0x10,key16_17807,0x80);
  (*(code *)PTR_BF_set_key_006a7a04)(&local_17f4,0x10,key16_17807);
  (*(code *)PTR_CAST_set_key_006a7a08)(auStack_24a4,0x10,key16_17807);
  local_287c = 0;
  local_2878 = 0;
  local_2874 = 0;
  local_2870 = 0;
  local_286c = 0;
  local_2868 = 0;
  local_2864 = 0;
  local_2860 = 0;
  (*(code *)PTR_signal_006a9ad8)(0xe,sig_done);
  if (local_2718 != 0) {
    iVar17 = 0x10;
    local_2928 = 8.880847767003767e-307;
    uVar18 = *(undefined4 *)puVar4;
    pdVar33 = (double *)(results + 0x28);
    if (mr != 0) goto LAB_0044f504;
LAB_0044f380:
    pcVar20 = "Doing %s for %ds on %d size blocks: ";
    do {
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20,names._4_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        iVar34 = iVar34 + 1;
        uVar18 = (*(code *)PTR_EVP_mdc2_006a7a10)();
        (*(code *)PTR_EVP_Digest_006a7a14)(local_2980._0_4_,iVar17,auStack_7a4,0,uVar18,0);
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._4_4_,dVar36);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      local_2930 = dVar36;
      if (pdVar23 == (double *)(results + 0x50)) goto LAB_0044f538;
      iVar17 = *local_2928._0_4_;
      local_2928 = (double)(ZEXT48(local_2928._0_4_ + 1) << 0x20);
      uVar18 = *(undefined4 *)puVar4;
      pdVar33 = pdVar23;
      if (mr == 0) goto LAB_0044f380;
LAB_0044f504:
      pcVar20 = "+DT:%s:%d:%d\n";
    } while( true );
  }
  iVar34 = 0;
  dVar36 = 0.0;
LAB_0044f538:
  if (local_2714 != 0) {
    iVar17 = 0x10;
    local_2928 = 8.880847767003767e-307;
    uVar18 = *(undefined4 *)puVar4;
    pdVar33 = (double *)(results + 0x50);
    if (mr != 0) goto LAB_0044f72c;
LAB_0044f5a8:
    pcVar20 = "Doing %s for %ds on %d size blocks: ";
    do {
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20,names._8_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        iVar34 = iVar34 + 1;
        uVar18 = (*(code *)PTR_EVP_md4_006a7a18)();
        (*(code *)PTR_EVP_Digest_006a7a14)(local_2980._0_4_,iVar17,auStack_794,0,uVar18,0);
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._8_4_,dVar36);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      local_2930 = dVar36;
      if (pdVar23 == (double *)(results + 0x78)) break;
      iVar17 = *local_2928._0_4_;
      local_2928 = (double)(ZEXT48(local_2928._0_4_ + 1) << 0x20);
      uVar18 = *(undefined4 *)puVar4;
      pdVar33 = pdVar23;
      if (mr == 0) goto LAB_0044f5a8;
LAB_0044f72c:
      pcVar20 = "+DT:%s:%d:%d\n";
    } while( true );
  }
  if (local_2710 != 0) {
    iVar17 = 0x10;
    local_2918 = (int *)(lengths + 4);
    uVar18 = *(undefined4 *)puVar4;
    pdVar33 = (double *)(results + 0x78);
    if (mr != 0) goto LAB_0044f934;
LAB_0044f7ac:
    pcVar20 = "Doing %s for %ds on %d size blocks: ";
    do {
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20,names._12_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        iVar34 = iVar34 + 1;
        uVar18 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(&DAT_00631ba0);
        (*(code *)PTR_EVP_Digest_006a7a14)(local_2980._0_4_,iVar17,auStack_784,0,uVar18,0);
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      local_2930 = (double)((ulonglong)names._12_4_ << 0x20);
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._12_4_,dVar36);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      local_2928 = dVar36;
      if (pdVar23 == (double *)(results + 0xa0)) break;
      piVar8 = local_2918 + 1;
      iVar17 = *local_2918;
      uVar18 = *(undefined4 *)puVar4;
      local_2918 = piVar8;
      pdVar33 = pdVar23;
      if (mr == 0) goto LAB_0044f7ac;
LAB_0044f934:
      pcVar20 = "+DT:%s:%d:%d\n";
    } while( true );
  }
  if (local_270c != 0) {
    iVar17 = 0x10;
    (*(code *)PTR_HMAC_CTX_init_006a7a1c)(auStack_2420);
    uVar18 = (*(code *)PTR_EVP_md5_006a70c8)();
    (*(code *)PTR_HMAC_Init_ex_006a7acc)(auStack_2420,"This is a key...",0x10,uVar18,0);
    local_2928 = 8.880847767003767e-307;
    pdVar33 = (double *)(results + 0xa0);
    do {
      if (mr == 0) {
        pcVar20 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar20 = "+DT:%s:%d:%d\n";
      }
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,names._16_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_HMAC_Init_ex_006a7acc)(auStack_2420,0,0,0,0);
        iVar34 = iVar34 + 1;
        (*(code *)PTR_HMAC_Update_006a7ad0)(auStack_2420,local_2980._0_4_,iVar17);
        (*(code *)PTR_HMAC_Final_006a7ad4)(auStack_2420,auStack_774,0);
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._16_4_,dVar36);
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      if (pdVar33 + 1 == (double *)(results + 200)) goto LAB_004552b0;
      iVar17 = *local_2928._0_4_;
      local_2928 = (double)(ZEXT48(local_2928._0_4_ + 1) << 0x20);
      pdVar33 = pdVar33 + 1;
    } while( true );
  }
LAB_0044f94c:
  if (local_2708 != 0) {
    iVar17 = 0x10;
    local_2928 = 8.880847767003767e-307;
    uVar18 = *(undefined4 *)puVar4;
    pdVar33 = (double *)(results + 200);
    if (mr != 0) goto LAB_0044fb40;
LAB_0044f9bc:
    pcVar20 = "Doing %s for %ds on %d size blocks: ";
    do {
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20,names._20_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        iVar34 = iVar34 + 1;
        uVar18 = (*(code *)PTR_EVP_sha1_006a75d0)();
        (*(code *)PTR_EVP_Digest_006a7a14)(local_2980._0_4_,iVar17,auStack_764,0,uVar18,0);
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._20_4_,dVar36);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      local_2930 = dVar36;
      if (pdVar23 == (double *)(results + 0xf0)) break;
      iVar17 = *local_2928._0_4_;
      local_2928 = (double)(ZEXT48(local_2928._0_4_ + 1) << 0x20);
      uVar18 = *(undefined4 *)puVar4;
      pdVar33 = pdVar23;
      if (mr == 0) goto LAB_0044f9bc;
LAB_0044fb40:
      pcVar20 = "+DT:%s:%d:%d\n";
    } while( true );
  }
  if (local_26c0 != 0) {
    iVar17 = 0x10;
    local_2928 = 8.880847767003767e-307;
    uVar18 = *(undefined4 *)puVar4;
    pdVar33 = (double *)(results + 0x398);
    if (mr != 0) goto LAB_0044fd28;
LAB_0044fbbc:
    pcVar20 = "Doing %s for %ds on %d size blocks: ";
    do {
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20,names._92_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_SHA256_006a7a20)(local_2980._0_4_,iVar17,auStack_73c);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._92_4_,dVar36);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      local_2930 = dVar36;
      if (pdVar23 == (double *)(results + 0x3c0)) break;
      iVar17 = *local_2928._0_4_;
      local_2928 = (double)(ZEXT48(local_2928._0_4_ + 1) << 0x20);
      uVar18 = *(undefined4 *)puVar4;
      pdVar33 = pdVar23;
      if (mr == 0) goto LAB_0044fbbc;
LAB_0044fd28:
      pcVar20 = "+DT:%s:%d:%d\n";
    } while( true );
  }
  if (local_26bc != 0) {
    iVar17 = 0x10;
    local_2928 = 8.880847767003767e-307;
    uVar18 = *(undefined4 *)puVar4;
    pdVar33 = (double *)(results + 0x3c0);
    if (mr != 0) goto LAB_0044ff10;
LAB_0044fda4:
    pcVar20 = "Doing %s for %ds on %d size blocks: ";
    do {
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20,names._96_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_SHA512_006a7a24)(local_2980._0_4_,iVar17,auStack_6bc);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._96_4_,dVar36);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      local_2930 = dVar36;
      if (pdVar23 == (double *)(results + 1000)) break;
      iVar17 = *local_2928._0_4_;
      local_2928 = (double)(ZEXT48(local_2928._0_4_ + 1) << 0x20);
      uVar18 = *(undefined4 *)puVar4;
      pdVar33 = pdVar23;
      if (mr == 0) goto LAB_0044fda4;
LAB_0044ff10:
      pcVar20 = "+DT:%s:%d:%d\n";
    } while( true );
  }
  if (local_26b8 != 0) {
    iVar17 = 0x10;
    local_2928 = 8.880847767003767e-307;
    uVar18 = *(undefined4 *)puVar4;
    pdVar33 = (double *)(results + 1000);
    if (mr != 0) goto LAB_004500f8;
LAB_0044ff8c:
    pcVar20 = "Doing %s for %ds on %d size blocks: ";
    do {
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20,names._100_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_WHIRLPOOL_006a7a28)(local_2980._0_4_,iVar17,auStack_67c);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._100_4_,dVar36);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      local_2930 = dVar36;
      if (pdVar23 == (double *)(results + 0x410)) break;
      iVar17 = *local_2928._0_4_;
      local_2928 = (double)(ZEXT48(local_2928._0_4_ + 1) << 0x20);
      uVar18 = *(undefined4 *)puVar4;
      pdVar33 = pdVar23;
      if (mr == 0) goto LAB_0044ff8c;
LAB_004500f8:
      pcVar20 = "+DT:%s:%d:%d\n";
    } while( true );
  }
  if (local_2704 != 0) {
    iVar17 = 0x10;
    local_2928 = 8.880847767003767e-307;
    uVar18 = *(undefined4 *)puVar4;
    pdVar33 = (double *)(results + 0xf0);
    if (mr != 0) goto LAB_004502f8;
LAB_00450174:
    pcVar20 = "Doing %s for %ds on %d size blocks: ";
    do {
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20,names._24_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        iVar34 = iVar34 + 1;
        uVar18 = (*(code *)PTR_EVP_ripemd160_006a7a2c)();
        (*(code *)PTR_EVP_Digest_006a7a14)(local_2980._0_4_,iVar17,auStack_750,0,uVar18,0);
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._24_4_,dVar36);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      local_2930 = dVar36;
      if (pdVar23 == (double *)(results + 0x118)) break;
      iVar17 = *local_2928._0_4_;
      local_2928 = (double)(ZEXT48(local_2928._0_4_ + 1) << 0x20);
      uVar18 = *(undefined4 *)puVar4;
      pdVar33 = pdVar23;
      if (mr == 0) goto LAB_00450174;
LAB_004502f8:
      pcVar20 = "+DT:%s:%d:%d\n";
    } while( true );
  }
  if (local_2700 != 0) {
    pdVar33 = (double *)(results + 0x118);
    iVar17 = 0x10;
    local_2930 = 8.880847767003767e-307;
    local_2928 = 1.185753592986413e-306;
    uVar18 = *(undefined4 *)puVar4;
    if (mr != 0) goto LAB_004504e8;
LAB_00450370:
    pcVar20 = "Doing %s for %ds on %d size blocks: ";
    pdVar23 = pdVar33;
    do {
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20,names._28_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_RC4_006a7a30)(auStack_1e9c,iVar17,local_2980._0_4_,local_2980._0_4_);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      pdVar33 = pdVar23 + 1;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._28_4_,dVar36);
      *pdVar23 = ((double)iVar34 / dVar36) * (double)iVar17;
      if (pdVar33 == (double *)(results + 0x140)) break;
      iVar17 = *(int *)local_2930._0_4_;
      local_2930 = (double)(ZEXT48((int *)((int)local_2930._0_4_ + 4)) << 0x20);
      uVar18 = *(undefined4 *)puVar4;
      if (mr == 0) goto LAB_00450370;
LAB_004504e8:
      pcVar20 = "+DT:%s:%d:%d\n";
      pdVar23 = pdVar33;
    } while( true );
  }
  if (local_26fc != 0) {
    puVar30 = lengths;
    pdVar33 = (double *)(results + 0x140);
    do {
      iVar17 = *(int *)puVar30;
      if (mr == 0) {
        pcVar20 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar20 = "+DT:%s:%d:%d\n";
      }
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,names._32_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_DES_ncbc_encrypt_006a7a34)
                  (local_2980._0_4_,local_2980._0_4_,iVar17,auStack_2624,local_2960._0_4_,1);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      local_2930 = (double)((ulonglong)names._32_4_ << 0x20);
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._32_4_,dVar36);
      puVar30 = (undefined1 *)((int)puVar30 + 4);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      local_2928 = dVar36;
      pdVar33 = pdVar23;
    } while (pdVar23 != (double *)(results + 0x168));
  }
  if (local_26f8 != 0) {
    puVar30 = lengths;
    pdVar33 = (double *)(results + 0x168);
    do {
      iVar17 = *(int *)puVar30;
      if (mr == 0) {
        pcVar20 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar20 = "+DT:%s:%d:%d\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,names._36_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      iVar34 = 0;
      do {
        iVar34 = iVar34 + 1;
        (*(code *)PTR_DES_ede3_cbc_encrypt_006a7a38)
                  (local_2980._0_4_,local_2980._0_4_,iVar17,auStack_2624,auStack_25a4,auStack_2524,
                   local_2960._0_4_,1);
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      local_2930 = (double)((ulonglong)names._36_4_ << 0x20);
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._36_4_,dVar36);
      puVar30 = (undefined1 *)((int)puVar30 + 4);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      local_2928 = dVar36;
      pdVar33 = pdVar23;
    } while (pdVar23 != (double *)(results + 400));
  }
  if (local_26dc != 0) {
    iVar17 = 0x10;
    uVar18 = *(undefined4 *)puVar4;
    local_2930 = 1.185998046901533e-306;
    local_2928 = 8.900295434028806e-307;
    pdVar33 = (double *)(results + 0x280);
    piVar8 = (int *)(lengths + 4);
    if (mr != 0) goto LAB_00450ae4;
LAB_00450960:
    pcVar20 = "Doing %s for %ds on %d size blocks: ";
    do {
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20,names._64_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_AES_cbc_encrypt_006a7a3c)
                  (local_2980._0_4_,local_2980._0_4_,iVar17,auStack_2278,local_2958._0_4_,1);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._64_4_,dVar36);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      if (pdVar23 == (double *)(results + 0x2a8)) break;
      piVar12 = piVar8 + 1;
      iVar17 = *piVar8;
      uVar18 = *(undefined4 *)puVar4;
      pdVar33 = pdVar23;
      piVar8 = piVar12;
      if (mr == 0) goto LAB_00450960;
LAB_00450ae4:
      pcVar20 = "+DT:%s:%d:%d\n";
    } while( true );
  }
  if (local_26d8 != 0) {
    iVar17 = 0x10;
    uVar18 = *(undefined4 *)puVar4;
    local_2930 = 1.186025208447657e-306;
    local_2928 = 8.900295434028806e-307;
    pdVar33 = (double *)(results + 0x2a8);
    piVar8 = (int *)(lengths + 4);
    if (mr != 0) goto LAB_00450ce8;
LAB_00450b64:
    pcVar20 = "Doing %s for %ds on %d size blocks: ";
    do {
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20,names._68_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_AES_cbc_encrypt_006a7a3c)
                  (local_2980._0_4_,local_2980._0_4_,iVar17,auStack_2184,local_2958._0_4_,1);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._68_4_,dVar36);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      if (pdVar23 == (double *)(results + 0x2d0)) break;
      piVar12 = piVar8 + 1;
      iVar17 = *piVar8;
      uVar18 = *(undefined4 *)puVar4;
      pdVar33 = pdVar23;
      piVar8 = piVar12;
      if (mr == 0) goto LAB_00450b64;
LAB_00450ce8:
      pcVar20 = "+DT:%s:%d:%d\n";
    } while( true );
  }
  if (local_26d4 != 0) {
    iVar17 = 0x10;
    uVar18 = *(undefined4 *)puVar4;
    local_2930 = 1.186052369993781e-306;
    local_2928 = 8.900295434028806e-307;
    pdVar33 = (double *)(results + 0x2d0);
    piVar8 = (int *)(lengths + 4);
    if (mr != 0) goto LAB_00450eec;
LAB_00450d68:
    pcVar20 = "Doing %s for %ds on %d size blocks: ";
    do {
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20,names._72_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_AES_cbc_encrypt_006a7a3c)
                  (local_2980._0_4_,local_2980._0_4_,iVar17,auStack_2090,local_2958._0_4_,1);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._72_4_,dVar36);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      if (pdVar23 == (double *)(results + 0x2f8)) break;
      piVar12 = piVar8 + 1;
      iVar17 = *piVar8;
      uVar18 = *(undefined4 *)puVar4;
      pdVar33 = pdVar23;
      piVar8 = piVar12;
      if (mr == 0) goto LAB_00450d68;
LAB_00450eec:
      pcVar20 = "+DT:%s:%d:%d\n";
    } while( true );
  }
  if (local_26b4 != 0) {
    iVar17 = 0x10;
    uVar18 = *(undefined4 *)puVar4;
    local_2930 = 1.186269662362776e-306;
    local_2928 = 8.900295434028806e-307;
    pdVar33 = (double *)(results + 0x410);
    piVar8 = (int *)(lengths + 4);
    if (mr != 0) goto LAB_004510fc;
LAB_00450f6c:
    pcVar20 = "Doing %s for %ds on %d size blocks: ";
    do {
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20,names._104_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_AES_ige_encrypt_006a7a40)
                  (local_2980._0_4_,local_2950,iVar17,auStack_2278,local_2958._0_4_,1);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._104_4_,dVar36);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      if (pdVar23 == (double *)(results + 0x438)) break;
      piVar12 = piVar8 + 1;
      iVar17 = *piVar8;
      uVar18 = *(undefined4 *)puVar4;
      pdVar33 = pdVar23;
      piVar8 = piVar12;
      if (mr == 0) goto LAB_00450f6c;
LAB_004510fc:
      pcVar20 = "+DT:%s:%d:%d\n";
    } while( true );
  }
  if (local_26b0 != 0) {
    iVar17 = 0x10;
    uVar18 = *(undefined4 *)puVar4;
    local_2930 = 1.1862968239089e-306;
    local_2928 = 8.900295434028806e-307;
    pdVar33 = (double *)(results + 0x438);
    piVar8 = (int *)(lengths + 4);
    if (mr != 0) goto LAB_0045130c;
LAB_0045117c:
    pcVar20 = "Doing %s for %ds on %d size blocks: ";
    do {
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20,names._108_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_AES_ige_encrypt_006a7a40)
                  (local_2980._0_4_,local_2950,iVar17,auStack_2184,local_2958._0_4_,1);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._108_4_,dVar36);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      if (pdVar23 == (double *)(results + 0x460)) break;
      piVar12 = piVar8 + 1;
      iVar17 = *piVar8;
      uVar18 = *(undefined4 *)puVar4;
      pdVar33 = pdVar23;
      piVar8 = piVar12;
      if (mr == 0) goto LAB_0045117c;
LAB_0045130c:
      pcVar20 = "+DT:%s:%d:%d\n";
    } while( true );
  }
  if (local_26ac != 0) {
    iVar17 = 0x10;
    uVar18 = *(undefined4 *)puVar4;
    local_2930 = 8.900295434028806e-307;
    local_2928 = 8.900295434028806e-307;
    pdVar33 = (double *)(results + 0x460);
    piVar8 = (int *)(lengths + 4);
    if (mr != 0) goto LAB_00451514;
LAB_0045138c:
    pcVar20 = "Doing %s for %ds on %d size blocks: ";
    do {
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20,names._112_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_AES_ige_encrypt_006a7a40)
                  (local_2980._0_4_,local_2950,iVar17,auStack_2090,local_2958._0_4_,1);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._112_4_,dVar36);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      if (pdVar23 == (double *)(results + 0x488)) break;
      piVar12 = piVar8 + 1;
      iVar17 = *piVar8;
      uVar18 = *(undefined4 *)puVar4;
      pdVar33 = pdVar23;
      piVar8 = piVar12;
      if (mr == 0) goto LAB_0045138c;
LAB_00451514:
      pcVar20 = "+DT:%s:%d:%d\n";
    } while( true );
  }
  if (local_26a8 != 0) {
    iVar17 = 0x10;
    uVar18 = (*(code *)PTR_CRYPTO_gcm128_new_006a7a44)(auStack_2278,PTR_AES_encrypt_006a7ac0);
    (*(code *)PTR_CRYPTO_gcm128_setiv_006a7ac4)(uVar18,"0123456789ab",0xc);
    local_2988._0_4_ = (double *)(results + 0x488);
    local_2930 = 8.900295434028806e-307;
    local_2928 = 8.900295434028806e-307;
    piVar8 = (int *)(lengths + 4);
    do {
      if (mr == 0) {
        pcVar20 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar20 = "+DT:%s:%d:%d\n";
      }
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,names._116_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_CRYPTO_gcm128_aad_006a7ac8)(uVar18,local_2980._0_4_,iVar17);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._116_4_,dVar36);
      *local_2988._0_4_ = ((double)iVar34 / dVar36) * (double)iVar17;
      if (local_2988._0_4_ + 1 == (double *)&mr) goto LAB_00455294;
      iVar17 = *piVar8;
      local_2988._0_4_ = local_2988._0_4_ + 1;
      piVar8 = piVar8 + 1;
    } while( true );
  }
LAB_0045152c:
  if (local_26d0 != 0) {
    iVar17 = 0x10;
    uVar18 = *(undefined4 *)puVar4;
    local_2930 = 8.900295434028806e-307;
    local_2928 = 8.900295434028806e-307;
    pdVar33 = (double *)(results + 0x2f8);
    piVar8 = (int *)(lengths + 4);
    if (mr != 0) goto LAB_00451724;
LAB_004515a0:
    pcVar20 = "Doing %s for %ds on %d size blocks: ";
    do {
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20,names._76_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_Camellia_cbc_encrypt_006a7a48)
                  (local_2980._0_4_,local_2980._0_4_,iVar17,auStack_1d98,local_2958._0_4_,1);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._76_4_,dVar36);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      if (pdVar23 == (double *)(results + 800)) break;
      piVar12 = piVar8 + 1;
      iVar17 = *piVar8;
      uVar18 = *(undefined4 *)puVar4;
      pdVar33 = pdVar23;
      piVar8 = piVar12;
      if (mr == 0) goto LAB_004515a0;
LAB_00451724:
      pcVar20 = "+DT:%s:%d:%d\n";
    } while( true );
  }
  if (local_26cc != 0) {
    iVar17 = 0x10;
    uVar18 = *(undefined4 *)puVar4;
    local_2930 = 8.900295434028806e-307;
    local_2928 = 8.900295434028806e-307;
    pdVar33 = (double *)(results + 800);
    piVar8 = (int *)(lengths + 4);
    if (mr != 0) goto LAB_00451928;
LAB_004517a4:
    pcVar20 = "Doing %s for %ds on %d size blocks: ";
    do {
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20,names._80_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_Camellia_cbc_encrypt_006a7a48)
                  (local_2980._0_4_,local_2980._0_4_,iVar17,auStack_1c80,local_2958._0_4_,1);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._80_4_,dVar36);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      if (pdVar23 == (double *)(results + 0x348)) break;
      piVar12 = piVar8 + 1;
      iVar17 = *piVar8;
      uVar18 = *(undefined4 *)puVar4;
      pdVar33 = pdVar23;
      piVar8 = piVar12;
      if (mr == 0) goto LAB_004517a4;
LAB_00451928:
      pcVar20 = "+DT:%s:%d:%d\n";
    } while( true );
  }
  if (local_26c8 != 0) {
    iVar17 = 0x10;
    uVar18 = *(undefined4 *)puVar4;
    local_2930 = 8.900295434028806e-307;
    local_2928 = 8.900295434028806e-307;
    pdVar33 = (double *)(results + 0x348);
    piVar8 = (int *)(lengths + 4);
    if (mr != 0) goto LAB_00451b2c;
LAB_004519a8:
    pcVar20 = "Doing %s for %ds on %d size blocks: ";
    do {
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20,names._84_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_Camellia_cbc_encrypt_006a7a48)
                  (local_2980._0_4_,local_2980._0_4_,iVar17,auStack_1b68,local_2958._0_4_,1);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._84_4_,dVar36);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      if (pdVar23 == (double *)(results + 0x370)) break;
      piVar12 = piVar8 + 1;
      iVar17 = *piVar8;
      uVar18 = *(undefined4 *)puVar4;
      pdVar33 = pdVar23;
      piVar8 = piVar12;
      if (mr == 0) goto LAB_004519a8;
LAB_00451b2c:
      pcVar20 = "+DT:%s:%d:%d\n";
    } while( true );
  }
  if (local_26f4 != 0) {
    puVar30 = lengths;
    local_2930 = 8.900295434028806e-307;
    local_2928 = 8.900295434028806e-307;
    pdVar33 = (double *)(results + 400);
    do {
      iVar17 = *(int *)puVar30;
      if (mr == 0) {
        pcVar20 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar20 = "+DT:%s:%d:%d\n";
      }
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,names._40_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_idea_cbc_encrypt_006a7a4c)
                  (local_2980._0_4_,local_2980._0_4_,iVar17,auStack_2350,local_2958._0_4_,1);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._40_4_,dVar36);
      puVar30 = (undefined1 *)((int)puVar30 + 4);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      pdVar33 = pdVar23;
    } while (pdVar23 != (double *)(results + 0x1b8));
  }
  if (local_26f0 != 0) {
    iVar17 = 0x10;
    uVar18 = *(undefined4 *)puVar4;
    local_2930 = 8.900295434028806e-307;
    local_2928 = 8.900295434028806e-307;
    pdVar33 = (double *)(results + 0x1b8);
    piVar8 = (int *)(lengths + 4);
    if (mr != 0) goto LAB_00451efc;
LAB_00451d8c:
    pcVar20 = "Doing %s for %ds on %d size blocks: ";
    do {
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20,names._44_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_SEED_cbc_encrypt_006a7a50)
                  (local_2980._0_4_,local_2980._0_4_,iVar17,aiStack_26a4,local_2958._0_4_,1);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._44_4_,dVar36);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      if (pdVar23 == (double *)(results + 0x1e0)) break;
      piVar12 = piVar8 + 1;
      iVar17 = *piVar8;
      uVar18 = *(undefined4 *)puVar4;
      pdVar33 = pdVar23;
      piVar8 = piVar12;
      if (mr == 0) goto LAB_00451d8c;
LAB_00451efc:
      pcVar20 = "+DT:%s:%d:%d\n";
    } while( true );
  }
  if (local_26ec != 0) {
    puVar30 = lengths;
    local_2930 = 8.900295434028806e-307;
    local_2928 = 8.900295434028806e-307;
    pdVar33 = (double *)(results + 0x1e0);
    do {
      iVar17 = *(int *)puVar30;
      if (mr == 0) {
        pcVar20 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar20 = "+DT:%s:%d:%d\n";
      }
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,names._48_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_RC2_cbc_encrypt_006a7a54)
                  (local_2980._0_4_,local_2980._0_4_,iVar17,auStack_1f9c,local_2958._0_4_,1);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._48_4_,dVar36);
      puVar30 = (undefined1 *)((int)puVar30 + 4);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      pdVar33 = pdVar23;
    } while (pdVar23 != (double *)(results + 0x208));
  }
  if (local_26e4 != 0) {
    puVar30 = lengths;
    local_2930 = 8.900295434028806e-307;
    local_2928 = 8.900295434028806e-307;
    pdVar33 = (double *)(results + 0x230);
    do {
      iVar17 = *(int *)puVar30;
      if (mr == 0) {
        pcVar20 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar20 = "+DT:%s:%d:%d\n";
      }
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,names._56_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_BF_cbc_encrypt_006a7a58)
                  (local_2980._0_4_,local_2980._0_4_,iVar17,&local_17f4,local_2958._0_4_,1);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._56_4_,dVar36);
      puVar30 = (undefined1 *)((int)puVar30 + 4);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      pdVar33 = pdVar23;
    } while (pdVar23 != (double *)(results + 600));
  }
  if (local_26e0 != 0) {
    puVar30 = lengths;
    local_2930 = 8.900295434028806e-307;
    local_2928 = 8.900295434028806e-307;
    pdVar33 = (double *)(results + 600);
    do {
      iVar17 = *(int *)puVar30;
      if (mr == 0) {
        pcVar20 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar20 = "+DT:%s:%d:%d\n";
      }
      iVar34 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,names._60_4_,3,iVar17);
      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
      (*(code *)PTR_alarm_006a9ac0)(3);
      app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
      run = 1;
      do {
        (*(code *)PTR_CAST_cbc_encrypt_006a7a5c)
                  (local_2980._0_4_,local_2980._0_4_,iVar17,auStack_24a4,local_2958._0_4_,1);
        iVar34 = iVar34 + 1;
        if (run == 0) break;
      } while (iVar34 != 0x7fffffff);
      dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._60_4_,dVar36);
      puVar30 = (undefined1 *)((int)puVar30 + 4);
      pdVar23 = pdVar33 + 1;
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      pdVar33 = pdVar23;
    } while (pdVar23 != (double *)(results + 0x280));
  }
  if (local_26c4 != 0) {
    iVar17 = 0x10;
    local_2928 = 8.900295434028806e-307;
    local_2930 = 8.900295434028806e-307;
    pdVar33 = (double *)(results + 0x370);
    piVar8 = (int *)(lengths + 4);
    do {
      if ((int **)local_294c != (int **)0x0) {
        names._88_4_ = (*(code *)PTR_OBJ_nid2ln_006a711c)(*(int **)local_294c);
        if (mr == 0) {
          pcVar20 = "Doing %s for %ds on %d size blocks: ";
        }
        else {
          pcVar20 = "+DT:%s:%d:%d\n";
        }
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,names._88_4_,3,iVar17);
        (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
        (*(code *)PTR_alarm_006a9ac0)(3);
        (*(code *)PTR_EVP_CIPHER_CTX_init_006a7a64)(auStack_2420);
        if (local_2914 == 0) {
          iVar34 = 0;
          (*(code *)PTR_EVP_EncryptInit_ex_006a7a98)
                    (auStack_2420,local_294c,0,key16_17807,local_2958._0_4_);
          (*(code *)PTR_EVP_CIPHER_CTX_set_padding_006a7564)(auStack_2420,0);
          app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
          run = 1;
          do {
            (*(code *)PTR_EVP_EncryptUpdate_006a7aa0)
                      (auStack_2420,local_2980._0_4_,unaff_s8,local_2980._0_4_,iVar17);
            iVar34 = iVar34 + 1;
            pcVar32 = (code *)PTR_EVP_EncryptFinal_ex_006a7a9c;
            if (run == 0) break;
            pcVar32 = (code *)PTR_EVP_EncryptFinal_ex_006a7a9c;
          } while (iVar34 != 0x7fffffff);
        }
        else {
          iVar34 = 0;
          (*(code *)PTR_EVP_DecryptInit_ex_006a7a68)
                    (auStack_2420,local_294c,0,key16_17807,local_2958._0_4_);
          (*(code *)PTR_EVP_CIPHER_CTX_set_padding_006a7564)(auStack_2420,0);
          app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
          run = 1;
          do {
            (*(code *)PTR_EVP_DecryptUpdate_006a7a70)
                      (auStack_2420,local_2980._0_4_,unaff_s8,local_2980._0_4_,iVar17);
            iVar34 = iVar34 + 1;
            pcVar32 = (code *)PTR_EVP_DecryptFinal_ex_006a7a6c;
            if (run == 0) break;
          } while (iVar34 != 0x7fffffff);
        }
        (*pcVar32)(auStack_2420,local_2980._0_4_,unaff_s8);
        dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
        (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_2420);
      }
      if (local_2938._0_4_ != (undefined4 *)0x0) {
        names._88_4_ = (*(code *)PTR_OBJ_nid2ln_006a711c)(*local_2938._0_4_);
        if (mr == 0) {
          pcVar20 = "Doing %s for %ds on %d size blocks: ";
        }
        else {
          pcVar20 = "+DT:%s:%d:%d\n";
        }
        iVar34 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,names._88_4_,3,iVar17);
        (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
        (*(code *)PTR_alarm_006a9ac0)(3);
        app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
        run = 1;
        do {
          (*(code *)PTR_EVP_Digest_006a7a14)
                    (local_2980._0_4_,iVar17,auStack_6fc,0,local_2938._0_4_,0);
          iVar34 = iVar34 + 1;
          if (run == 0) break;
        } while (iVar34 != 0x7fffffff);
        dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
      }
      if (mr == 0) {
        pcVar20 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar20 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,names._88_4_,dVar36);
      *pdVar33 = ((double)iVar34 / dVar36) * (double)iVar17;
      if (pdVar33 + 1 == (double *)(results + 0x398)) break;
      iVar17 = *piVar8;
      pdVar33 = pdVar33 + 1;
      piVar8 = piVar8 + 1;
    } while( true );
  }
  iVar17 = 0;
  (*(code *)PTR_RAND_pseudo_bytes_006a7a60)(local_2980._0_4_,0x24);
  do {
    iVar34 = iVar17;
    if (local_288c[iVar17] != (int *)0x0) {
      piVar8 = local_289c[iVar17];
      iVar9 = (*(code *)PTR_RSA_sign_006a7a78)
                        (0x72,local_2980._0_4_,0x24,local_2950,&local_28bc,piVar8);
      if (iVar9 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar4,"RSA sign failure.  No RSA sign will be done.\n");
        iVar9 = 1;
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
      }
      else {
        uVar18 = *(undefined4 *)(rsa_bits_17830 + iVar17 * 4);
        if (mr == 0) {
          pcVar20 = "Doing %d bit %s %s\'s for %ds: ";
        }
        else {
          pcVar20 = "+DTP:%d:%s:%s:%d\n";
        }
        iVar9 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,uVar18,"private","rsa",10);
        (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
        (*(code *)PTR_alarm_006a9ac0)(10);
        app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
        run = 1;
        while (iVar10 = (*(code *)PTR_RSA_sign_006a7a78)
                                  (0x72,local_2980._0_4_,0x24,local_2950,&local_28bc,piVar8),
              iVar10 != 0) {
          iVar9 = iVar9 + 1;
          if ((run == 0) || (iVar9 == 0x7fffffff)) goto LAB_00452c3c;
        }
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,"RSA sign failure\n");
        iVar9 = 1;
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
LAB_00452c3c:
        dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
        if (mr == 0) {
          pcVar20 = "%ld %d bit private RSA\'s in %.2fs\n";
        }
        else {
          pcVar20 = "+R1:%ld:%d:%.2f\n";
        }
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar9,uVar18,dVar36);
        *(double *)(rsa_results + iVar17 * 0x10) = dVar36 / (double)iVar9;
      }
      iVar10 = (*(code *)PTR_RSA_verify_006a7a7c)(0x72,local_2980._0_4_,0x24,local_2950);
      if (iVar10 < 1) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar4,"RSA verify failure.  No RSA verify will be done.\n");
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
        local_288c[iVar17] = (int *)0x0;
      }
      else {
        uVar18 = *(undefined4 *)(rsa_bits_17830 + iVar17 * 4);
        if (mr == 0) {
          pcVar20 = "Doing %d bit %s %s\'s for %ds: ";
        }
        else {
          pcVar20 = "+DTP:%d:%s:%s:%d\n";
        }
        iVar10 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,uVar18,"public","rsa",10);
        (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
        (*(code *)PTR_alarm_006a9ac0)(10);
        app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
        run = 1;
        while (iVar11 = (*(code *)PTR_RSA_verify_006a7a7c)
                                  (0x72,local_2980._0_4_,0x24,local_2950,local_28bc,piVar8),
              0 < iVar11) {
          iVar10 = iVar10 + 1;
          if ((run == 0) || (iVar10 == 0x7fffffff)) goto LAB_00452a48;
        }
        iVar10 = 1;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,"RSA verify failure\n");
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
LAB_00452a48:
        dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
        if (mr == 0) {
          pcVar20 = "%ld %d bit public RSA\'s in %.2fs\n";
        }
        else {
          pcVar20 = "+R2:%ld:%d:%.2f\n";
        }
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar10,uVar18);
        *(double *)(rsa_results + iVar17 * 0x10 + 8) = dVar36 / (double)iVar10;
      }
      if (1 < iVar9) goto LAB_0045285c;
      if (iVar17 + 1 != 4) {
        iVar9 = iVar17 + 2;
        local_288c[iVar17 + 1] = (int *)0x0;
        iVar34 = iVar9;
        if (iVar9 < 4) {
          iVar34 = iVar17 + 3;
          local_288c[iVar9] = (int *)0x0;
          if (iVar17 == 0) {
            local_2880 = 0;
            iVar34 = 4;
          }
        }
        goto LAB_0045285c;
      }
      break;
    }
LAB_0045285c:
    iVar17 = iVar34 + 1;
  } while (iVar17 < 4);
  (*(code *)PTR_RAND_pseudo_bytes_006a7a60)(local_2980._0_4_,0x14);
  iVar17 = (*(code *)PTR_RAND_status_006a773c)();
  if (iVar17 != 1) {
    (*(code *)PTR_RAND_seed_006a7a80)
              ("string to make the random number generator think it has entropy",0x40);
    rnd_fake = 1;
  }
  local_2958 = 0x6b000000000000;
  iVar17 = 0;
  local_2980 = 0x6b000000000000;
  do {
    if (local_28b4[iVar17 + 3] == 0) {
LAB_00452d30:
      iVar17 = iVar17 + 1;
    }
    else {
      iVar9 = local_28b4[iVar17];
      iVar34 = (*(code *)PTR_DSA_sign_006a7a90)
                         (0x74,local_2980._0_4_,0x14,local_2950,unaff_s8,iVar9);
      if (iVar34 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar4,"DSA sign failure.  No DSA sign will be done.\n");
        iVar34 = 1;
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
      }
      else {
        uVar18 = *(undefined4 *)(dsa_bits_17835 + iVar17 * 4);
        if (mr == 0) {
          pcVar20 = "Doing %d bit %s %s\'s for %ds: ";
        }
        else {
          pcVar20 = "+DTP:%d:%s:%s:%d\n";
        }
        iVar34 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar4,pcVar20,uVar18,"sign",&DAT_00631ad0,10);
        (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
        (*(code *)PTR_alarm_006a9ac0)(10);
        app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
        run = 1;
        while (iVar10 = (*(code *)PTR_DSA_sign_006a7a90)
                                  (0x74,local_2980._0_4_,0x14,local_2950,unaff_s8,iVar9),
              iVar10 != 0) {
          iVar34 = iVar34 + 1;
          if ((run == 0) || (iVar34 == 0x7fffffff)) goto LAB_0045342c;
        }
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,"DSA sign failure\n");
        iVar34 = 1;
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
LAB_0045342c:
        dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
        if (mr == 0) {
          pcVar20 = "%ld %d bit DSA signs in %.2fs\n";
        }
        else {
          pcVar20 = "+R3:%ld:%d:%.2f\n";
        }
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar34,uVar18,dVar36);
        *(double *)(dsa_results + iVar17 * 0x10) = dVar36 / (double)iVar34;
      }
      iVar10 = (*(code *)PTR_DSA_verify_006a7a94)(0x74,local_2980._0_4_,0x14,local_2950);
      if (iVar10 < 1) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar4,"DSA verify failure.  No DSA verify will be done.\n");
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
        local_28b4[iVar17 + 3] = 0;
      }
      else {
        uVar18 = *(undefined4 *)(dsa_bits_17835 + iVar17 * 4);
        if (mr == 0) {
          pcVar20 = "Doing %d bit %s %s\'s for %ds: ";
        }
        else {
          pcVar20 = "+DTP:%d:%s:%s:%d\n";
        }
        iVar10 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar4,pcVar20,uVar18,"verify",&DAT_00631ad0,10);
        (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
        (*(code *)PTR_alarm_006a9ac0)(10);
        app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
        run = 1;
        while (iVar11 = (*(code *)PTR_DSA_verify_006a7a94)
                                  (0x74,local_2980._0_4_,0x14,local_2950,local_28b8,iVar9),
              0 < iVar11) {
          iVar10 = iVar10 + 1;
          if ((run == 0) || (iVar10 == 0x7fffffff)) goto LAB_00453254;
        }
        iVar10 = 1;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,"DSA verify failure\n");
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
LAB_00453254:
        dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
        if (mr == 0) {
          pcVar20 = "%ld %d bit DSA verify in %.2fs\n";
        }
        else {
          pcVar20 = "+R4:%ld:%d:%.2f\n";
        }
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar10,uVar18);
        *(double *)(dsa_results + iVar17 * 0x10 + 8) = dVar36 / (double)iVar10;
      }
      if (1 < iVar34) goto LAB_00452d30;
      if (iVar17 == 2) {
        iVar17 = 4;
      }
      else {
        local_28b4[iVar17 + 4] = 0;
        if (iVar17 == 0) {
          local_28b4[5] = 0;
          iVar17 = 4;
        }
        else {
          iVar17 = iVar17 + 3;
        }
      }
    }
  } while (iVar17 < 3);
  if (rnd_fake != 0) {
    (*(code *)PTR_RAND_cleanup_006a7434)();
  }
  iVar17 = (*(code *)PTR_RAND_status_006a773c)();
  if (iVar17 != 1) {
    (*(code *)PTR_RAND_seed_006a7a80)
              ("string to make the random number generator think it has entropy",0x40);
    rnd_fake = 1;
  }
  iVar17 = 0;
  do {
    iVar9 = iVar17 * 4;
    iVar34 = iVar17;
    if (local_279c[iVar17] != 0) {
      piVar8 = (int *)(*(code *)PTR_EC_KEY_new_by_curve_name_006a78c4)
                                (*(undefined4 *)(test_curves_17836 + iVar9));
      local_285c[iVar17] = piVar8;
      if (piVar8 == (int *)0x0) {
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,"ECDSA failure.\n");
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
        goto LAB_00452dc4;
      }
      (*(code *)PTR_EC_KEY_precompute_mult_006a7a84)(piVar8,0);
      (*(code *)PTR_EC_KEY_generate_key_006a71d0)(piVar8);
      iVar10 = (*(code *)PTR_ECDSA_sign_006a7a88)
                         (0,local_2980._0_4_,0x14,auStack_63c,unaff_s8,piVar8);
      if (iVar10 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar4,"ECDSA sign failure.  No ECDSA sign will be done.\n");
        iVar10 = 1;
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
      }
      else {
        uVar18 = *(undefined4 *)(test_curves_bits_17838 + iVar9);
        if (mr == 0) {
          pcVar20 = "Doing %d bit %s %s\'s for %ds: ";
        }
        else {
          pcVar20 = "+DTP:%d:%s:%s:%d\n";
        }
        iVar10 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,uVar18,"sign","ecdsa",10);
        (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
        (*(code *)PTR_alarm_006a9ac0)(10);
        app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
        run = 1;
        while (iVar11 = (*(code *)PTR_ECDSA_sign_006a7a88)
                                  (0,local_2980._0_4_,0x14,auStack_63c,unaff_s8,piVar8), iVar11 != 0
              ) {
          iVar10 = iVar10 + 1;
          if ((run == 0) || (iVar10 == 0x7fffffff)) goto LAB_004535d0;
        }
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,"ECDSA sign failure\n");
        iVar10 = 1;
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
LAB_004535d0:
        dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
        if (mr == 0) {
          pcVar20 = "%ld %d bit ECDSA signs in %.2fs \n";
        }
        else {
          pcVar20 = "+R5:%ld:%d:%.2f\n";
        }
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar10,uVar18,dVar36);
        *(double *)(ecdsa_results + iVar17 * 0x10) = dVar36 / (double)iVar10;
      }
      iVar11 = (*(code *)PTR_ECDSA_verify_006a7a8c)(0,local_2980._0_4_,0x14,auStack_63c);
      if (iVar11 == 1) {
        uVar18 = *(undefined4 *)(test_curves_bits_17838 + iVar9);
        if (mr == 0) {
          pcVar20 = "Doing %d bit %s %s\'s for %ds: ";
        }
        else {
          pcVar20 = "+DTP:%d:%s:%s:%d\n";
        }
        iVar9 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,uVar18,"verify","ecdsa",10)
        ;
        (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
        (*(code *)PTR_alarm_006a9ac0)(10);
        app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
        run = 1;
        while (iVar11 = (*(code *)PTR_ECDSA_verify_006a7a8c)
                                  (0,local_2980._0_4_,0x14,auStack_63c,local_28b8,piVar8),
              iVar11 == 1) {
          iVar9 = iVar9 + 1;
          if ((run == 0) || (iVar9 == 0x7fffffff)) goto LAB_00453fc8;
        }
        iVar9 = 1;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,"ECDSA verify failure\n");
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
LAB_00453fc8:
        dVar36 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
        if (mr == 0) {
          pcVar20 = "%ld %d bit ECDSA verify in %.2fs\n";
        }
        else {
          pcVar20 = "+R6:%ld:%d:%.2f\n";
        }
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar9,uVar18);
        *(double *)(ecdsa_results + iVar17 * 0x10 + 8) = dVar36 / (double)iVar9;
      }
      else {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar4,"ECDSA verify failure.  No ECDSA verify will be done.\n");
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
        local_279c[iVar17] = 0;
      }
      if (1 < iVar10) goto LAB_00452dc4;
      if (iVar17 + 1 != 0x10) {
        iVar34 = iVar17 + 2;
        local_279c[iVar17 + 1] = 0;
        if (iVar34 < 0x10) {
          iVar9 = iVar17 + 3;
          local_279c[iVar34] = 0;
          iVar34 = iVar9;
          if (iVar9 < 0x10) {
            iVar34 = iVar17 + 4;
            local_279c[iVar9] = 0;
            if (iVar34 < 0x10) {
              iVar9 = iVar17 + 5;
              local_279c[iVar34] = 0;
              iVar34 = iVar9;
              if (iVar9 < 0x10) {
                iVar34 = iVar17 + 6;
                local_279c[iVar9] = 0;
                if (iVar34 < 0x10) {
                  iVar9 = iVar17 + 7;
                  local_279c[iVar34] = 0;
                  iVar34 = iVar9;
                  if (iVar9 < 0x10) {
                    iVar34 = iVar17 + 8;
                    local_279c[iVar9] = 0;
                    if (iVar34 < 0x10) {
                      iVar9 = iVar17 + 9;
                      local_279c[iVar34] = 0;
                      iVar34 = iVar9;
                      if (iVar9 < 0x10) {
                        iVar34 = iVar17 + 10;
                        local_279c[iVar9] = 0;
                        if (iVar34 < 0x10) {
                          iVar9 = iVar17 + 0xb;
                          local_279c[iVar34] = 0;
                          iVar34 = iVar9;
                          if (iVar9 < 0x10) {
                            iVar34 = iVar17 + 0xc;
                            local_279c[iVar9] = 0;
                            if (iVar34 < 0x10) {
                              iVar9 = iVar17 + 0xd;
                              local_279c[iVar34] = 0;
                              iVar34 = iVar9;
                              if (iVar9 < 0x10) {
                                iVar34 = iVar17 + 0xe;
                                local_279c[iVar9] = 0;
                                if (iVar34 < 0x10) {
                                  local_279c[iVar34] = 0;
                                  iVar34 = iVar17 + 0xf;
                                  if (iVar17 == 0) {
                                    local_279c[15] = 0;
                                    iVar34 = 0x10;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        goto LAB_00452dc4;
      }
      break;
    }
LAB_00452dc4:
    iVar17 = iVar34 + 1;
  } while (iVar17 < 0x10);
  if (rnd_fake != 0) {
    (*(code *)PTR_RAND_cleanup_006a7434)();
  }
  iVar17 = (*(code *)PTR_RAND_status_006a773c)();
  if (iVar17 != 1) {
    (*(code *)PTR_RAND_seed_006a7a80)
              ("string to make the random number generator think it has entropy",0x40);
    rnd_fake = 1;
  }
  iVar17 = 0;
  dVar36 = DAT_0063f538;
  dVar38 = DAT_0063f538;
  do {
    iVar34 = iVar17;
    if (local_279c[iVar17 + 0x10] != 0) {
      uVar18 = *(undefined4 *)(test_curves_17836 + iVar17 * 4);
      piVar8 = (int *)(*(code *)PTR_EC_KEY_new_by_curve_name_006a78c4)(uVar18);
      local_281c[iVar17] = piVar8;
      piVar12 = (int *)(*(code *)PTR_EC_KEY_new_by_curve_name_006a78c4)(uVar18);
      local_27dc[iVar17] = piVar12;
      if ((piVar8 == (int *)0x0) || (piVar12 == (int *)0x0)) {
        pcVar20 = "ECDH failure.\n";
        uVar18 = *(undefined4 *)puVar4;
      }
      else {
        iVar9 = (*(code *)PTR_EC_KEY_generate_key_006a71d0)(piVar8);
        if ((iVar9 != 0) &&
           (iVar9 = (*(code *)PTR_EC_KEY_generate_key_006a71d0)(piVar12), iVar9 != 0)) {
          uVar18 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(piVar8);
          iVar9 = (*(code *)PTR_EC_GROUP_get_degree_006a7ae0)(uVar18);
          if (iVar9 < 0xc1) {
            iVar9 = 0x14;
            pcVar32 = KDF1_SHA1;
          }
          else {
            pcVar32 = (code *)0x0;
            iVar9 = iVar9 + 7 >> 3;
          }
          pcVar21 = acStack_53d + 1;
          pcVar20 = local_43c;
          uVar18 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(piVar12);
          iVar10 = (*(code *)PTR_ECDH_compute_key_006a7ae8)(pcVar21,iVar9,uVar18,piVar8,pcVar32);
          uVar18 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(piVar8);
          iVar11 = (*(code *)PTR_ECDH_compute_key_006a7ae8)(pcVar20,iVar9,uVar18,piVar12,pcVar32);
          if (iVar10 < 1) {
            bVar2 = iVar10 == iVar11;
LAB_004553a4:
            if (!bVar2) goto LAB_00456808;
          }
          else {
            if (iVar10 == iVar11) {
              pcVar14 = pcVar21;
              do {
                cVar16 = *pcVar14;
                cVar1 = *pcVar20;
                if (pcVar14 == pcVar21 + iVar10 + -1) {
                  bVar2 = cVar16 == cVar1;
                  goto LAB_004553a4;
                }
                pcVar14 = pcVar14 + 1;
                pcVar20 = pcVar20 + 1;
              } while (cVar16 == cVar1);
            }
LAB_00456808:
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar4,"ECDH computations don\'t match.\n");
            (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
          }
          uVar18 = *(undefined4 *)(test_curves_bits_17838 + iVar17 * 4);
          if (mr == 0) {
            pcVar20 = "Doing %d bit %s %s\'s for %ds: ";
          }
          else {
            pcVar20 = "+DTP:%d:%s:%s:%d\n";
          }
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar4,pcVar20,uVar18,"",&DAT_0063e880,10);
          (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar4,0xb,0,0);
          (*(code *)PTR_alarm_006a9ac0)(10);
          app_tminterval(0,*(undefined4 *)(local_2990 + -0x4754));
          run = 1;
          iVar10 = 0;
          do {
            iVar10 = iVar10 + 1;
            uVar29 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(piVar12);
            (*(code *)PTR_ECDH_compute_key_006a7ae8)(pcVar21,iVar9,uVar29,piVar8,pcVar32);
            if (run == 0) {
              dVar37 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
              if (mr == 0) {
                pcVar20 = "%ld %d-bit ECDH ops in %.2fs\n";
              }
              else {
                pcVar20 = "+R7:%ld:%d:%.2f\n";
              }
              (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,pcVar20,iVar10,uVar18);
              *(double *)(ecdh_results + iVar17 * 8) = dVar37 / (double)iVar10;
              if (iVar10 == 1) goto LAB_0045378c;
              goto LAB_004536c4;
            }
          } while (iVar10 != 0x7fffffff);
          local_2938 = (double)app_tminterval(1,*(undefined4 *)(local_2990 + -0x4754));
          if (mr == 0) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar4,"%ld %d-bit ECDH ops in %.2fs\n",0x7fffffff,uVar18);
            *(double *)(ecdh_results + iVar17 * 8) = local_2938 / dVar36;
          }
          else {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar4,"+R7:%ld:%d:%.2f\n",0x7fffffff,uVar18);
            *(double *)(ecdh_results + iVar17 * 8) = local_2938 / dVar38;
          }
          goto LAB_004536c4;
        }
        pcVar20 = "ECDH key generation failure.\n";
        uVar18 = *(undefined4 *)puVar4;
      }
      (*(code *)PTR_BIO_printf_006a6e38)(uVar18,pcVar20);
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
LAB_0045378c:
      if (iVar17 != 0xf) {
        iVar34 = iVar17 + 2;
        local_279c[iVar17 + 0x11] = 0;
        if (iVar34 < 0x10) {
          iVar34 = iVar17 + 3;
          local_279c[iVar17 + 0x12] = 0;
          if (iVar34 < 0x10) {
            iVar34 = iVar17 + 4;
            local_279c[iVar17 + 0x13] = 0;
            if (iVar34 < 0x10) {
              iVar34 = iVar17 + 5;
              local_279c[iVar17 + 0x14] = 0;
              if (iVar34 < 0x10) {
                iVar34 = iVar17 + 6;
                local_279c[iVar17 + 0x15] = 0;
                if (iVar34 < 0x10) {
                  iVar34 = iVar17 + 7;
                  local_279c[iVar17 + 0x16] = 0;
                  if (iVar34 < 0x10) {
                    iVar34 = iVar17 + 8;
                    local_279c[iVar17 + 0x17] = 0;
                    if (iVar34 < 0x10) {
                      iVar34 = iVar17 + 9;
                      local_279c[iVar17 + 0x18] = 0;
                      if (iVar34 < 0x10) {
                        iVar34 = iVar17 + 10;
                        local_279c[iVar17 + 0x19] = 0;
                        if (iVar34 < 0x10) {
                          iVar34 = iVar17 + 0xb;
                          local_279c[iVar17 + 0x1a] = 0;
                          if (iVar34 < 0x10) {
                            iVar34 = iVar17 + 0xc;
                            local_279c[iVar17 + 0x1b] = 0;
                            if (iVar34 < 0x10) {
                              iVar34 = iVar17 + 0xd;
                              local_279c[iVar17 + 0x1c] = 0;
                              if (iVar34 < 0x10) {
                                iVar34 = iVar17 + 0xe;
                                local_279c[iVar17 + 0x1d] = 0;
                                if (iVar34 < 0x10) {
                                  iVar34 = iVar17 + 0xf;
                                  local_279c[iVar17 + 0x1e] = 0;
                                  if (iVar17 == 0) {
                                    local_279c[31] = 0;
                                    iVar34 = 0x10;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        goto LAB_004536c4;
      }
      break;
    }
LAB_004536c4:
    iVar17 = iVar34 + 1;
  } while (iVar17 < 0x10);
  if (rnd_fake != 0) {
    (*(code *)PTR_RAND_cleanup_006a7434)();
  }
  if (mr == 0) {
    local_2980 = ZEXT48(PTR_stdout_006a99c8) << 0x20;
    puVar31 = (undefined4 *)PTR_stdout_006a99c8;
    goto LAB_00454c34;
  }
  uVar26 = (uint)local_2980._0_4_;
  if (local_28e0 != 0) {
    local_2980 = ZEXT48(PTR_stdout_006a99c8) << 0x20;
    goto LAB_004545bc;
  }
  goto LAB_00453930;
LAB_004549b0:
  (*(code *)PTR_close_006a994c)(local_17f0);
  puVar5 = PTR___printf_chk_006a99c4;
  iVar34 = iVar17 + 1;
  *puVar24 = local_17f4;
  (*(code *)puVar5)(1,"Forked child %d\n",iVar17);
  iVar17 = iVar34;
  puVar24 = puVar24 + 1;
  if ((int)local_2988._0_4_ <= iVar34) goto LAB_00455538;
  goto LAB_004549f0;
LAB_00455538:
  local_2980 = ZEXT48(puVar31) << 0x20;
  local_2938 = 8.900295434028806e-307;
  iVar17 = 0;
  local_2930 = 1.18546024828827e-306;
  dVar36 = DAT_0063f520;
  dVar38 = DAT_0063f520;
  do {
    uVar18 = (*(code *)PTR_fdopen_006a9b20)(*local_2958._0_4_,"r");
LAB_004555a4:
    iVar34 = (*(code *)PTR_fgets_006a9ae0)(local_43c,0x400,uVar18);
    if (iVar34 != 0) {
      while( true ) {
        puVar15 = (undefined *)(*(code *)PTR_strchr_006a9a28)(local_43c,10);
        if (puVar15 != (undefined *)0x0) {
          *puVar15 = 0;
        }
        if (local_43c[0] == '+') break;
        pcVar20 = "Don\'t understand line \'%s\' from child %d\n";
LAB_004555f8:
        (*(code *)PTR___fprintf_chk_006a9980)(*(undefined4 *)unaff_s7,1,pcVar20,local_43c,iVar17);
        iVar34 = (*(code *)PTR_fgets_006a9ae0)(local_43c,0x400,uVar18);
        if (iVar34 == 0) goto LAB_00455628;
      }
      (*(code *)PTR___printf_chk_006a99c4)(1,"Got: %s from %d\n",local_43c,iVar17);
      iVar34 = (*(code *)PTR_strncmp_006a9970)(local_43c,&DAT_0063ed00,3);
      if (iVar34 == 0) {
        uVar26 = (uint)local_43c[3];
        if (uVar26 == 0) {
          pcVar20 = local_43c + 3;
          pcVar21 = (char *)0x0;
        }
        else {
          (*(code *)PTR_memset_006a99f4)(acStack_53d + 1,0,0x100);
          puVar19 = &sep_19044;
          acStack_53d[1] = 1;
          cVar16 = sep_19044._0_1_;
          while (uVar3 = (uint)cVar16, uVar3 != 0) {
            puVar19 = (undefined2 *)((int)puVar19 + 1);
            cVar16 = *(char *)puVar19;
            acStack_53d[(uVar3 & 0xff) + 1] = '\x01';
          }
          pcVar21 = local_43c + 3;
          pcVar20 = pcVar21;
          if (acStack_53d[(uVar26 & 0xff) + 1] == '\0') {
            pcVar14 = local_438;
            do {
              pcVar20 = pcVar14;
              pcVar14 = pcVar20 + 1;
            } while (acStack_53d[((int)*pcVar20 & 0xffU) + 1] == '\0');
            if ((int)*pcVar20 != 0) goto LAB_0045582c;
          }
          else {
LAB_0045582c:
            *pcVar20 = '\0';
            pcVar20 = pcVar20 + 1;
          }
        }
        iVar34 = (*(code *)PTR_strtol_006a9958)(pcVar21,0,10);
        uVar26 = (uint)*pcVar20;
        if (uVar26 != 0) {
          (*(code *)PTR_memset_006a99f4)(acStack_53d + 1,0,0x100);
          puVar19 = &sep_19044;
          acStack_53d[1] = 1;
          cVar16 = sep_19044._0_1_;
          while (uVar3 = (uint)cVar16, uVar3 != 0) {
            puVar19 = (undefined2 *)((int)puVar19 + 1);
            cVar16 = *(char *)puVar19;
            acStack_53d[(uVar3 & 0xff) + 1] = '\x01';
          }
          pcVar21 = pcVar20;
          if (acStack_53d[(uVar26 & 0xff) + 1] == '\0') {
            do {
              pcVar20 = pcVar20 + 1;
              uVar26 = (uint)*pcVar20;
            } while (acStack_53d[(uVar26 & 0xff) + 1] == '\0');
            pcVar21 = pcVar20;
            if (uVar26 == 0) goto LAB_00455900;
          }
          uVar26 = (uint)pcVar21[1];
          pcVar20 = pcVar21 + 1;
          *pcVar21 = '\0';
        }
LAB_00455900:
        pdVar33 = (double *)(local_298c + iVar34 * 0x28);
        pcVar21 = pcVar20;
        if (uVar26 == 0) goto LAB_00455a10;
        do {
          (*(code *)PTR_memset_006a99f4)(acStack_53d + 1,0,0x100);
          acStack_53d[1] = 1;
          puVar19 = &sep_19044;
          cVar16 = sep_19044._0_1_;
          while (uVar3 = (uint)cVar16, uVar3 != 0) {
            puVar19 = (undefined2 *)((int)puVar19 + 1);
            cVar16 = *(char *)puVar19;
            acStack_53d[(uVar3 & 0xff) + 1] = '\x01';
          }
          pcVar21 = pcVar20;
          pdVar23 = pdVar33;
          if (acStack_53d[(uVar26 & 0xff) + 1] == '\0') {
            do {
              pcVar21 = pcVar21 + 1;
            } while (acStack_53d[((int)*pcVar21 & 0xffU) + 1] == '\0');
            if ((int)*pcVar21 != 0) goto LAB_004559d4;
          }
          else {
LAB_004559d4:
            *pcVar21 = '\0';
            pcVar21 = pcVar21 + 1;
          }
          while( true ) {
            pdVar33 = pdVar23 + 1;
            dVar37 = (double)(*(code *)PTR_strtod_006a99d8)(pcVar20,0);
            *pdVar23 = *pdVar23 + dVar37;
            if (pdVar33 == (double *)(local_298c + iVar34 * 0x28 + 0x28)) goto LAB_004555a4;
            uVar26 = (uint)*pcVar21;
            pcVar20 = pcVar21;
            if (uVar26 != 0) break;
LAB_00455a10:
            pcVar20 = (char *)0x0;
            pdVar23 = pdVar33;
          }
        } while( true );
      }
      iVar34 = (*(code *)PTR_strncmp_006a9970)(local_43c,&DAT_0063ed04,4);
      if (iVar34 == 0) {
        uVar26 = (uint)local_438[0];
        if (uVar26 == 0) {
          pcVar20 = local_438;
          pcVar21 = (char *)0x0;
        }
        else {
          (*(code *)PTR_memset_006a99f4)(acStack_53d + 1,0,0x100);
          puVar19 = &sep_19044;
          acStack_53d[1] = 1;
          cVar16 = sep_19044._0_1_;
          while (uVar3 = (uint)cVar16, uVar3 != 0) {
            puVar19 = (undefined2 *)((int)puVar19 + 1);
            cVar16 = *(char *)puVar19;
            acStack_53d[(uVar3 & 0xff) + 1] = '\x01';
          }
          pcVar21 = local_438;
          pcVar20 = pcVar21;
          if (acStack_53d[(uVar26 & 0xff) + 1] == '\0') {
            pcVar20 = local_438;
            do {
              pcVar20 = pcVar20 + 1;
            } while (acStack_53d[((int)*pcVar20 & 0xffU) + 1] == '\0');
            if ((int)*pcVar20 != 0) goto LAB_00455acc;
          }
          else {
LAB_00455acc:
            *pcVar20 = '\0';
            pcVar20 = pcVar20 + 1;
          }
        }
        iVar34 = (*(code *)PTR_strtol_006a9958)(pcVar21,0,10);
        cVar16 = *pcVar20;
        if ((int)cVar16 == 0) {
          pcVar21 = (char *)0x0;
        }
        else {
          (*(code *)PTR_memset_006a99f4)(acStack_53d + 1,0,0x100);
          puVar19 = &sep_19044;
          acStack_53d[1] = 1;
          cVar1 = sep_19044._0_1_;
          while (uVar26 = (uint)cVar1, uVar26 != 0) {
            puVar19 = (undefined2 *)((int)puVar19 + 1);
            cVar1 = *(char *)puVar19;
            acStack_53d[(uVar26 & 0xff) + 1] = '\x01';
          }
          if (acStack_53d[((int)cVar16 & 0xffU) + 1] == '\0') {
            do {
              pcVar20 = pcVar20 + 1;
            } while (acStack_53d[((int)*pcVar20 & 0xffU) + 1] == '\0');
            pcVar21 = (char *)0x0;
            if ((int)*pcVar20 == 0) goto LAB_00455c54;
          }
          cVar16 = pcVar20[1];
          pcVar21 = pcVar20 + 1;
          *pcVar20 = '\0';
          pcVar20 = pcVar21;
          if ((int)cVar16 == 0) {
            pcVar21 = (char *)0x0;
          }
          else {
            (*(code *)PTR_memset_006a99f4)(acStack_53d + 1,0,0x100);
            puVar19 = &sep_19044;
            acStack_53d[1] = 1;
            cVar1 = sep_19044._0_1_;
            while (uVar26 = (uint)cVar1, uVar26 != 0) {
              puVar19 = (undefined2 *)((int)puVar19 + 1);
              cVar1 = *(char *)puVar19;
              acStack_53d[(uVar26 & 0xff) + 1] = '\x01';
            }
            if (acStack_53d[((int)cVar16 & 0xffU) + 1] == '\0') {
              do {
                pcVar20 = pcVar20 + 1;
              } while (acStack_53d[((int)*pcVar20 & 0xffU) + 1] == '\0');
              if ((int)*pcVar20 == 0) goto LAB_00455c54;
            }
            *pcVar20 = '\0';
            pcVar20 = pcVar20 + 1;
          }
        }
LAB_00455c54:
        dVar37 = (double)(*(code *)PTR_strtod_006a99d8)(pcVar21,0);
        if (iVar17 == 0) {
          uVar26 = (uint)*pcVar20;
          iVar9 = iVar34 * 0x10;
          local_2930._0_4_ = rsa_results;
          *(double *)(rsa_results + iVar9) = dVar37;
          if (uVar26 == 0) goto LAB_00456c34;
LAB_00455ca4:
          local_2930._0_4_ = rsa_results;
          iVar9 = iVar34 * 0x10;
          (*(code *)PTR_memset_006a99f4)(acStack_53d + 1,0,0x100);
          puVar19 = &sep_19044;
          acStack_53d[1] = 1;
          cVar16 = sep_19044._0_1_;
          while (uVar3 = (uint)cVar16, uVar3 != 0) {
            puVar19 = (undefined2 *)((int)puVar19 + 1);
            cVar16 = *(char *)puVar19;
            acStack_53d[(uVar3 & 0xff) + 1] = '\x01';
          }
          pcVar21 = pcVar20;
          if (acStack_53d[(uVar26 & 0xff) + 1] == '\0') {
            do {
              pcVar21 = pcVar21 + 1;
            } while (acStack_53d[((int)*pcVar21 & 0xffU) + 1] == '\0');
            if ((int)*pcVar21 != 0) goto LAB_00455d40;
          }
          else {
LAB_00455d40:
            *pcVar21 = '\0';
          }
          dVar37 = (double)(*(code *)PTR_strtod_006a99d8)(pcVar20,0);
          if (iVar17 == 0) goto LAB_00456c44;
        }
        else {
          uVar26 = (uint)*pcVar20;
          *(double *)(rsa_results + iVar34 * 0x10) =
               DAT_0063f520 /
               (DAT_0063f520 / *(double *)(rsa_results + iVar34 * 0x10) + DAT_0063f520 / dVar37);
          if (uVar26 != 0) goto LAB_00455ca4;
          dVar37 = (double)(*(code *)PTR_strtod_006a99d8)(0,0);
        }
        *(double *)(rsa_results + iVar34 * 0x10 + 8) =
             DAT_0063f520 /
             (DAT_0063f520 / *(double *)(rsa_results + iVar34 * 0x10 + 8) + DAT_0063f520 / dVar37);
      }
      else {
        iVar34 = (*(code *)PTR_strncmp_006a9970)(local_43c,&DAT_0063ed0c,4);
        if (iVar34 == 0) {
          uVar26 = (uint)local_438[0];
          if (uVar26 == 0) {
            pcVar20 = local_438;
            pcVar21 = (char *)0x0;
          }
          else {
            (*(code *)PTR_memset_006a99f4)(acStack_53d + 1,0,0x100);
            puVar19 = &sep_19044;
            acStack_53d[1] = 1;
            cVar16 = sep_19044._0_1_;
            while (uVar3 = (uint)cVar16, uVar3 != 0) {
              puVar19 = (undefined2 *)((int)puVar19 + 1);
              cVar16 = *(char *)puVar19;
              acStack_53d[(uVar3 & 0xff) + 1] = '\x01';
            }
            pcVar21 = local_438;
            pcVar20 = pcVar21;
            if (acStack_53d[(uVar26 & 0xff) + 1] == '\0') {
              pcVar20 = local_438;
              do {
                pcVar20 = pcVar20 + 1;
              } while (acStack_53d[((int)*pcVar20 & 0xffU) + 1] == '\0');
              if ((int)*pcVar20 != 0) goto LAB_00455e24;
            }
            else {
LAB_00455e24:
              *pcVar20 = '\0';
              pcVar20 = pcVar20 + 1;
            }
          }
          iVar34 = (*(code *)PTR_strtol_006a9958)(pcVar21,0,10);
          cVar16 = *pcVar20;
          if ((int)cVar16 == 0) {
            pcVar21 = (char *)0x0;
          }
          else {
            (*(code *)PTR_memset_006a99f4)(acStack_53d + 1,0,0x100);
            puVar19 = &sep_19044;
            acStack_53d[1] = 1;
            cVar1 = sep_19044._0_1_;
            while (uVar26 = (uint)cVar1, uVar26 != 0) {
              puVar19 = (undefined2 *)((int)puVar19 + 1);
              cVar1 = *(char *)puVar19;
              acStack_53d[(uVar26 & 0xff) + 1] = '\x01';
            }
            if (acStack_53d[((int)cVar16 & 0xffU) + 1] == '\0') {
              do {
                pcVar20 = pcVar20 + 1;
              } while (acStack_53d[((int)*pcVar20 & 0xffU) + 1] == '\0');
              pcVar21 = (char *)0x0;
              if ((int)*pcVar20 == 0) goto LAB_00455fac;
            }
            cVar16 = pcVar20[1];
            pcVar21 = pcVar20 + 1;
            *pcVar20 = '\0';
            pcVar20 = pcVar21;
            if ((int)cVar16 == 0) {
              pcVar21 = (char *)0x0;
            }
            else {
              (*(code *)PTR_memset_006a99f4)(acStack_53d + 1,0,0x100);
              puVar19 = &sep_19044;
              acStack_53d[1] = 1;
              cVar1 = sep_19044._0_1_;
              while (uVar26 = (uint)cVar1, uVar26 != 0) {
                puVar19 = (undefined2 *)((int)puVar19 + 1);
                cVar1 = *(char *)puVar19;
                acStack_53d[(uVar26 & 0xff) + 1] = '\x01';
              }
              if (acStack_53d[((int)cVar16 & 0xffU) + 1] == '\0') {
                do {
                  pcVar20 = pcVar20 + 1;
                } while (acStack_53d[((int)*pcVar20 & 0xffU) + 1] == '\0');
                if ((int)*pcVar20 == 0) goto LAB_00455fac;
              }
              *pcVar20 = '\0';
              pcVar20 = pcVar20 + 1;
            }
          }
LAB_00455fac:
          dVar37 = (double)(*(code *)PTR_strtod_006a99d8)(pcVar21,0);
          local_2930._0_4_ = dsa_results;
          if (iVar17 == 0) {
            iVar9 = iVar34 * 0x10;
            uVar26 = (uint)*pcVar20;
            *(double *)(dsa_results + iVar9) = dVar37;
            if (uVar26 != 0) goto LAB_00455ffc;
LAB_00456c34:
            dVar37 = (double)(*(code *)PTR_strtod_006a99d8)(0,0);
          }
          else {
            uVar26 = (uint)*pcVar20;
            *(double *)(dsa_results + iVar34 * 0x10) =
                 DAT_0063f520 /
                 (DAT_0063f520 / *(double *)(dsa_results + iVar34 * 0x10) + DAT_0063f520 / dVar37);
            if (uVar26 == 0) {
              dVar37 = (double)(*(code *)PTR_strtod_006a99d8)(0,0);
LAB_004560b8:
              puVar30 = dsa_results + iVar34 * 0x10;
              goto LAB_004560bc;
            }
LAB_00455ffc:
            iVar9 = iVar34 * 0x10;
            (*(code *)PTR_memset_006a99f4)(acStack_53d + 1,0,0x100);
            puVar19 = &sep_19044;
            acStack_53d[1] = 1;
            cVar16 = sep_19044._0_1_;
            while (uVar3 = (uint)cVar16, uVar3 != 0) {
              puVar19 = (undefined2 *)((int)puVar19 + 1);
              cVar16 = *(char *)puVar19;
              acStack_53d[(uVar3 & 0xff) + 1] = '\x01';
            }
            pcVar21 = pcVar20;
            if (acStack_53d[(uVar26 & 0xff) + 1] == '\0') {
              do {
                pcVar21 = pcVar21 + 1;
              } while (acStack_53d[((int)*pcVar21 & 0xffU) + 1] == '\0');
              if ((int)*pcVar21 != 0) goto LAB_00456098;
            }
            else {
LAB_00456098:
              *pcVar21 = '\0';
            }
            dVar37 = (double)(*(code *)PTR_strtod_006a99d8)(pcVar20,0);
            if (iVar17 != 0) goto LAB_004560b8;
          }
LAB_00456c44:
          *(double *)(local_2930._0_4_ + iVar9 + 8) = dVar37;
        }
        else {
          iVar34 = (*(code *)PTR_strncmp_006a9970)(local_43c,&DAT_0063ed14,4);
          if (iVar34 == 0) {
            uVar26 = (uint)local_438[0];
            if (uVar26 == 0) {
              pcVar20 = local_438;
              pcVar21 = (char *)0x0;
            }
            else {
              (*(code *)PTR_memset_006a99f4)(acStack_53d + 1,0,0x100);
              puVar19 = &sep_19044;
              acStack_53d[1] = 1;
              cVar16 = sep_19044._0_1_;
              while (uVar3 = (uint)cVar16, uVar3 != 0) {
                puVar19 = (undefined2 *)((int)puVar19 + 1);
                cVar16 = *(char *)puVar19;
                acStack_53d[(uVar3 & 0xff) + 1] = '\x01';
              }
              pcVar21 = local_438;
              pcVar20 = pcVar21;
              if (acStack_53d[(uVar26 & 0xff) + 1] == '\0') {
                pcVar20 = local_438;
                do {
                  pcVar20 = pcVar20 + 1;
                } while (acStack_53d[((int)*pcVar20 & 0xffU) + 1] == '\0');
                if ((int)*pcVar20 != 0) goto LAB_00456184;
              }
              else {
LAB_00456184:
                *pcVar20 = '\0';
                pcVar20 = pcVar20 + 1;
              }
            }
            iVar34 = (*(code *)PTR_strtol_006a9958)(pcVar21,0,10);
            cVar16 = *pcVar20;
            if ((int)cVar16 == 0) {
              pcVar21 = (char *)0x0;
            }
            else {
              (*(code *)PTR_memset_006a99f4)(acStack_53d + 1,0,0x100);
              puVar19 = &sep_19044;
              acStack_53d[1] = 1;
              cVar1 = sep_19044._0_1_;
              while (uVar26 = (uint)cVar1, uVar26 != 0) {
                puVar19 = (undefined2 *)((int)puVar19 + 1);
                cVar1 = *(char *)puVar19;
                acStack_53d[(uVar26 & 0xff) + 1] = '\x01';
              }
              if (acStack_53d[((int)cVar16 & 0xffU) + 1] == '\0') {
                do {
                  pcVar20 = pcVar20 + 1;
                } while (acStack_53d[((int)*pcVar20 & 0xffU) + 1] == '\0');
                pcVar21 = (char *)0x0;
                if ((int)*pcVar20 == 0) goto LAB_0045630c;
              }
              cVar16 = pcVar20[1];
              pcVar21 = pcVar20 + 1;
              *pcVar20 = '\0';
              pcVar20 = pcVar21;
              if ((int)cVar16 == 0) {
                pcVar21 = (char *)0x0;
              }
              else {
                (*(code *)PTR_memset_006a99f4)(acStack_53d + 1,0,0x100);
                puVar19 = &sep_19044;
                acStack_53d[1] = 1;
                cVar1 = sep_19044._0_1_;
                while (uVar26 = (uint)cVar1, uVar26 != 0) {
                  puVar19 = (undefined2 *)((int)puVar19 + 1);
                  cVar1 = *(char *)puVar19;
                  acStack_53d[(uVar26 & 0xff) + 1] = '\x01';
                }
                if (acStack_53d[((int)cVar16 & 0xffU) + 1] == '\0') {
                  do {
                    pcVar20 = pcVar20 + 1;
                  } while (acStack_53d[((int)*pcVar20 & 0xffU) + 1] == '\0');
                  if ((int)*pcVar20 == 0) goto LAB_0045630c;
                }
                *pcVar20 = '\0';
                pcVar20 = pcVar20 + 1;
              }
            }
LAB_0045630c:
            dVar37 = (double)(*(code *)PTR_strtod_006a99d8)(pcVar21,0);
            if (iVar17 == 0) {
              uVar26 = (uint)*pcVar20;
              *(double *)(ecdsa_results + iVar34 * 0x10) = dVar37;
              if (uVar26 != 0) goto LAB_00456350;
              dVar37 = (double)(*(code *)PTR_strtod_006a99d8)(0,0);
LAB_00456be4:
              *(double *)(ecdsa_results + iVar34 * 0x10 + 8) = dVar37;
            }
            else {
              uVar26 = (uint)*pcVar20;
              *(double *)(ecdsa_results + iVar34 * 0x10) =
                   dVar36 / (dVar36 / *(double *)(ecdsa_results + iVar34 * 0x10) + dVar36 / dVar37);
              if (uVar26 == 0) {
                dVar37 = (double)(*(code *)PTR_strtod_006a99d8)(0,0);
                puVar30 = ecdsa_results + iVar34 * 0x10;
              }
              else {
LAB_00456350:
                (*(code *)PTR_memset_006a99f4)(acStack_53d + 1,0,0x100);
                puVar19 = &sep_19044;
                acStack_53d[1] = 1;
                cVar16 = sep_19044._0_1_;
                while (uVar3 = (uint)cVar16, uVar3 != 0) {
                  puVar19 = (undefined2 *)((int)puVar19 + 1);
                  cVar16 = *(char *)puVar19;
                  acStack_53d[(uVar3 & 0xff) + 1] = '\x01';
                }
                pcVar21 = pcVar20;
                if (acStack_53d[(uVar26 & 0xff) + 1] == '\0') {
                  do {
                    pcVar21 = pcVar21 + 1;
                  } while (acStack_53d[((int)*pcVar21 & 0xffU) + 1] == '\0');
                  if ((int)*pcVar21 != 0) goto LAB_004563e4;
                }
                else {
LAB_004563e4:
                  *pcVar21 = '\0';
                }
                dVar37 = (double)(*(code *)PTR_strtod_006a99d8)(pcVar20,0);
                if (iVar17 == 0) goto LAB_00456be4;
                puVar30 = ecdsa_results + iVar34 * 0x10;
              }
LAB_004560bc:
              *(double *)(puVar30 + 8) =
                   DAT_0063f520 / (DAT_0063f520 / *(double *)(puVar30 + 8) + DAT_0063f520 / dVar37);
            }
          }
          else {
            iVar34 = (*(code *)PTR_strncmp_006a9970)(local_43c,&DAT_0063ed1c,4);
            if (iVar34 == 0) {
              uVar26 = (uint)local_438[0];
              if (uVar26 == 0) {
                pcVar20 = local_438;
                pcVar21 = (char *)0x0;
              }
              else {
                (*(code *)PTR_memset_006a99f4)(acStack_53d + 1,0,0x100);
                puVar19 = &sep_19044;
                acStack_53d[1] = 1;
                cVar16 = sep_19044._0_1_;
                while (uVar3 = (uint)cVar16, uVar3 != 0) {
                  puVar19 = (undefined2 *)((int)puVar19 + 1);
                  cVar16 = *(char *)puVar19;
                  acStack_53d[(uVar3 & 0xff) + 1] = '\x01';
                }
                pcVar21 = local_438;
                pcVar20 = pcVar21;
                if (acStack_53d[(uVar26 & 0xff) + 1] == '\0') {
                  pcVar20 = local_438;
                  do {
                    pcVar20 = pcVar20 + 1;
                  } while (acStack_53d[((int)*pcVar20 & 0xffU) + 1] == '\0');
                  if ((int)*pcVar20 != 0) goto LAB_004564b0;
                }
                else {
LAB_004564b0:
                  *pcVar20 = '\0';
                  pcVar20 = pcVar20 + 1;
                }
              }
              iVar34 = (*(code *)PTR_strtol_006a9958)(pcVar21,0,10);
              cVar16 = *pcVar20;
              if ((int)cVar16 == 0) {
LAB_004566b0:
                pcVar21 = (char *)0x0;
              }
              else {
                (*(code *)PTR_memset_006a99f4)(acStack_53d + 1,0,0x100);
                puVar19 = &sep_19044;
                acStack_53d[1] = 1;
                cVar1 = sep_19044._0_1_;
                while (uVar26 = (uint)cVar1, uVar26 != 0) {
                  puVar19 = (undefined2 *)((int)puVar19 + 1);
                  cVar1 = *(char *)puVar19;
                  acStack_53d[(uVar26 & 0xff) + 1] = '\x01';
                }
                if (acStack_53d[((int)cVar16 & 0xffU) + 1] == '\0') {
                  do {
                    pcVar20 = pcVar20 + 1;
                  } while (acStack_53d[((int)*pcVar20 & 0xffU) + 1] == '\0');
                  pcVar21 = (char *)0x0;
                  if ((int)*pcVar20 != 0) goto LAB_00456578;
                }
                else {
LAB_00456578:
                  cVar16 = pcVar20[1];
                  pcVar21 = pcVar20 + 1;
                  *pcVar20 = '\0';
                  if ((int)cVar16 == 0) goto LAB_004566b0;
                  (*(code *)PTR_memset_006a99f4)(acStack_53d + 1,0,0x100);
                  puVar19 = &sep_19044;
                  acStack_53d[1] = 1;
                  cVar1 = sep_19044._0_1_;
                  while (uVar26 = (uint)cVar1, uVar26 != 0) {
                    puVar19 = (undefined2 *)((int)puVar19 + 1);
                    cVar1 = *(char *)puVar19;
                    acStack_53d[(uVar26 & 0xff) + 1] = '\x01';
                  }
                  pcVar20 = pcVar21;
                  if (acStack_53d[((int)cVar16 & 0xffU) + 1] == '\0') {
                    do {
                      pcVar20 = pcVar20 + 1;
                    } while (acStack_53d[((int)*pcVar20 & 0xffU) + 1] == '\0');
                    if ((int)*pcVar20 == 0) goto LAB_00456634;
                  }
                  *pcVar20 = '\0';
                }
              }
LAB_00456634:
              dVar37 = (double)(*(code *)PTR_strtod_006a99d8)(pcVar21,0);
              if (iVar17 == 0) {
                *(double *)(ecdh_results + iVar34 * 8) = dVar37;
              }
              else {
                *(double *)(ecdh_results + iVar34 * 8) =
                     dVar38 / (dVar38 / *(double *)(ecdh_results + iVar34 * 8) + dVar38 / dVar37);
              }
            }
            else {
              iVar34 = (*(code *)PTR_strncmp_006a9970)(local_43c,&DAT_0063ed24,3);
              if (iVar34 != 0) {
                pcVar20 = "Unknown type \'%s\' from child %d\n";
                goto LAB_004555f8;
              }
            }
          }
        }
      }
      goto LAB_004555a4;
    }
LAB_00455628:
    iVar17 = iVar17 + 1;
    local_2958 = ZEXT48(local_2958._0_4_ + 1) << 0x20;
    (*(code *)PTR_fclose_006a9998)(uVar18);
  } while (iVar17 < (int)local_2988._0_4_);
  (*(code *)PTR_free_006a9af0)(puVar13);
  uVar26 = (uint)local_2948._0_4_;
  if (mr == 0) {
    local_28e0 = 0;
LAB_00454c34:
    puVar15 = PTR_stdout_006a99c8;
    uVar29 = *puVar31;
    uVar18 = (*(code *)PTR_SSLeay_version_006a7aa4)(0);
    (*(code *)PTR___fprintf_chk_006a9980)(uVar29,1,"%s\n",uVar18);
    uVar29 = *puVar31;
    uVar18 = (*(code *)PTR_SSLeay_version_006a7aa4)(3);
    (*(code *)PTR___fprintf_chk_006a9980)(uVar29,1,"%s\n",uVar18);
    (*(code *)PTR___printf_chk_006a99c4)(1,"options:");
    uVar18 = (*(code *)PTR_BN_options_006a7aa8)();
    (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_0063f00c,uVar18);
    uVar18 = (*(code *)PTR_RC4_options_006a7aac)();
    (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_0063f00c,uVar18);
    uVar18 = (*(code *)PTR_DES_options_006a7ab0)();
    (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_0063f00c,uVar18);
    uVar18 = (*(code *)PTR_AES_options_006a7ab4)();
    (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_0063f00c,uVar18);
    uVar18 = (*(code *)PTR_idea_options_006a7ab8)();
    (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_0063f00c,uVar18);
    uVar18 = (*(code *)PTR_BF_options_006a7abc)();
    (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_0063f00c,uVar18);
    uVar29 = *puVar31;
    uVar18 = (*(code *)PTR_SSLeay_version_006a7aa4)(2);
    (*(code *)PTR___fprintf_chk_006a9980)(uVar29,1,&DAT_0063f010,uVar18);
    uVar26 = (uint)local_2980._0_4_;
    if (local_28e0 != 0) {
      if (mr == 0) {
        (*(code *)PTR_fwrite_006a9a74)
                  ("The \'numbers\' are in 1000s of bytes per second processed.\n",1,0x3a,
                   *(undefined4 *)puVar15);
        (*(code *)PTR_fwrite_006a9a74)("type        ",1,0xc,*(undefined4 *)puVar15);
      }
      else {
LAB_004545bc:
        (*(code *)PTR_fwrite_006a9a74)(&DAT_0063f018,1,2,*local_2980._0_4_);
      }
      puVar30 = lengths;
      do {
        if (mr == 0) {
          pcVar20 = "%7d bytes";
        }
        else {
          pcVar20 = ":%d";
        }
        uVar18 = *(undefined4 *)puVar30;
        puVar30 = (undefined1 *)((int)puVar30 + 4);
        (*(code *)PTR___fprintf_chk_006a9980)(*local_2980._0_4_,1,pcVar20,uVar18);
      } while (puVar30 != "string to make the random number generator think it has entropy");
      (*(code *)PTR_fputc_006a99a4)(10,*local_2980._0_4_);
    }
  }
LAB_00453930:
  local_2974 = (int **)&_gp_1;
  local_2948 = 0x6aa20000000000;
  local_2960 = 0x6aa28000000000;
  local_28e4 = (double *)(results + 0x28);
  local_294c = test_curves_bits_17838;
  local_298c = names;
  iVar17 = 0;
  piVar8 = local_291c;
  dVar36 = DAT_0063f528;
  do {
    puVar15 = PTR_stdout_006a99c8;
    if (*piVar8 != 0) {
      if (mr == 0) {
        (*(code *)PTR___fprintf_chk_006a9980)
                  (*(undefined4 *)PTR_stdout_006a99c8,1,"%-13s",*(undefined4 *)local_298c);
      }
      else {
        (*(code *)PTR___fprintf_chk_006a9980)
                  (*(undefined4 *)PTR_stdout_006a99c8,1,"+F:%d:%s",iVar17,*(undefined4 *)local_298c)
        ;
      }
      pdVar33 = local_28e4 + -5;
      do {
        if (dVar36 < *pdVar33) {
          if (mr != 0) {
            uVar18 = *(undefined4 *)puVar15;
            goto LAB_004539bc;
          }
          (*(code *)PTR___fprintf_chk_006a9980)(*(undefined4 *)puVar15,1," %11.2fk");
        }
        else {
          uVar18 = *(undefined4 *)puVar15;
          if (mr == 0) {
            pcVar20 = " %11.2f ";
          }
          else {
LAB_004539bc:
            pcVar20 = ":%.2f";
          }
          (*(code *)PTR___fprintf_chk_006a9980)(uVar18,1,pcVar20);
        }
        pdVar33 = pdVar33 + 1;
      } while (pdVar33 != local_28e4);
      (*(code *)PTR_fputc_006a99a4)(10,*(undefined4 *)puVar15);
    }
    iVar17 = iVar17 + 1;
    piVar8 = piVar8 + 1;
    local_28e4 = local_28e4 + 5;
    local_298c = (char *)((int)local_298c + 4);
  } while (iVar17 != 0x1e);
  if (local_288c[0] == (int *)0x0) {
    if (local_288c[1] == (int *)0x0) {
      if (local_2884 != 0) {
        local_2980 = ZEXT48(PTR_stdout_006a99c8) << 0x20;
        goto LAB_00454134;
      }
      bVar2 = true;
    }
    else {
      local_2980 = ZEXT48(PTR_stdout_006a99c8) << 0x20;
LAB_004540d4:
      bVar2 = true;
      if (mr == 0) {
        (*(code *)PTR___printf_chk_006a99c4)
                  (1,"%18ssign    verify    sign/s verify/s\n",&DAT_0063eb84);
        goto LAB_00453a84;
      }
LAB_004540dc:
      (*(code *)PTR___fprintf_chk_006a9980)(*local_2980._0_4_,1,"+F2:%u:%u:%f:%f\n",1);
LAB_00454120:
      if (local_2884 != 0) {
        if (!bVar2) goto LAB_004548e8;
LAB_00454134:
        bVar2 = true;
        if (mr == 0) {
          (*(code *)PTR___printf_chk_006a99c4)
                    (1,"%18ssign    verify    sign/s verify/s\n",&DAT_0063eb84);
          goto LAB_004548e8;
        }
        goto LAB_00454140;
      }
    }
LAB_00454180:
    if (local_2880 != 0) {
      if (bVar2) {
        if (mr == 0) {
          local_2980 = ZEXT48(PTR_stdout_006a99c8) << 0x20;
          (*(code *)PTR___printf_chk_006a99c4)
                    (1,"%18ssign    verify    sign/s verify/s\n",&DAT_0063eb84);
          goto LAB_00453af8;
        }
        local_2980 = ZEXT48(PTR_stdout_006a99c8) << 0x20;
      }
      else {
        local_2980 = ZEXT48(PTR_stdout_006a99c8) << 0x20;
LAB_00453af8:
        if (mr == 0) {
          (*(code *)PTR___fprintf_chk_006a9980)
                    (*local_2980._0_4_,1,"rsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x1000,
                     rsa_results._48_8_,rsa_results._56_8_,DAT_0063f520 / rsa_results._48_8_,
                     DAT_0063f520 / rsa_results._56_8_);
          goto LAB_004541e4;
        }
      }
      (*(code *)PTR___fprintf_chk_006a9980)(*local_2980._0_4_,1,"+F2:%u:%u:%f:%f\n",3);
    }
  }
  else {
    bVar2 = true;
    if (mr == 0) {
      (*(code *)PTR___printf_chk_006a99c4)
                (1,"%18ssign    verify    sign/s verify/s\n",&DAT_0063eb84);
      if (mr != 0) {
        bVar2 = false;
        goto LAB_00453a24;
      }
      local_2980 = ZEXT48(PTR_stdout_006a99c8) << 0x20;
      (*(code *)PTR___fprintf_chk_006a9980)
                (*(undefined4 *)PTR_stdout_006a99c8,1,"rsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",
                 0x200,rsa_results._0_8_,rsa_results._8_8_,DAT_0063f520 / rsa_results._0_8_,
                 DAT_0063f520 / rsa_results._8_8_);
      if (local_288c[1] != (int *)0x0) goto LAB_00453a84;
      if (local_2884 == 0) {
        bVar2 = false;
        goto LAB_00454180;
      }
LAB_004548e8:
      if (mr != 0) {
        bVar2 = false;
LAB_00454140:
        (*(code *)PTR___fprintf_chk_006a9980)(*local_2980._0_4_,1,"+F2:%u:%u:%f:%f\n",2);
        goto LAB_00454180;
      }
      (*(code *)PTR___fprintf_chk_006a9980)
                (*local_2980._0_4_,1,"rsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x800,
                 rsa_results._32_8_,rsa_results._40_8_,DAT_0063f520 / rsa_results._32_8_,
                 DAT_0063f520 / rsa_results._40_8_);
      if (local_2880 == 0) goto LAB_004541e4;
      goto LAB_00453af8;
    }
LAB_00453a24:
    local_2980 = ZEXT48(PTR_stdout_006a99c8) << 0x20;
    (*(code *)PTR___fprintf_chk_006a9980)
              (*(undefined4 *)PTR_stdout_006a99c8,1,"+F2:%u:%u:%f:%f\n",0);
    if (local_288c[1] == (int *)0x0) goto LAB_00454120;
    if (bVar2) goto LAB_004540d4;
LAB_00453a84:
    if (mr != 0) {
      bVar2 = false;
      goto LAB_004540dc;
    }
    (*(code *)PTR___fprintf_chk_006a9980)
              (*local_2980._0_4_,1,"rsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x400,
               rsa_results._16_8_,rsa_results._24_8_,DAT_0063f520 / rsa_results._16_8_,
               DAT_0063f520 / rsa_results._24_8_);
    if (local_2884 != 0) goto LAB_004548e8;
    if (local_2880 != 0) goto LAB_00453af8;
  }
LAB_004541e4:
  if (local_28b4[3] == 0) {
    if (local_28b4[4] == 0) {
      if (local_28b4[5] == 0) goto LAB_00454314;
      local_2980 = ZEXT48(PTR_stdout_006a99c8) << 0x20;
    }
    else {
      local_2980 = ZEXT48(PTR_stdout_006a99c8) << 0x20;
LAB_004547a4:
      bVar2 = true;
      if (mr == 0) {
        (*(code *)PTR___printf_chk_006a99c4)
                  (1,"%18ssign    verify    sign/s verify/s\n",&DAT_0063eb84);
        goto LAB_00454258;
      }
LAB_004547ac:
      (*(code *)PTR___fprintf_chk_006a9980)(*local_2980._0_4_,1,"+F3:%u:%u:%f:%f\n",1);
LAB_004547f0:
      if (local_28b4[5] == 0) goto LAB_00454314;
      if (!bVar2) goto LAB_004542c0;
    }
    if (mr == 0) {
      (*(code *)PTR___printf_chk_006a99c4)
                (1,"%18ssign    verify    sign/s verify/s\n",&DAT_0063eb84);
      goto LAB_004542c0;
    }
  }
  else {
    bVar2 = true;
    if (mr == 0) {
      (*(code *)PTR___printf_chk_006a99c4)
                (1,"%18ssign    verify    sign/s verify/s\n",&DAT_0063eb84);
      if (mr != 0) {
        bVar2 = false;
        goto LAB_004541f8;
      }
      local_2980 = ZEXT48(PTR_stdout_006a99c8) << 0x20;
      (*(code *)PTR___fprintf_chk_006a9980)
                (*(undefined4 *)PTR_stdout_006a99c8,1,"dsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",
                 0x200,dsa_results._0_8_,dsa_results._8_8_,DAT_0063f520 / dsa_results._0_8_,
                 DAT_0063f520 / dsa_results._8_8_);
      if (local_28b4[4] != 0) goto LAB_00454258;
    }
    else {
LAB_004541f8:
      local_2980 = ZEXT48(PTR_stdout_006a99c8) << 0x20;
      (*(code *)PTR___fprintf_chk_006a9980)
                (*(undefined4 *)PTR_stdout_006a99c8,1,"+F3:%u:%u:%f:%f\n",0);
      if (local_28b4[4] == 0) goto LAB_004547f0;
      if (bVar2) goto LAB_004547a4;
LAB_00454258:
      if (mr != 0) {
        bVar2 = false;
        goto LAB_004547ac;
      }
      (*(code *)PTR___fprintf_chk_006a9980)
                (*local_2980._0_4_,1,"dsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x400,
                 dsa_results._16_8_,dsa_results._24_8_,DAT_0063f520 / dsa_results._16_8_,
                 DAT_0063f520 / dsa_results._24_8_);
    }
    if (local_28b4[5] == 0) goto LAB_00454314;
LAB_004542c0:
    if (mr == 0) {
      (*(code *)PTR___fprintf_chk_006a9980)
                (*local_2980._0_4_,1,"dsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x800,
                 dsa_results._32_8_,dsa_results._40_8_,DAT_0063f520 / dsa_results._32_8_,
                 DAT_0063f520 / dsa_results._40_8_);
      goto LAB_00454314;
    }
  }
  (*(code *)PTR___fprintf_chk_006a9980)(*local_2980._0_4_,1,"+F3:%u:%u:%f:%f\n",2);
LAB_00454314:
  local_2988 = (ulonglong)uVar26 << 0x20;
  local_2990 = "+F4:%u:%u:%f:%f\n";
  iVar17 = 0;
  local_298c = "-check_ss_sig";
  bVar2 = true;
  piVar8 = local_28f8;
  puVar24 = (undefined4 *)local_294c;
LAB_004543bc:
  do {
    if (*piVar8 != 0) {
      if (bVar2) {
        bVar2 = true;
        if (mr == 0) {
          (*(code *)PTR___printf_chk_006a99c4)
                    (1,"%30ssign    verify    sign/s verify/s\n",&DAT_0063eb84);
          if (mr == 0) goto LAB_004543d8;
          bVar2 = false;
        }
      }
      else {
        bVar2 = false;
        if (mr == 0) {
LAB_004543d8:
          iVar17 = iVar17 + 1;
          bVar2 = false;
          piVar8 = piVar8 + 1;
          (*(code *)PTR___fprintf_chk_006a9980)
                    (*(undefined4 *)PTR_stdout_006a99c8,1,
                     "%4u bit ecdsa (%s) %8.4fs %8.4fs %8.1f %8.1f\n",*puVar24);
          puVar24 = puVar24 + 1;
          if (iVar17 == 0x10) break;
          goto LAB_004543bc;
        }
      }
      (*(code *)PTR___fprintf_chk_006a9980)
                (*(undefined4 *)PTR_stdout_006a99c8,1,"+F4:%u:%u:%f:%f\n",iVar17);
    }
    iVar17 = iVar17 + 1;
    piVar8 = piVar8 + 1;
    puVar24 = puVar24 + 1;
  } while (iVar17 != 0x10);
  local_2948._0_4_ = ecdh_results;
  iVar17 = 0;
  ppiVar7 = (int **)0x1;
  pcVar20 = "+F5:%u:%u:%f:%f\n";
  puVar24 = (undefined4 *)local_294c;
  piVar8 = local_28f4;
  puVar28 = test_curves_names_17837;
LAB_004544d0:
  do {
    puVar35 = puVar28;
    puVar30 = local_2948._0_4_;
    if (*piVar8 != 0) {
      if (ppiVar7 == (int **)0x0) {
        ppiVar7 = (int **)0x0;
        if (mr == 0) {
LAB_004544ec:
          iVar17 = iVar17 + 1;
          ppiVar7 = (int **)0x0;
          piVar8 = piVar8 + 1;
          (*(code *)PTR___fprintf_chk_006a9980)
                    (*(undefined4 *)PTR_stdout_006a99c8,1,"%4u bit ecdh (%s) %8.4fs %8.1f\n",
                     *puVar24);
          puVar24 = puVar24 + 1;
          local_2948._0_4_ = puVar30 + 8;
          puVar28 = puVar35 + 4;
          if (iVar17 == 0x10) break;
          goto LAB_004544d0;
        }
      }
      else {
        ppiVar7 = (int **)0x1;
        if (mr == 0) {
          (*(code *)PTR___printf_chk_006a99c4)(1,"%30sop      op/s\n",&DAT_0063eb84);
          if (mr == 0) goto LAB_004544ec;
          ppiVar7 = (int **)0x0;
        }
      }
      (*(code *)PTR___fprintf_chk_006a9980)
                (*(undefined4 *)PTR_stdout_006a99c8,1,"+F5:%u:%u:%f:%f\n",iVar17);
    }
    iVar17 = iVar17 + 1;
    piVar8 = piVar8 + 1;
    puVar24 = puVar24 + 1;
    local_2948._0_4_ = puVar30 + 8;
    puVar28 = puVar35 + 4;
  } while (iVar17 != 0x10);
  unaff_s8 = (int **)(puVar35 + 4);
  puVar30 = puVar30 + 8;
  local_2914 = 0;
  local_2980._0_4_ = (undefined4 *)uVar26;
LAB_0044ee88:
  (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
  (*(code *)PTR_CRYPTO_free_006a6e88)(local_2980._0_4_);
  (*(code *)PTR_CRYPTO_free_006a6e88)(local_2950);
  unaff_s6 = local_2974;
  goto LAB_0044e984;
LAB_004552b0:
  (*(code *)PTR_HMAC_CTX_cleanup_006a7adc)(auStack_2420);
  local_2930 = dVar36;
  goto LAB_0044f94c;
LAB_00455294:
  (*(code *)PTR_CRYPTO_gcm128_release_006a7ad8)(uVar18);
  goto LAB_0045152c;
}

