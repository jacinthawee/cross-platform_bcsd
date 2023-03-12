
/* WARNING: Could not reconcile some variable overlaps */

int BIO_get_accept_socket(char *host_port,int mode)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  char cVar10;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  char *pcVar11;
  char **ip;
  char *unaff_s0;
  char *pcVar12;
  size_t n;
  undefined4 *unaff_s1;
  code *unaff_s2;
  char *unaff_s4;
  uint uVar13;
  char **unaff_s5;
  char *unaff_s6;
  uint uStack_524;
  uint uStack_520;
  undefined4 uStack_51c;
  undefined4 uStack_518;
  undefined4 uStack_514;
  undefined4 uStack_510;
  undefined4 uStack_50c;
  undefined auStack_508 [32];
  undefined auStack_4e8 [1028];
  int iStack_e4;
  char *pcStack_e0;
  undefined4 *puStack_dc;
  code *pcStack_d8;
  int iStack_d4;
  char *pcStack_d0;
  char **ppcStack_cc;
  char *pcStack_c8;
  code *pcStack_c4;
  char *local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  char *local_68;
  char *local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  char *local_4c;
  char *local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  char *local_30;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ip = (char **)mode;
  pcStack_c8 = BUF_strdup(host_port);
  if (pcStack_c8 != (char *)0x0) {
    cVar10 = *pcStack_c8;
    unaff_s4 = pcStack_c8;
    if (cVar10 == '\0') {
      unaff_s0 = (char *)0x0;
    }
    else {
      pcVar11 = pcStack_c8;
      unaff_s0 = (char *)0x0;
      do {
        pcVar12 = pcVar11;
        if ((cVar10 != ':') && (pcVar12 = unaff_s0, cVar10 == '/')) {
          *pcVar11 = '\0';
          if (unaff_s0 == (char *)0x0) goto LAB_005277f8;
          goto LAB_005277ec;
        }
        pcVar11 = pcVar11 + 1;
        cVar10 = *pcVar11;
        unaff_s0 = pcVar12;
      } while (cVar10 != '\0');
      if (pcVar12 != (char *)0x0) {
LAB_005277ec:
        unaff_s4 = unaff_s0 + 1;
        *unaff_s0 = '\0';
        unaff_s0 = pcStack_c8;
      }
    }
LAB_005277f8:
    unaff_s2 = p_getaddrinfo_6623;
    unaff_s1 = (undefined4 *)&_gp_1;
    if ((p_getaddrinfo_6623 == (code *)0x0) &&
       ((p_getaddrinfo_6623 = (code *)(*(code *)PTR_DSO_global_lookup_006a88fc)("getaddrinfo"),
        p_getaddrinfo_6623 == (code *)0x0 ||
        (p_freeaddrinfo_6628 = (code *)(*(code *)PTR_DSO_global_lookup_006a88fc)("freeaddrinfo"),
        p_freeaddrinfo_6628 == (code *)0x0)))) {
      p_getaddrinfo_6623 = (code *)0xffffffff;
LAB_00527888:
      unaff_s5 = &local_8c;
      ip = unaff_s5;
      iVar4 = BIO_get_port(unaff_s4,(ushort *)unaff_s5);
      if (iVar4 != 0) {
        local_64 = (char *)0x0;
        local_60 = 0;
        local_5c = 0;
        local_58 = 0;
        local_54 = 0;
        local_50 = 0;
        local_68 = (char *)CONCAT22(2,local_8c._0_2_);
        if ((unaff_s0 == (char *)0x0) ||
           ((ip = &local_30, *unaff_s0 == '*' && (unaff_s0[1] == '\0')))) {
          local_68._0_2_ = 2;
          unaff_s4 = &SUB_00000010;
        }
        else {
          iVar4 = BIO_get_host_ip(unaff_s0,(uchar *)ip);
          if (iVar4 == 0) goto LAB_0052789c;
          local_64 = local_30;
          unaff_s4 = &SUB_00000010;
        }
        goto LAB_00527954;
      }
    }
    else {
      unaff_s2 = p_getaddrinfo_6623;
      if (p_getaddrinfo_6623 == (code *)0xffffffff) goto LAB_00527888;
      local_84 = 0;
      unaff_s1 = &local_88;
      local_80 = 0;
      local_7c = 0;
      local_78 = 0;
      local_74 = 0;
      local_70 = 0;
      local_6c = 0;
      local_88 = 1;
      if (unaff_s0 != (char *)0x0) {
        iVar4 = (*(code *)PTR_strchr_006a9a28)(unaff_s0,0x3a);
        if (iVar4 == 0) {
          if ((*unaff_s0 == '*') && (unaff_s0[1] == '\0')) {
            unaff_s0 = (char *)0x0;
            local_84 = 2;
          }
        }
        else {
          if (unaff_s0[1] == '\0') {
            unaff_s0 = (char *)0x0;
          }
          local_84 = 10;
        }
      }
      iVar4 = (*unaff_s2)(unaff_s0,unaff_s4,unaff_s1,&local_8c);
      if (iVar4 != 0) goto LAB_00527888;
      unaff_s4 = (char *)0x1c;
      if (*(char **)(local_8c + 0x10) < (char *)0x1d) {
        unaff_s4 = *(char **)(local_8c + 0x10);
      }
      (*(code *)PTR___memcpy_chk_006a9a48)(&local_68,*(undefined4 *)(local_8c + 0x14),unaff_s4,0x1c)
      ;
      (*p_freeaddrinfo_6628)(local_8c);
LAB_00527954:
      unaff_s2 = (code *)0xffffffff;
      unaff_s1 = (undefined4 *)(*(code *)PTR_socket_006a9984)(local_68._0_2_,2,6);
      while (unaff_s1 != (undefined4 *)0xffffffff) {
        unaff_s5 = (char **)0xffffffff;
        puVar5 = unaff_s1;
        if (mode == 2) {
          local_88 = 1;
          unaff_s0 = (char *)(*(code *)PTR_setsockopt_006a9b2c)(unaff_s1,0xffff,4,&local_88);
          iVar4 = (*(code *)PTR_bind_006a9a10)(unaff_s1,&local_68,unaff_s4);
          if (iVar4 != -1) goto LAB_00527b98;
          puVar6 = (undefined4 *)(*(code *)PTR___errno_location_006a99e8)();
          unaff_s5 = (char **)*puVar6;
LAB_00527c68:
          ERR_put_error(2,6,(int)unaff_s5,"b_sock.c",0x30b);
          ERR_add_error_data(3,"port=\'",host_port,"\'");
          ip = (char **)&DAT_00000069;
          ERR_put_error(0x20,0x69,0x75,"b_sock.c",0x30d);
LAB_00527cd8:
          unaff_s2 = (code *)(CAST_S_table3 + 0x110);
          (*(code *)PTR_CRYPTO_free_006a6e88)(pcStack_c8);
          if (unaff_s0 == (char *)0x0) {
LAB_00527e20:
            (*(code *)PTR_close_006a994c)(unaff_s1);
            puVar5 = (undefined4 *)0xffffffff;
          }
          goto LAB_005278b0;
        }
        ip = &local_68;
        iVar4 = (*(code *)PTR_bind_006a9a10)(unaff_s1,&local_68,unaff_s4);
        if (iVar4 != -1) {
          unaff_s0 = (char *)0x0;
LAB_00527b98:
          ip = (char **)&DAT_00000080;
          iVar4 = (*(code *)PTR_listen_006a99b0)(unaff_s1);
          if (iVar4 == -1) {
            piVar9 = (int *)(*(code *)PTR___errno_location_006a99e8)();
            ERR_put_error(2,6,*piVar9,"b_sock.c",0x311);
            ERR_add_error_data(3,"port=\'",host_port,"\'");
            ip = (char **)&DAT_00000069;
            ERR_put_error(0x20,0x69,0x77,"b_sock.c",0x313);
            goto LAB_00527cd8;
          }
          (*(code *)PTR_CRYPTO_free_006a6e88)(pcStack_c8);
          goto LAB_005278b0;
        }
        puVar6 = (undefined4 *)(*(code *)PTR___errno_location_006a99e8)();
        unaff_s5 = (char **)*puVar6;
        if ((mode != 1) || (unaff_s5 != (char **)0x7d)) goto LAB_00527c64;
        local_4c = local_68;
        local_48 = local_64;
        local_44 = local_60;
        local_40 = local_5c;
        local_3c = local_58;
        local_38 = local_54;
        local_34 = local_50;
        local_4c._0_2_ = (short)((uint)local_68 >> 0x10);
        if ((unaff_s0 == (char *)0x0) || ((*unaff_s0 == '*' && (unaff_s0[1] == '\0')))) {
          if (local_4c._0_2_ == 10) {
            local_44 = 0;
            local_40 = 0;
            local_3c = 0;
            local_38 = 1;
            goto LAB_00527a4c;
          }
          if (local_4c._0_2_ == 2) {
            local_48 = (char *)0x7f000001;
            goto LAB_00527a4c;
          }
          (*(code *)PTR_CRYPTO_free_006a6e88)(pcStack_c8);
          goto LAB_00527e20;
        }
LAB_00527a4c:
        iVar4 = (*(code *)PTR_socket_006a9984)(local_4c._0_2_,2,6);
        mode = iVar4;
        if (iVar4 == -1) {
LAB_00527c64:
          unaff_s0 = (char *)0x0;
          goto LAB_00527c68;
        }
        mode = (*(code *)PTR_connect_006a9950)(iVar4,&local_4c,unaff_s4);
        (*(code *)PTR_close_006a994c)(iVar4);
        if (mode != -1) goto LAB_00527c64;
        mode = 2;
        (*(code *)PTR_close_006a994c)(unaff_s1);
        unaff_s1 = (undefined4 *)(*(code *)PTR_socket_006a9984)(local_68._0_2_,2,6);
      }
      unaff_s5 = (char **)0xffffffff;
      unaff_s0 = CAST_S_table3 + 0x110;
      piVar9 = (int *)(*(code *)PTR___errno_location_006a99e8)();
      ERR_put_error(2,4,*piVar9,"b_sock.c",0x2d4);
      ERR_add_error_data(3,"port=\'",host_port,"\'");
      ip = (char **)&DAT_00000069;
      ERR_put_error(0x20,0x69,0x76,"b_sock.c",0x2d6);
    }
LAB_0052789c:
    (*(code *)PTR_CRYPTO_free_006a6e88)(pcStack_c8);
    unaff_s6 = pcStack_c8;
  }
  puVar5 = (undefined4 *)0xffffffff;
  pcStack_c8 = unaff_s6;
