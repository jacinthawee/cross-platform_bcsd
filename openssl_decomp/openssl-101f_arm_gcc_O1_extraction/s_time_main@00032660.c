
void s_time_main(int param_1,int param_2)

{
  char **ppcVar1;
  bool bVar2;
  int iVar3;
  SSL *pSVar4;
  size_t sVar5;
  time_t tVar6;
  int iVar7;
  long lVar8;
  undefined4 uVar9;
  char *__s1;
  undefined4 uVar10;
  char **ppcVar11;
  int iVar12;
  double dVar13;
  double dVar14;
  char acStack_2034 [8192];
  int local_34;
  
  local_34 = __TMC_END__;
  signal(0xd,(__sighandler_t)0x1);
  maxTime = 0x1e;
  host = s_localhost_4433_00132614;
  t_cert_file = (char *)0x0;
  t_key_file = (char *)0x0;
  CApath = (char *)0x0;
  CAfile = (char *)0x0;
  tm_cipher = (char *)0x0;
  tm_verify = 0;
  tm_ctx = (SSL_CTX *)0x0;
  s_time_meth = (SSL_METHOD *)0x0;
  s_www_path = (char *)0x0;
  bytes_read = 0;
  st_bugs = 0;
  perform = 0;
  t_nbio = 0;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  s_time_meth = SSLv23_client_method();
  ppcVar11 = (char **)(param_2 + 4);
  verify_depth = 0;
  verify_error = 0;
  bVar2 = false;
  for (param_1 = param_1 + -1; 0 < param_1; param_1 = param_1 + -1) {
    __s1 = *ppcVar11;
    iVar3 = strcmp(__s1,"-connect");
    if (iVar3 == 0) {
      param_1 = param_1 + -1;
      if (param_1 == 0) goto LAB_000328b8;
      host = ppcVar11[1];
      ppcVar11 = ppcVar11 + 1;
    }
    else {
      iVar3 = strcmp(__s1,"-reuse");
      if (iVar3 == 0) {
        perform = 2;
      }
      else {
        iVar3 = strcmp(__s1,"-new");
        if (iVar3 == 0) {
          perform = 1;
        }
        else {
          iVar3 = strcmp(__s1,"-verify");
          if (iVar3 == 0) {
            param_1 = param_1 + -1;
            tm_verify = 5;
            if (param_1 == 0) goto LAB_000328b8;
            ppcVar1 = ppcVar11 + 1;
            ppcVar11 = ppcVar11 + 1;
            verify_depth = strtol(*ppcVar1,(char **)0x0,10);
            BIO_printf(bio_err,"verify depth is %d\n",verify_depth);
          }
          else {
            iVar3 = strcmp(__s1,"-cert");
            if (iVar3 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_000328b8;
              t_cert_file = ppcVar11[1];
              ppcVar11 = ppcVar11 + 1;
            }
            else {
              iVar3 = strcmp(__s1,"-key");
              if (iVar3 == 0) {
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_000328b8;
                t_key_file = ppcVar11[1];
                ppcVar11 = ppcVar11 + 1;
              }
              else {
                iVar3 = strcmp(__s1,"-CApath");
                if (iVar3 == 0) {
                  param_1 = param_1 + -1;
                  if (param_1 == 0) goto LAB_000328b8;
                  CApath = ppcVar11[1];
                  ppcVar11 = ppcVar11 + 1;
                }
                else {
                  iVar3 = strcmp(__s1,"-CAfile");
                  if (iVar3 == 0) {
                    param_1 = param_1 + -1;
                    if (param_1 == 0) goto LAB_000328b8;
                    CAfile = ppcVar11[1];
                    ppcVar11 = ppcVar11 + 1;
                  }
                  else {
                    iVar3 = strcmp(__s1,"-cipher");
                    if (iVar3 == 0) {
                      param_1 = param_1 + -1;
                      if (param_1 == 0) goto LAB_000328b8;
                      tm_cipher = ppcVar11[1];
                      ppcVar11 = ppcVar11 + 1;
                    }
                    else {
                      iVar3 = strcmp(__s1,"-nbio");
                      if (iVar3 == 0) {
                        t_nbio = 1;
                      }
                      else {
                        iVar3 = strcmp(__s1,"-www");
                        if (iVar3 == 0) {
                          param_1 = param_1 + -1;
                          if (param_1 == 0) goto LAB_000328b8;
                          s_www_path = ppcVar11[1];
                          ppcVar11 = ppcVar11 + 1;
                          sVar5 = strlen(s_www_path);
                          if (0x1f9c < sVar5) {
                            bVar2 = true;
                            BIO_printf(bio_err,"-www option too long\n");
                          }
                        }
                        else {
                          iVar3 = strcmp(__s1,"-bugs");
                          if (iVar3 == 0) {
                            st_bugs = 1;
                          }
                          else {
                            iVar3 = strcmp(__s1,"-ssl2");
                            if (iVar3 == 0) {
                              s_time_meth = SSLv2_client_method();
                            }
                            else {
                              iVar3 = strcmp(__s1,"-ssl3");
                              if (iVar3 == 0) {
                                s_time_meth = SSLv3_client_method();
                              }
                              else {
                                iVar3 = strcmp(__s1,"-time");
                                if (iVar3 != 0) {
                                  BIO_printf(bio_err,"unknown option %s\n",__s1);
                                  bVar2 = true;
                                  break;
                                }
                                param_1 = param_1 + -1;
                                if (param_1 == 0) goto LAB_000328b8;
                                maxTime = strtol(ppcVar11[1],(char **)0x0,10);
                                ppcVar11 = ppcVar11 + 1;
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
    ppcVar11 = ppcVar11 + 1;
  }
  if (perform == 0) {
    perform = 3;
  }
  if (bVar2) {
LAB_000328b8:
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
    __printf_chk(1,PTR_umsg_20677_00032c34,0x1e);
    goto LAB_000327b8;
  }
  SSL_library_init();
  tm_ctx = SSL_CTX_new(s_time_meth);
  if (tm_ctx == (SSL_CTX *)0x0) {
    uVar10 = 1;
    goto LAB_000327d4;
  }
  SSL_CTX_set_quiet_shutdown(tm_ctx,1);
  if (st_bugs != 0) {
    SSL_CTX_ctrl(tm_ctx,0x20,-0x7ffff401,(void *)0x0);
  }
  SSL_CTX_set_cipher_list(tm_ctx,tm_cipher);
  iVar3 = set_cert_stuff(tm_ctx,t_cert_file,t_key_file);
  if (iVar3 == 0) {
LAB_000327b8:
    uVar10 = 1;
  }
  else {
    SSL_load_error_strings();
    iVar3 = SSL_CTX_load_verify_locations(tm_ctx,CAfile,CApath);
    if ((iVar3 == 0) || (iVar3 = SSL_CTX_set_default_verify_paths(tm_ctx), iVar3 == 0)) {
      ERR_print_errors(bio_err);
    }
    if ((tm_cipher == (char *)0x0) && (tm_cipher = getenv("SSL_CIPHER"), tm_cipher == (char *)0x0))
    {
      fwrite("No CIPHER specified\n",1,0x14,stderr);
    }
    if (perform << 0x1f < 0) {
      __printf_chk(1,"Collecting connection statistics for %d seconds\n",maxTime);
      bytes_read = 0;
      tVar6 = time((time_t *)0x0);
      iVar3 = 0;
      iVar12 = tVar6 + maxTime;
      app_tminterval(0,1);
      while (tVar6 = time((time_t *)0x0), dVar14 = DAT_00032e78, tVar6 <= iVar12) {
        pSVar4 = (SSL *)doConnection(0);
        if (pSVar4 == (SSL *)0x0) goto LAB_000327b8;
        if (s_www_path != (char *)0x0) {
          BIO_snprintf(acStack_2034,0x2000,"GET %s HTTP/1.0\r\n\r\n");
          sVar5 = strlen(acStack_2034);
          SSL_write(pSVar4,acStack_2034,sVar5);
          while (iVar7 = SSL_read(pSVar4,acStack_2034,0x2000), 0 < iVar7) {
            bytes_read = iVar7 + bytes_read;
          }
        }
        SSL_set_shutdown(pSVar4,3);
        iVar7 = SSL_get_fd(pSVar4);
        shutdown(iVar7,2);
        iVar7 = SSL_get_fd(pSVar4);
        iVar3 = iVar3 + 1;
        close(iVar7);
        lVar8 = SSL_ctrl(pSVar4,8,0,(void *)0x0);
        if (lVar8 == 0) {
          iVar7 = SSL_version(pSVar4);
          if (iVar7 == 0x301) {
            iVar7 = 0x74;
          }
          else if (iVar7 == 0x300) {
            iVar7 = 0x33;
          }
          else if (iVar7 == 2) {
            iVar7 = 0x32;
          }
          else {
            iVar7 = 0x2a;
          }
        }
        else {
          iVar7 = 0x72;
        }
        fputc(iVar7,stdout);
        fflush(stdout);
        SSL_free(pSVar4);
      }
      dVar13 = (double)app_tminterval(1,1);
      time((time_t *)0x0);
      __printf_chk(1,"\n\n%d connections in %.2fs; %.2f connections/user sec, bytes read %ld\n",
                   iVar3,bytes_read,dVar13 + dVar14,(double)(longlong)iVar3 / (dVar13 + dVar14),
                   bytes_read);
      tVar6 = time((time_t *)0x0);
      iVar12 = (tVar6 - iVar12) + maxTime;
      uVar10 = __aeabi_idiv(bytes_read,iVar3);
      __printf_chk(1,"%d connections in %ld real seconds, %ld bytes read per connection\n",iVar3,
                   iVar12,uVar10);
    }
    if (-1 < perform << 0x1e) goto LAB_000327b8;
    puts("\n\nNow timing with session id reuse.");
    pSVar4 = (SSL *)doConnection(0);
    if (pSVar4 == (SSL *)0x0) {
      fwrite("Unable to get connection\n",1,0x19,stderr);
      goto LAB_000327b8;
    }
    if (s_www_path != (char *)0x0) {
      BIO_snprintf(acStack_2034,0x2000,"GET %s HTTP/1.0\r\n\r\n");
      sVar5 = strlen(acStack_2034);
      SSL_write(pSVar4,acStack_2034,sVar5);
      do {
        iVar3 = SSL_read(pSVar4,acStack_2034,0x2000);
      } while (0 < iVar3);
    }
    SSL_set_shutdown(pSVar4,3);
    iVar3 = SSL_get_fd(pSVar4);
    shutdown(iVar3,2);
    iVar3 = SSL_get_fd(pSVar4);
    close(iVar3);
    tVar6 = time((time_t *)0x0);
    iVar3 = 0;
    iVar12 = tVar6 + maxTime;
    puts("starting");
    bytes_read = 0;
    app_tminterval(0,1);
    while (tVar6 = time((time_t *)0x0), tVar6 <= iVar12) {
      iVar7 = doConnection(pSVar4);
      if (iVar7 == 0) {
        uVar10 = 1;
        goto LAB_00032d8e;
      }
      if (s_www_path != (char *)0x0) {
        BIO_snprintf(acStack_2034,0x2000,"GET %s HTTP/1.0\r\n\r\n");
        sVar5 = strlen(acStack_2034);
        SSL_write(pSVar4,acStack_2034,sVar5);
        while (iVar7 = SSL_read(pSVar4,acStack_2034,0x2000), 0 < iVar7) {
          bytes_read = iVar7 + bytes_read;
        }
      }
      SSL_set_shutdown(pSVar4,3);
      iVar7 = SSL_get_fd(pSVar4);
      shutdown(iVar7,2);
      iVar7 = SSL_get_fd(pSVar4);
      iVar3 = iVar3 + 1;
      close(iVar7);
      lVar8 = SSL_ctrl(pSVar4,8,0,(void *)0x0);
      if (lVar8 == 0) {
        iVar7 = SSL_version(pSVar4);
        if (iVar7 == 0x301) {
          iVar7 = 0x74;
        }
        else if (iVar7 == 0x300) {
          iVar7 = 0x33;
        }
        else if (iVar7 == 2) {
          iVar7 = 0x32;
        }
        else {
          iVar7 = 0x2a;
        }
      }
      else {
        iVar7 = 0x72;
      }
      fputc(iVar7,stdout);
      fflush(stdout);
    }
    uVar10 = 0;
    dVar14 = (double)app_tminterval(1,1);
    __printf_chk(1,"\n\n%d connections in %.2fs; %.2f connections/user sec, bytes read %ld\n",iVar3,
                 bytes_read,dVar14 + DAT_00032e78,(double)(longlong)iVar3 / (dVar14 + DAT_00032e78),
                 bytes_read);
    tVar6 = time((time_t *)0x0);
    iVar12 = (tVar6 - iVar12) + maxTime;
    uVar9 = __aeabi_idiv(bytes_read,iVar3);
    __printf_chk(1,"%d connections in %ld real seconds, %ld bytes read per connection\n",iVar3,
                 iVar12,uVar9);
LAB_00032d8e:
    SSL_free(pSVar4);
  }
  if (tm_ctx != (SSL_CTX *)0x0) {
    SSL_CTX_free(tm_ctx);
    tm_ctx = (SSL_CTX *)0x0;
  }
LAB_000327d4:
  if (local_34 == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar10);
}

