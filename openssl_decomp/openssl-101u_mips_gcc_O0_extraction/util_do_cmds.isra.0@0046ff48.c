
int util_do_cmds_isra_0(char *param_1,char **param_2,char **param_3)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined *puVar9;
  undefined4 uVar10;
  char **ppcVar11;
  undefined4 uVar12;
  char *pcVar13;
  char *pcVar14;
  char **ppcVar15;
  int iVar16;
  char cVar17;
  char *pcVar18;
  undefined *unaff_s0;
  undefined *puVar19;
  undefined1 *puVar20;
  int unaff_s1;
  uint uVar21;
  int unaff_s3;
  char **ppcVar22;
  char *pcVar23;
  int unaff_s6;
  int unaff_s7;
  code *pcVar24;
  char *unaff_s8;
  undefined *puStack_1cc;
  undefined *puStack_1c8;
  int iStack_1c4;
  int iStack_1c0;
  char *pcStack_1bc;
  undefined *puStack_1b8;
  char **ppcStack_1b4;
  char *pcStack_1b0;
  char *pcStack_1ac;
  undefined *puStack_1a8;
  undefined4 *puStack_1a4;
  char *pcStack_1a0;
  char *pcStack_19c;
  char *pcStack_198;
  char *pcStack_194;
  char *pcStack_190;
  char *pcStack_188;
  int iStack_184;
  undefined *puStack_180;
  int iStack_17c;
  char **ppcStack_178;
  int iStack_174;
  char **ppcStack_170;
  char *pcStack_16c;
  int iStack_168;
  int iStack_164;
  char *pcStack_160;
  code *pcStack_15c;
  undefined *local_148;
  char *local_13c;
  char *local_138;
  int *local_134;
  char local_12c [256];
  int local_2c;
  
  local_148 = &_gp;
  local_134 = (int *)PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppcVar15 = param_2;
  pcVar18 = (char *)param_2;
  iVar4 = (*(code *)PTR_sk_num_006a6e2c)();
  if (iVar4 < 0) {
    pcVar18 = "[Error]: internal stack error\n";
    ppcVar15 = param_3;
    (**(code **)(local_148 + -0x7fa8))();
  }
  else {
    unaff_s1 = 0;
    unaff_s3 = iVar4;
    if (iVar4 != 0) {
      unaff_s8 = local_12c;
      local_13c = "[Failure]: %s\n";
      local_138 = "[Success]: %s\n";
      puVar19 = unaff_s0;
LAB_00470010:
      pcVar24 = *(code **)(local_148 + -0x7fbc);
      do {
        unaff_s6 = (*pcVar24)(param_2,unaff_s1);
        unaff_s7 = (**(code **)(local_148 + -0x53b8))(unaff_s6,0x3a);
        if (unaff_s7 == 0) {
          iVar5 = (**(code **)(local_148 + -0x7208))(param_1,unaff_s6,0,0);
          if (iVar5 == 0) goto LAB_0046ffe0;
          ppcVar15 = param_3;
          pcVar18 = local_138;
          (**(code **)(local_148 + -0x7fa8))(param_3,local_138,unaff_s6);
        }
        else {
          unaff_s0 = (undefined *)(unaff_s7 - unaff_s6);
          if (0xfe < (int)unaff_s0) {
            pcVar18 = "[Error]: command name too long\n";
            ppcVar15 = param_3;
            (**(code **)(local_148 + -0x7fa8))();
            break;
          }
          (**(code **)(local_148 + -0x5398))(unaff_s8,unaff_s6,unaff_s0,0x100);
          puVar19 = &stack0xffffffd8 + (int)unaff_s0;
          local_12c[(int)unaff_s0] = '\0';
          iVar5 = (**(code **)(local_148 + -0x7208))(param_1,unaff_s8,unaff_s7 + 1,0);
          if (iVar5 == 0) goto LAB_0046ffe0;
          ppcVar15 = param_3;
          pcVar18 = local_138;
          (**(code **)(local_148 + -0x7fa8))(param_3,local_138,unaff_s6);
        }
        unaff_s1 = unaff_s1 + 1;
        pcVar24 = *(code **)(local_148 + -0x7fbc);
        unaff_s0 = puVar19;
        if (iVar4 == unaff_s1) break;
      } while( true );
    }
  }
