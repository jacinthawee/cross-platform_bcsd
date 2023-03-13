
int BIO_accept(int sock,char **ip_port)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  size_t sVar5;
  char *pcVar6;
  int *piVar7;
  int in_GS_OFFSET;
  socklen_t local_464;
  sockaddr local_460;
  char local_441 [32];
  char local_421 [1025];
  int local_20;
  
  local_464 = 0x1c;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar1 = 0;
  do {
    *(undefined4 *)(local_460.sa_data + (uVar1 - 2)) = 0;
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x1c);
  iVar2 = accept(sock,&local_460,&local_464);
  if (iVar2 == -1) {
    iVar2 = BIO_sock_should_retry(-1);
    if (iVar2 == 0) {
      piVar7 = __errno_location();
      ERR_put_error(2,8,*piVar7,"b_sock.c",0x357);
      ERR_put_error(0x20,0x65,100,"b_sock.c",0x358);
      iVar2 = -1;
    }
    else {
      iVar2 = -2;
    }
  }
  else if (ip_port != (char **)0x0) {
    if ((p_getnameinfo_6720 == (code *)0x0) &&
       (p_getnameinfo_6720 = (code *)DSO_global_lookup("getnameinfo"),
       p_getnameinfo_6720 == (code *)0x0)) {
      p_getnameinfo_6720 = (code *)0xffffffff;
    }
    else if (p_getnameinfo_6720 != (code *)0xffffffff) {
      iVar3 = (*p_getnameinfo_6720)(&local_460,local_464,local_421,0x401,local_441,0x20,3);
      if (iVar3 == 0) {
        sVar4 = strlen(local_421);
        sVar5 = strlen(local_441);
        sVar5 = sVar4 + 2 + sVar5;
        pcVar6 = *ip_port;
        if (pcVar6 == (char *)0x0) {
          pcVar6 = (char *)CRYPTO_malloc(sVar5,"b_sock.c",0x381);
        }
        else {
          *pcVar6 = '\0';
          pcVar6 = (char *)CRYPTO_realloc(pcVar6,sVar5,"b_sock.c",0x37f);
        }
        if (pcVar6 == (char *)0x0) {
          ERR_put_error(0x20,0x65,0x41,"b_sock.c",900);
        }
        else {
          *ip_port = pcVar6;
          BIO_snprintf(pcVar6,sVar5,"%s:%s",local_421,local_441);
        }
        goto LAB_0811d132;
      }
    }
    if (local_460.sa_family == 2) {
      pcVar6 = *ip_port;
      if (pcVar6 == (char *)0x0) {
        pcVar6 = (char *)CRYPTO_malloc(0x18,"b_sock.c",0x391);
        if (pcVar6 == (char *)0x0) {
          ERR_put_error(0x20,0x65,0x41,"b_sock.c",0x392);
          goto LAB_0811d132;
        }
        *ip_port = pcVar6;
      }
      BIO_snprintf(pcVar6,0x18,"%d.%d.%d.%d:%d",local_460.sa_data._2_4_ & 0xff,
                   ((local_460.sa_data._2_4_ & 0xff00) << 8) >> 0x10,
                   (local_460.sa_data._2_4_ & 0xff0000) >> 0x10,local_460.sa_data._2_4_ >> 0x18,
                   (uint)(ushort)(local_460.sa_data._0_2_ >> 8 | local_460.sa_data._0_2_ << 8));
    }
  }
LAB_0811d132:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

