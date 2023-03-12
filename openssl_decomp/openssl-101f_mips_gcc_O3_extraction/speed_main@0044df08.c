
/* WARNING: Heritage AFTER dead removal. Example location: r0x006ab9b8 : 0x00450120 */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int speed_main(int param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  char **ppcVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  char *pcVar14;
  uint uVar15;
  undefined *puVar16;
  char cVar17;
  undefined2 *puVar18;
  int iVar19;
  undefined4 uVar20;
  char *pcVar21;
  char *pcVar22;
  char *pcVar23;
  char **ppcVar24;
  double *pdVar25;
  char **ppcVar26;
  uint uVar27;
  char **ppcVar28;
  undefined1 *puVar29;
  double *pdVar30;
  undefined1 *puVar31;
  int *piVar32;
  undefined4 uVar33;
  undefined4 *puVar34;
  code *pcVar35;
  char **unaff_s6;
  undefined4 *unaff_s7;
  undefined4 *puVar36;
  int iVar37;
  char *pcVar38;
  char *unaff_s8;
  double dVar39;
  double dVar40;
  double dVar41;
  char *local_298c;
  longlong local_2988;
  ulonglong local_2980;
  undefined1 *local_2978;
  char **local_2970;
  int local_295c;
  longlong local_2958;
  ulonglong local_2950;
  ulonglong local_2948;
  longlong local_2940;
  double local_2938;
  double local_2930;
  undefined1 *local_2928;
  int *local_2924;
  char *local_2920;
  char *local_2918;
  char *local_2910;
  int local_290c;
  int *local_2908;
  int *local_2904;
  char *local_2900;
  char *local_28fc;
  double *local_28f0;
  int local_28ec;
  char *local_28e4;
  char *local_28e0;
  char *local_28c4;
  undefined4 local_28bc;
  char *local_28b8;
  int local_28b4 [6];
  char *local_289c [4];
  char *local_288c [2];
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
  char *local_285c [16];
  char *local_281c [16];
  char *local_27dc [16];
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
  
  puVar7 = PTR___stack_chk_guard_006aabf0;
  puVar5 = PTR_bio_err_006a7f3c;
  local_3c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_298c = "\x14";
  usertime = (char *)0xffffffff;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  local_2978 = results;
  (*(code *)PTR_memset_006aab00)(results,0,0x4b0);
  local_28b4[0] = 0;
  local_28b4[1] = 0;
  local_28b4[2] = 0;
  (*(code *)PTR_memset_006aab00)(local_285c,0,0x40);
  (*(code *)PTR_memset_006aab00)(local_281c,0,0x40);
  (*(code *)PTR_memset_006aab00)(local_27dc,0,0x40);
  iVar19 = *(int *)puVar5;
  if (iVar19 == 0) {
    uVar20 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar19 = (*(code *)PTR_BIO_new_006a7fa4)(uVar20);
    *(int *)puVar5 = iVar19;
    puVar16 = PTR_stderr_006aac00;
    if (iVar19 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar19,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
      iVar19 = *(int *)puVar5;
      unaff_s7 = (undefined4 *)puVar16;
    }
  }
  iVar19 = load_config(iVar19,0);
  puVar31 = (undefined1 *)local_285c;
  ppcVar8 = local_281c;
  puVar36 = unaff_s7;
  if (iVar19 != 0) {
    local_289c[0] = (char *)0x0;
    local_289c[1] = (char *)0x0;
    local_289c[2] = (char *)0x0;
    local_289c[3] = (char *)0x0;
    local_2980._0_4_ = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x2001,"speed.c",0x29b);
    if (local_2980._0_4_ != (undefined4 *)0x0) {
      local_295c = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x2001,"speed.c",0x2a0);
      if (local_295c != 0) {
        local_2950._0_4_ = &local_71c;
        (*(code *)PTR_memset_006aab00)(auStack_1a4c,0,600);
        local_2924 = local_279c + 0x20;
        local_71c = 0;
        local_2958 = ZEXT48(&local_7ac) << 0x20;
        local_2908 = local_279c;
        local_7ac = 0;
        local_2904 = local_279c + 0x10;
        local_7a8 = 0;
        local_718 = 0;
        local_714 = 0;
        ppcVar24 = (char **)(param_1 + -1);
        ppcVar26 = (char **)(param_2 + 4);
        local_710 = 0;
        local_70c = 0;
        local_708 = 0;
        local_704 = 0;
        local_700 = 0;
        (*(code *)PTR_memset_006aab00)(local_2924,0,0x78);
        local_288c[0] = (char *)0x0;
        local_288c[1] = (char *)0x0;
        local_2884 = 0;
        local_2880 = 0;
        local_28b4[3] = 0;
        local_28b4[4] = 0;
        local_28b4[5] = 0;
        (*(code *)PTR_memset_006aab00)(local_2908,0,0x40);
        (*(code *)PTR_memset_006aab00)(local_2904,0,0x40);
        if (ppcVar24 != (char **)0x0) {
          local_2980 = ZEXT48(local_2980._0_4_) << 0x20;
          local_2950 = ZEXT48(local_2950._0_4_) << 0x20;
          local_2988 = 0;
          local_2928 = (undefined1 *)0x0;
          ppcVar8 = (char **)0x0;
          local_2948 = 0x65000000000000;
          ppcVar28 = (char **)0x0;
          puVar36 = (undefined4 *)&DAT_00632578;
          unaff_s8 = &UNK_0063eb68;
          local_290c = 0;
          local_2970 = ppcVar24;
          goto LAB_0044e328;
        }
        local_2940 = 0;
        local_290c = 0;
        local_2928 = (undefined1 *)0x0;
        pcVar23 = usertime;
        goto LAB_0044e3d0;
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,"out of memory\n");
      local_290c = 1;
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar5);
      (*(code *)PTR_CRYPTO_free_006a7f88)(local_2980._0_4_);
      goto LAB_0044e07c;
    }
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,"out of memory\n");
  }
  local_290c = 1;
  (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar5);
LAB_0044e07c:
  local_2970 = local_289c;
  do {
    if (*local_2970 != (char *)0x0) {
      (*(code *)PTR_RSA_free_006a86f0)();
    }
    local_2970 = local_2970 + 1;
  } while (local_288c != local_2970);
  piVar9 = local_28b4;
  do {
    if (*piVar9 != 0) {
      (*(code *)PTR_DSA_free_006a862c)();
    }
    piVar9 = piVar9 + 1;
    ppcVar28 = local_285c;
  } while (piVar9 != local_28b4 + 3);
  do {
    if (*ppcVar28 != (char *)0x0) {
      (*(code *)PTR_EC_KEY_free_006a82d8)();
    }
    ppcVar28 = ppcVar28 + 1;
    ppcVar24 = local_281c;
    ppcVar26 = local_27dc;
  } while (local_281c != ppcVar28);
  do {
    if (*ppcVar24 != (char *)0x0) {
      (*(code *)PTR_EC_KEY_free_006a82d8)();
    }
    if (*ppcVar26 != (char *)0x0) {
      (*(code *)PTR_EC_KEY_free_006a82d8)();
    }
    ppcVar24 = ppcVar24 + 1;
    ppcVar26 = ppcVar26 + 1;
  } while (local_27dc != ppcVar24);
  if (local_3c == *(int *)puVar7) {
    return local_290c;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  ppcVar28 = local_27dc;
  local_2970 = unaff_s6;
LAB_0045639c:
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"des-ede3");
  if (iVar19 == 0) {
    local_26f8 = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"aes-128-cbc");
  if (iVar19 == 0) {
    local_26dc = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"aes-192-cbc");
  if (iVar19 == 0) {
    local_26d8 = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"aes-256-cbc");
  if (iVar19 == 0) {
    local_26d4 = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"aes-128-ige");
  if (iVar19 == 0) {
    local_26b4 = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"aes-192-ige");
  if (iVar19 == 0) {
    local_26b0 = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"aes-256-ige");
  if (iVar19 == 0) {
    local_26ac = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"camellia-128-cbc");
  if (iVar19 == 0) {
    local_26d0 = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"camellia-192-cbc");
  if (iVar19 == 0) {
    local_26cc = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"camellia-256-cbc");
  if (iVar19 == 0) {
    local_26c8 = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"openssl");
  if (iVar19 == 0) {
    ppcVar28 = (char **)((int)ppcVar28 + -1);
    uVar20 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a8bd8)();
    (*(code *)PTR_RSA_set_default_method_006a8bdc)(uVar20);
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"dsa512");
  if (iVar19 == 0) {
    local_28b4[3] = 2;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"dsa1024");
  if (iVar19 == 0) {
    local_28b4[4] = 2;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"dsa2048");
  if (iVar19 == 0) {
    local_28b4[5] = 2;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"rsa512");
  if (iVar19 == 0) {
    local_288c[0] = (char *)0x2;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"rsa1024");
  if (iVar19 == 0) {
    local_288c[1] = (char *)0x2;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"rsa2048");
  if (iVar19 == 0) {
    local_2884 = 2;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"rsa4096");
  if (iVar19 == 0) {
    local_2880 = 2;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"rc2-cbc");
  if ((iVar19 == 0) ||
     ((((local_2940._0_4_ == (undefined4 *)0x0 && (*(char *)((int)puVar31 + 1) == 'c')) &&
       (*(char *)((int)puVar31 + 2) == '2')) && (*(char *)((int)puVar31 + 3) == '\0')))) {
    local_26ec = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"idea-cbc");
  if ((iVar19 == 0) || (iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,&DAT_0063265c), iVar19 == 0)
     ) {
    local_26f4 = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"seed-cbc");
  if ((iVar19 == 0) || (iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"seed"), iVar19 == 0)) {
    local_26f0 = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"bf-cbc");
  if (((iVar19 == 0) || (iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"blowfish"), iVar19 == 0))
     || ((local_2970 == (char **)0x62 &&
         ((*(char *)((int)puVar31 + 1) == 'f' && (*(char *)((int)puVar31 + 2) == '\0')))))) {
    local_26e4 = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"cast-cbc");
  if (((iVar19 == 0) ||
      (iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,&DAT_00632678), iVar19 == 0)) ||
     (iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"cast5"), iVar19 == 0)) {
    local_26e0 = 1;
    goto LAB_0044e318;
  }
  if (local_2970 == (char **)&DAT_00000064) {
    if (((*(char *)((int)puVar31 + 1) == 'e') && (*(char *)((int)puVar31 + 2) == 's')) &&
       (*(char *)((int)puVar31 + 3) == '\0')) {
      local_26fc = 1;
      local_26f8 = 1;
      goto LAB_0044e318;
    }
  }
  else if (((local_2970 == (char **)&DAT_00000061) && (*(char *)((int)puVar31 + 1) == 'e')) &&
          ((*(char *)((int)puVar31 + 2) == 's' && (*(char *)((int)puVar31 + 3) == '\0')))) {
    local_26dc = 1;
    local_26d8 = 1;
    local_26d4 = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ghash");
  if (iVar19 == 0) {
    local_26a8 = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"camellia");
  if (iVar19 == 0) {
    local_26d0 = 1;
    local_26cc = 1;
    local_26c8 = 1;
    goto LAB_0044e318;
  }
  if (local_2940._0_4_ == (undefined4 *)0x0) {
    if (*(char *)((int)puVar31 + 1) == 's') {
      cVar17 = *(char *)((int)puVar31 + 2);
      if ((cVar17 == 'a') && (*(char *)((int)puVar31 + 3) == '\0')) {
        local_288c[0] = (char *)0x1;
        local_288c[1] = (char *)0x1;
        local_2884 = 1;
        local_2880 = 1;
        goto LAB_0044e318;
      }
      if (local_2970 == (char **)&DAT_00000064) goto LAB_004569a0;
    }
  }
  else if ((local_2970 == (char **)&DAT_00000064) && (*(char *)((int)puVar31 + 1) == 's')) {
    cVar17 = *(char *)((int)puVar31 + 2);
LAB_004569a0:
    if ((cVar17 == 'a') && (*(char *)((int)puVar31 + 3) == '\0')) {
      local_28b4[3] = 1;
      local_28b4[4] = 1;
      local_28b4[5] = 1;
      goto LAB_0044e318;
    }
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdsap160");
  if (iVar19 == 0) {
    local_279c[0] = 2;
  }
  else {
    iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdsap192");
    if (iVar19 == 0) {
      local_279c[1] = 2;
    }
    else {
      iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdsap224");
      if (iVar19 == 0) {
        local_279c[2] = 2;
      }
      else {
        iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdsap256");
        if (iVar19 == 0) {
          local_279c[3] = 2;
        }
        else {
          iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdsap384");
          if (iVar19 == 0) {
            local_279c[4] = 2;
          }
          else {
            iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdsap521");
            if (iVar19 == 0) {
              local_279c[5] = 2;
            }
            else {
              iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdsak163");
              if (iVar19 == 0) {
                local_279c[6] = 2;
              }
              else {
                iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdsak233");
                if (iVar19 == 0) {
                  local_279c[7] = 2;
                }
                else {
                  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdsak283");
                  if (iVar19 == 0) {
                    local_279c[8] = 2;
                  }
                  else {
                    iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdsak409");
                    if (iVar19 == 0) {
                      local_279c[9] = 2;
                    }
                    else {
                      iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdsak571");
                      if (iVar19 == 0) {
                        local_279c[10] = 2;
                      }
                      else {
                        iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdsab163");
                        if (iVar19 == 0) {
                          local_279c[11] = 2;
                        }
                        else {
                          iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdsab233");
                          if (iVar19 == 0) {
                            local_279c[12] = 2;
                          }
                          else {
                            iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdsab283");
                            if (iVar19 == 0) {
                              local_279c[13] = 2;
                            }
                            else {
                              iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdsab409");
                              if (iVar19 == 0) {
                                local_279c[14] = 2;
                              }
                              else {
                                iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdsab571");
                                if (iVar19 == 0) {
                                  local_279c[15] = 2;
                                }
                                else {
                                  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdsa");
                                  if (iVar19 == 0) {
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
                                    iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdhp160");
                                    if (iVar19 == 0) {
                                      local_279c[16] = 2;
                                    }
                                    else {
                                      iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdhp192");
                                      if (iVar19 == 0) {
                                        local_279c[17] = 2;
                                      }
                                      else {
                                        iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ecdhp224");
                                        if (iVar19 == 0) {
                                          local_279c[18] = 2;
                                        }
                                        else {
                                          iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                             (puVar31,"ecdhp256");
                                          if (iVar19 == 0) {
                                            local_279c[19] = 2;
                                          }
                                          else {
                                            iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                               (puVar31,"ecdhp384");
                                            if (iVar19 == 0) {
                                              local_279c[20] = 2;
                                            }
                                            else {
                                              iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                 (puVar31,"ecdhp521");
                                              if (iVar19 == 0) {
                                                local_279c[21] = 2;
                                              }
                                              else {
                                                iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                   (puVar31,"ecdhk163");
                                                if (iVar19 == 0) {
                                                  local_279c[22] = 2;
                                                }
                                                else {
                                                  iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                     (puVar31,"ecdhk233");
                                                  if (iVar19 == 0) {
                                                    local_279c[23] = 2;
                                                  }
                                                  else {
                                                    iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                       (puVar31,"ecdhk283");
                                                    if (iVar19 == 0) {
                                                      local_279c[24] = 2;
                                                    }
                                                    else {
                                                      iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                         (puVar31,"ecdhk409");
                                                      if (iVar19 == 0) {
                                                        local_279c[25] = 2;
                                                      }
                                                      else {
                                                        iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                           (puVar31,"ecdhk571");
                                                        if (iVar19 == 0) {
                                                          local_279c[26] = 2;
                                                        }
                                                        else {
                                                          iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                             (puVar31,"ecdhb163");
                                                          if (iVar19 == 0) {
                                                            local_279c[27] = 2;
                                                          }
                                                          else {
                                                            iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                               (puVar31,"ecdhb233");
                                                            if (iVar19 == 0) {
                                                              local_279c[28] = 2;
                                                            }
                                                            else {
                                                              iVar19 = (*(code *)PTR_strcmp_006aac20
                                                                       )(puVar31,"ecdhb283");
                                                              if (iVar19 == 0) {
                                                                local_279c[29] = 2;
                                                              }
                                                              else {
                                                                iVar19 = (*(code *)
                                                  PTR_strcmp_006aac20)(puVar31,"ecdhb409");
                                                  if (iVar19 == 0) {
                                                    local_279c[30] = 2;
                                                  }
                                                  else {
                                                    iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                       (puVar31,"ecdhb571");
                                                    if (iVar19 == 0) {
                                                      local_279c[31] = 2;
                                                    }
                                                    else {
                                                      iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                         (puVar31,&DAT_0063edb4);
                                                      if (iVar19 != 0) {
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,
                                                                   "Error: bad option or value\n");
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,"\n");
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,
                                                                   "Available values:\n");
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,"mdc2     "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,"md4      "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,"md5      "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,"hmac     "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,"sha1     "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,"sha256   "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,"sha512   "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,
                                                                   (int)local_2938._0_4_ + -0x1480);
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,
                                                                   (int)local_2930._0_4_ + 0x2580);
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,"\n");
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,"idea-cbc "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,"seed-cbc "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,"rc2-cbc  "
                                                                  );
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,"bf-cbc");
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,"\n");
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,
                                                                   "des-cbc  des-ede3 ");
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar5,
                                                                                                                                      
                                                  "aes-128-cbc aes-192-cbc aes-256-cbc ");
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,
                                                             "aes-128-ige aes-192-ige aes-256-ige ")
                                                  ;
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,"\n");
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,
                                                                                                                          
                                                  "camellia-128-cbc camellia-192-cbc camellia-256-cbc "
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,&DAT_00632664);
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,"\n");
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,
                                                             "rsa512   rsa1024  rsa2048  rsa4096\n")
                                                  ;
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,
                                                             "dsa512   dsa1024  dsa2048\n");
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,
                                                                                                                          
                                                  "ecdsap160 ecdsap192 ecdsap224 ecdsap256 ecdsap384 ecdsap521\n"
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,
                                                                                                                          
                                                  "ecdsak163 ecdsak233 ecdsak283 ecdsak409 ecdsak571\n"
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,
                                                                                                                          
                                                  "ecdsab163 ecdsab233 ecdsab283 ecdsab409 ecdsab571\n"
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,"ecdsa\n");
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,
                                                                                                                          
                                                  "ecdhp160  ecdhp192  ecdhp224  ecdhp256  ecdhp384  ecdhp521\n"
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,
                                                                                                                          
                                                  "ecdhk163  ecdhk233  ecdhk283  ecdhk409  ecdhk571\n"
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,
                                                                                                                          
                                                  "ecdhb163  ecdhb233  ecdhb283  ecdhb409  ecdhb571\n"
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,"ecdh\n");
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,"idea     ");
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,"seed     ");
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,&DAT_0063f0b0);
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,&DAT_0063f0bc);
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,"aes      ");
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,"camellia ");
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,"rsa      ");
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,"blowfish");
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,"\n");
                                                  local_290c = 1;
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,"\n");
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,
                                                             "Available options:\n");
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,
                                                                                                                          
                                                  "-engine e       use engine e, possibly a hardware device.\n"
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,
                                                             "-evp e          use EVP e.\n");
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,
                                                                                                                          
                                                  "-decrypt        time decryption instead of encryption (only EVP).\n"
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,
                                                                                                                          
                                                  "-mr             produce machine readable output.\n"
                                                  );
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar5,
                                                                                                                          
                                                  "-multi n        run n benchmarks in parallel.\n")
                                                  ;
                                                  goto LAB_0044e580;
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
LAB_0044e318:
  ppcVar24 = (char **)((int)ppcVar24 + -1);
  ppcVar26 = ppcVar26 + 1;
  uVar3 = local_2950;
  while( true ) {
    unaff_s7 = (undefined4 *)PTR_stderr_006aac00;
    puVar16 = PTR_stdout_006aaad4;
    ppcVar28 = (char **)((int)ppcVar28 + 1);
    local_2950 = uVar3;
    if (ppcVar24 == (char **)0x0) {
      local_2988._0_4_ = (double *)((ulonglong)local_2988 >> 0x20);
      local_2980._0_4_ = (undefined4 *)(local_2980 >> 0x20);
      local_2940 = ZEXT48(ppcVar8) << 0x20;
      local_2950._0_4_ = (undefined4 *)(uVar3 >> 0x20);
      if (local_2988._0_4_ == (double *)0x0) {
        pcVar23 = *(char **)(local_298c + -0x3814);
        unaff_s7 = puVar36;
        goto LAB_0044e3c8;
      }
      puVar13 = (undefined4 *)(*(code *)PTR_malloc_006aab64)((int)local_2988._0_4_ << 2);
      local_2938 = (double)(ZEXT48(ppcVar28) << 0x20);
      local_2948 = local_2980 & 0xffffffff00000000;
      local_2950 = ZEXT48(puVar13) << 0x20;
      local_2930 = (double)(uVar3 & 0xffffffff00000000);
      local_2980 = 0x63f1d400000000;
      iVar19 = 0;
      puVar36 = puVar13;
      goto LAB_00454138;
    }
LAB_0044e328:
    puVar31 = *ppcVar26;
    if ((int)ppcVar24 < 1) goto LAB_0044e524;
    iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"-elapsed");
    if (iVar19 == 0) {
      ppcVar28 = (char **)((int)ppcVar28 + -1);
      *(undefined4 *)(local_298c + -0x3814) = 0;
      goto LAB_0044e318;
    }
    iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,&DAT_0063eae4);
    if (iVar19 != 0) break;
    puVar31 = (undefined1 *)(ppcVar26 + 1);
    if (ppcVar24 == (char **)0x1) {
      local_290c = 1;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,"no EVP given\n");
      goto LAB_0044e580;
    }
    ppcVar8 = (char **)(*(code *)PTR_EVP_get_cipherbyname_006a8494)(ppcVar26[1]);
    if ((ppcVar8 == (char **)0x0) &&
       (local_2928 = (undefined1 *)(*(code *)PTR_EVP_get_digestbyname_006a802c)(ppcVar26[1]),
       (undefined4 *)local_2928 == (undefined4 *)0x0)) {
      local_290c = 1;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar5,"%s is an unknown cipher or digest\n",ppcVar26[1]);
      goto LAB_0044e580;
    }
    ppcVar24 = (char **)((int)ppcVar24 + -2);
    local_26c4 = 1;
    ppcVar26 = ppcVar26 + 2;
    uVar3 = local_2950;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"-decrypt");
  if (iVar19 == 0) {
    ppcVar28 = (char **)((int)ppcVar28 + -1);
    local_290c = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"-engine");
  if (iVar19 == 0) {
    ppcVar24 = (char **)((int)ppcVar24 + -1);
    puVar31 = (undefined1 *)(ppcVar26 + 1);
    if (ppcVar24 == (char **)0x0) {
      local_290c = 1;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,"no engine given\n");
      goto LAB_0044e580;
    }
    ppcVar28 = (char **)((int)ppcVar28 + -1);
    setup_engine(*(undefined4 *)puVar5,ppcVar26[1],0);
    ppcVar26 = (char **)puVar31;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"-multi");
  if (iVar19 == 0) {
    ppcVar24 = (char **)((int)ppcVar24 + -1);
    puVar31 = (undefined1 *)(ppcVar26 + 1);
    if (ppcVar24 == (char **)0x0) {
      local_290c = 1;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,"no multi count given\n");
      goto LAB_0044e580;
    }
    uVar15 = (*(code *)PTR_strtol_006aaa68)(ppcVar26[1],0,10);
    local_2988 = (ulonglong)uVar15 << 0x20;
    if ((int)uVar15 < 1) {
      local_290c = 1;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,"bad multi count\n");
      goto LAB_0044e580;
    }
    ppcVar28 = (char **)((int)ppcVar28 + -1);
    ppcVar26 = (char **)puVar31;
    goto LAB_0044e318;
  }
  if ((((*puVar31 == '-') && (*(char *)((int)puVar31 + 1) == 'm')) &&
      (*(char *)((int)puVar31 + 2) == 'r')) && (*(char *)((int)puVar31 + 3) == '\0')) {
    ppcVar28 = (char **)((int)ppcVar28 + -1);
    mr = 1;
    goto LAB_0044e318;
  }