LAB_005278b0:
  if (local_2c == *(int *)puVar2) {
    return (int)puVar5;
  }
  pcStack_c4 = BIO_accept;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  uStack_524 = 0;
  uStack_520 = 0;
  uStack_51c = 0;
  uStack_518 = 0;
  uStack_514 = 0;
  uStack_510 = 0;
  uStack_50c = 0;
  iStack_e4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcStack_e0 = unaff_s0;
  puStack_dc = unaff_s1;
  pcStack_d8 = unaff_s2;
  iStack_d4 = mode;
  pcStack_d0 = unaff_s4;
  ppcStack_cc = unaff_s5;
  iVar4 = (*(code *)PTR_accept_006a9a78)();
  if (iVar4 == -1) {
    iVar4 = BIO_sock_should_retry(-1);
    if (iVar4 == 0) {
      piVar9 = (int *)(*(code *)PTR___errno_location_006a99e8)();
      ERR_put_error(2,8,*piVar9,"b_sock.c",0x357);
      ERR_put_error(0x20,0x65,100,"b_sock.c",0x358);
      iVar4 = -1;
    }
    else {
      iVar4 = -2;
    }
  }
  else if (ip != (char **)0x0) {
    if ((p_getnameinfo_6687 == (code *)0x0) &&
       (p_getnameinfo_6687 = (code *)(*(code *)PTR_DSO_global_lookup_006a88fc)("getnameinfo"),
       p_getnameinfo_6687 == (code *)0x0)) {
      p_getnameinfo_6687 = (code *)0xffffffff;
    }
    else if (p_getnameinfo_6687 != (code *)0xffffffff) {
      iVar7 = (*p_getnameinfo_6687)(&uStack_524,0x1c,auStack_4e8,0x401,auStack_508,0x20,3);
      if (iVar7 == 0) {
        iVar7 = (*(code *)PTR_strlen_006a9a24)(auStack_4e8);
        iVar8 = (*(code *)PTR_strlen_006a9a24)(auStack_508);
        puVar1 = PTR_CRYPTO_realloc_006a7b58;
        pcVar11 = *ip;
        n = iVar7 + iVar8 + 2;
        if (pcVar11 == (char *)0x0) {
          pcVar11 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(n,"b_sock.c",0x381);
        }
        else {
          *pcVar11 = '\0';
          pcVar11 = (char *)(*(code *)puVar1)(pcVar11,n,"b_sock.c",0x37f);
        }
        if (pcVar11 == (char *)0x0) {
          ERR_put_error(0x20,0x65,0x41,"b_sock.c",900);
        }
        else {
          *ip = pcVar11;
          BIO_snprintf(pcVar11,n,"%s:%s",auStack_4e8,auStack_508);
        }
        goto LAB_00527fb0;
      }
    }
    uVar3 = uStack_520;
    if (uStack_524._0_2_ == 2) {
      pcVar11 = *ip;
      uVar13 = uStack_524 & 0xffff;
      if (pcVar11 == (char *)0x0) {
        pcVar11 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x18,"b_sock.c",0x391);
        if (pcVar11 == (char *)0x0) {
          ERR_put_error(0x20,0x65,0x41,"b_sock.c",0x392);
          goto LAB_00527fb0;
        }
        *ip = pcVar11;
      }
      BIO_snprintf(pcVar11,0x18,"%d.%d.%d.%d:%d",uVar3 >> 0x18,(uVar3 << 8) >> 0x18,
                   (uVar3 << 0x10) >> 0x18,uVar3 & 0xff,uVar13);
    }
  }
LAB_00527fb0:
  if (iStack_e4 == *(int *)puVar2) {
    return iVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return 1;
}

