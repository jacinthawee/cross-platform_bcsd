
int BIO_get_host_ip(char *str,uchar *ip)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  bool bVar4;
  int iVar5;
  char *mode;
  hostent *mode_00;
  int iVar6;
  int in_GS_OFFSET;
  uint local_30 [4];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_30[3] = 0;
  local_30[2] = 0;
  local_30[1] = 0;
  local_30[0] = 0;
  iVar6 = 0;
  mode = str;
  while( true ) {
    bVar4 = false;
    cVar2 = *mode;
    while( true ) {
      iVar5 = (int)cVar2;
      mode = mode + 1;
      if (9 < iVar5 - 0x30U) break;
      uVar1 = (iVar5 - 0x30U) + local_30[iVar6] * 10;
      local_30[iVar6] = uVar1;
      if (0xff < uVar1) goto LAB_0811ef30;
      cVar2 = *mode;
      bVar4 = true;
    }
    if (iVar5 != 0x2e) break;
    if (!bVar4) {
      ERR_put_error(0x20,0x6a,0x6c,"b_sock.c",0x82);
      goto LAB_0811efb3;
    }
    if (iVar6 == 3) goto LAB_0811ef30;
    iVar6 = iVar6 + 1;
  }
  mode = (char *)((uint)mode & 0xffffff00 | (uint)(iVar6 == 3));
  if ((iVar5 == 0 && iVar6 == 3) && (bVar4)) {
    *ip = (uchar)local_30[0];
    ip[1] = (uchar)local_30[1];
    ip[2] = (uchar)local_30[2];
    ip[3] = (uchar)local_30[3];
    iVar6 = 1;
    goto LAB_0811efc8;
  }
LAB_0811ef30:
  CRYPTO_lock((int)mode,9,(char *)0x16,(int)"b_sock.c");
  mode_00 = gethostbyname(str);
  if (mode_00 == (hostent *)0x0) {
    ERR_put_error(0x20,0x6a,0x66,"b_sock.c",0x95);
  }
  else {
    if (*(short *)&mode_00->h_addrtype == 2) {
      *ip = **mode_00->h_addr_list;
      ip[1] = (*mode_00->h_addr_list)[1];
      ip[2] = (*mode_00->h_addr_list)[2];
      bVar3 = (*mode_00->h_addr_list)[3];
      ip[3] = bVar3;
      CRYPTO_lock((uint)bVar3,10,(char *)0x16,(int)"b_sock.c");
      iVar6 = 1;
      goto LAB_0811efc8;
    }
    ERR_put_error(0x20,0x6a,0x6b,"b_sock.c",0x9c);
  }
  CRYPTO_lock((int)mode_00,10,(char *)0x16,(int)"b_sock.c");
LAB_0811efb3:
  ERR_add_error_data(2,"host=",str);
  iVar6 = 0;
LAB_0811efc8:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

