
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
  char **local_38;
  char *local_30;
  int local_2c;
  
  puVar4 = PTR___stack_chk_guard_006aabf0;
  puVar2 = PTR_bio_err_006a7f3c;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar5 = (undefined *)(*(code *)PTR_sk_new_null_006a80a4)();
  uVar6 = (*(code *)PTR_sk_new_null_006a80a4)();
  uVar7 = (*(code *)PTR_sk_new_null_006a80a4)();
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  (*(code *)PTR_SSL_load_error_strings_006a867c)();
  iVar18 = *(int *)puVar2;
  if (iVar18 == 0) {
    iVar18 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stderr_006aac00,0);
    *(int *)puVar2 = iVar18;
  }
  iVar18 = load_config(iVar18,0);
  if (iVar18 == 0) {
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
    (*(code *)PTR_sk_pop_free_006a8158)(puVar5,identity);
    (*(code *)PTR_sk_pop_free_006a8158)(uVar6,identity);
    iVar18 = 1;
    (*(code *)PTR_sk_pop_free_006a8158)(uVar7,identity);
    puVar8 = puVar5;
    goto LAB_0046f848;
  }
  local_4c = (undefined4 *)PTR_stdout_006aaad4;
  iVar18 = param_1 - 1;
  param_2 = param_2 + 1;
  puVar8 = (undefined *)(*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdout_006aaad4,0);
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
    local_74 = &DAT_00644314;
    pcVar14 = (char *)0x0;
    local_64 = "s\n";
    unaff_s5 = (char *)0x0;
    do {
      unaff_s8 = *param_2;
      iVar23 = (*(code *)PTR_strncmp_006aaa7c)(unaff_s8,&DAT_0064430c,2);
      ppcVar10 = param_2;
      if (iVar23 == 0) {
        pcVar14 = (char *)0x0;
        pcVar12 = unaff_s8;
        do {
          pcVar22 = pcVar14;
          pcVar12 = pcVar12 + 1;
          pcVar14 = pcVar22 + 1;
        } while (*pcVar12 == 'v');
        pcVar14 = (char *)(*(code *)PTR_strlen_006aab30)();
        if ((pcVar22 < pcVar14) || (4 < (int)pcVar14)) goto LAB_0046fca0;
      }
      else {
        cVar17 = *unaff_s8;
        if (((cVar17 == '-') && (unaff_s8[1] == 'c')) && (unaff_s8[2] == '\0')) {
          local_6c = 1;
        }
        else {
          iVar23 = (*(code *)PTR_strncmp_006aaa7c)(unaff_s8,&DAT_00644310,2);
          if (iVar23 == 0) {
            pcVar22 = (char *)0x0;
            pcVar12 = unaff_s8;
            do {
              unaff_s5 = pcVar22;
              pcVar12 = pcVar12 + 1;
              pcVar22 = unaff_s5 + 1;
            } while (*pcVar12 == 't');
            pcVar12 = (char *)(*(code *)PTR_strlen_006aab30)();
            if ((unaff_s5 < pcVar12) || (unaff_s5 = pcVar12 + -1, 1 < (int)unaff_s5))
            goto LAB_0046fca0;
            local_68 = 1;
          }
          else {
            iVar23 = (*(code *)PTR_strcmp_006aac20)(unaff_s8,&DAT_00644314);
            if (iVar23 == 0) {
              iVar18 = iVar18 + -1;
              if (iVar18 == 0) goto LAB_0046fca0;
              (*(code *)PTR_sk_push_006a80a8)(uVar6,param_2[1]);
              ppcVar10 = param_2 + 1;
            }
            else {
              iVar23 = (*(code *)PTR_strcmp_006aac20)(unaff_s8,"-post");
              if (iVar23 == 0) {
                iVar18 = iVar18 + -1;
                ppcVar10 = param_2 + 1;
                if (iVar18 == 0) goto LAB_0046fca0;
                (*(code *)PTR_sk_push_006a80a8)(uVar7,param_2[1]);
              }
              else {
                iVar23 = (*(code *)PTR_strncmp_006aaa7c)(unaff_s8,&DAT_00641850,2);
                if ((iVar23 == 0) ||
                   (((cVar17 == '-' && (unaff_s8[1] == '?')) && (unaff_s8[2] == '\0')))) {
LAB_0046fca0:
                  if (engine_usage._0_4_ != 0) {
                    puVar19 = engine_usage;
                    do {
                      puVar19 = (undefined1 *)((int)puVar19 + 4);
                      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"%s");
                    } while (*(int *)puVar19 != 0);
                  }
                  local_5c = 0x470000;
                  local_70 = puVar5;
                  goto LAB_0046fce4;
                }
                (*(code *)PTR_sk_push_006a80a8)(puVar5,unaff_s8);
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
  iVar18 = (*(code *)PTR_sk_num_006a7f2c)(puVar5);
  if (iVar18 == 0) {
    for (iVar18 = (*(code *)PTR_ENGINE_get_first_006a8e74)(); iVar18 != 0;
        iVar18 = (*(code *)PTR_ENGINE_get_next_006a8e78)(iVar18)) {
      uVar9 = (*(code *)PTR_ENGINE_get_id_006a8cc0)(iVar18);
      (*(code *)PTR_sk_push_006a80a8)(puVar5,uVar9);
    }
  }
  local_70 = (undefined *)0x0;
  local_5c = 0x470000;
  local_54 = "s\n";
  local_58 = "engine.c";
  local_3c = "<no description>";
  local_44 = "s\n";
  local_50 = &DAT_0063f0b4;
  iVar18 = (*(code *)PTR_sk_num_006a7f2c)(puVar5);
  local_74 = puVar5;
  local_64 = pcVar14;
  if (iVar18 < 1) goto LAB_0046fb14;
LAB_0046fa00:
  uVar9 = (*(code *)PTR_sk_value_006a7f24)(local_74,local_70);
  ppcVar10 = (char **)(*(code *)PTR_ENGINE_by_id_006a7f9c)(uVar9);
  param_2 = ppcVar10;
  if (ppcVar10 == (char **)0x0) {
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
    goto LAB_0046faec;
  }
  uVar11 = (*(code *)PTR_ENGINE_get_name_006a8e50)(ppcVar10);
  (*(code *)PTR_BIO_printf_006a7f38)(puVar8,local_54 + 0x432c,uVar9,uVar11);
  util_do_cmds_isra_0(ppcVar10,uVar6,puVar8);
  uVar11 = (*(code *)PTR_ENGINE_get_id_006a8cc0)(ppcVar10);
  iVar18 = (*(code *)PTR_strcmp_006aac20)(uVar11,uVar9);
  if (iVar18 != 0) {
    uVar9 = (*(code *)PTR_ENGINE_get_id_006a8cc0)(ppcVar10);
    uVar11 = (*(code *)PTR_ENGINE_get_name_006a8e50)(ppcVar10);
    (*(code *)PTR_BIO_printf_006a7f38)(puVar8,"Loaded: (%s) %s\n",uVar9,uVar11);
  }
  puVar5 = local_74;
  if (local_6c != 0) {
    iVar18 = (*(code *)PTR_ENGINE_get_RSA_006a8e54)(ppcVar10);
    if (iVar18 == 0) {
      iVar18 = (*(code *)PTR_ENGINE_get_DSA_006a8e58)(ppcVar10);
      if (iVar18 != 0) {
        pcVar12 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x100,local_58,0x6b);
        if (pcVar12 == (char *)0x0) goto LAB_0046fce4;
        *pcVar12 = '\0';
        ppcVar21 = (char **)0x100;
        ppcVar20 = (char **)0x100;
LAB_0046fdec:
        (*(code *)PTR_BUF_strlcat_006a8068)(pcVar12,"DSA",ppcVar21);
        goto LAB_0046fe08;
      }
      iVar18 = (*(code *)PTR_ENGINE_get_DH_006a8e5c)(ppcVar10);
      if (iVar18 != 0) {
        pcVar12 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x100,local_58,0x6b);
        if (pcVar12 == (char *)0x0) goto LAB_0046fce4;
        *pcVar12 = '\0';
        ppcVar21 = (char **)0x100;
        ppcVar20 = (char **)0x100;
        goto LAB_0046fe44;
      }
      iVar18 = (*(code *)PTR_ENGINE_get_RAND_006a8e60)(ppcVar10);
      if (iVar18 != 0) {
        pcVar12 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x100,local_58,0x6b);
        if (pcVar12 == (char *)0x0) goto LAB_0046fce4;
        *pcVar12 = '\0';
        ppcVar21 = (char **)0x100;
        ppcVar20 = (char **)0x100;
        goto LAB_0046fe9c;
      }
      pcVar12 = (char *)0x0;
      ppcVar20 = (char **)0x100;
    }
    else {
      pcVar12 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x100,local_58,0x6b);
      puVar3 = PTR_BUF_strlcat_006a8068;
      if (pcVar12 == (char *)0x0) goto LAB_0046fce4;
      *pcVar12 = '\0';
      (*(code *)puVar3)(pcVar12,"RSA",0x100);
      iVar18 = (*(code *)PTR_ENGINE_get_DSA_006a8e58)(ppcVar10);
      if (iVar18 != 0) {
        iVar18 = (*(code *)PTR_strlen_006aab30)(pcVar12);
        if (iVar18 + 3U < 0x100) {
          ppcVar21 = (char **)0x100;
          ppcVar20 = (char **)0x100;
        }
        else {
          pcVar12 = (char *)(*(code *)PTR_CRYPTO_realloc_006a8c44)(pcVar12,0x200,local_58,0x77);
          if (pcVar12 == (char *)0x0) goto LAB_0046fce4;
          ppcVar21 = (char **)0x200;
          ppcVar20 = (char **)0x200;
        }
        if (*pcVar12 != '\0') {
          (*(code *)PTR_BUF_strlcat_006a8068)(pcVar12,", ",ppcVar21);
        }
        goto LAB_0046fdec;
      }
      ppcVar21 = (char **)0x100;
      ppcVar20 = (char **)0x100;
LAB_0046fe08:
      iVar18 = (*(code *)PTR_ENGINE_get_DH_006a8e5c)(ppcVar10);
      if (iVar18 == 0) {
        iVar18 = (*(code *)PTR_ENGINE_get_RAND_006a8e60)(ppcVar10);
      }
      else {
        iVar18 = (*(code *)PTR_strlen_006aab30)(pcVar12);
        if (ppcVar21 <= (char **)(iVar18 + 2)) {
          ppcVar20 = ppcVar20 + 0x40;
          pcVar12 = (char *)(*(code *)PTR_CRYPTO_realloc_006a8c44)(pcVar12,ppcVar20,"engine.c",0x77)
          ;
          ppcVar21 = ppcVar20;
          if (pcVar12 == (char *)0x0) goto LAB_0046fce4;
        }
        if (*pcVar12 != '\0') {
          (*(code *)PTR_BUF_strlcat_006a8068)(pcVar12,", ",ppcVar21);
        }
LAB_0046fe44:
        (*(code *)PTR_BUF_strlcat_006a8068)(pcVar12,"DH",ppcVar21);
        iVar18 = (*(code *)PTR_ENGINE_get_RAND_006a8e60)(ppcVar10);
      }
      if (iVar18 != 0) {
        iVar18 = (*(code *)PTR_strlen_006aab30)(pcVar12);
        if (ppcVar21 <= (char **)(iVar18 + 4)) {
          ppcVar20 = ppcVar20 + 0x40;
          pcVar12 = (char *)(*(code *)PTR_CRYPTO_realloc_006a8c44)(pcVar12,ppcVar20,"engine.c",0x77)
          ;
          ppcVar21 = ppcVar20;
          if (pcVar12 == (char *)0x0) goto LAB_0046fce4;
        }
        if (*pcVar12 != '\0') {
          (*(code *)PTR_BUF_strlcat_006a8068)(pcVar12,", ",ppcVar21);
        }
LAB_0046fe9c:
        (*(code *)PTR_BUF_strlcat_006a8068)(pcVar12,"RAND",ppcVar21);
      }
    }
    pcVar13 = (code *)(*(code *)PTR_ENGINE_get_ciphers_006a8e64)(ppcVar10);
    if ((pcVar13 != (code *)0x0) &&
       (pcVar14 = (char *)(*pcVar13)(ppcVar10,0,&local_30,0), 0 < (int)pcVar14)) {
      pcVar22 = (char *)0x0;
      local_48 = ", ";
      do {
        unaff_s5 = (char *)(*(code *)PTR_OBJ_nid2sn_006a819c)
                                     (*(undefined4 *)(local_30 + (int)pcVar22 * 4));
        unaff_s8 = pcVar14;
        local_38 = ppcVar10;
        if (pcVar12 == (char *)0x0) {
          pcVar12 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x100,local_58,0x6b);
          puVar3 = PTR_strlen_006aab30;
          if (pcVar12 == (char *)0x0) goto LAB_0046fce4;
          *pcVar12 = '\0';
          uVar16 = (*(code *)puVar3)(unaff_s5);
          if (0xff < uVar16) {
            ppcVar21 = (char **)0x200;
            goto LAB_0046ff94;
          }
          ppcVar20 = (char **)0x100;
        }
        else {
          iVar18 = (*(code *)PTR_strlen_006aab30)(pcVar12);
          iVar23 = (*(code *)PTR_strlen_006aab30)(unaff_s5);
          if ((char **)(iVar18 + iVar23) < ppcVar20) {
            cVar17 = *pcVar12;
          }
          else {
            ppcVar21 = ppcVar20 + 0x40;
            param_2 = ppcVar20;
LAB_0046ff94:
            pcVar12 = (char *)(*(code *)PTR_CRYPTO_realloc_006a8c44)
                                        (pcVar12,ppcVar21,"engine.c",0x77);
            if (pcVar12 == (char *)0x0) goto LAB_0046fce4;
            cVar17 = *pcVar12;
            ppcVar20 = ppcVar21;
          }
          if (cVar17 != '\0') {
            (*(code *)PTR_BUF_strlcat_006a8068)(pcVar12,", ",ppcVar20);
          }
        }
        pcVar22 = pcVar22 + 1;
        (*(code *)PTR_BUF_strlcat_006a8068)(pcVar12,unaff_s5,ppcVar20);
        param_2 = ppcVar20;
      } while (pcVar14 != pcVar22);
    }
    pcVar13 = (code *)(*(code *)PTR_ENGINE_get_digests_006a8e6c)(ppcVar10);
    if (pcVar13 == (code *)0x0) {
LAB_00470498:
      pcVar13 = (code *)(*(code *)PTR_ENGINE_get_pkey_meths_006a8e70)(ppcVar10);
      if (pcVar13 != (code *)0x0) {
LAB_004704b4:
        local_38 = &local_30;
        unaff_s5 = (char *)(*pcVar13)(ppcVar10,0,local_38,0);
        if (0 < (int)unaff_s5) {
          pcVar14 = (char *)0x0;
          local_48 = ", ";
          do {
            unaff_s8 = (char *)(*(code *)PTR_OBJ_nid2sn_006a819c)
                                         (*(undefined4 *)(local_30 + (int)pcVar14 * 4));
            if (pcVar12 == (char *)0x0) {
              pcVar12 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x100,local_58,0x6b);
              puVar3 = PTR_strlen_006aab30;
              param_2 = ppcVar10;
              if (pcVar12 == (char *)0x0) goto LAB_0046fce4;
              *pcVar12 = '\0';
              uVar16 = (*(code *)puVar3)(unaff_s8);
              if (0xff < uVar16) {
                ppcVar20 = (char **)0x200;
                goto LAB_00470578;
              }
              ppcVar20 = (char **)0x100;
            }
            else {
              iVar18 = (*(code *)PTR_strlen_006aab30)(pcVar12);
              iVar23 = (*(code *)PTR_strlen_006aab30)(unaff_s8);
              if (ppcVar20 <= (char **)(iVar18 + iVar23)) {
                ppcVar20 = ppcVar20 + 0x40;
LAB_00470578:
                pcVar12 = (char *)(*(code *)PTR_CRYPTO_realloc_006a8c44)
                                            (pcVar12,ppcVar20,"engine.c",0x77);
                param_2 = ppcVar10;
                if (pcVar12 == (char *)0x0) goto LAB_0046fce4;
              }
              if (*pcVar12 != '\0') {
                (*(code *)PTR_BUF_strlcat_006a8068)(pcVar12,", ",ppcVar20);
                local_38 = ppcVar20;
              }
            }
            pcVar14 = pcVar14 + 1;
            (*(code *)PTR_BUF_strlcat_006a8068)(pcVar12,unaff_s8,ppcVar20);
          } while (unaff_s5 != pcVar14);
          goto LAB_004708f8;
        }
      }
      if (pcVar12 != (char *)0x0) {
        cVar17 = *pcVar12;
        goto LAB_004708fc;
      }
    }
    else {
      local_38 = &local_30;
      unaff_s8 = (char *)(*pcVar13)(ppcVar10,0,local_38,0);
      if ((int)unaff_s8 < 1) goto LAB_00470498;
      pcVar14 = (char *)0x0;
      local_48 = ", ";
      param_2 = ppcVar10;
      do {
        unaff_s5 = (char *)(*(code *)PTR_OBJ_nid2sn_006a819c)
                                     (*(undefined4 *)(local_30 + (int)pcVar14 * 4));
        if (pcVar12 == (char *)0x0) {
          pcVar12 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x100,local_58,0x6b);
          puVar3 = PTR_strlen_006aab30;
          if (pcVar12 == (char *)0x0) goto LAB_0046fce4;
          *pcVar12 = '\0';
          uVar16 = (*(code *)puVar3)(unaff_s5);
          if (0xff < uVar16) {
            ppcVar21 = (char **)0x200;
            goto LAB_004703bc;
          }
          ppcVar20 = (char **)0x100;
        }
        else {
          iVar18 = (*(code *)PTR_strlen_006aab30)(pcVar12);
          iVar23 = (*(code *)PTR_strlen_006aab30)(unaff_s5);
          ppcVar21 = ppcVar20;
          if (ppcVar20 <= (char **)(iVar18 + iVar23)) {
            ppcVar21 = ppcVar20 + 0x40;
            param_2 = ppcVar20;
LAB_004703bc:
            pcVar12 = (char *)(*(code *)PTR_CRYPTO_realloc_006a8c44)
                                        (pcVar12,ppcVar21,"engine.c",0x77);
            if (pcVar12 == (char *)0x0) goto LAB_0046fce4;
          }
          ppcVar20 = ppcVar21;
          if (*pcVar12 != '\0') {
            (*(code *)PTR_BUF_strlcat_006a8068)(pcVar12,", ",ppcVar21);
          }
        }
        pcVar14 = pcVar14 + 1;
        (*(code *)PTR_BUF_strlcat_006a8068)(pcVar12,unaff_s5,ppcVar20);
        param_2 = ppcVar20;
      } while (unaff_s8 != pcVar14);
      pcVar13 = (code *)(*(code *)PTR_ENGINE_get_pkey_meths_006a8e70)(ppcVar10);
      if (pcVar13 != (code *)0x0) goto LAB_004704b4;
