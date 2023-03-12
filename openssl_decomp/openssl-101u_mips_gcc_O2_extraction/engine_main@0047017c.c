
int engine_main(uint param_1,char **param_2)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined *puVar8;
  undefined4 uVar9;
  char **ppcVar10;
  undefined4 uVar11;
  char *pcVar12;
  code *pcVar13;
  char *pcVar14;
  int iVar15;
  char cVar17;
  uint uVar16;
  int iVar18;
  undefined1 *puVar19;
  char **ppcVar20;
  char **ppcVar21;
  char *pcVar22;
  int iVar23;
  char *unaff_s5;
  char *unaff_s8;
  undefined *local_74;
  undefined *local_70;
  int local_6c;
  int local_68;
  char *local_64;
  undefined *local_60;
  uint local_5c;
  char *local_58;
  char *local_54;
  undefined *local_50;
  undefined4 *local_4c;
  char *local_48;
  char *local_44;
  char *local_40;
  char *local_3c;
  char *local_38;
  char *local_30;
  int local_2c;
  
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  puVar2 = PTR_bio_err_006a6e3c;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar5 = (undefined *)(*(code *)PTR_sk_new_null_006a6fa4)();
  uVar6 = (*(code *)PTR_sk_new_null_006a6fa4)();
  uVar7 = (*(code *)PTR_sk_new_null_006a6fa4)();
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  (*(code *)PTR_SSL_load_error_strings_006a7588)();
  iVar18 = *(int *)puVar2;
  if (iVar18 == 0) {
    iVar18 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *(int *)puVar2 = iVar18;
  }
  iVar18 = load_config(iVar18,0);
  if (iVar18 == 0) {
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
    (*(code *)PTR_sk_pop_free_006a7058)(puVar5,identity);
    (*(code *)PTR_sk_pop_free_006a7058)(uVar6,identity);
    iVar18 = 1;
    (*(code *)PTR_sk_pop_free_006a7058)(uVar7,identity);
    puVar8 = puVar5;
    goto LAB_00470298;
  }
  local_4c = (undefined4 *)PTR_stdout_006a99c8;
  iVar18 = param_1 - 1;
  param_2 = param_2 + 1;
  puVar8 = (undefined *)(*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
  local_60 = puVar8;
  if (iVar18 < 1) {
    local_40 = (char *)0x0;
    pcVar14 = (char *)0x0;
    local_68 = 0;
    local_6c = 0;
    pcVar12 = local_40;
  }
  else {
    local_68 = 0;
    local_6c = 0;
    local_74 = &DAT_00643de4;
    pcVar14 = (char *)0x0;
    local_64 = "-check_ss_sig";
    unaff_s5 = (char *)0x0;
    do {
      unaff_s8 = *param_2;
      iVar23 = (*(code *)PTR_strncmp_006a9970)(unaff_s8,&DAT_00643ddc,2);
      ppcVar10 = param_2;
      if (iVar23 == 0) {
        pcVar14 = (char *)0x0;
        pcVar12 = unaff_s8;
        do {
          pcVar22 = pcVar14;
          pcVar12 = pcVar12 + 1;
          pcVar14 = pcVar22 + 1;
        } while (*pcVar12 == 'v');
        pcVar14 = (char *)(*(code *)PTR_strlen_006a9a24)();
        if ((pcVar22 < pcVar14) || (4 < (int)pcVar14)) goto LAB_004706f0;
      }
      else {
        cVar17 = *unaff_s8;
        if (((cVar17 == '-') && (unaff_s8[1] == 'c')) && (unaff_s8[2] == '\0')) {
          local_6c = 1;
        }
        else {
          iVar23 = (*(code *)PTR_strncmp_006a9970)(unaff_s8,&DAT_00643de0,2);
          if (iVar23 == 0) {
            pcVar22 = (char *)0x0;
            pcVar12 = unaff_s8;
            do {
              unaff_s5 = pcVar22;
              pcVar12 = pcVar12 + 1;
              pcVar22 = unaff_s5 + 1;
            } while (*pcVar12 == 't');
            pcVar12 = (char *)(*(code *)PTR_strlen_006a9a24)();
            if ((unaff_s5 < pcVar12) || (unaff_s5 = pcVar12 + -1, 1 < (int)unaff_s5))
            goto LAB_004706f0;
            local_68 = 1;
          }
          else {
            iVar23 = (*(code *)PTR_strcmp_006a9b18)(unaff_s8,&DAT_00643de4);
            if (iVar23 == 0) {
              iVar18 = iVar18 + -1;
              if (iVar18 == 0) goto LAB_004706f0;
              (*(code *)PTR_sk_push_006a6fa8)(uVar6,param_2[1]);
              ppcVar10 = param_2 + 1;
            }
            else {
              iVar23 = (*(code *)PTR_strcmp_006a9b18)(unaff_s8,"-post");
              if (iVar23 == 0) {
                iVar18 = iVar18 + -1;
                ppcVar10 = param_2 + 1;
                if (iVar18 == 0) goto LAB_004706f0;
                (*(code *)PTR_sk_push_006a6fa8)(uVar7,param_2[1]);
              }
              else {
                iVar23 = (*(code *)PTR_strncmp_006a9970)(unaff_s8,&DAT_006412e0,2);
                if ((iVar23 == 0) ||
                   (((cVar17 == '-' && (unaff_s8[1] == '?')) && (unaff_s8[2] == '\0')))) {
LAB_004706f0:
                  if (engine_usage._0_4_ != 0) {
                    puVar19 = engine_usage;
                    do {
                      puVar19 = (undefined1 *)((int)puVar19 + 4);
                      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"%s");
                    } while (*(int *)puVar19 != 0);
                  }
                  local_5c = 0x470000;
                  local_70 = puVar5;
                  goto LAB_00470734;
                }
                (*(code *)PTR_sk_push_006a6fa8)(puVar5,unaff_s8);
              }
            }
          }
        }
      }
      iVar18 = iVar18 + -1;
      param_2 = ppcVar10 + 1;
      pcVar12 = unaff_s5;
    } while (iVar18 != 0);
  }
  local_40 = pcVar12;
  iVar18 = (*(code *)PTR_sk_num_006a6e2c)(puVar5);
  if (iVar18 == 0) {
    for (iVar18 = (*(code *)PTR_ENGINE_get_first_006a7d84)(); iVar18 != 0;
        iVar18 = (*(code *)PTR_ENGINE_get_next_006a7d88)(iVar18)) {
      uVar9 = (*(code *)PTR_ENGINE_get_id_006a7bd4)(iVar18);
      (*(code *)PTR_sk_push_006a6fa8)(puVar5,uVar9);
    }
  }
  local_70 = (undefined *)0x0;
  local_5c = 0x470000;
  local_54 = "-check_ss_sig";
  local_58 = "engine.c";
  local_3c = "<no description>";
  local_44 = "-check_ss_sig";
  local_50 = &DAT_0063eb80;
  iVar18 = (*(code *)PTR_sk_num_006a6e2c)(puVar5);
  local_74 = puVar5;
  local_64 = pcVar14;
  if (iVar18 < 1) goto LAB_00470564;
