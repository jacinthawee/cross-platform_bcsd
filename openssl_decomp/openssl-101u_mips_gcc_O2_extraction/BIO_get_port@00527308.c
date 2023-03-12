
int BIO_get_port(char *str,ushort *port_ptr)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  
  if (str == (char *)0x0) {
    ERR_put_error(0x20,0x6b,0x71,"b_sock.c",0xb0);
    return 0;
  }
  iVar2 = (*(code *)PTR_strtol_006a9958)(str,0,10);
  if (iVar2 != 0) {
    *port_ptr = (ushort)iVar2;
    return 1;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x17,"b_sock.c",0xb7);
  iVar2 = (*(code *)PTR_getservbyname_006a99f0)(str,&DAT_00641018);
  puVar1 = PTR_CRYPTO_lock_006a8144;
  if (iVar2 != 0) {
    *port_ptr = (ushort)*(undefined4 *)(iVar2 + 8);
    (*(code *)puVar1)(10,0x17,"b_sock.c",0xc3);
    return 1;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x17,"b_sock.c",0xc3);
  iVar2 = (*(code *)PTR_strcmp_006a9b18)(str,&DAT_00667870);
  if (iVar2 == 0) {
    *port_ptr = 0x50;
    return 1;
  }
  iVar2 = (*(code *)PTR_strcmp_006a9b18)(str,"telnet");
  if (iVar2 == 0) {
    *port_ptr = 0x17;
    return 1;
  }
  iVar2 = (*(code *)PTR_strcmp_006a9b18)(str,"socks");
  if (iVar2 == 0) {
    *port_ptr = 0x438;
    return 1;
  }
  iVar2 = (*(code *)PTR_strcmp_006a9b18)(str,"https");
  if (iVar2 == 0) {
LAB_0052754c:
    *port_ptr = 0x1bb;
  }
  else {
    if (*str == 's') {
      if (((str[1] == 's') && (str[2] == 'l')) && (str[3] == '\0')) goto LAB_0052754c;
    }
    else if (((*str == 'f') && (str[1] == 't')) && ((str[2] == 'p' && (str[3] == '\0')))) {
      *port_ptr = 0x15;
      return 1;
    }
    iVar2 = (*(code *)PTR_strcmp_006a9b18)(str,"gopher");
    if (iVar2 != 0) {
      piVar3 = (int *)(*(code *)PTR___errno_location_006a99e8)();
      ERR_put_error(2,3,*piVar3,"b_sock.c",0xd8);
      ERR_add_error_data(3,"service=\'",str,"\'");
      return 0;
    }
    *port_ptr = 0x46;
  }
  return 1;
}