LAB_004700bc:
  if (local_2c == *local_134) {
    return *local_134;
  }
  pcStack_15c = engine_main;
  (**(code **)(local_148 + -0x5330))();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  puVar19 = PTR_bio_err_006a6e3c;
  iStack_184 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_180 = unaff_s0;
  iStack_17c = unaff_s1;
  ppcStack_178 = param_3;
  iStack_174 = unaff_s3;
  ppcStack_170 = param_2;
  pcStack_16c = param_1;
  iStack_168 = unaff_s6;
  iStack_164 = unaff_s7;
  pcStack_160 = unaff_s8;
  puVar6 = (undefined *)(*(code *)PTR_sk_new_null_006a6fa4)();
  uVar7 = (*(code *)PTR_sk_new_null_006a6fa4)();
  uVar8 = (*(code *)PTR_sk_new_null_006a6fa4)();
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  (*(code *)PTR_SSL_load_error_strings_006a7588)();
  iVar4 = *(int *)puVar19;
  if (iVar4 == 0) {
    iVar4 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *(int *)puVar19 = iVar4;
  }
  iVar4 = load_config(iVar4,0);
  if (iVar4 == 0) {
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar19);
    (*(code *)PTR_sk_pop_free_006a7058)(puVar6,identity);
    (*(code *)PTR_sk_pop_free_006a7058)(uVar7,identity);
    iVar4 = 1;
    (*(code *)PTR_sk_pop_free_006a7058)(uVar8,identity);
    puVar9 = puVar6;
    goto LAB_00470298;
  }
  puStack_1a4 = (undefined4 *)PTR_stdout_006a99c8;
  iVar4 = (int)ppcVar15 + -1;
  pcVar18 = (char *)((int)pcVar18 + 4);
  puVar9 = (undefined *)(*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
  puStack_1b8 = puVar9;
  if (iVar4 < 1) {
    pcStack_198 = (char *)0x0;
    pcVar14 = (char *)0x0;
    iStack_1c0 = 0;
    iStack_1c4 = 0;
    pcVar13 = pcStack_198;
  }
  else {
    iStack_1c0 = 0;
    iStack_1c4 = 0;
    puStack_1cc = &DAT_00643de4;
    pcVar14 = (char *)0x0;
    pcStack_1bc = "-check_ss_sig";
    param_1 = (char *)0x0;
    do {
      unaff_s8 = *(char **)pcVar18;
      iVar5 = (*(code *)PTR_strncmp_006a9970)(unaff_s8,&DAT_00643ddc,2);
      ppcVar15 = (char **)pcVar18;
      if (iVar5 == 0) {
        pcVar14 = (char *)0x0;
        pcVar13 = unaff_s8;
        do {
          pcVar23 = pcVar14;
          pcVar13 = pcVar13 + 1;
          pcVar14 = pcVar23 + 1;
        } while (*pcVar13 == 'v');
        pcVar14 = (char *)(*(code *)PTR_strlen_006a9a24)();
        if ((pcVar23 < pcVar14) || (4 < (int)pcVar14)) goto LAB_004706f0;
      }
      else {
        cVar17 = *unaff_s8;
        if (((cVar17 == '-') && (unaff_s8[1] == 'c')) && (unaff_s8[2] == '\0')) {
          iStack_1c4 = 1;
        }
        else {
          iVar5 = (*(code *)PTR_strncmp_006a9970)(unaff_s8,&DAT_00643de0,2);
          if (iVar5 == 0) {
            pcVar23 = (char *)0x0;
            pcVar13 = unaff_s8;
            do {
              param_1 = pcVar23;
              pcVar13 = pcVar13 + 1;
              pcVar23 = param_1 + 1;
            } while (*pcVar13 == 't');
            pcVar13 = (char *)(*(code *)PTR_strlen_006a9a24)();
            if ((param_1 < pcVar13) || (param_1 = pcVar13 + -1, 1 < (int)param_1))
            goto LAB_004706f0;
            iStack_1c0 = 1;
          }
          else {
            iVar5 = (*(code *)PTR_strcmp_006a9b18)(unaff_s8,&DAT_00643de4);
            if (iVar5 == 0) {
              iVar4 = iVar4 + -1;
              if (iVar4 == 0) goto LAB_004706f0;
              (*(code *)PTR_sk_push_006a6fa8)(uVar7,*(char **)((int)pcVar18 + 4));
              ppcVar15 = (char **)((int)pcVar18 + 4);
            }
            else {
              iVar5 = (*(code *)PTR_strcmp_006a9b18)(unaff_s8,"-post");
              if (iVar5 == 0) {
                iVar4 = iVar4 + -1;
                ppcVar15 = (char **)((int)pcVar18 + 4);
                if (iVar4 == 0) goto LAB_004706f0;
                (*(code *)PTR_sk_push_006a6fa8)(uVar8,*(char **)((int)pcVar18 + 4));
              }
              else {
                iVar5 = (*(code *)PTR_strncmp_006a9970)(unaff_s8,&DAT_006412e0,2);
                if ((iVar5 == 0) ||
                   (((cVar17 == '-' && (unaff_s8[1] == '?')) && (unaff_s8[2] == '\0')))) {
LAB_004706f0:
                  if (engine_usage._0_4_ != 0) {
                    puVar20 = engine_usage;
                    do {
                      puVar20 = (undefined1 *)((int)puVar20 + 4);
                      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar19,"%s");
                    } while (*(int *)puVar20 != 0);
                  }
                  ppcStack_1b4 = (char **)0x470000;
                  puStack_1c8 = puVar6;
                  goto LAB_00470734;
                }
                (*(code *)PTR_sk_push_006a6fa8)(puVar6,unaff_s8);
              }
            }
          }
        }
      }
      iVar4 = iVar4 + -1;
      pcVar18 = (char *)(ppcVar15 + 1);
      pcVar13 = param_1;
    } while (iVar4 != 0);
  }
  pcStack_198 = pcVar13;
  iVar4 = (*(code *)PTR_sk_num_006a6e2c)(puVar6);
  if (iVar4 == 0) {
    for (iVar4 = (*(code *)PTR_ENGINE_get_first_006a7d84)(); iVar4 != 0;
        iVar4 = (*(code *)PTR_ENGINE_get_next_006a7d88)(iVar4)) {
      uVar10 = (*(code *)PTR_ENGINE_get_id_006a7bd4)(iVar4);
      (*(code *)PTR_sk_push_006a6fa8)(puVar6,uVar10);
    }
  }
  puStack_1c8 = (undefined *)0x0;
  ppcStack_1b4 = (char **)0x470000;
  pcStack_1ac = "-check_ss_sig";
  pcStack_1b0 = "engine.c";
  pcStack_194 = "<no description>";
  pcStack_19c = "-check_ss_sig";
  puStack_1a8 = &DAT_0063eb80;
  iVar4 = (*(code *)PTR_sk_num_006a6e2c)(puVar6);
  puStack_1cc = puVar6;
  pcStack_1bc = pcVar14;
  if (iVar4 < 1) goto LAB_00470564;