LAB_00470450:
  uVar9 = (*(code *)PTR_sk_value_006a6e24)(local_74,local_70);
  ppcVar10 = (char **)(*(code *)PTR_ENGINE_by_id_006a6e9c)(uVar9);
  param_2 = ppcVar10;
  if (ppcVar10 == (char **)0x0) {
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
    goto LAB_0047053c;
  }
  uVar11 = (*(code *)PTR_ENGINE_get_name_006a7d60)(ppcVar10);
  (*(code *)PTR_BIO_printf_006a6e38)(puVar8,local_54 + 0x3dfc,uVar9,uVar11);
  util_do_cmds_isra_0(ppcVar10,uVar6,puVar8);
  uVar11 = (*(code *)PTR_ENGINE_get_id_006a7bd4)(ppcVar10);
  iVar18 = (*(code *)PTR_strcmp_006a9b18)(uVar11,uVar9);
  if (iVar18 != 0) {
    uVar9 = (*(code *)PTR_ENGINE_get_id_006a7bd4)(ppcVar10);
    uVar11 = (*(code *)PTR_ENGINE_get_name_006a7d60)(ppcVar10);
    (*(code *)PTR_BIO_printf_006a6e38)(puVar8,"Loaded: (%s) %s\n",uVar9,uVar11);
  }
  puVar5 = local_74;
  if (local_6c != 0) {
    iVar18 = (*(code *)PTR_ENGINE_get_RSA_006a7d64)(ppcVar10);
    if (iVar18 == 0) {
      iVar18 = (*(code *)PTR_ENGINE_get_DSA_006a7d68)(ppcVar10);
      if (iVar18 != 0) {
        pcVar12 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x100,local_58,0x68);
        if (pcVar12 == (char *)0x0) goto LAB_00470734;
        *pcVar12 = '\0';
        ppcVar21 = (char **)0x100;
        ppcVar20 = (char **)0x100;
LAB_0047083c:
        (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar12,"DSA",ppcVar21);
        goto LAB_00470858;
      }
      iVar18 = (*(code *)PTR_ENGINE_get_DH_006a7d6c)(ppcVar10);
      if (iVar18 != 0) {
        pcVar12 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x100,local_58,0x68);
        if (pcVar12 == (char *)0x0) goto LAB_00470734;
        *pcVar12 = '\0';
        ppcVar21 = (char **)0x100;
        ppcVar20 = (char **)0x100;
        goto LAB_00470894;
      }
      iVar18 = (*(code *)PTR_ENGINE_get_RAND_006a7d70)(ppcVar10);
      if (iVar18 != 0) {
        pcVar12 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x100,local_58,0x68);
        if (pcVar12 == (char *)0x0) goto LAB_00470734;
        *pcVar12 = '\0';
        ppcVar21 = (char **)0x100;
        ppcVar20 = (char **)0x100;
        goto LAB_004708ec;
      }
      pcVar12 = (char *)0x0;
      ppcVar20 = (char **)0x100;
    }
    else {
      pcVar12 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x100,local_58,0x68);
      puVar3 = PTR_BUF_strlcat_006a6f68;
      if (pcVar12 == (char *)0x0) goto LAB_00470734;
      *pcVar12 = '\0';
      (*(code *)puVar3)(pcVar12,"RSA",0x100);
      iVar18 = (*(code *)PTR_ENGINE_get_DSA_006a7d68)(ppcVar10);
      if (iVar18 != 0) {
        iVar18 = (*(code *)PTR_strlen_006a9a24)(pcVar12);
        if (iVar18 + 3U < 0x100) {
          ppcVar21 = (char **)0x100;
          ppcVar20 = (char **)0x100;
        }
        else {
          pcVar12 = (char *)(*(code *)PTR_CRYPTO_realloc_006a7b58)(pcVar12,0x200,local_58,0x70);
          if (pcVar12 == (char *)0x0) goto LAB_00470734;
          ppcVar21 = (char **)0x200;
          ppcVar20 = (char **)0x200;
        }
        if (*pcVar12 != '\0') {
          (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar12,", ",ppcVar21);
        }
        goto LAB_0047083c;
      }
      ppcVar21 = (char **)0x100;
      ppcVar20 = (char **)0x100;
