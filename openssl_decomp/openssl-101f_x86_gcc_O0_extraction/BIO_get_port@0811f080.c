
int BIO_get_port(char *str,ushort *port_ptr)

{
  uint uVar1;
  ushort uVar2;
  long lVar3;
  servent *psVar4;
  int *piVar5;
  int iVar6;
  byte *pbVar7;
  char *pcVar8;
  byte *pbVar9;
  char *pcVar10;
  undefined uVar11;
  undefined uVar12;
  bool bVar13;
  byte bVar14;
  
  bVar14 = 0;
  if (str == (char *)0x0) {
    ERR_put_error(0x20,0x6b,0x71,"b_sock.c",0xb6);
    return 0;
  }
  lVar3 = strtol(str,(char **)0x0,10);
  if (lVar3 != 0) {
    *port_ptr = (ushort)lVar3;
    return 1;
  }
  CRYPTO_lock(0,9,(char *)0x17,(int)"b_sock.c");
  psVar4 = getservbyname(str,"tcp");
  uVar11 = 0;
  uVar12 = psVar4 == (servent *)0x0;
  if (!(bool)uVar12) {
    uVar1 = psVar4->s_port;
    uVar2 = (ushort)uVar1;
    uVar2 = uVar2 >> 8 | uVar2 << 8;
    *port_ptr = uVar2;
    CRYPTO_lock(uVar1 & 0xffff0000 | (uint)uVar2,10,(char *)0x17,(int)"b_sock.c");
    return 1;
  }
  CRYPTO_lock(0,10,(char *)0x17,(int)"b_sock.c");
  iVar6 = 5;
  pbVar7 = (byte *)str;
  pbVar9 = &DAT_08223794;
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    uVar11 = *pbVar7 < *pbVar9;
    uVar12 = *pbVar7 == *pbVar9;
    pbVar7 = pbVar7 + (uint)bVar14 * -2 + 1;
    pbVar9 = pbVar9 + (uint)bVar14 * -2 + 1;
  } while ((bool)uVar12);
  bVar13 = (!(bool)uVar11 && !(bool)uVar12) == (bool)uVar11;
  if (bVar13) {
    *port_ptr = 0x50;
    return 1;
  }
  iVar6 = 7;
  pcVar8 = str;
  pcVar10 = "telnet";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar13 = *pcVar8 == *pcVar10;
    pcVar8 = pcVar8 + (uint)bVar14 * -2 + 1;
    pcVar10 = pcVar10 + (uint)bVar14 * -2 + 1;
  } while (bVar13);
  if (bVar13) {
    *port_ptr = 0x17;
    return 1;
  }
  iVar6 = 6;
  pcVar8 = str;
  pcVar10 = "socks";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar13 = *pcVar8 == *pcVar10;
    pcVar8 = pcVar8 + (uint)bVar14 * -2 + 1;
    pcVar10 = pcVar10 + (uint)bVar14 * -2 + 1;
  } while (bVar13);
  if (bVar13) {
    *port_ptr = 0x438;
    return 1;
  }
  iVar6 = 6;
  pcVar8 = str;
  pcVar10 = "https";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar13 = *pcVar8 == *pcVar10;
    pcVar8 = pcVar8 + (uint)bVar14 * -2 + 1;
    pcVar10 = pcVar10 + (uint)bVar14 * -2 + 1;
  } while (bVar13);
  if (bVar13) {
LAB_0811f266:
    *port_ptr = 0x1bb;
    lVar3 = 1;
  }
  else {
    if (*str == 's') {
      bVar13 = str[1] == 's';
      if (((bVar13) && (bVar13 = str[2] == 'l', bVar13)) && (bVar13 = str[3] == '\0', bVar13))
      goto LAB_0811f266;
    }
    else {
      bVar13 = *str == 'f';
      if (((bVar13) && (bVar13 = str[1] == 't', bVar13)) &&
         ((bVar13 = str[2] == 'p', bVar13 && (bVar13 = str[3] == '\0', bVar13)))) {
        *port_ptr = 0x15;
        return 1;
      }
    }
    iVar6 = 7;
    pcVar8 = str;
    pcVar10 = "gopher";
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar13 = *pcVar8 == *pcVar10;
      pcVar8 = pcVar8 + (uint)bVar14 * -2 + 1;
      pcVar10 = pcVar10 + (uint)bVar14 * -2 + 1;
    } while (bVar13);
    if (bVar13) {
      lVar3 = 1;
      *port_ptr = 0x46;
    }
    else {
      piVar5 = __errno_location();
      ERR_put_error(2,3,*piVar5,"b_sock.c",0xe0);
      ERR_add_error_data(3,"service=\'",str,"\'");
    }
  }
  return lVar3;
}

