
int do_server(ushort param_1,int param_2,int *param_3,code *param_4,undefined4 param_5)

{
  char *__s;
  int __fd;
  int iVar1;
  int *piVar2;
  int __fd_00;
  hostent *phVar3;
  size_t sVar4;
  char *dst;
  int in_GS_OFFSET;
  socklen_t local_34;
  sockaddr local_30;
  int local_20;
  
  local_30.sa_data._2_4_ = 0;
  local_30.sa_data._6_4_ = 0;
  local_30.sa_data._10_4_ = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_30.sa_family = 2;
  local_30.sa_data._0_2_ = param_1 >> 8 | param_1 << 8;
  if (param_2 == 1) {
    __fd = socket(2,1,6);
  }
  else {
    __fd = socket(2,2,0x11);
  }
  iVar1 = 0;
  if (__fd != -1) {
    local_34 = 1;
    setsockopt(__fd,1,2,&local_34,4);
    iVar1 = bind(__fd,&local_30,0x10);
    if (iVar1 == -1) {
      perror("bind");
    }
    else if ((param_2 != 1) || (iVar1 = listen(__fd,0x80), iVar1 != -1)) {
      if (param_3 != (int *)0x0) {
        *param_3 = __fd;
      }
      dst = (char *)0x0;
      do {
        while (param_2 != 1) {
          iVar1 = (*param_4)(dst,__fd,param_5);
          if (dst != (char *)0x0) {
            CRYPTO_free(dst);
          }
          if (iVar1 < 0) goto LAB_0807ed10;
        }
        while( true ) {
          local_34 = 0x10;
          from_18096._0_4_ = 0;
          from_18096._4_4_ = 0;
          from_18096._8_4_ = 0;
          from_18096._12_4_ = 0;
          __fd_00 = accept(__fd,(sockaddr *)from_18096,&local_34);
          if (__fd_00 != -1) break;
          piVar2 = __errno_location();
          if (*piVar2 != 4) {
            __fprintf_chk(stderr,1,"errno=%d ",*piVar2);
            perror("accept");
            goto LAB_0807eb9a;
          }
        }
        phVar3 = gethostbyaddr(from_18096 + 4,4,2);
        if (phVar3 == (hostent *)0x0) {
          dst = (char *)0x0;
          BIO_printf(bio_err,"bad gethostbyaddr\n");
          iVar1 = (*param_4)(0,__fd_00,param_5);
        }
        else {
          sVar4 = strlen(phVar3->h_name);
          dst = (char *)CRYPTO_malloc(sVar4 + 1,"s_socket.c",0x1c2);
          if (dst == (char *)0x0) {
            perror("OPENSSL_malloc");
            goto LAB_0807eb9a;
          }
          __s = phVar3->h_name;
          sVar4 = strlen(__s);
          BUF_strlcpy(dst,__s,sVar4 + 1);
          iVar1 = GetHostByName();
          if (iVar1 == 0) {
            BIO_printf(bio_err,"gethostbyname failure\n");
            goto LAB_0807eb9a;
          }
          if (*(int *)(iVar1 + 8) != 2) {
            BIO_printf(bio_err,"gethostbyname addr is not AF_INET\n");
            goto LAB_0807eb9a;
          }
          iVar1 = (*param_4)(dst,__fd_00,param_5);
          CRYPTO_free(dst);
        }
        shutdown(__fd_00,2);
        close(__fd_00);
      } while (-1 < iVar1);
LAB_0807ed10:
      shutdown(__fd,2);
      close(__fd);
      goto LAB_0807ebb2;
    }
LAB_0807eb9a:
    shutdown(__fd,0);
    close(__fd);
    iVar1 = 0;
  }
LAB_0807ebb2:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

