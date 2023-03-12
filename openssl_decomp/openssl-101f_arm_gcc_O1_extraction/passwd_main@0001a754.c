
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void passwd_main(undefined4 param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  BIO_METHOD *pBVar4;
  BIO *bp;
  BIO *pBVar5;
  long lVar6;
  char *pcVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  BIO *__s1;
  BIO *pBVar11;
  void *pvVar12;
  undefined8 *puVar13;
  int iVar14;
  uint uVar15;
  uint local_206c;
  uint local_2068;
  undefined8 *local_2064;
  uint local_205c;
  undefined4 local_2058;
  undefined4 local_2054;
  undefined4 local_2050;
  void *local_2048;
  BIO *local_2044;
  uint local_2040;
  uint local_203c;
  BIO *local_2034;
  void *local_2030;
  char acStack_202c [8192];
  int local_2c;
  
  local_2c = __TMC_END__;
  local_2034 = (BIO *)0x0;
  local_2030 = (void *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar4 = BIO_s_file();
    bio_err = BIO_new(pBVar4);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar3 = load_config(bio_err,0);
  if (iVar3 == 0) {
LAB_0001a96c:
    bp = (BIO *)0x0;
    pBVar11 = (BIO *)0x1;
    __s1 = (BIO *)0x0;
    pBVar5 = (BIO *)0x0;
  }
  else {
    pBVar4 = BIO_s_file();
    bp = BIO_new(pBVar4);
    if (bp == (BIO *)0x0) goto LAB_0001a96c;
    BIO_ctrl(bp,0x6a,0x10,stdout);
    local_206c = 0;
    uVar15 = 0;
    local_2050 = 0;
    local_2054 = 0;
    local_2058 = 0;
    local_205c = 0;
    local_2044 = (BIO *)0x0;
    local_2064 = (undefined8 *)0x0;
    local_203c = 0;
    local_2040 = 0;
    local_2048 = (void *)0x0;
    local_2068 = 0;
    iVar3 = 0;
    do {
      pBVar11 = local_2044;
      iVar14 = iVar3 + 1;
      __s1 = *(BIO **)(param_2 + iVar14 * 4);
      puVar13 = (undefined8 *)(param_2 + iVar14 * 4);
      if (__s1 == (BIO *)0x0) break;
      pBVar5 = (BIO *)strcmp((char *)__s1,"-crypt");
      if (pBVar5 == (BIO *)0x0) {
        uVar15 = 1;
        __s1 = pBVar5;
      }
      else {
        cVar1 = *(char *)&__s1->method;
        if (((cVar1 == '-') && (*(char *)((int)&__s1->method + 1) == '1')) &&
           (pBVar5 = (BIO *)(uint)*(byte *)((int)&__s1->method + 2), pBVar5 == (BIO *)0x0)) {
          local_206c = 1;
          __s1 = pBVar5;
        }
        else {
          pBVar5 = (BIO *)strcmp((char *)__s1,"-apr1");
          if (pBVar5 == (BIO *)0x0) {
            local_2068 = 1;
            __s1 = pBVar5;
          }
          else {
            pBVar5 = (BIO *)strcmp((char *)__s1,"-salt");
            if (pBVar5 == (BIO *)0x0) {
              if (*(BIO **)((int)puVar13 + 4) == (BIO *)0x0) {
LAB_0001aa28:
                pBVar5 = (BIO *)0x0;
              }
              else if (local_2034 == (BIO *)0x0) {
                iVar14 = iVar3 + 2;
                local_205c = 1;
                pBVar5 = local_2034;
                __s1 = local_2034;
                local_2034 = *(BIO **)((int)puVar13 + 4);
                goto LAB_0001a838;
              }
LAB_0001a9c4:
              __s1 = (BIO *)0x1;
            }
            else if (((cVar1 == '-') && (*(char *)((int)&__s1->method + 1) == 'i')) &&
                    ((*(char *)((int)&__s1->method + 2) == 'n' &&
                     (*(char *)((int)&__s1->method + 3) == '\0')))) {
              if ((*(void **)((int)puVar13 + 4) == (void *)0x0) || (local_2044 != (BIO *)0x0))
              goto LAB_0001aa28;
              iVar14 = iVar3 + 2;
              local_2044 = (BIO *)0x1;
              pBVar5 = pBVar11;
              __s1 = pBVar11;
              local_2048 = *(void **)((int)puVar13 + 4);
            }
            else {
              pBVar5 = (BIO *)strcmp((char *)__s1,"-stdin");
              if (pBVar5 == (BIO *)0x0) {
                if (local_2044 != (BIO *)0x0) goto LAB_0001a9c4;
                local_2044 = (BIO *)0x1;
                local_2040 = 1;
                pBVar5 = pBVar11;
                __s1 = pBVar11;
              }
              else {
                pBVar5 = (BIO *)strcmp((char *)__s1,"-noverify");
                if (pBVar5 == (BIO *)0x0) {
                  local_203c = 1;
                  __s1 = pBVar5;
                }
                else {
                  pBVar5 = (BIO *)strcmp((char *)__s1,"-quiet");
                  if (pBVar5 == (BIO *)0x0) {
                    local_2058 = 1;
                    __s1 = pBVar5;
                  }
                  else {
                    pBVar5 = (BIO *)strcmp((char *)__s1,"-table");
                    if (pBVar5 == (BIO *)0x0) {
                      local_2054 = 1;
                      __s1 = pBVar5;
                    }
                    else {
                      pBVar5 = (BIO *)strcmp((char *)__s1,"-reverse");
                      if (pBVar5 == (BIO *)0x0) {
                        local_2050 = 1;
                        __s1 = pBVar5;
                      }
                      else {
                        if ((cVar1 == '-') || (local_2044 != (BIO *)0x0)) goto LAB_0001aa28;
                        pBVar5 = (BIO *)0x1;
                        local_2044 = (BIO *)0x1;
                        __s1 = pBVar11;
                        local_2064 = puVar13;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
LAB_0001a838:
      iVar3 = iVar14;
    } while (((uint)pBVar5 | (uint)__s1) == 0);
    uVar2 = local_2068;
    if ((local_206c | uVar15 | local_2068) == 0) {
      uVar15 = 1;
    }
    if ((1 < local_206c + uVar15 + local_2068) || (__s1 != (BIO *)0x0)) {
      pBVar5 = (BIO *)0x0;
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
      ERR_print_errors(bio_err);
      __s1 = (BIO *)0x0;
      pBVar11 = (BIO *)0x1;
      goto joined_r0x0001a982;
    }
    pvVar12 = local_2048;
    if (local_2048 != (void *)0x0) {
      pvVar12 = (void *)0x1;
    }
    pBVar5 = __s1;
    if ((local_2040 | (uint)pvVar12) == 0) {
LAB_0001aa56:
      if (uVar15 == 0) {
        iVar3 = 0x101;
        if ((local_206c | local_2068) == 0) {
          iVar3 = 1;
          iVar14 = 2;
          local_2068 = 0;
        }
        else {
          iVar14 = 0x102;
          local_2068 = 0x100;
        }
      }
      else {
        iVar3 = 9;
        iVar14 = 10;
        local_2068 = 8;
      }
      if (local_2064 == (undefined8 *)0x0) {
        __s1 = (BIO *)CRYPTO_malloc(iVar14,"passwd.c",0xdc);
        if (__s1 == (BIO *)0x0) goto LAB_0001aae6;
      }
      else {
        iVar14 = 0;
        __s1 = (BIO *)0x0;
      }
      uVar9 = count_leading_zeroes(pBVar5);
      uVar10 = count_leading_zeroes(local_2064);
      if ((uVar9 & uVar10) >> 5 == 0) {
        if (uVar9 >> 5 != 0) {
          if (uVar10 >> 5 != 0) {
                    /* WARNING: Subroutine does not return */
            __assert_fail("passwds != NULL","passwd.c",0xef,PTR___PRETTY_FUNCTION___18640_0001adc4);
          }
          pBVar11 = *(BIO **)local_2064;
          goto LAB_0001aafa;
        }
        if (__s1 == (BIO *)0x0) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("passwd != NULL","passwd.c",0x100,PTR___PRETTY_FUNCTION___18640_0001adc4);
        }
        do {
          iVar14 = BIO_gets(pBVar5,(char *)__s1,iVar3);
          while( true ) {
            if (iVar14 < 1) goto LAB_0001abd6;
            pcVar7 = strchr((char *)__s1,10);
            if (pcVar7 == (char *)0x0) break;
            *pcVar7 = '\0';
            iVar14 = do_passwd(local_205c,&local_2034,&local_2030,__s1,bp,local_2058,local_2054,
                               local_2050,local_2068,uVar15,local_206c,uVar2);
            if (iVar14 == 0) goto LAB_0001aae6;
            iVar14 = BIO_gets(pBVar5,(char *)__s1,iVar3);
          }
          do {
            iVar14 = BIO_gets(pBVar5,acStack_202c,0x2000);
            if (iVar14 < 1) break;
            pcVar7 = strchr(acStack_202c,10);
          } while (pcVar7 == (char *)0x0);
          iVar8 = do_passwd(local_205c,&local_2034,&local_2030,__s1,bp,local_2058,local_2054,
                            local_2050,local_2068,uVar15,local_206c,uVar2);
          if (iVar8 == 0) goto LAB_0001aae6;
        } while (0 < iVar14);
LAB_0001abd6:
        pBVar11 = (BIO *)0x0;
      }
      else {
        iVar3 = EVP_read_pw_string((char *)__s1,iVar14,"Password: ",
                                   (uint)((local_205c | local_203c) == 0));
        if (iVar3 == 0) {
          local_2064 = &passwds_static_18641;
          pBVar11 = __s1;
          passwds_static_18641._0_4_ = __s1;
LAB_0001aafa:
          if (pBVar11 == (BIO *)0x0) {
                    /* WARNING: Subroutine does not return */
            __assert_fail("*passwds != NULL","passwd.c",0xf0,PTR___PRETTY_FUNCTION___18640_0001adc4)
            ;
          }
          do {
            pBVar5 = (BIO *)do_passwd(local_205c,&local_2034,&local_2030,*(undefined4 *)local_2064,
                                      bp,local_2058,local_2054,local_2050,local_2068,uVar15,
                                      local_206c,uVar2);
            if (pBVar5 == (BIO *)0x0) {
              pBVar11 = (BIO *)0x1;
              break;
            }
            pBVar11 = *(BIO **)(undefined8 *)((int)local_2064 + 4);
            pBVar5 = pBVar11;
            local_2064 = (undefined8 *)((int)local_2064 + 4);
          } while (pBVar11 != (BIO *)0x0);
        }
        else {
          pBVar11 = (BIO *)0x1;
          pBVar5 = (BIO *)0x0;
        }
      }
    }
    else {
      pBVar4 = BIO_s_file();
      pBVar5 = BIO_new(pBVar4);
      if (pBVar5 != (BIO *)0x0) {
        if (pvVar12 == (void *)0x0) {
          if (local_2040 == 0) {
                    /* WARNING: Subroutine does not return */
            __assert_fail("in_stdin","passwd.c",0xcc,PTR___PRETTY_FUNCTION___18640_0001adc4);
          }
          BIO_ctrl(pBVar5,0x6a,0,stdin);
        }
        else {
          if (local_2040 != 0) {
                    /* WARNING: Subroutine does not return */
            __assert_fail("in_stdin == 0","passwd.c",0xc6,PTR___PRETTY_FUNCTION___18640_0001adc4);
          }
          lVar6 = BIO_ctrl(pBVar5,0x6c,3,local_2048);
          if (lVar6 < 1) goto LAB_0001aae6;
        }
        goto LAB_0001aa56;
      }
LAB_0001aae6:
      pBVar11 = (BIO *)0x1;
    }
  }
  ERR_print_errors(bio_err);
joined_r0x0001a982:
  if (local_2030 != (void *)0x0) {
    CRYPTO_free(local_2030);
  }
  if (__s1 != (BIO *)0x0) {
    CRYPTO_free(__s1);
  }
  if (pBVar5 != (BIO *)0x0) {
    BIO_free(pBVar5);
  }
  if (bp != (BIO *)0x0) {
    BIO_free_all(bp);
  }
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pBVar11);
}