LAB_0044e524:
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,puVar36);
  if (iVar19 == 0) {
    local_2718 = 1;
    goto LAB_0044e318;
  }
  local_2970 = (char **)(uint)(byte)*puVar31;
  if ((local_2970 == (char **)&DAT_0000006d) && (*(char *)((int)puVar31 + 1) == 'd')) {
    if ((*(char *)((int)puVar31 + 2) == '4') && (*(char *)((int)puVar31 + 3) == '\0')) {
      local_2714 = 1;
      goto LAB_0044e318;
    }
    if ((*(char *)((int)puVar31 + 2) == '5') && (*(char *)((int)puVar31 + 3) == '\0')) {
      local_2710 = 1;
      goto LAB_0044e318;
    }
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,unaff_s8);
  if (iVar19 == 0) {
    local_270c = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,(int)local_2948._0_4_ + -0x1e4c);
  if (iVar19 == 0) {
    local_2708 = 1;
    goto LAB_0044e318;
  }
  if ((((local_2970 == (char **)&DAT_00000073) && (*(char *)((int)puVar31 + 1) == 'h')) &&
      (*(char *)((int)puVar31 + 2) == 'a')) && (*(char *)((int)puVar31 + 3) == '\0')) {
    local_2708 = 1;
    local_26c0 = 1;
    local_26bc = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"sha256");
  if (iVar19 == 0) {
    local_26c0 = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"sha512");
  if (iVar19 == 0) {
    local_26bc = 1;
    goto LAB_0044e318;
  }
  local_2938 = 8.900295434028806e-307;
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"whirlpool");
  if (iVar19 == 0) {
    local_26b8 = 1;
    goto LAB_0044e318;
  }
  iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ripemd");
  if (iVar19 != 0) {
    local_2930 = 8.455280662327365e-307;
    iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"rmd160");
    if ((iVar19 != 0) && (iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"ripemd160"), iVar19 != 0)
       ) {
      local_2940 = (ulonglong)(0x72U - (int)local_2970) << 0x20;
      if (((0x72U - (int)local_2970 == 0) &&
          ((*(char *)((int)puVar31 + 1) == 'c' && (*(char *)((int)puVar31 + 2) == '4')))) &&
         (*(char *)((int)puVar31 + 3) == '\0')) {
        local_2700 = 1;
        goto LAB_0044e318;
      }
      iVar19 = (*(code *)PTR_strcmp_006aac20)(puVar31,"des-cbc");
      if (iVar19 == 0) {
        local_26fc = 1;
        goto LAB_0044e318;
      }
      goto LAB_0045639c;
    }
  }
  local_2704 = 1;
  goto LAB_0044e318;
LAB_00454138:
  iVar37 = (*(code *)PTR_pipe_006aaadc)(&local_17f4);
  puVar34 = (undefined4 *)PTR_stdout_006aaad4;
  if (iVar37 == -1) {
    uVar33 = *unaff_s7;
    uVar20 = 0xd;
    pcVar23 = "pipe failure\n";
LAB_00456248:
    (*(code *)PTR_fwrite_006aab7c)(pcVar23,1,uVar20,uVar33);
    iVar19 = (*(code *)PTR_exit_006aab4c)(1);
    return iVar19;
  }
  (*(code *)PTR_fflush_006aac0c)(*(undefined4 *)puVar16);
  (*(code *)PTR_fflush_006aac0c)(*unaff_s7);
  pcVar23 = (char *)(*(code *)PTR_fork_006aaac4)();
  local_2948._0_4_ = (undefined1 *)(local_2948 >> 0x20);
  local_2980._0_4_ = (undefined4 *)local_2948._0_4_;
  if (pcVar23 != (char *)0x0) goto LAB_004540f8;
  local_2930._0_4_ = (char *)((ulonglong)local_2930 >> 0x20);
  (*(code *)PTR_close_006aaa5c)(local_17f4);
  (*(code *)PTR_close_006aaa5c)(1);
  iVar19 = (*(code *)PTR_dup_006aac04)(local_17f0);
  if (iVar19 == -1) {
    uVar20 = 0xb;
    pcVar23 = "dup failed\n";
    uVar33 = *(undefined4 *)PTR_stderr_006aac00;
    goto LAB_00456248;
  }
  (*(code *)PTR_close_006aaa5c)(local_17f0);
  puVar16 = PTR_free_006aabf8;
  *(undefined4 *)(local_298c + -0x3814) = 0;
  mr = 1;
  (*(code *)puVar16)(puVar13);
  local_2950._0_4_ = (undefined4 *)local_2930._0_4_;
  local_2978 = pcVar23;
LAB_0044e3c8:
  puVar36 = unaff_s7;
  if (ppcVar28 == (char **)0x0) {
LAB_0044e3d0:
    piVar9 = local_2924;
    for (iVar19 = 1; (iVar19 == 0x17 || (*piVar9 = 1, iVar19 != 0x1e)); iVar19 = iVar19 + 1) {
      piVar9 = piVar9 + 1;
    }
    local_288c[0] = (char *)0x1;
    local_288c[1] = (char *)0x1;
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
    puVar36 = unaff_s7;
  }
  local_28ec = 0;
  piVar9 = local_2924;
  do {
    iVar19 = *piVar9;
    piVar9 = piVar9 + 1;
    local_28ec = local_28ec + (uint)(iVar19 != 0);
  } while (aiStack_26a4 != piVar9);
  if ((pcVar23 == (char *)0x0) && (mr == 0)) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar5,
               "You have chosen to measure elapsed time instead of user CPU time.\n");
  }
  local_2970 = local_289c;
  puVar31 = rsa_data_17821;
  puVar29 = rsa_data_length_17822;
  ppcVar8 = (char **)0x0;
  unaff_s8 = (char *)&local_28b8;
  do {
    local_28b8 = *(char **)puVar31;
    pcVar23 = (char *)(*(code *)PTR_d2i_RSAPrivateKey_006a8ad4)(0,unaff_s8,*(undefined4 *)puVar29);
    *local_2970 = pcVar23;
    if (pcVar23 == (char *)0x0) {
      local_290c = 1;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar5,"internal error loading RSA key number %d\n",ppcVar8);
      goto LAB_0044e580;
    }
    ppcVar8 = (char **)((int)ppcVar8 + 1);
    puVar31 = (undefined1 *)((int)puVar31 + 4);
    puVar29 = (undefined1 *)((int)puVar29 + 4);
    local_2970 = local_2970 + 1;
  } while (ppcVar8 != (char **)&SUB_00000004);
  local_28b4[0] = get_dsa512();
  local_28b4[1] = get_dsa1024();
  local_28b4[2] = get_dsa2048();
  (*(code *)PTR_DES_set_key_unchecked_006a8ad8)(&key_17804,auStack_2624);
  (*(code *)PTR_DES_set_key_unchecked_006a8ad8)(&key2_17805,auStack_25a4);
  (*(code *)PTR_DES_set_key_unchecked_006a8ad8)(&key3_17806,auStack_2524);
  (*(code *)PTR_AES_set_encrypt_key_006a8adc)(key16_17797,0x80,auStack_2278);
  (*(code *)PTR_AES_set_encrypt_key_006a8adc)(key24_17798,0xc0,auStack_2184);
  (*(code *)PTR_AES_set_encrypt_key_006a8adc)(key32_17799,0x100,auStack_2090);
  (*(code *)PTR_Camellia_set_key_006a8ae0)(key16_17797,0x80,auStack_1d98);
  (*(code *)PTR_Camellia_set_key_006a8ae0)(ckey24_17800,0xc0,auStack_1c80);
  (*(code *)PTR_Camellia_set_key_006a8ae0)(ckey32_17801,0x100,auStack_1b68);
  (*(code *)PTR_idea_set_encrypt_key_006a8ae4)(key16_17797,auStack_2350);
  (*(code *)PTR_SEED_set_key_006a8ae8)(key16_17797,aiStack_26a4);
  (*(code *)PTR_RC4_set_key_006a8aec)(auStack_1e9c,0x10,key16_17797);
  (*(code *)PTR_RC2_set_key_006a8af0)(auStack_1f9c,0x10,key16_17797,0x80);
  (*(code *)PTR_BF_set_key_006a8af4)(&local_17f4,0x10,key16_17797);
  (*(code *)PTR_CAST_set_key_006a8af8)(auStack_24a4,0x10,key16_17797);
  local_287c = 0;
  local_2878 = 0;
  local_2874 = 0;
  local_2870 = 0;
  local_286c = 0;
  local_2868 = 0;
  local_2864 = 0;
  local_2860 = 0;
  (*(code *)PTR_signal_006aabe0)(0xe,sig_done);
  if (local_2718 != 0) {
    iVar19 = 0x10;
    local_2930 = 8.890625923608535e-307;
    local_28e0 = "+DT:%s:%d:%d\n";
    local_28fc = "Doing %s for %ds on %d size blocks: ";
    uVar20 = *(undefined4 *)puVar5;
    puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
    pdVar30 = (double *)(results + 0x28);
    do {
      pcVar23 = local_28fc;
      if (mr != 0) {
        pcVar23 = local_28e0;
      }
      iVar37 = 0;
      PTR_bio_err_006a7f3c = (undefined *)puVar36;
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,pcVar23,names._4_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*puVar36,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        iVar37 = iVar37 + 1;
        uVar20 = (*(code *)PTR_EVP_mdc2_006a8b00)();
        (*(code *)PTR_EVP_Digest_006a8b04)(local_2980._0_4_,iVar19,auStack_7a4,0,uVar20,0);
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._4_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 0x50)) goto LAB_0044ec2c;
      local_2930._0_4_ = (char *)((ulonglong)local_2930 >> 0x20);
      iVar19 = *(int *)local_2930._0_4_;
      local_2930 = (double)(ZEXT48((int *)((int)local_2930._0_4_ + 4)) << 0x20);
      uVar20 = *(undefined4 *)puVar5;
      puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
      pdVar30 = pdVar30 + 1;
    } while( true );
  }
  iVar37 = 0;
  dVar39 = 0.0;
