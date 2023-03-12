
int name_cmp(char *name,char *cmp)

{
  size_t __n;
  uint uVar1;
  
  __n = strlen(cmp);
  uVar1 = strncmp(name,cmp,__n);
  if (uVar1 == 0) {
    uVar1 = (uint)(name[__n] != '.' && name[__n] != '\0');
  }
  return uVar1;
}

