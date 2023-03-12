
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
  char **ppcStack_190;
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
  local_134 = (int *)PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  ppcVar15 = param_2;
  pcVar18 = (char *)param_2;
  iVar4 = (*(code *)PTR_sk_num_006a7f2c)();
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
LAB_0046f5c0:
      pcVar24 = *(code **)(local_148 + -0x7fbc);
      do {
        unaff_s6 = (*pcVar24)(param_2,unaff_s1);
        unaff_s7 = (**(code **)(local_148 + -0x53ac))(unaff_s6,0x3a);
        if (unaff_s7 == 0) {
          iVar5 = (**(code **)(local_148 + -0x721c))(param_1,unaff_s6,0,0);
          if (iVar5 == 0) goto LAB_0046f590;
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
          (**(code **)(local_148 + -0x538c))(unaff_s8,unaff_s6,unaff_s0,0x100);
          puVar19 = &stack0xffffffd8 + (int)unaff_s0;
          local_12c[(int)unaff_s0] = '\0';
          iVar5 = (**(code **)(local_148 + -0x721c))(param_1,unaff_s8,unaff_s7 + 1,0);
          if (iVar5 == 0) goto LAB_0046f590;
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
LAB_0046f66c:
  if (local_2c == *local_134) {
    return *local_134;
  }
  pcStack_15c = engine_main;
  (**(code **)(local_148 + -0x5328))();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  puVar19 = PTR_bio_err_006a7f3c;
  iStack_184 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_180 = unaff_s0;
  iStack_17c = unaff_s1;
  ppcStack_178 = param_3;
  iStack_174 = unaff_s3;
  ppcStack_170 = param_2;
  pcStack_16c = param_1;
  iStack_168 = unaff_s6;
  iStack_164 = unaff_s7;
  pcStack_160 = unaff_s8;
  puVar6 = (undefined *)(*(code *)PTR_sk_new_null_006a80a4)();
  uVar7 = (*(code *)PTR_sk_new_null_006a80a4)();
  uVar8 = (*(code *)PTR_sk_new_null_006a80a4)();
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  (*(code *)PTR_SSL_load_error_strings_006a867c)();
  iVar4 = *(int *)puVar19;
  if (iVar4 == 0) {
    iVar4 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stderr_006aac00,0);
    *(int *)puVar19 = iVar4;
  }
  iVar4 = load_config(iVar4,0);
  if (iVar4 == 0) {
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar19);
    (*(code *)PTR_sk_pop_free_006a8158)(puVar6,identity);
    (*(code *)PTR_sk_pop_free_006a8158)(uVar7,identity);
    iVar4 = 1;
    (*(code *)PTR_sk_pop_free_006a8158)(uVar8,identity);
    puVar9 = puVar6;
    goto LAB_0046f848;
  }
  puStack_1a4 = (undefined4 *)PTR_stdout_006aaad4;
  iVar4 = (int)ppcVar15 + -1;
  pcVar18 = (char *)((int)pcVar18 + 4);
  puVar9 = (undefined *)(*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdout_006aaad4,0);
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
    puStack_1cc = &DAT_00644314;
    pcVar14 = (char *)0x0;
    pcStack_1bc = "s\n";
    param_1 = (char *)0x0;
    do {
      unaff_s8 = *(char **)pcVar18;
      iVar5 = (*(code *)PTR_strncmp_006aaa7c)(unaff_s8,&DAT_0064430c,2);
      ppcVar15 = (char **)pcVar18;
      if (iVar5 == 0) {
        pcVar14 = (char *)0x0;
        pcVar13 = unaff_s8;
        do {
          pcVar23 = pcVar14;
          pcVar13 = pcVar13 + 1;
          pcVar14 = pcVar23 + 1;
        } while (*pcVar13 == 'v');
        pcVar14 = (char *)(*(code *)PTR_strlen_006aab30)();
        if ((pcVar23 < pcVar14) || (4 < (int)pcVar14)) goto LAB_0046fca0;
      }
      else {
        cVar17 = *unaff_s8;
        if (((cVar17 == '-') && (unaff_s8[1] == 'c')) && (unaff_s8[2] == '\0')) {
          iStack_1c4 = 1;
        }
        else {
          iVar5 = (*(code *)PTR_strncmp_006aaa7c)(unaff_s8,&DAT_00644310,2);
          if (iVar5 == 0) {
            pcVar23 = (char *)0x0;
            pcVar13 = unaff_s8;
            do {
              param_1 = pcVar23;
              pcVar13 = pcVar13 + 1;
              pcVar23 = param_1 + 1;
            } while (*pcVar13 == 't');
            pcVar13 = (char *)(*(code *)PTR_strlen_006aab30)();
            if ((param_1 < pcVar13) || (param_1 = pcVar13 + -1, 1 < (int)param_1))
            goto LAB_0046fca0;
            iStack_1c0 = 1;
          }
          else {
            iVar5 = (*(code *)PTR_strcmp_006aac20)(unaff_s8,&DAT_00644314);
            if (iVar5 == 0) {
              iVar4 = iVar4 + -1;
              if (iVar4 == 0) goto LAB_0046fca0;
              (*(code *)PTR_sk_push_006a80a8)(uVar7,*(char **)((int)pcVar18 + 4));
              ppcVar15 = (char **)((int)pcVar18 + 4);
            }
            else {
              iVar5 = (*(code *)PTR_strcmp_006aac20)(unaff_s8,"-post");
              if (iVar5 == 0) {
                iVar4 = iVar4 + -1;
                ppcVar15 = (char **)((int)pcVar18 + 4);
                if (iVar4 == 0) goto LAB_0046fca0;
                (*(code *)PTR_sk_push_006a80a8)(uVar8,*(char **)((int)pcVar18 + 4));
              }
              else {
                iVar5 = (*(code *)PTR_strncmp_006aaa7c)(unaff_s8,&DAT_00641850,2);
                if ((iVar5 == 0) ||
                   (((cVar17 == '-' && (unaff_s8[1] == '?')) && (unaff_s8[2] == '\0')))) {
LAB_0046fca0:
                  if (engine_usage._0_4_ != 0) {
                    puVar20 = engine_usage;
                    do {
                      puVar20 = (undefined1 *)((int)puVar20 + 4);
                      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar19,"%s");
                    } while (*(int *)puVar20 != 0);
                  }
                  ppcStack_1b4 = (char **)0x470000;
                  puStack_1c8 = puVar6;
                  goto LAB_0046fce4;
                }
                (*(code *)PTR_sk_push_006a80a8)(puVar6,unaff_s8);
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
  iVar4 = (*(code *)PTR_sk_num_006a7f2c)(puVar6);
  if (iVar4 == 0) {
    for (iVar4 = (*(code *)PTR_ENGINE_get_first_006a8e74)(); iVar4 != 0;
        iVar4 = (*(code *)PTR_ENGINE_get_next_006a8e78)(iVar4)) {
      uVar10 = (*(code *)PTR_ENGINE_get_id_006a8cc0)(iVar4);
      (*(code *)PTR_sk_push_006a80a8)(puVar6,uVar10);
    }
  }
  puStack_1c8 = (undefined *)0x0;
  ppcStack_1b4 = (char **)0x470000;
  pcStack_1ac = "s\n";
  pcStack_1b0 = "engine.c";
  pcStack_194 = "<no description>";
  pcStack_19c = "s\n";
  puStack_1a8 = &DAT_0063f0b4;
  iVar4 = (*(code *)PTR_sk_num_006a7f2c)(puVar6);
  puStack_1cc = puVar6;
  pcStack_1bc = pcVar14;
  if (iVar4 < 1) goto LAB_0046fb14;
LAB_0046fa00:
  uVar10 = (*(code *)PTR_sk_value_006a7f24)(puStack_1cc,puStack_1c8);
  ppcVar11 = (char **)(*(code *)PTR_ENGINE_by_id_006a7f9c)(uVar10);
  pcVar18 = (char *)ppcVar11;
  if (ppcVar11 == (char **)0x0) {
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar19);
    goto LAB_0046faec;
  }
  uVar12 = (*(code *)PTR_ENGINE_get_name_006a8e50)(ppcVar11);
  (*(code *)PTR_BIO_printf_006a7f38)(puVar9,pcStack_1ac + 0x432c,uVar10,uVar12);
  util_do_cmds_isra_0(ppcVar11,uVar7,puVar9);
  uVar12 = (*(code *)PTR_ENGINE_get_id_006a8cc0)(ppcVar11);
  iVar4 = (*(code *)PTR_strcmp_006aac20)(uVar12,uVar10);
  if (iVar4 != 0) {
    uVar10 = (*(code *)PTR_ENGINE_get_id_006a8cc0)(ppcVar11);
    uVar12 = (*(code *)PTR_ENGINE_get_name_006a8e50)(ppcVar11);
    (*(code *)PTR_BIO_printf_006a7f38)(puVar9,"Loaded: (%s) %s\n",uVar10,uVar12);
  }
  puVar6 = puStack_1cc;
  if (iStack_1c4 != 0) {
    iVar4 = (*(code *)PTR_ENGINE_get_RSA_006a8e54)(ppcVar11);
    if (iVar4 == 0) {
      iVar4 = (*(code *)PTR_ENGINE_get_DSA_006a8e58)(ppcVar11);
      if (iVar4 != 0) {
        pcVar13 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x100,pcStack_1b0,0x6b);
        if (pcVar13 == (char *)0x0) goto LAB_0046fce4;
        *pcVar13 = '\0';
        ppcVar22 = (char **)0x100;
        ppcVar15 = (char **)0x100;
LAB_0046fdec:
        (*(code *)PTR_BUF_strlcat_006a8068)(pcVar13,"DSA",ppcVar22);
        goto LAB_0046fe08;
      }
      iVar4 = (*(code *)PTR_ENGINE_get_DH_006a8e5c)(ppcVar11);
      if (iVar4 != 0) {
        pcVar13 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x100,pcStack_1b0,0x6b);
        if (pcVar13 == (char *)0x0) goto LAB_0046fce4;
        *pcVar13 = '\0';
        ppcVar22 = (char **)0x100;
        ppcVar15 = (char **)0x100;
        goto LAB_0046fe44;
      }
      iVar4 = (*(code *)PTR_ENGINE_get_RAND_006a8e60)(ppcVar11);
      if (iVar4 != 0) {
        pcVar13 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x100,pcStack_1b0,0x6b);
        if (pcVar13 == (char *)0x0) goto LAB_0046fce4;
        *pcVar13 = '\0';
        ppcVar22 = (char **)0x100;
        ppcVar15 = (char **)0x100;
        goto LAB_0046fe9c;
      }
      pcVar13 = (char *)0x0;
      ppcVar15 = (char **)0x100;
    }
    else {
      pcVar13 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x100,pcStack_1b0,0x6b);
      puVar2 = PTR_BUF_strlcat_006a8068;
      if (pcVar13 == (char *)0x0) goto LAB_0046fce4;
      *pcVar13 = '\0';
      (*(code *)puVar2)(pcVar13,"RSA",0x100);
      iVar4 = (*(code *)PTR_ENGINE_get_DSA_006a8e58)(ppcVar11);
      if (iVar4 != 0) {
        iVar4 = (*(code *)PTR_strlen_006aab30)(pcVar13);
        if (iVar4 + 3U < 0x100) {
          ppcVar22 = (char **)0x100;
          ppcVar15 = (char **)0x100;
        }
        else {
          pcVar13 = (char *)(*(code *)PTR_CRYPTO_realloc_006a8c44)(pcVar13,0x200,pcStack_1b0,0x77);
          if (pcVar13 == (char *)0x0) goto LAB_0046fce4;
          ppcVar22 = (char **)0x200;
          ppcVar15 = (char **)0x200;
        }
        if (*pcVar13 != '\0') {
          (*(code *)PTR_BUF_strlcat_006a8068)(pcVar13,", ",ppcVar22);
        }
        goto LAB_0046fdec;
      }
      ppcVar22 = (char **)0x100;
      ppcVar15 = (char **)0x100;
LAB_0046fe08:
      iVar4 = (*(code *)PTR_ENGINE_get_DH_006a8e5c)(ppcVar11);
      if (iVar4 == 0) {
        iVar4 = (*(code *)PTR_ENGINE_get_RAND_006a8e60)(ppcVar11);
      }
      else {
        iVar4 = (*(code *)PTR_strlen_006aab30)(pcVar13);
        if (ppcVar22 <= (char **)(iVar4 + 2)) {
          ppcVar15 = ppcVar15 + 0x40;
          pcVar13 = (char *)(*(code *)PTR_CRYPTO_realloc_006a8c44)(pcVar13,ppcVar15,"engine.c",0x77)
          ;
          ppcVar22 = ppcVar15;
          if (pcVar13 == (char *)0x0) goto LAB_0046fce4;
        }
        if (*pcVar13 != '\0') {
          (*(code *)PTR_BUF_strlcat_006a8068)(pcVar13,", ",ppcVar22);
        }
LAB_0046fe44:
        (*(code *)PTR_BUF_strlcat_006a8068)(pcVar13,"DH",ppcVar22);
        iVar4 = (*(code *)PTR_ENGINE_get_RAND_006a8e60)(ppcVar11);
      }
      if (iVar4 != 0) {
        iVar4 = (*(code *)PTR_strlen_006aab30)(pcVar13);
        if (ppcVar22 <= (char **)(iVar4 + 4)) {
          ppcVar15 = ppcVar15 + 0x40;
          pcVar13 = (char *)(*(code *)PTR_CRYPTO_realloc_006a8c44)(pcVar13,ppcVar15,"engine.c",0x77)
          ;
          ppcVar22 = ppcVar15;
          if (pcVar13 == (char *)0x0) goto LAB_0046fce4;
        }
        if (*pcVar13 != '\0') {
          (*(code *)PTR_BUF_strlcat_006a8068)(pcVar13,", ",ppcVar22);
        }
LAB_0046fe9c:
        (*(code *)PTR_BUF_strlcat_006a8068)(pcVar13,"RAND",ppcVar22);
      }
    }
    pcVar24 = (code *)(*(code *)PTR_ENGINE_get_ciphers_006a8e64)(ppcVar11);
    if ((pcVar24 != (code *)0x0) &&
       (pcVar14 = (char *)(*pcVar24)(ppcVar11,0,&pcStack_188,0), 0 < (int)pcVar14)) {
      pcVar23 = (char *)0x0;
      pcStack_1a0 = ", ";
      do {
        param_1 = (char *)(*(code *)PTR_OBJ_nid2sn_006a819c)
                                    (*(undefined4 *)(pcStack_188 + (int)pcVar23 * 4));
        unaff_s8 = pcVar14;
        ppcStack_190 = ppcVar11;
        if (pcVar13 == (char *)0x0) {
          pcVar13 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x100,pcStack_1b0,0x6b);
          puVar2 = PTR_strlen_006aab30;
          if (pcVar13 == (char *)0x0) goto LAB_0046fce4;
          *pcVar13 = '\0';
          uVar21 = (*(code *)puVar2)(param_1);
          if (0xff < uVar21) {
            ppcVar22 = (char **)0x200;
            goto LAB_0046ff94;
          }
          ppcVar15 = (char **)0x100;
        }
        else {
          iVar4 = (*(code *)PTR_strlen_006aab30)(pcVar13);
          iVar5 = (*(code *)PTR_strlen_006aab30)(param_1);
          if ((char **)(iVar4 + iVar5) < ppcVar15) {
            cVar17 = *pcVar13;
          }
          else {
            ppcVar22 = ppcVar15 + 0x40;
            pcVar18 = (char *)ppcVar15;
LAB_0046ff94:
            pcVar13 = (char *)(*(code *)PTR_CRYPTO_realloc_006a8c44)
                                        (pcVar13,ppcVar22,"engine.c",0x77);
            if (pcVar13 == (char *)0x0) goto LAB_0046fce4;
            cVar17 = *pcVar13;
            ppcVar15 = ppcVar22;
          }
          if (cVar17 != '\0') {
            (*(code *)PTR_BUF_strlcat_006a8068)(pcVar13,", ",ppcVar15);
          }
        }
        pcVar23 = pcVar23 + 1;
        (*(code *)PTR_BUF_strlcat_006a8068)(pcVar13,param_1,ppcVar15);
        pcVar18 = (char *)ppcVar15;
      } while (pcVar14 != pcVar23);
    }
    pcVar24 = (code *)(*(code *)PTR_ENGINE_get_digests_006a8e6c)(ppcVar11);
    if (pcVar24 == (code *)0x0) {
LAB_00470498:
      pcVar24 = (code *)(*(code *)PTR_ENGINE_get_pkey_meths_006a8e70)(ppcVar11);
      if (pcVar24 != (code *)0x0) {
LAB_004704b4:
        ppcStack_190 = &pcStack_188;
        param_1 = (char *)(*pcVar24)(ppcVar11,0,ppcStack_190,0);
        if (0 < (int)param_1) {
          pcVar14 = (char *)0x0;
          pcStack_1a0 = ", ";
          do {
            unaff_s8 = (char *)(*(code *)PTR_OBJ_nid2sn_006a819c)
                                         (*(undefined4 *)(pcStack_188 + (int)pcVar14 * 4));
            if (pcVar13 == (char *)0x0) {
              pcVar13 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x100,pcStack_1b0,0x6b);
              puVar2 = PTR_strlen_006aab30;
              pcVar18 = (char *)ppcVar11;
              if (pcVar13 == (char *)0x0) goto LAB_0046fce4;
              *pcVar13 = '\0';
              uVar21 = (*(code *)puVar2)(unaff_s8);
              if (0xff < uVar21) {
                ppcVar15 = (char **)0x200;
                goto LAB_00470578;
              }
              ppcVar15 = (char **)0x100;
            }
            else {
              iVar4 = (*(code *)PTR_strlen_006aab30)(pcVar13);
              iVar5 = (*(code *)PTR_strlen_006aab30)(unaff_s8);
              if (ppcVar15 <= (char **)(iVar4 + iVar5)) {
                ppcVar15 = ppcVar15 + 0x40;
LAB_00470578:
                pcVar13 = (char *)(*(code *)PTR_CRYPTO_realloc_006a8c44)
                                            (pcVar13,ppcVar15,"engine.c",0x77);
                pcVar18 = (char *)ppcVar11;
                if (pcVar13 == (char *)0x0) goto LAB_0046fce4;
              }
              if (*pcVar13 != '\0') {
                (*(code *)PTR_BUF_strlcat_006a8068)(pcVar13,", ",ppcVar15);
                ppcStack_190 = ppcVar15;
              }
            }
            pcVar14 = pcVar14 + 1;
            (*(code *)PTR_BUF_strlcat_006a8068)(pcVar13,unaff_s8,ppcVar15);
          } while (param_1 != pcVar14);
          goto LAB_004708f8;
        }
      }
      if (pcVar13 != (char *)0x0) {
        cVar17 = *pcVar13;
        goto LAB_004708fc;
      }
    }
    else {
      ppcStack_190 = &pcStack_188;
      unaff_s8 = (char *)(*pcVar24)(ppcVar11,0,ppcStack_190,0);
      if ((int)unaff_s8 < 1) goto LAB_00470498;
      pcVar14 = (char *)0x0;
      pcStack_1a0 = ", ";
      pcVar18 = (char *)ppcVar11;
      do {
        param_1 = (char *)(*(code *)PTR_OBJ_nid2sn_006a819c)
                                    (*(undefined4 *)(pcStack_188 + (int)pcVar14 * 4));
        if (pcVar13 == (char *)0x0) {
          pcVar13 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x100,pcStack_1b0,0x6b);
          puVar2 = PTR_strlen_006aab30;
          if (pcVar13 == (char *)0x0) goto LAB_0046fce4;
          *pcVar13 = '\0';
          uVar21 = (*(code *)puVar2)(param_1);
          if (0xff < uVar21) {
            ppcVar22 = (char **)0x200;
            goto LAB_004703bc;
          }
          ppcVar15 = (char **)0x100;
        }
        else {
          iVar4 = (*(code *)PTR_strlen_006aab30)(pcVar13);
          iVar5 = (*(code *)PTR_strlen_006aab30)(param_1);
          ppcVar22 = ppcVar15;
          if (ppcVar15 <= (char **)(iVar4 + iVar5)) {
            ppcVar22 = ppcVar15 + 0x40;
            pcVar18 = (char *)ppcVar15;
LAB_004703bc:
            pcVar13 = (char *)(*(code *)PTR_CRYPTO_realloc_006a8c44)
                                        (pcVar13,ppcVar22,"engine.c",0x77);
            if (pcVar13 == (char *)0x0) goto LAB_0046fce4;
          }
          ppcVar15 = ppcVar22;
          if (*pcVar13 != '\0') {
            (*(code *)PTR_BUF_strlcat_006a8068)(pcVar13,", ",ppcVar22);
          }
        }
        pcVar14 = pcVar14 + 1;
        (*(code *)PTR_BUF_strlcat_006a8068)(pcVar13,param_1,ppcVar15);
        pcVar18 = (char *)ppcVar15;
      } while (unaff_s8 != pcVar14);
      pcVar24 = (code *)(*(code *)PTR_ENGINE_get_pkey_meths_006a8e70)(ppcVar11);
      if (pcVar24 != (code *)0x0) goto LAB_004704b4;
