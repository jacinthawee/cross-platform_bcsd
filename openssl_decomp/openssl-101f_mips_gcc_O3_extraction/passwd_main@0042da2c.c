
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
  
  puVar10 = PTR___stack_chk_guard_006aabf0;
  puVar9 = PTR_bio_err_006a7f3c;
  local_2034 = 0;
  local_2030 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  iVar16 = *(int *)puVar9;
  if (iVar16 == 0) {
    uVar12 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar16 = (*(code *)PTR_BIO_new_006a7fa4)(uVar12);
    *(int *)puVar9 = iVar16;
    if (iVar16 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar16,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
      iVar16 = *(int *)puVar9;
    }
  }
  iVar16 = (*(code *)PTR_load_config_006a7f64)(iVar16,0);
  if (iVar16 == 0) {
LAB_0042dc7c:
    iVar16 = 0;
LAB_0042dc80:
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar9);
joined_r0x0042def0:
    if (local_2030 == 0) {
      uVar12 = 1;
    }
    else {
      iVar18 = 0;
LAB_0042dc9c:
      iVar19 = 0;
      uVar12 = 1;
LAB_0042dca8:
      (*(code *)PTR_CRYPTO_free_006a7f88)();
LAB_0042dcb4:
      if (iVar19 != 0) {
LAB_0042dcc0:
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar19);
      }