LAB_00470450:
  uVar10 = (*(code *)PTR_sk_value_006a6e24)(puStack_1cc,puStack_1c8);
  ppcVar11 = (char **)(*(code *)PTR_ENGINE_by_id_006a6e9c)(uVar10);
  pcVar18 = (char *)ppcVar11;
  if (ppcVar11 == (char **)0x0) {
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar19);
    goto LAB_0047053c;
  }
  uVar12 = (*(code *)PTR_ENGINE_get_name_006a7d60)(ppcVar11);
  (*(code *)PTR_BIO_printf_006a6e38)(puVar9,pcStack_1ac + 0x3dfc,uVar10,uVar12);
  util_do_cmds_isra_0(ppcVar11,uVar7,puVar9);
  uVar12 = (*(code *)PTR_ENGINE_get_id_006a7bd4)(ppcVar11);
  iVar4 = (*(code *)PTR_strcmp_006a9b18)(uVar12,uVar10);
  if (iVar4 != 0) {
    uVar10 = (*(code *)PTR_ENGINE_get_id_006a7bd4)(ppcVar11);
    uVar12 = (*(code *)PTR_ENGINE_get_name_006a7d60)(ppcVar11);
    (*(code *)PTR_BIO_printf_006a6e38)(puVar9,"Loaded: (%s) %s\n",uVar10,uVar12);
  }
  puVar6 = puStack_1cc;
  if (iStack_1c4 != 0) {
    iVar4 = (*(code *)PTR_ENGINE_get_RSA_006a7d64)(ppcVar11);
    if (iVar4 == 0) {
      iVar4 = (*(code *)PTR_ENGINE_get_DSA_006a7d68)(ppcVar11);
      if (iVar4 != 0) {
        pcVar13 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x100,pcStack_1b0,0x68);
        if (pcVar13 == (char *)0x0) goto LAB_00470734;
        *pcVar13 = '\0';
        ppcVar22 = (char **)0x100;
        ppcVar15 = (char **)0x100;
LAB_0047083c:
        (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar13,"DSA",ppcVar22);
        goto LAB_00470858;
      }
      iVar4 = (*(code *)PTR_ENGINE_get_DH_006a7d6c)(ppcVar11);
      if (iVar4 != 0) {
        pcVar13 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x100,pcStack_1b0,0x68);
        if (pcVar13 == (char *)0x0) goto LAB_00470734;
        *pcVar13 = '\0';
        ppcVar22 = (char **)0x100;
        ppcVar15 = (char **)0x100;
        goto LAB_00470894;
      }
      iVar4 = (*(code *)PTR_ENGINE_get_RAND_006a7d70)(ppcVar11);
      if (iVar4 != 0) {
        pcVar13 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x100,pcStack_1b0,0x68);
        if (pcVar13 == (char *)0x0) goto LAB_00470734;
        *pcVar13 = '\0';
        ppcVar22 = (char **)0x100;
        ppcVar15 = (char **)0x100;
        goto LAB_004708ec;
      }
      pcVar13 = (char *)0x0;
      ppcVar15 = (char **)0x100;
    }
    else {
      pcVar13 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x100,pcStack_1b0,0x68);
      puVar2 = PTR_BUF_strlcat_006a6f68;
      if (pcVar13 == (char *)0x0) goto LAB_00470734;
      *pcVar13 = '\0';
      (*(code *)puVar2)(pcVar13,"RSA",0x100);
      iVar4 = (*(code *)PTR_ENGINE_get_DSA_006a7d68)(ppcVar11);
      if (iVar4 != 0) {
        iVar4 = (*(code *)PTR_strlen_006a9a24)(pcVar13);
        if (iVar4 + 3U < 0x100) {
          ppcVar22 = (char **)0x100;
          ppcVar15 = (char **)0x100;
        }
        else {
          pcVar13 = (char *)(*(code *)PTR_CRYPTO_realloc_006a7b58)(pcVar13,0x200,pcStack_1b0,0x70);
          if (pcVar13 == (char *)0x0) goto LAB_00470734;
          ppcVar22 = (char **)0x200;
          ppcVar15 = (char **)0x200;
        }
        if (*pcVar13 != '\0') {
          (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar13,", ",ppcVar22);
        }
        goto LAB_0047083c;
      }
      ppcVar22 = (char **)0x100;
      ppcVar15 = (char **)0x100;