LAB_004708f8:
      local_48 = ", ";
      cVar17 = *pcVar12;
LAB_004708fc:
      if (cVar17 != '\0') {
        (*(code *)PTR_BIO_printf_006a7f38)(puVar8," [%s]\n",pcVar12);
      }
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar12);
  }
  if (local_68 != 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(puVar8,"%s",local_50);
    iVar18 = (*(code *)PTR_ENGINE_init_006a8e68)(ppcVar10);
    if (iVar18 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(puVar8,"[ unavailable ]\n");
      if (local_40 != (char *)0x0) {
        (*(code *)PTR_ERR_print_errors_fp_006a8e7c)(*local_4c);
      }
      (*(code *)PTR_ERR_clear_error_006a7fe0)();
    }
    else {
      (*(code *)PTR_BIO_printf_006a7f38)(puVar8,"[ available ]\n");
      util_do_cmds_isra_0(ppcVar10,uVar7,puVar8);
      (*(code *)PTR_ENGINE_finish_006a80c4)(ppcVar10);
    }
  }
  if ((int)local_64 < 1) goto LAB_0046fadc;
  iVar18 = (*(code *)PTR_ENGINE_ctrl_006a8cb4)(ppcVar10,10,0,0,0);
  if (iVar18 == 0) goto LAB_0046fadc;
  iVar18 = (*(code *)PTR_ENGINE_ctrl_006a8cb4)(ppcVar10,0xb,0,0,0);
  if (iVar18 < 1) goto LAB_0046fadc;
  local_48 = (char *)(*(code *)PTR_sk_new_null_006a80a4)();
  param_2 = ppcVar10;
  if (local_48 != (char *)0x0) {
    iVar23 = 0;
    local_38 = (char **)0x640000;
    goto LAB_00470138;
  }
