
undefined4 passwd_main(undefined4 param_1,int param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined8 *puVar11;
  undefined4 uVar12;
  int iVar13;
  undefined *puVar14;
  byte bVar15;
  int iVar16;
  undefined8 *puVar17;
  int iVar18;
  int iVar19;
  char *pcVar20;
  bool bVar21;
  undefined4 uVar22;
  undefined4 local_2088;
  undefined4 local_2084;
  undefined4 local_2080;
  undefined4 local_207c;
  int local_2074;
  int local_2068;
  undefined8 *local_2054;
  int local_2034;
  int local_2030;
  undefined auStack_202c [8192];
  int local_2c;
  
  puVar10 = PTR___stack_chk_guard_006a9ae8;
  puVar9 = PTR_bio_err_006a6e3c;
  local_2034 = 0;
  local_2030 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  iVar16 = *(int *)puVar9;
  if (iVar16 == 0) {
    uVar12 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar16 = (*(code *)PTR_BIO_new_006a6ea4)(uVar12);
    *(int *)puVar9 = iVar16;
    if (iVar16 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar16,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
      iVar16 = *(int *)puVar9;
    }
  }
  iVar16 = (*(code *)PTR_load_config_006a6e64)(iVar16,0);
  if (iVar16 == 0) {
LAB_0042dd8c:
    iVar16 = 0;
LAB_0042dd90:
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar9);
joined_r0x0042e000:
    if (local_2030 == 0) {
      uVar12 = 1;
    }
    else {
      iVar18 = 0;
LAB_0042ddac:
      iVar19 = 0;
      uVar12 = 1;
LAB_0042ddb8:
      (*(code *)PTR_CRYPTO_free_006a6e88)();
LAB_0042ddc4:
      if (iVar19 != 0) {
LAB_0042ddd0:
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar19);
      }
LAB_0042dddc:
      if (iVar18 != 0) goto LAB_0042dde4;
    }
  }
  else {
    uVar12 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar16 = (*(code *)PTR_BIO_new_006a6ea4)(uVar12);
    if (iVar16 == 0) goto LAB_0042dd8c;
    puVar17 = (undefined8 *)(param_2 + 4);
    (*(code *)PTR_BIO_ctrl_006a6e18)(iVar16,0x6a,0x10,*(undefined4 *)PTR_stdout_006a99c8);
    pcVar20 = *(char **)(param_2 + 4);
    if (pcVar20 == (char *)0x0) {
      bVar15 = 1;
      bVar7 = false;
      bVar21 = true;
      bVar6 = false;
      local_2068 = 0;
      bVar5 = false;
      cVar3 = '\0';
      local_2080 = 0;
      local_207c = 0;
      local_2074 = 0;
      local_2054 = (undefined8 *)0x0;
      local_2084 = 0;
      cVar2 = '\0';
    }
    else {
      bVar8 = false;
      cVar3 = '\0';
      cVar2 = '\0';
      local_207c = 0;
      local_2080 = 0;
      local_2084 = 0;
      local_2074 = 0;
      bVar4 = false;
      local_2054 = (undefined8 *)0x0;
      bVar7 = false;
      bVar6 = false;
      local_2068 = 0;
      bVar21 = false;
      iVar18 = 0;
      iVar19 = 1;
      do {
        while (iVar13 = (*(code *)PTR_strcmp_006a9b18)(pcVar20,&DAT_00634d98), puVar11 = local_2054,
              iVar13 == 0) {
          puVar17 = (undefined8 *)(param_2 + (iVar19 + 1) * 4);
          bVar21 = true;
          pcVar20 = *(char **)puVar17;
          bVar5 = false;
          iVar18 = iVar19;
          iVar19 = iVar19 + 1;
          if (pcVar20 == (char *)0x0) goto joined_r0x0042deac;
        }
        cVar1 = *pcVar20;
        if (((cVar1 == '-') && (pcVar20[1] == '1')) && (pcVar20[2] == '\0')) {
          cVar2 = '\x01';
          bVar5 = false;
        }
        else {
          iVar13 = (*(code *)PTR_strcmp_006a9b18)(pcVar20,"-apr1");
          if (iVar13 == 0) {
            bVar8 = true;
            cVar3 = '\x01';
            bVar5 = false;
          }
          else {
            iVar13 = (*(code *)PTR_strcmp_006a9b18)(pcVar20,"-salt");
            if (iVar13 == 0) {
              if ((*(int *)(param_2 + (iVar19 + 1) * 4) == 0) || (local_2034 != 0)) {
LAB_0042dea8:
                bVar5 = true;
                puVar11 = local_2054;
                break;
              }
              iVar19 = iVar18 + 2;
              local_2074 = 1;
              local_2034 = *(int *)(param_2 + iVar19 * 4);
              bVar5 = false;
            }
            else {
              bVar5 = bVar4;
              if (((cVar1 == '-') && (pcVar20[1] == 'i')) &&
                 ((pcVar20[2] == 'n' && (pcVar20[3] == '\0')))) {
                if ((*(int *)(param_2 + (iVar19 + 1) * 4) == 0) || (bVar4)) goto LAB_0042dea8;
                iVar19 = iVar18 + 2;
                local_2068 = *(int *)(param_2 + iVar19 * 4);
                bVar4 = true;
              }
              else {
                iVar18 = (*(code *)PTR_strcmp_006a9b18)(pcVar20,"-stdin");
                if (iVar18 == 0) {
                  if (bVar4) goto LAB_0042dea8;
                  bVar6 = true;
                  bVar4 = true;
                }
                else {
                  iVar18 = (*(code *)PTR_strcmp_006a9b18)(pcVar20,"-noverify");
                  if (iVar18 == 0) {
                    bVar5 = false;
                    bVar7 = true;
                  }
                  else {
                    iVar18 = (*(code *)PTR_strcmp_006a9b18)(pcVar20,"-quiet");
                    if (iVar18 == 0) {
                      local_2084 = 1;
                      bVar5 = false;
                    }
                    else {
                      iVar18 = (*(code *)PTR_strcmp_006a9b18)(pcVar20,"-table");
                      if (iVar18 == 0) {
                        local_2080 = 1;
                        bVar5 = false;
                      }
                      else {
                        iVar18 = (*(code *)PTR_strcmp_006a9b18)(pcVar20,"-reverse");
                        if (iVar18 != 0) {
                          if ((cVar1 == '-') || (bVar5 = false, puVar11 = puVar17, bVar4))
                          goto LAB_0042dea8;
                          break;
                        }
                        local_207c = 1;
                        bVar5 = false;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        puVar17 = (undefined8 *)(param_2 + (iVar19 + 1) * 4);
        pcVar20 = *(char **)puVar17;
        iVar18 = iVar19;
        iVar19 = iVar19 + 1;
      } while (pcVar20 != (char *)0x0);
joined_r0x0042deac:
      local_2054 = puVar11;
      if (bVar21 == false) {
        if (cVar2 == '\0') {
          cVar2 = '\0';
          bVar21 = !bVar8;
          bVar15 = bVar21 + cVar3;
        }
        else {
          bVar15 = cVar3 + 1;
          cVar2 = '\x01';
        }
      }
      else {
        bVar21 = true;
        bVar15 = cVar2 + '\x01' + cVar3;
      }
    }
    if ((1 < bVar15) || (bVar5)) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar9,"Usage: passwd [options] [passwords]\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar9,"where options are\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar9,
                 "-crypt             standard Unix password algorithm (default)\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar9,"-1                 MD5-based password algorithm\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar9,
                 "-apr1              MD5-based password algorithm, Apache variant\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar9,"-salt string       use provided salt\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar9,"-in file           read passwords from file\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar9,"-stdin             read passwords from stdin\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar9,
                 "-noverify          never verify when reading password from terminal\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar9,"-quiet             no warnings\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar9,"-table             format output as table\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar9,"-reverse           switch table columns\n");
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar9);
      goto joined_r0x0042e000;
    }
    if (local_2068 == 0) {
      if (bVar6) {
        uVar12 = (*(code *)PTR_BIO_s_file_006a6ea0)();
        iVar18 = (*(code *)PTR_BIO_new_006a6ea4)(uVar12);
        if (iVar18 == 0) goto LAB_0042dd90;
        (*(code *)PTR_BIO_ctrl_006a6e18)(iVar18,0x6a,0,*(undefined4 *)PTR_stdin_006a9a14);
      }
      else {
        iVar18 = 0;
      }
LAB_0042e120:
      if (bVar21 == false) {
        if (cVar2 == '\0') {
          local_2088 = 1;
          uVar12 = 0x100;
          if (cVar3 != '\0') {
            local_2088 = 0x101;
          }
          uVar22 = 2;
          if (cVar3 == '\0') {
            uVar12 = 0;
          }
          else {
            uVar22 = 0x102;
          }
        }
        else {
          uVar22 = 0x102;
          uVar12 = 0x100;
          local_2088 = 0x101;
        }
      }
      else {
        uVar22 = 10;
        uVar12 = 8;
        local_2088 = 9;
      }
      if (local_2054 != (undefined8 *)0x0) {
        if (iVar18 != 0) {
          uVar12 = (*(code *)PTR___assert_fail_006a993c)
                             ("passwd != NULL","passwd.c",0xf4,"passwd_main");
          return uVar12;
        }
        iVar19 = 0;
        if (*(int *)local_2054 == 0) {
          uVar12 = (*(code *)PTR___assert_fail_006a993c)
                             ("*passwds != NULL","passwd.c",0xe5,"passwd_main");
          return uVar12;
        }
LAB_0042e35c:
        do {
          puVar17 = (undefined8 *)((int)local_2054 + 4);
          iVar18 = do_passwd(local_2074,&local_2034,&local_2030,*(undefined4 *)local_2054,iVar16,
                             local_2084,local_2080,local_207c,uVar12,bVar21,cVar2,cVar3);
          if (iVar18 == 0) {
            uVar12 = 1;
            goto LAB_0042e3dc;
          }
          local_2054 = puVar17;
        } while (*(int *)puVar17 != 0);
        uVar12 = 0;
LAB_0042e3dc:
        iVar18 = 0;
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar9);
        if (local_2030 != 0) goto LAB_0042ddb8;
        goto LAB_0042ddc4;
      }
      iVar19 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar22,"passwd.c",0xd1);
      if (iVar19 != 0) {
        if (iVar18 == 0) {
          iVar13 = (*(code *)PTR_EVP_read_pw_string_006a7278)
                             (iVar19,uVar22,"Password: ",local_2074 == 0 && !bVar7);
          if (iVar13 == 0) {
            local_2054 = &passwds_static_16012;
            passwds_static_16012._0_4_ = iVar19;
            goto LAB_0042e35c;
          }
        }
        else {
          do {
            while( true ) {
              iVar13 = (*(code *)PTR_BIO_gets_006a74d4)(iVar18,iVar19,local_2088);
              if (iVar13 < 1) {
                uVar12 = 0;
                goto LAB_0042e4dc;
              }
              puVar14 = (undefined *)(*(code *)PTR_strchr_006a9a28)(iVar19,10);
              if (puVar14 != (undefined *)0x0) break;
              do {
                iVar13 = (*(code *)PTR_BIO_gets_006a74d4)(iVar18,auStack_202c,0x2000);
                if (iVar13 < 1) {
                  iVar13 = do_passwd(local_2074,&local_2034,&local_2030,iVar19,iVar16,local_2084,
                                     local_2080,local_207c,uVar12,bVar21,cVar2,cVar3);
                  if (iVar13 == 0) goto LAB_0042e5fc;
                  uVar12 = 0;
                  goto LAB_0042e584;
                }
                iVar13 = (*(code *)PTR_strchr_006a9a28)(auStack_202c,10);
              } while (iVar13 == 0);
              iVar13 = do_passwd(local_2074,&local_2034,&local_2030,iVar19,iVar16,local_2084,
                                 local_2080,local_207c,uVar12,bVar21,cVar2,cVar3);
              if (iVar13 == 0) {
LAB_0042e5fc:
                uVar12 = 1;
LAB_0042e584:
                (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar9);
                if (local_2030 == 0) goto LAB_0042ddd0;
                goto LAB_0042ddb8;
              }
            }
            *puVar14 = 0;
            iVar13 = do_passwd(local_2074,&local_2034,&local_2030,iVar19,iVar16,local_2084,
                               local_2080,local_207c,uVar12,bVar21,cVar2,cVar3);
          } while (iVar13 != 0);
        }
        uVar12 = 1;
LAB_0042e4dc:
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar9);
        if (local_2030 != 0) goto LAB_0042ddb8;
        goto LAB_0042ddd0;
      }
      uVar12 = 1;
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar9);
      if (local_2030 != 0) goto LAB_0042ddb8;
      goto LAB_0042dddc;
    }
    uVar12 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar18 = (*(code *)PTR_BIO_new_006a6ea4)(uVar12);
    if (iVar18 == 0) goto LAB_0042dd90;
    if (bVar6) goto LAB_0042e6dc;
    iVar19 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar18,0x6c,3,local_2068);
    if (0 < iVar19) goto LAB_0042e120;
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar9);
    if (local_2030 != 0) goto LAB_0042ddac;
    uVar12 = 1;
LAB_0042dde4:
    (*(code *)PTR_BIO_free_006a6e70)(iVar18);
  }
  if (iVar16 != 0) {
    (*(code *)PTR_BIO_free_all_006a6e74)(iVar16);
  }
  if (local_2c == *(int *)puVar10) {
    return uVar12;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0042e6dc:
  uVar12 = (*(code *)PTR___assert_fail_006a993c)("in_stdin == 0","passwd.c",0xbb,"passwd_main");
  return uVar12;
}

