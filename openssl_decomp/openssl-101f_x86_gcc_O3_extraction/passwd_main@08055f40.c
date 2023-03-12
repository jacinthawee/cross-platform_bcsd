
/* WARNING: Removing unreachable block (ram,0x080561a6) */
/* WARNING: Removing unreachable block (ram,0x080561a8) */
/* WARNING: Removing unreachable block (ram,0x080561aa) */
/* WARNING: Removing unreachable block (ram,0x080561af) */

undefined4 passwd_main(undefined4 param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  void *pvVar3;
  bool bVar4;
  bool bVar5;
  byte bVar6;
  byte bVar7;
  int iVar8;
  BIO_METHOD *pBVar9;
  byte *pbVar10;
  uint uVar11;
  long lVar12;
  char *pcVar13;
  int iVar14;
  uint uVar15;
  BIO *bp;
  undefined8 *puVar16;
  byte *pbVar17;
  char *buf;
  int iVar18;
  byte *pbVar19;
  undefined4 uVar20;
  int in_GS_OFFSET;
  bool bVar21;
  bool bVar22;
  byte bVar23;
  uint local_2074;
  uint local_2070;
  BIO *local_206c;
  uint local_2060;
  uint local_205c;
  undefined4 local_2054;
  undefined4 local_2050;
  undefined4 local_204c;
  void *local_2040;
  undefined8 *local_203c;
  int local_2028;
  char local_2020 [8192];
  int local_20;
  
  bVar23 = 0;
  local_2028 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar9 = BIO_s_file();
    bio_err = BIO_new(pBVar9);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar8 = load_config(bio_err,0);
  if (iVar8 == 0) {
LAB_08056180:
    local_206c = (BIO *)0x0;
  }
  else {
    pBVar9 = BIO_s_file();
    local_206c = BIO_new(pBVar9);
    if (local_206c == (BIO *)0x0) goto LAB_08056180;
    BIO_ctrl(local_206c,0x6a,0x10,stdout);
    local_205c = 0;
    local_2060 = 0;
    local_2074 = 0;
    local_204c = 0;
    local_2050 = 0;
    local_2054 = 0;
    bVar6 = 0;
    bVar4 = false;
    local_203c = (undefined8 *)0x0;
    bVar7 = 0;
    bVar5 = false;
    local_2040 = (void *)0x0;
    iVar8 = 0;
    do {
      iVar18 = iVar8 + 1;
      iVar1 = iVar18 * 4;
      pbVar10 = *(byte **)(undefined8 *)(param_2 + iVar1);
      bVar21 = false;
      bVar22 = pbVar10 == (byte *)0x0;
      if (bVar22) break;
      iVar14 = 7;
      pbVar17 = pbVar10;
      pbVar19 = (byte *)"-crypt";
      do {
        if (iVar14 == 0) break;
        iVar14 = iVar14 + -1;
        bVar21 = *pbVar17 < *pbVar19;
        bVar22 = *pbVar17 == *pbVar19;
        pbVar17 = pbVar17 + (uint)bVar23 * -2 + 1;
        pbVar19 = pbVar19 + (uint)bVar23 * -2 + 1;
      } while (bVar22);
      if ((!bVar21 && !bVar22) == bVar21) {
        local_2074 = 1;
        uVar15 = 0;
        pbVar10 = (byte *)0x0;
      }
      else {
        bVar2 = *pbVar10;
        bVar21 = bVar2 == 0x2d;
        if (((bVar21) && (bVar21 = pbVar10[1] == 0x31, bVar21)) &&
           (bVar21 = pbVar10[2] == 0, bVar21)) {
          local_2060 = 1;
          pbVar10 = (byte *)0x0;
LAB_080560b6:
          uVar15 = 0;
        }
        else {
          iVar14 = 6;
          pbVar17 = pbVar10;
          pbVar19 = &DAT_081ed0ef;
          do {
            if (iVar14 == 0) break;
            iVar14 = iVar14 + -1;
            bVar21 = *pbVar17 == *pbVar19;
            pbVar17 = pbVar17 + (uint)bVar23 * -2 + 1;
            pbVar19 = pbVar19 + (uint)bVar23 * -2 + 1;
          } while (bVar21);
          if (bVar21) {
            local_205c = 1;
            uVar15 = 0;
            pbVar10 = (byte *)0x0;
          }
          else {
            iVar14 = 6;
            pbVar17 = pbVar10;
            pbVar19 = (byte *)"-salt";
            do {
              if (iVar14 == 0) break;
              iVar14 = iVar14 + -1;
              bVar21 = *pbVar17 == *pbVar19;
              pbVar17 = pbVar17 + (uint)bVar23 * -2 + 1;
              pbVar19 = pbVar19 + (uint)bVar23 * -2 + 1;
            } while (bVar21);
            if (bVar21) {
              uVar15 = 0;
              iVar1 = *(int *)(param_2 + 4 + iVar1);
              pbVar10 = (byte *)0x1;
              if ((iVar1 == 0) || (local_2028 != 0)) goto LAB_080560b6;
              iVar18 = iVar8 + 2;
              bVar6 = 1;
              pbVar10 = (byte *)0x0;
              local_2028 = iVar1;
            }
            else {
              bVar21 = bVar2 == 0x2d;
              if (((bVar21) && (bVar21 = pbVar10[1] == 0x69, bVar21)) &&
                 ((bVar21 = pbVar10[2] == 0x6e, bVar21 && (bVar21 = pbVar10[3] == 0, bVar21)))) {
                pvVar3 = *(void **)(param_2 + 4 + iVar1);
                if ((bVar4) || (pvVar3 == (void *)0x0)) {
LAB_080565a0:
                  uVar15 = 0;
                  pbVar10 = (byte *)0x1;
                }
                else {
                  iVar18 = iVar8 + 2;
                  uVar15 = 0;
                  pbVar10 = (byte *)0x0;
                  bVar4 = true;
                  local_2040 = pvVar3;
                }
              }
              else {
                iVar8 = 7;
                pbVar17 = pbVar10;
                pbVar19 = (byte *)"-stdin";
                do {
                  if (iVar8 == 0) break;
                  iVar8 = iVar8 + -1;
                  bVar21 = *pbVar17 == *pbVar19;
                  pbVar17 = pbVar17 + (uint)bVar23 * -2 + 1;
                  pbVar19 = pbVar19 + (uint)bVar23 * -2 + 1;
                } while (bVar21);
                if (bVar21) {
                  uVar15 = 0;
                  if (bVar4) {
                    pbVar10 = (byte *)0x1;
                  }
                  else {
                    pbVar10 = (byte *)0x0;
                    bVar4 = true;
                    bVar5 = true;
                  }
                }
                else {
                  iVar8 = 10;
                  pbVar17 = pbVar10;
                  pbVar19 = (byte *)"-noverify";
                  do {
                    if (iVar8 == 0) break;
                    iVar8 = iVar8 + -1;
                    bVar21 = *pbVar17 == *pbVar19;
                    pbVar17 = pbVar17 + (uint)bVar23 * -2 + 1;
                    pbVar19 = pbVar19 + (uint)bVar23 * -2 + 1;
                  } while (bVar21);
                  if (bVar21) {
                    uVar15 = 0;
                    pbVar10 = (byte *)0x0;
                    bVar7 = 1;
                  }
                  else {
                    iVar8 = 7;
                    pbVar17 = pbVar10;
                    pbVar19 = (byte *)"-quiet";
                    do {
                      if (iVar8 == 0) break;
                      iVar8 = iVar8 + -1;
                      bVar21 = *pbVar17 == *pbVar19;
                      pbVar17 = pbVar17 + (uint)bVar23 * -2 + 1;
                      pbVar19 = pbVar19 + (uint)bVar23 * -2 + 1;
                    } while (bVar21);
                    if (bVar21) {
                      local_2054 = 1;
                      uVar15 = 0;
                      pbVar10 = (byte *)0x0;
                    }
                    else {
                      iVar8 = 7;
                      pbVar17 = pbVar10;
                      pbVar19 = (byte *)"-table";
                      do {
                        if (iVar8 == 0) break;
                        iVar8 = iVar8 + -1;
                        bVar21 = *pbVar17 == *pbVar19;
                        pbVar17 = pbVar17 + (uint)bVar23 * -2 + 1;
                        pbVar19 = pbVar19 + (uint)bVar23 * -2 + 1;
                      } while (bVar21);
                      if (bVar21) {
                        local_2050 = 1;
                        uVar15 = 0;
                        pbVar10 = (byte *)0x0;
                      }
                      else {
                        iVar8 = 9;
                        pbVar17 = (byte *)"-reverse";
                        do {
                          if (iVar8 == 0) break;
                          iVar8 = iVar8 + -1;
                          bVar21 = *pbVar10 == *pbVar17;
                          pbVar10 = pbVar10 + (uint)bVar23 * -2 + 1;
                          pbVar17 = pbVar17 + (uint)bVar23 * -2 + 1;
                        } while (bVar21);
                        if (bVar21) {
                          local_204c = 1;
                          uVar15 = 0;
                          pbVar10 = (byte *)0x0;
                        }
                        else {
                          if ((bVar4) || (bVar2 == 0x2d)) goto LAB_080565a0;
                          uVar15 = 1;
                          bVar4 = true;
                          pbVar10 = (byte *)0x0;
                          local_203c = (undefined8 *)(param_2 + iVar1);
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
      iVar8 = iVar18;
    } while ((uVar15 | (uint)pbVar10) == 0);
    uVar15 = 1;
    if ((local_2074 | local_2060 | local_205c) != 0) {
      uVar15 = local_2074;
    }
    if ((uVar15 + local_2060 + local_205c < 2) && ((char)pbVar10 == '\0')) {
      if ((local_2040 == (void *)0x0) && (bp = (BIO *)0x0, !bVar5)) goto LAB_08056109;
      pBVar9 = BIO_s_file();
      bp = BIO_new(pBVar9);
      if (bp == (BIO *)0x0) goto LAB_08056188;
      if (local_2040 == (void *)0x0) {
        if (!bVar5) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("in_stdin","passwd.c",0xcc,"passwd_main");
        }
        BIO_ctrl(bp,0x6a,0,stdin);
LAB_08056109:
        if (uVar15 == 0) {
          uVar11 = local_2060 | local_205c;
          iVar8 = (-(uint)(uVar11 == 0) & 0xffffff00) + 0x101;
          local_2070 = -uVar11 & 0x100;
          iVar18 = (-(uint)(uVar11 == 0) & 0xffffff00) + 0x102;
        }
        else {
          iVar8 = 9;
          iVar18 = 10;
          local_2070 = 8;
        }
        if (local_203c == (undefined8 *)0x0) {
          buf = (char *)CRYPTO_malloc(iVar18,"passwd.c",0xdc);
          if (buf != (char *)0x0) {
            if (bp == (BIO *)0x0) {
              iVar8 = EVP_read_pw_string(buf,iVar18,"Password: ",(uint)!(bool)(bVar7 | bVar6));
              if (iVar8 == 0) {
                local_203c = &passwds_static_16029;
                passwds_static_16029._0_4_ = buf;
                goto LAB_08056756;
              }
            }
            else {
              do {
                iVar18 = BIO_gets(bp,buf,iVar8);
                if (iVar18 < 1) {
LAB_08056720:
                  uVar20 = 0;
                  goto LAB_08056608;
                }
                pcVar13 = strchr(buf,10);
                if (pcVar13 == (char *)0x0) {
                  do {
                    iVar18 = BIO_gets(bp,local_2020,0x2000);
                    if (iVar18 < 1) {
                      iVar8 = do_passwd(buf,local_206c,local_2054,local_2050,local_204c,local_2070,
                                        uVar15,local_2060,local_205c);
                      if (iVar8 == 0) goto LAB_08056600;
                      goto LAB_08056720;
                    }
                    pcVar13 = strchr(local_2020,10);
                  } while (pcVar13 == (char *)0x0);
                }
                else {
                  *pcVar13 = '\0';
                }
                iVar18 = do_passwd(buf,local_206c,local_2054,local_2050,local_204c,local_2070,uVar15
                                   ,local_2060,local_205c);
              } while (iVar18 != 0);
            }
LAB_08056600:
            uVar20 = 1;
LAB_08056608:
            ERR_print_errors(bio_err);
            goto LAB_080561bf;
          }
          ERR_print_errors(bio_err);
          uVar20 = 1;
        }
        else {
          if (bp != (BIO *)0x0) {
                    /* WARNING: Subroutine does not return */
            __assert_fail("passwd != NULL","passwd.c",0x100,"passwd_main");
          }
          if (*(int *)local_203c == 0) {
                    /* WARNING: Subroutine does not return */
            __assert_fail("*passwds != NULL","passwd.c",0xf0,"passwd_main");
          }
          buf = (char *)0x0;
LAB_08056756:
          do {
            puVar16 = (undefined8 *)((int)local_203c + 4);
            iVar8 = do_passwd(*(undefined4 *)local_203c,local_206c,local_2054,local_2050,local_204c,
                              local_2070,uVar15,local_2060,local_205c);
            if (iVar8 == 0) {
              uVar20 = 1;
              goto LAB_0805679d;
            }
            local_203c = puVar16;
          } while (*(int *)puVar16 != 0);
          uVar20 = 0;
LAB_0805679d:
          ERR_print_errors(bio_err);
          bp = (BIO *)0x0;
          if (buf != (char *)0x0) {
LAB_080561bf:
            CRYPTO_free(buf);
          }
        }
        if (bp == (BIO *)0x0) goto LAB_080561db;
      }
      else {
        if (bVar5) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("in_stdin == 0","passwd.c",0xc6,"passwd_main");
        }
        lVar12 = BIO_ctrl(bp,0x6c,3,local_2040);
        if (0 < lVar12) goto LAB_08056109;
        ERR_print_errors(bio_err);
        uVar20 = 1;
      }
      BIO_free(bp);
      goto LAB_080561db;
    }
    BIO_printf(bio_err,"Usage: passwd [options] [passwords]\n");
    BIO_printf(bio_err,"where options are\n");
    BIO_printf(bio_err,"-crypt             standard Unix password algorithm (default)\n");
    BIO_printf(bio_err,"-1                 MD5-based password algorithm\n");
    BIO_printf(bio_err,"-apr1              MD5-based password algorithm, Apache variant\n");
    BIO_printf(bio_err,"-salt string       use provided salt\n");
    BIO_printf(bio_err,"-in file           read passwords from file\n");
    BIO_printf(bio_err,"-stdin             read passwords from stdin\n");
    BIO_printf(bio_err,"-noverify          never verify when reading password from terminal\n");
    BIO_printf(bio_err,"-quiet             no warnings\n");
    BIO_printf(bio_err,"-table             format output as table\n");
    BIO_printf(bio_err,"-reverse           switch table columns\n");
  }
LAB_08056188:
  uVar20 = 1;
  ERR_print_errors(bio_err);
LAB_080561db:
  if (local_206c != (BIO *)0x0) {
    BIO_free_all(local_206c);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar20;
}