LAB_00470858:
      iVar18 = (*(code *)PTR_ENGINE_get_DH_006a7d6c)(ppcVar10);
      if (iVar18 == 0) {
        iVar18 = (*(code *)PTR_ENGINE_get_RAND_006a7d70)(ppcVar10);
      }
      else {
        iVar18 = (*(code *)PTR_strlen_006a9a24)(pcVar12);
        if (ppcVar21 <= (char **)(iVar18 + 2)) {
          ppcVar20 = ppcVar20 + 0x40;
          pcVar12 = (char *)(*(code *)PTR_CRYPTO_realloc_006a7b58)(pcVar12,ppcVar20,"engine.c",0x70)
          ;
          ppcVar21 = ppcVar20;
          if (pcVar12 == (char *)0x0) goto LAB_00470734;
        }
        if (*pcVar12 != '\0') {
          (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar12,", ",ppcVar21);
        }
LAB_00470894:
        (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar12,"DH",ppcVar21);
        iVar18 = (*(code *)PTR_ENGINE_get_RAND_006a7d70)(ppcVar10);
      }
      if (iVar18 != 0) {
        iVar18 = (*(code *)PTR_strlen_006a9a24)(pcVar12);
        if (ppcVar21 <= (char **)(iVar18 + 4)) {
          ppcVar20 = ppcVar20 + 0x40;
          pcVar12 = (char *)(*(code *)PTR_CRYPTO_realloc_006a7b58)(pcVar12,ppcVar20,"engine.c",0x70)
          ;
          ppcVar21 = ppcVar20;
          if (pcVar12 == (char *)0x0) goto LAB_00470734;
        }
        if (*pcVar12 != '\0') {
          (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar12,", ",ppcVar21);
        }
LAB_004708ec:
        (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar12,"RAND",ppcVar21);
      }
    }
    pcVar13 = (code *)(*(code *)PTR_ENGINE_get_ciphers_006a7d74)(ppcVar10);
    if ((pcVar13 != (code *)0x0) &&
       (pcVar14 = (char *)(*pcVar13)(ppcVar10,0,&local_30,0), 0 < (int)pcVar14)) {
      pcVar22 = (char *)0x0;
      local_48 = ", ";
      do {
        unaff_s5 = (char *)(*(code *)PTR_OBJ_nid2sn_006a709c)
                                     (*(undefined4 *)(local_30 + (int)pcVar22 * 4));
        unaff_s8 = pcVar14;
        local_38 = (char *)ppcVar10;
        if (pcVar12 == (char *)0x0) {
          pcVar12 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x100,local_58,0x68);
          puVar3 = PTR_strlen_006a9a24;
          if (pcVar12 == (char *)0x0) goto LAB_00470734;
          *pcVar12 = '\0';
          uVar16 = (*(code *)puVar3)(unaff_s5);
          if (0xff < uVar16) {
            ppcVar21 = (char **)0x200;
            goto LAB_004709e4;
          }
          ppcVar20 = (char **)0x100;
        }
        else {
          iVar18 = (*(code *)PTR_strlen_006a9a24)(pcVar12);
          iVar23 = (*(code *)PTR_strlen_006a9a24)(unaff_s5);
          if ((char **)(iVar18 + iVar23) < ppcVar20) {
            cVar17 = *pcVar12;
          }
          else {
            ppcVar21 = ppcVar20 + 0x40;
            param_2 = ppcVar20;
LAB_004709e4:
            pcVar12 = (char *)(*(code *)PTR_CRYPTO_realloc_006a7b58)
                                        (pcVar12,ppcVar21,"engine.c",0x70);
            if (pcVar12 == (char *)0x0) goto LAB_00470734;
            cVar17 = *pcVar12;
            ppcVar20 = ppcVar21;
          }
          if (cVar17 != '\0') {
            (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar12,", ",ppcVar20);
          }
        }
        pcVar22 = pcVar22 + 1;
        (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar12,unaff_s5,ppcVar20);
        param_2 = ppcVar20;
      } while (pcVar14 != pcVar22);
    }
    pcVar13 = (code *)(*(code *)PTR_ENGINE_get_digests_006a7d7c)(ppcVar10);
    if (pcVar13 == (code *)0x0) {
LAB_00470ee8:
      pcVar13 = (code *)(*(code *)PTR_ENGINE_get_pkey_meths_006a7d80)(ppcVar10);
      if (pcVar13 != (code *)0x0) {
LAB_00470f04:
        local_38 = (char *)&local_30;
        unaff_s5 = (char *)(*pcVar13)(ppcVar10,0,local_38,0);
        if (0 < (int)unaff_s5) {
          pcVar14 = (char *)0x0;
          local_48 = ", ";
          do {
            unaff_s8 = (char *)(*(code *)PTR_OBJ_nid2sn_006a709c)
                                         (*(undefined4 *)(local_30 + (int)pcVar14 * 4));
            if (pcVar12 == (char *)0x0) {
              pcVar12 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x100,local_58,0x68);
              puVar3 = PTR_strlen_006a9a24;
              param_2 = ppcVar10;
              if (pcVar12 == (char *)0x0) goto LAB_00470734;
              *pcVar12 = '\0';
              uVar16 = (*(code *)puVar3)(unaff_s8);
              if (0xff < uVar16) {
                ppcVar20 = (char **)0x200;
                goto LAB_00470fc8;
              }
              ppcVar20 = (char **)0x100;
            }
            else {
              iVar18 = (*(code *)PTR_strlen_006a9a24)(pcVar12);
              iVar23 = (*(code *)PTR_strlen_006a9a24)(unaff_s8);
              if (ppcVar20 <= (char **)(iVar18 + iVar23)) {
                ppcVar20 = ppcVar20 + 0x40;
LAB_00470fc8:
                pcVar12 = (char *)(*(code *)PTR_CRYPTO_realloc_006a7b58)
                                            (pcVar12,ppcVar20,"engine.c",0x70);
                param_2 = ppcVar10;
                if (pcVar12 == (char *)0x0) goto LAB_00470734;
              }
              if (*pcVar12 != '\0') {
                (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar12,", ",ppcVar20);
                local_38 = (char *)ppcVar20;
              }
            }
            pcVar14 = pcVar14 + 1;
            (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar12,unaff_s8,ppcVar20);
          } while (unaff_s5 != pcVar14);
          goto LAB_00471348;
        }
      }
      if (pcVar12 != (char *)0x0) {
        cVar17 = *pcVar12;
        goto LAB_0047134c;
      }
    }
    else {
      local_38 = (char *)&local_30;
      unaff_s8 = (char *)(*pcVar13)(ppcVar10,0,local_38,0);
      if ((int)unaff_s8 < 1) goto LAB_00470ee8;
      pcVar14 = (char *)0x0;
      local_48 = ", ";
      param_2 = ppcVar10;
      do {
        unaff_s5 = (char *)(*(code *)PTR_OBJ_nid2sn_006a709c)
                                     (*(undefined4 *)(local_30 + (int)pcVar14 * 4));
        if (pcVar12 == (char *)0x0) {
          pcVar12 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x100,local_58,0x68);
          puVar3 = PTR_strlen_006a9a24;
          if (pcVar12 == (char *)0x0) goto LAB_00470734;
          *pcVar12 = '\0';
          uVar16 = (*(code *)puVar3)(unaff_s5);
          if (0xff < uVar16) {
            ppcVar21 = (char **)0x200;
            goto LAB_00470e0c;
          }
          ppcVar20 = (char **)0x100;
        }
        else {
          iVar18 = (*(code *)PTR_strlen_006a9a24)(pcVar12);
          iVar23 = (*(code *)PTR_strlen_006a9a24)(unaff_s5);
          ppcVar21 = ppcVar20;
          if (ppcVar20 <= (char **)(iVar18 + iVar23)) {
            ppcVar21 = ppcVar20 + 0x40;
            param_2 = ppcVar20;
LAB_00470e0c:
            pcVar12 = (char *)(*(code *)PTR_CRYPTO_realloc_006a7b58)
                                        (pcVar12,ppcVar21,"engine.c",0x70);
            if (pcVar12 == (char *)0x0) goto LAB_00470734;
          }
          ppcVar20 = ppcVar21;
          if (*pcVar12 != '\0') {
            (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar12,", ",ppcVar21);
          }
        }
        pcVar14 = pcVar14 + 1;
        (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar12,unaff_s5,ppcVar20);
        param_2 = ppcVar20;
      } while (unaff_s8 != pcVar14);
      pcVar13 = (code *)(*(code *)PTR_ENGINE_get_pkey_meths_006a7d80)(ppcVar10);
      if (pcVar13 != (code *)0x0) goto LAB_00470f04;
