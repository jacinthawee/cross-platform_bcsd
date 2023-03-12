
int name_cmp(char *name,char *cmp)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (*(code *)PTR_strlen_006aab30)(cmp);
  uVar2 = (*(code *)PTR_strncmp_006aaa7c)(name,cmp,iVar1);
  if (uVar2 == 0) {
    if (name[iVar1] == '\0') {
      return 0;
    }
    uVar2 = (uint)(name[iVar1] != '.');
  }
  return uVar2;
}