LAB_0044ec2c:
  if (local_2714 != 0) {
    iVar19 = 0x10;
    local_2930 = 8.890625923608535e-307;
    uVar20 = *(undefined4 *)puVar5;
    local_28e0 = "+DT:%s:%d:%d\n";
    local_28fc = "Doing %s for %ds on %d size blocks: ";
    puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
    pdVar30 = (double *)(results + 0x50);
    do {
      pcVar23 = local_28fc;
      if (mr != 0) {
        pcVar23 = local_28e0;
      }
      iVar37 = 0;
      PTR_bio_err_006a7f3c = (undefined *)puVar36;
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,pcVar23,names._8_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*puVar36,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        iVar37 = iVar37 + 1;
        uVar20 = (*(code *)PTR_EVP_md4_006a8b08)();
        (*(code *)PTR_EVP_Digest_006a8b04)(local_2980._0_4_,iVar19,auStack_794,0,uVar20,0);
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._8_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 0x78)) break;
      local_2930._0_4_ = (char *)((ulonglong)local_2930 >> 0x20);
      iVar19 = *(int *)local_2930._0_4_;
      local_2930 = (double)(ZEXT48((int *)((int)local_2930._0_4_ + 4)) << 0x20);
      uVar20 = *(undefined4 *)puVar5;
      puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
      pdVar30 = pdVar30 + 1;
    } while( true );
  }
  if (local_2710 != 0) {
    iVar19 = 0x10;
    local_2930 = 8.890625923608535e-307;
    uVar20 = *(undefined4 *)puVar5;
    local_28c4 = "+DT:%s:%d:%d\n";
    local_28e4 = "Doing %s for %ds on %d size blocks: ";
    puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
    pdVar30 = (double *)(results + 0x78);
    do {
      pcVar23 = local_28e4;
      if (mr != 0) {
        pcVar23 = local_28c4;
      }
      iVar37 = 0;
      PTR_bio_err_006a7f3c = (undefined *)puVar36;
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,pcVar23,names._12_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*puVar36,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        iVar37 = iVar37 + 1;
        uVar20 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(&DAT_00632570);
        (*(code *)PTR_EVP_Digest_006a8b04)(local_2980._0_4_,iVar19,auStack_784,0,uVar20,0);
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._12_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 0xa0)) break;
      local_2930._0_4_ = (char *)((ulonglong)local_2930 >> 0x20);
      iVar19 = *(int *)local_2930._0_4_;
      local_2930 = (double)(ZEXT48((int *)((int)local_2930._0_4_ + 4)) << 0x20);
      uVar20 = *(undefined4 *)puVar5;
      puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
      pdVar30 = pdVar30 + 1;
    } while( true );
  }
  if (local_270c != 0) {
    (*(code *)PTR_HMAC_CTX_init_006a8b0c)(auStack_2420);
    uVar20 = (*(code *)PTR_EVP_md5_006a81c8)();
    (*(code *)PTR_HMAC_Init_ex_006a8ba0)(auStack_2420,"This is a key...",0x10,uVar20,0);
    local_2900 = lengths + 4;
    iVar19 = 0x10;
    local_28c4 = "+DT:%s:%d:%d\n";
    local_28e4 = "Doing %s for %ds on %d size blocks: ";
    pdVar30 = (double *)(results + 0xa0);
    do {
      puVar16 = PTR_bio_err_006a7f3c;
      pcVar23 = local_28c4;
      if (mr == 0) {
        pcVar23 = local_28e4;
      }
      iVar37 = 0;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,names._16_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar16,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_HMAC_Init_ex_006a8ba0)(auStack_2420,0,0,0,0);
        iVar37 = iVar37 + 1;
        (*(code *)PTR_HMAC_Update_006a8ba4)(auStack_2420,local_2980._0_4_,iVar19);
        (*(code *)PTR_HMAC_Final_006a8ba8)(auStack_2420,auStack_774,0);
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._16_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 200)) goto LAB_004547c0;
      iVar19 = *(int *)local_2900;
      local_2900 = (char *)((int)local_2900 + 4);
      pdVar30 = pdVar30 + 1;
    } while( true );
  }
LAB_0044f048:
  if (local_2708 != 0) {
    iVar19 = 0x10;
    local_2930 = 8.890625923608535e-307;
    uVar20 = *(undefined4 *)puVar5;
    local_28e0 = "+DT:%s:%d:%d\n";
    local_28fc = "Doing %s for %ds on %d size blocks: ";
    puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
    pdVar30 = (double *)(results + 200);
    do {
      pcVar23 = local_28fc;
      if (mr != 0) {
        pcVar23 = local_28e0;
      }
      iVar37 = 0;
      PTR_bio_err_006a7f3c = (undefined *)puVar36;
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,pcVar23,names._20_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*puVar36,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        iVar37 = iVar37 + 1;
        uVar20 = (*(code *)PTR_EVP_sha1_006a86c4)();
        (*(code *)PTR_EVP_Digest_006a8b04)(local_2980._0_4_,iVar19,auStack_764,0,uVar20,0);
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._20_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 0xf0)) break;
      local_2930._0_4_ = (char *)((ulonglong)local_2930 >> 0x20);
      iVar19 = *(int *)local_2930._0_4_;
      local_2930 = (double)(ZEXT48((int *)((int)local_2930._0_4_ + 4)) << 0x20);
      uVar20 = *(undefined4 *)puVar5;
      puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
      pdVar30 = pdVar30 + 1;
    } while( true );
  }
  if (local_26c0 != 0) {
    iVar19 = 0x10;
    local_2930 = 8.890625923608535e-307;
    uVar20 = *(undefined4 *)puVar5;
    local_28e0 = "+DT:%s:%d:%d\n";
    local_28fc = "Doing %s for %ds on %d size blocks: ";
    puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
    pdVar30 = (double *)(results + 0x398);
    do {
      pcVar23 = local_28fc;
      if (mr != 0) {
        pcVar23 = local_28e0;
      }
      iVar37 = 0;
      PTR_bio_err_006a7f3c = (undefined *)puVar36;
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,pcVar23,names._92_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*puVar36,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_SHA256_006a8b10)(local_2980._0_4_,iVar19,auStack_73c);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._92_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 0x3c0)) break;
      local_2930._0_4_ = (char *)((ulonglong)local_2930 >> 0x20);
      iVar19 = *(int *)local_2930._0_4_;
      local_2930 = (double)(ZEXT48((int *)((int)local_2930._0_4_ + 4)) << 0x20);
      uVar20 = *(undefined4 *)puVar5;
      puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
      pdVar30 = pdVar30 + 1;
    } while( true );
  }
  if (local_26bc != 0) {
    iVar19 = 0x10;
    local_2930 = 8.890625923608535e-307;
    uVar20 = *(undefined4 *)puVar5;
    local_28e0 = "+DT:%s:%d:%d\n";
    local_28fc = "Doing %s for %ds on %d size blocks: ";
    puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
    pdVar30 = (double *)(results + 0x3c0);
    do {
      pcVar23 = local_28fc;
      if (mr != 0) {
        pcVar23 = local_28e0;
      }
      iVar37 = 0;
      PTR_bio_err_006a7f3c = (undefined *)puVar36;
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,pcVar23,names._96_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*puVar36,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_SHA512_006a8b14)(local_2980._0_4_,iVar19,auStack_6bc);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._96_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 1000)) break;
      local_2930._0_4_ = (char *)((ulonglong)local_2930 >> 0x20);
      iVar19 = *(int *)local_2930._0_4_;
      local_2930 = (double)(ZEXT48((int *)((int)local_2930._0_4_ + 4)) << 0x20);
      uVar20 = *(undefined4 *)puVar5;
      puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
      pdVar30 = pdVar30 + 1;
    } while( true );
  }
  if (local_26b8 != 0) {
    iVar19 = 0x10;
    local_2930 = 8.890625923608535e-307;
    uVar20 = *(undefined4 *)puVar5;
    local_28e0 = "+DT:%s:%d:%d\n";
    local_28fc = "Doing %s for %ds on %d size blocks: ";
    puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
    pdVar30 = (double *)(results + 1000);
    do {
      pcVar23 = local_28fc;
      if (mr != 0) {
        pcVar23 = local_28e0;
      }
      iVar37 = 0;
      PTR_bio_err_006a7f3c = (undefined *)puVar36;
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,pcVar23,names._100_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*puVar36,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_WHIRLPOOL_006a8b18)(local_2980._0_4_,iVar19,auStack_67c);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._100_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 0x410)) break;
      local_2930._0_4_ = (char *)((ulonglong)local_2930 >> 0x20);
      iVar19 = *(int *)local_2930._0_4_;
      local_2930 = (double)(ZEXT48((int *)((int)local_2930._0_4_ + 4)) << 0x20);
      uVar20 = *(undefined4 *)puVar5;
      puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
      pdVar30 = pdVar30 + 1;
    } while( true );
  }
  if (local_2704 != 0) {
    iVar19 = 0x10;
    local_2930 = 8.890625923608535e-307;
    uVar20 = *(undefined4 *)puVar5;
    local_28e0 = "+DT:%s:%d:%d\n";
    local_28fc = "Doing %s for %ds on %d size blocks: ";
    puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
    pdVar30 = (double *)(results + 0xf0);
    do {
      pcVar23 = local_28fc;
      if (mr != 0) {
        pcVar23 = local_28e0;
      }
      iVar37 = 0;
      PTR_bio_err_006a7f3c = (undefined *)puVar36;
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,pcVar23,names._24_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*puVar36,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        iVar37 = iVar37 + 1;
        uVar20 = (*(code *)PTR_EVP_ripemd160_006a8b1c)();
        (*(code *)PTR_EVP_Digest_006a8b04)(local_2980._0_4_,iVar19,auStack_750,0,uVar20,0);
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._24_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 0x118)) break;
      local_2930._0_4_ = (char *)((ulonglong)local_2930 >> 0x20);
      iVar19 = *(int *)local_2930._0_4_;
      local_2930 = (double)(ZEXT48((int *)((int)local_2930._0_4_ + 4)) << 0x20);
      uVar20 = *(undefined4 *)puVar5;
      puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
      pdVar30 = pdVar30 + 1;
    } while( true );
  }
  if (local_2700 != 0) {
    iVar19 = 0x10;
    local_2930 = 1.188725066132418e-306;
    uVar20 = *(undefined4 *)puVar5;
    local_28e4 = "+DT:%s:%d:%d\n";
    local_2900 = "Doing %s for %ds on %d size blocks: ";
    pdVar30 = (double *)(results + 0x118);
    puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
    piVar9 = (int *)(lengths + 4);
    do {
      pcVar23 = local_2900;
      if (mr != 0) {
        pcVar23 = local_28e4;
      }
      iVar37 = 0;
      PTR_bio_err_006a7f3c = (undefined *)puVar36;
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,pcVar23,names._28_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*puVar36,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_RC4_006a8b20)(auStack_1e9c,iVar19,local_2980._0_4_,local_2980._0_4_);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._28_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 0x140)) break;
      iVar19 = *piVar9;
      uVar20 = *(undefined4 *)puVar5;
      pdVar30 = pdVar30 + 1;
      puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
      piVar9 = piVar9 + 1;
    } while( true );
  }
  if (local_26fc != 0) {
    puVar31 = lengths;
    local_28e4 = "+DT:%s:%d:%d\n";
    local_2900 = "Doing %s for %ds on %d size blocks: ";
    pdVar30 = (double *)(results + 0x140);
    do {
      puVar16 = PTR_bio_err_006a7f3c;
      iVar19 = *(int *)puVar31;
      pcVar23 = local_28e4;
      if (mr == 0) {
        pcVar23 = local_2900;
      }
      iVar37 = 0;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,names._32_4_,3,iVar19);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar16,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_DES_ncbc_encrypt_006a8b24)
                  (local_2980._0_4_,local_2980._0_4_,iVar19,auStack_2624,local_2958._0_4_,1);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._32_4_,dVar39);
      puVar31 = (undefined1 *)((int)puVar31 + 4);
      pdVar25 = pdVar30 + 1;
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      local_2930 = dVar39;
      pdVar30 = pdVar25;
    } while (pdVar25 != (double *)(results + 0x168));
  }
  if (local_26f8 != 0) {
    puVar31 = lengths;
    local_28e0 = "+DT:%s:%d:%d\n";
    local_28fc = "Doing %s for %ds on %d size blocks: ";
    pdVar30 = (double *)(results + 0x168);
    do {
      puVar16 = PTR_bio_err_006a7f3c;
      iVar19 = *(int *)puVar31;
      pcVar23 = local_28e0;
      if (mr == 0) {
        pcVar23 = local_28fc;
      }
      iVar37 = 0;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,names._36_4_,3,iVar19);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar16,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        iVar37 = iVar37 + 1;
        (*(code *)PTR_DES_ede3_cbc_encrypt_006a8b28)
                  (local_2980._0_4_,local_2980._0_4_,iVar19,auStack_2624,auStack_25a4,auStack_2524,
                   local_2958._0_4_,1);
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._36_4_,dVar39);
      puVar31 = (undefined1 *)((int)puVar31 + 4);
      pdVar25 = pdVar30 + 1;
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      local_2930 = dVar39;
      pdVar30 = pdVar25;
    } while (pdVar25 != (double *)(results + 400));
  }
  if (local_26dc != 0) {
    iVar19 = 0x10;
    uVar20 = *(undefined4 *)puVar5;
    local_2920 = "+DT:%s:%d:%d\n";
    local_2930 = 8.900295434028806e-307;
    puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
    pdVar30 = (double *)(results + 0x280);
    piVar9 = (int *)(lengths + 4);
    do {
      local_2938._0_4_ = local_2920;
      if (mr == 0) {
        local_2938._0_4_ = "Doing %s for %ds on %d size blocks: ";
      }
      iVar37 = 0;
      PTR_bio_err_006a7f3c = (undefined *)puVar36;
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,local_2938._0_4_,names._64_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*puVar36,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_AES_cbc_encrypt_006a8b2c)
                  (local_2980._0_4_,local_2980._0_4_,iVar19,auStack_2278,local_2950._0_4_,1);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._64_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 0x2a8)) break;
      iVar19 = *piVar9;
      uVar20 = *(undefined4 *)puVar5;
      puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
      pdVar30 = pdVar30 + 1;
      piVar9 = piVar9 + 1;
    } while( true );
  }
  if (local_26d8 != 0) {
    iVar19 = 0x10;
    uVar20 = *(undefined4 *)puVar5;
    local_2920 = "+DT:%s:%d:%d\n";
    local_2930 = 8.900295434028806e-307;
    puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
    pdVar30 = (double *)(results + 0x2a8);
    piVar9 = (int *)(lengths + 4);
    do {
      local_2938._0_4_ = local_2920;
      if (mr == 0) {
        local_2938._0_4_ = "Doing %s for %ds on %d size blocks: ";
      }
      iVar37 = 0;
      PTR_bio_err_006a7f3c = (undefined *)puVar36;
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,local_2938._0_4_,names._68_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*puVar36,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_AES_cbc_encrypt_006a8b2c)
                  (local_2980._0_4_,local_2980._0_4_,iVar19,auStack_2184,local_2950._0_4_,1);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._68_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 0x2d0)) break;
      iVar19 = *piVar9;
      uVar20 = *(undefined4 *)puVar5;
      puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
      pdVar30 = pdVar30 + 1;
      piVar9 = piVar9 + 1;
    } while( true );
  }
  if (local_26d4 != 0) {
    iVar19 = 0x10;
    uVar20 = *(undefined4 *)puVar5;
    local_2920 = "+DT:%s:%d:%d\n";
    local_2930 = 8.900295434028806e-307;
    puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
    pdVar30 = (double *)(results + 0x2d0);
    piVar9 = (int *)(lengths + 4);
    do {
      local_2938._0_4_ = local_2920;
      if (mr == 0) {
        local_2938._0_4_ = "Doing %s for %ds on %d size blocks: ";
      }
      iVar37 = 0;
      PTR_bio_err_006a7f3c = (undefined *)puVar36;
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,local_2938._0_4_,names._72_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*puVar36,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_AES_cbc_encrypt_006a8b2c)
                  (local_2980._0_4_,local_2980._0_4_,iVar19,auStack_2090,local_2950._0_4_,1);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._72_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 0x2f8)) break;
      iVar19 = *piVar9;
      uVar20 = *(undefined4 *)puVar5;
      puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
      pdVar30 = pdVar30 + 1;
      piVar9 = piVar9 + 1;
    } while( true );
  }
  if (local_26b4 != 0) {
    iVar19 = 0x10;
    uVar20 = *(undefined4 *)puVar5;
    local_2910 = "+DT:%s:%d:%d\n";
    local_2930 = 8.877588381468844e-307;
    puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
    pdVar30 = (double *)(results + 0x410);
    piVar9 = (int *)(lengths + 4);
    do {
      local_2930._0_4_ = local_2910;
      if (mr == 0) {
        local_2930._0_4_ = "Doing %s for %ds on %d size blocks: ";
      }
      iVar37 = 0;
      PTR_bio_err_006a7f3c = (undefined *)puVar36;
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,local_2930._0_4_,names._104_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*puVar36,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_AES_ige_encrypt_006a8b30)
                  (local_2980._0_4_,local_295c,iVar19,auStack_2278,local_2950._0_4_,1);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._104_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 0x438)) break;
      iVar19 = *piVar9;
      uVar20 = *(undefined4 *)puVar5;
      puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
      pdVar30 = pdVar30 + 1;
      piVar9 = piVar9 + 1;
    } while( true );
  }
  if (local_26b0 != 0) {
    iVar19 = 0x10;
    uVar20 = *(undefined4 *)puVar5;
    local_2910 = "+DT:%s:%d:%d\n";
    local_2930 = 8.877588381468844e-307;
    puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
    pdVar30 = (double *)(results + 0x438);
    piVar9 = (int *)(lengths + 4);
    do {
      local_2930._0_4_ = local_2910;
      if (mr == 0) {
        local_2930._0_4_ = "Doing %s for %ds on %d size blocks: ";
      }
      iVar37 = 0;
      PTR_bio_err_006a7f3c = (undefined *)puVar36;
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,local_2930._0_4_,names._108_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*puVar36,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_AES_ige_encrypt_006a8b30)
                  (local_2980._0_4_,local_295c,iVar19,auStack_2184,local_2950._0_4_,1);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._108_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 0x460)) break;
      iVar19 = *piVar9;
      uVar20 = *(undefined4 *)puVar5;
      puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
      pdVar30 = pdVar30 + 1;
      piVar9 = piVar9 + 1;
    } while( true );
  }
  if (local_26ac != 0) {
    iVar19 = 0x10;
    uVar20 = *(undefined4 *)puVar5;
    local_2918 = "+DT:%s:%d:%d\n";
    local_2930 = 8.877588381468844e-307;
    puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
    pdVar30 = (double *)(results + 0x460);
    piVar9 = (int *)(lengths + 4);
    do {
      local_2930._0_4_ = local_2918;
      if (mr == 0) {
        local_2930._0_4_ = "Doing %s for %ds on %d size blocks: ";
      }
      iVar37 = 0;
      PTR_bio_err_006a7f3c = (undefined *)puVar36;
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,local_2930._0_4_,names._112_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*puVar36,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_AES_ige_encrypt_006a8b30)
                  (local_2980._0_4_,local_295c,iVar19,auStack_2090,local_2950._0_4_,1);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._112_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 0x488)) break;
      iVar19 = *piVar9;
      uVar20 = *(undefined4 *)puVar5;
      puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
      pdVar30 = pdVar30 + 1;
      piVar9 = piVar9 + 1;
    } while( true );
  }
  if (local_26a8 != 0) {
    iVar19 = 0x10;
    uVar20 = (*(code *)PTR_CRYPTO_gcm128_new_006a8b34)(auStack_2278,PTR_AES_encrypt_006a8b90);
    (*(code *)PTR_CRYPTO_gcm128_setiv_006a8b94)(uVar20,"0123456789ab",0xc);
    local_2988._0_4_ = (double *)(results + 0x488);
    local_2920 = "+DT:%s:%d:%d\n";
    local_2930 = 8.900295434028806e-307;
    piVar9 = (int *)(lengths + 4);
    do {
      puVar16 = PTR_bio_err_006a7f3c;
      local_2938._0_4_ = local_2920;
      if (mr == 0) {
        local_2938._0_4_ = "Doing %s for %ds on %d size blocks: ";
      }
      iVar37 = 0;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar5,local_2938._0_4_,names._116_4_,3,iVar19);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar16,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_CRYPTO_gcm128_aad_006a8b98)(uVar20,local_2980._0_4_,iVar19);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._116_4_,dVar39);
      *local_2988._0_4_ = ((double)iVar37 / dVar39) * (double)iVar19;
      if (local_2988._0_4_ + 1 == (double *)&mr) goto LAB_00454534;
      iVar19 = *piVar9;
      local_2988._0_4_ = local_2988._0_4_ + 1;
      piVar9 = piVar9 + 1;
    } while( true );
  }
