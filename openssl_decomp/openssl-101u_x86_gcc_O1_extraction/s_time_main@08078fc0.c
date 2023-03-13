
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 s_time_main(int param_1,int param_2)

{
  char **ppcVar1;
  char *pcVar2;
  bool bVar3;
  SSL *pSVar4;
  uint uVar5;
  uint uVar6;
  time_t tVar7;
  int iVar8;
  long lVar9;
  size_t sVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  char **ppcVar15;
  undefined4 uVar16;
  char *pcVar17;
  int iVar18;
  char *pcVar19;
  int in_GS_OFFSET;
  bool bVar20;
  byte bVar21;
  float10 fVar22;
  float10 fVar23;
  int local_2030;
  uint local_2020 [2048];
  int local_20;
  
  bVar21 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  signal(0xd,(__sighandler_t)0x1);
  host = "localhost:4433";
  t_cert_file = (char *)0x0;
  t_key_file = (char *)0x0;
  CApath = (char *)0x0;
  CAfile = (char *)0x0;
  tm_cipher = (char *)0x0;
  maxTime = 0x1e;
  tm_ctx = (SSL_CTX *)0x0;
  s_time_meth = (SSL_METHOD *)0x0;
  s_www_path = (char *)0x0;
  bytes_read = 0;
  st_bugs = 0;
  perform = 0;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  s_time_meth = SSLv23_client_method();
  ppcVar15 = (char **)(param_2 + 4);
  verify_depth = 0;
  verify_error = 0;
  local_2030 = param_1 + -1;
  bVar20 = local_2030 == 0;
  if (local_2030 < 1) {
    if (perform == 0) {
      bVar3 = false;
LAB_08079310:
      perform = 3;
      goto LAB_0807912f;
    }
LAB_0807913d:
    SSL_library_init();
    uVar16 = 1;
    tm_ctx = SSL_CTX_new(s_time_meth);
    if (tm_ctx == (SSL_CTX *)0x0) goto LAB_080791db;
    SSL_CTX_set_quiet_shutdown(tm_ctx,1);
    if (st_bugs != 0) {
      SSL_CTX_ctrl(tm_ctx,0x20,-0x7ffff401,(void *)0x0);
    }
    SSL_CTX_set_cipher_list(tm_ctx,tm_cipher);
    iVar12 = set_cert_stuff(tm_ctx,t_cert_file,t_key_file);
    if (iVar12 != 0) {
      SSL_load_error_strings();
      iVar12 = SSL_CTX_load_verify_locations(tm_ctx,CAfile,CApath);
      if ((iVar12 == 0) || (iVar12 = SSL_CTX_set_default_verify_paths(tm_ctx), iVar12 == 0)) {
        ERR_print_errors(bio_err);
      }
      if ((tm_cipher == (char *)0x0) && (tm_cipher = getenv("SSL_CIPHER"), tm_cipher == (char *)0x0)
         ) {
        fwrite("No CIPHER specified\n",1,0x14,stderr);
      }
      if ((perform & 1) != 0) {
        __printf_chk(1,"Collecting connection statistics for %d seconds\n",maxTime);
        bytes_read = 0;
        tVar7 = time((time_t *)0x0);
        iVar12 = tVar7 + maxTime;
        iVar18 = 0;
        app_tminterval(0,1);
        while (tVar7 = time((time_t *)0x0), tVar7 <= iVar12) {
          pSVar4 = (SSL *)doConnection();
          if (pSVar4 == (SSL *)0x0) goto LAB_080791b5;
          if (s_www_path != (char *)0x0) {
            BIO_snprintf((char *)local_2020,0x2000,"GET %s HTTP/1.0\r\n\r\n",s_www_path);
            puVar14 = local_2020;
            do {
              puVar13 = puVar14;
              uVar5 = *puVar13 + 0xfefefeff & ~*puVar13;
              uVar6 = uVar5 & 0x80808080;
              puVar14 = puVar13 + 1;
            } while (uVar6 == 0);
            bVar20 = (uVar5 & 0x8080) == 0;
            if (bVar20) {
              uVar6 = uVar6 >> 0x10;
            }
            if (bVar20) {
              puVar14 = (uint *)((int)puVar13 + 6);
            }
            SSL_write(pSVar4,local_2020,
                      (int)((int)puVar14 +
                           ((-3 - (uint)CARRY1((byte)uVar6,(byte)uVar6)) - (int)local_2020)));
            while (iVar8 = SSL_read(pSVar4,local_2020,0x2000), 0 < iVar8) {
              bytes_read = bytes_read + iVar8;
            }
          }
          iVar18 = iVar18 + 1;
          SSL_set_shutdown(pSVar4,3);
          iVar8 = SSL_get_fd(pSVar4);
          shutdown(iVar8,2);
          iVar8 = SSL_get_fd(pSVar4);
          close(iVar8);
          lVar9 = SSL_ctrl(pSVar4,8,0,(void *)0x0);
          iVar8 = 0x72;
          if (lVar9 == 0) {
            iVar11 = SSL_version(pSVar4);
            iVar8 = 0x74;
            if ((iVar11 != 0x301) && (iVar8 = 0x33, iVar11 != 0x300)) {
              iVar8 = (uint)(iVar11 == 2) * 8 + 0x2a;
            }
          }
          fputc(iVar8,stdout);
          fflush(stdout);
          SSL_free(pSVar4);
        }
        fVar22 = (float10)app_tminterval(1,1);
        fVar23 = (float10)_DAT_081f7720;
        time((time_t *)0x0);
        __printf_chk(1,"\n\n%d connections in %.2fs; %.2f connections/user sec, bytes read %ld\n",
                     iVar18,(double)(fVar22 + fVar23),(double)iVar18 / (double)(fVar22 + fVar23),
                     bytes_read);
        time((time_t *)0x0);
        __printf_chk();
      }
      if ((perform & 2) != 0) {
        puts("\n\nNow timing with session id reuse.");
        pSVar4 = (SSL *)doConnection();
        if (pSVar4 != (SSL *)0x0) {
          if (s_www_path != (char *)0x0) {
            BIO_snprintf((char *)local_2020,0x2000,"GET %s HTTP/1.0\r\n\r\n",s_www_path);
            puVar14 = local_2020;
            do {
              puVar13 = puVar14;
              uVar5 = *puVar13 + 0xfefefeff & ~*puVar13;
              uVar6 = uVar5 & 0x80808080;
              puVar14 = puVar13 + 1;
            } while (uVar6 == 0);
            bVar20 = (uVar5 & 0x8080) == 0;
            if (bVar20) {
              uVar6 = uVar6 >> 0x10;
            }
            if (bVar20) {
              puVar14 = (uint *)((int)puVar13 + 6);
            }
            SSL_write(pSVar4,local_2020,
                      (int)((int)puVar14 +
                           ((-3 - (uint)CARRY1((byte)uVar6,(byte)uVar6)) - (int)local_2020)));
            do {
              iVar12 = SSL_read(pSVar4,local_2020,0x2000);
            } while (0 < iVar12);
          }
          SSL_set_shutdown(pSVar4,3);
          iVar12 = SSL_get_fd(pSVar4);
          shutdown(iVar12,2);
          iVar12 = SSL_get_fd(pSVar4);
          close(iVar12);
          tVar7 = time((time_t *)0x0);
          iVar12 = tVar7 + maxTime;
          puts("starting");
          iVar18 = 0;
          bytes_read = 0;
          app_tminterval(0,1);
          while (tVar7 = time((time_t *)0x0), tVar7 <= iVar12) {
            iVar8 = doConnection();
            if (iVar8 == 0) {
              uVar16 = 1;
              goto LAB_08079a6a;
            }
            if (s_www_path != (char *)0x0) {
              BIO_snprintf((char *)local_2020,0x2000,"GET %s HTTP/1.0\r\n\r\n",s_www_path);
              puVar14 = local_2020;
              do {
                puVar13 = puVar14;
                uVar5 = *puVar13 + 0xfefefeff & ~*puVar13;
                uVar6 = uVar5 & 0x80808080;
                puVar14 = puVar13 + 1;
              } while (uVar6 == 0);
              bVar20 = (uVar5 & 0x8080) == 0;
              if (bVar20) {
                uVar6 = uVar6 >> 0x10;
              }
              if (bVar20) {
                puVar14 = (uint *)((int)puVar13 + 6);
              }
              SSL_write(pSVar4,local_2020,
                        (int)((int)puVar14 +
                             ((-3 - (uint)CARRY1((byte)uVar6,(byte)uVar6)) - (int)local_2020)));
              while (iVar8 = SSL_read(pSVar4,local_2020,0x2000), 0 < iVar8) {
                bytes_read = bytes_read + iVar8;
              }
            }
            iVar18 = iVar18 + 1;
            SSL_set_shutdown(pSVar4,3);
            iVar8 = SSL_get_fd(pSVar4);
            shutdown(iVar8,2);
            iVar8 = SSL_get_fd(pSVar4);
            close(iVar8);
            lVar9 = SSL_ctrl(pSVar4,8,0,(void *)0x0);
            iVar8 = 0x72;
            if (lVar9 == 0) {
              iVar11 = SSL_version(pSVar4);
              iVar8 = 0x74;
              if ((iVar11 != 0x301) && (iVar8 = 0x33, iVar11 != 0x300)) {
                iVar8 = (uint)(iVar11 == 2) * 8 + 0x2a;
              }
            }
            fputc(iVar8,stdout);
            fflush(stdout);
          }
          fVar23 = (float10)app_tminterval(1,1);
          __printf_chk(1,"\n\n%d connections in %.2fs; %.2f connections/user sec, bytes read %ld\n",
                       iVar18,(double)(fVar23 + (float10)_DAT_081f7720),
                       (double)((float10)iVar18 / (fVar23 + (float10)_DAT_081f7720)),bytes_read);
          time((time_t *)0x0);
          uVar16 = 0;
          __printf_chk();
LAB_08079a6a:
          SSL_free(pSVar4);
          goto LAB_080791ba;
        }
        fwrite("Unable to get connection\n",1,0x19,stderr);
      }
    }
LAB_080791b5:
    uVar16 = 1;
  }
  else {
    bVar3 = false;
    do {
      pcVar2 = *ppcVar15;
      iVar12 = 9;
      pcVar17 = pcVar2;
      pcVar19 = "-connect";
      do {
        if (iVar12 == 0) break;
        iVar12 = iVar12 + -1;
        bVar20 = *pcVar17 == *pcVar19;
        pcVar17 = pcVar17 + (uint)bVar21 * -2 + 1;
        pcVar19 = pcVar19 + (uint)bVar21 * -2 + 1;
      } while (bVar20);
      if (bVar20) {
        local_2030 = local_2030 + -1;
        if (local_2030 == 0) goto LAB_08079320;
        host = ppcVar15[1];
        ppcVar15 = ppcVar15 + 1;
      }
      else {
        iVar12 = 7;
        pcVar17 = pcVar2;
        pcVar19 = "-reuse";
        do {
          if (iVar12 == 0) break;
          iVar12 = iVar12 + -1;
          bVar20 = *pcVar17 == *pcVar19;
          pcVar17 = pcVar17 + (uint)bVar21 * -2 + 1;
          pcVar19 = pcVar19 + (uint)bVar21 * -2 + 1;
        } while (bVar20);
        if (bVar20) {
          perform = 2;
        }
        else {
          iVar12 = 5;
          pcVar17 = pcVar2;
          pcVar19 = "-new";
          do {
            if (iVar12 == 0) break;
            iVar12 = iVar12 + -1;
            bVar20 = *pcVar17 == *pcVar19;
            pcVar17 = pcVar17 + (uint)bVar21 * -2 + 1;
            pcVar19 = pcVar19 + (uint)bVar21 * -2 + 1;
          } while (bVar20);
          if (bVar20) {
            perform = 1;
          }
          else {
            iVar12 = 8;
            pcVar17 = pcVar2;
            pcVar19 = "-verify";
            do {
              if (iVar12 == 0) break;
              iVar12 = iVar12 + -1;
              bVar20 = *pcVar17 == *pcVar19;
              pcVar17 = pcVar17 + (uint)bVar21 * -2 + 1;
              pcVar19 = pcVar19 + (uint)bVar21 * -2 + 1;
            } while (bVar20);
            if (bVar20) {
              local_2030 = local_2030 + -1;
              if (local_2030 == 0) goto LAB_08079320;
              verify_depth = strtol(ppcVar15[1],(char **)0x0,10);
              BIO_printf(bio_err,"verify depth is %d\n",verify_depth);
              ppcVar15 = ppcVar15 + 1;
            }
            else {
              iVar12 = 6;
              pcVar17 = pcVar2;
              pcVar19 = "-cert";
              do {
                if (iVar12 == 0) break;
                iVar12 = iVar12 + -1;
                bVar20 = *pcVar17 == *pcVar19;
                pcVar17 = pcVar17 + (uint)bVar21 * -2 + 1;
                pcVar19 = pcVar19 + (uint)bVar21 * -2 + 1;
              } while (bVar20);
              if (bVar20) {
                local_2030 = local_2030 + -1;
                if (local_2030 == 0) goto LAB_08079320;
                t_cert_file = ppcVar15[1];
                ppcVar15 = ppcVar15 + 1;
              }
              else {
                iVar12 = 5;
                pcVar17 = pcVar2;
                pcVar19 = "-key";
                do {
                  if (iVar12 == 0) break;
                  iVar12 = iVar12 + -1;
                  bVar20 = *pcVar17 == *pcVar19;
                  pcVar17 = pcVar17 + (uint)bVar21 * -2 + 1;
                  pcVar19 = pcVar19 + (uint)bVar21 * -2 + 1;
                } while (bVar20);
                if (bVar20) {
                  local_2030 = local_2030 + -1;
                  if (local_2030 == 0) goto LAB_08079320;
                  t_key_file = ppcVar15[1];
                  ppcVar15 = ppcVar15 + 1;
                }
                else {
                  iVar12 = 8;
                  pcVar17 = pcVar2;
                  pcVar19 = "-CApath";
                  do {
                    if (iVar12 == 0) break;
                    iVar12 = iVar12 + -1;
                    bVar20 = *pcVar17 == *pcVar19;
                    pcVar17 = pcVar17 + (uint)bVar21 * -2 + 1;
                    pcVar19 = pcVar19 + (uint)bVar21 * -2 + 1;
                  } while (bVar20);
                  if (bVar20) {
                    local_2030 = local_2030 + -1;
                    if (local_2030 == 0) goto LAB_08079320;
                    CApath = ppcVar15[1];
                    ppcVar15 = ppcVar15 + 1;
                  }
                  else {
                    iVar12 = 8;
                    pcVar17 = pcVar2;
                    pcVar19 = "-CAfile";
                    do {
                      if (iVar12 == 0) break;
                      iVar12 = iVar12 + -1;
                      bVar20 = *pcVar17 == *pcVar19;
                      pcVar17 = pcVar17 + (uint)bVar21 * -2 + 1;
                      pcVar19 = pcVar19 + (uint)bVar21 * -2 + 1;
                    } while (bVar20);
                    if (bVar20) {
                      local_2030 = local_2030 + -1;
                      if (local_2030 == 0) goto LAB_08079320;
                      CAfile = ppcVar15[1];
                      ppcVar15 = ppcVar15 + 1;
                    }
                    else {
                      iVar12 = 8;
                      pcVar17 = pcVar2;
                      pcVar19 = "-cipher";
                      do {
                        if (iVar12 == 0) break;
                        iVar12 = iVar12 + -1;
                        bVar20 = *pcVar17 == *pcVar19;
                        pcVar17 = pcVar17 + (uint)bVar21 * -2 + 1;
                        pcVar19 = pcVar19 + (uint)bVar21 * -2 + 1;
                      } while (bVar20);
                      if (bVar20) {
                        local_2030 = local_2030 + -1;
                        if (local_2030 == 0) goto LAB_08079320;
                        tm_cipher = ppcVar15[1];
                        ppcVar15 = ppcVar15 + 1;
                      }
                      else {
                        iVar12 = 6;
                        pcVar17 = pcVar2;
                        pcVar19 = "-nbio";
                        do {
                          if (iVar12 == 0) break;
                          iVar12 = iVar12 + -1;
                          bVar20 = *pcVar17 == *pcVar19;
                          pcVar17 = pcVar17 + (uint)bVar21 * -2 + 1;
                          pcVar19 = pcVar19 + (uint)bVar21 * -2 + 1;
                        } while (bVar20);
                        if (!bVar20) {
                          iVar12 = 5;
                          pcVar17 = pcVar2;
                          pcVar19 = "-www";
                          do {
                            if (iVar12 == 0) break;
                            iVar12 = iVar12 + -1;
                            bVar20 = *pcVar17 == *pcVar19;
                            pcVar17 = pcVar17 + (uint)bVar21 * -2 + 1;
                            pcVar19 = pcVar19 + (uint)bVar21 * -2 + 1;
                          } while (bVar20);
                          if (bVar20) {
                            local_2030 = local_2030 + -1;
                            if (local_2030 == 0) goto LAB_08079320;
                            s_www_path = ppcVar15[1];
                            ppcVar15 = ppcVar15 + 1;
                            sVar10 = strlen(s_www_path);
                            if (0x1f9c < sVar10) {
                              BIO_printf(bio_err,"-www option too long\n");
                              bVar3 = true;
                            }
                          }
                          else {
                            iVar12 = 6;
                            pcVar17 = pcVar2;
                            pcVar19 = "-bugs";
                            do {
                              if (iVar12 == 0) break;
                              iVar12 = iVar12 + -1;
                              bVar20 = *pcVar17 == *pcVar19;
                              pcVar17 = pcVar17 + (uint)bVar21 * -2 + 1;
                              pcVar19 = pcVar19 + (uint)bVar21 * -2 + 1;
                            } while (bVar20);
                            if (bVar20) {
                              st_bugs = 1;
                            }
                            else {
                              iVar12 = 6;
                              pcVar17 = pcVar2;
                              pcVar19 = "-ssl3";
                              do {
                                if (iVar12 == 0) break;
                                iVar12 = iVar12 + -1;
                                bVar20 = *pcVar17 == *pcVar19;
                                pcVar17 = pcVar17 + (uint)bVar21 * -2 + 1;
                                pcVar19 = pcVar19 + (uint)bVar21 * -2 + 1;
                              } while (bVar20);
                              if (bVar20) {
                                s_time_meth = SSLv3_client_method();
                              }
                              else {
                                iVar12 = 6;
                                pcVar17 = pcVar2;
                                pcVar19 = "-time";
                                do {
                                  if (iVar12 == 0) break;
                                  iVar12 = iVar12 + -1;
                                  bVar20 = *pcVar17 == *pcVar19;
                                  pcVar17 = pcVar17 + (uint)bVar21 * -2 + 1;
                                  pcVar19 = pcVar19 + (uint)bVar21 * -2 + 1;
                                } while (bVar20);
                                if (!bVar20) {
                                  BIO_printf(bio_err,"unknown option %s\n",pcVar2);
                                  if (perform != 0) goto LAB_08079320;
                                  bVar3 = true;
                                  goto LAB_08079310;
                                }
                                local_2030 = local_2030 + -1;
                                if (local_2030 == 0) goto LAB_08079320;
                                ppcVar1 = ppcVar15 + 1;
                                maxTime = strtol(ppcVar15[1],(char **)0x0,10);
                                ppcVar15 = ppcVar1;
                                if (maxTime < 1) {
                                  BIO_printf(bio_err,"time must be > 0\n");
                                  bVar3 = true;
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
      local_2030 = local_2030 + -1;
      ppcVar15 = ppcVar15 + 1;
      bVar20 = local_2030 == 0;
    } while (!bVar20);
    if (perform == 0) goto LAB_08079310;
LAB_0807912f:
    if (!bVar3) goto LAB_0807913d;
LAB_08079320:
    uVar16 = 1;
    puts("usage: s_time <args>\n");
    __printf_chk(1,"-connect host:port - host:port to connect to (default is %s)\n","localhost:4433"
                );
    puts("-nbio         - Run with non-blocking IO");
    puts("-ssl2         - Just use SSLv2");
    puts("-ssl3         - Just use SSLv3");
    puts("-bugs         - Turn on SSL bug compatibility");
    puts("-new          - Just time new connections");
    puts("-reuse        - Just time connection reuse");
    puts("-www page     - Retrieve \'page\' from the site");
    __printf_chk(1,
                 "-time arg     - max number of seconds to collect data, default %d\n-verify arg   - turn on peer certificate verification, arg == depth\n-cert arg     - certificate file to use, PEM format assumed\n-key arg      - RSA file to use, PEM format assumed, key is in cert file\n                file if not specified by this option\n-CApath arg   - PEM format directory of CA\'s\n-CAfile arg   - PEM format file of CA\'s\n-cipher       - preferred cipher to use, play with \'openssl ciphers\'\n\n"
                 ,0x1e);
  }
LAB_080791ba:
  if (tm_ctx != (SSL_CTX *)0x0) {
    SSL_CTX_free(tm_ctx);
    tm_ctx = (SSL_CTX *)0x0;
  }
LAB_080791db:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar16;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

