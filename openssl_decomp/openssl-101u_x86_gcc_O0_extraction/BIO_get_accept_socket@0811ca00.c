
/* WARNING: Could not reconcile some variable overlaps */

int BIO_get_accept_socket(char *host_port,int mode)

{
  code *pcVar1;
  char cVar2;
  char *ptr;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  char *pcVar9;
  char *__s;
  char *pcVar10;
  socklen_t __len;
  int in_GS_OFFSET;
  bool bVar11;
  sockaddr *local_9c;
  int local_80;
  undefined4 local_7c [8];
  sockaddr local_5c;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  sockaddr local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ptr = BUF_strdup(host_port);
  if (ptr == (char *)0x0) {
LAB_0811ccd8:
    iVar5 = -1;
    goto LAB_0811ccdd;
  }
  cVar2 = *ptr;
  pcVar10 = ptr;
  if (cVar2 == '\0') {
    __s = (char *)0x0;
  }
  else {
    pcVar4 = ptr;
    __s = (char *)0x0;
    do {
      while (pcVar9 = pcVar4, cVar2 == ':') {
        cVar2 = pcVar9[1];
        pcVar4 = pcVar9 + 1;
        __s = pcVar9;
        if (cVar2 == '\0') goto joined_r0x0811cd05;
      }
      if (cVar2 == '/') {
        *pcVar9 = '\0';
        break;
      }
      cVar2 = pcVar9[1];
      pcVar4 = pcVar9 + 1;
    } while (cVar2 != '\0');
joined_r0x0811cd05:
    if (__s != (char *)0x0) {
      pcVar10 = __s + 1;
      *__s = '\0';
      __s = ptr;
    }
  }
  if ((p_getaddrinfo_6653 != (code *)0x0) ||
     ((p_getaddrinfo_6653 = (code *)DSO_global_lookup("getaddrinfo"),
      p_getaddrinfo_6653 != (code *)0x0 &&
      (p_freeaddrinfo_6658 = (code *)DSO_global_lookup("freeaddrinfo"),
      p_freeaddrinfo_6658 != (code *)0x0)))) {
    pcVar1 = p_getaddrinfo_6653;
    if (p_getaddrinfo_6653 == (code *)0xffffffff) goto LAB_0811ccb8;
    uVar3 = 0;
    do {
      *(undefined4 *)((int)local_7c + uVar3) = 0;
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x20);
    local_7c[0] = 1;
    if (__s != (char *)0x0) {
      pcVar4 = strchr(__s,0x3a);
      if (pcVar4 == (char *)0x0) {
        if ((*__s == '*') && (__s[1] == '\0')) {
          local_7c[1] = 2;
          __s = (char *)0x0;
        }
      }
      else {
        local_7c[1] = 10;
        if (__s[1] == '\0') {
          __s = (char *)0x0;
        }
      }
    }
    iVar5 = (*pcVar1)(__s,pcVar10,local_7c,&local_80);
    if (iVar5 != 0) goto LAB_0811ccb8;
    __len = 0x1c;
    if (*(uint *)(local_80 + 0x10) < 0x1d) {
      __len = *(socklen_t *)(local_80 + 0x10);
    }
    __memcpy_chk(&local_5c,*(undefined4 *)(local_80 + 0x14),__len,0x1c);
    (*p_freeaddrinfo_6658)(local_80);
    uVar3 = local_5c._0_4_ & 0xffff;
    goto LAB_0811cbaf;
  }
  p_getaddrinfo_6653 = (code *)0xffffffff;
LAB_0811ccb8:
  iVar5 = BIO_get_port(pcVar10,(ushort *)&local_80);
  if (iVar5 == 0) {
    CRYPTO_free(ptr);
    goto LAB_0811ccd8;
  }
  uVar3 = 0;
  do {
    *(undefined4 *)(local_5c.sa_data + (uVar3 - 2)) = 0;
    uVar3 = uVar3 + 4;
  } while (uVar3 < 0x1c);
  local_5c._0_4_ = CONCAT22((ushort)local_80 >> 8 | (ushort)local_80 << 8,2);
  if ((__s == (char *)0x0) || ((*__s == '*' && (__s[1] == '\0')))) {
    uVar3 = 2;
    __len = 0x10;
LAB_0811cbaf:
    while( true ) {
      local_9c = &local_5c;
      iVar5 = socket(uVar3,1,6);
      if (iVar5 == -1) break;
      if (mode == 2) {
        local_7c[0] = 1;
        iVar7 = setsockopt(iVar5,1,2,local_7c,4);
        iVar6 = bind(iVar5,local_9c,__len);
        if (iVar6 != -1) goto LAB_0811cdd0;
        piVar8 = __errno_location();
        bVar11 = iVar7 == 0;
        iVar7 = *piVar8;
LAB_0811ce35:
        ERR_put_error(2,6,iVar7,"b_sock.c",0x30b);
        ERR_add_error_data(3,"port=\'",host_port,"\'");
        ERR_put_error(0x20,0x69,0x75,"b_sock.c",0x30d);
LAB_0811ce7e:
        CRYPTO_free(ptr);
        if (bVar11) {
LAB_0811cf83:
          close(iVar5);
          iVar5 = -1;
        }
        goto LAB_0811ccdd;
      }
      iVar7 = bind(iVar5,local_9c,__len);
      if (iVar7 != -1) {
        iVar7 = 0;
LAB_0811cdd0:
        iVar6 = listen(iVar5,0x80);
        if (iVar6 == -1) {
          piVar8 = __errno_location();
          ERR_put_error(2,6,*piVar8,"b_sock.c",0x311);
          ERR_add_error_data(3,"port=\'",host_port,"\'");
          ERR_put_error(0x20,0x69,0x77,"b_sock.c",0x313);
          bVar11 = iVar7 == 0;
          goto LAB_0811ce7e;
        }
        goto LAB_0811cdea;
      }
      piVar8 = __errno_location();
      iVar7 = *piVar8;
      bVar11 = mode == 1 && iVar7 == 0x62;
      if (mode != 1 || iVar7 != 0x62) {
        bVar11 = true;
        goto LAB_0811ce35;
      }
      local_40._0_4_ = local_5c._0_4_;
      local_40.sa_data._2_4_ = local_5c.sa_data._2_4_;
      local_40.sa_data._6_4_ = local_5c.sa_data._6_4_;
      local_40.sa_data._10_4_ = local_5c.sa_data._10_4_;
      local_30 = local_4c;
      local_2c = local_48;
      local_28 = local_44;
      local_40.sa_family = (sa_family_t)local_5c._0_4_;
      if ((__s == (char *)0x0) || ((*__s == '*' && (__s[1] == '\0')))) {
        if (local_40.sa_family == 10) {
          local_40.sa_data._6_4_ = 0;
          local_40.sa_data._10_4_ = 0;
          local_30 = 0;
          local_2c = 0x1000000;
          goto LAB_0811cb55;
        }
        if (local_40.sa_family == 2) {
          local_40.sa_data._2_4_ = 0x100007f;
          goto LAB_0811cb55;
        }
        CRYPTO_free(ptr);
        goto LAB_0811cf83;
      }
LAB_0811cb55:
      iVar7 = socket(local_5c._0_4_ & 0xffff,1,6);
      if (iVar7 == -1) {
LAB_0811ce30:
        iVar7 = 0x62;
        goto LAB_0811ce35;
      }
      iVar6 = connect(iVar7,&local_40,__len);
      close(iVar7);
      if (iVar6 != -1) goto LAB_0811ce30;
      mode = 2;
      close(iVar5);
      uVar3 = local_5c._0_4_ & 0xffff;
    }
    piVar8 = __errno_location();
    ERR_put_error(2,4,*piVar8,"b_sock.c",0x2d4);
    ERR_add_error_data(3,"port=\'",host_port,"\'");
    ERR_put_error(0x20,0x69,0x76,"b_sock.c",0x2d6);
  }
  else {
    iVar5 = BIO_get_host_ip(__s,(uchar *)&local_24);
    if (iVar5 != 0) {
      local_5c.sa_data._2_4_ = local_24;
      __len = 0x10;
      uVar3 = local_5c._0_4_ & 0xffff;
      goto LAB_0811cbaf;
    }
    iVar5 = -1;
  }
LAB_0811cdea:
  CRYPTO_free(ptr);
LAB_0811ccdd:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

