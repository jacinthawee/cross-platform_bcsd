
/* WARNING: Could not reconcile some variable overlaps */

int BIO_accept(int sock,char **ip_port)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  size_t sVar7;
  size_t sVar8;
  int *piVar9;
  uint uVar10;
  char *pcVar11;
  socklen_t local_460;
  sockaddr local_45c;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  char acStack_440 [32];
  char acStack_420 [1028];
  int local_1c;
  
  local_45c._0_4_ = 0;
  local_1c = __TMC_END__;
  local_45c.sa_data._2_4_ = 0;
  local_460 = 0x1c;
  local_45c.sa_data._6_4_ = 0;
  local_45c.sa_data._10_4_ = 0;
  local_44c = 0;
  local_448 = 0;
  local_444 = 0;
  iVar5 = accept(sock,&local_45c,&local_460);
  if (iVar5 == -1) {
    iVar6 = BIO_sock_should_retry(-1);
    if (iVar6 == 0) {
      piVar9 = __errno_location();
      ERR_put_error(2,8,*piVar9,"b_sock.c",0x36f);
      ERR_put_error(0x20,0x65,100,"b_sock.c",0x370);
    }
    else {
      iVar5 = -2;
    }
  }
  else if (ip_port != (char **)0x0) {
    if ((p_getnameinfo_9333 == (code *)0x0) &&
       (p_getnameinfo_9333 = (code *)DSO_global_lookup("getnameinfo"),
       p_getnameinfo_9333 == (code *)0x0)) {
      p_getnameinfo_9333 = (code *)0xffffffff;
    }
    else if ((p_getnameinfo_9333 != (code *)0xffffffff) &&
            (iVar6 = (*p_getnameinfo_9333)
                               (&local_45c,local_460,acStack_420,0x401,acStack_440,0x20,3),
            iVar6 == 0)) {
      sVar7 = strlen(acStack_420);
      sVar8 = strlen(acStack_440);
      pcVar11 = *ip_port;
      sVar7 = sVar8 + sVar7 + 2;
      if (pcVar11 == (char *)0x0) {
        pcVar11 = (char *)CRYPTO_malloc(sVar7,"b_sock.c",0x390);
      }
      else {
        *pcVar11 = '\0';
        pcVar11 = (char *)CRYPTO_realloc(pcVar11,sVar7,"b_sock.c",0x38f);
      }
      if (pcVar11 == (char *)0x0) {
        ERR_put_error(0x20,0x65,0x41,"b_sock.c",0x393);
      }
      else {
        *ip_port = pcVar11;
        BIO_snprintf(pcVar11,sVar7,"%s:%s",acStack_420,acStack_440);
      }
      goto LAB_000a41b0;
    }
    uVar4 = local_45c.sa_data._2_4_;
    if (local_45c.sa_family == 2) {
      uVar3 = local_45c._0_4_ >> 0x10;
      pcVar11 = *ip_port;
      uVar10 = local_45c._0_4_ >> 0x18;
      uVar1 = local_45c.sa_data._2_4_ >> 8;
      uVar2 = local_45c.sa_data._2_4_ >> 0x10;
      if (pcVar11 == (char *)0x0) {
        pcVar11 = (char *)CRYPTO_malloc(0x18,"b_sock.c",0x3a0);
        if (pcVar11 == (char *)0x0) {
          ERR_put_error(0x20,0x65,0x41,"b_sock.c",0x3a2);
          goto LAB_000a41b0;
        }
        *ip_port = pcVar11;
      }
      BIO_snprintf(pcVar11,0x18,"%d.%d.%d.%d:%d",uVar4 & 0xff,uVar1 & 0xff,uVar2 & 0xff,
                   uVar4 >> 0x18,uVar10 | (uVar3 & 0xff) << 8);
    }
  }
LAB_000a41b0:
  if (local_1c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}

