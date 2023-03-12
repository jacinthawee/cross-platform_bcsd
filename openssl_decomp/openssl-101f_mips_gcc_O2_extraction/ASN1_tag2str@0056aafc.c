
char * ASN1_tag2str(int tag)

{
  bool bVar1;
  
  bVar1 = (uint)tag < 0x1f;
  if ((tag & 0xfffffff7U) == 0x102) {
    tag = tag & 0xfffffeff;
    bVar1 = (uint)tag < 0x1f;
  }
  if (bVar1) {
    return *(char **)(tag2str_7235 + tag * 4);
  }
  return "(unknown)";
}