LAB_00471348:
      local_48 = ", ";
      cVar17 = *pcVar12;
LAB_0047134c:
      if (cVar17 != '\0') {
        (*(code *)PTR_BIO_printf_006a6e38)(puVar8," [%s]\n",pcVar12);
      }
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar12);
  }
  if (local_68 != 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(puVar8,"%s",local_50);
    iVar18 = (*(code *)PTR_ENGINE_init_006a7d78)(ppcVar10);
    if (iVar18 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(puVar8,"[ unavailable ]\n");
      if (local_40 != (char *)0x0) {
        (*(code *)PTR_ERR_print_errors_fp_006a7d8c)(*local_4c);
      }
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
    }
    else {
      (*(code *)PTR_BIO_printf_006a6e38)(puVar8,"[ available ]\n");
      util_do_cmds_isra_0(ppcVar10,uVar7,puVar8);
      (*(code *)PTR_ENGINE_finish_006a6fc4)(ppcVar10);
    }
  }
  if ((int)local_64 < 1) goto LAB_0047052c;
  iVar18 = (*(code *)PTR_ENGINE_ctrl_006a7bc8)(ppcVar10,10,0,0,0);
  if (iVar18 == 0) goto LAB_0047052c;
  iVar18 = (*(code *)PTR_ENGINE_ctrl_006a7bc8)(ppcVar10,0xb,0,0,0);
  if (iVar18 < 1) goto LAB_0047052c;
  local_48 = (char *)(*(code *)PTR_sk_new_null_006a6fa4)();
  param_2 = ppcVar10;
  if (local_48 != (char *)0x0) {
    iVar23 = 0;
    local_38 = "-check_ss_sig";
    goto LAB_00470b88;
  }