LAB_0046fce4:
  iVar18 = 1;
  puVar8 = puVar5;
  do {
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
    (*(code *)PTR_sk_pop_free_006a8158)(puVar8,local_5c - 0xb10);
    (*(code *)PTR_sk_pop_free_006a8158)(uVar6,local_5c - 0xb10);
    (*(code *)PTR_sk_pop_free_006a8158)(uVar7,local_5c - 0xb10);
    param_1 = local_5c;
    if (local_60 != (undefined *)0x0) {
      (*(code *)PTR_BIO_free_all_006a7f74)();
    }
LAB_0046f848:
    if (local_2c == *(int *)puVar4) {
      return iVar18;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    ppcVar10 = param_2;
LAB_00470cd0:
    param_1 = param_1 & 0xfffffff0;
    if (param_1 == 0) goto LAB_00470778;
    bVar1 = false;
LAB_00470b64:
    (*(code *)PTR_BIO_printf_006a7f38)(puVar8,"<0x%04X>",param_1);
LAB_00470a64:
    if (!bVar1) goto LAB_00470778;
LAB_00470a6c:
    (*(code *)PTR_BIO_printf_006a7f38)(puVar8,"  <illegal flags!>");
LAB_00470778:
    iVar23 = 0;
    (*(code *)PTR_BIO_printf_006a7f38)(puVar8,"\n");
LAB_004706d0:
    (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s8);
    if (unaff_s5 != (char *)0x0) goto LAB_00470288;
LAB_00470114:
    iVar18 = (*(code *)PTR_ENGINE_ctrl_006a8cb4)(ppcVar10,0xc,iVar18,0,0);
    if (0 < iVar18) {
LAB_00470138:
      param_1 = (*(code *)PTR_ENGINE_ctrl_006a8cb4)(ppcVar10,0x12,iVar18,0,0);
      if ((int)param_1 < 0) {
LAB_00470964:
        bVar1 = false;
        goto LAB_00470968;
      }
      if (((param_1 & 8) != 0) && (local_64 != (char *)0x4)) {
        (*(code *)PTR_CRYPTO_free_006a7f88)(0);
        goto LAB_00470114;
      }
      iVar15 = (*(code *)PTR_ENGINE_ctrl_006a8cb4)(ppcVar10,0xe,iVar18,0,0);
      if ((iVar15 < 1) ||
         (unaff_s8 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar15 + 1,local_58,0xe6),
         unaff_s5 = local_58, unaff_s8 == (char *)0x0)) goto LAB_00470964;
      iVar15 = (*(code *)PTR_ENGINE_ctrl_006a8cb4)(ppcVar10,0xf,iVar18,unaff_s8,0);
      if ((iVar15 < 1) ||
         (iVar15 = (*(code *)PTR_ENGINE_ctrl_006a8cb4)(ppcVar10,0x10,iVar18,0,0), iVar15 < 0)) {
        unaff_s5 = (char *)0x0;
LAB_00470600:
        (*(code *)PTR_sk_pop_free_006a8158)(local_48,local_5c - 0xb10);
        (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s8);
        param_2 = ppcVar10;
        puVar5 = local_74;
        if (unaff_s5 != (char *)0x0) {
          (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s5);
        }
        goto LAB_0046fce4;
      }
      if (iVar15 == 0) {
        unaff_s5 = (char *)0x0;
      }
      else {
        unaff_s5 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar15 + 1,local_58,0xf1);
        if ((unaff_s5 == (char *)0x0) ||
           (iVar15 = (*(code *)PTR_ENGINE_ctrl_006a8cb4)(ppcVar10,0x11,iVar18,unaff_s5,0),
           iVar15 < 1)) goto LAB_00470600;
      }
      if (iVar23 == 0) {
        iVar15 = (*(code *)PTR_BIO_puts_006a8058)(puVar8,local_50);
      }
      else {
        iVar15 = (*(code *)PTR_BIO_printf_006a7f38)(puVar8,", ");
        iVar15 = iVar23 + iVar15;
      }
      if (local_64 == (char *)0x1) {
        if ((5 < iVar15) &&
           (iVar23 = (*(code *)PTR_strlen_006aab30)(unaff_s8), 0x4e < iVar23 + iVar15)) {
          (*(code *)PTR_BIO_printf_006a7f38)(puVar8,"\n");
          iVar15 = (*(code *)PTR_BIO_puts_006a8058)(puVar8,local_50);
        }
        iVar23 = (*(code *)PTR_BIO_printf_006a7f38)(puVar8,"%s",unaff_s8);
        iVar23 = iVar23 + iVar15;
        goto LAB_004706d0;
      }
      if (unaff_s5 == (char *)0x0) {
        (*(code *)PTR_BIO_printf_006a7f38)(puVar8,local_44 + 0x43d4,unaff_s8,local_3c);
        if (local_64 != (char *)0x2) goto LAB_0047070c;
        iVar23 = 0;
        (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s8);
        goto LAB_00470114;
      }
      (*(code *)PTR_BIO_printf_006a7f38)(puVar8,local_44 + 0x43d4,unaff_s8,unaff_s5);
      if (local_64 == (char *)0x2) {
        iVar23 = 0;
        (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s8);
LAB_00470288:
        (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s5);
        goto LAB_00470114;
      }
LAB_0047070c:
      (*(code *)PTR_BIO_printf_006a7f38)(puVar8,local_38 + 0x10dc,local_50,local_50);
      if (param_1 == 0) {
        iVar23 = 0;
        (*(code *)PTR_BIO_printf_006a7f38)(puVar8,"<no flags>\n");
        goto LAB_004706d0;
      }
      if ((param_1 & 8) != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(puVar8,"[Internal] ");
      }
      if ((param_1 & 1) == 0) {
        bVar1 = false;
        if ((param_1 & 2) != 0) goto LAB_00470a34;
        if ((param_1 & 4) == 0) goto LAB_00470cd0;
        (*(code *)PTR_BIO_printf_006a7f38)(puVar8,"NO_INPUT");
joined_r0x00470b40:
        if ((param_1 & 0xfffffff0) != 0) {
          bVar1 = false;
          break;
        }
        goto LAB_00470778;
      }
      (*(code *)PTR_BIO_printf_006a7f38)(puVar8,"NUMERIC");
      if ((param_1 & 2) == 0) {
        if ((param_1 & 4) != 0) goto LAB_00470b84;
        goto joined_r0x00470b40;
      }
      bVar1 = true;
      (*(code *)PTR_BIO_printf_006a7f38)(puVar8,&DAT_006443a4);
LAB_00470a34:
      (*(code *)PTR_BIO_printf_006a7f38)(puVar8,"STRING");
      if ((param_1 & 4) == 0) {
        if ((param_1 & 0xfffffff0) == 0) goto LAB_00470a64;
        break;
      }
LAB_00470b84:
      bVar1 = true;
      (*(code *)PTR_BIO_printf_006a7f38)(puVar8,&DAT_006443a4);
      (*(code *)PTR_BIO_printf_006a7f38)(puVar8,"NO_INPUT");
      if ((param_1 & 0xfffffff0) != 0) break;
      goto LAB_00470a6c;
    }
    if (iVar23 < 1) {
      bVar1 = true;
    }
    else {
      bVar1 = true;
      (*(code *)PTR_BIO_printf_006a7f38)(puVar8,"\n");
    }
LAB_00470968:
    (*(code *)PTR_sk_pop_free_006a8158)(local_48,local_5c - 0xb10);
    param_2 = ppcVar10;
    puVar5 = local_74;
    if (!bVar1) goto LAB_0046fce4;
LAB_0046fadc:
    (*(code *)PTR_ENGINE_free_006a7f84)(ppcVar10);
    param_2 = ppcVar10;
LAB_0046faec:
    local_70 = local_70 + 1;
    iVar18 = (*(code *)PTR_sk_num_006a7f2c)(local_74);
    if ((int)local_70 < iVar18) goto LAB_0046fa00;
LAB_0046fb14:
    iVar18 = 0;
    puVar8 = local_74;
  } while( true );
  param_1 = param_1 & 0xfffffff0;
  (*(code *)PTR_BIO_printf_006a7f38)(puVar8,&DAT_006443a4);
  goto LAB_00470b64;
}