LAB_0042dccc:
      if (iVar18 != 0) goto LAB_0042dcd4;
    }
  }
  else {
    uVar12 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar16 = (*(code *)PTR_BIO_new_006a7fa4)(uVar12);
    if (iVar16 == 0) goto LAB_0042dc7c;
    puVar17 = (undefined8 *)(param_2 + 4);
    (*(code *)PTR_BIO_ctrl_006a7f18)(iVar16,0x6a,0x10,*(undefined4 *)PTR_stdout_006aaad4);
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
        while (iVar13 = (*(code *)PTR_strcmp_006aac20)(pcVar20,&DAT_00635658), puVar11 = local_2054,
              iVar13 == 0) {
          puVar17 = (undefined8 *)(param_2 + (iVar19 + 1) * 4);
          bVar21 = true;
          pcVar20 = *(char **)puVar17;
          bVar5 = false;
          iVar18 = iVar19;
          iVar19 = iVar19 + 1;
          if (pcVar20 == (char *)0x0) goto joined_r0x0042dd9c;
        }
        cVar1 = *pcVar20;
        if (((cVar1 == '-') && (pcVar20[1] == '1')) && (pcVar20[2] == '\0')) {
          cVar2 = '\x01';
          bVar5 = false;
        }
        else {
          iVar13 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-apr1");
          if (iVar13 == 0) {
            bVar8 = true;
            cVar3 = '\x01';
            bVar5 = false;
          }
          else {
            iVar13 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-salt");
            if (iVar13 == 0) {
              if ((*(int *)(param_2 + (iVar19 + 1) * 4) == 0) || (local_2034 != 0)) {
LAB_0042dd98:
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
                if ((*(int *)(param_2 + (iVar19 + 1) * 4) == 0) || (bVar4)) goto LAB_0042dd98;
                iVar19 = iVar18 + 2;
                local_2068 = *(int *)(param_2 + iVar19 * 4);
                bVar4 = true;
              }
              else {
                iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-stdin");
                if (iVar18 == 0) {
                  if (bVar4) goto LAB_0042dd98;
                  bVar6 = true;
                  bVar4 = true;
                }
                else {
                  iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-noverify");
                  if (iVar18 == 0) {
                    bVar5 = false;
                    bVar7 = true;
                  }
                  else {
                    iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-quiet");
                    if (iVar18 == 0) {
                      local_2084 = 1;
                      bVar5 = false;
                    }
                    else {
                      iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-table");
                      if (iVar18 == 0) {
                        local_2080 = 1;
                        bVar5 = false;
                      }
                      else {
                        iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-reverse");
                        if (iVar18 != 0) {
                          if ((cVar1 == '-') || (bVar5 = false, puVar11 = puVar17, bVar4))
                          goto LAB_0042dd98;
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
joined_r0x0042dd9c:
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
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar9,"Usage: passwd [options] [passwords]\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar9,"where options are\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar9,
                 "-crypt             standard Unix password algorithm (default)\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar9,"-1                 MD5-based password algorithm\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar9,
                 "-apr1              MD5-based password algorithm, Apache variant\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar9,"-salt string       use provided salt\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar9,"-in file           read passwords from file\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar9,"-stdin             read passwords from stdin\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar9,
                 "-noverify          never verify when reading password from terminal\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar9,"-quiet             no warnings\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar9,"-table             format output as table\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar9,"-reverse           switch table columns\n");
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar9);
      goto joined_r0x0042def0;
    }
    if (local_2068 == 0) {
      if (bVar6) {
        uVar12 = (*(code *)PTR_BIO_s_file_006a7fa0)();
        iVar18 = (*(code *)PTR_BIO_new_006a7fa4)(uVar12);
        if (iVar18 == 0) goto LAB_0042dc80;
        (*(code *)PTR_BIO_ctrl_006a7f18)(iVar18,0x6a,0,*(undefined4 *)PTR_stdin_006aab20);
      }
      else {
        iVar18 = 0;
      }
LAB_0042e010:
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
          uVar12 = (*(code *)PTR___assert_fail_006aaa4c)
                             ("passwd != NULL","passwd.c",0x100,"passwd_main");
          return uVar12;
        }
        iVar19 = 0;
        if (*(int *)local_2054 == 0) {
          uVar12 = (*(code *)PTR___assert_fail_006aaa4c)
                             ("*passwds != NULL","passwd.c",0xf0,"passwd_main");
          return uVar12;
        }
LAB_0042e24c:
        do {
          puVar17 = (undefined8 *)((int)local_2054 + 4);
          iVar18 = do_passwd(local_2074,&local_2034,&local_2030,*(undefined4 *)local_2054,iVar16,
                             local_2084,local_2080,local_207c,uVar12,bVar21,cVar2,cVar3);
          if (iVar18 == 0) {
            uVar12 = 1;
            goto LAB_0042e2cc;
          }
          local_2054 = puVar17;
        } while (*(int *)puVar17 != 0);
        uVar12 = 0;
LAB_0042e2cc:
        iVar18 = 0;
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar9);
        if (local_2030 != 0) goto LAB_0042dca8;
        goto LAB_0042dcb4;
      }
      iVar19 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar22,"passwd.c",0xdc);
      if (iVar19 != 0) {
        if (iVar18 == 0) {
          iVar13 = (*(code *)PTR_EVP_read_pw_string_006a8388)
                             (iVar19,uVar22,"Password: ",local_2074 == 0 && !bVar7);
          if (iVar13 == 0) {
            local_2054 = &passwds_static_16002;
            passwds_static_16002._0_4_ = iVar19;
            goto LAB_0042e24c;
          }
        }
        else {
          do {
            while( true ) {
              iVar13 = (*(code *)PTR_BIO_gets_006a85d0)(iVar18,iVar19,local_2088);
              if (iVar13 < 1) {
                uVar12 = 0;
                goto LAB_0042e3cc;
              }
              puVar14 = (undefined *)(*(code *)PTR_strchr_006aab34)(iVar19,10);
              if (puVar14 != (undefined *)0x0) break;
              do {
                iVar13 = (*(code *)PTR_BIO_gets_006a85d0)(iVar18,auStack_202c,0x2000);
                if (iVar13 < 1) {
                  iVar13 = do_passwd(local_2074,&local_2034,&local_2030,iVar19,iVar16,local_2084,
                                     local_2080,local_207c,uVar12,bVar21,cVar2,cVar3);
                  if (iVar13 == 0) goto LAB_0042e4ec;
                  uVar12 = 0;
                  goto LAB_0042e474;
                }
                iVar13 = (*(code *)PTR_strchr_006aab34)(auStack_202c,10);
              } while (iVar13 == 0);
              iVar13 = do_passwd(local_2074,&local_2034,&local_2030,iVar19,iVar16,local_2084,
                                 local_2080,local_207c,uVar12,bVar21,cVar2,cVar3);
              if (iVar13 == 0) {
LAB_0042e4ec:
                uVar12 = 1;
LAB_0042e474:
                (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar9);
                if (local_2030 == 0) goto LAB_0042dcc0;
                goto LAB_0042dca8;
              }
            }
            *puVar14 = 0;
            iVar13 = do_passwd(local_2074,&local_2034,&local_2030,iVar19,iVar16,local_2084,
                               local_2080,local_207c,uVar12,bVar21,cVar2,cVar3);
          } while (iVar13 != 0);
        }
        uVar12 = 1;
LAB_0042e3cc:
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar9);
        if (local_2030 != 0) goto LAB_0042dca8;
        goto LAB_0042dcc0;
      }
      uVar12 = 1;
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar9);
      if (local_2030 != 0) goto LAB_0042dca8;
      goto LAB_0042dccc;
    }
    uVar12 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar18 = (*(code *)PTR_BIO_new_006a7fa4)(uVar12);
    if (iVar18 == 0) goto LAB_0042dc80;
    if (bVar6) goto LAB_0042e5cc;
    iVar19 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar18,0x6c,3,local_2068);
    if (0 < iVar19) goto LAB_0042e010;
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar9);
    if (local_2030 != 0) goto LAB_0042dc9c;
    uVar12 = 1;
LAB_0042dcd4:
    (*(code *)PTR_BIO_free_006a7f70)(iVar18);
  }
  if (iVar16 != 0) {
    (*(code *)PTR_BIO_free_all_006a7f74)(iVar16);
  }
  if (local_2c == *(int *)puVar10) {
    return uVar12;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0042e5cc:
  uVar12 = (*(code *)PTR___assert_fail_006aaa4c)("in_stdin == 0","passwd.c",0xc6,"passwd_main");
  return uVar12;
}