LAB_00470858:
      iVar4 = (*(code *)PTR_ENGINE_get_DH_006a7d6c)(ppcVar11);
      if (iVar4 == 0) {
        iVar4 = (*(code *)PTR_ENGINE_get_RAND_006a7d70)(ppcVar11);
      }
      else {
        iVar4 = (*(code *)PTR_strlen_006a9a24)(pcVar13);
        if (ppcVar22 <= (char **)(iVar4 + 2)) {
          ppcVar15 = ppcVar15 + 0x40;
          pcVar13 = (char *)(*(code *)PTR_CRYPTO_realloc_006a7b58)(pcVar13,ppcVar15,"engine.c",0x70)
          ;
          ppcVar22 = ppcVar15;
          if (pcVar13 == (char *)0x0) goto LAB_00470734;
        }
        if (*pcVar13 != '\0') {
          (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar13,", ",ppcVar22);
        }
LAB_00470894:
        (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar13,"DH",ppcVar22);
        iVar4 = (*(code *)PTR_ENGINE_get_RAND_006a7d70)(ppcVar11);
      }
      if (iVar4 != 0) {
        iVar4 = (*(code *)PTR_strlen_006a9a24)(pcVar13);
        if (ppcVar22 <= (char **)(iVar4 + 4)) {
          ppcVar15 = ppcVar15 + 0x40;
          pcVar13 = (char *)(*(code *)PTR_CRYPTO_realloc_006a7b58)(pcVar13,ppcVar15,"engine.c",0x70)
          ;
          ppcVar22 = ppcVar15;
          if (pcVar13 == (char *)0x0) goto LAB_00470734;
        }
        if (*pcVar13 != '\0') {
          (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar13,", ",ppcVar22);
        }
LAB_004708ec:
        (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar13,"RAND",ppcVar22);
      }
    }
    pcVar24 = (code *)(*(code *)PTR_ENGINE_get_ciphers_006a7d74)(ppcVar11);
    if ((pcVar24 != (code *)0x0) &&
       (pcVar14 = (char *)(*pcVar24)(ppcVar11,0,&pcStack_188,0), 0 < (int)pcVar14)) {
      pcVar23 = (char *)0x0;
      pcStack_1a0 = ", ";
      do {
        param_1 = (char *)(*(code *)PTR_OBJ_nid2sn_006a709c)
                                    (*(undefined4 *)(pcStack_188 + (int)pcVar23 * 4));
        unaff_s8 = pcVar14;
        pcStack_190 = (char *)ppcVar11;
        if (pcVar13 == (char *)0x0) {
          pcVar13 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x100,pcStack_1b0,0x68);
          puVar2 = PTR_strlen_006a9a24;
          if (pcVar13 == (char *)0x0) goto LAB_00470734;
          *pcVar13 = '\0';
          uVar21 = (*(code *)puVar2)(param_1);
          if (0xff < uVar21) {
            ppcVar22 = (char **)0x200;
            goto LAB_004709e4;
          }
          ppcVar15 = (char **)0x100;
        }
        else {
          iVar4 = (*(code *)PTR_strlen_006a9a24)(pcVar13);
          iVar5 = (*(code *)PTR_strlen_006a9a24)(param_1);
          if ((char **)(iVar4 + iVar5) < ppcVar15) {
            cVar17 = *pcVar13;
          }
          else {
            ppcVar22 = ppcVar15 + 0x40;
            pcVar18 = (char *)ppcVar15;
LAB_004709e4:
            pcVar13 = (char *)(*(code *)PTR_CRYPTO_realloc_006a7b58)
                                        (pcVar13,ppcVar22,"engine.c",0x70);
            if (pcVar13 == (char *)0x0) goto LAB_00470734;
            cVar17 = *pcVar13;
            ppcVar15 = ppcVar22;
          }
          if (cVar17 != '\0') {
            (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar13,", ",ppcVar15);
          }
        }
        pcVar23 = pcVar23 + 1;
        (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar13,param_1,ppcVar15);
        pcVar18 = (char *)ppcVar15;
      } while (pcVar14 != pcVar23);
    }
    pcVar24 = (code *)(*(code *)PTR_ENGINE_get_digests_006a7d7c)(ppcVar11);
    if (pcVar24 == (code *)0x0) {
LAB_00470ee8:
      pcVar24 = (code *)(*(code *)PTR_ENGINE_get_pkey_meths_006a7d80)(ppcVar11);
      if (pcVar24 != (code *)0x0) {
LAB_00470f04:
        pcStack_190 = (char *)&pcStack_188;
        param_1 = (char *)(*pcVar24)(ppcVar11,0,pcStack_190,0);
        if (0 < (int)param_1) {
          pcVar14 = (char *)0x0;
          pcStack_1a0 = ", ";
          do {
            unaff_s8 = (char *)(*(code *)PTR_OBJ_nid2sn_006a709c)
                                         (*(undefined4 *)(pcStack_188 + (int)pcVar14 * 4));
            if (pcVar13 == (char *)0x0) {
              pcVar13 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x100,pcStack_1b0,0x68);
              puVar2 = PTR_strlen_006a9a24;
              pcVar18 = (char *)ppcVar11;
              if (pcVar13 == (char *)0x0) goto LAB_00470734;
              *pcVar13 = '\0';
              uVar21 = (*(code *)puVar2)(unaff_s8);
              if (0xff < uVar21) {
                ppcVar15 = (char **)0x200;
                goto LAB_00470fc8;
              }
              ppcVar15 = (char **)0x100;
            }
            else {
              iVar4 = (*(code *)PTR_strlen_006a9a24)(pcVar13);
              iVar5 = (*(code *)PTR_strlen_006a9a24)(unaff_s8);
              if (ppcVar15 <= (char **)(iVar4 + iVar5)) {
                ppcVar15 = ppcVar15 + 0x40;
LAB_00470fc8:
                pcVar13 = (char *)(*(code *)PTR_CRYPTO_realloc_006a7b58)
                                            (pcVar13,ppcVar15,"engine.c",0x70);
                pcVar18 = (char *)ppcVar11;
                if (pcVar13 == (char *)0x0) goto LAB_00470734;
              }
              if (*pcVar13 != '\0') {
                (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar13,", ",ppcVar15);
                pcStack_190 = (char *)ppcVar15;
              }
            }
            pcVar14 = pcVar14 + 1;
            (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar13,unaff_s8,ppcVar15);
          } while (param_1 != pcVar14);
          goto LAB_00471348;
        }
      }
      if (pcVar13 != (char *)0x0) {
        cVar17 = *pcVar13;
        goto LAB_0047134c;
      }
    }
    else {
      pcStack_190 = (char *)&pcStack_188;
      unaff_s8 = (char *)(*pcVar24)(ppcVar11,0,pcStack_190,0);
      if ((int)unaff_s8 < 1) goto LAB_00470ee8;
      pcVar14 = (char *)0x0;
      pcStack_1a0 = ", ";
      pcVar18 = (char *)ppcVar11;
      do {
        param_1 = (char *)(*(code *)PTR_OBJ_nid2sn_006a709c)
                                    (*(undefined4 *)(pcStack_188 + (int)pcVar14 * 4));
        if (pcVar13 == (char *)0x0) {
          pcVar13 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x100,pcStack_1b0,0x68);
          puVar2 = PTR_strlen_006a9a24;
          if (pcVar13 == (char *)0x0) goto LAB_00470734;
          *pcVar13 = '\0';
          uVar21 = (*(code *)puVar2)(param_1);
          if (0xff < uVar21) {
            ppcVar22 = (char **)0x200;
            goto LAB_00470e0c;
          }
          ppcVar15 = (char **)0x100;
        }
        else {
          iVar4 = (*(code *)PTR_strlen_006a9a24)(pcVar13);
          iVar5 = (*(code *)PTR_strlen_006a9a24)(param_1);
          ppcVar22 = ppcVar15;
          if (ppcVar15 <= (char **)(iVar4 + iVar5)) {
            ppcVar22 = ppcVar15 + 0x40;
            pcVar18 = (char *)ppcVar15;
LAB_00470e0c:
            pcVar13 = (char *)(*(code *)PTR_CRYPTO_realloc_006a7b58)
                                        (pcVar13,ppcVar22,"engine.c",0x70);
            if (pcVar13 == (char *)0x0) goto LAB_00470734;
          }
          ppcVar15 = ppcVar22;
          if (*pcVar13 != '\0') {
            (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar13,", ",ppcVar22);
          }
        }
        pcVar14 = pcVar14 + 1;
        (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar13,param_1,ppcVar15);
        pcVar18 = (char *)ppcVar15;
      } while (unaff_s8 != pcVar14);
      pcVar24 = (code *)(*(code *)PTR_ENGINE_get_pkey_meths_006a7d80)(ppcVar11);
      if (pcVar24 != (code *)0x0) goto LAB_00470f04;
