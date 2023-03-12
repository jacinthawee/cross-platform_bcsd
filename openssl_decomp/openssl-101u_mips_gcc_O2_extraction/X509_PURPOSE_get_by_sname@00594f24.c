
int X509_PURPOSE_get_by_sname(char *sname)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  
  puVar3 = xstandard;
  iVar2 = 0;
  while( true ) {
    if (xptable == 0) {
      iVar1 = 9;
    }
    else {
      iVar1 = (*(code *)PTR_sk_num_006a6e2c)(xptable);
      iVar1 = iVar1 + 9;
    }
    if (iVar1 <= iVar2) {
      return -1;
    }
    if (iVar2 < 9) {
      iVar1 = (*(code *)PTR_strcmp_006a9b18)(*(undefined4 *)(puVar3 + 0x14),sname);
    }
    else {
      iVar1 = (*(code *)PTR_sk_value_006a6e24)(xptable,iVar2 + -9);
      iVar1 = (*(code *)PTR_strcmp_006a9b18)(*(undefined4 *)(iVar1 + 0x14),sname);
    }
    if (iVar1 == 0) break;
    puVar3 = puVar3 + 0x1c;
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

