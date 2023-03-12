
void index_serial_LHASH_HASH(int param_1)

{
  char cVar1;
  char *c;
  
  c = *(char **)(param_1 + 0xc);
  cVar1 = *c;
  while (cVar1 == '0') {
    c = c + 1;
    cVar1 = *c;
  }
  lh_strhash(c);
  return;
}