LAB_00470734:
  iVar18 = 1;
  puVar8 = puVar5;
  do {
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
    (*(code *)PTR_sk_pop_free_006a7058)(puVar8,local_5c - 0xc0);
    (*(code *)PTR_sk_pop_free_006a7058)(uVar6,local_5c - 0xc0);
    (*(code *)PTR_sk_pop_free_006a7058)(uVar7,local_5c - 0xc0);
    param_1 = local_5c;
    if (local_60 != (undefined *)0x0) {
      (*(code *)PTR_BIO_free_all_006a6e74)();
    }
LAB_00470298:
    if (local_2c == *(int *)puVar4) {
      return iVar18;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    ppcVar10 = param_2;
LAB_00471720:
    param_1 = param_1 & 0xfffffff0;
    if (param_1 == 0) goto LAB_004711c8;
    bVar1 = false;
LAB_004715b4:
    (*(code *)PTR_BIO_printf_006a6e38)(puVar8,"<0x%04X>",param_1);
LAB_004714b4:
    if (!bVar1) goto LAB_004711c8;
LAB_004714bc:
    (*(code *)PTR_BIO_printf_006a6e38)(puVar8,"  <illegal flags!>");
LAB_004711c8:
    iVar23 = 0;
    (*(code *)PTR_BIO_printf_006a6e38)(puVar8,"\n");
LAB_00471120:
    (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s8);
    if (unaff_s5 != (char *)0x0) goto LAB_00470cd8;
LAB_00470b64:
    iVar18 = (*(code *)PTR_ENGINE_ctrl_006a7bc8)(ppcVar10,0xc,iVar18,0,0);
    if (0 < iVar18) {
LAB_00470b88:
      param_1 = (*(code *)PTR_ENGINE_ctrl_006a7bc8)(ppcVar10,0x12,iVar18,0,0);
      if ((int)param_1 < 0) {
LAB_004713b4:
        bVar1 = false;
        goto LAB_004713b8;
      }
      if (((param_1 & 8) != 0) && (local_64 != (char *)0x4)) {
        (*(code *)PTR_CRYPTO_free_006a6e88)(0);
        goto LAB_00470b64;
      }
      iVar15 = (*(code *)PTR_ENGINE_ctrl_006a7bc8)(ppcVar10,0xe,iVar18,0,0);
      if ((iVar15 < 1) ||
         (unaff_s8 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar15 + 1,local_58,0xda),
         unaff_s5 = local_58, unaff_s8 == (char *)0x0)) goto LAB_004713b4;
      iVar15 = (*(code *)PTR_ENGINE_ctrl_006a7bc8)(ppcVar10,0xf,iVar18,unaff_s8,0);
      if ((iVar15 < 1) ||
         (iVar15 = (*(code *)PTR_ENGINE_ctrl_006a7bc8)(ppcVar10,0x10,iVar18,0,0), iVar15 < 0)) {
        unaff_s5 = (char *)0x0;
LAB_00471050:
        (*(code *)PTR_sk_pop_free_006a7058)(local_48,local_5c - 0xc0);
        (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s8);
        param_2 = ppcVar10;
        puVar5 = local_74;
        if (unaff_s5 != (char *)0x0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s5);
        }
        goto LAB_00470734;
      }
      if (iVar15 == 0) {
        unaff_s5 = (char *)0x0;
      }
      else {
        unaff_s5 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar15 + 1,local_58,0xe4);
        if ((unaff_s5 == (char *)0x0) ||
           (iVar15 = (*(code *)PTR_ENGINE_ctrl_006a7bc8)(ppcVar10,0x11,iVar18,unaff_s5,0),
           iVar15 < 1)) goto LAB_00471050;
      }
      if (iVar23 == 0) {
        iVar15 = (*(code *)PTR_BIO_puts_006a6f58)(puVar8,local_50);
      }
      else {
        iVar15 = (*(code *)PTR_BIO_printf_006a6e38)(puVar8,", ");
        iVar15 = iVar23 + iVar15;
      }
      if (local_64 == (char *)0x1) {
        if ((5 < iVar15) &&
           (iVar23 = (*(code *)PTR_strlen_006a9a24)(unaff_s8), 0x4e < iVar23 + iVar15)) {
          (*(code *)PTR_BIO_printf_006a6e38)(puVar8,"\n");
          iVar15 = (*(code *)PTR_BIO_puts_006a6f58)(puVar8,local_50);
        }
        iVar23 = (*(code *)PTR_BIO_printf_006a6e38)(puVar8,"%s",unaff_s8);
        iVar23 = iVar23 + iVar15;
        goto LAB_00471120;
      }
      if (unaff_s5 == (char *)0x0) {
        (*(code *)PTR_BIO_printf_006a6e38)(puVar8,local_44 + 0x3ea4,unaff_s8,local_3c);
        if (local_64 != (char *)0x2) goto LAB_0047115c;
        iVar23 = 0;
        (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s8);
        goto LAB_00470b64;
      }
      (*(code *)PTR_BIO_printf_006a6e38)(puVar8,local_44 + 0x3ea4,unaff_s8,unaff_s5);
      if (local_64 == (char *)0x2) {
        iVar23 = 0;
        (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s8);
LAB_00470cd8:
        (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s5);
        goto LAB_00470b64;
      }
