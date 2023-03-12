
void do_server(int param_1,int param_2,int *param_3,code *param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  undefined *__addr;
  int *piVar2;
  int __fd;
  size_t sVar3;
  hostent *dst;
  int iVar4;
  int iVar5;
  hostent *ptr;
  undefined4 *puVar6;
  char *__s;
  undefined4 *puVar7;
  socklen_t local_40;
  sockaddr local_3c;
  int local_2c;
  
  local_3c.sa_data._2_4_ = 0;
  local_2c = __stack_chk_guard;
  local_3c.sa_data._0_2_ = (ushort)(byte)((uint)param_1 >> 8) | (ushort)(param_1 << 8);
  local_3c.sa_data._6_4_ = 0;
  local_3c.sa_data._10_4_ = 0;
  if (param_2 == 1) {
    iVar5 = 6;
    iVar4 = param_2;
  }
  else {
    iVar4 = 2;
    iVar5 = 0x11;
  }
  local_3c.sa_family = 2;
  iVar4 = socket(2,iVar4,iVar5);
  if (iVar4 == -1) {
    iVar5 = 0;
  }
  else {
    local_40 = 1;
    setsockopt(iVar4,1,2,&local_40,4);
    iVar5 = bind(iVar4,&local_3c,0x10);
    if (iVar5 == -1) {
      perror("bind");
    }
    else if ((param_2 != 1) || (iVar5 = listen(iVar4,0x80), iVar5 != -1)) {
      if (param_3 != (int *)0x0) {
        *param_3 = iVar4;
      }
      ptr = (hostent *)0x0;
      do {
        while( true ) {
          puVar1 = DAT_0003687c;
          __fd = iVar4;
          if (param_2 == 1) {
            puVar7 = DAT_0003687c + 1;
            puVar6 = DAT_0003687c + 2;
            while( true ) {
              __addr = PTR_from_20716_00036880;
              local_40 = 0x10;
              *(undefined4 *)PTR_from_20716_00036880 = 0;
              *puVar1 = 0;
              *puVar7 = 0;
              *puVar6 = 0;
              __fd = accept(iVar4,(sockaddr *)__addr,&local_40);
              if (__fd != -1) break;
              piVar2 = __errno_location();
              if (*piVar2 != 4) {
                __fprintf_chk(stderr,1,"errno=%d ");
                perror("accept");
                goto LAB_000367a8;
              }
            }
            ptr = gethostbyaddr(DAT_0003687c,4,2);
            if (ptr == (hostent *)0x0) {
              BIO_printf(bio_err,"bad gethostbyaddr\n");
            }
            else {
              sVar3 = strlen(ptr->h_name);
              dst = (hostent *)CRYPTO_malloc(sVar3 + 1,"s_socket.c",0x1c5);
              if (dst == (hostent *)0x0) {
                perror("OPENSSL_malloc");
                close(__fd);
                goto LAB_000367a8;
              }
              __s = ptr->h_name;
              sVar3 = strlen(__s);
              BUF_strlcpy((char *)dst,__s,sVar3 + 1);
              iVar5 = GetHostByName(dst);
              if (iVar5 == 0) {
                BIO_printf(bio_err,"gethostbyname failure\n");
                close(__fd);
                goto LAB_000367a8;
              }
              ptr = dst;
              if (*(int *)(iVar5 + 8) != 2) {
                BIO_printf(bio_err,"gethostbyname addr is not AF_INET\n");
                close(__fd);
                goto LAB_000367a8;
              }
            }
          }
          iVar5 = (*param_4)(ptr,__fd,param_5);
          if (ptr != (hostent *)0x0) {
            CRYPTO_free(ptr);
          }
          if (param_2 == 1) break;
          if (iVar5 < 0) goto LAB_000367dc;
        }
        shutdown(__fd,2);
        close(__fd);
      } while (-1 < iVar5);
LAB_000367dc:
      shutdown(iVar4,2);
      close(iVar4);
      goto LAB_000367b8;
    }
LAB_000367a8:
    shutdown(iVar4,0);
    close(iVar4);
    iVar5 = 0;
  }
LAB_000367b8:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar5);
}