LAB_00471348:
      pcStack_1a0 = ", ";
      cVar17 = *pcVar13;
LAB_0047134c:
      if (cVar17 != '\0') {
        (*(code *)PTR_BIO_printf_006a6e38)(puVar9," [%s]\n",pcVar13);
      }
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar13);
  }
  if (iStack_1c0 != 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(puVar9,"%s",puStack_1a8);
    iVar4 = (*(code *)PTR_ENGINE_init_006a7d78)(ppcVar11);
    if (iVar4 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(puVar9,"[ unavailable ]\n");
      if (pcStack_198 != (char *)0x0) {
        (*(code *)PTR_ERR_print_errors_fp_006a7d8c)(*puStack_1a4);
      }
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
    }
    else {
      (*(code *)PTR_BIO_printf_006a6e38)(puVar9,"[ available ]\n");
      util_do_cmds_isra_0(ppcVar11,uVar8,puVar9);
      (*(code *)PTR_ENGINE_finish_006a6fc4)(ppcVar11);
    }
  }
  if ((int)pcStack_1bc < 1) goto LAB_0047052c;
  iVar4 = (*(code *)PTR_ENGINE_ctrl_006a7bc8)(ppcVar11,10,0,0,0);
  if (iVar4 == 0) goto LAB_0047052c;
  iVar4 = (*(code *)PTR_ENGINE_ctrl_006a7bc8)(ppcVar11,0xb,0,0,0);
  if (iVar4 < 1) goto LAB_0047052c;
  pcStack_1a0 = (char *)(*(code *)PTR_sk_new_null_006a6fa4)();
  pcVar18 = (char *)ppcVar11;
  if (pcStack_1a0 != (char *)0x0) {
    iVar5 = 0;
    pcStack_190 = "-check_ss_sig";
    goto LAB_00470b88;
  }