LAB_004708f8:
      pcStack_1a0 = ", ";
      cVar17 = *pcVar13;
LAB_004708fc:
      if (cVar17 != '\0') {
        (*(code *)PTR_BIO_printf_006a7f38)(puVar9," [%s]\n",pcVar13);
      }
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar13);
  }
  if (iStack_1c0 != 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(puVar9,"%s",puStack_1a8);
    iVar4 = (*(code *)PTR_ENGINE_init_006a8e68)(ppcVar11);
    if (iVar4 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(puVar9,"[ unavailable ]\n");
      if (pcStack_198 != (char *)0x0) {
        (*(code *)PTR_ERR_print_errors_fp_006a8e7c)(*puStack_1a4);
      }
      (*(code *)PTR_ERR_clear_error_006a7fe0)();
    }
    else {
      (*(code *)PTR_BIO_printf_006a7f38)(puVar9,"[ available ]\n");
      util_do_cmds_isra_0(ppcVar11,uVar8,puVar9);
      (*(code *)PTR_ENGINE_finish_006a80c4)(ppcVar11);
    }
  }
  if ((int)pcStack_1bc < 1) goto LAB_0046fadc;
  iVar4 = (*(code *)PTR_ENGINE_ctrl_006a8cb4)(ppcVar11,10,0,0,0);
  if (iVar4 == 0) goto LAB_0046fadc;
  iVar4 = (*(code *)PTR_ENGINE_ctrl_006a8cb4)(ppcVar11,0xb,0,0,0);
  if (iVar4 < 1) goto LAB_0046fadc;
  pcStack_1a0 = (char *)(*(code *)PTR_sk_new_null_006a80a4)();
  pcVar18 = (char *)ppcVar11;
  if (pcStack_1a0 != (char *)0x0) {
    iVar5 = 0;
    ppcStack_190 = (char **)0x640000;
    goto LAB_00470138;
  }
