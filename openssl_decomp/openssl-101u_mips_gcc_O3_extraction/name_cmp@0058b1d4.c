
int name_cmp(char *name,char *cmp)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (*(code *)PTR_strlen_006a9a24)(cmp);
  uVar2 = (*(code *)PTR_strncmp_006a9970)(name,cmp,iVar1);
  if (uVar2 == 0) {
    if (name[iVar1] == '\0') {
      return 0;
    }
    uVar2 = (uint)(name[iVar1] != '.');
  }
  return uVar2;
}

