
char * DSO_get_filename(DSO *dso)

{
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x7f,0x43,"dso_lib.c",0x151);
  }
  else {
    dso = (DSO *)dso->filename;
  }
  return (char *)dso;
}

