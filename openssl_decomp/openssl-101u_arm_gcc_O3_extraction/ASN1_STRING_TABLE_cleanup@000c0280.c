
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ASN1_STRING_TABLE_cleanup(void)

{
  _STACK *st;
  
  st = stable;
  if (stable != (_STACK *)0x0) {
    stable = (_STACK *)0x0;
    sk_pop_free(st,st_free + 1);
    return;
  }
  return;
}

