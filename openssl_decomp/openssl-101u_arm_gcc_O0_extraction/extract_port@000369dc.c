
long extract_port(char *param_1,ushort *param_2)

{
  long lVar1;
  servent *psVar2;
  
  lVar1 = strtol(param_1,(char **)0x0,10);
  if (lVar1 == 0) {
    psVar2 = getservbyname(param_1,"tcp");
    if (psVar2 != (servent *)0x0) {
      *param_2 = (ushort)(byte)((uint)psVar2->s_port >> 8) | (ushort)(psVar2->s_port << 8);
      return 1;
    }
    BIO_printf(bio_err,"getservbyname failure for %s\n",param_1);
  }
  else {
    *param_2 = (ushort)lVar1;
    lVar1 = 1;
  }
  return lVar1;
}

