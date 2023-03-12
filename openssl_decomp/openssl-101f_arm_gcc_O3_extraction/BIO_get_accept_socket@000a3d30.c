
/* WARNING: Could not reconcile some variable overlaps */

int BIO_get_accept_socket(char *host_port,int mode)

{
  byte *pbVar1;
  byte *ptr;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint __domain;
  byte *pbVar7;
  byte *__s;
  byte *pbVar8;
  byte *str;
  socklen_t __len;
  int local_a0;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  byte local_70;
  byte local_6f;
  byte local_6e;
  byte local_6d;
  sockaddr local_68;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  sockaddr local_48;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 uStack_30;
  int local_2c;
  
  local_2c = __TMC_END__;
  ptr = (byte *)BUF_strdup(host_port);
  if (ptr == (byte *)0x0) {
    iVar3 = -1;
    goto LAB_000a3e08;
  }
  __s = (byte *)(uint)*ptr;
  str = ptr;
  if (__s != (byte *)0x0) {
    pbVar1 = ptr;
    pbVar8 = (byte *)0x0;
    do {
      while (pbVar7 = pbVar1, __s != (byte *)0x3a) {
        if (__s == (byte *)0x2f) {
          *pbVar7 = 0;
          pbVar7 = pbVar8;
          goto joined_r0x000a3e20;
        }
        __s = (byte *)(uint)pbVar7[1];
        pbVar1 = pbVar7 + 1;
        pbVar7 = pbVar8;
        if (__s == (byte *)0x0) goto joined_r0x000a3e20;
      }
      __s = (byte *)(uint)pbVar7[1];
      pbVar1 = pbVar7 + 1;
      pbVar8 = pbVar7;
    } while (__s != (byte *)0x0);
joined_r0x000a3e20:
    __s = pbVar7;
    if (__s != (byte *)0x0) {
      str = __s + 1;
      *__s = 0;
      __s = ptr;
    }
  }
  if ((p_getaddrinfo_9267 == (code *)0x0) &&
     ((p_getaddrinfo_9267 = (code *)DSO_global_lookup("getaddrinfo"),
      p_getaddrinfo_9267 == (code *)0x0 ||
      (p_freeaddrinfo_9272 = (code *)DSO_global_lookup("freeaddrinfo"),
      p_freeaddrinfo_9272 == (code *)0x0)))) {
    p_getaddrinfo_9267 = (code *)0xffffffff;
LAB_000a3dee:
    local_94._0_2_ = local_94._1_2_;
    iVar3 = BIO_get_port((char *)str,(ushort *)&local_94);
    if (iVar3 != 0) {
      __domain = 2;
      local_68.sa_data._2_4_ = 0;
      local_68.sa_data._6_4_ = 0;
      local_68.sa_data._10_4_ = 0;
      local_58 = 0;
      local_54 = 0;
      local_50 = 0;
      local_68._0_4_ = CONCAT22((ushort)local_94 >> 8 | (ushort)local_94 << 8,2);
      if ((__s == (byte *)0x0) || ((*__s == 0x2a && (__s[1] == 0)))) {
        __len = 0x10;
      }
      else {
        iVar3 = BIO_get_host_ip((char *)__s,&local_70);
        if (iVar3 == 0) goto LAB_000a3dfc;
        __len = 0x10;
        __domain = local_68._0_4_ & 0xffff;
        local_68.sa_data._2_4_ =
             (uint)local_6d << 0x18 | (uint)local_6e << 0x10 | (uint)local_6f << 8 | (uint)local_70;
      }
      goto LAB_000a3e4c;
    }
LAB_000a3dfc:
    iVar3 = -1;
  }
  else {
    if (p_getaddrinfo_9267 == (code *)0xffffffff) goto LAB_000a3dee;
    local_8c = 0;
    local_88 = 0;
    local_84 = 0;
    local_80 = 0;
    local_7c = 0;
    local_78 = 0;
    local_74 = 0;
    local_90 = 1;
    if (__s != (byte *)0x0) {
      pcVar2 = strchr((char *)__s,0x3a);
      if (pcVar2 == (char *)0x0) {
        if ((*__s == 0x2a) && ((byte *)(uint)__s[1] == (byte *)0x0)) {
          local_8c = 2;
          __s = (byte *)(uint)__s[1];
        }
      }
      else {
        local_8c = 10;
        if (__s[1] == 0) {
          __s = (byte *)0x0;
        }
      }
    }
    iVar3 = (*p_getaddrinfo_9267)(__s,str,&local_90,&local_94);
    if (iVar3 != 0) goto LAB_000a3dee;
    __len = *(uint *)(local_94 + 0x10);
    if (0x1b < __len) {
      __len = 0x1c;
    }
    __memcpy_chk(&local_68,*(undefined4 *)(local_94 + 0x14),__len);
    (*p_freeaddrinfo_9272)(local_94);
    __domain = local_68._0_4_ & 0xffff;
LAB_000a3e4c:
    local_a0 = 0;
    while (iVar3 = socket(__domain,1,6), iVar3 != -1) {
      if (mode == 2) {
        local_90 = 1;
        local_a0 = setsockopt(iVar3,1,2,&local_90,4);
        mode = 0;
      }
      iVar5 = bind(iVar3,&local_68,__len);
      if (iVar5 != -1) {
        iVar5 = listen(iVar3,0x80);
        if (iVar5 != -1) goto LAB_000a3e00;
        piVar6 = __errno_location();
        ERR_put_error(2,6,*piVar6,"b_sock.c",0x32b);
        ERR_add_error_data(3,"port=\'",host_port,"\'");
        ERR_put_error(0x20,0x69,0x77,"b_sock.c",0x32d);
LAB_000a3f66:
        CRYPTO_free(ptr);
        if (local_a0 == 0) {
          close(iVar3);
          iVar3 = -1;
        }
        goto LAB_000a3e08;
      }
      piVar6 = __errno_location();
      iVar5 = *piVar6;
      if (iVar5 != 0x62 || mode != 1) {
LAB_000a3f20:
        ERR_put_error(2,6,iVar5,"b_sock.c",0x324);
        ERR_add_error_data(3,"port=\'",host_port,"\'");
        ERR_put_error(0x20,0x69,0x75,"b_sock.c",0x326);
        goto LAB_000a3f66;
      }
      local_48._0_4_ = local_68._0_4_;
      local_48.sa_data._2_4_ = local_68.sa_data._2_4_;
      local_48.sa_data._6_4_ = local_68.sa_data._6_4_;
      local_48.sa_data._10_4_ = local_68.sa_data._10_4_;
      local_38 = local_58;
      local_34 = local_54;
      uStack_30 = local_50;
      if ((__s == (byte *)0x0) || ((*__s == 0x2a && (__s[1] == 0)))) {
        if ((local_68._0_4_ & 0xffff) == 10) {
          local_48.sa_data._6_4_ = 0;
          local_48.sa_data._10_4_ = 0;
          local_38 = 0;
          local_34 = 0x1000000;
        }
        else {
          if ((local_68._0_4_ & 0xffff) != 2) goto LAB_000a3f66;
          local_48.sa_data._2_4_ = 0x100007f;
        }
      }
      iVar5 = socket(local_68._0_4_ & 0xffff,1,6);
      if (iVar5 == -1) {
LAB_000a3f1e:
        iVar5 = 0x62;
        goto LAB_000a3f20;
      }
      iVar4 = connect(iVar5,&local_48,__len);
      close(iVar5);
      if (iVar4 != -1) goto LAB_000a3f1e;
      mode = 2;
      close(iVar3);
      __domain = local_68._0_4_ & 0xffff;
    }
    piVar6 = __errno_location();
    ERR_put_error(2,4,*piVar6,"b_sock.c",0x2e5);
    ERR_add_error_data(3,"port=\'",host_port,"\'");
    ERR_put_error(0x20,0x69,0x76,"b_sock.c",0x2e7);
  }
LAB_000a3e00:
  CRYPTO_free(ptr);
LAB_000a3e08:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}

