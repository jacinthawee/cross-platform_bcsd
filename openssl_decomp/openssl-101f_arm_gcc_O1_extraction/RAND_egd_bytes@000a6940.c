
int RAND_egd_bytes(char *path,int bytes)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RAND_query_egd_bytes(path,(uchar *)0x0,bytes);
  if ((iVar1 < 1) || (iVar2 = RAND_status(), iVar2 != 1)) {
    iVar1 = 0;
  }
  return iVar1;
}

