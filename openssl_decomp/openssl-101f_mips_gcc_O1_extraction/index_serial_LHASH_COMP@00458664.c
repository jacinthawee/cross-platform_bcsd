
void index_serial_LHASH_COMP(int param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = *(char **)(param_1 + 0xc);
  cVar1 = *pcVar2;
  while (cVar1 == '0') {
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
  }
  pcVar3 = *(char **)(param_2 + 0xc);
  cVar1 = *pcVar3;
  while (cVar1 == '0') {
    pcVar3 = pcVar3 + 1;
    cVar1 = *pcVar3;
  }
  (*(code *)PTR_strcmp_006aac20)(pcVar2,pcVar3);
  return;
}