LAB_0046fce4:
  iVar4 = 1;
  puVar9 = puVar6;
  do {
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar19);
    (*(code *)PTR_sk_pop_free_006a8158)(puVar9,ppcStack_1b4 + -0x2c4);
    (*(code *)PTR_sk_pop_free_006a8158)(uVar7,ppcStack_1b4 + -0x2c4);
    (*(code *)PTR_sk_pop_free_006a8158)(uVar8,ppcStack_1b4 + -0x2c4);
    ppcVar15 = ppcStack_1b4;
    if (puStack_1b8 != (undefined *)0x0) {
      (*(code *)PTR_BIO_free_all_006a7f74)();
    }
LAB_0046f848:
    if (iStack_184 == *(int *)puVar3) {
      return iVar4;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    ppcVar11 = (char **)pcVar18;
LAB_00470cd0:
    uVar21 = (uint)ppcVar15 & 0xfffffff0;
    if (uVar21 == 0) goto LAB_00470778;
    bVar1 = false;
LAB_00470b64:
    (*(code *)PTR_BIO_printf_006a7f38)(puVar9,"<0x%04X>",uVar21);
LAB_00470a64:
    if (!bVar1) goto LAB_00470778;
LAB_00470a6c:
    (*(code *)PTR_BIO_printf_006a7f38)(puVar9,"  <illegal flags!>");
LAB_00470778:
    iVar5 = 0;
    (*(code *)PTR_BIO_printf_006a7f38)(puVar9,"\n");
LAB_004706d0:
    (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s8);
    if (param_1 != (char *)0x0) goto LAB_00470288;
LAB_00470114:
    iVar4 = (*(code *)PTR_ENGINE_ctrl_006a8cb4)(ppcVar11,0xc,iVar4,0,0);
    if (0 < iVar4) {
LAB_00470138:
      ppcVar15 = (char **)(*(code *)PTR_ENGINE_ctrl_006a8cb4)(ppcVar11,0x12,iVar4,0,0);
      if ((int)ppcVar15 < 0) {
LAB_00470964:
        bVar1 = false;
        goto LAB_00470968;
      }
      if ((((uint)ppcVar15 & 8) != 0) && (pcStack_1bc != (char *)0x4)) {
        (*(code *)PTR_CRYPTO_free_006a7f88)(0);
        goto LAB_00470114;
      }
      iVar16 = (*(code *)PTR_ENGINE_ctrl_006a8cb4)(ppcVar11,0xe,iVar4,0,0);
      if ((iVar16 < 1) ||
         (unaff_s8 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar16 + 1,pcStack_1b0,0xe6),
         param_1 = pcStack_1b0, unaff_s8 == (char *)0x0)) goto LAB_00470964;
      iVar16 = (*(code *)PTR_ENGINE_ctrl_006a8cb4)(ppcVar11,0xf,iVar4,unaff_s8,0);
      if ((iVar16 < 1) ||
         (iVar16 = (*(code *)PTR_ENGINE_ctrl_006a8cb4)(ppcVar11,0x10,iVar4,0,0), iVar16 < 0)) {
        param_1 = (char *)0x0;
LAB_00470600:
        (*(code *)PTR_sk_pop_free_006a8158)(pcStack_1a0,ppcStack_1b4 + -0x2c4);
        (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s8);
        pcVar18 = (char *)ppcVar11;
        puVar6 = puStack_1cc;
        if (param_1 != (char *)0x0) {
          (*(code *)PTR_CRYPTO_free_006a7f88)(param_1);
        }
        goto LAB_0046fce4;
      }
      if (iVar16 == 0) {
        param_1 = (char *)0x0;
      }
      else {
        param_1 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar16 + 1,pcStack_1b0,0xf1);
        if ((param_1 == (char *)0x0) ||
           (iVar16 = (*(code *)PTR_ENGINE_ctrl_006a8cb4)(ppcVar11,0x11,iVar4,param_1,0), iVar16 < 1)
           ) goto LAB_00470600;
      }
      if (iVar5 == 0) {
        iVar16 = (*(code *)PTR_BIO_puts_006a8058)(puVar9,puStack_1a8);
      }
      else {
        iVar16 = (*(code *)PTR_BIO_printf_006a7f38)(puVar9,", ");
        iVar16 = iVar5 + iVar16;
      }
      if (pcStack_1bc == (char *)0x1) {
        if ((5 < iVar16) &&
           (iVar5 = (*(code *)PTR_strlen_006aab30)(unaff_s8), 0x4e < iVar5 + iVar16)) {
          (*(code *)PTR_BIO_printf_006a7f38)(puVar9,"\n");
          iVar16 = (*(code *)PTR_BIO_puts_006a8058)(puVar9,puStack_1a8);
        }
        iVar5 = (*(code *)PTR_BIO_printf_006a7f38)(puVar9,"%s",unaff_s8);
        iVar5 = iVar5 + iVar16;
        goto LAB_004706d0;
      }
      if (param_1 == (char *)0x0) {
        (*(code *)PTR_BIO_printf_006a7f38)(puVar9,pcStack_19c + 0x43d4,unaff_s8,pcStack_194);
        if (pcStack_1bc != (char *)0x2) goto LAB_0047070c;
        iVar5 = 0;
        (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s8);
        goto LAB_00470114;
      }
      (*(code *)PTR_BIO_printf_006a7f38)(puVar9,pcStack_19c + 0x43d4,unaff_s8,param_1);
      if (pcStack_1bc == (char *)0x2) {
        iVar5 = 0;
        (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s8);
LAB_00470288:
        (*(code *)PTR_CRYPTO_free_006a7f88)(param_1);
        goto LAB_00470114;
      }