LAB_00470734:
  iVar4 = 1;
  puVar9 = puVar6;
  do {
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar19);
    (*(code *)PTR_sk_pop_free_006a7058)(puVar9,ppcStack_1b4 + -0x30);
    (*(code *)PTR_sk_pop_free_006a7058)(uVar7,ppcStack_1b4 + -0x30);
    (*(code *)PTR_sk_pop_free_006a7058)(uVar8,ppcStack_1b4 + -0x30);
    ppcVar15 = ppcStack_1b4;
    if (puStack_1b8 != (undefined *)0x0) {
      (*(code *)PTR_BIO_free_all_006a6e74)();
    }
LAB_00470298:
    if (iStack_184 == *(int *)puVar3) {
      return iVar4;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    ppcVar11 = (char **)pcVar18;
LAB_00471720:
    uVar21 = (uint)ppcVar15 & 0xfffffff0;
    if (uVar21 == 0) goto LAB_004711c8;
    bVar1 = false;
LAB_004715b4:
    (*(code *)PTR_BIO_printf_006a6e38)(puVar9,"<0x%04X>",uVar21);
LAB_004714b4:
    if (!bVar1) goto LAB_004711c8;
LAB_004714bc:
    (*(code *)PTR_BIO_printf_006a6e38)(puVar9,"  <illegal flags!>");
LAB_004711c8:
    iVar5 = 0;
    (*(code *)PTR_BIO_printf_006a6e38)(puVar9,"\n");
LAB_00471120:
    (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s8);
    if (param_1 != (char *)0x0) goto LAB_00470cd8;
LAB_00470b64:
    iVar4 = (*(code *)PTR_ENGINE_ctrl_006a7bc8)(ppcVar11,0xc,iVar4,0,0);
    if (0 < iVar4) {
LAB_00470b88:
      ppcVar15 = (char **)(*(code *)PTR_ENGINE_ctrl_006a7bc8)(ppcVar11,0x12,iVar4,0,0);
      if ((int)ppcVar15 < 0) {
LAB_004713b4:
        bVar1 = false;
        goto LAB_004713b8;
      }
      if ((((uint)ppcVar15 & 8) != 0) && (pcStack_1bc != (char *)0x4)) {
        (*(code *)PTR_CRYPTO_free_006a6e88)(0);
        goto LAB_00470b64;
      }
      iVar16 = (*(code *)PTR_ENGINE_ctrl_006a7bc8)(ppcVar11,0xe,iVar4,0,0);
      if ((iVar16 < 1) ||
         (unaff_s8 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar16 + 1,pcStack_1b0,0xda),
         param_1 = pcStack_1b0, unaff_s8 == (char *)0x0)) goto LAB_004713b4;
      iVar16 = (*(code *)PTR_ENGINE_ctrl_006a7bc8)(ppcVar11,0xf,iVar4,unaff_s8,0);
      if ((iVar16 < 1) ||
         (iVar16 = (*(code *)PTR_ENGINE_ctrl_006a7bc8)(ppcVar11,0x10,iVar4,0,0), iVar16 < 0)) {
        param_1 = (char *)0x0;
LAB_00471050:
        (*(code *)PTR_sk_pop_free_006a7058)(pcStack_1a0,ppcStack_1b4 + -0x30);
        (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s8);
        pcVar18 = (char *)ppcVar11;
        puVar6 = puStack_1cc;
        if (param_1 != (char *)0x0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)(param_1);
        }
        goto LAB_00470734;
      }
      if (iVar16 == 0) {
        param_1 = (char *)0x0;
      }
      else {
        param_1 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar16 + 1,pcStack_1b0,0xe4);
        if ((param_1 == (char *)0x0) ||
           (iVar16 = (*(code *)PTR_ENGINE_ctrl_006a7bc8)(ppcVar11,0x11,iVar4,param_1,0), iVar16 < 1)
           ) goto LAB_00471050;
      }
      if (iVar5 == 0) {
        iVar16 = (*(code *)PTR_BIO_puts_006a6f58)(puVar9,puStack_1a8);
      }
      else {
        iVar16 = (*(code *)PTR_BIO_printf_006a6e38)(puVar9,", ");
        iVar16 = iVar5 + iVar16;
      }
      if (pcStack_1bc == (char *)0x1) {
        if ((5 < iVar16) &&
           (iVar5 = (*(code *)PTR_strlen_006a9a24)(unaff_s8), 0x4e < iVar5 + iVar16)) {
          (*(code *)PTR_BIO_printf_006a6e38)(puVar9,"\n");
          iVar16 = (*(code *)PTR_BIO_puts_006a6f58)(puVar9,puStack_1a8);
        }
        iVar5 = (*(code *)PTR_BIO_printf_006a6e38)(puVar9,"%s",unaff_s8);
        iVar5 = iVar5 + iVar16;
        goto LAB_00471120;
      }
      if (param_1 == (char *)0x0) {
        (*(code *)PTR_BIO_printf_006a6e38)(puVar9,pcStack_19c + 0x3ea4,unaff_s8,pcStack_194);
        if (pcStack_1bc != (char *)0x2) goto LAB_0047115c;
        iVar5 = 0;
        (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s8);
        goto LAB_00470b64;
      }
      (*(code *)PTR_BIO_printf_006a6e38)(puVar9,pcStack_19c + 0x3ea4,unaff_s8,param_1);
      if (pcStack_1bc == (char *)0x2) {
        iVar5 = 0;
        (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s8);
LAB_00470cd8:
        (*(code *)PTR_CRYPTO_free_006a6e88)(param_1);
        goto LAB_00470b64;
      }
