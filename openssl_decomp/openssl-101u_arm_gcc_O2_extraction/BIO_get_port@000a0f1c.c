
int BIO_get_port(char *str,ushort *port_ptr)

{
  long lVar1;
  servent *psVar2;
  int iVar3;
  int *piVar4;
  
  if (str == (char *)0x0) {
    ERR_put_error(0x20,0x6b,0x71,"b_sock.c",0xb0);
    return 0;
  }
  lVar1 = strtol(str,(char **)0x0,10);
  if (lVar1 != 0) {
    *port_ptr = (ushort)lVar1;
    return 1;
  }
  CRYPTO_lock(9,0x17,"b_sock.c",0xb7);
  psVar2 = getservbyname(str,"tcp");
  if (psVar2 != (servent *)0x0) {
    *port_ptr = (ushort)(byte)((uint)psVar2->s_port >> 8) | (ushort)(psVar2->s_port << 8);
    CRYPTO_lock(10,0x17,"b_sock.c",0xc3);
    return 1;
  }
  CRYPTO_lock(10,0x17,"b_sock.c",0xc3);
  iVar3 = strcmp(str,"http");
  if (iVar3 == 0) {
    *port_ptr = 0x50;
    return 1;
  }
  iVar3 = strcmp(str,"telnet");
  if (iVar3 == 0) {
    *port_ptr = 0x17;
    return 1;
  }
  iVar3 = strcmp(str,"socks");
  if (iVar3 == 0) {
    *port_ptr = 0x438;
    return 1;
  }
  iVar3 = strcmp(str,"https");
  if (iVar3 == 0) {
LAB_000a1030:
    lVar1 = 1;
    *port_ptr = 0x1bb;
  }
  else {
    if (*str == 's') {
      if (((str[1] == 's') && (str[2] == 'l')) && (str[3] == '\0')) goto LAB_000a1030;
    }
    else if (((*str == 'f') && (str[1] == 't')) && ((str[2] == 'p' && (str[3] == '\0')))) {
      *port_ptr = 0x15;
      return 1;
    }
    iVar3 = strcmp(str,"gopher");
    if (iVar3 == 0) {
      lVar1 = 1;
      *port_ptr = 0x46;
    }
    else {
      piVar4 = __errno_location();
      ERR_put_error(2,3,*piVar4,"b_sock.c",0xd8);
      ERR_add_error_data(3,"service=\'",str,"\'");
    }
  }
  return lVar1;
}