LAB_0047115c:
      (*(code *)PTR_BIO_printf_006a6e38)(puVar8,(char **)((int)local_38 + 0x3e40),local_50,local_50)
      ;
      if (param_1 == 0) {
        iVar23 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)(puVar8,"<no flags>\n");
        goto LAB_00471120;
      }
      if ((param_1 & 8) != 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(puVar8,"[Internal] ");
      }
      if ((param_1 & 1) == 0) {
        bVar1 = false;
        if ((param_1 & 2) != 0) goto LAB_00471484;
        if ((param_1 & 4) == 0) goto LAB_00471720;
        (*(code *)PTR_BIO_printf_006a6e38)(puVar8,"NO_INPUT");
joined_r0x00471590:
        if ((param_1 & 0xfffffff0) != 0) {
          bVar1 = false;
          break;
        }
        goto LAB_004711c8;
      }
      (*(code *)PTR_BIO_printf_006a6e38)(puVar8,"NUMERIC");
      if ((param_1 & 2) == 0) {
        if ((param_1 & 4) != 0) goto LAB_004715d4;
        goto joined_r0x00471590;
      }
      bVar1 = true;
      (*(code *)PTR_BIO_printf_006a6e38)(puVar8,&DAT_00643e74);
LAB_00471484:
      (*(code *)PTR_BIO_printf_006a6e38)(puVar8,"STRING");
      if ((param_1 & 4) == 0) {
        if ((param_1 & 0xfffffff0) == 0) goto LAB_004714b4;
        break;
      }
