
void index_serial_LHASH_COMP(int param_1,int param_2)

{
  char cVar1;
  char *__s1;
  char *__s2;
  
  __s1 = *(char **)(param_1 + 0xc);
  cVar1 = *__s1;
  while (cVar1 == '0') {
    __s1 = __s1 + 1;
    cVar1 = *__s1;
  }
  __s2 = *(char **)(param_2 + 0xc);
  cVar1 = *__s2;
  while (cVar1 == '0') {
    __s2 = __s2 + 1;
    cVar1 = *__s2;
  }
  strcmp(__s1,__s2);
  return;
}

