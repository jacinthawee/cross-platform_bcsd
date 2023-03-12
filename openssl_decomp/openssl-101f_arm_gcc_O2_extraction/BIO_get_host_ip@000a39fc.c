
int BIO_get_host_ip(char *str,uchar *ip)

{
  bool bVar1;
  hostent *phVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  bool bVar6;
  uint local_30 [5];
  
  bVar1 = false;
  iVar4 = 0;
  local_30[3] = 0;
  local_30[2] = 0;
  local_30[1] = 0;
  local_30[0] = 0;
  pbVar5 = (byte *)str;
  do {
    while( true ) {
      uVar3 = (uint)*pbVar5;
      if (uVar3 - 0x30 < 10) break;
      if (uVar3 != 0x2e) {
        if ((uVar3 == 0 && iVar4 == 3) && (bVar1)) {
          *ip = (uchar)local_30[0];
          ip[1] = (uchar)local_30[1];
          ip[2] = (uchar)local_30[2];
          ip[3] = (uchar)local_30[3];
          return 1;
        }
        goto LAB_000a3a3e;
      }
      if (!bVar1) {
        ERR_put_error(0x20,0x6a,0x6c,"b_sock.c",0x82);
        goto LAB_000a3ae2;
      }
      bVar6 = iVar4 == 3;
      bVar1 = false;
      iVar4 = iVar4 + 1;
      pbVar5 = pbVar5 + 1;
      if (bVar6) goto LAB_000a3a3e;
    }
    bVar1 = true;
    uVar3 = (uVar3 - 0x30) + local_30[iVar4] * 10;
    local_30[iVar4] = uVar3;
    pbVar5 = pbVar5 + 1;
  } while (uVar3 < 0x100);
LAB_000a3a3e:
  CRYPTO_lock(9,0x16,"b_sock.c",0x90);
  phVar2 = gethostbyname(str);
  if (phVar2 == (hostent *)0x0) {
    ERR_put_error(0x20,0x6a,0x66,"b_sock.c",0x95);
  }
  else {
    if (*(short *)&phVar2->h_addrtype == 2) {
      *ip = **phVar2->h_addr_list;
      ip[1] = (*phVar2->h_addr_list)[1];
      ip[2] = (*phVar2->h_addr_list)[2];
      ip[3] = (*phVar2->h_addr_list)[3];
      CRYPTO_lock(10,0x16,"b_sock.c",0xa5);
      return 1;
    }
    ERR_put_error(0x20,0x6a,0x6b,"b_sock.c",0x9c);
  }
  CRYPTO_lock(10,0x16,"b_sock.c",0xa5);
LAB_000a3ae2:
  ERR_add_error_data(2,"host=",str);
  return 0;
}

