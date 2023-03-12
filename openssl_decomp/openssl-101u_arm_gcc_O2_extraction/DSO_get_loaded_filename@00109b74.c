
char * DSO_get_loaded_filename(DSO *dso)

{
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x80,0x43,"dso_lib.c",0x1a3);
  }
  else {
    dso = (DSO *)dso->loaded_filename;
  }
  return (char *)dso;
}