LAB_004715d4:
      bVar1 = true;
      (*(code *)PTR_BIO_printf_006a6e38)(puVar8,&DAT_00643e74);
      (*(code *)PTR_BIO_printf_006a6e38)(puVar8,"NO_INPUT");
      if ((param_1 & 0xfffffff0) != 0) break;
      goto LAB_004714bc;
    }
    if (iVar23 < 1) {
      bVar1 = true;
    }
    else {
      bVar1 = true;
      (*(code *)PTR_BIO_printf_006a6e38)(puVar8,"\n");
    }
LAB_004713b8:
    (*(code *)PTR_sk_pop_free_006a7058)(local_48,local_5c - 0xc0);
    param_2 = ppcVar10;
    puVar5 = local_74;
    if (!bVar1) goto LAB_00470734;
LAB_0047052c:
    (*(code *)PTR_ENGINE_free_006a6e84)(ppcVar10);
    param_2 = ppcVar10;
LAB_0047053c:
    local_70 = local_70 + 1;
    iVar18 = (*(code *)PTR_sk_num_006a6e2c)(local_74);
    if ((int)local_70 < iVar18) goto LAB_00470450;
LAB_00470564:
    iVar18 = 0;
    puVar8 = local_74;
  } while( true );
  param_1 = param_1 & 0xfffffff0;
  (*(code *)PTR_BIO_printf_006a6e38)(puVar8,&DAT_00643e74);
  goto LAB_004715b4;
}