LAB_0047070c:
      (*(code *)PTR_BIO_printf_006a7f38)(puVar9,ppcStack_190 + 0x10dc,puStack_1a8,puStack_1a8);
      if (ppcVar15 == (char **)0x0) {
        iVar5 = 0;
        (*(code *)PTR_BIO_printf_006a7f38)(puVar9,"<no flags>\n");
        goto LAB_004706d0;
      }
      if (((uint)ppcVar15 & 8) != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(puVar9,"[Internal] ");
      }
      if (((uint)ppcVar15 & 1) == 0) {
        bVar1 = false;
        if (((uint)ppcVar15 & 2) != 0) goto LAB_00470a34;
        if (((uint)ppcVar15 & 4) == 0) goto LAB_00470cd0;
        (*(code *)PTR_BIO_printf_006a7f38)(puVar9,"NO_INPUT");
joined_r0x00470b40:
        if (((uint)ppcVar15 & 0xfffffff0) != 0) {
          bVar1 = false;
          goto LAB_00470b50;
        }
        goto LAB_00470778;
      }
      (*(code *)PTR_BIO_printf_006a7f38)(puVar9,"NUMERIC");
      if (((uint)ppcVar15 & 2) == 0) {
        if (((uint)ppcVar15 & 4) != 0) goto LAB_00470b84;
        goto joined_r0x00470b40;
      }
      bVar1 = true;
      (*(code *)PTR_BIO_printf_006a7f38)(puVar9,&DAT_006443a4);
