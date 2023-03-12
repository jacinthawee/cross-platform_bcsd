
int X509_REQ_extension_nid(int nid)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)ext_nids;
  piVar2 = (int *)ext_nids;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (nid == iVar1) break;
    piVar2 = piVar2 + 1;
    iVar1 = *piVar2;
  }
  return 1;
}

