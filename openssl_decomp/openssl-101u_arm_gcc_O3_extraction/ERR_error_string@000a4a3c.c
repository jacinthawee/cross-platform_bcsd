
char * ERR_error_string(ulong e,char *buf)

{
  char *buf_00;
  
  buf_00 = PTR_buf_8174_000a4a54;
  if (buf != (char *)0x0) {
    buf_00 = buf;
  }
  ERR_error_string_n(e,buf_00,0x100);
  return buf_00;
}

