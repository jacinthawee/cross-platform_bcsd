
char * ASN1_tag2str(int tag)

{
  char *pcVar1;
  
  if ((tag & 0xfffffff7U) == 0x102) {
    tag = tag & 0xfffffeff;
  }
  pcVar1 = "(unknown)";
  if ((uint)tag < 0x1f) {
    pcVar1 = *(char **)(tag2str_7215 + tag * 4);
  }
  return pcVar1;
}

