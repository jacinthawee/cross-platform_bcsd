
char * ERR_error_string(ulong e,char *buf)

{
  undefined1 *buf_00;
  
  buf_00 = buf;
  if (buf == (char *)0x0) {
    buf_00 = buf_5540;
  }
  ERR_error_string_n(e,buf_00,0x100);
  return buf_00;
}