LAB_00450c20:
  if (local_26d0 != 0) {
    iVar19 = 0x10;
    uVar20 = *(undefined4 *)puVar5;
    local_2920 = "+DT:%s:%d:%d\n";
    local_2930 = 8.900295434028806e-307;
    puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
    pdVar30 = (double *)(results + 0x2f8);
    piVar9 = (int *)(lengths + 4);
    do {
      local_2938._0_4_ = local_2920;
      if (mr == 0) {
        local_2938._0_4_ = "Doing %s for %ds on %d size blocks: ";
      }
      iVar37 = 0;
      PTR_bio_err_006a7f3c = (undefined *)puVar36;
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,local_2938._0_4_,names._76_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*puVar36,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_Camellia_cbc_encrypt_006a8b38)
                  (local_2980._0_4_,local_2980._0_4_,iVar19,auStack_1d98,local_2950._0_4_,1);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._76_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 800)) break;
      iVar19 = *piVar9;
      uVar20 = *(undefined4 *)puVar5;
      puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
      pdVar30 = pdVar30 + 1;
      piVar9 = piVar9 + 1;
    } while( true );
  }
  if (local_26cc != 0) {
    iVar19 = 0x10;
    uVar20 = *(undefined4 *)puVar5;
    local_2920 = "+DT:%s:%d:%d\n";
    local_2930 = 8.900295434028806e-307;
    puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
    pdVar30 = (double *)(results + 800);
    piVar9 = (int *)(lengths + 4);
    do {
      local_2938._0_4_ = local_2920;
      if (mr == 0) {
        local_2938._0_4_ = "Doing %s for %ds on %d size blocks: ";
      }
      iVar37 = 0;
      PTR_bio_err_006a7f3c = (undefined *)puVar36;
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,local_2938._0_4_,names._80_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*puVar36,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_Camellia_cbc_encrypt_006a8b38)
                  (local_2980._0_4_,local_2980._0_4_,iVar19,auStack_1c80,local_2950._0_4_,1);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._80_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 0x348)) break;
      iVar19 = *piVar9;
      uVar20 = *(undefined4 *)puVar5;
      puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
      pdVar30 = pdVar30 + 1;
      piVar9 = piVar9 + 1;
    } while( true );
  }
  if (local_26c8 != 0) {
    iVar19 = 0x10;
    uVar20 = *(undefined4 *)puVar5;
    local_2920 = "+DT:%s:%d:%d\n";
    local_2930 = 8.900295434028806e-307;
    puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
    pdVar30 = (double *)(results + 0x348);
    piVar9 = (int *)(lengths + 4);
    do {
      local_2938._0_4_ = local_2920;
      if (mr == 0) {
        local_2938._0_4_ = "Doing %s for %ds on %d size blocks: ";
      }
      iVar37 = 0;
      PTR_bio_err_006a7f3c = (undefined *)puVar36;
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,local_2938._0_4_,names._84_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*puVar36,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_Camellia_cbc_encrypt_006a8b38)
                  (local_2980._0_4_,local_2980._0_4_,iVar19,auStack_1b68,local_2950._0_4_,1);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._84_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 0x370)) break;
      iVar19 = *piVar9;
      uVar20 = *(undefined4 *)puVar5;
      puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
      pdVar30 = pdVar30 + 1;
      piVar9 = piVar9 + 1;
    } while( true );
  }
  if (local_26f4 != 0) {
    puVar31 = lengths;
    local_2920 = "+DT:%s:%d:%d\n";
    local_2930 = 8.900295434028806e-307;
    pdVar30 = (double *)(results + 400);
    do {
      puVar16 = PTR_bio_err_006a7f3c;
      iVar19 = *(int *)puVar31;
      local_2938._0_4_ = local_2920;
      if (mr == 0) {
        local_2938._0_4_ = "Doing %s for %ds on %d size blocks: ";
      }
      iVar37 = 0;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar5,local_2938._0_4_,names._40_4_,3,iVar19);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar16,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_idea_cbc_encrypt_006a8b3c)
                  (local_2980._0_4_,local_2980._0_4_,iVar19,auStack_2350,local_2950._0_4_,1);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._40_4_,dVar39);
      puVar31 = (undefined1 *)((int)puVar31 + 4);
      pdVar25 = pdVar30 + 1;
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      pdVar30 = pdVar25;
    } while (pdVar25 != (double *)(results + 0x1b8));
  }
  if (local_26f0 != 0) {
    iVar19 = 0x10;
    uVar20 = *(undefined4 *)puVar5;
    local_2920 = "+DT:%s:%d:%d\n";
    local_2930 = 8.900295434028806e-307;
    puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
    pdVar30 = (double *)(results + 0x1b8);
    piVar9 = (int *)(lengths + 4);
    do {
      local_2938._0_4_ = local_2920;
      if (mr == 0) {
        local_2938._0_4_ = "Doing %s for %ds on %d size blocks: ";
      }
      iVar37 = 0;
      PTR_bio_err_006a7f3c = (undefined *)puVar36;
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,local_2938._0_4_,names._44_4_,3);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*puVar36,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_SEED_cbc_encrypt_006a8b40)
                  (local_2980._0_4_,local_2980._0_4_,iVar19,aiStack_26a4,local_2950._0_4_,1);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._44_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 0x1e0)) break;
      iVar19 = *piVar9;
      uVar20 = *(undefined4 *)puVar5;
      puVar36 = (undefined4 *)PTR_bio_err_006a7f3c;
      pdVar30 = pdVar30 + 1;
      piVar9 = piVar9 + 1;
    } while( true );
  }
  if (local_26ec != 0) {
    puVar31 = lengths;
    local_2920 = "+DT:%s:%d:%d\n";
    local_2930 = 8.900295434028806e-307;
    pdVar30 = (double *)(results + 0x1e0);
    do {
      puVar16 = PTR_bio_err_006a7f3c;
      iVar19 = *(int *)puVar31;
      local_2938._0_4_ = local_2920;
      if (mr == 0) {
        local_2938._0_4_ = "Doing %s for %ds on %d size blocks: ";
      }
      iVar37 = 0;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar5,local_2938._0_4_,names._48_4_,3,iVar19);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar16,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_RC2_cbc_encrypt_006a8b44)
                  (local_2980._0_4_,local_2980._0_4_,iVar19,auStack_1f9c,local_2950._0_4_,1);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._48_4_,dVar39);
      puVar31 = (undefined1 *)((int)puVar31 + 4);
      pdVar25 = pdVar30 + 1;
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      pdVar30 = pdVar25;
    } while (pdVar25 != (double *)(results + 0x208));
  }
  if (local_26e4 != 0) {
    puVar31 = lengths;
    local_2920 = "+DT:%s:%d:%d\n";
    local_2930 = 8.900295434028806e-307;
    pdVar30 = (double *)(results + 0x230);
    do {
      puVar16 = PTR_bio_err_006a7f3c;
      iVar19 = *(int *)puVar31;
      local_2938._0_4_ = local_2920;
      if (mr == 0) {
        local_2938._0_4_ = "Doing %s for %ds on %d size blocks: ";
      }
      iVar37 = 0;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar5,local_2938._0_4_,names._56_4_,3,iVar19);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar16,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_BF_cbc_encrypt_006a8b48)
                  (local_2980._0_4_,local_2980._0_4_,iVar19,&local_17f4,local_2950._0_4_,1);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._56_4_,dVar39);
      puVar31 = (undefined1 *)((int)puVar31 + 4);
      pdVar25 = pdVar30 + 1;
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      pdVar30 = pdVar25;
    } while (pdVar25 != (double *)(results + 600));
  }
  if (local_26e0 != 0) {
    puVar31 = lengths;
    local_2920 = "+DT:%s:%d:%d\n";
    local_2930 = 8.900295434028806e-307;
    pdVar30 = (double *)(results + 600);
    do {
      puVar16 = PTR_bio_err_006a7f3c;
      iVar19 = *(int *)puVar31;
      local_2938._0_4_ = local_2920;
      if (mr == 0) {
        local_2938._0_4_ = "Doing %s for %ds on %d size blocks: ";
      }
      iVar37 = 0;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar5,local_2938._0_4_,names._60_4_,3,iVar19);
      (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar16,0xb,0,0);
      (*(code *)PTR_alarm_006aabc8)(3);
      app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
      run = 1;
      do {
        (*(code *)PTR_CAST_cbc_encrypt_006a8b4c)
                  (local_2980._0_4_,local_2980._0_4_,iVar19,auStack_24a4,local_2950._0_4_,1);
        iVar37 = iVar37 + 1;
        if (run == 0) break;
      } while (iVar37 != 0x7fffffff);
      dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._60_4_,dVar39);
      puVar31 = (undefined1 *)((int)puVar31 + 4);
      pdVar25 = pdVar30 + 1;
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      pdVar30 = pdVar25;
    } while (pdVar25 != (double *)(results + 0x280));
  }
  if (local_26c4 != 0) {
    iVar19 = 0x10;
    local_2930 = 8.885247937475913e-307;
    pdVar30 = (double *)(results + 0x370);
    piVar9 = (int *)(lengths + 4);
    do {
      puVar16 = PTR_bio_err_006a7f3c;
      if (local_2940._0_4_ != (undefined4 *)0x0) {
        names._88_4_ = (*(code *)PTR_OBJ_nid2ln_006a821c)(*local_2940._0_4_);
        if (mr == 0) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar5,"Doing %s for %ds on %d size blocks: ",names._88_4_,3,
                     iVar19);
          (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar16,0xb,0,0);
          (*(code *)PTR_alarm_006aabc8)(3);
          (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(auStack_2420);
          if (local_290c != 0) goto LAB_00451c48;
LAB_004533cc:
          iVar37 = 0;
          (*(code *)PTR_EVP_EncryptInit_ex_006a8b84)
                    (auStack_2420,local_2940._0_4_,0,key16_17797,local_2950._0_4_);
          (*(code *)PTR_EVP_CIPHER_CTX_set_padding_006a8650)(auStack_2420,0);
          app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
          run = 1;
          do {
            (*(code *)PTR_EVP_EncryptUpdate_006a8b8c)
                      (auStack_2420,local_2980._0_4_,unaff_s8,local_2980._0_4_,iVar19);
            iVar37 = iVar37 + 1;
            pcVar35 = (code *)PTR_EVP_EncryptFinal_ex_006a8b88;
            if (run == 0) break;
            pcVar35 = (code *)PTR_EVP_EncryptFinal_ex_006a8b88;
          } while (iVar37 != 0x7fffffff);
        }
        else {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar5,"+DT:%s:%d:%d\n",names._88_4_,3,iVar19);
          (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar16,0xb,0,0);
          (*(code *)PTR_alarm_006aabc8)(3);
          (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(auStack_2420);
          if (local_290c == 0) goto LAB_004533cc;
LAB_00451c48:
          (*(code *)PTR_EVP_DecryptInit_ex_006a8b54)(auStack_2420,local_2940._0_4_,0,key16_17797);
          iVar37 = 0;
          (*(code *)PTR_EVP_CIPHER_CTX_set_padding_006a8650)(auStack_2420,0);
          app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
          run = 1;
          do {
            (*(code *)PTR_EVP_DecryptUpdate_006a8b5c)
                      (auStack_2420,local_2980._0_4_,unaff_s8,local_2980._0_4_,iVar19);
            iVar37 = iVar37 + 1;
            pcVar35 = (code *)PTR_EVP_DecryptFinal_ex_006a8b58;
            if (run == 0) break;
          } while (iVar37 != 0x7fffffff);
        }
        (*pcVar35)(auStack_2420,local_2980._0_4_,unaff_s8);
        dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
        (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_2420);
      }
      puVar16 = PTR_bio_err_006a7f3c;
      if ((undefined4 *)local_2928 != (undefined4 *)0x0) {
        names._88_4_ = (*(code *)PTR_OBJ_nid2ln_006a821c)(*(undefined4 *)local_2928);
        if (mr == 0) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar5,"Doing %s for %ds on %d size blocks: ",names._88_4_,3,
                     iVar19);
          (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar16,0xb,0,0);
          (*(code *)PTR_alarm_006aabc8)(3);
          app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
        }
        else {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar5,"+DT:%s:%d:%d\n",names._88_4_,3,iVar19);
          (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar16,0xb,0,0);
          (*(code *)PTR_alarm_006aabc8)(3);
          app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
        }
        run = 1;
        iVar37 = 0;
        do {
          (*(code *)PTR_EVP_Digest_006a8b04)(local_2980._0_4_,iVar19,auStack_6fc,0,local_2928,0);
          iVar37 = iVar37 + 1;
          if (run == 0) break;
        } while (iVar37 != 0x7fffffff);
        dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
      }
      if (mr == 0) {
        pcVar23 = "%d %s\'s in %.2fs\n";
      }
      else {
        pcVar23 = "+R:%d:%s:%f\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,names._88_4_,dVar39);
      *pdVar30 = ((double)iVar37 / dVar39) * (double)iVar19;
      if (pdVar30 + 1 == (double *)(results + 0x398)) break;
      iVar19 = *piVar9;
      pdVar30 = pdVar30 + 1;
      piVar9 = piVar9 + 1;
    } while( true );
  }
  iVar19 = 0;
  (*(code *)PTR_RAND_pseudo_bytes_006a8664)(local_2980._0_4_,0x24);
  local_2980 = 0x6b000000000000;
  do {
    iVar37 = iVar19;
    if (local_288c[iVar19] != (char *)0x0) {
      pcVar23 = local_289c[iVar19];
      iVar10 = (*(code *)PTR_RSA_sign_006a8b64)
                         (0x72,local_2980._0_4_,0x24,local_295c,&local_28bc,pcVar23);
      puVar16 = PTR_bio_err_006a7f3c;
      if (iVar10 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar5,"RSA sign failure.  No RSA sign will be done.\n");
        iVar10 = 1;
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar5);
      }
      else {
        uVar20 = *(undefined4 *)(rsa_bits_17820 + iVar19 * 4);
        if (mr == 0) {
          pcVar21 = "Doing %d bit %s %s\'s for %ds: ";
        }
        else {
          pcVar21 = "+DTP:%d:%s:%s:%d\n";
        }
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar21,uVar20,"private","rsa",10);
        iVar10 = 0;
        (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar16,0xb,0,0);
        (*(code *)PTR_alarm_006aabc8)(10);
        app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
        run = 1;
        while (iVar11 = (*(code *)PTR_RSA_sign_006a8b64)
                                  (0x72,local_2980._0_4_,0x24,local_295c,&local_28bc,pcVar23),
              iVar11 != 0) {
          iVar10 = iVar10 + 1;
          if ((run == 0) || (iVar10 == 0x7fffffff)) goto LAB_004522b8;
        }
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,"RSA sign failure\n");
        iVar10 = 1;
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar5);
LAB_004522b8:
        dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
        if (mr == 0) {
          pcVar21 = "%ld %d bit private RSA\'s in %.2fs\n";
        }
        else {
          pcVar21 = "+R1:%ld:%d:%.2f\n";
        }
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar21,iVar10,uVar20,dVar39);
        *(double *)(rsa_results + iVar19 * 0x10) = dVar39 / (double)iVar10;
      }
      iVar11 = (*(code *)PTR_RSA_verify_006a8b68)(0x72,local_2980._0_4_,0x24,local_295c);
      puVar16 = PTR_bio_err_006a7f3c;
      if (iVar11 < 1) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar5,"RSA verify failure.  No RSA verify will be done.\n");
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar5);
        local_288c[iVar19] = (char *)0x0;
      }
      else {
        uVar20 = *(undefined4 *)(rsa_bits_17820 + iVar19 * 4);
        if (mr == 0) {
          pcVar21 = "Doing %d bit %s %s\'s for %ds: ";
        }
        else {
          pcVar21 = "+DTP:%d:%s:%s:%d\n";
        }
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar21,uVar20,"public","rsa",10);
        iVar11 = 0;
        (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar16,0xb,0,0);
        (*(code *)PTR_alarm_006aabc8)(10);
        app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
        run = 1;
        while (iVar12 = (*(code *)PTR_RSA_verify_006a8b68)
                                  (0x72,local_2980._0_4_,0x24,local_295c,local_28bc,pcVar23),
              0 < iVar12) {
          iVar11 = iVar11 + 1;
          if ((run == 0) || (iVar11 == 0x7fffffff)) goto LAB_004520cc;
        }
        iVar11 = 1;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,"RSA verify failure\n");
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar5);
LAB_004520cc:
        dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
        if (mr == 0) {
          pcVar23 = "%ld %d bit public RSA\'s in %.2fs\n";
        }
        else {
          pcVar23 = "+R2:%ld:%d:%.2f\n";
        }
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar11,uVar20);
        *(double *)(rsa_results + iVar19 * 0x10 + 8) = dVar39 / (double)iVar11;
      }
      if (iVar10 != 1) goto LAB_00451ef4;
      if (iVar19 + 1 != 4) {
        iVar10 = iVar19 + 2;
        local_288c[iVar19 + 1] = (char *)0x0;
        iVar37 = iVar10;
        if (iVar10 < 4) {
          iVar37 = iVar19 + 3;
          local_288c[iVar10] = (char *)0x0;
          if (iVar19 == 0) {
            local_2880 = 0;
            iVar37 = 4;
          }
        }
        goto LAB_00451ef4;
      }
      break;
    }
