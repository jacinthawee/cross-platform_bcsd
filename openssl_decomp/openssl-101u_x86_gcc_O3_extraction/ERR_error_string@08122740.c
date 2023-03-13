
char * ERR_error_string(ulong e,char *buf)

{
  if (buf == (char *)0x0) {
    buf = buf_5520;
  }
  ERR_error_string_n(e,buf,0x100);
  return buf;
}

