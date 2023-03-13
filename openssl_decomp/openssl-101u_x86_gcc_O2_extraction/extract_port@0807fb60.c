
long extract_port(char *param_1,ushort *param_2)

{
  ushort uVar1;
  long lVar2;
  servent *psVar3;
  
  lVar2 = strtol(param_1,(char **)0x0,10);
  if (lVar2 == 0) {
    psVar3 = getservbyname(param_1,"tcp");
    if (psVar3 != (servent *)0x0) {
      uVar1 = (ushort)psVar3->s_port;
      *param_2 = uVar1 >> 8 | uVar1 << 8;
      return 1;
    }
    BIO_printf(bio_err,"getservbyname failure for %s\n",param_1);
  }
  else {
    *param_2 = (ushort)lVar2;
    lVar2 = 1;
  }
  return lVar2;
}

