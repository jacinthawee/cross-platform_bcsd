
int BIO_get_host_ip(char *str,uchar *ip)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  uint uVar6;
  int *piVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  uint local_2c [4];
  char *local_1c;
  undefined2 auStack_18 [2];
  
  puVar5 = PTR___stack_chk_guard_006aabf0;
  iVar10 = 0;
  local_2c[3] = 0;
  local_2c[2] = 0;
  local_2c[1] = 0;
  local_2c[0] = 0;
  local_1c = *(char **)PTR___stack_chk_guard_006aabf0;
  pcVar8 = str;
  pcVar9 = (char *)ip;
  do {
    bVar1 = false;
    cVar2 = *pcVar8;
    while( true ) {
      iVar3 = (int)cVar2;
      pcVar8 = pcVar8 + 1;
      if (9 < iVar3 - 0x30U) break;
      pcVar9 = (char *)(auStack_18 + iVar10 * 2);
      uVar6 = local_2c[iVar10] * 10 + (iVar3 - 0x30U);
      local_2c[iVar10] = uVar6;
      if (0xff < uVar6) goto LAB_0052a590;
      cVar2 = *pcVar8;
      bVar1 = true;
    }
    if (iVar3 != 0x2e) {
      if (((iVar3 == 0) && (iVar10 == 3)) && (bVar1)) {
        iVar10 = 1;
        *ip = (uchar)local_2c[0];
        ip[1] = (uchar)local_2c[1];
        ip[2] = (uchar)local_2c[2];
        ip[3] = (uchar)local_2c[3];
        goto LAB_0052a654;
      }
      break;
    }
    if (!bVar1) {
      ERR_put_error(0x20,0x6a,0x6c,"b_sock.c",0x82);
      goto LAB_0052a634;
    }
    bVar1 = iVar10 != 3;
    iVar10 = iVar10 + 1;
  } while (bVar1);
LAB_0052a590:
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x16,"b_sock.c",0x90);
  iVar10 = (*(code *)PTR_gethostbyname_006aaa70)(str);
  puVar4 = PTR_CRYPTO_lock_006a926c;
  if (iVar10 == 0) {
    ERR_put_error(0x20,0x6a,0x66,"b_sock.c",0x95);
LAB_0052a5f0:
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x16,"b_sock.c",0xa5);
LAB_0052a634:
    pcVar9 = s_host__00667eac;
    ERR_add_error_data(2,s_host__00667eac,str);
    iVar10 = 0;
  }
  else {
    if (*(short *)(iVar10 + 10) != 2) {
      ERR_put_error(0x20,0x6a,0x6b,"b_sock.c",0x9c);
      goto LAB_0052a5f0;
    }
    pcVar9 = &DAT_00000016;
    *ip = ***(uchar ***)(iVar10 + 0x10);
    ip[1] = *(uchar *)(**(int **)(iVar10 + 0x10) + 1);
    ip[2] = *(uchar *)(**(int **)(iVar10 + 0x10) + 2);
    ip[3] = *(uchar *)(**(int **)(iVar10 + 0x10) + 3);
    (*(code *)puVar4)(10,0x16,"b_sock.c",0xa5);
    iVar10 = 1;
  }
LAB_0052a654:
  if (local_1c == *(char **)puVar5) {
    return iVar10;
  }
  pcVar8 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (pcVar8 == (char *)0x0) {
    ERR_put_error(0x20,0x6b,0x71,"b_sock.c",0xb6);
    return 0;
  }
  iVar10 = (*(code *)PTR_strtol_006aaa68)();
  if (iVar10 != 0) {
    *(short *)pcVar9 = (short)iVar10;
    return 1;
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x17,"b_sock.c",0xbe);
  iVar10 = (*(code *)PTR_getservbyname_006aaafc)(pcVar8,&DAT_00641588);
  if (iVar10 != 0) {
    *(short *)pcVar9 = (short)*(undefined4 *)(iVar10 + 8);
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x17,"b_sock.c",0xc9);
    return 1;
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x17,"b_sock.c",0xc9);
  iVar10 = (*(code *)PTR_strcmp_006aac20)(pcVar8,&DAT_00668350);
  if (iVar10 == 0) {
    *(undefined2 *)pcVar9 = 0x50;
    return 1;
  }
  iVar10 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"telnet");
  if (iVar10 == 0) {
    *(undefined2 *)pcVar9 = 0x17;
    return 1;
  }
  iVar10 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"socks");
  if (iVar10 == 0) {
    *(undefined2 *)pcVar9 = 0x438;
    return 1;
  }
  iVar10 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"https");
  if (iVar10 == 0) {
LAB_0052a97c:
    *(undefined2 *)pcVar9 = 0x1bb;
  }
  else {
    if (*pcVar8 == 's') {
      if (((pcVar8[1] == 's') && (pcVar8[2] == 'l')) && (pcVar8[3] == '\0')) goto LAB_0052a97c;
    }
    else if (((*pcVar8 == 'f') && (pcVar8[1] == 't')) && ((pcVar8[2] == 'p' && (pcVar8[3] == '\0')))
            ) {
      *(undefined2 *)pcVar9 = 0x15;
      return 1;
    }
    iVar10 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"gopher");
    if (iVar10 != 0) {
      piVar7 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
      ERR_put_error(2,3,*piVar7,"b_sock.c",0xe0);
      ERR_add_error_data(3,"service=\'",pcVar8,"\'");
      return 0;
    }
    *(undefined2 *)pcVar9 = 0x46;
  }
  return 1;
}