LAB_00470a34:
      (*(code *)PTR_BIO_printf_006a7f38)(puVar9,"STRING");
      if (((uint)ppcVar15 & 4) == 0) {
        if (((uint)ppcVar15 & 0xfffffff0) == 0) goto LAB_00470a64;
        goto LAB_00470b50;
      }
LAB_00470b84:
      bVar1 = true;
      (*(code *)PTR_BIO_printf_006a7f38)(puVar9,&DAT_006443a4);
      (*(code *)PTR_BIO_printf_006a7f38)(puVar9,"NO_INPUT");
      if (((uint)ppcVar15 & 0xfffffff0) != 0) goto LAB_00470b50;
      goto LAB_00470a6c;
    }
    if (iVar5 < 1) {
      bVar1 = true;
    }
    else {
      bVar1 = true;
      (*(code *)PTR_BIO_printf_006a7f38)(puVar9,"\n");
    }
LAB_00470968:
    (*(code *)PTR_sk_pop_free_006a8158)(pcStack_1a0,ppcStack_1b4 + -0x2c4);
    pcVar18 = (char *)ppcVar11;
    puVar6 = puStack_1cc;
    if (!bVar1) goto LAB_0046fce4;
LAB_0046fadc:
    (*(code *)PTR_ENGINE_free_006a7f84)(ppcVar11);
    pcVar18 = (char *)ppcVar11;
LAB_0046faec:
    puStack_1c8 = puStack_1c8 + 1;
    iVar4 = (*(code *)PTR_sk_num_006a7f2c)(puStack_1cc);
    if ((int)puStack_1c8 < iVar4) goto LAB_0046fa00;
LAB_0046fb14:
    iVar4 = 0;
    puVar9 = puStack_1cc;
  } while( true );
LAB_0046f590:
  unaff_s1 = unaff_s1 + 1;
  pcVar18 = local_13c;
  (**(code **)(local_148 + -0x7fa8))(param_3,local_13c,unaff_s6);
  ppcVar15 = param_3;
  (**(code **)(local_148 + -0x7fa0))();
  unaff_s0 = puVar19;
  if (iVar4 == unaff_s1) goto LAB_0046f66c;
  goto LAB_0046f5c0;
LAB_00470b50:
  uVar21 = (uint)ppcVar15 & 0xfffffff0;
  (*(code *)PTR_BIO_printf_006a7f38)(puVar9,&DAT_006443a4);
  goto LAB_00470b64;
}

