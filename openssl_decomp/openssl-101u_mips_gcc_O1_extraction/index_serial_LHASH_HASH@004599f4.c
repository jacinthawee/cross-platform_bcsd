
void index_serial_LHASH_HASH(int param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)(param_1 + 0xc);
  cVar1 = *pcVar2;
  while (cVar1 == '0') {
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
  }
                    /* WARNING: Could not recover jumptable at 0x00459a28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_lh_strhash_006a73ac)(pcVar2);
  return;
}