LAB_00451ef4:
    iVar19 = iVar37 + 1;
  } while (iVar19 < 4);
  (*(code *)PTR_RAND_pseudo_bytes_006a8664)(local_2980._0_4_,0x14);
  iVar19 = (*(code *)PTR_RAND_status_006a882c)();
  if (iVar19 != 1) {
    (*(code *)PTR_RAND_seed_006a8b6c)
              ("string to make the random number generator think it has entropy",0x40);
    rnd_fake = 1;
  }
  local_2950 = 0x6b000000000000;
  iVar19 = 0;
  do {
    if (local_28b4[iVar19 + 3] == 0) {
LAB_004523b4:
      iVar19 = iVar19 + 1;
    }
    else {
      iVar10 = local_28b4[iVar19];
      iVar37 = (*(code *)PTR_DSA_sign_006a8b7c)
                         (0x74,local_2980._0_4_,0x14,local_295c,unaff_s8,iVar10);
      puVar16 = PTR_bio_err_006a7f3c;
      if (iVar37 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar5,"DSA sign failure.  No DSA sign will be done.\n");
        iVar37 = 1;
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar5);
      }
      else {
        uVar20 = *(undefined4 *)(dsa_bits_17825 + iVar19 * 4);
        if (mr == 0) {
          pcVar23 = "Doing %d bit %s %s\'s for %ds: ";
        }
        else {
          pcVar23 = "+DTP:%d:%s:%s:%d\n";
        }
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar5,pcVar23,uVar20,"sign",&DAT_006324a0,10);
        iVar37 = 0;
        (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar16,0xb,0,0);
        (*(code *)PTR_alarm_006aabc8)(10);
        app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
        run = 1;
        while (iVar11 = (*(code *)PTR_DSA_sign_006a8b7c)
                                  (0x74,local_2980._0_4_,0x14,local_295c,unaff_s8,iVar10),
              iVar11 != 0) {
          iVar37 = iVar37 + 1;
          if ((run == 0) || (iVar37 == 0x7fffffff)) goto LAB_00452a9c;
        }
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,"DSA sign failure\n");
        iVar37 = 1;
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar5);
LAB_00452a9c:
        dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
        if (mr == 0) {
          pcVar23 = "%ld %d bit DSA signs in %.2fs\n";
        }
        else {
          pcVar23 = "+R3:%ld:%d:%.2f\n";
        }
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar37,uVar20,dVar39);
        *(double *)(dsa_results + iVar19 * 0x10) = dVar39 / (double)iVar37;
      }
      iVar11 = (*(code *)PTR_DSA_verify_006a8b80)(0x74,local_2980._0_4_,0x14,local_295c);
      puVar16 = PTR_bio_err_006a7f3c;
      if (iVar11 < 1) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar5,"DSA verify failure.  No DSA verify will be done.\n");
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar5);
        local_28b4[iVar19 + 3] = 0;
      }
      else {
        uVar20 = *(undefined4 *)(dsa_bits_17825 + iVar19 * 4);
        if (mr == 0) {
          pcVar23 = "Doing %d bit %s %s\'s for %ds: ";
        }
        else {
          pcVar23 = "+DTP:%d:%s:%s:%d\n";
        }
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar5,pcVar23,uVar20,"verify",0x6324a00000000a);
        iVar11 = 0;
        (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar16,0xb,0,0);
        (*(code *)PTR_alarm_006aabc8)(10);
        app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
        run = 1;
        while (iVar12 = (*(code *)PTR_DSA_verify_006a8b80)
                                  (0x74,local_2980._0_4_,0x14,local_295c,local_28b8,iVar10),
              0 < iVar12) {
          iVar11 = iVar11 + 1;
          if ((run == 0) || (iVar11 == 0x7fffffff)) goto LAB_004528d0;
        }
        iVar11 = 1;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,"DSA verify failure\n");
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar5);
LAB_004528d0:
        dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
        if (mr == 0) {
          pcVar23 = "%ld %d bit DSA verify in %.2fs\n";
        }
        else {
          pcVar23 = "+R4:%ld:%d:%.2f\n";
        }
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar11,uVar20);
        *(double *)(dsa_results + iVar19 * 0x10 + 8) = dVar39 / (double)iVar11;
      }
      if (iVar37 != 1) goto LAB_004523b4;
      if (iVar19 == 2) {
        iVar19 = 4;
      }
      else {
        local_28b4[iVar19 + 4] = 0;
        if (iVar19 == 0) {
          local_28b4[5] = 0;
          iVar19 = 4;
        }
        else {
          iVar19 = iVar19 + 3;
        }
      }
    }
  } while (iVar19 < 3);
  if (rnd_fake != 0) {
    (*(code *)PTR_RAND_cleanup_006a8534)();
  }
  iVar19 = (*(code *)PTR_RAND_status_006a882c)();
  if (iVar19 != 1) {
    (*(code *)PTR_RAND_seed_006a8b6c)
              ("string to make the random number generator think it has entropy",0x40);
    rnd_fake = 1;
  }
  iVar19 = 0;
  local_2938 = 1.068035452083457e-306;
  do {
    iVar10 = iVar19 * 4;
    iVar37 = iVar19;
    if (local_279c[iVar19] != 0) {
      pcVar23 = (char *)(*(code *)PTR_EC_KEY_new_by_curve_name_006a89ac)
                                  (*(undefined4 *)(test_curves_17826 + iVar10));
      local_285c[iVar19] = pcVar23;
      if (pcVar23 == (char *)0x0) {
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,"ECDSA failure.\n");
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar5);
        goto LAB_00452448;
      }
      (*(code *)PTR_EC_KEY_precompute_mult_006a8b70)(pcVar23,0);
      (*(code *)PTR_EC_KEY_generate_key_006a82d4)(pcVar23);
      iVar11 = (*(code *)PTR_ECDSA_sign_006a8b74)
                         (0,local_2980._0_4_,0x14,auStack_63c,unaff_s8,pcVar23);
      puVar16 = PTR_bio_err_006a7f3c;
      if (iVar11 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar5,"ECDSA sign failure.  No ECDSA sign will be done.\n");
        iVar11 = 1;
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar5);
      }
      else {
        uVar20 = *(undefined4 *)(test_curves_bits_17828 + iVar10);
        if (mr == 0) {
          pcVar21 = "Doing %d bit %s %s\'s for %ds: ";
        }
        else {
          pcVar21 = "+DTP:%d:%s:%s:%d\n";
        }
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar21,uVar20,"sign","ecdsa",10);
        iVar11 = 0;
        (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar16,0xb,0,0);
        (*(code *)PTR_alarm_006aabc8)(10);
        app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
        run = 1;
        while (iVar12 = (*(code *)PTR_ECDSA_sign_006a8b74)
                                  (0,local_2980._0_4_,0x14,auStack_63c,unaff_s8,pcVar23),
              iVar12 != 0) {
          iVar11 = iVar11 + 1;
          if ((run == 0) || (iVar11 == 0x7fffffff)) goto LAB_00452c34;
        }
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,"ECDSA sign failure\n");
        iVar11 = 1;
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar5);
LAB_00452c34:
        dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
        if (mr == 0) {
          pcVar21 = "%ld %d bit ECDSA signs in %.2fs \n";
        }
        else {
          pcVar21 = "+R5:%ld:%d:%.2f\n";
        }
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar21,iVar11,uVar20,dVar39);
        *(double *)(ecdsa_results + iVar19 * 0x10) = dVar39 / (double)iVar11;
      }
      iVar12 = (*(code *)PTR_ECDSA_verify_006a8b78)(0,local_2980._0_4_,0x14,auStack_63c);
      puVar16 = PTR_bio_err_006a7f3c;
      if (iVar12 == 1) {
        uVar20 = *(undefined4 *)(test_curves_bits_17828 + iVar10);
        if (mr == 0) {
          pcVar21 = "Doing %d bit %s %s\'s for %ds: ";
        }
        else {
          pcVar21 = "+DTP:%d:%s:%s:%d\n";
        }
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar5,pcVar21,uVar20,"verify",0x63ecec0000000a);
        (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar16,0xb,0,0);
        (*(code *)PTR_alarm_006aabc8)(10);
        app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
        iVar10 = 0;
        run = iVar12;
        while (iVar12 = (*(code *)PTR_ECDSA_verify_006a8b78)
                                  (0,local_2980._0_4_,0x14,auStack_63c,local_28b8,pcVar23),
              iVar12 == 1) {
          iVar10 = iVar10 + 1;
          if ((run == 0) || (iVar10 == 0x7fffffff)) goto LAB_00453680;
        }
        iVar10 = 1;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,"ECDSA verify failure\n");
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar5);
LAB_00453680:
        dVar39 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
        if (mr == 0) {
          pcVar23 = "%ld %d bit ECDSA verify in %.2fs\n";
        }
        else {
          pcVar23 = "+R6:%ld:%d:%.2f\n";
        }
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar10,uVar20);
        *(double *)(ecdsa_results + iVar19 * 0x10 + 8) = dVar39 / (double)iVar10;
      }
      else {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar5,"ECDSA verify failure.  No ECDSA verify will be done.\n");
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar5);
        local_279c[iVar19] = 0;
      }
      if (iVar11 != 1) goto LAB_00452448;
      if (iVar19 + 1 != 0x10) {
        iVar37 = iVar19 + 2;
        local_279c[iVar19 + 1] = 0;
        if (iVar37 < 0x10) {
          iVar10 = iVar19 + 3;
          local_279c[iVar37] = 0;
          iVar37 = iVar10;
          if (iVar10 < 0x10) {
            iVar37 = iVar19 + 4;
            local_279c[iVar10] = 0;
            if (iVar37 < 0x10) {
              iVar10 = iVar19 + 5;
              local_279c[iVar37] = 0;
              iVar37 = iVar10;
              if (iVar10 < 0x10) {
                iVar37 = iVar19 + 6;
                local_279c[iVar10] = 0;
                if (iVar37 < 0x10) {
                  iVar10 = iVar19 + 7;
                  local_279c[iVar37] = 0;
                  iVar37 = iVar10;
                  if (iVar10 < 0x10) {
                    iVar37 = iVar19 + 8;
                    local_279c[iVar10] = 0;
                    if (iVar37 < 0x10) {
                      iVar10 = iVar19 + 9;
                      local_279c[iVar37] = 0;
                      iVar37 = iVar10;
                      if (iVar10 < 0x10) {
                        iVar37 = iVar19 + 10;
                        local_279c[iVar10] = 0;
                        if (iVar37 < 0x10) {
                          iVar10 = iVar19 + 0xb;
                          local_279c[iVar37] = 0;
                          iVar37 = iVar10;
                          if (iVar10 < 0x10) {
                            iVar37 = iVar19 + 0xc;
                            local_279c[iVar10] = 0;
                            if (iVar37 < 0x10) {
                              iVar10 = iVar19 + 0xd;
                              local_279c[iVar37] = 0;
                              iVar37 = iVar10;
                              if (iVar10 < 0x10) {
                                iVar37 = iVar19 + 0xe;
                                local_279c[iVar10] = 0;
                                if (iVar37 < 0x10) {
                                  local_279c[iVar37] = 0;
                                  iVar37 = iVar19 + 0xf;
                                  if (iVar19 == 0) {
                                    local_279c[15] = 0;
                                    iVar37 = 0x10;
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
        goto LAB_00452448;
      }
      break;
    }
LAB_00452448:
    iVar19 = iVar37 + 1;
  } while (iVar19 < 0x10);
  if (rnd_fake != 0) {
    (*(code *)PTR_RAND_cleanup_006a8534)();
  }
  iVar19 = (*(code *)PTR_RAND_status_006a882c)();
  if (iVar19 != 1) {
    (*(code *)PTR_RAND_seed_006a8b6c)
              ("string to make the random number generator think it has entropy",0x40);
    rnd_fake = 1;
  }
  local_2940 = ZEXT48(local_2980._0_4_) << 0x20;
  iVar19 = 0;
  dVar39 = DAT_0063fad8;
  dVar41 = DAT_0063fad8;
  do {
    iVar37 = iVar19;
    if (local_279c[iVar19 + 0x10] != 0) {
      uVar20 = *(undefined4 *)(test_curves_17826 + iVar19 * 4);
      pcVar23 = (char *)(*(code *)PTR_EC_KEY_new_by_curve_name_006a89ac)(uVar20);
      local_281c[iVar19] = pcVar23;
      pcVar21 = (char *)(*(code *)PTR_EC_KEY_new_by_curve_name_006a89ac)(uVar20);
      local_27dc[iVar19] = pcVar21;
      if ((pcVar23 == (char *)0x0) || (pcVar21 == (char *)0x0)) {
        pcVar23 = "ECDH failure.\n";
        uVar20 = *(undefined4 *)puVar5;
      }
      else {
        iVar10 = (*(code *)PTR_EC_KEY_generate_key_006a82d4)(pcVar23);
        if ((iVar10 != 0) &&
           (iVar10 = (*(code *)PTR_EC_KEY_generate_key_006a82d4)(pcVar21), iVar10 != 0)) {
          uVar20 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(pcVar23);
          iVar10 = (*(code *)PTR_EC_GROUP_get_degree_006a8bcc)(uVar20);
          if (iVar10 < 0xc1) {
            iVar10 = 0x14;
            pcVar35 = KDF1_SHA1;
          }
          else {
            pcVar35 = (code *)0x0;
            iVar10 = iVar10 + 7 >> 3;
          }
          pcVar38 = acStack_53d + 1;
          pcVar22 = local_43c;
          uVar20 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(pcVar21);
          iVar11 = (*(code *)PTR_ECDH_compute_key_006a8bd4)(pcVar38,iVar10,uVar20,pcVar23,pcVar35);
          uVar20 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(pcVar23);
          iVar12 = (*(code *)PTR_ECDH_compute_key_006a8bd4)(pcVar22,iVar10,uVar20,pcVar21,pcVar35);
          if (iVar11 < 1) {
            bVar2 = iVar11 == iVar12;
LAB_00454af8:
            if (!bVar2) goto LAB_00455ee4;
          }
          else {
            if (iVar11 == iVar12) {
              pcVar14 = pcVar38;
              do {
                cVar17 = *pcVar14;
                cVar1 = *pcVar22;
                if (pcVar14 == pcVar38 + iVar11 + -1) {
                  bVar2 = cVar17 == cVar1;
                  goto LAB_00454af8;
                }
                pcVar14 = pcVar14 + 1;
                pcVar22 = pcVar22 + 1;
              } while (cVar17 == cVar1);
            }
LAB_00455ee4:
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar5,"ECDH computations don\'t match.\n");
            (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar5);
          }
          puVar16 = PTR_bio_err_006a7f3c;
          uVar15 = *(uint *)(test_curves_bits_17828 + iVar19 * 4);
          local_2938 = (double)((ulonglong)uVar15 << 0x20);
          if (mr == 0) {
            pcVar22 = "Doing %d bit %s %s\'s for %ds: ";
          }
          else {
            pcVar22 = "+DTP:%d:%s:%s:%d\n";
          }
          iVar11 = 0;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar5,pcVar22,uVar15,"",&DAT_0063edb4,10);
          (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar16,0xb,0,0);
          (*(code *)PTR_alarm_006aabc8)(10);
          app_tminterval(0,*(undefined4 *)(local_298c + -0x3814));
          run = 1;
          do {
            iVar11 = iVar11 + 1;
            uVar20 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(pcVar21);
            (*(code *)PTR_ECDH_compute_key_006a8bd4)(pcVar38,iVar10,uVar20,pcVar23,pcVar35);
            if (run == 0) {
              local_2938 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
              if (mr == 0) {
                pcVar23 = "%ld %d-bit ECDH ops in %.2fs\n";
              }
              else {
                pcVar23 = "+R7:%ld:%d:%.2f\n";
              }
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar5,pcVar23,iVar11,uVar15);
              *(double *)(ecdh_results + iVar19 * 8) = local_2938 / (double)iVar11;
              if (iVar11 != 1) goto LAB_00452d28;
              goto LAB_00452df0;
            }
          } while (iVar11 != 0x7fffffff);
          local_2930 = (double)app_tminterval(1,*(undefined4 *)(local_298c + -0x3814));
          if (mr == 0) {
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar5,"%ld %d-bit ECDH ops in %.2fs\n",0x7fffffff,uVar15);
            *(double *)(ecdh_results + iVar19 * 8) = local_2930 / dVar39;
          }
          else {
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar5,"+R7:%ld:%d:%.2f\n",0x7fffffff,uVar15);
            *(double *)(ecdh_results + iVar19 * 8) = local_2930 / dVar41;
          }
          goto LAB_00452d28;
        }
        pcVar23 = "ECDH key generation failure.\n";
        uVar20 = *(undefined4 *)puVar5;
      }
      (*(code *)PTR_BIO_printf_006a7f38)(uVar20,pcVar23);
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar5);
LAB_00452df0:
      if (iVar19 != 0xf) {
        iVar37 = iVar19 + 2;
        local_279c[iVar19 + 0x11] = 0;
        if (iVar37 < 0x10) {
          iVar37 = iVar19 + 3;
          local_279c[iVar19 + 0x12] = 0;
          if (iVar37 < 0x10) {
            iVar37 = iVar19 + 4;
            local_279c[iVar19 + 0x13] = 0;
            if (iVar37 < 0x10) {
              iVar37 = iVar19 + 5;
              local_279c[iVar19 + 0x14] = 0;
              if (iVar37 < 0x10) {
                iVar37 = iVar19 + 6;
                local_279c[iVar19 + 0x15] = 0;
                if (iVar37 < 0x10) {
                  iVar37 = iVar19 + 7;
                  local_279c[iVar19 + 0x16] = 0;
                  if (iVar37 < 0x10) {
                    iVar37 = iVar19 + 8;
                    local_279c[iVar19 + 0x17] = 0;
                    if (iVar37 < 0x10) {
                      iVar37 = iVar19 + 9;
                      local_279c[iVar19 + 0x18] = 0;
                      if (iVar37 < 0x10) {
                        iVar37 = iVar19 + 10;
                        local_279c[iVar19 + 0x19] = 0;
                        if (iVar37 < 0x10) {
                          iVar37 = iVar19 + 0xb;
                          local_279c[iVar19 + 0x1a] = 0;
                          if (iVar37 < 0x10) {
                            iVar37 = iVar19 + 0xc;
                            local_279c[iVar19 + 0x1b] = 0;
                            if (iVar37 < 0x10) {
                              iVar37 = iVar19 + 0xd;
                              local_279c[iVar19 + 0x1c] = 0;
                              if (iVar37 < 0x10) {
                                iVar37 = iVar19 + 0xe;
                                local_279c[iVar19 + 0x1d] = 0;
                                if (iVar37 < 0x10) {
                                  iVar37 = iVar19 + 0xf;
                                  local_279c[iVar19 + 0x1e] = 0;
                                  if (iVar19 == 0) {
                                    local_279c[31] = 0;
                                    iVar37 = 0x10;
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
        goto LAB_00452d28;
      }
      break;
    }
LAB_00452d28:
    iVar19 = iVar37 + 1;
  } while (iVar19 < 0x10);
  if (rnd_fake != 0) {
    (*(code *)PTR_RAND_cleanup_006a8534)();
  }
  if (mr == 0) {
    local_2980 = ZEXT48(PTR_stdout_006aaad4) << 0x20;
    puVar34 = (undefined4 *)PTR_stdout_006aaad4;
    goto LAB_00454824;
  }
  uVar15 = (uint)local_2980._0_4_;
  if (local_28ec != 0) {
    local_2980 = ZEXT48(PTR_stdout_006aaad4) << 0x20;
    goto LAB_00453ce8;
  }
  goto LAB_00452f7c;
LAB_004540f8:
  (*(code *)PTR_close_006aaa5c)(local_17f0);
  puVar6 = PTR___printf_chk_006aaad0;
  iVar37 = iVar19 + 1;
  *puVar36 = local_17f4;
  (*(code *)puVar6)(1,"Forked child %d\n",iVar19);
  iVar19 = iVar37;
  puVar36 = puVar36 + 1;
  if ((int)local_2988._0_4_ <= iVar37) goto LAB_00454c7c;
  goto LAB_00454138;
LAB_00454c7c:
  local_2980 = ZEXT48(puVar34) << 0x20;
  local_2930 = 8.900295434028806e-307;
  local_2938 = 9.345310205730246e-307;
  uVar15 = 0;
  local_2920 = dsa_results;
  dVar39 = DAT_0063fac0;
  dVar41 = DAT_0063fac0;
  do {
    uVar20 = (*(code *)PTR_fdopen_006aac28)(*local_2950._0_4_,"r");
LAB_00454ce8:
    iVar19 = (*(code *)PTR_fgets_006aabe8)(local_43c,0x400,uVar20);
    if (iVar19 != 0) {
      while( true ) {
        puVar16 = (undefined *)(*(code *)PTR_strchr_006aab34)(local_43c,10);
        if (puVar16 != (undefined *)0x0) {
          *puVar16 = 0;
        }
        if (local_43c[0] == '+') break;
        pcVar23 = "Don\'t understand line \'%s\' from child %d\n";
LAB_00454d3c:
        (*(code *)PTR___fprintf_chk_006aaa8c)(*unaff_s7,1,pcVar23,local_43c,uVar15);
        iVar19 = (*(code *)PTR_fgets_006aabe8)(local_43c,0x400,uVar20);
        if (iVar19 == 0) goto LAB_00454d6c;
      }
      (*(code *)PTR___printf_chk_006aaad0)(1,"Got: %s from %d\n",local_43c,uVar15);
      iVar19 = (*(code *)PTR_strncmp_006aaa7c)(local_43c,&DAT_0063f234,3);
      if (iVar19 == 0) {
        uVar27 = (uint)local_43c[3];
        if (uVar27 == 0) {
          pcVar23 = local_43c + 3;
          pcVar21 = (char *)0x0;
        }
        else {
          (*(code *)PTR_memset_006aab00)(acStack_53d + 1,0,0x100);
          puVar18 = &sep_19034;
          acStack_53d[1] = 1;
          cVar17 = sep_19034._0_1_;
          while (uVar4 = (uint)cVar17, uVar4 != 0) {
            puVar18 = (undefined2 *)((int)puVar18 + 1);
            cVar17 = *(char *)puVar18;
            acStack_53d[(uVar4 & 0xff) + 1] = '\x01';
          }
          pcVar21 = local_43c + 3;
          pcVar23 = pcVar21;
          if (acStack_53d[(uVar27 & 0xff) + 1] == '\0') {
            pcVar22 = local_438;
            do {
              pcVar23 = pcVar22;
              pcVar22 = pcVar23 + 1;
            } while (acStack_53d[((int)*pcVar23 & 0xffU) + 1] == '\0');
            if ((int)*pcVar23 != 0) goto LAB_00454f70;
          }
          else {
LAB_00454f70:
            *pcVar23 = '\0';
            pcVar23 = pcVar23 + 1;
          }
        }
        iVar19 = (*(code *)PTR_strtol_006aaa68)(pcVar21,0,10);
        uVar27 = (uint)*pcVar23;
        if (uVar27 != 0) {
          (*(code *)PTR_memset_006aab00)(acStack_53d + 1,0,0x100);
          puVar18 = &sep_19034;
          acStack_53d[1] = 1;
          cVar17 = sep_19034._0_1_;
          while (uVar4 = (uint)cVar17, uVar4 != 0) {
            puVar18 = (undefined2 *)((int)puVar18 + 1);
            cVar17 = *(char *)puVar18;
            acStack_53d[(uVar4 & 0xff) + 1] = '\x01';
          }
          pcVar21 = pcVar23;
          if (acStack_53d[(uVar27 & 0xff) + 1] == '\0') {
            do {
              pcVar23 = pcVar23 + 1;
              uVar27 = (uint)*pcVar23;
            } while (acStack_53d[(uVar27 & 0xff) + 1] == '\0');
            pcVar21 = pcVar23;
            if (uVar27 == 0) goto LAB_00455044;
          }
          uVar27 = (uint)pcVar21[1];
          pcVar23 = pcVar21 + 1;
          *pcVar21 = '\0';
        }
LAB_00455044:
        local_2940 = (ulonglong)uVar15 << 0x20;
        pdVar30 = (double *)(local_2978 + iVar19 * 0x28);
        pcVar21 = pcVar23;
        if (uVar27 == 0) goto LAB_00455154;
        do {
          (*(code *)PTR_memset_006aab00)(acStack_53d + 1,0,0x100);
          acStack_53d[1] = 1;
          puVar18 = &sep_19034;
          cVar17 = sep_19034._0_1_;
          while (uVar4 = (uint)cVar17, uVar4 != 0) {
            puVar18 = (undefined2 *)((int)puVar18 + 1);
            cVar17 = *(char *)puVar18;
            acStack_53d[(uVar4 & 0xff) + 1] = '\x01';
          }
          pcVar21 = pcVar23;
          pdVar25 = pdVar30;
          if (acStack_53d[(uVar27 & 0xff) + 1] == '\0') {
            do {
              pcVar21 = pcVar21 + 1;
            } while (acStack_53d[((int)*pcVar21 & 0xffU) + 1] == '\0');
            if ((int)*pcVar21 != 0) goto LAB_00455118;
          }
          else {
LAB_00455118:
            *pcVar21 = '\0';
            pcVar21 = pcVar21 + 1;
          }
          while( true ) {
            pdVar30 = pdVar25 + 1;
            dVar40 = (double)(*(code *)PTR_strtod_006aaae4)(pcVar23,0);
            *pdVar25 = *pdVar25 + dVar40;
            if ((double *)(local_2978 + iVar19 * 0x28 + 0x28) == pdVar30) goto LAB_00454ce8;
            uVar27 = (uint)*pcVar21;
            pcVar23 = pcVar21;
            if (uVar27 != 0) break;
LAB_00455154:
            pcVar23 = (char *)0x0;
            pdVar25 = pdVar30;
          }
        } while( true );
      }
      iVar19 = (*(code *)PTR_strncmp_006aaa7c)(local_43c,&DAT_0063f238,4);
      if (iVar19 == 0) {
        uVar27 = (uint)local_438[0];
        if (uVar27 == 0) {
          pcVar23 = local_438;
          pcVar21 = (char *)0x0;
        }
        else {
          (*(code *)PTR_memset_006aab00)(acStack_53d + 1,0,0x100);
          puVar18 = &sep_19034;
          acStack_53d[1] = 1;
          cVar17 = sep_19034._0_1_;
          while (uVar4 = (uint)cVar17, uVar4 != 0) {
            puVar18 = (undefined2 *)((int)puVar18 + 1);
            cVar17 = *(char *)puVar18;
            acStack_53d[(uVar4 & 0xff) + 1] = '\x01';
          }
          pcVar21 = local_438;
          pcVar23 = pcVar21;
          if (acStack_53d[(uVar27 & 0xff) + 1] == '\0') {
            pcVar23 = local_438;
            do {
              pcVar23 = pcVar23 + 1;
            } while (acStack_53d[((int)*pcVar23 & 0xffU) + 1] == '\0');
            if ((int)*pcVar23 != 0) goto LAB_00455210;
          }
          else {
LAB_00455210:
            *pcVar23 = '\0';
            pcVar23 = pcVar23 + 1;
          }
        }
        iVar19 = (*(code *)PTR_strtol_006aaa68)(pcVar21,0,10);
        cVar17 = *pcVar23;
        if ((int)cVar17 == 0) {
          pcVar21 = (char *)0x0;
        }
        else {
          (*(code *)PTR_memset_006aab00)(acStack_53d + 1,0,0x100);
          puVar18 = &sep_19034;
          acStack_53d[1] = 1;
          cVar1 = sep_19034._0_1_;
          while (uVar27 = (uint)cVar1, uVar27 != 0) {
            puVar18 = (undefined2 *)((int)puVar18 + 1);
            cVar1 = *(char *)puVar18;
            acStack_53d[(uVar27 & 0xff) + 1] = '\x01';
          }
          if (acStack_53d[((int)cVar17 & 0xffU) + 1] == '\0') {
            do {
              pcVar23 = pcVar23 + 1;
            } while (acStack_53d[((int)*pcVar23 & 0xffU) + 1] == '\0');
            pcVar21 = (char *)0x0;
            if ((int)*pcVar23 == 0) goto LAB_00455398;
          }
          cVar17 = pcVar23[1];
          pcVar21 = pcVar23 + 1;
          *pcVar23 = '\0';
          pcVar23 = pcVar21;
          if ((int)cVar17 == 0) {
            pcVar21 = (char *)0x0;
          }
          else {
            (*(code *)PTR_memset_006aab00)(acStack_53d + 1,0,0x100);
            puVar18 = &sep_19034;
            acStack_53d[1] = 1;
            cVar1 = sep_19034._0_1_;
            while (uVar27 = (uint)cVar1, uVar27 != 0) {
              puVar18 = (undefined2 *)((int)puVar18 + 1);
              cVar1 = *(char *)puVar18;
              acStack_53d[(uVar27 & 0xff) + 1] = '\x01';
            }
            if (acStack_53d[((int)cVar17 & 0xffU) + 1] == '\0') {
              do {
                pcVar23 = pcVar23 + 1;
              } while (acStack_53d[((int)*pcVar23 & 0xffU) + 1] == '\0');
              if ((int)*pcVar23 == 0) goto LAB_00455398;
            }
            *pcVar23 = '\0';
            pcVar23 = pcVar23 + 1;
          }
        }
LAB_00455398:
        dVar40 = (double)(*(code *)PTR_strtod_006aaae4)(pcVar21,0);
        if (uVar15 == 0) {
          uVar27 = (uint)*pcVar23;
          puVar31 = (undefined1 *)(iVar19 * 0x10);
          puVar29 = rsa_results;
          *(double *)(rsa_results + (int)puVar31) = dVar40;
          if (uVar27 != 0) goto LAB_004553ec;
LAB_00456348:
          dVar40 = (double)(*(code *)PTR_strtod_006aaae4)(0,0);
LAB_0045635c:
          *(double *)(puVar31 + (int)puVar29 + 8) = dVar40;
          goto LAB_00454ce8;
        }
        puVar31 = (undefined1 *)(iVar19 * 0x10);
        puVar29 = rsa_results;
        uVar27 = (uint)*pcVar23;
        *(double *)(rsa_results + (int)puVar31) =
             DAT_0063fac0 /
             (DAT_0063fac0 / *(double *)(rsa_results + (int)puVar31) + DAT_0063fac0 / dVar40);
        if (uVar27 == 0) {
LAB_00455b18:
          dVar40 = (double)(*(code *)PTR_strtod_006aaae4)(0,0);
        }
        else {
LAB_004553ec:
          puVar29 = rsa_results;
          puVar31 = (undefined1 *)(iVar19 * 0x10);
          (*(code *)PTR_memset_006aab00)(acStack_53d + 1,0,0x100);
          puVar18 = &sep_19034;
          acStack_53d[1] = 1;
          cVar17 = sep_19034._0_1_;
          while (uVar4 = (uint)cVar17, uVar4 != 0) {
            puVar18 = (undefined2 *)((int)puVar18 + 1);
            cVar17 = *(char *)puVar18;
            acStack_53d[(uVar4 & 0xff) + 1] = '\x01';
          }
          pcVar21 = pcVar23;
          if (acStack_53d[(uVar27 & 0xff) + 1] == '\0') {
            do {
              pcVar23 = pcVar23 + 1;
              uVar27 = (uint)*pcVar23;
            } while (acStack_53d[(uVar27 & 0xff) + 1] == '\0');
joined_r0x004557dc:
            if (uVar27 != 0) goto LAB_00455484;
          }
          else {
LAB_00455484:
            *pcVar23 = '\0';
          }
          dVar40 = (double)(*(code *)PTR_strtod_006aaae4)(pcVar21,0);
          if (uVar15 == 0) goto LAB_0045635c;
        }
        puVar31 = puVar31 + (int)puVar29;
      }
      else {
        iVar19 = (*(code *)PTR_strncmp_006aaa7c)(local_43c,&DAT_0063f240,4);
        if (iVar19 == 0) {
          uVar27 = (uint)local_438[0];
          if (uVar27 == 0) {
            pcVar23 = local_438;
            pcVar21 = (char *)0x0;
          }
          else {
            (*(code *)PTR_memset_006aab00)(acStack_53d + 1,0,0x100);
            puVar18 = &sep_19034;
            acStack_53d[1] = 1;
            cVar17 = sep_19034._0_1_;
            while (uVar4 = (uint)cVar17, uVar4 != 0) {
              puVar18 = (undefined2 *)((int)puVar18 + 1);
              cVar17 = *(char *)puVar18;
              acStack_53d[(uVar4 & 0xff) + 1] = '\x01';
            }
            pcVar21 = local_438;
            pcVar23 = pcVar21;
            if (acStack_53d[(uVar27 & 0xff) + 1] == '\0') {
              pcVar23 = local_438;
              do {
                pcVar23 = pcVar23 + 1;
              } while (acStack_53d[((int)*pcVar23 & 0xffU) + 1] == '\0');
              if ((int)*pcVar23 != 0) goto LAB_00455570;
            }
            else {
LAB_00455570:
              *pcVar23 = '\0';
              pcVar23 = pcVar23 + 1;
            }
          }
          iVar19 = (*(code *)PTR_strtol_006aaa68)(pcVar21,0,10);
          cVar17 = *pcVar23;
          if ((int)cVar17 == 0) {
            pcVar21 = (char *)0x0;
          }
          else {
            (*(code *)PTR_memset_006aab00)(acStack_53d + 1,0,0x100);
            puVar18 = &sep_19034;
            acStack_53d[1] = 1;
            cVar1 = sep_19034._0_1_;
            while (uVar27 = (uint)cVar1, uVar27 != 0) {
              puVar18 = (undefined2 *)((int)puVar18 + 1);
              cVar1 = *(char *)puVar18;
              acStack_53d[(uVar27 & 0xff) + 1] = '\x01';
            }
            if (acStack_53d[((int)cVar17 & 0xffU) + 1] == '\0') {
              do {
                pcVar23 = pcVar23 + 1;
              } while (acStack_53d[((int)*pcVar23 & 0xffU) + 1] == '\0');
              pcVar21 = (char *)0x0;
              if ((int)*pcVar23 == 0) goto LAB_004556f8;
            }
            cVar17 = pcVar23[1];
            pcVar21 = pcVar23 + 1;
            *pcVar23 = '\0';
            pcVar23 = pcVar21;
            if ((int)cVar17 == 0) {
              pcVar21 = (char *)0x0;
            }
            else {
              (*(code *)PTR_memset_006aab00)(acStack_53d + 1,0,0x100);
              puVar18 = &sep_19034;
              acStack_53d[1] = 1;
              cVar1 = sep_19034._0_1_;
              while (uVar27 = (uint)cVar1, uVar27 != 0) {
                puVar18 = (undefined2 *)((int)puVar18 + 1);
                cVar1 = *(char *)puVar18;
                acStack_53d[(uVar27 & 0xff) + 1] = '\x01';
              }
              if (acStack_53d[((int)cVar17 & 0xffU) + 1] == '\0') {
                do {
                  pcVar23 = pcVar23 + 1;
                } while (acStack_53d[((int)*pcVar23 & 0xffU) + 1] == '\0');
                if ((int)*pcVar23 == 0) goto LAB_004556f8;
              }
              *pcVar23 = '\0';
              pcVar23 = pcVar23 + 1;
            }
          }
LAB_004556f8:
          dVar40 = (double)(*(code *)PTR_strtod_006aaae4)(pcVar21,0);
          puVar31 = local_2920;
          if (uVar15 == 0) {
            puVar29 = (undefined1 *)(iVar19 * 0x10);
            uVar27 = (uint)*pcVar23;
            *(double *)(dsa_results + (int)puVar29) = dVar40;
            if (uVar27 != 0) goto LAB_00455748;
            goto LAB_00456348;
          }
          puVar29 = (undefined1 *)(iVar19 * 0x10);
          uVar27 = (uint)*pcVar23;
          *(double *)(dsa_results + (int)puVar29) =
               DAT_0063fac0 /
               (DAT_0063fac0 / *(double *)(dsa_results + (int)puVar29) + DAT_0063fac0 / dVar40);
          if (uVar27 == 0) goto LAB_00455b18;
LAB_00455748:
          puVar29 = (undefined1 *)(iVar19 * 0x10);
          (*(code *)PTR_memset_006aab00)(acStack_53d + 1,0,0x100);
          puVar18 = &sep_19034;
          acStack_53d[1] = 1;
          cVar17 = sep_19034._0_1_;
          while (uVar4 = (uint)cVar17, uVar4 != 0) {
            puVar18 = (undefined2 *)((int)puVar18 + 1);
            cVar17 = *(char *)puVar18;
            acStack_53d[(uVar4 & 0xff) + 1] = '\x01';
          }
          pcVar21 = pcVar23;
          if (acStack_53d[(uVar27 & 0xff) + 1] == '\0') {
            do {
              pcVar23 = pcVar23 + 1;
              uVar27 = (uint)*pcVar23;
              puVar31 = dsa_results;
            } while (acStack_53d[(uVar27 & 0xff) + 1] == '\0');
            goto joined_r0x004557dc;
          }
          goto LAB_00455484;
        }
        iVar19 = (*(code *)PTR_strncmp_006aaa7c)(local_43c,&DAT_0063f248,4);
        if (iVar19 != 0) {
          iVar19 = (*(code *)PTR_strncmp_006aaa7c)(local_43c,&DAT_0063f250,4);
          if (iVar19 == 0) {
            uVar27 = (uint)local_438[0];
            if (uVar27 == 0) {
              pcVar23 = local_438;
              pcVar21 = (char *)0x0;
            }
            else {
              (*(code *)PTR_memset_006aab00)(acStack_53d + 1,0,0x100);
              puVar18 = &sep_19034;
              acStack_53d[1] = 1;
              cVar17 = sep_19034._0_1_;
              while (uVar4 = (uint)cVar17, uVar4 != 0) {
                puVar18 = (undefined2 *)((int)puVar18 + 1);
                cVar17 = *(char *)puVar18;
                acStack_53d[(uVar4 & 0xff) + 1] = '\x01';
              }
              pcVar21 = local_438;
              pcVar23 = pcVar21;
              if (acStack_53d[(uVar27 & 0xff) + 1] == '\0') {
                pcVar23 = local_438;
                do {
                  pcVar23 = pcVar23 + 1;
                } while (acStack_53d[((int)*pcVar23 & 0xffU) + 1] == '\0');
                if ((int)*pcVar23 != 0) goto LAB_00455be4;
              }
              else {
LAB_00455be4:
                *pcVar23 = '\0';
                pcVar23 = pcVar23 + 1;
              }
            }
            iVar19 = (*(code *)PTR_strtol_006aaa68)(pcVar21,0,10);
            cVar17 = *pcVar23;
            if ((int)cVar17 == 0) {
LAB_00455df0:
              pcVar21 = (char *)0x0;
            }
            else {
              (*(code *)PTR_memset_006aab00)(acStack_53d + 1,0,0x100);
              puVar18 = &sep_19034;
              acStack_53d[1] = 1;
              cVar1 = sep_19034._0_1_;
              while (uVar27 = (uint)cVar1, uVar27 != 0) {
                puVar18 = (undefined2 *)((int)puVar18 + 1);
                cVar1 = *(char *)puVar18;
                acStack_53d[(uVar27 & 0xff) + 1] = '\x01';
              }
              if (acStack_53d[((int)cVar17 & 0xffU) + 1] == '\0') {
                do {
                  pcVar23 = pcVar23 + 1;
                } while (acStack_53d[((int)*pcVar23 & 0xffU) + 1] == '\0');
                pcVar21 = (char *)0x0;
                if ((int)*pcVar23 != 0) goto LAB_00455cac;
              }
              else {
LAB_00455cac:
                cVar17 = pcVar23[1];
                pcVar21 = pcVar23 + 1;
                *pcVar23 = '\0';
                if ((int)cVar17 == 0) goto LAB_00455df0;
                (*(code *)PTR_memset_006aab00)(acStack_53d + 1,0,0x100);
                acStack_53d[1] = 1;
                puVar18 = &sep_19034;
                cVar1 = sep_19034._0_1_;
                while (uVar27 = (uint)cVar1, uVar27 != 0) {
                  puVar18 = (undefined2 *)((int)puVar18 + 1);
                  cVar1 = *(char *)puVar18;
                  acStack_53d[(uVar27 & 0xff) + 1] = '\x01';
                }
                pcVar23 = pcVar21;
                if (acStack_53d[((int)cVar17 & 0xffU) + 1] == '\0') {
                  do {
                    pcVar23 = pcVar23 + 1;
                  } while (acStack_53d[((int)*pcVar23 & 0xffU) + 1] == '\0');
                  if ((int)*pcVar23 == 0) goto LAB_00455d68;
                }
                *pcVar23 = '\0';
              }
            }
LAB_00455d68:
            dVar40 = (double)(*(code *)PTR_strtod_006aaae4)(pcVar21,0);
            if (uVar15 == 0) {
              *(double *)(ecdh_results + iVar19 * 8) = dVar40;
            }
            else {
              *(double *)(ecdh_results + iVar19 * 8) =
                   dVar41 / (dVar41 / *(double *)(ecdh_results + iVar19 * 8) + dVar41 / dVar40);
            }
          }
          else {
            iVar19 = (*(code *)PTR_strncmp_006aaa7c)(local_43c,&DAT_0063f258,3);
            if (iVar19 != 0) {
              pcVar23 = "Unknown type \'%s\' from child %d\n";
              goto LAB_00454d3c;
            }
          }
          goto LAB_00454ce8;
        }
        uVar27 = (uint)local_438[0];
        if (uVar27 == 0) {
          pcVar23 = local_438;
          pcVar21 = (char *)0x0;
        }
        else {
          (*(code *)PTR_memset_006aab00)(acStack_53d + 1,0,0x100);
          puVar18 = &sep_19034;
          acStack_53d[1] = 1;
          cVar17 = sep_19034._0_1_;
          while (uVar4 = (uint)cVar17, uVar4 != 0) {
            puVar18 = (undefined2 *)((int)puVar18 + 1);
            cVar17 = *(char *)puVar18;
            acStack_53d[(uVar4 & 0xff) + 1] = '\x01';
          }
          pcVar21 = local_438;
          pcVar23 = pcVar21;
          if (acStack_53d[(uVar27 & 0xff) + 1] == '\0') {
            pcVar23 = local_438;
            do {
              pcVar23 = pcVar23 + 1;
            } while (acStack_53d[((int)*pcVar23 & 0xffU) + 1] == '\0');
            if ((int)*pcVar23 != 0) goto LAB_0045588c;
          }
          else {
LAB_0045588c:
            *pcVar23 = '\0';
            pcVar23 = pcVar23 + 1;
          }
        }
        iVar19 = (*(code *)PTR_strtol_006aaa68)(pcVar21,0,10);
        cVar17 = *pcVar23;
        if ((int)cVar17 == 0) {
          pcVar21 = (char *)0x0;
        }
        else {
          (*(code *)PTR_memset_006aab00)(acStack_53d + 1,0,0x100);
          puVar18 = &sep_19034;
          acStack_53d[1] = 1;
          cVar1 = sep_19034._0_1_;
          while (uVar27 = (uint)cVar1, uVar27 != 0) {
            puVar18 = (undefined2 *)((int)puVar18 + 1);
            cVar1 = *(char *)puVar18;
            acStack_53d[(uVar27 & 0xff) + 1] = '\x01';
          }
          if (acStack_53d[((int)cVar17 & 0xffU) + 1] == '\0') {
            do {
              pcVar23 = pcVar23 + 1;
            } while (acStack_53d[((int)*pcVar23 & 0xffU) + 1] == '\0');
            pcVar21 = (char *)0x0;
            if ((int)*pcVar23 == 0) goto LAB_00455a14;
          }
          cVar17 = pcVar23[1];
          pcVar21 = pcVar23 + 1;
          *pcVar23 = '\0';
          pcVar23 = pcVar21;
          if ((int)cVar17 == 0) {
            pcVar21 = (char *)0x0;
          }
          else {
            (*(code *)PTR_memset_006aab00)(acStack_53d + 1,0,0x100);
            puVar18 = &sep_19034;
            acStack_53d[1] = 1;
            cVar1 = sep_19034._0_1_;
            while (uVar27 = (uint)cVar1, uVar27 != 0) {
              puVar18 = (undefined2 *)((int)puVar18 + 1);
              cVar1 = *(char *)puVar18;
              acStack_53d[(uVar27 & 0xff) + 1] = '\x01';
            }
            if (acStack_53d[((int)cVar17 & 0xffU) + 1] == '\0') {
              do {
                pcVar23 = pcVar23 + 1;
              } while (acStack_53d[((int)*pcVar23 & 0xffU) + 1] == '\0');
              if ((int)*pcVar23 == 0) goto LAB_00455a14;
            }
            *pcVar23 = '\0';
            pcVar23 = pcVar23 + 1;
          }
        }
LAB_00455a14:
        dVar40 = (double)(*(code *)PTR_strtod_006aaae4)(pcVar21,0);
        if (uVar15 == 0) {
          uVar27 = (uint)*pcVar23;
          *(double *)(ecdsa_results + iVar19 * 0x10) = dVar40;
          if (uVar27 != 0) goto LAB_00455a58;
          dVar40 = (double)(*(code *)PTR_strtod_006aaae4)(0,0);
LAB_00456294:
          *(double *)(ecdsa_results + iVar19 * 0x10 + 8) = dVar40;
          goto LAB_00454ce8;
        }
        uVar27 = (uint)*pcVar23;
        *(double *)(ecdsa_results + iVar19 * 0x10) =
             dVar39 / (dVar39 / *(double *)(ecdsa_results + iVar19 * 0x10) + dVar39 / dVar40);
        if (uVar27 == 0) {
          dVar40 = (double)(*(code *)PTR_strtod_006aaae4)(0,0);
          puVar31 = ecdsa_results + iVar19 * 0x10;
        }
        else {
LAB_00455a58:
          (*(code *)PTR_memset_006aab00)(acStack_53d + 1,0,0x100);
          puVar18 = &sep_19034;
          acStack_53d[1] = 1;
          cVar17 = sep_19034._0_1_;
          while (uVar4 = (uint)cVar17, uVar4 != 0) {
            puVar18 = (undefined2 *)((int)puVar18 + 1);
            cVar17 = *(char *)puVar18;
            acStack_53d[(uVar4 & 0xff) + 1] = '\x01';
          }
          pcVar21 = pcVar23;
          if (acStack_53d[(uVar27 & 0xff) + 1] == '\0') {
            do {
              pcVar21 = pcVar21 + 1;
            } while (acStack_53d[((int)*pcVar21 & 0xffU) + 1] == '\0');
            if ((int)*pcVar21 != 0) goto LAB_00455aec;
          }
          else {
LAB_00455aec:
            *pcVar21 = '\0';
          }
          dVar40 = (double)(*(code *)PTR_strtod_006aaae4)(pcVar23,0);
          if (uVar15 == 0) goto LAB_00456294;
          puVar31 = ecdsa_results + iVar19 * 0x10;
        }
      }
      *(double *)(puVar31 + 8) =
           DAT_0063fac0 / (DAT_0063fac0 / *(double *)(puVar31 + 8) + DAT_0063fac0 / dVar40);
      goto LAB_00454ce8;
    }
LAB_00454d6c:
    uVar15 = uVar15 + 1;
    local_2950 = ZEXT48(local_2950._0_4_ + 1) << 0x20;
    (*(code *)PTR_fclose_006aaaa4)(uVar20);
  } while ((int)uVar15 < (int)local_2988._0_4_);
  (*(code *)PTR_free_006aabf8)(puVar13);
  uVar15 = (uint)local_2948._0_4_;
  if (mr == 0) {
    local_28ec = 0;
LAB_00454824:
    puVar16 = PTR_stdout_006aaad4;
    uVar33 = *puVar34;
    uVar20 = (*(code *)PTR_SSLeay_version_006a8bb0)(0);
    (*(code *)PTR___fprintf_chk_006aaa8c)(uVar33,1,"%s\n",uVar20);
    uVar33 = *puVar34;
    uVar20 = (*(code *)PTR_SSLeay_version_006a8bb0)(3);
    (*(code *)PTR___fprintf_chk_006aaa8c)(uVar33,1,"%s\n",uVar20);
    (*(code *)PTR___printf_chk_006aaad0)(1,"options:");
    uVar20 = (*(code *)PTR_BN_options_006a8bb4)();
    (*(code *)PTR___printf_chk_006aaad0)(1,&DAT_0063f588,uVar20);
    uVar20 = (*(code *)PTR_RC4_options_006a8bb8)();
    (*(code *)PTR___printf_chk_006aaad0)(1,&DAT_0063f588,uVar20);
    uVar20 = (*(code *)PTR_DES_options_006a8bbc)();
    (*(code *)PTR___printf_chk_006aaad0)(1,&DAT_0063f588,uVar20);
    uVar20 = (*(code *)PTR_AES_options_006a8bc0)();
    (*(code *)PTR___printf_chk_006aaad0)(1,&DAT_0063f588,uVar20);
    uVar20 = (*(code *)PTR_idea_options_006a8bc4)();
    (*(code *)PTR___printf_chk_006aaad0)(1,&DAT_0063f588,uVar20);
    uVar20 = (*(code *)PTR_BF_options_006a8bc8)();
    (*(code *)PTR___printf_chk_006aaad0)(1,&DAT_0063f588,uVar20);
    uVar33 = *puVar34;
    uVar20 = (*(code *)PTR_SSLeay_version_006a8bb0)(2);
    (*(code *)PTR___fprintf_chk_006aaa8c)(uVar33,1,&DAT_0063f58c,uVar20);
    uVar15 = (uint)local_2980._0_4_;
    if (local_28ec != 0) {
      if (mr == 0) {
        (*(code *)PTR_fwrite_006aab7c)
                  ("The \'numbers\' are in 1000s of bytes per second processed.\n",1,0x3a,
                   *(undefined4 *)puVar16);
        (*(code *)PTR_fwrite_006aab7c)("type        ",1,0xc,*(undefined4 *)puVar16);
      }
      else {
LAB_00453ce8:
        (*(code *)PTR_fwrite_006aab7c)(&DAT_0063f594,1,2,*local_2980._0_4_);
      }
      puVar31 = lengths;
      do {
        if (mr == 0) {
          pcVar23 = "%7d bytes";
        }
        else {
          pcVar23 = ":%d";
        }
        uVar20 = *(undefined4 *)puVar31;
        puVar31 = (undefined1 *)((int)puVar31 + 4);
        (*(code *)PTR___fprintf_chk_006aaa8c)(*local_2980._0_4_,1,pcVar23,uVar20);
      } while (puVar31 != "string to make the random number generator think it has entropy");
      (*(code *)PTR_fputc_006aaab0)(10,*local_2980._0_4_);
    }
  }
LAB_00452f7c:
  local_2948 = 0x63f94000000000;
  local_2958 = 0x6ab39800000000;
  local_28f0 = (double *)(results + 0x28);
  local_2928 = ecdh_results;
  local_2978 = names;
  iVar19 = 0;
  piVar9 = local_2924;
  dVar39 = DAT_0063fac8;
  do {
    puVar16 = PTR_stdout_006aaad4;
    if (*piVar9 != 0) {
      if (mr == 0) {
        (*(code *)PTR___fprintf_chk_006aaa8c)
                  (*(undefined4 *)PTR_stdout_006aaad4,1,"%-13s",*(undefined4 *)local_2978);
      }
      else {
        (*(code *)PTR___fprintf_chk_006aaa8c)
                  (*(undefined4 *)PTR_stdout_006aaad4,1,"+F:%d:%s",iVar19,*(undefined4 *)local_2978)
        ;
      }
      pdVar30 = local_28f0 + -5;
      do {
        if (dVar39 < *pdVar30) {
          if (mr != 0) {
            uVar20 = *(undefined4 *)puVar16;
            goto LAB_00453008;
          }
          (*(code *)PTR___fprintf_chk_006aaa8c)(*(undefined4 *)puVar16,1," %11.2fk");
        }
        else {
          uVar20 = *(undefined4 *)puVar16;
          if (mr == 0) {
            pcVar23 = " %11.2f ";
          }
          else {
LAB_00453008:
            pcVar23 = ":%.2f";
          }
          (*(code *)PTR___fprintf_chk_006aaa8c)(uVar20,1,pcVar23);
        }
        pdVar30 = pdVar30 + 1;
      } while (local_28f0 != pdVar30);
      (*(code *)PTR_fputc_006aaab0)(10,*(undefined4 *)puVar16);
    }
    iVar19 = iVar19 + 1;
    piVar9 = piVar9 + 1;
    local_28f0 = local_28f0 + 5;
    local_2978 = (undefined1 *)((int)local_2978 + 4);
  } while (iVar19 != 0x1e);
  if (local_288c[0] == (char *)0x0) {
    if (local_288c[1] == (char *)0x0) {
      bVar2 = true;
      if (local_2884 != 0) {
        local_2980 = ZEXT48(PTR_stdout_006aaad4) << 0x20;
        goto LAB_00453838;
      }
    }
    else {
      local_2980 = ZEXT48(PTR_stdout_006aaad4) << 0x20;
LAB_004537d8:
      bVar2 = true;
      if (mr == 0) {
        (*(code *)PTR___printf_chk_006aaad0)
                  (1,"%18ssign    verify    sign/s verify/s\n",&DAT_0063f0b8);
        goto LAB_004530d0;
      }
LAB_004537e0:
      (*(code *)PTR___fprintf_chk_006aaa8c)(*local_2980._0_4_,1,"+F2:%u:%u:%f:%f\n",1);
LAB_00453824:
      if (local_2884 != 0) {
        if (!bVar2) goto LAB_00454030;
LAB_00453838:
        bVar2 = true;
        if (mr == 0) {
          (*(code *)PTR___printf_chk_006aaad0)
                    (1,"%18ssign    verify    sign/s verify/s\n",&DAT_0063f0b8);
          goto LAB_00454030;
        }
        goto LAB_00453844;
      }
    }
LAB_00453884:
    if (local_2880 != 0) {
      if (bVar2) {
        if (mr == 0) {
          local_2980 = ZEXT48(PTR_stdout_006aaad4) << 0x20;
          (*(code *)PTR___printf_chk_006aaad0)
                    (1,"%18ssign    verify    sign/s verify/s\n",&DAT_0063f0b8);
          goto LAB_00453144;
        }
        local_2980 = ZEXT48(PTR_stdout_006aaad4) << 0x20;
      }
      else {
        local_2980 = ZEXT48(PTR_stdout_006aaad4) << 0x20;
LAB_00453144:
        if (mr == 0) {
          (*(code *)PTR___fprintf_chk_006aaa8c)
                    (*local_2980._0_4_,1,"rsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x1000,
                     rsa_results._48_8_,rsa_results._56_8_,DAT_0063fac0 / rsa_results._48_8_,
                     DAT_0063fac0 / rsa_results._56_8_);
          goto LAB_004538e8;
        }
      }
      (*(code *)PTR___fprintf_chk_006aaa8c)(*local_2980._0_4_,1,"+F2:%u:%u:%f:%f\n",3);
    }
  }
  else {
    bVar2 = true;
    if (mr == 0) {
      (*(code *)PTR___printf_chk_006aaad0)
                (1,"%18ssign    verify    sign/s verify/s\n",&DAT_0063f0b8);
      if (mr != 0) {
        bVar2 = false;
        goto LAB_00453070;
      }
      local_2980 = ZEXT48(PTR_stdout_006aaad4) << 0x20;
      (*(code *)PTR___fprintf_chk_006aaa8c)
                (*(undefined4 *)PTR_stdout_006aaad4,1,"rsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",
                 0x200,rsa_results._0_8_,rsa_results._8_8_,DAT_0063fac0 / rsa_results._0_8_,
                 DAT_0063fac0 / rsa_results._8_8_);
      if (local_288c[1] != (char *)0x0) goto LAB_004530d0;
      bVar2 = false;
      if (local_2884 == 0) goto LAB_00453884;
LAB_00454030:
      if (mr != 0) {
        bVar2 = false;
LAB_00453844:
        (*(code *)PTR___fprintf_chk_006aaa8c)(*local_2980._0_4_,1,"+F2:%u:%u:%f:%f\n",2);
        goto LAB_00453884;
      }
      (*(code *)PTR___fprintf_chk_006aaa8c)
                (*local_2980._0_4_,1,"rsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x800,
                 rsa_results._32_8_,rsa_results._40_8_,DAT_0063fac0 / rsa_results._32_8_,
                 DAT_0063fac0 / rsa_results._40_8_);
      if (local_2880 == 0) goto LAB_004538e8;
      goto LAB_00453144;
    }
LAB_00453070:
    local_2980 = ZEXT48(PTR_stdout_006aaad4) << 0x20;
    (*(code *)PTR___fprintf_chk_006aaa8c)
              (*(undefined4 *)PTR_stdout_006aaad4,1,"+F2:%u:%u:%f:%f\n",0);
    if (local_288c[1] == (char *)0x0) goto LAB_00453824;
    if (bVar2) goto LAB_004537d8;
LAB_004530d0:
    if (mr != 0) {
      bVar2 = false;
      goto LAB_004537e0;
    }
    (*(code *)PTR___fprintf_chk_006aaa8c)
              (*local_2980._0_4_,1,"rsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x400,
               rsa_results._16_8_,rsa_results._24_8_,DAT_0063fac0 / rsa_results._16_8_,
               DAT_0063fac0 / rsa_results._24_8_);
    if (local_2884 != 0) goto LAB_00454030;
    if (local_2880 != 0) goto LAB_00453144;
  }
LAB_004538e8:
  if (local_28b4[3] == 0) {
    if (local_28b4[4] == 0) {
      if (local_28b4[5] == 0) goto LAB_00453a18;
      local_2980 = ZEXT48(PTR_stdout_006aaad4) << 0x20;
    }
    else {
      local_2980 = ZEXT48(PTR_stdout_006aaad4) << 0x20;
LAB_00453eec:
      bVar2 = true;
      if (mr == 0) {
        (*(code *)PTR___printf_chk_006aaad0)
                  (1,"%18ssign    verify    sign/s verify/s\n",&DAT_0063f0b8);
        goto LAB_0045395c;
      }
LAB_00453ef4:
      (*(code *)PTR___fprintf_chk_006aaa8c)(*local_2980._0_4_,1,"+F3:%u:%u:%f:%f\n",1);
LAB_00453f38:
      if (local_28b4[5] == 0) goto LAB_00453a18;
      if (!bVar2) goto LAB_004539c4;
    }
    if (mr == 0) {
      (*(code *)PTR___printf_chk_006aaad0)
                (1,"%18ssign    verify    sign/s verify/s\n",&DAT_0063f0b8);
      goto LAB_004539c4;
    }
  }
  else {
    bVar2 = true;
    if (mr == 0) {
      (*(code *)PTR___printf_chk_006aaad0)
                (1,"%18ssign    verify    sign/s verify/s\n",&DAT_0063f0b8);
      if (mr != 0) {
        bVar2 = false;
        goto LAB_004538fc;
      }
      local_2980 = ZEXT48(PTR_stdout_006aaad4) << 0x20;
      (*(code *)PTR___fprintf_chk_006aaa8c)
                (*(undefined4 *)PTR_stdout_006aaad4,1,"dsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",
                 0x200,dsa_results._0_8_,dsa_results._8_8_,DAT_0063fac0 / dsa_results._0_8_,
                 DAT_0063fac0 / dsa_results._8_8_);
      if (local_28b4[4] != 0) goto LAB_0045395c;
    }
    else {
LAB_004538fc:
      local_2980 = ZEXT48(PTR_stdout_006aaad4) << 0x20;
      (*(code *)PTR___fprintf_chk_006aaa8c)
                (*(undefined4 *)PTR_stdout_006aaad4,1,"+F3:%u:%u:%f:%f\n",0);
      if (local_28b4[4] == 0) goto LAB_00453f38;
      if (bVar2) goto LAB_00453eec;
LAB_0045395c:
      if (mr != 0) {
        bVar2 = false;
        goto LAB_00453ef4;
      }
      (*(code *)PTR___fprintf_chk_006aaa8c)
                (*local_2980._0_4_,1,"dsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x400,
                 dsa_results._16_8_,dsa_results._24_8_,DAT_0063fac0 / dsa_results._16_8_,
                 DAT_0063fac0 / dsa_results._24_8_);
    }
    if (local_28b4[5] == 0) goto LAB_00453a18;
LAB_004539c4:
    if (mr == 0) {
      (*(code *)PTR___fprintf_chk_006aaa8c)
                (*local_2980._0_4_,1,"dsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x800,
                 dsa_results._32_8_,dsa_results._40_8_,DAT_0063fac0 / dsa_results._32_8_,
                 DAT_0063fac0 / dsa_results._40_8_);
      goto LAB_00453a18;
    }
  }
  (*(code *)PTR___fprintf_chk_006aaa8c)(*local_2980._0_4_,1,"+F3:%u:%u:%f:%f\n",2);
LAB_00453a18:
  local_2948._0_4_ = test_curves_bits_17828;
  local_2988 = (ulonglong)uVar15 << 0x20;
  local_298c = "+F4:%u:%u:%f:%f\n";
  iVar19 = 0;
  local_2978 = "s\n";
  bVar2 = true;
  piVar9 = local_2908;
  puVar36 = (undefined4 *)local_2948._0_4_;
LAB_00453ac0:
  do {
    if (*piVar9 != 0) {
      if (bVar2) {
        bVar2 = true;
        if (mr == 0) {
          (*(code *)PTR___printf_chk_006aaad0)
                    (1,"%30ssign    verify    sign/s verify/s\n",&DAT_0063f0b8);
          if (mr == 0) goto LAB_00453adc;
          bVar2 = false;
        }
      }
      else {
        bVar2 = false;
        if (mr == 0) {
LAB_00453adc:
          iVar19 = iVar19 + 1;
          bVar2 = false;
          piVar9 = piVar9 + 1;
          (*(code *)PTR___fprintf_chk_006aaa8c)
                    (*(undefined4 *)PTR_stdout_006aaad4,1,
                     "%4u bit ecdsa (%s) %8.4fs %8.4fs %8.1f %8.1f\n",*puVar36);
          puVar36 = puVar36 + 1;
          if (iVar19 == 0x10) break;
          goto LAB_00453ac0;
        }
      }
      (*(code *)PTR___fprintf_chk_006aaa8c)
                (*(undefined4 *)PTR_stdout_006aaad4,1,"+F4:%u:%u:%f:%f\n",iVar19);
    }
    iVar19 = iVar19 + 1;
    piVar9 = piVar9 + 1;
    puVar36 = puVar36 + 1;
  } while (iVar19 != 0x10);
  iVar19 = 0;
  local_2970 = (char **)0x1;
  unaff_s8 = "+F5:%u:%u:%f:%f\n";
  piVar9 = local_2904;
  puVar31 = local_2928;
LAB_00453bd4:
  do {
    puVar36 = (undefined4 *)local_2948._0_4_;
    puVar29 = puVar31;
    piVar32 = piVar9;
    if (*piVar32 != 0) {
      if (local_2970 == (char **)0x0) {
        local_2970 = (char **)0x0;
        if (mr == 0) {
LAB_00453bf0:
          iVar19 = iVar19 + 1;
          local_2970 = (char **)0x0;
          (*(code *)PTR___fprintf_chk_006aaa8c)
                    (*(undefined4 *)PTR_stdout_006aaad4,1,"%4u bit ecdh (%s) %8.4fs %8.1f\n",
                     *puVar36);
          piVar9 = piVar32 + 1;
          puVar31 = puVar29 + 8;
          local_2948._0_4_ = (undefined1 *)(puVar36 + 1);
          if (iVar19 == 0x10) break;
          goto LAB_00453bd4;
        }
      }
      else {
        local_2970 = (char **)0x1;
        if (mr == 0) {
          (*(code *)PTR___printf_chk_006aaad0)(1,"%30sop      op/s\n",&DAT_0063f0b8);
          if (mr == 0) goto LAB_00453bf0;
          local_2970 = (char **)0x0;
        }
      }
      (*(code *)PTR___fprintf_chk_006aaa8c)
                (*(undefined4 *)PTR_stdout_006aaad4,1,"+F5:%u:%u:%f:%f\n",iVar19);
    }
    iVar19 = iVar19 + 1;
    piVar9 = piVar32 + 1;
    puVar31 = puVar29 + 8;
    local_2948._0_4_ = (undefined1 *)(puVar36 + 1);
  } while (iVar19 != 0x10);
  puVar36 = puVar36 + 1;
  ppcVar8 = (char **)(puVar29 + 8);
  puVar31 = (undefined1 *)(piVar32 + 1);
  local_290c = 0;
  local_2980._0_4_ = (undefined4 *)uVar15;
LAB_0044e580:
  (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar5);
  (*(code *)PTR_CRYPTO_free_006a7f88)(local_2980._0_4_);
  (*(code *)PTR_CRYPTO_free_006a7f88)(local_295c);
  unaff_s6 = local_2970;
  goto LAB_0044e07c;
LAB_004547c0:
  (*(code *)PTR_HMAC_CTX_cleanup_006a8bac)(auStack_2420);
  local_2930 = dVar39;
  goto LAB_0044f048;
LAB_00454534:
  (*(code *)PTR_CRYPTO_gcm128_release_006a8b9c)(uVar20);
  goto LAB_00450c20;
}

