
int X509_PURPOSE_get_by_sname(char *sname)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  
  puVar4 = xstandard;
  iVar3 = 0;
  while( true ) {
    iVar1 = 9;
    if (xptable != (_STACK *)0x0) {
      iVar1 = sk_num(xptable);
      iVar1 = iVar1 + 9;
    }
    if (iVar1 <= iVar3) {
      return -1;
    }
    puVar2 = puVar4;
    if (8 < iVar3) {
      puVar2 = (undefined1 *)sk_value(xptable,iVar3 + -9);
    }
    puVar4 = puVar4 + 0x1c;
    iVar1 = strcmp(*(char **)(puVar2 + 0x14),sname);
    if (iVar1 == 0) break;
    iVar3 = iVar3 + 1;
  }
  return iVar3;
}