LAB_0047115c:
      (*(code *)PTR_BIO_printf_006a6e38)
                (puVar9,(char **)((int)pcStack_190 + 0x3e40),puStack_1a8,puStack_1a8);
      if (ppcVar15 == (char **)0x0) {
        iVar5 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)(puVar9,"<no flags>\n");
        goto LAB_00471120;
      }
      if (((uint)ppcVar15 & 8) != 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(puVar9,"[Internal] ");
      }
      if (((uint)ppcVar15 & 1) == 0) {
        bVar1 = false;
        if (((uint)ppcVar15 & 2) != 0) goto LAB_00471484;
        if (((uint)ppcVar15 & 4) == 0) goto LAB_00471720;
        (*(code *)PTR_BIO_printf_006a6e38)(puVar9,"NO_INPUT");
joined_r0x00471590:
        if (((uint)ppcVar15 & 0xfffffff0) != 0) {
          bVar1 = false;
          goto LAB_004715a0;
        }
        goto LAB_004711c8;
      }
      (*(code *)PTR_BIO_printf_006a6e38)(puVar9,"NUMERIC");
      if (((uint)ppcVar15 & 2) == 0) {
        if (((uint)ppcVar15 & 4) != 0) goto LAB_004715d4;
        goto joined_r0x00471590;
      }
      bVar1 = true;
      (*(code *)PTR_BIO_printf_006a6e38)(puVar9,&DAT_00643e74);
