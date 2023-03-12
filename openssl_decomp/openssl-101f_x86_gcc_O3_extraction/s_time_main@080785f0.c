
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 s_time_main(int param_1,int param_2)

{
  char *pcVar1;
  bool bVar2;
  SSL *pSVar3;
  uint uVar4;
  uint uVar5;
  time_t tVar6;
  int iVar7;
  long lVar8;
  size_t sVar9;
  int iVar10;
  int iVar11;
  uint *puVar12;
  uint *puVar13;
  char **ppcVar14;
  undefined4 uVar15;
  char *pcVar16;
  int iVar17;
  char *pcVar18;
  int in_GS_OFFSET;
  bool bVar19;
  byte bVar20;
  float10 fVar21;
  float10 fVar22;
  int local_2030;
  uint local_2020 [2048];
  int local_20;
  
  bVar20 = 0;
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
  ppcVar14 = (char **)(param_2 + 4);
  verify_depth = 0;
  verify_error = 0;
  local_2030 = param_1 + -1;
  bVar19 = local_2030 == 0;
  if (local_2030 < 1) {
    if (perform == 0) {
      bVar2 = false;
LAB_08078940:
      perform = 3;
      goto LAB_0807875f;
    }
LAB_0807876d:
    SSL_library_init();
    uVar15 = 1;
    tm_ctx = SSL_CTX_new(s_time_meth);
    if (tm_ctx == (SSL_CTX *)0x0) goto LAB_0807880b;
    SSL_CTX_set_quiet_shutdown(tm_ctx,1);
    if (st_bugs != 0) {
      SSL_CTX_ctrl(tm_ctx,0x20,-0x7ffff401,(void *)0x0);
    }
    SSL_CTX_set_cipher_list(tm_ctx,tm_cipher);
    iVar11 = set_cert_stuff(tm_ctx,t_cert_file,t_key_file);
    if (iVar11 != 0) {
      SSL_load_error_strings();
      iVar11 = SSL_CTX_load_verify_locations(tm_ctx,CAfile,CApath);
      if ((iVar11 == 0) || (iVar11 = SSL_CTX_set_default_verify_paths(tm_ctx), iVar11 == 0)) {
        ERR_print_errors(bio_err);
      }
      if ((tm_cipher == (char *)0x0) && (tm_cipher = getenv("SSL_CIPHER"), tm_cipher == (char *)0x0)
         ) {
        fwrite("No CIPHER specified\n",1,0x14,stderr);
      }
      if ((perform & 1) != 0) {
        __printf_chk(1,"Collecting connection statistics for %d seconds\n",maxTime);
        bytes_read = 0;
        tVar6 = time((time_t *)0x0);
        iVar11 = tVar6 + maxTime;
        iVar17 = 0;
        app_tminterval(0,1);
        while (tVar6 = time((time_t *)0x0), tVar6 <= iVar11) {
          pSVar3 = (SSL *)doConnection();
          if (pSVar3 == (SSL *)0x0) goto LAB_080787e5;
          if (s_www_path != (char *)0x0) {
            BIO_snprintf((char *)local_2020,0x2000,"GET %s HTTP/1.0\r\n\r\n",s_www_path);
            puVar13 = local_2020;
            do {
              puVar12 = puVar13;
              uVar4 = *puVar12 + 0xfefefeff & ~*puVar12;
              uVar5 = uVar4 & 0x80808080;
              puVar13 = puVar12 + 1;
            } while (uVar5 == 0);
            bVar19 = (uVar4 & 0x8080) == 0;
            if (bVar19) {
              uVar5 = uVar5 >> 0x10;
            }
            if (bVar19) {
              puVar13 = (uint *)((int)puVar12 + 6);
            }
            SSL_write(pSVar3,local_2020,
                      (int)((int)puVar13 +
                           ((-3 - (uint)CARRY1((byte)uVar5,(byte)uVar5)) - (int)local_2020)));
            while (iVar7 = SSL_read(pSVar3,local_2020,0x2000), 0 < iVar7) {
              bytes_read = bytes_read + iVar7;
            }
          }
          iVar17 = iVar17 + 1;
          SSL_set_shutdown(pSVar3,3);
          iVar7 = SSL_get_fd(pSVar3);
          shutdown(iVar7,2);
          iVar7 = SSL_get_fd(pSVar3);
          close(iVar7);
          lVar8 = SSL_ctrl(pSVar3,8,0,(void *)0x0);
          iVar7 = 0x72;
          if (lVar8 == 0) {
            iVar10 = SSL_version(pSVar3);
            iVar7 = 0x74;
            if ((iVar10 != 0x301) && (iVar7 = 0x33, iVar10 != 0x300)) {
              iVar7 = (uint)(iVar10 == 2) * 8 + 0x2a;
            }
          }
          fputc(iVar7,stdout);
          fflush(stdout);
          SSL_free(pSVar3);
        }
        fVar21 = (float10)app_tminterval(1,1);
        fVar22 = (float10)_DAT_081f7380;
        time((time_t *)0x0);
        __printf_chk(1,"\n\n%d connections in %.2fs; %.2f connections/user sec, bytes read %ld\n",
                     iVar17,(double)(fVar21 + fVar22),(double)iVar17 / (double)(fVar21 + fVar22),
                     bytes_read);
        time((time_t *)0x0);
        __printf_chk();
      }
      if ((perform & 2) != 0) {
        puts("\n\nNow timing with session id reuse.");
        pSVar3 = (SSL *)doConnection();
        if (pSVar3 != (SSL *)0x0) {
          if (s_www_path != (char *)0x0) {
            BIO_snprintf((char *)local_2020,0x2000,"GET %s HTTP/1.0\r\n\r\n",s_www_path);
            puVar13 = local_2020;
            do {
              puVar12 = puVar13;
              uVar4 = *puVar12 + 0xfefefeff & ~*puVar12;
              uVar5 = uVar4 & 0x80808080;
              puVar13 = puVar12 + 1;
            } while (uVar5 == 0);
            bVar19 = (uVar4 & 0x8080) == 0;
            if (bVar19) {
              uVar5 = uVar5 >> 0x10;
            }
            if (bVar19) {
              puVar13 = (uint *)((int)puVar12 + 6);
            }
            SSL_write(pSVar3,local_2020,
                      (int)((int)puVar13 +
                           ((-3 - (uint)CARRY1((byte)uVar5,(byte)uVar5)) - (int)local_2020)));
            do {
              iVar11 = SSL_read(pSVar3,local_2020,0x2000);
            } while (0 < iVar11);
          }
          SSL_set_shutdown(pSVar3,3);
          iVar11 = SSL_get_fd(pSVar3);
          shutdown(iVar11,2);
          iVar11 = SSL_get_fd(pSVar3);
          close(iVar11);
          tVar6 = time((time_t *)0x0);
          iVar11 = tVar6 + maxTime;
          puts("starting");
          iVar17 = 0;
          bytes_read = 0;
          app_tminterval(0,1);
          while (tVar6 = time((time_t *)0x0), tVar6 <= iVar11) {
            iVar7 = doConnection();
            if (iVar7 == 0) {
              uVar15 = 1;
              goto LAB_08079090;
            }
            if (s_www_path != (char *)0x0) {
              BIO_snprintf((char *)local_2020,0x2000,"GET %s HTTP/1.0\r\n\r\n",s_www_path);
              puVar13 = local_2020;
              do {
                puVar12 = puVar13;
                uVar4 = *puVar12 + 0xfefefeff & ~*puVar12;
                uVar5 = uVar4 & 0x80808080;
                puVar13 = puVar12 + 1;
              } while (uVar5 == 0);
              bVar19 = (uVar4 & 0x8080) == 0;
              if (bVar19) {
                uVar5 = uVar5 >> 0x10;
              }
              if (bVar19) {
                puVar13 = (uint *)((int)puVar12 + 6);
              }
              SSL_write(pSVar3,local_2020,
                        (int)((int)puVar13 +
                             ((-3 - (uint)CARRY1((byte)uVar5,(byte)uVar5)) - (int)local_2020)));
              while (iVar7 = SSL_read(pSVar3,local_2020,0x2000), 0 < iVar7) {
                bytes_read = bytes_read + iVar7;
              }
            }
            iVar17 = iVar17 + 1;
            SSL_set_shutdown(pSVar3,3);
            iVar7 = SSL_get_fd(pSVar3);
            shutdown(iVar7,2);
            iVar7 = SSL_get_fd(pSVar3);
            close(iVar7);
            lVar8 = SSL_ctrl(pSVar3,8,0,(void *)0x0);
            iVar7 = 0x72;
            if (lVar8 == 0) {
              iVar10 = SSL_version(pSVar3);
              iVar7 = 0x74;
              if ((iVar10 != 0x301) && (iVar7 = 0x33, iVar10 != 0x300)) {
                iVar7 = (uint)(iVar10 == 2) * 8 + 0x2a;
              }
            }
            fputc(iVar7,stdout);
            fflush(stdout);
          }
          fVar22 = (float10)app_tminterval(1,1);
          __printf_chk(1,"\n\n%d connections in %.2fs; %.2f connections/user sec, bytes read %ld\n",
                       iVar17,(double)(fVar22 + (float10)_DAT_081f7380),
                       (double)((float10)iVar17 / (fVar22 + (float10)_DAT_081f7380)),bytes_read);
          time((time_t *)0x0);
          uVar15 = 0;
          __printf_chk();
LAB_08079090:
          SSL_free(pSVar3);
          goto LAB_080787ea;
        }
        fwrite("Unable to get connection\n",1,0x19,stderr);
      }
    }
LAB_080787e5:
    uVar15 = 1;
  }
  else {
    bVar2 = false;
    do {
      pcVar1 = *ppcVar14;
      iVar11 = 9;
      pcVar16 = pcVar1;
      pcVar18 = "-connect";
      do {
        if (iVar11 == 0) break;
        iVar11 = iVar11 + -1;
        bVar19 = *pcVar16 == *pcVar18;
        pcVar16 = pcVar16 + (uint)bVar20 * -2 + 1;
        pcVar18 = pcVar18 + (uint)bVar20 * -2 + 1;
      } while (bVar19);
      if (bVar19) {
        local_2030 = local_2030 + -1;
        if (local_2030 == 0) goto LAB_08078950;
        host = ppcVar14[1];
        ppcVar14 = ppcVar14 + 1;
      }
      else {
        iVar11 = 7;
        pcVar16 = pcVar1;
        pcVar18 = "-reuse";
        do {
          if (iVar11 == 0) break;
          iVar11 = iVar11 + -1;
          bVar19 = *pcVar16 == *pcVar18;
          pcVar16 = pcVar16 + (uint)bVar20 * -2 + 1;
          pcVar18 = pcVar18 + (uint)bVar20 * -2 + 1;
        } while (bVar19);
        if (bVar19) {
          perform = 2;
        }
        else {
          iVar11 = 5;
          pcVar16 = pcVar1;
          pcVar18 = "-new";
          do {
            if (iVar11 == 0) break;
            iVar11 = iVar11 + -1;
            bVar19 = *pcVar16 == *pcVar18;
            pcVar16 = pcVar16 + (uint)bVar20 * -2 + 1;
            pcVar18 = pcVar18 + (uint)bVar20 * -2 + 1;
          } while (bVar19);
          if (bVar19) {
            perform = 1;
          }
          else {
            iVar11 = 8;
            pcVar16 = pcVar1;
            pcVar18 = "-verify";
            do {
              if (iVar11 == 0) break;
              iVar11 = iVar11 + -1;
              bVar19 = *pcVar16 == *pcVar18;
              pcVar16 = pcVar16 + (uint)bVar20 * -2 + 1;
              pcVar18 = pcVar18 + (uint)bVar20 * -2 + 1;
            } while (bVar19);
            if (bVar19) {
              local_2030 = local_2030 + -1;
              if (local_2030 == 0) goto LAB_08078950;
              verify_depth = strtol(ppcVar14[1],(char **)0x0,10);
              BIO_printf(bio_err,"verify depth is %d\n",verify_depth);
              ppcVar14 = ppcVar14 + 1;
            }
            else {
              iVar11 = 6;
              pcVar16 = pcVar1;
              pcVar18 = "-cert";
              do {
                if (iVar11 == 0) break;
                iVar11 = iVar11 + -1;
                bVar19 = *pcVar16 == *pcVar18;
                pcVar16 = pcVar16 + (uint)bVar20 * -2 + 1;
                pcVar18 = pcVar18 + (uint)bVar20 * -2 + 1;
              } while (bVar19);
              if (bVar19) {
                local_2030 = local_2030 + -1;
                if (local_2030 == 0) goto LAB_08078950;
                t_cert_file = ppcVar14[1];
                ppcVar14 = ppcVar14 + 1;
              }
              else {
                iVar11 = 5;
                pcVar16 = pcVar1;
                pcVar18 = "-key";
                do {
                  if (iVar11 == 0) break;
                  iVar11 = iVar11 + -1;
                  bVar19 = *pcVar16 == *pcVar18;
                  pcVar16 = pcVar16 + (uint)bVar20 * -2 + 1;
                  pcVar18 = pcVar18 + (uint)bVar20 * -2 + 1;
                } while (bVar19);
                if (bVar19) {
                  local_2030 = local_2030 + -1;
                  if (local_2030 == 0) goto LAB_08078950;
                  t_key_file = ppcVar14[1];
                  ppcVar14 = ppcVar14 + 1;
                }
                else {
                  iVar11 = 8;
                  pcVar16 = pcVar1;
                  pcVar18 = "-CApath";
                  do {
                    if (iVar11 == 0) break;
                    iVar11 = iVar11 + -1;
                    bVar19 = *pcVar16 == *pcVar18;
                    pcVar16 = pcVar16 + (uint)bVar20 * -2 + 1;
                    pcVar18 = pcVar18 + (uint)bVar20 * -2 + 1;
                  } while (bVar19);
                  if (bVar19) {
                    local_2030 = local_2030 + -1;
                    if (local_2030 == 0) goto LAB_08078950;
                    CApath = ppcVar14[1];
                    ppcVar14 = ppcVar14 + 1;
                  }
                  else {
                    iVar11 = 8;
                    pcVar16 = pcVar1;
                    pcVar18 = "-CAfile";
                    do {
                      if (iVar11 == 0) break;
                      iVar11 = iVar11 + -1;
                      bVar19 = *pcVar16 == *pcVar18;
                      pcVar16 = pcVar16 + (uint)bVar20 * -2 + 1;
                      pcVar18 = pcVar18 + (uint)bVar20 * -2 + 1;
                    } while (bVar19);
                    if (bVar19) {
                      local_2030 = local_2030 + -1;
                      if (local_2030 == 0) goto LAB_08078950;
                      CAfile = ppcVar14[1];
                      ppcVar14 = ppcVar14 + 1;
                    }
                    else {
                      iVar11 = 8;
                      pcVar16 = pcVar1;
                      pcVar18 = "-cipher";
                      do {
                        if (iVar11 == 0) break;
                        iVar11 = iVar11 + -1;
                        bVar19 = *pcVar16 == *pcVar18;
                        pcVar16 = pcVar16 + (uint)bVar20 * -2 + 1;
                        pcVar18 = pcVar18 + (uint)bVar20 * -2 + 1;
                      } while (bVar19);
                      if (bVar19) {
                        local_2030 = local_2030 + -1;
                        if (local_2030 == 0) goto LAB_08078950;
                        tm_cipher = ppcVar14[1];
                        ppcVar14 = ppcVar14 + 1;
                      }
                      else {
                        iVar11 = 6;
                        pcVar16 = pcVar1;
                        pcVar18 = "-nbio";
                        do {
                          if (iVar11 == 0) break;
                          iVar11 = iVar11 + -1;
                          bVar19 = *pcVar16 == *pcVar18;
                          pcVar16 = pcVar16 + (uint)bVar20 * -2 + 1;
                          pcVar18 = pcVar18 + (uint)bVar20 * -2 + 1;
                        } while (bVar19);
                        if (!bVar19) {
                          iVar11 = 5;
                          pcVar16 = pcVar1;
                          pcVar18 = "-www";
                          do {
                            if (iVar11 == 0) break;
                            iVar11 = iVar11 + -1;
                            bVar19 = *pcVar16 == *pcVar18;
                            pcVar16 = pcVar16 + (uint)bVar20 * -2 + 1;
                            pcVar18 = pcVar18 + (uint)bVar20 * -2 + 1;
                          } while (bVar19);
                          if (bVar19) {
                            local_2030 = local_2030 + -1;
                            if (local_2030 == 0) goto LAB_08078950;
                            s_www_path = ppcVar14[1];
                            ppcVar14 = ppcVar14 + 1;
                            sVar9 = strlen(s_www_path);
                            if (0x1f9c < sVar9) {
                              BIO_printf(bio_err,"-www option too long\n");
                              bVar2 = true;
                            }
                          }
                          else {
                            iVar11 = 6;
                            pcVar16 = pcVar1;
                            pcVar18 = "-bugs";
                            do {
                              if (iVar11 == 0) break;
                              iVar11 = iVar11 + -1;
                              bVar19 = *pcVar16 == *pcVar18;
                              pcVar16 = pcVar16 + (uint)bVar20 * -2 + 1;
                              pcVar18 = pcVar18 + (uint)bVar20 * -2 + 1;
                            } while (bVar19);
                            if (bVar19) {
                              st_bugs = 1;
                            }
                            else {
                              iVar11 = 6;
                              pcVar16 = pcVar1;
                              pcVar18 = "-ssl2";
                              do {
                                if (iVar11 == 0) break;
                                iVar11 = iVar11 + -1;
                                bVar19 = *pcVar16 == *pcVar18;
                                pcVar16 = pcVar16 + (uint)bVar20 * -2 + 1;
                                pcVar18 = pcVar18 + (uint)bVar20 * -2 + 1;
                              } while (bVar19);
                              if (bVar19) {
                                s_time_meth = SSLv2_client_method();
                              }
                              else {
                                iVar11 = 6;
                                pcVar16 = pcVar1;
                                pcVar18 = "-ssl3";
                                do {
                                  if (iVar11 == 0) break;
                                  iVar11 = iVar11 + -1;
                                  bVar19 = *pcVar16 == *pcVar18;
                                  pcVar16 = pcVar16 + (uint)bVar20 * -2 + 1;
                                  pcVar18 = pcVar18 + (uint)bVar20 * -2 + 1;
                                } while (bVar19);
                                if (bVar19) {
                                  s_time_meth = SSLv3_client_method();
                                }
                                else {
                                  iVar11 = 6;
                                  pcVar16 = pcVar1;
                                  pcVar18 = "-time";
                                  do {
                                    if (iVar11 == 0) break;
                                    iVar11 = iVar11 + -1;
                                    bVar19 = *pcVar16 == *pcVar18;
                                    pcVar16 = pcVar16 + (uint)bVar20 * -2 + 1;
                                    pcVar18 = pcVar18 + (uint)bVar20 * -2 + 1;
                                  } while (bVar19);
                                  if (!bVar19) {
                                    BIO_printf(bio_err,"unknown option %s\n",pcVar1);
                                    if (perform != 0) goto LAB_08078950;
                                    bVar2 = true;
                                    goto LAB_08078940;
                                  }
                                  local_2030 = local_2030 + -1;
                                  if (local_2030 == 0) goto LAB_08078950;
                                  maxTime = strtol(ppcVar14[1],(char **)0x0,10);
                                  ppcVar14 = ppcVar14 + 1;
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
      ppcVar14 = ppcVar14 + 1;
      bVar19 = local_2030 == 0;
    } while (!bVar19);
    if (perform == 0) goto LAB_08078940;
LAB_0807875f:
    if (!bVar2) goto LAB_0807876d;
LAB_08078950:
    uVar15 = 1;
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
LAB_080787ea:
  if (tm_ctx != (SSL_CTX *)0x0) {
    SSL_CTX_free(tm_ctx);
    tm_ctx = (SSL_CTX *)0x0;
  }
LAB_0807880b:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar15;
}