LAB_00471484:
      (*(code *)PTR_BIO_printf_006a6e38)(puVar9,"STRING");
      if (((uint)ppcVar15 & 4) == 0) {
        if (((uint)ppcVar15 & 0xfffffff0) == 0) goto LAB_004714b4;
        goto LAB_004715a0;
      }
LAB_004715d4:
      bVar1 = true;
      (*(code *)PTR_BIO_printf_006a6e38)(puVar9,&DAT_00643e74);
      (*(code *)PTR_BIO_printf_006a6e38)(puVar9,"NO_INPUT");
      if (((uint)ppcVar15 & 0xfffffff0) != 0) goto LAB_004715a0;
      goto LAB_004714bc;
    }
    if (iVar5 < 1) {
      bVar1 = true;
    }
    else {
      bVar1 = true;
      (*(code *)PTR_BIO_printf_006a6e38)(puVar9,"\n");
    }
LAB_004713b8:
    (*(code *)PTR_sk_pop_free_006a7058)(pcStack_1a0,ppcStack_1b4 + -0x30);
    pcVar18 = (char *)ppcVar11;
    puVar6 = puStack_1cc;
    if (!bVar1) goto LAB_00470734;
LAB_0047052c:
    (*(code *)PTR_ENGINE_free_006a6e84)(ppcVar11);
    pcVar18 = (char *)ppcVar11;
LAB_0047053c:
    puStack_1c8 = puStack_1c8 + 1;
    iVar4 = (*(code *)PTR_sk_num_006a6e2c)(puStack_1cc);
    if ((int)puStack_1c8 < iVar4) goto LAB_00470450;
LAB_00470564:
    iVar4 = 0;
    puVar9 = puStack_1cc;
  } while( true );
LAB_0046ffe0:
  unaff_s1 = unaff_s1 + 1;
  pcVar18 = local_13c;
  (**(code **)(local_148 + -0x7fa8))(param_3,local_13c,unaff_s6);
  ppcVar15 = param_3;
  (**(code **)(local_148 + -0x7fa0))();
  unaff_s0 = puVar19;
  if (iVar4 == unaff_s1) goto LAB_004700bc;
  goto LAB_00470010;
LAB_004715a0:
  uVar21 = (uint)ppcVar15 & 0xfffffff0;
  (*(code *)PTR_BIO_printf_006a6e38)(puVar9,&DAT_00643e74);
  goto LAB_004715b4;
}

